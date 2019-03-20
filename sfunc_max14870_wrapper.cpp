
/*
 * Include Files
 *
 */
#if defined(MATLAB_MEX_FILE)
#include "tmwtypes.h"
#include "simstruc_types.h"
#else
#include "rtwtypes.h"
#endif



/* %%%-SFUNWIZ_wrapper_includes_Changes_BEGIN --- EDIT HERE TO _END */
# ifndef MATLAB_MEX_FILE 
#include <Arduino.h> 
#include "DualMAX14870MotorShield.h"
#include "DualMAX14870MotorShield.cpp"

int num=0;
DualMAX14870MotorShield md = DualMAX14870MotorShield();


# endif
/* %%%-SFUNWIZ_wrapper_includes_Changes_END --- EDIT HERE TO _BEGIN */
#define u_width 1

/*
 * Create external references here.  
 *
 */
/* %%%-SFUNWIZ_wrapper_externs_Changes_BEGIN --- EDIT HERE TO _END */
/* extern double func(double a); */
/* %%%-SFUNWIZ_wrapper_externs_Changes_END --- EDIT HERE TO _BEGIN */

/*
 * Output function
 *
 */
extern "C" void sfunc_max14870_Outputs_wrapper(const real_T *mot,
			const real_T *spd,
			const real_T *xD)
{
/* %%%-SFUNWIZ_wrapper_Outputs_Changes_BEGIN --- EDIT HERE TO _END */
/* This sample sets the output equal to the input
      y0[0] = u0[0]; 
 For complex signals use: y0[0].re = u0[0].re; 
      y0[0].im = u0[0].im;
      y1[0].re = u1[0].re;
      y1[0].im = u1[0].im;
 */
if (xD[0]==1) { 
/* don't do anything for mex file generation */ 
# ifndef MATLAB_MEX_FILE 
/* get encoder position and set is as output */ 
    md.enableDrivers();
    if (num==1){
         md.setM1Speed(spd[0]);
          
    }
    else{
          md.setM2Speed(spd[0]);
    }
# endif 
}
/* %%%-SFUNWIZ_wrapper_Outputs_Changes_END --- EDIT HERE TO _BEGIN */
}

/*
 * Updates function
 *
 */
extern "C"  void sfunc_max14870_Update_wrapper(const real_T *mot,
			const real_T *spd,
			real_T *xD)
{
/* %%%-SFUNWIZ_wrapper_Update_Changes_BEGIN --- EDIT HERE TO _END */
/*
 * Code example
 *   xD[0] = u0[0];
 */
if (xD[0]!=1) { 
    # ifndef MATLAB_MEX_FILE 
    num=mot[0];
    # endif 
    /* initialization done */ 
    xD[0]=1; 
}
/* %%%-SFUNWIZ_wrapper_Update_Changes_END --- EDIT HERE TO _BEGIN */
}

