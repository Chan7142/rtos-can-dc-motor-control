/*
 * File: Subsystem.c
 *
 * Code generated for Simulink model 'Subsystem'.
 *
 * Model version                  : 1.17
 * Simulink Coder version         : 8.10 (R2016a) 10-Feb-2016
 * C/C++ source code generated on : Fri Jul 03 18:12:29 2026
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: ARM Compatible->ARM Cortex
 * Code generation objectives:
 *    1. Execution efficiency
 *    2. RAM efficiency
 * Validation result: Not run
 */

#include "Subsystem.h"

/* Block signals and states (auto storage) */
DW rtDW;

/* External inputs (root inport signals with auto storage) */
ExtU rtU;

/* External outputs (root outports fed by signals with auto storage) */
ExtY rtY;

/* Real-time model */
RT_MODEL rtM_;
RT_MODEL *const rtM = &rtM_;

/* Model step function */
void Subsystem_step(void)
{
  /* local block i/o variables */
  real_T rtb_Saturation;
  real_T rtb_DiscreteStateSpace[3];
  real_T rtb_Sum;
  real_T rtb_ProportionalGain;
  real_T rtb_TSamp;
  real_T Integrator;

  /* DiscreteStateSpace: '<S1>/Discrete State-Space' */
  {
    rtb_DiscreteStateSpace[0] = (1.0)*rtDW.Observer[0];
    rtb_DiscreteStateSpace[1] = (1.0)*rtDW.Observer[1];
    rtb_DiscreteStateSpace[2] = (1.0)*rtDW.Observer[2];
  }

  /* Sum: '<S1>/Sum' incorporates:
   *  Gain: '<S1>/Gain'
   *  Inport: '<Root>/ref'
   *  Inport: '<Root>/theta'
   *  Sum: '<S1>/Sum1'
   */
  rtb_Sum = (rtU.ref - rtU.theta) * 10.0 - rtb_DiscreteStateSpace[1];

  /* Gain: '<S2>/Proportional Gain' */
  rtb_ProportionalGain = 0.024361228293130539 * rtb_Sum;

  /* DiscreteIntegrator: '<S2>/Integrator' incorporates:
   *  Gain: '<S2>/Integral Gain'
   */
  Integrator = 2.0301023577608781 * rtb_Sum * 0.001 + rtDW.Integrator_DSTATE;

  /* Gain: '<S2>/Derivative Gain' */
  rtb_Sum *= 0.0;

  /* SampleTimeMath: '<S3>/TSamp'
   *
   * About '<S3>/TSamp':
   *  y = u * K where K = 1 / ( w * Ts )
   */
  rtb_TSamp = rtb_Sum * 1000.0;

  /* Sum: '<S2>/Sum' incorporates:
   *  Delay: '<S3>/UD'
   *  Sum: '<S3>/Diff'
   */
  rtb_Sum = (rtb_ProportionalGain + Integrator) + (rtb_TSamp - rtDW.UD_DSTATE);

  /* Saturate: '<S1>/Saturation' */
  if (rtb_Sum > 12.0) {
    rtb_Saturation = 12.0;
  } else if (rtb_Sum < -12.0) {
    rtb_Saturation = -12.0;
  } else {
    rtb_Saturation = rtb_Sum;
  }

  /* End of Saturate: '<S1>/Saturation' */

  /* Outport: '<Root>/input' */
  rtY.input = rtb_Sum;

  /* Outport: '<Root>/theta_hat' */
  rtY.theta_hat = rtb_DiscreteStateSpace[0];

  /* Outport: '<Root>/speed_rad_hat' */
  rtY.speed_rad_hat = rtb_DiscreteStateSpace[1];

  /* Outport: '<Root>/d_hat' */
  rtY.d_hat = rtb_DiscreteStateSpace[2];

  /* Update for DiscreteStateSpace: '<S1>/Discrete State-Space' */
  {
    real_T xnew[3];
    xnew[0] = (0.93458290957195156)*rtDW.Observer[0] + (0.00092744868888819615)*
      rtDW.Observer[1]
      + (4.7561471225035705E-7)*rtDW.Observer[2];
    xnew[0] += (0.00097617145270231)*rtb_Saturation + (0.065417090428048483)*
      rtU.theta;
    xnew[1] = (-1.8628242896472313)*rtDW.Observer[0] + (0.919125431423815)*
      rtDW.Observer[1]
      + (0.0009591563363715533)*rtDW.Observer[2];
    xnew[1] += (1.968612429616325)*rtb_Saturation + (1.8628242896472318)*
      rtU.theta;
    xnew[2] = (-120.88540603029905)*rtDW.Observer[0] + (-0.059451839031294633)*
      rtDW.Observer[1]
      + (0.99997993250637562)*rtDW.Observer[2];
    xnew[2] += (-0.041187360060282022)*rtb_Saturation + (120.88540603029907)*
      rtU.theta;
    (void) memcpy(&rtDW.Observer[0], xnew,
                  sizeof(real_T)*3);
  }

  /* Update for DiscreteIntegrator: '<S2>/Integrator' */
  rtDW.Integrator_DSTATE = Integrator;

  /* Update for Delay: '<S3>/UD' */
  rtDW.UD_DSTATE = rtb_TSamp;
}

/* Model initialize function */
void Subsystem_initialize(void)
{
  /* (no initialization code required) */
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
