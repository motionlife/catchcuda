set(CMAKE_CUDA_STANDARD 14)
if (UNIX OR LINUX)
    set(CMAKE_CUDA_COMPILER /usr/local/cuda-10.2/bin/nvcc)
endif (UNIX OR LINUX)

#file(GLOB cuda_common_src "common/inc/*.h" "common/inc/GL/*.h" "common/src/*.cpp")
add_library(mycuda vectorAdd.h vectorAdd.cu utils.h deviceQuery.cu bandwidthTest.cu)

target_include_directories(mycuda PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})
target_include_directories(mycuda PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/common/inc/)

set_target_properties(
        mycuda
        PROPERTIES
        CUDA_SEPARABLE_COMPILATION ON)
