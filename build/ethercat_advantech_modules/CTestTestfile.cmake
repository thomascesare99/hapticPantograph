# CMake generated Testfile for 
# Source directory: /home/telecom/ros2_pant_ec_ws/src/ethercat_driver_ros2/ethercat_plugins/ethercat_advantech_modules
# Build directory: /home/telecom/ros2_pant_ec_ws/build/ethercat_advantech_modules
# 
# This file includes the relevant testing commands required for 
# testing this directory and lists subdirectories to be tested as well.
add_test(test_load_advantech_plugins "/usr/bin/python3.10" "-u" "/opt/ros/humble/share/ament_cmake_test/cmake/run_test.py" "/home/telecom/ros2_pant_ec_ws/build/ethercat_advantech_modules/test_results/ethercat_advantech_modules/test_load_advantech_plugins.gtest.xml" "--package-name" "ethercat_advantech_modules" "--output-file" "/home/telecom/ros2_pant_ec_ws/build/ethercat_advantech_modules/ament_cmake_gmock/test_load_advantech_plugins.txt" "--command" "/home/telecom/ros2_pant_ec_ws/build/ethercat_advantech_modules/test_load_advantech_plugins" "--gtest_output=xml:/home/telecom/ros2_pant_ec_ws/build/ethercat_advantech_modules/test_results/ethercat_advantech_modules/test_load_advantech_plugins.gtest.xml")
set_tests_properties(test_load_advantech_plugins PROPERTIES  LABELS "gmock" REQUIRED_FILES "/home/telecom/ros2_pant_ec_ws/build/ethercat_advantech_modules/test_load_advantech_plugins" TIMEOUT "60" WORKING_DIRECTORY "/home/telecom/ros2_pant_ec_ws/build/ethercat_advantech_modules" _BACKTRACE_TRIPLES "/opt/ros/humble/share/ament_cmake_test/cmake/ament_add_test.cmake;125;add_test;/opt/ros/humble/share/ament_cmake_gmock/cmake/ament_add_gmock.cmake;106;ament_add_test;/opt/ros/humble/share/ament_cmake_gmock/cmake/ament_add_gmock.cmake;52;_ament_add_gmock;/home/telecom/ros2_pant_ec_ws/src/ethercat_driver_ros2/ethercat_plugins/ethercat_advantech_modules/CMakeLists.txt;45;ament_add_gmock;/home/telecom/ros2_pant_ec_ws/src/ethercat_driver_ros2/ethercat_plugins/ethercat_advantech_modules/CMakeLists.txt;0;")
add_test(copyright "/usr/bin/python3.10" "-u" "/opt/ros/humble/share/ament_cmake_test/cmake/run_test.py" "/home/telecom/ros2_pant_ec_ws/build/ethercat_advantech_modules/test_results/ethercat_advantech_modules/copyright.xunit.xml" "--package-name" "ethercat_advantech_modules" "--output-file" "/home/telecom/ros2_pant_ec_ws/build/ethercat_advantech_modules/ament_copyright/copyright.txt" "--command" "/opt/ros/humble/bin/ament_copyright" "--xunit-file" "/home/telecom/ros2_pant_ec_ws/build/ethercat_advantech_modules/test_results/ethercat_advantech_modules/copyright.xunit.xml")
set_tests_properties(copyright PROPERTIES  LABELS "copyright;linter" TIMEOUT "200" WORKING_DIRECTORY "/home/telecom/ros2_pant_ec_ws/src/ethercat_driver_ros2/ethercat_plugins/ethercat_advantech_modules" _BACKTRACE_TRIPLES "/opt/ros/humble/share/ament_cmake_test/cmake/ament_add_test.cmake;125;add_test;/opt/ros/humble/share/ament_cmake_copyright/cmake/ament_copyright.cmake;51;ament_add_test;/opt/ros/humble/share/ament_cmake_copyright/cmake/ament_cmake_copyright_lint_hook.cmake;18;ament_copyright;/opt/ros/humble/share/ament_cmake_copyright/cmake/ament_cmake_copyright_lint_hook.cmake;0;;/opt/ros/humble/share/ament_cmake_core/cmake/core/ament_execute_extensions.cmake;48;include;/opt/ros/humble/share/ament_lint_auto/cmake/ament_lint_auto_package_hook.cmake;21;ament_execute_extensions;/opt/ros/humble/share/ament_lint_auto/cmake/ament_lint_auto_package_hook.cmake;0;;/opt/ros/humble/share/ament_cmake_core/cmake/core/ament_execute_extensions.cmake;48;include;/opt/ros/humble/share/ament_cmake_core/cmake/core/ament_package.cmake;66;ament_execute_extensions;/home/telecom/ros2_pant_ec_ws/src/ethercat_driver_ros2/ethercat_plugins/ethercat_advantech_modules/CMakeLists.txt;64;ament_package;/home/telecom/ros2_pant_ec_ws/src/ethercat_driver_ros2/ethercat_plugins/ethercat_advantech_modules/CMakeLists.txt;0;")
add_test(cppcheck "/usr/bin/python3.10" "-u" "/opt/ros/humble/share/ament_cmake_test/cmake/run_test.py" "/home/telecom/ros2_pant_ec_ws/build/ethercat_advantech_modules/test_results/ethercat_advantech_modules/cppcheck.xunit.xml" "--package-name" "ethercat_advantech_modules" "--output-file" "/home/telecom/ros2_pant_ec_ws/build/ethercat_advantech_modules/ament_cppcheck/cppcheck.txt" "--command" "/opt/ros/humble/bin/ament_cppcheck" "--xunit-file" "/home/telecom/ros2_pant_ec_ws/build/ethercat_advantech_modules/test_results/ethercat_advantech_modules/cppcheck.xunit.xml" "--include_dirs" "/home/telecom/ros2_pant_ec_ws/src/ethercat_driver_ros2/ethercat_plugins/ethercat_advantech_modules/include" "/home/telecom/ros2_pant_ec_ws/src/ethercat_driver_ros2/ethercat_plugins/ethercat_advantech_modules/include")
set_tests_properties(cppcheck PROPERTIES  LABELS "cppcheck;linter" TIMEOUT "300" WORKING_DIRECTORY "/home/telecom/ros2_pant_ec_ws/src/ethercat_driver_ros2/ethercat_plugins/ethercat_advantech_modules" _BACKTRACE_TRIPLES "/opt/ros/humble/share/ament_cmake_test/cmake/ament_add_test.cmake;125;add_test;/opt/ros/humble/share/ament_cmake_cppcheck/cmake/ament_cppcheck.cmake;66;ament_add_test;/opt/ros/humble/share/ament_cmake_cppcheck/cmake/ament_cmake_cppcheck_lint_hook.cmake;83;ament_cppcheck;/opt/ros/humble/share/ament_cmake_cppcheck/cmake/ament_cmake_cppcheck_lint_hook.cmake;0;;/opt/ros/humble/share/ament_cmake_core/cmake/core/ament_execute_extensions.cmake;48;include;/opt/ros/humble/share/ament_lint_auto/cmake/ament_lint_auto_package_hook.cmake;21;ament_execute_extensions;/opt/ros/humble/share/ament_lint_auto/cmake/ament_lint_auto_package_hook.cmake;0;;/opt/ros/humble/share/ament_cmake_core/cmake/core/ament_execute_extensions.cmake;48;include;/opt/ros/humble/share/ament_cmake_core/cmake/core/ament_package.cmake;66;ament_execute_extensions;/home/telecom/ros2_pant_ec_ws/src/ethercat_driver_ros2/ethercat_plugins/ethercat_advantech_modules/CMakeLists.txt;64;ament_package;/home/telecom/ros2_pant_ec_ws/src/ethercat_driver_ros2/ethercat_plugins/ethercat_advantech_modules/CMakeLists.txt;0;")
add_test(cpplint "/usr/bin/python3.10" "-u" "/opt/ros/humble/share/ament_cmake_test/cmake/run_test.py" "/home/telecom/ros2_pant_ec_ws/build/ethercat_advantech_modules/test_results/ethercat_advantech_modules/cpplint.xunit.xml" "--package-name" "ethercat_advantech_modules" "--output-file" "/home/telecom/ros2_pant_ec_ws/build/ethercat_advantech_modules/ament_cpplint/cpplint.txt" "--command" "/opt/ros/humble/bin/ament_cpplint" "--xunit-file" "/home/telecom/ros2_pant_ec_ws/build/ethercat_advantech_modules/test_results/ethercat_advantech_modules/cpplint.xunit.xml")
set_tests_properties(cpplint PROPERTIES  LABELS "cpplint;linter" TIMEOUT "120" WORKING_DIRECTORY "/home/telecom/ros2_pant_ec_ws/src/ethercat_driver_ros2/ethercat_plugins/ethercat_advantech_modules" _BACKTRACE_TRIPLES "/opt/ros/humble/share/ament_cmake_test/cmake/ament_add_test.cmake;125;add_test;/opt/ros/humble/share/ament_cmake_cpplint/cmake/ament_cpplint.cmake;68;ament_add_test;/opt/ros/humble/share/ament_cmake_cpplint/cmake/ament_cmake_cpplint_lint_hook.cmake;35;ament_cpplint;/opt/ros/humble/share/ament_cmake_cpplint/cmake/ament_cmake_cpplint_lint_hook.cmake;0;;/opt/ros/humble/share/ament_cmake_core/cmake/core/ament_execute_extensions.cmake;48;include;/opt/ros/humble/share/ament_lint_auto/cmake/ament_lint_auto_package_hook.cmake;21;ament_execute_extensions;/opt/ros/humble/share/ament_lint_auto/cmake/ament_lint_auto_package_hook.cmake;0;;/opt/ros/humble/share/ament_cmake_core/cmake/core/ament_execute_extensions.cmake;48;include;/opt/ros/humble/share/ament_cmake_core/cmake/core/ament_package.cmake;66;ament_execute_extensions;/home/telecom/ros2_pant_ec_ws/src/ethercat_driver_ros2/ethercat_plugins/ethercat_advantech_modules/CMakeLists.txt;64;ament_package;/home/telecom/ros2_pant_ec_ws/src/ethercat_driver_ros2/ethercat_plugins/ethercat_advantech_modules/CMakeLists.txt;0;")
add_test(lint_cmake "/usr/bin/python3.10" "-u" "/opt/ros/humble/share/ament_cmake_test/cmake/run_test.py" "/home/telecom/ros2_pant_ec_ws/build/ethercat_advantech_modules/test_results/ethercat_advantech_modules/lint_cmake.xunit.xml" "--package-name" "ethercat_advantech_modules" "--output-file" "/home/telecom/ros2_pant_ec_ws/build/ethercat_advantech_modules/ament_lint_cmake/lint_cmake.txt" "--command" "/opt/ros/humble/bin/ament_lint_cmake" "--xunit-file" "/home/telecom/ros2_pant_ec_ws/build/ethercat_advantech_modules/test_results/ethercat_advantech_modules/lint_cmake.xunit.xml")
set_tests_properties(lint_cmake PROPERTIES  LABELS "lint_cmake;linter" TIMEOUT "60" WORKING_DIRECTORY "/home/telecom/ros2_pant_ec_ws/src/ethercat_driver_ros2/ethercat_plugins/ethercat_advantech_modules" _BACKTRACE_TRIPLES "/opt/ros/humble/share/ament_cmake_test/cmake/ament_add_test.cmake;125;add_test;/opt/ros/humble/share/ament_cmake_lint_cmake/cmake/ament_lint_cmake.cmake;47;ament_add_test;/opt/ros/humble/share/ament_cmake_lint_cmake/cmake/ament_cmake_lint_cmake_lint_hook.cmake;21;ament_lint_cmake;/opt/ros/humble/share/ament_cmake_lint_cmake/cmake/ament_cmake_lint_cmake_lint_hook.cmake;0;;/opt/ros/humble/share/ament_cmake_core/cmake/core/ament_execute_extensions.cmake;48;include;/opt/ros/humble/share/ament_lint_auto/cmake/ament_lint_auto_package_hook.cmake;21;ament_execute_extensions;/opt/ros/humble/share/ament_lint_auto/cmake/ament_lint_auto_package_hook.cmake;0;;/opt/ros/humble/share/ament_cmake_core/cmake/core/ament_execute_extensions.cmake;48;include;/opt/ros/humble/share/ament_cmake_core/cmake/core/ament_package.cmake;66;ament_execute_extensions;/home/telecom/ros2_pant_ec_ws/src/ethercat_driver_ros2/ethercat_plugins/ethercat_advantech_modules/CMakeLists.txt;64;ament_package;/home/telecom/ros2_pant_ec_ws/src/ethercat_driver_ros2/ethercat_plugins/ethercat_advantech_modules/CMakeLists.txt;0;")
add_test(uncrustify "/usr/bin/python3.10" "-u" "/opt/ros/humble/share/ament_cmake_test/cmake/run_test.py" "/home/telecom/ros2_pant_ec_ws/build/ethercat_advantech_modules/test_results/ethercat_advantech_modules/uncrustify.xunit.xml" "--package-name" "ethercat_advantech_modules" "--output-file" "/home/telecom/ros2_pant_ec_ws/build/ethercat_advantech_modules/ament_uncrustify/uncrustify.txt" "--command" "/opt/ros/humble/bin/ament_uncrustify" "--xunit-file" "/home/telecom/ros2_pant_ec_ws/build/ethercat_advantech_modules/test_results/ethercat_advantech_modules/uncrustify.xunit.xml")
set_tests_properties(uncrustify PROPERTIES  LABELS "uncrustify;linter" TIMEOUT "60" WORKING_DIRECTORY "/home/telecom/ros2_pant_ec_ws/src/ethercat_driver_ros2/ethercat_plugins/ethercat_advantech_modules" _BACKTRACE_TRIPLES "/opt/ros/humble/share/ament_cmake_test/cmake/ament_add_test.cmake;125;add_test;/opt/ros/humble/share/ament_cmake_uncrustify/cmake/ament_uncrustify.cmake;70;ament_add_test;/opt/ros/humble/share/ament_cmake_uncrustify/cmake/ament_cmake_uncrustify_lint_hook.cmake;34;ament_uncrustify;/opt/ros/humble/share/ament_cmake_uncrustify/cmake/ament_cmake_uncrustify_lint_hook.cmake;0;;/opt/ros/humble/share/ament_cmake_core/cmake/core/ament_execute_extensions.cmake;48;include;/opt/ros/humble/share/ament_lint_auto/cmake/ament_lint_auto_package_hook.cmake;21;ament_execute_extensions;/opt/ros/humble/share/ament_lint_auto/cmake/ament_lint_auto_package_hook.cmake;0;;/opt/ros/humble/share/ament_cmake_core/cmake/core/ament_execute_extensions.cmake;48;include;/opt/ros/humble/share/ament_cmake_core/cmake/core/ament_package.cmake;66;ament_execute_extensions;/home/telecom/ros2_pant_ec_ws/src/ethercat_driver_ros2/ethercat_plugins/ethercat_advantech_modules/CMakeLists.txt;64;ament_package;/home/telecom/ros2_pant_ec_ws/src/ethercat_driver_ros2/ethercat_plugins/ethercat_advantech_modules/CMakeLists.txt;0;")
add_test(xmllint "/usr/bin/python3.10" "-u" "/opt/ros/humble/share/ament_cmake_test/cmake/run_test.py" "/home/telecom/ros2_pant_ec_ws/build/ethercat_advantech_modules/test_results/ethercat_advantech_modules/xmllint.xunit.xml" "--package-name" "ethercat_advantech_modules" "--output-file" "/home/telecom/ros2_pant_ec_ws/build/ethercat_advantech_modules/ament_xmllint/xmllint.txt" "--command" "/opt/ros/humble/bin/ament_xmllint" "--xunit-file" "/home/telecom/ros2_pant_ec_ws/build/ethercat_advantech_modules/test_results/ethercat_advantech_modules/xmllint.xunit.xml")
set_tests_properties(xmllint PROPERTIES  LABELS "xmllint;linter" TIMEOUT "60" WORKING_DIRECTORY "/home/telecom/ros2_pant_ec_ws/src/ethercat_driver_ros2/ethercat_plugins/ethercat_advantech_modules" _BACKTRACE_TRIPLES "/opt/ros/humble/share/ament_cmake_test/cmake/ament_add_test.cmake;125;add_test;/opt/ros/humble/share/ament_cmake_xmllint/cmake/ament_xmllint.cmake;50;ament_add_test;/opt/ros/humble/share/ament_cmake_xmllint/cmake/ament_cmake_xmllint_lint_hook.cmake;18;ament_xmllint;/opt/ros/humble/share/ament_cmake_xmllint/cmake/ament_cmake_xmllint_lint_hook.cmake;0;;/opt/ros/humble/share/ament_cmake_core/cmake/core/ament_execute_extensions.cmake;48;include;/opt/ros/humble/share/ament_lint_auto/cmake/ament_lint_auto_package_hook.cmake;21;ament_execute_extensions;/opt/ros/humble/share/ament_lint_auto/cmake/ament_lint_auto_package_hook.cmake;0;;/opt/ros/humble/share/ament_cmake_core/cmake/core/ament_execute_extensions.cmake;48;include;/opt/ros/humble/share/ament_cmake_core/cmake/core/ament_package.cmake;66;ament_execute_extensions;/home/telecom/ros2_pant_ec_ws/src/ethercat_driver_ros2/ethercat_plugins/ethercat_advantech_modules/CMakeLists.txt;64;ament_package;/home/telecom/ros2_pant_ec_ws/src/ethercat_driver_ros2/ethercat_plugins/ethercat_advantech_modules/CMakeLists.txt;0;")
subdirs("gmock")
subdirs("gtest")
