#include "practice.h"
#include <cuda_runtime.h>
#include <curand.h>
#include <device_launch_parameters.h>

#include <chrono>
#include <iostream>
using namespace std;

__global__ void addTen(float *d, int count) {
  int tpb = blockDim.x * blockDim.y * blockDim.z;
  int tpib = threadIdx.x + blockDim.x * threadIdx.y +
             blockDim.x * blockDim.y * threadIdx.z;
  int bpg =
      blockIdx.x + gridDim.x * blockIdx.y + gridDim.x * gridDim.y * blockIdx.z;
  int tid = bpg * tpb + tpib;
  if (tid < count)
    d[tid] += 10;
}

int map_fun(int count) {
  curandGenerator_t gen;
  curandCreateGenerator(&gen, CURAND_RNG_PSEUDO_MTGP32);
  curandSetPseudoRandomGeneratorSeed(gen, time(nullptr));

  //  const int count = 123456;
  int size = count * sizeof(float);
  float *d;
  float h[count];
  cudaMalloc(&d, size);
  curandGenerateUniform(gen, d, count);

  dim3 block(8, 8, 8);
  dim3 grid(16, 16);

  addTen<<<grid, block>>>(d, count);
  cudaMemcpy(h, d, size, cudaMemcpyDeviceToHost);
  cudaFree(d);
  for (auto n : h) {
    cout << n << endl;
  }
  return 0;
}

int gather_fun(int count){
  curandGenerator_t gen;
  curandCreateGenerator(&gen, CURAND_RNG_PSEUDO_MTGP32);
  cout << count << endl;
  return 9;
}