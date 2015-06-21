#define DECLARE_CCTK_PARAMETERS \
CCTK_REAL  dx&&\
CCTK_REAL  dxyz&&\
CCTK_REAL  dy&&\
CCTK_REAL  dz&&\
CCTK_REAL  xmax&&\
CCTK_REAL  xmin&&\
CCTK_REAL  xyzmax&&\
CCTK_REAL  xyzmin&&\
CCTK_REAL  ymax&&\
CCTK_REAL  ymin&&\
CCTK_REAL  zmax&&\
CCTK_REAL  zmin&&\
CCTK_STRING  bitant_plane&&\
CCTK_STRING  domain&&\
CCTK_STRING  quadrant_direction&&\
CCTK_STRING  type&&\
CCTK_INT symmetry_xmax&&\
CCTK_INT symmetry_xmin&&\
CCTK_INT symmetry_ymax&&\
CCTK_INT symmetry_ymin&&\
CCTK_INT symmetry_zmax&&\
CCTK_INT symmetry_zmin&&\
COMMON /gridrest/dx,dxyz,dy,dz,xmax,xmin,xyzmax,xyzmin,ymax,ymin,zmax,zmin,bitant_plane,domain,quadrant_direction,type,symmetry_xmax,symmetry_xmin,symmetry_ymax,symmetry_ymin,symmetry_zmax,symmetry_zmin&&\
CCTK_INT avoid_origin&&\
CCTK_INT avoid_originx&&\
CCTK_INT avoid_originy&&\
CCTK_INT avoid_originz&&\
CCTK_INT no_origin&&\
CCTK_INT no_originx&&\
CCTK_INT no_originy&&\
CCTK_INT no_originz&&\
COMMON /CartGrid3Dpriv/avoid_origin,avoid_originx,avoid_originy,avoid_originz,no_origin,no_originx,no_originy,no_originz&&\
CCTK_INT CCTKH0&&\
CCTK_INT CCTKH1&&\
CCTK_INT CCTKH2&&\
CCTK_INT CCTKH3&&\
CCTK_INT CCTKH4&&\
CCTK_INT CCTKH5&&\
CCTK_INT CCTKH6&&\
CCTK_INT CCTKH7&&\
CCTK_INT periodic&&\
CCTK_INT periodic_x&&\
CCTK_INT periodic_y&&\
CCTK_INT periodic_z&&\
COMMON /DRIVERrest/CCTKH0,CCTKH1,CCTKH2,CCTKH3,CCTKH4,CCTKH5,CCTKH6,CCTKH7,periodic,periodic_x,periodic_y,periodic_z&&\


