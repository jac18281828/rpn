cmake_minimum_required(VERSION 2.8.9)

set(CMAKE_VERBOSE_MAKEFILE on)

set(MAJOR 1)
set(VERSION ${MAJOR}.0.0)

add_compile_options(-DRPN_VERSION=${VERSION} -Wshadow -Wpointer-arith -Wcast-qual -Wcast-align -Wwrite-strings -fno-common -ansi -pedantic)

project (rpn)

find_package(FLEX REQUIRED)

FLEX_TARGET(rpn src/tokens.l ${CMAKE_CURRENT_BINARY_DIR}/tokens.cpp)

FIND_PACKAGE(BISON REQUIRED)

BISON_TARGET(rpn src/rpn.y ${CMAKE_CURRENT_BINARY_DIR}/rpn.cpp)

set(SRC src/doublestacktype.cpp src/machine.cpp src/printerrorhandler.cpp src/stringstacktype.cpp ${FLEX_rpn_OUTPUTS} ${BISON_rpn_OUTPUTS})

add_executable(rpn  ${SRC} src/main.cpp)

target_include_directories(rpn PRIVATE include ${CMAKE_CURRENT_BINARY_DIR})

target_link_libraries(rpn ${FLEX_LIBRARIES} ${BISON_LIBRARIES} -lm)
