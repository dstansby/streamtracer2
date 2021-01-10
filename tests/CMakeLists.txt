project(StreamTracerTests)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_library(interp ../src/interp.cpp)
add_library(grid ../src/grid.cpp)
add_executable(tests runtests.cpp test_interp.cpp)
target_link_libraries(tests interp grid)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} --coverage")
