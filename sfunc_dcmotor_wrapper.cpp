
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
#include "DualVNH5019MotorShield.h"
#include "DualVNH5019MotorShield.cpp"

int num=0;
DualVNH5019MotorShield md = DualVNH5019MotorShield();


# endif
/* %%%-SFUNWIZ_wrapper_includes_Changes_END --- EDIT HERE TO _BEGIN */
#define u_width 1
#define y_width 1

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
extern "C" void sfunc_dcmotor_Outputs_wrapper(const real_T *mot,
			const real_T *spd,
			real_T *current,
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
    if (num==1){
         md.setM1Speed(spd[0]);
         current[0]=md.getM1CurrentMilliamps();
         
    }
    else{
          md.setM2Speed(spd[0]);
         current[0]=md.getM2CurrentMilliamps();               
    }
# endif 
}
/* %%%-SFUNWIZ_wrapper_Outputs_Changes_END --- EDIT HERE TO _BEGIN */
}

/*
 * Updates function
 *
 */
extern "C"  void sfunc_dcmotor_Update_wrapper(const real_T *mot,
			const real_T *spd,
			real_T *current,
			real_T *xD)
{
/* %%%-SFUNWIZ_wrapper_Update_Changes_BEGIN --- EDIT HERE TO _END */
/*
 * Code example
 *   xD[0] = u0[0];
 */
if (xD[0]!=1) { 
    # ifndef MATLAB_MEX_FILE 
    md.init();
    num=mot[0];
    # endif 
    /* initialization done */ 
    xD[0]=1; 
}
/* %%%-SFUNWIZ_wrapper_Update_Changes_END --- EDIT HERE TO _BEGIN */
}
/*
 * Terminate function
 *
 */
extern "C"  void sfunc_dcmotor_Terminate_wrapper(real_T *xD)
{
/* %%%-SFUNWIZ_wrapper_Terminate_Changes_BEGIN --- EDIT HERE TO _END */
/*
 * Custom Terminate code goes here.
 */

if (xD[0]==1) { 
/* don't do anything for mex file generation */ 
# ifndef MATLAB_MEX_FILE 
/* get encoder position and set is as output */ 
    md.setM1Speed(0);
    md.setM2Speed(0);
   
# endif 
}
/* %%%-SFUNWIZ_wrapper_Terminate_Changes_END --- EDIT HERE TO _BEGIN */
}

