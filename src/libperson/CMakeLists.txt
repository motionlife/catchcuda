add_library(person Person.h Person.cpp Resource.h Resource.cpp)
target_include_directories (person INTERFACE ${CMAKE_CURRENT_SOURCE_DIR})