project(StreamTracerTests)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(tests runtests.cpp test_interp.cpp test_grid.cpp)
target_link_libraries(tests interp grid)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")
