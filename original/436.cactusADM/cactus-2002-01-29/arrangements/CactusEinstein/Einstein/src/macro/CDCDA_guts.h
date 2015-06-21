/*@@
  @header   CDCDA_guts.h
  @date     Jul 98
  @author   Gabrielle Allen
  @desc
  Macro to calculate all second covariant spatial derivative of lapse

  That is alpha_{;ij}

  @enddesc
@@*/

#ifndef CDCDA_GUTS
#define CDCDA_GUTS

#include "CactusEinstein/Einstein/src/macro/DA_guts.h"
#include "CactusEinstein/Einstein/src/macro/DDA_guts.h"
#include "CactusEinstein/Einstein/src/macro/CHR2_guts.h"

#ifdef FCODE 

      CDCDA_CDXXDA = (DDA_DXXDA-CHR2_XXX*DA_DXDA-CHR2_YXX*DA_DYDA-CHR2_ZXX*DA_DZDA)
      CDCDA_CDXYDA = (DDA_DXYDA-CHR2_XXY*DA_DXDA-CHR2_YXY*DA_DYDA-CHR2_ZXY*DA_DZDA)
      CDCDA_CDXZDA = (DDA_DXZDA-CHR2_XXZ*DA_DXDA-CHR2_YXZ*DA_DYDA-CHR2_ZXZ*DA_DZDA)
      CDCDA_CDYYDA = (DDA_DYYDA-CHR2_XYY*DA_DXDA-CHR2_YYY*DA_DYDA-CHR2_ZYY*DA_DZDA)
      CDCDA_CDYZDA = (DDA_DYZDA-CHR2_XYZ*DA_DXDA-CHR2_YYZ*DA_DYDA-CHR2_ZYZ*DA_DZDA)
      CDCDA_CDZZDA = (DDA_DZZDA-CHR2_XZZ*DA_DXDA-CHR2_YZZ*DA_DYDA-CHR2_ZZZ*DA_DZDA)

#endif

#ifdef CCODE

      CDCDA_CDXXDA = (DDA_DXXDA-CHR2_XXX*DA_DXDA-CHR2_YXX*DA_DYDA-CHR2_ZXX*DA_DZDA);
      CDCDA_CDXYDA = (DDA_DXYDA-CHR2_XXY*DA_DXDA-CHR2_YXY*DA_DYDA-CHR2_ZXY*DA_DZDA);
      CDCDA_CDXZDA = (DDA_DXZDA-CHR2_XXZ*DA_DXDA-CHR2_YXZ*DA_DYDA-CHR2_ZXZ*DA_DZDA);
      CDCDA_CDYYDA = (DDA_DYYDA-CHR2_XYY*DA_DXDA-CHR2_YYY*DA_DYDA-CHR2_ZYY*DA_DZDA);
      CDCDA_CDYZDA = (DDA_DYZDA-CHR2_XYZ*DA_DXDA-CHR2_YYZ*DA_DYDA-CHR2_ZYZ*DA_DZDA);
      CDCDA_CDZZDA = (DDA_DZZDA-CHR2_XZZ*DA_DXDA-CHR2_YZZ*DA_DYDA-CHR2_ZZZ*DA_DZDA);

#endif

#endif

