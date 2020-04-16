add_subdirectory(libperson)
add_subdirectory(libmycuda)

add_executable(cppfun main.cpp)
target_link_libraries(cppfun LINK_PUBLIC person)
target_link_libraries(cppfun LINK_PUBLIC mycuda)