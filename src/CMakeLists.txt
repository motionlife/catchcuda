add_subdirectory(libperson)
add_subdirectory(libmycuda)

add_executable(cppfun main.cpp)
target_link_libraries(cppfun PRIVATE person mycuda)