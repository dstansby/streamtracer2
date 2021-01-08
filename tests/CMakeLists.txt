project(StreamTracerTests)

add_library(interp ../src/interp.cpp)
add_executable(tests runtests.cpp test_interp.cpp)
target_link_libraries(tests interp)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")
