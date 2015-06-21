#include "cctk_Types.h"
#include "cctk_WarnLevel.h"
#include "cctk_Parameter.h"
#include "cctki_Groups.h"
#include "cctki_FortranWrappers.h"
int CCTKi_BindingsFortranWrapperCactus(void *GH, void *fpointer);
int CactusBindingsVariables_Cactus_Initialise(void);
int CactusBindingsVariables_Cactus_Initialise(void)
{
  CCTKi_RegisterFortranWrapper("Cactus", CCTKi_BindingsFortranWrapperCactus);

  return 0;
}
