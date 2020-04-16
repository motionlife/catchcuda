set(CMAKE_CUDA_STANDARD 14)
set(CMAKE_CUDA_COMPILER /usr/local/cuda-10.2/bin/nvcc)

#file(GLOB cuda_common_src
##        "common/inc/*.h"
##        "common/inc/GL/*.h"
##        "common/src/*.cpp"
#        )

add_library(mycuda vectorAdd.h vectorAdd.cu)
target_include_directories (mycuda PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})
target_include_directories (mycuda PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/common/inc/)
target_include_directories (mycuda PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/common/inc/GL/)

set_target_properties(
        mycuda
        PROPERTIES
        CUDA_SEPARABLE_COMPILATION ON)
