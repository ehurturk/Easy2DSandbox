cmake_minimum_required(VERSION 3.19)
project(Easy2DSandbox)

set(CMAKE_CXX_STANDARD 17)

find_library(GLFWLIB libglfw.3.3.dylib)
find_library(Easy2DLIB libEasy2D.1.0.dylib)
message(STATUS ${EASY2D_LIB})

include_directories(/usr/local/include)
add_executable(Easy2DSandbox main.cpp scripts/script1.cpp scripts/script1.h scripts/script2.cpp scripts/script2.h scripts/script3.cpp scripts/script3.h scripts/gameobject.cpp scripts/gameobject.h)
target_link_libraries(${CMAKE_PROJECT_NAME} PUBLIC ${Easy2DLIB} ${GLFWLIB})
