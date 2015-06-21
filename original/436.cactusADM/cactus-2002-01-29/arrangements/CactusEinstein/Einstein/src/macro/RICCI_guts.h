/*@@
  @header   RICCI_guts.h
  @date     Jun 98
  @author   Gabrielle Allen
  @desc
  Macro to calculate the components of the Ricci tensor. 

  Requires: Second derivatives of physical metric
            Christoffel symbols of first kind
            Christoffel symbols of second kind
            Upper physical metric

  Provides: Components of the physical Ricci tensor

  @enddesc
@@*/

#ifndef RICCI_GUTS
#define RICCI_GUTS

#include "CactusEinstein/Einstein/src/macro/UPPERMET_guts.h"
#include "CactusEinstein/Einstein/src/macro/DDG_guts.h"
#include "CactusEinstein/Einstein/src/macro/CHR1_guts.h"
#include "CactusEinstein/Einstein/src/macro/CHR2_guts.h"

#ifdef FCODE

      RICCI_RXX = (DXYDG_DXYDGXY+(-DXXDG_DXXDGYY-DYYDG_DYYDGXX)/2 -
     & CHR1_XYY*CHR2_XXX +CHR1_XXY*CHR2_XXY-CHR1_YYY*CHR2_YXX +
     & CHR1_YXY*CHR2_YXY - CHR1_ZYY*CHR2_ZXX +
     & CHR1_ZXY*CHR2_ZXY)*UPPERMET_UYY + (-DXXDG_DXXDGYZ + DXYDG_DXYDGXZ +
     & DXZDG_DXZDGXY - DYZDG_DYZDGXX - 2*(CHR1_YYZ*CHR2_YXX +
     & CHR1_ZYZ*CHR2_ZXX) + 2*(-(CHR1_XYZ*CHR2_XXX) + CHR1_XXZ*CHR2_XXY +
     & CHR1_YXZ*CHR2_YXY + CHR1_ZXZ*CHR2_ZXY))*UPPERMET_UYZ + (DXZDG_DXZDGXZ
     & + (-DXXDG_DXXDGZZ - DZZDG_DZZDGXX)/2 - CHR1_XZZ*CHR2_XXX +
     & CHR1_XXZ*CHR2_XXZ - CHR1_YZZ*CHR2_YXX + CHR1_YXZ*CHR2_YXZ -
     & CHR1_ZZZ*CHR2_ZXX + CHR1_ZXZ*CHR2_ZXZ)*UPPERMET_UZZ

      RICCI_RXY = (-DXYDG_DXYDGXY + (DXXDG_DXXDGYY + DYYDG_DYYDGXX)/2 +
     & CHR1_XYY*CHR2_XXX - CHR1_XXY*CHR2_XXY + CHR1_YYY*CHR2_YXX -
     & CHR1_YXY*CHR2_YXY + CHR1_ZYY*CHR2_ZXX -
     & CHR1_ZXY*CHR2_ZXY)*UPPERMET_UXY + ((DXXDG_DXXDGYZ - DXYDG_DXYDGXZ -
     & DXZDG_DXZDGXY + DYZDG_DYZDGXX)/2 + CHR1_XYZ*CHR2_XXX -
     & CHR1_XXZ*CHR2_XXY + CHR1_YYZ*CHR2_YXX - CHR1_YXZ*CHR2_YXY +
     & CHR1_ZYZ*CHR2_ZXX - CHR1_ZXZ*CHR2_ZXY)*UPPERMET_UXZ +
     & ((-DXYDG_DXYDGYZ + DXZDG_DXZDGYY + DYYDG_DYYDGXZ - DYZDG_DYZDGXY)/2 -
     & CHR1_XYZ*CHR2_XXY + CHR1_XYY*CHR2_XXZ - CHR1_YYZ*CHR2_YXY +
     & CHR1_YYY*CHR2_YXZ - CHR1_ZYZ*CHR2_ZXY +
     & CHR1_ZYY*CHR2_ZXZ)*UPPERMET_UYZ + ((-DXYDG_DXYDGZZ + DXZDG_DXZDGYZ +
     & DYZDG_DYZDGXZ - DZZDG_DZZDGXY)/2 - CHR1_XZZ*CHR2_XXY +
     & CHR1_XYZ*CHR2_XXZ - CHR1_YZZ*CHR2_YXY + CHR1_YYZ*CHR2_YXZ -
     & CHR1_ZZZ*CHR2_ZXY + CHR1_ZYZ*CHR2_ZXZ)*UPPERMET_UZZ ;

      RICCI_RXZ = ((DXXDG_DXXDGYZ - DXYDG_DXYDGXZ - DXZDG_DXZDGXY +
     & DYZDG_DYZDGXX)/2 + CHR1_XYZ*CHR2_XXX - CHR1_XXZ*CHR2_XXY +
     & CHR1_YYZ*CHR2_YXX - CHR1_YXZ*CHR2_YXY + CHR1_ZYZ*CHR2_ZXX -
     & CHR1_ZXZ*CHR2_ZXY)*UPPERMET_UXY + (-DXZDG_DXZDGXZ + (DXXDG_DXXDGZZ +
     & DZZDG_DZZDGXX)/2 + CHR1_XZZ*CHR2_XXX - CHR1_XXZ*CHR2_XXZ +
     & CHR1_YZZ*CHR2_YXX - CHR1_YXZ*CHR2_YXZ + CHR1_ZZZ*CHR2_ZXX -
     & CHR1_ZXZ*CHR2_ZXZ)*UPPERMET_UXZ + ((DXYDG_DXYDGYZ - DXZDG_DXZDGYY -
     & DYYDG_DYYDGXZ + DYZDG_DYZDGXY)/2 + CHR1_XYZ*CHR2_XXY -
     & CHR1_XYY*CHR2_XXZ + CHR1_YYZ*CHR2_YXY - CHR1_YYY*CHR2_YXZ +
     & CHR1_ZYZ*CHR2_ZXY - CHR1_ZYY*CHR2_ZXZ)*UPPERMET_UYY + ((DXYDG_DXYDGZZ
     & - DXZDG_DXZDGYZ - DYZDG_DYZDGXZ + DZZDG_DZZDGXY)/2 + CHR1_XZZ*CHR2_XXY
     & - CHR1_XYZ*CHR2_XXZ + CHR1_YZZ*CHR2_YXY - CHR1_YYZ*CHR2_YXZ +
     & CHR1_ZZZ*CHR2_ZXY - CHR1_ZYZ*CHR2_ZXZ)*UPPERMET_UYZ ;

      RICCI_RYY = (DXYDG_DXYDGXY + (-DXXDG_DXXDGYY - DYYDG_DYYDGXX)/2 -
     & CHR1_XYY*CHR2_XXX + CHR1_XXY*CHR2_XXY - CHR1_YYY*CHR2_YXX +
     & CHR1_YXY*CHR2_YXY - CHR1_ZYY*CHR2_ZXX +
     & CHR1_ZXY*CHR2_ZXY)*UPPERMET_UXX + (DXYDG_DXYDGYZ - DXZDG_DXZDGYY -
     & DYYDG_DYYDGXZ + DYZDG_DYZDGXY + 2*(CHR1_XYZ*CHR2_XXY -
     & CHR1_XYY*CHR2_XXZ + CHR1_YYZ*CHR2_YXY + CHR1_ZYZ*CHR2_ZXY) -
     & 2*(CHR1_YYY*CHR2_YXZ + CHR1_ZYY*CHR2_ZXZ)) *UPPERMET_UXZ +
     & (DYZDG_DYZDGYZ + (-DYYDG_DYYDGZZ - DZZDG_DZZDGYY)/2 -
     & CHR1_XZZ*CHR2_XYY + CHR1_XYZ*CHR2_XYZ - CHR1_YZZ*CHR2_YYY +
     & CHR1_YYZ*CHR2_YYZ - CHR1_ZZZ*CHR2_ZYY +
     & CHR1_ZYZ*CHR2_ZYZ)*UPPERMET_UZZ ;

      RICCI_RYZ = ((-DXXDG_DXXDGYZ + DXYDG_DXYDGXZ + DXZDG_DXZDGXY -
     & DYZDG_DYZDGXX)/2 - CHR1_XYZ*CHR2_XXX + CHR1_XXZ*CHR2_XXY -
     & CHR1_YYZ*CHR2_YXX + CHR1_YXZ*CHR2_YXY - CHR1_ZYZ*CHR2_ZXX +
     & CHR1_ZXZ*CHR2_ZXY)*UPPERMET_UXX + ((-DXYDG_DXYDGYZ + DXZDG_DXZDGYY +
     & DYYDG_DYYDGXZ - DYZDG_DYZDGXY)/2 - CHR1_XYZ*CHR2_XXY +
     & CHR1_XYY*CHR2_XXZ - CHR1_YYZ*CHR2_YXY + CHR1_YYY*CHR2_YXZ -
     & CHR1_ZYZ*CHR2_ZXY + CHR1_ZYY*CHR2_ZXZ)*UPPERMET_UXY + ((DXYDG_DXYDGZZ
     & - DXZDG_DXZDGYZ - DYZDG_DYZDGXZ + DZZDG_DZZDGXY)/2 + CHR1_XZZ*CHR2_XXY
     & - CHR1_XYZ*CHR2_XXZ + CHR1_YZZ*CHR2_YXY - CHR1_YYZ*CHR2_YXZ +
     & CHR1_ZZZ*CHR2_ZXY - CHR1_ZYZ*CHR2_ZXZ)*UPPERMET_UXZ + (-DYZDG_DYZDGYZ
     & + (DYYDG_DYYDGZZ + DZZDG_DZZDGYY)/2 + CHR1_XZZ*CHR2_XYY -
     & CHR1_XYZ*CHR2_XYZ + CHR1_YZZ*CHR2_YYY - CHR1_YYZ*CHR2_YYZ +
     & CHR1_ZZZ*CHR2_ZYY - CHR1_ZYZ*CHR2_ZYZ)*UPPERMET_UYZ ;

      RICCI_RZZ = (DXZDG_DXZDGXZ + (-DXXDG_DXXDGZZ - DZZDG_DZZDGXX)/2 -
     & CHR1_XZZ*CHR2_XXX + CHR1_XXZ*CHR2_XXZ - CHR1_YZZ*CHR2_YXX +
     & CHR1_YXZ*CHR2_YXZ - CHR1_ZZZ*CHR2_ZXX +
     & CHR1_ZXZ*CHR2_ZXZ)*UPPERMET_UXX + (-DXYDG_DXYDGZZ + DXZDG_DXZDGYZ +
     & DYZDG_DYZDGXZ - DZZDG_DZZDGXY - 2*(CHR1_YZZ*CHR2_YXY +
     & CHR1_ZZZ*CHR2_ZXY) + 2*(-(CHR1_XZZ*CHR2_XXY) + CHR1_XYZ*CHR2_XXZ +
     & CHR1_YYZ*CHR2_YXZ + CHR1_ZYZ*CHR2_ZXZ))*UPPERMET_UXY + (DYZDG_DYZDGYZ
     & + (-DYYDG_DYYDGZZ - DZZDG_DZZDGYY)/2 - CHR1_XZZ*CHR2_XYY +
     & CHR1_XYZ*CHR2_XYZ - CHR1_YZZ*CHR2_YYY + CHR1_YYZ*CHR2_YYZ -
     & CHR1_ZZZ*CHR2_ZYY + CHR1_ZYZ*CHR2_ZYZ)*UPPERMET_UYY ;

#endif

#ifdef CCODE 

      RICCI_RXX =  (DXYDG_DXYDGXY+(-DXXDG_DXXDGYY-DYYDG_DYYDGXX)/2 -
      CHR1_XYY*CHR2_XXX +CHR1_XXY*CHR2_XXY-CHR1_YYY*CHR2_YXX +
      CHR1_YXY*CHR2_YXY - CHR1_ZYY*CHR2_ZXX +
      CHR1_ZXY*CHR2_ZXY)*UPPERMET_UYY + (-DXXDG_DXXDGYZ + DXYDG_DXYDGXZ +
      DXZDG_DXZDGXY - DYZDG_DYZDGXX - 2*(CHR1_YYZ*CHR2_YXX +
      CHR1_ZYZ*CHR2_ZXX) + 2*(-(CHR1_XYZ*CHR2_XXX) + CHR1_XXZ*CHR2_XXY +
      CHR1_YXZ*CHR2_YXY + CHR1_ZXZ*CHR2_ZXY))*UPPERMET_UYZ + (DXZDG_DXZDGXZ
      + (-DXXDG_DXXDGZZ - DZZDG_DZZDGXX)/2 - CHR1_XZZ*CHR2_XXX +
      CHR1_XXZ*CHR2_XXZ - CHR1_YZZ*CHR2_YXX + CHR1_YXZ*CHR2_YXZ -
      CHR1_ZZZ*CHR2_ZXX + CHR1_ZXZ*CHR2_ZXZ)*UPPERMET_UZZ;

      RICCI_RXY = (-DXYDG_DXYDGXY + (DXXDG_DXXDGYY + DYYDG_DYYDGXX)/2 +
      CHR1_XYY*CHR2_XXX - CHR1_XXY*CHR2_XXY + CHR1_YYY*CHR2_YXX -
      CHR1_YXY*CHR2_YXY + CHR1_ZYY*CHR2_ZXX -
      CHR1_ZXY*CHR2_ZXY)*UPPERMET_UXY + ((DXXDG_DXXDGYZ - DXYDG_DXYDGXZ -
      DXZDG_DXZDGXY + DYZDG_DYZDGXX)/2 + CHR1_XYZ*CHR2_XXX -
      CHR1_XXZ*CHR2_XXY + CHR1_YYZ*CHR2_YXX - CHR1_YXZ*CHR2_YXY +
      CHR1_ZYZ*CHR2_ZXX - CHR1_ZXZ*CHR2_ZXY)*UPPERMET_UXZ +
      ((-DXYDG_DXYDGYZ + DXZDG_DXZDGYY + DYYDG_DYYDGXZ - DYZDG_DYZDGXY)/2 -
      CHR1_XYZ*CHR2_XXY + CHR1_XYY*CHR2_XXZ - CHR1_YYZ*CHR2_YXY +
      CHR1_YYY*CHR2_YXZ - CHR1_ZYZ*CHR2_ZXY +
      CHR1_ZYY*CHR2_ZXZ)*UPPERMET_UYZ + ((-DXYDG_DXYDGZZ + DXZDG_DXZDGYZ +
      DYZDG_DYZDGXZ - DZZDG_DZZDGXY)/2 - CHR1_XZZ*CHR2_XXY +
      CHR1_XYZ*CHR2_XXZ - CHR1_YZZ*CHR2_YXY + CHR1_YYZ*CHR2_YXZ -
      CHR1_ZZZ*CHR2_ZXY + CHR1_ZYZ*CHR2_ZXZ)*UPPERMET_UZZ ;

      RICCI_RXZ = ((DXXDG_DXXDGYZ - DXYDG_DXYDGXZ - DXZDG_DXZDGXY +
      DYZDG_DYZDGXX)/2 + CHR1_XYZ*CHR2_XXX - CHR1_XXZ*CHR2_XXY +
      CHR1_YYZ*CHR2_YXX - CHR1_YXZ*CHR2_YXY + CHR1_ZYZ*CHR2_ZXX -
      CHR1_ZXZ*CHR2_ZXY)*UPPERMET_UXY + (-DXZDG_DXZDGXZ + (DXXDG_DXXDGZZ +
      DZZDG_DZZDGXX)/2 + CHR1_XZZ*CHR2_XXX - CHR1_XXZ*CHR2_XXZ +
      CHR1_YZZ*CHR2_YXX - CHR1_YXZ*CHR2_YXZ + CHR1_ZZZ*CHR2_ZXX -
      CHR1_ZXZ*CHR2_ZXZ)*UPPERMET_UXZ + ((DXYDG_DXYDGYZ - DXZDG_DXZDGYY -
      DYYDG_DYYDGXZ + DYZDG_DYZDGXY)/2 + CHR1_XYZ*CHR2_XXY -
      CHR1_XYY*CHR2_XXZ + CHR1_YYZ*CHR2_YXY - CHR1_YYY*CHR2_YXZ +
      CHR1_ZYZ*CHR2_ZXY - CHR1_ZYY*CHR2_ZXZ)*UPPERMET_UYY + ((DXYDG_DXYDGZZ
      - DXZDG_DXZDGYZ - DYZDG_DYZDGXZ + DZZDG_DZZDGXY)/2 + CHR1_XZZ*CHR2_XXY
      - CHR1_XYZ*CHR2_XXZ + CHR1_YZZ*CHR2_YXY - CHR1_YYZ*CHR2_YXZ +
      CHR1_ZZZ*CHR2_ZXY - CHR1_ZYZ*CHR2_ZXZ)*UPPERMET_UYZ ;

      RICCI_RYY = (DXYDG_DXYDGXY + (-DXXDG_DXXDGYY - DYYDG_DYYDGXX)/2 -
      CHR1_XYY*CHR2_XXX + CHR1_XXY*CHR2_XXY - CHR1_YYY*CHR2_YXX +
      CHR1_YXY*CHR2_YXY - CHR1_ZYY*CHR2_ZXX +
      CHR1_ZXY*CHR2_ZXY)*UPPERMET_UXX + (DXYDG_DXYDGYZ - DXZDG_DXZDGYY -
      DYYDG_DYYDGXZ + DYZDG_DYZDGXY + 2*(CHR1_XYZ*CHR2_XXY -
      CHR1_XYY*CHR2_XXZ + CHR1_YYZ*CHR2_YXY + CHR1_ZYZ*CHR2_ZXY) -
      2*(CHR1_YYY*CHR2_YXZ + CHR1_ZYY*CHR2_ZXZ)) *UPPERMET_UXZ +
      (DYZDG_DYZDGYZ + (-DYYDG_DYYDGZZ - DZZDG_DZZDGYY)/2 -
      CHR1_XZZ*CHR2_XYY + CHR1_XYZ*CHR2_XYZ - CHR1_YZZ*CHR2_YYY +
      CHR1_YYZ*CHR2_YYZ - CHR1_ZZZ*CHR2_ZYY +
      CHR1_ZYZ*CHR2_ZYZ)*UPPERMET_UZZ ;

      RICCI_RYZ = ((-DXXDG_DXXDGYZ + DXYDG_DXYDGXZ + DXZDG_DXZDGXY -
      DYZDG_DYZDGXX)/2 - CHR1_XYZ*CHR2_XXX + CHR1_XXZ*CHR2_XXY -
      CHR1_YYZ*CHR2_YXX + CHR1_YXZ*CHR2_YXY - CHR1_ZYZ*CHR2_ZXX +
      CHR1_ZXZ*CHR2_ZXY)*UPPERMET_UXX + ((-DXYDG_DXYDGYZ + DXZDG_DXZDGYY +
      DYYDG_DYYDGXZ - DYZDG_DYZDGXY)/2 - CHR1_XYZ*CHR2_XXY +
      CHR1_XYY*CHR2_XXZ - CHR1_YYZ*CHR2_YXY + CHR1_YYY*CHR2_YXZ -
      CHR1_ZYZ*CHR2_ZXY + CHR1_ZYY*CHR2_ZXZ)*UPPERMET_UXY + ((DXYDG_DXYDGZZ
      - DXZDG_DXZDGYZ - DYZDG_DYZDGXZ + DZZDG_DZZDGXY)/2 + CHR1_XZZ*CHR2_XXY
      - CHR1_XYZ*CHR2_XXZ + CHR1_YZZ*CHR2_YXY - CHR1_YYZ*CHR2_YXZ +
      CHR1_ZZZ*CHR2_ZXY - CHR1_ZYZ*CHR2_ZXZ)*UPPERMET_UXZ + (-DYZDG_DYZDGYZ
      + (DYYDG_DYYDGZZ + DZZDG_DZZDGYY)/2 + CHR1_XZZ*CHR2_XYY -
      CHR1_XYZ*CHR2_XYZ + CHR1_YZZ*CHR2_YYY - CHR1_YYZ*CHR2_YYZ +
      CHR1_ZZZ*CHR2_ZYY - CHR1_ZYZ*CHR2_ZYZ)*UPPERMET_UYZ ;

      RICCI_RZZ = (DXZDG_DXZDGXZ + (-DXXDG_DXXDGZZ - DZZDG_DZZDGXX)/2 -
      CHR1_XZZ*CHR2_XXX + CHR1_XXZ*CHR2_XXZ - CHR1_YZZ*CHR2_YXX +
      CHR1_YXZ*CHR2_YXZ - CHR1_ZZZ*CHR2_ZXX +
      CHR1_ZXZ*CHR2_ZXZ)*UPPERMET_UXX + (-DXYDG_DXYDGZZ + DXZDG_DXZDGYZ +
      DYZDG_DYZDGXZ - DZZDG_DZZDGXY - 2*(CHR1_YZZ*CHR2_YXY +
      CHR1_ZZZ*CHR2_ZXY) + 2*(-(CHR1_XZZ*CHR2_XXY) + CHR1_XYZ*CHR2_XXZ +
      CHR1_YYZ*CHR2_YXZ + CHR1_ZYZ*CHR2_ZXZ))*UPPERMET_UXY + (DYZDG_DYZDGYZ
      + (-DYYDG_DYYDGZZ - DZZDG_DZZDGYY)/2 - CHR1_XZZ*CHR2_XYY +
      CHR1_XYZ*CHR2_XYZ - CHR1_YZZ*CHR2_YYY + CHR1_YYZ*CHR2_YYZ -
      CHR1_ZZZ*CHR2_ZYY + CHR1_ZYZ*CHR2_ZYZ)*UPPERMET_UYY ;

#endif

#endif
