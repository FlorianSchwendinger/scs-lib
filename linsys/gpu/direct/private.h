#ifndef PRIV_H_GUARD
#define PRIV_H_GUARD

#ifdef __cplusplus
extern "C" {
#endif

#include "common.h"
#include "external/amd/amd.h"
#include "glbopts.h"
#include "linalg.h"
#include "scs.h"

#include <cublas_v2.h>
#include <cuda.h>
#include <cuda_runtime_api.h>
#include <cusparse.h>

struct SCS_LIN_SYS_WORK {
  scs_int Annz; /* num non-zeros in A matrix */
  /* CUDA */
  cublasHandle_t cublas_handle;
  cusparseHandle_t cusparse_handle;
  cusparseMatDescr_t descr;
  /* ALL BELOW HOSTED ON THE GPU */
  scs_float *z;     /* preconditioned */
  ScsMatrix *Ag;    /* A matrix on GPU */
  ScsMatrix *Agt;   /* A trans matrix on GPU */
};

#ifdef __cplusplus
}
#endif
#endif
