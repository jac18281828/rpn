# Copyright © John A Cairns <john@2ad.com> 2016-2020

# This file is part of RPN.

# RPN is free software: you can redistribute it and/or modify
# it under the terms of the GNU General Public License as published by
# the Free Software Foundation, either version 3 of the License, or
# (at your option) any later version.

# RPN is distributed in the hope that it will be useful,
# but WITHOUT ANY WARRANTY; without even the implied warranty of
# MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
# GNU General Public License for more details.

# You should have received a copy of the GNU General Public License
# along with Foobar.  If not, see <https://www.gnu.org/licenses/>.

cmake_minimum_required(VERSION 3.5)

#set(CMAKE_VERBOSE_MAKEFILE on)

set(MAJOR 1)
set(VERSION ${MAJOR}.0.1)

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
