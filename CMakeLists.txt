cmake_minimum_required(VERSION 3.19)
project(Easy2DSandbox)

set(CMAKE_CXX_STANDARD 17)

find_library(GLFWLIB libglfw.3.3.dylib)
find_library(Easy2DLIB libEasy2D.1.0.dylib)
message(STATUS ${EASY2D_LIB})

include_directories(/usr/local/include)
add_executable(Easy2DSandbox main.cpp script1.cpp script1.h script2.cpp script2.h script3.cpp script3.h gameobject.cpp gameobject.h)
target_link_libraries(${CMAKE_PROJECT_NAME} PUBLIC ${Easy2DLIB} ${GLFWLIB})
