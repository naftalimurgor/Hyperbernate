cmake_minimum_required(VERSION 3.14 FATAL_ERROR)
# Simple CMAKE guide: https://github.com/pyk/cmake-tutorial
# Define project  
project(
  Hyperbernate
  VERSION 1.0
  LANGUAGES CXX
)

# sources
file(GLOB SOURCES src/*.cpp)

# Define executable with sources
add_executable(Hyperbernate ${SOURCES})

# Define header location paths
target_include_directories(Hyperbernate PUBLIC "${CMAKE_CURRENT_LIST_DIR}/src/include")


# add imgui setup with opengl 
# create a mainloop window
