#define THORN_IS_CartGrid3D

#include <stdarg.h>

#include "cctk.h"
#include "cctk_Parameters.h"
#include "cctki_ScheduleBindings.h"

/* Prototypes for functions to be registered. */


/*@@
  @routine    CCTKi_BindingsParameterRecovery_CartGrid3D
  @date       
  @author     
  @desc 
  Creates the parameter recovery bindings for thorn CartGrid3D
  @enddesc 
  @calls     
  @calledby   
  @history 

  @endhistory

@@*/
int CCTKi_BindingsParameterRecovery_CartGrid3D(void);
int CCTKi_BindingsParameterRecovery_CartGrid3D(void)
{
  DECLARE_CCTK_PARAMETERS
  int result = 0;







  USE_CCTK_PARAMETERS;   return (result);
}
