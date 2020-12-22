set(CMAKE_CUDA_STANDARD 14)
if (UNIX OR LINUX)
    set(CMAKE_CUDA_COMPILER /usr/local/cuda/bin/nvcc)
endif (UNIX OR LINUX)

#file(GLOB cuda_common_src "common/inc/*.h" "common/inc/GL/*.h" "common/src/*.cpp")
add_library(mycuda
        vectorAdd.h utils.h practice.h thrust.h
        vectorAdd.cu deviceQuery.cu bandwidthTest.cu practice.cu thrust.cu)

target_include_directories(
        mycuda
        INTERFACE ${CMAKE_CURRENT_SOURCE_DIR}
        PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/common/inc/)

set_target_properties(
        mycuda
        PROPERTIES
        CUDA_SEPARABLE_COMPILATION ON)


# Find the cuda package
find_package(CUDA 11 REQUIRED)
target_link_libraries(mycuda ${CUDA_LIBRARIES} ${CUDA_curand_LIBRARY})



