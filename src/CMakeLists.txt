add_subdirectory(libperson)
add_subdirectory(libmycuda)
add_subdirectory(beautiful_cpp_stl_algorithms)
add_subdirectory(tests)

add_executable(cppfun main.cpp)
target_link_libraries(cppfun PRIVATE person mycuda)