cmake_minimum_required(VERSION 3.7)
project(MyShell)

set(CMAKE_CXX_STANDARD 11)

set(SOURCE_FILES main.cpp)
add_executable(MyShell ${SOURCE_FILES})
FIND_PACKAGE( Boost COMPONENTS filesystem program_options system REQUIRED )

INCLUDE_DIRECTORIES( ${Boost_INCLUDE_DIR} )

target_link_libraries( MyShell ${Boost_LIBRARIES} )
