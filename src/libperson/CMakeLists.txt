add_library(person Person.h Person.cpp Resource.h Resource.cpp)
target_include_directories (person PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})