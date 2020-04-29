cmake_minimum_required(VERSION 3.5)

#set(CMAKE_VERBOSE_MAKEFILE on)

set(MAJOR 1)
set(VERSION ${MAJOR}.0.0)

project (rpn LANGUAGES CXX VERSION ${VERSION})

add_compile_options(-std=c++17 -DRPN_VERSION=${VERSION})

find_package(FLEX REQUIRED)

FLEX_TARGET(rpn src/tokens.l ${CMAKE_CURRENT_BINARY_DIR}/tokens.cpp)

FIND_PACKAGE(BISON REQUIRED)

BISON_TARGET(rpn src/rpn.y ${CMAKE_CURRENT_BINARY_DIR}/rpn.cpp)

set(SRC src/printerrorhandler.cpp ${FLEX_rpn_OUTPUTS} ${BISON_rpn_OUTPUTS})

add_executable(rpn  ${SRC} src/main.cpp)

target_include_directories(rpn PRIVATE include ${CMAKE_CURRENT_BINARY_DIR})

target_link_libraries(rpn ${FLEX_LIBRARIES} ${BISON_LIBRARIES} m)

enable_testing()

add_executable(rpntest test/main.cpp test/bioptest.cpp test/uoptest.cpp test/ufuntest.cpp test/machinetest.cpp)

add_test(rpn ${CMAKE_CURRENT_BINARY_DIR}/rpntest)

target_include_directories(rpntest PRIVATE include test)
