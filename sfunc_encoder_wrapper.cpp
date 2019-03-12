
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
#ifndef MATLAB_MEX_FILE 
#include <Arduino.h>

#define digitalPinToInterrupt(p)  ( (p) == 2 ? 0 : ((p) == 3 ? 1 : ((p) >= 18 && (p) <= 21 ? 23 - (p) : -1)))

int encoderA=0;
int encoderB=0;
int pulses;                              //Output pulses.
int pulsesChanged = 0;
unsigned long passedtime;
int counter;


void A_CHANGE() {                                     //Interrupt function to read the x2 pulses of the encoder.
  if ( digitalRead(encoderB) == 0 ) {
    if ( digitalRead(encoderA) == 0 ) {
      // A fell, B is low
      pulses--; // Moving forward
      counter--;
    } else {
      // A rose, B is high
      pulses++; // Moving reverse
      counter++;
    }
  } else {
    if (digitalRead(encoderA) == 0 ) {


      pulses++; // Moving reverse
      counter++;
    } else {
      // A rose, B is low
      pulses--; // Moving forward
      counter--;
    }
  }
  pulsesChanged = 1;
}
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
extern "C" void sfunc_encoder_Outputs_wrapper(const uint8_T *pinA,
			const uint8_T *pinB,
			const uint32_T *cntperrot,
			const uint16_T *sampletime,
			int16_T *pos,
			real_T *rpm,
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
    delay(sampletime[0]);
    detachInterrupt(digitalPinToInterrupt(encoderA));
  if (pulsesChanged != 0) {
    pulsesChanged = 0;
    pos[0]=pulses;
  }
    
   rpm[0] = 60.0*1000.0/(millis() - passedtime)*counter/cntperrot[0];
   passedtime = millis();

   counter = 0; 
   attachInterrupt(digitalPinToInterrupt(encoderA), A_CHANGE, CHANGE);
# endif 
}
/* %%%-SFUNWIZ_wrapper_Outputs_Changes_END --- EDIT HERE TO _BEGIN */
}

/*
 * Updates function
 *
 */
extern "C" void sfunc_encoder_Update_wrapper(const uint8_T *pinA,
			const uint8_T *pinB,
			const uint32_T *cntperrot,
			const uint16_T *sampletime,
			int16_T *pos,
			real_T *rpm,
			real_T *xD)
{
/* %%%-SFUNWIZ_wrapper_Update_Changes_BEGIN --- EDIT HERE TO _END */
/*
 * Code example
 *   xD[0] = u0[0];
 */
if (xD[0]!=1) { 
    # ifndef MATLAB_MEX_FILE 
    encoderA=pinA[0];
    encoderB=pinB[0];
    counter = 0;
    attachInterrupt(digitalPinToInterrupt(encoderA), A_CHANGE, CHANGE);
    # endif 
    /* initialization done */ 
    xD[0]=1; 
}
/* %%%-SFUNWIZ_wrapper_Update_Changes_END --- EDIT HERE TO _BEGIN */
}

