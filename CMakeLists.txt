cmake_minimum_required(VERSION 3.5)
project(MyShell)

set(CMAKE_CXX_STANDARD 11)

set(CP_SOURCE_FILES cp_main.cpp cp.cpp cp.h)
set(RM_SOURCE_FILES rm.cpp rm.h rm_main.cpp)
set(MV_SOURCE_FILES mv.cpp mv.h mv_main.cpp)
set(MKDIR_SOURCE_FILES mkdir.cpp mkdir.h mkdir_main.cpp)
set(LS_SOURCE_FILES ls_main.cpp ls.cpp ls.h )
set(SHELL_SOURCE_FILES main.cpp)

add_executable(mycp ${CP_SOURCE_FILES})
add_executable(myrm ${RM_SOURCE_FILES})
add_executable(mymv ${MV_SOURCE_FILES})
add_executable(mymkdir ${MKDIR_SOURCE_FILES})
add_executable(myls ${LS_SOURCE_FILES})

add_executable(MyShell ${SHELL_SOURCE_FILES})

FIND_PACKAGE( Boost COMPONENTS filesystem program_options system REQUIRED )

INCLUDE_DIRECTORIES( ${Boost_INCLUDE_DIR} )

target_link_libraries( MyShell ${Boost_LIBRARIES} )
target_link_libraries( mycp ${Boost_LIBRARIES} )
target_link_libraries( myrm ${Boost_LIBRARIES} )
target_link_libraries( mymv ${Boost_LIBRARIES} )
target_link_libraries( mymkdir ${Boost_LIBRARIES} )
target_link_libraries( myls ${Boost_LIBRARIES} )
