# generated from rosidl_generator_py/resource/_idl.py.em
# with input from ethercat_msgs:srv/SetSdo.idl
# generated code does not contain a copyright notice


# Import statements for member types

import builtins  # noqa: E402, I100

import rosidl_parser.definition  # noqa: E402, I100


class Metaclass_SetSdo_Request(type):
    """Metaclass of message 'SetSdo_Request'."""

    _CREATE_ROS_MESSAGE = None
    _CONVERT_FROM_PY = None
    _CONVERT_TO_PY = None
    _DESTROY_ROS_MESSAGE = None
    _TYPE_SUPPORT = None

    __constants = {
    }

    @classmethod
    def __import_type_support__(cls):
        try:
            from rosidl_generator_py import import_type_support
            module = import_type_support('ethercat_msgs')
        except ImportError:
            import logging
            import traceback
            logger = logging.getLogger(
                'ethercat_msgs.srv.SetSdo_Request')
            logger.debug(
                'Failed to import needed modules for type support:\n' +
                traceback.format_exc())
        else:
            cls._CREATE_ROS_MESSAGE = module.create_ros_message_msg__srv__set_sdo__request
            cls._CONVERT_FROM_PY = module.convert_from_py_msg__srv__set_sdo__request
            cls._CONVERT_TO_PY = module.convert_to_py_msg__srv__set_sdo__request
            cls._TYPE_SUPPORT = module.type_support_msg__srv__set_sdo__request
            cls._DESTROY_ROS_MESSAGE = module.destroy_ros_message_msg__srv__set_sdo__request

    @classmethod
    def __prepare__(cls, name, bases, **kwargs):
        # list constant names here so that they appear in the help text of
        # the message class under "Data and other attributes defined here:"
        # as well as populate each message instance
        return {
        }


class SetSdo_Request(metaclass=Metaclass_SetSdo_Request):
    """Message class 'SetSdo_Request'."""

    __slots__ = [
        '_master_id',
        '_slave_position',
        '_sdo_index',
        '_sdo_subindex',
        '_sdo_data_type',
        '_sdo_value',
    ]

    _fields_and_field_types = {
        'master_id': 'int16',
        'slave_position': 'int16',
        'sdo_index': 'int16',
        'sdo_subindex': 'int16',
        'sdo_data_type': 'string',
        'sdo_value': 'string',
    }

    SLOT_TYPES = (
        rosidl_parser.definition.BasicType('int16'),  # noqa: E501
        rosidl_parser.definition.BasicType('int16'),  # noqa: E501
        rosidl_parser.definition.BasicType('int16'),  # noqa: E501
        rosidl_parser.definition.BasicType('int16'),  # noqa: E501
        rosidl_parser.definition.UnboundedString(),  # noqa: E501
        rosidl_parser.definition.UnboundedString(),  # noqa: E501
    )

    def __init__(self, **kwargs):
        assert all('_' + key in self.__slots__ for key in kwargs.keys()), \
            'Invalid arguments passed to constructor: %s' % \
            ', '.join(sorted(k for k in kwargs.keys() if '_' + k not in self.__slots__))
        self.master_id = kwargs.get('master_id', int())
        self.slave_position = kwargs.get('slave_position', int())
        self.sdo_index = kwargs.get('sdo_index', int())
        self.sdo_subindex = kwargs.get('sdo_subindex', int())
        self.sdo_data_type = kwargs.get('sdo_data_type', str())
        self.sdo_value = kwargs.get('sdo_value', str())

    def __repr__(self):
        typename = self.__class__.__module__.split('.')
        typename.pop()
        typename.append(self.__class__.__name__)
        args = []
        for s, t in zip(self.__slots__, self.SLOT_TYPES):
            field = getattr(self, s)
            fieldstr = repr(field)
            # We use Python array type for fields that can be directly stored
            # in them, and "normal" sequences for everything else.  If it is
            # a type that we store in an array, strip off the 'array' portion.
            if (
                isinstance(t, rosidl_parser.definition.AbstractSequence) and
                isinstance(t.value_type, rosidl_parser.definition.BasicType) and
                t.value_type.typename in ['float', 'double', 'int8', 'uint8', 'int16', 'uint16', 'int32', 'uint32', 'int64', 'uint64']
            ):
                if len(field) == 0:
                    fieldstr = '[]'
                else:
                    assert fieldstr.startswith('array(')
                    prefix = "array('X', "
                    suffix = ')'
                    fieldstr = fieldstr[len(prefix):-len(suffix)]
            args.append(s[1:] + '=' + fieldstr)
        return '%s(%s)' % ('.'.join(typename), ', '.join(args))

    def __eq__(self, other):
        if not isinstance(other, self.__class__):
            return False
        if self.master_id != other.master_id:
            return False
        if self.slave_position != other.slave_position:
            return False
        if self.sdo_index != other.sdo_index:
            return False
        if self.sdo_subindex != other.sdo_subindex:
            return False
        if self.sdo_data_type != other.sdo_data_type:
            return False
        if self.sdo_value != other.sdo_value:
            return False
        return True

    @classmethod
    def get_fields_and_field_types(cls):
        from copy import copy
        return copy(cls._fields_and_field_types)

    @builtins.property
    def master_id(self):
        """Message field 'master_id'."""
        return self._master_id

    @master_id.setter
    def master_id(self, value):
        if __debug__:
            assert \
                isinstance(value, int), \
                "The 'master_id' field must be of type 'int'"
            assert value >= -32768 and value < 32768, \
                "The 'master_id' field must be an integer in [-32768, 32767]"
        self._master_id = value

    @builtins.property
    def slave_position(self):
        """Message field 'slave_position'."""
        return self._slave_position

    @slave_position.setter
    def slave_position(self, value):
        if __debug__:
            assert \
                isinstance(value, int), \
                "The 'slave_position' field must be of type 'int'"
            assert value >= -32768 and value < 32768, \
                "The 'slave_position' field must be an integer in [-32768, 32767]"
        self._slave_position = value

    @builtins.property
    def sdo_index(self):
        """Message field 'sdo_index'."""
        return self._sdo_index

    @sdo_index.setter
    def sdo_index(self, value):
        if __debug__:
            assert \
                isinstance(value, int), \
                "The 'sdo_index' field must be of type 'int'"
            assert value >= -32768 and value < 32768, \
                "The 'sdo_index' field must be an integer in [-32768, 32767]"
        self._sdo_index = value

    @builtins.property
    def sdo_subindex(self):
        """Message field 'sdo_subindex'."""
        return self._sdo_subindex

    @sdo_subindex.setter
    def sdo_subindex(self, value):
        if __debug__:
            assert \
                isinstance(value, int), \
                "The 'sdo_subindex' field must be of type 'int'"
            assert value >= -32768 and value < 32768, \
                "The 'sdo_subindex' field must be an integer in [-32768, 32767]"
        self._sdo_subindex = value

    @builtins.property
    def sdo_data_type(self):
        """Message field 'sdo_data_type'."""
        return self._sdo_data_type

    @sdo_data_type.setter
    def sdo_data_type(self, value):
        if __debug__:
            assert \
                isinstance(value, str), \
                "The 'sdo_data_type' field must be of type 'str'"
        self._sdo_data_type = value

    @builtins.property
    def sdo_value(self):
        """Message field 'sdo_value'."""
        return self._sdo_value

    @sdo_value.setter
    def sdo_value(self, value):
        if __debug__:
            assert \
                isinstance(value, str), \
                "The 'sdo_value' field must be of type 'str'"
        self._sdo_value = value


# Import statements for member types

# already imported above
# import builtins

# already imported above
# import rosidl_parser.definition


class Metaclass_SetSdo_Response(type):
    """Metaclass of message 'SetSdo_Response'."""

    _CREATE_ROS_MESSAGE = None
    _CONVERT_FROM_PY = None
    _CONVERT_TO_PY = None
    _DESTROY_ROS_MESSAGE = None
    _TYPE_SUPPORT = None

    __constants = {
    }

    @classmethod
    def __import_type_support__(cls):
        try:
            from rosidl_generator_py import import_type_support
            module = import_type_support('ethercat_msgs')
        except ImportError:
            import logging
            import traceback
            logger = logging.getLogger(
                'ethercat_msgs.srv.SetSdo_Response')
            logger.debug(
                'Failed to import needed modules for type support:\n' +
                traceback.format_exc())
        else:
            cls._CREATE_ROS_MESSAGE = module.create_ros_message_msg__srv__set_sdo__response
            cls._CONVERT_FROM_PY = module.convert_from_py_msg__srv__set_sdo__response
            cls._CONVERT_TO_PY = module.convert_to_py_msg__srv__set_sdo__response
            cls._TYPE_SUPPORT = module.type_support_msg__srv__set_sdo__response
            cls._DESTROY_ROS_MESSAGE = module.destroy_ros_message_msg__srv__set_sdo__response

    @classmethod
    def __prepare__(cls, name, bases, **kwargs):
        # list constant names here so that they appear in the help text of
        # the message class under "Data and other attributes defined here:"
        # as well as populate each message instance
        return {
        }


class SetSdo_Response(metaclass=Metaclass_SetSdo_Response):
    """Message class 'SetSdo_Response'."""

    __slots__ = [
        '_success',
        '_sdo_return_message',
    ]

    _fields_and_field_types = {
        'success': 'boolean',
        'sdo_return_message': 'string',
    }

    SLOT_TYPES = (
        rosidl_parser.definition.BasicType('boolean'),  # noqa: E501
        rosidl_parser.definition.UnboundedString(),  # noqa: E501
    )

    def __init__(self, **kwargs):
        assert all('_' + key in self.__slots__ for key in kwargs.keys()), \
            'Invalid arguments passed to constructor: %s' % \
            ', '.join(sorted(k for k in kwargs.keys() if '_' + k not in self.__slots__))
        self.success = kwargs.get('success', bool())
        self.sdo_return_message = kwargs.get('sdo_return_message', str())

    def __repr__(self):
        typename = self.__class__.__module__.split('.')
        typename.pop()
        typename.append(self.__class__.__name__)
        args = []
        for s, t in zip(self.__slots__, self.SLOT_TYPES):
            field = getattr(self, s)
            fieldstr = repr(field)
            # We use Python array type for fields that can be directly stored
            # in them, and "normal" sequences for everything else.  If it is
            # a type that we store in an array, strip off the 'array' portion.
            if (
                isinstance(t, rosidl_parser.definition.AbstractSequence) and
                isinstance(t.value_type, rosidl_parser.definition.BasicType) and
                t.value_type.typename in ['float', 'double', 'int8', 'uint8', 'int16', 'uint16', 'int32', 'uint32', 'int64', 'uint64']
            ):
                if len(field) == 0:
                    fieldstr = '[]'
                else:
                    assert fieldstr.startswith('array(')
                    prefix = "array('X', "
                    suffix = ')'
                    fieldstr = fieldstr[len(prefix):-len(suffix)]
            args.append(s[1:] + '=' + fieldstr)
        return '%s(%s)' % ('.'.join(typename), ', '.join(args))

    def __eq__(self, other):
        if not isinstance(other, self.__class__):
            return False
        if self.success != other.success:
            return False
        if self.sdo_return_message != other.sdo_return_message:
            return False
        return True

    @classmethod
    def get_fields_and_field_types(cls):
        from copy import copy
        return copy(cls._fields_and_field_types)

    @builtins.property
    def success(self):
        """Message field 'success'."""
        return self._success

    @success.setter
    def success(self, value):
        if __debug__:
            assert \
                isinstance(value, bool), \
                "The 'success' field must be of type 'bool'"
        self._success = value

    @builtins.property
    def sdo_return_message(self):
        """Message field 'sdo_return_message'."""
        return self._sdo_return_message

    @sdo_return_message.setter
    def sdo_return_message(self, value):
        if __debug__:
            assert \
                isinstance(value, str), \
                "The 'sdo_return_message' field must be of type 'str'"
        self._sdo_return_message = value


class Metaclass_SetSdo(type):
    """Metaclass of service 'SetSdo'."""

    _TYPE_SUPPORT = None

    @classmethod
    def __import_type_support__(cls):
        try:
            from rosidl_generator_py import import_type_support
            module = import_type_support('ethercat_msgs')
        except ImportError:
            import logging
            import traceback
            logger = logging.getLogger(
                'ethercat_msgs.srv.SetSdo')
            logger.debug(
                'Failed to import needed modules for type support:\n' +
                traceback.format_exc())
        else:
            cls._TYPE_SUPPORT = module.type_support_srv__srv__set_sdo

            from ethercat_msgs.srv import _set_sdo
            if _set_sdo.Metaclass_SetSdo_Request._TYPE_SUPPORT is None:
                _set_sdo.Metaclass_SetSdo_Request.__import_type_support__()
            if _set_sdo.Metaclass_SetSdo_Response._TYPE_SUPPORT is None:
                _set_sdo.Metaclass_SetSdo_Response.__import_type_support__()


class SetSdo(metaclass=Metaclass_SetSdo):
    from ethercat_msgs.srv._set_sdo import SetSdo_Request as Request
    from ethercat_msgs.srv._set_sdo import SetSdo_Response as Response

    def __init__(self):
        raise NotImplementedError('Service classes can not be instantiated')
