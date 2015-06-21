#define THORN_IS_PUGHReduce
#include "cctk.h"
#include "cctk_Flesh.h"
#include "cctk_Groups.h"
#include "cctk_Comm.h"
#include "cctk_Arguments.h"

int CCTKi_BindingsFortranWrapperPUGHReduce(cGH *GH, void *fpointer);

int CCTKi_BindingsFortranWrapperPUGHReduce(cGH *GH, void *fpointer)
{
  void (*function)(PUGHREDUCE_C2F_PROTO);

  DECLARE_PUGHREDUCE_C2F
  INITIALISE_PUGHREDUCE_C2F

  function = (void (*)(PUGHREDUCE_C2F_PROTO))fpointer;

  function(PASS_PUGHREDUCE_C2F(GH));

  return 0;

}
