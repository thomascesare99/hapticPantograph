#!/usr/bin/env python3
import sys
import os
import typing
import yaml
import rclpy
from rclpy.node import Node
from PyQt5.QtWidgets import QApplication, QMainWindow, QGraphicsScene, QGraphicsView, QGridLayout, QWidget, QGraphicsSimpleTextItem, QGraphicsItemGroup, QGraphicsPixmapItem
from PyQt5.QtGui import QImage, QPixmap, QFont, QPainter, QCursor,QPen, QVector3D, QColor
from PyQt5.QtCore import Qt, QPoint, QObject, pyqtSignal, QEvent, QLineF, QRunnable, QThreadPool
import pyqtgraph.opengl as gl
import nibabel as nib
import numpy as np
import matplotlib.pyplot as plt
import math
import threading
from std_msgs.msg import Float64MultiArray

class ImageViewer(QGraphicsView):
    mouse_wheel_scrolled = pyqtSignal(QGraphicsView, int)
    mouse_clicked = pyqtSignal(QGraphicsView, int, int)

    def __init__(self, parent=None):
        super(ImageViewer, self).__init__(parent)
        self.setRenderHint(QPainter.Antialiasing)
        self.setRenderHint(QPainter.SmoothPixmapTransform)
        self.setTransformationAnchor(QGraphicsView.AnchorUnderMouse)
        self.setResizeAnchor(QGraphicsView.AnchorUnderMouse)

        # Install the event filter for mouse wheel events
        self.viewport().installEventFilter(self)

    def eventFilter(self, obj, event):
        if event.type() == QEvent.Wheel:
            # Emit the mouse_wheel_scrolled signal with the wheel delta
            self.mouse_wheel_scrolled.emit(self, event.angleDelta().y())
            return True
        elif event.type() == QEvent.MouseButtonPress:
            # Emit the mouse_clicked signal with the mouse coordinates
            self.mouse_clicked.emit(self, event.pos().x(), event.pos().y())
            return True
        return super(ImageViewer, self).eventFilter(obj, event)


class MainWindow(QMainWindow):
    def __init__(self, volume_path, segmentation_path, angle_publisher):
        super().__init__()

        # Load the NIfTI image data
        volume = nib.load(volume_path)
        self.volume_data = volume.get_fdata()
        print(self.volume_data.shape)

        segmentation = nib.load(segmentation_path)
        self.segmentation_data = segmentation.get_fdata().astype(np.uint8)
        print(self.segmentation_data.shape)

        self.desired_angles_publisher = angle_publisher

        data_min = np.min(self.volume_data)
        data_max = np.max(self.volume_data)
        self.volume_data = ((self.volume_data - data_min) / (data_max - data_min)) * 255

        self.volume_data = self.volume_data.astype(np.uint8)  # Convert to unsigned 8-bit integer
        self.desired_trajectory_line = None
        self.actual_trajectory_line = None

        self.trajectory_start = None
        self.trajectory_end = None
        self.current_end = None

        # Create QGraphicsView and QGraphicsScene objects
        self.font = QFont()
        self.font.setPointSize(12)

        self.axial_view = ImageViewer()
        axial_scene = QGraphicsScene()
        axial_scene.setBackgroundBrush(Qt.black)
        self.axial_view.setScene(axial_scene)

        self.sagittal_view = ImageViewer()
        sagittal_scene = QGraphicsScene()
        sagittal_scene.setBackgroundBrush(Qt.black)
        self.sagittal_view.setScene(sagittal_scene)

        self.coronal_view = ImageViewer()
        coronal_scene = QGraphicsScene()
        coronal_scene.setBackgroundBrush(Qt.black)
        self.coronal_view.setScene(coronal_scene)

        self.volume_view = gl.GLViewWidget(self)

         # Connect the mouse_wheel_scrolled signal of ImageViewer to scroll_active_view method
        self.axial_view.mouse_wheel_scrolled.connect(self.scroll_active_view)
        self.sagittal_view.mouse_wheel_scrolled.connect(self.scroll_active_view)
        self.coronal_view.mouse_wheel_scrolled.connect(self.scroll_active_view)

        # Connect the mouse_clicked signal of ImageViewer to handle_mouse_click method
        self.axial_view.mouse_clicked.connect(self.handle_mouse_click)
        self.sagittal_view.mouse_clicked.connect(self.handle_mouse_click)
        self.coronal_view.mouse_clicked.connect(self.handle_mouse_click)

        # Set up the layouts
        layout = QGridLayout()
        layout.addWidget(self.axial_view, 0, 0)
        layout.addWidget(self.sagittal_view, 0, 1)
        layout.addWidget(self.coronal_view, 1, 1)
        layout.addWidget(self.volume_view, 1, 0)

        central_widget = QWidget()
        central_widget.setLayout(layout)
        self.setCentralWidget(central_widget)

        self.axial_index = self.volume_data.shape[2] // 2
        self.sagittal_index = self.volume_data.shape[0] // 2
        self.coronal_index = self.volume_data.shape[1] // 2

        self.d2 = np.zeros(self.volume_data.shape + (4,))
        self.d2[..., 3] = self.volume_data  # alpha
        self.d2[..., 0] = self.d2[..., 3]  # red
        self.d2[..., 1] = self.d2[..., 3]  # green
        self.d2[..., 2] = self.d2[..., 3]  # blue
        
        volume = gl.GLVolumeItem(self.d2, sliceDensity=1, smooth=True, glOptions='translucent')
        self.volume_view.addItem(volume)
        self.volume_view.setCameraPosition(distance=500, elevation=0, azimuth=0)
        self.volume_view.show()
        self.update_slices()

    def update_slices(self):
        axial_slice = np.rot90(self.volume_data[:, :, self.axial_index]).copy() # axial section moves along z
        sagittal_slice = np.rot90(self.volume_data[self.sagittal_index, :, :]).copy() # sagittal section moves along x
        coronal_slice = np.rot90(self.volume_data[:, self.coronal_index, :]).copy() # coronal section moves along y

        axial_segm = np.rot90(self.segmentation_data[:, :, self.axial_index]).copy() # axial section moves along z
        sagittal_segm = np.rot90(self.segmentation_data[self.sagittal_index, :, :]).copy() # sagittal section moves along x
        coronal_segm = np.rot90(self.segmentation_data[:, self.coronal_index, :]).copy() # coronal section moves along y        

        self.display_image(self.axial_view, axial_slice, axial_segm)
        self.display_image(self.sagittal_view, sagittal_slice, sagittal_segm)
        self.display_image(self.coronal_view, coronal_slice, coronal_segm)

   
    def display_image(self, view, image, segmentation):
        height, width = image.shape
        bytes_per_line = width
        view.setSceneRect(0, 0, width, height)
        view.setSceneRect(view.scene().itemsBoundingRect())
        view.scene().clear()
        
        q_image = QImage(image.data, width, height, bytes_per_line, QImage.Format_Grayscale8)
        image_pixmap = QPixmap.fromImage(q_image)

        
        colormap = ((0, 0, 0, 0),
                    (255, 0 , 0, 126), 
                    (0, 255, 0, 126))
        segm_data = np.zeros((height, width, 4), dtype = np.uint8)
        for i, color in enumerate(colormap):
            segm_data[segmentation==i]=color
        segmentation_image = QImage(segm_data.data, width, height, 4*bytes_per_line, QImage.Format_RGBA8888)

        # for row in range(height):
        #     for col in range(width):
        #         label = int(segmentation[row, col])
        #         color = colormap[label]
        #         segmentation_image.setPixelColor(col, row, color)
        segmentation_pixmap = QPixmap.fromImage(segmentation_image)

        result = QPixmap(image_pixmap)
        result.fill(Qt.transparent)
        painter = QPainter(result)  # from image
        painter.setRenderHint(QPainter.Antialiasing)
        painter.drawPixmap(QPoint(), image_pixmap)
        painter.setCompositionMode(QPainter.CompositionMode_SourceOver)
        painter.drawPixmap(result.rect(), segmentation_pixmap, segmentation_pixmap.rect())
        painter.end() 
        view.scene().addPixmap(result)

        pen = QPen(Qt.white, 1 , Qt.DashLine)
        if view is self.axial_view:
            self.add_text_item(view, "A", width/2, 0)
            self.add_text_item(view, "P", width/2, 0.95*height)
            self.add_text_item(view, "R", 0, height/2)
            self.add_text_item(view, "L", width, height/2)

            coronal_pos = int(height - height * self.coronal_index / self.volume_data.shape[1]) 
            coronal_line = QLineF(0, coronal_pos, width, coronal_pos)
            view.scene().addLine(coronal_line, pen)

            sagittal_pos = int(width * self.sagittal_index / self.volume_data.shape[0])
            sagittal_line = QLineF(sagittal_pos, 0, sagittal_pos, height)
            view.scene().addLine(sagittal_line, pen)

        if view is self.sagittal_view:
            self.add_text_item(view, "S", width/2, 0)
            self.add_text_item(view, "I", width/2, 0.95*height)
            self.add_text_item(view, "P", 0, height/2)
            self.add_text_item(view, "A", width, height/2)
        
            axial_pos = int(height - height * self.axial_index / self.volume_data.shape[2])
            axial_line = QLineF(0, axial_pos, width, axial_pos)
            view.scene().addLine(axial_line, pen)

            coronal_pos = int(width * self.coronal_index / self.volume_data.shape[1])
            coronal_line = QLineF(coronal_pos, 0, coronal_pos, height)
            view.scene().addLine(coronal_line, pen)

        if view is self.coronal_view:
            self.add_text_item(view, "S", width/2, 0)
            self.add_text_item(view, "I", width/2, 0.95*height)
            self.add_text_item(view, "R", 0, height/2)
            self.add_text_item(view, "L", width, height/2)
            axial_pos = int(height - height * self.axial_index / self.volume_data.shape[2])
            axial_line = QLineF(0, axial_pos, width, axial_pos)
            view.scene().addLine(axial_line, pen)

            sagittal_pos = int(width * self.sagittal_index / self.volume_data.shape[0])
            sagittal_line = QLineF(sagittal_pos, 0, sagittal_pos, height)
            view.scene().addLine(sagittal_line, pen)

    def add_text_item(self, view, text, x, y):
        # Create a QGraphicsSimpleTextItem
        text_item = QGraphicsSimpleTextItem(text)

        # Set the font for the text item
        font = QFont()
        font.setPointSize(12)
        text_item.setFont(font)

        # Set the color of the text item
        text_item.setBrush(Qt.yellow)

        # Set the position of the text item
        text_item.setPos(x, y)

        # Add the text item to the scene
        view.scene().addItem(text_item)

        
    def display_desired_trajectory_in_volume(self):
        if self.desired_trajectory_line is not None:
            self.volume_view.removeItem(self.desired_trajectory_line)

        self.desired_trajectory_line = gl.GLLinePlotItem(pos=[[self.trajectory_start.x(), self.trajectory_start.y(), self.trajectory_start.z()], 
                                                 [self.trajectory_end.x(), self.trajectory_end.y(), self.trajectory_end.z()]],
                                            color=(1.0, 0.0, 0.0, 1.0),
                                            width=3.0
                                            )
    
        self.volume_view.addItem(self.desired_trajectory_line)

        self.x_axis = gl.GLLinePlotItem(pos=[[self.trajectory_start.x(), self.trajectory_start.y(), self.trajectory_start.z()], 
                                                 [self.trajectory_start.x()+100, self.trajectory_start.y(), self.trajectory_start.z()]],
                                            color=(0, 1.0, 0, 1.0), # green
                                            width=3.0
                                            )
        self.y_axis = gl.GLLinePlotItem(pos=[[self.trajectory_start.x(), self.trajectory_start.y(), self.trajectory_start.z()], 
                                            [self.trajectory_start.x(), self.trajectory_start.y()+100, self.trajectory_start.z()]],
                                    color=(0, 0, 1.0, 1.0), # blue
                                    width=3.0
                                    )
        self.z_axis = gl.GLLinePlotItem(pos=[[self.trajectory_start.x(), self.trajectory_start.y(), self.trajectory_start.z()], 
                                            [self.trajectory_start.x(), self.trajectory_start.y(), self.trajectory_start.z()+100]],
                                    color=(1.0, 1.0, 1.0, 1.0), # white
                                    width=3.0
                                    )
        self.volume_view.addItem(self.x_axis)
        self.volume_view.addItem(self.y_axis)
        self.volume_view.addItem(self.z_axis)

        self.volume_view.show()

    # def display_trajectory_in_slices(self, trajectory, slice_index, view):
    #     # Update the corresponding image in the view
    #     if view is self.axial_view:
    #         axial_slice = np.rot90(self.volume_data[:, :, slice_index]).copy()
    #         axial_slice = self.draw_trajectory(axial_slice, trajectory)
    #         self.display_image(view, axial_slice)

    #     if view is self.sagittal_view:
    #         sagittal_slice = np.rot90(self.volume_data[slice_index, :, :]).copy()
    #         sagittal_slice = self.draw_trajectory(sagittal_slice, trajectory)
    #         self.display_image(view, sagittal_slice)

    #     if view is self.coronal_view:
    #         coronal_slice = np.rot90(self.volume_data[:, slice_index, :]).copy()
    #         coronal_slice = self.draw_trajectory(coronal_slice, trajectory)
    #         self.display_image(view, coronal_slice)

    
    def handle_mouse_click(self, view, x, y):
        # Handle mouse click event
        if self.trajectory_start is None:
            self.trajectory_start = self.handle_voxel_click(view, x, y)
        elif self.trajectory_end is None:
            self.trajectory_end = self.handle_voxel_click(view, x, y)
            self.display_desired_trajectory_in_volume()
            print("TRAJECTORY START: ")
            print(self.trajectory_start)
            print("TRAJECTORY END: ")
            print(self.trajectory_end)
            self.compute_angles()
        else:
            self.trajectory_start = self.handle_voxel_click(view, x, y)
            self.trajectory_end = None


    def handle_voxel_click(self, view, x,y):
        voxel = QVector3D()
        scene_position = view.mapToScene(int(x), int(y))
        if view is self.axial_view:
            voxel.setZ(self.axial_index)
            voxel.setX(scene_position.x())
            voxel.setY(view.height() - scene_position.y())
        elif view is self.sagittal_view:
            voxel.setX(self.sagittal_index)
            voxel.setY(scene_position.x())
            voxel.setZ(view.height() - scene_position.y())
        elif view is self.coronal_view:
            voxel.setY(self.coronal_index)
            voxel.setX(scene_position.x())
            voxel.setZ(view.height() - scene_position.y())
        return voxel
    
    def compute_angles(self):
        if self.trajectory_start and self.trajectory_end:
            direction_vector = self.trajectory_end - self.trajectory_start

            theta = math.degrees(math.atan2(-direction_vector.y(), direction_vector.x()))
            phi = math.degrees(math.asin(direction_vector.z() / direction_vector.length()))
            angle_msg = Float64MultiArray()
            angle_msg.data = [phi, theta]
            self.desired_angles_publisher.publish(angle_msg)

    def compute_actual_trajectory(self, msg):
        actual_phi = msg.data[0] *math.pi/180
        actual_theta = msg.data[1] *math.pi/180
        L = 200

        end_x =  self.trajectory_start.x() + L*math.cos(actual_theta)*math.sin(actual_phi)
        end_z = self.trajectory_start.z() - L*math.sin(actual_theta)*math.sin(actual_phi)
        end_y = self.trajectory_start.y() - L*math.cos(actual_phi)
        # if (end_x, end_y, end_z) != self.current_end:
        self.current_end = (end_x, end_y, end_z)
        self.display_actual_trajectory_in_volume(self.current_end)
    
    def display_actual_trajectory_in_volume(self, end_point):
        if self.actual_trajectory_line in self.volume_view.items:
            self.volume_view.removeItem(self.actual_trajectory_line)
        elif self.trajectory_start is not None:
            self.actual_trajectory_line = gl.GLLinePlotItem(pos=[[self.trajectory_start.x(), self.trajectory_start.y(), self.trajectory_start.z()], 
                                                    [end_point[0], end_point[1], end_point[2]]],
                                            color=(0.0, 1.0, 0.0, 1.0),
                                            width=2.0
                                            )
            self.volume_view.addItem(self.actual_trajectory_line)
            self.volume_view.show()

    def scroll_active_view(self, view, delta):
        if delta>0:
            if view is self.axial_view:
                self.axial_index = min(self.axial_index + 2, self.volume_data.shape[2] - 1)
            elif view is self.sagittal_view:
                self.sagittal_index = min(self.sagittal_index + 2, self.volume_data.shape[0] - 1)
            elif view is self.coronal_view:
                self.coronal_index = min(self.coronal_index + 2, self.volume_data.shape[1] - 1)
        else:
            if view is self.axial_view:
                self.axial_index = max(self.axial_index - 2, 0)
            elif view is self.sagittal_view:
                self.sagittal_index = max(self.sagittal_index - 2, 0)
            elif view is self.coronal_view:
                self.coronal_index = max(self.coronal_index - 2, 0)
        
        self.update_slices()



### ---------------------------- ROS NODE ------------------------ ###
### -------------------------------------------------------------- ###
### -------------------------------------------------------------- ###

class ROSNode(Node, QObject):
    ros_data_received = pyqtSignal(object)
    def __init__(self):
        print("ROS node spinning")
        super().__init__('gui_node')
        QObject.__init__(self)
        self.desired_angles_publisher_ = self.create_publisher(Float64MultiArray, 'desired_angles', 1)
        self.actual_angels_subscriber = self.create_subscription(Float64MultiArray, 'actual_angles', self.subscriber_callback, 1)
        # self.app = QApplication(sys.argv)
        # self.viewer = MainWindow(volume_path, segmentation_path, self.desired_angles_publisher_)
    def subscriber_callback(self, msg):
        print("Data received")
        self.ros_data_received.emit(msg)

class ROSWorker(QRunnable):
    def __init__(self):
        super().__init__()
        self.node = ROSNode()
    
    def run(self):
        rclpy.spin(self.node)

def main(args=None):
    rclpy.init()
    ros_worker = ROSWorker()
    thread_pool = QThreadPool()
    thread_pool.start(ros_worker)

    app = QApplication(sys.argv)

    with open("src/pant_nodes/gui_config.yaml", 'r') as f:
        config_data = yaml.safe_load(f)
        
    volume_path = config_data.get("volume_path")
    segmentation_path = config_data.get("segmentation_path")
    
    viewer = MainWindow(volume_path, segmentation_path, ros_worker.node.desired_angles_publisher_)
    ros_worker.node.ros_data_received.connect(viewer.compute_actual_trajectory)
    viewer.show()

    sys.exit(app.exec_())


if __name__ == '__main__':
    main()
