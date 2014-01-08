#include "cuda.h"

#include <cuda.h>
#include <ftl/either.h>

namespace cuda {

ftl::either<error,void*> malloc(size_t size) {
  char* arr;

  cudaError_t ret = cudaMalloc(&arr, size);
  if (ret != cudaSuccess)
    return make_left<error>(ret);
  return make_right<void*>(arr);
}

}  // namespace cuda
