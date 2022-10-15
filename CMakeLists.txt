cmake_minimum_required(VERSION 3.0.0)
project(what VERSION 0.1.0)

add_subdirectory(linklist)
add_subdirectory(misc)
add_subdirectory(stack)
add_subdirectory(string)

add_executable(what main.cpp)

target_link_libraries(what
  linklist
  misc
  stack
  string
)
