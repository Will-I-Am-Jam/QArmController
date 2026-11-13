/*
 * TrajRunner.c
 *
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * Code generation for model "TrajRunner".
 *
 * Model version              : 13.55
 * Simulink Coder version : 26.1 (R2026a) 20-Nov-2025
 * C source code generated on : Fri Nov 13 13:36:25 2026
 *
 * Target selection: quarc_win64.tlc
 * Note: GRT includes extra infrastructure and instrumentation for prototyping
 * Embedded hardware selection: Intel->x86-64 (Windows64)
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#include "TrajRunner.h"
#include "rtwtypes.h"
#include <math.h>
#include "TrajRunner_private.h"
#include "zero_crossing_types.h"
#include <string.h>
#include "TrajRunner_dt.h"

/* Named constants for MATLAB Function: '<Root>/MATLAB Function' */
#define TrajRunner_CALL_EVENT          (-1)

/* Block signals (default storage) */
B_TrajRunner_T TrajRunner_B;

/* Continuous states */
X_TrajRunner_T TrajRunner_X;

/* Disabled State Vector */
XDis_TrajRunner_T TrajRunner_XDis;

/* Block states (default storage) */
DW_TrajRunner_T TrajRunner_DW;

/* Previous zero-crossings (trigger) states */
PrevZCX_TrajRunner_T TrajRunner_PrevZCX;

/* Real-time model */
static RT_MODEL_TrajRunner_T TrajRunner_M_;
RT_MODEL_TrajRunner_T *const TrajRunner_M = &TrajRunner_M_;

/*
 * This function updates continuous states using the ODE4 fixed-step
 * solver algorithm
 */
static void rt_ertODEUpdateContinuousStates(RTWSolverInfo *si )
{
  time_T t = rtsiGetT(si);
  time_T tnew = rtsiGetSolverStopTime(si);
  time_T h = rtsiGetStepSize(si);
  real_T *x = rtsiGetContStates(si);
  ODE4_IntgData *id = (ODE4_IntgData *)rtsiGetSolverData(si);
  real_T *y = id->y;
  real_T *f0 = id->f[0];
  real_T *f1 = id->f[1];
  real_T *f2 = id->f[2];
  real_T *f3 = id->f[3];
  real_T temp;
  int_T i;
  int_T nXc = 3;
  rtsiSetSimTimeStep(si,MINOR_TIME_STEP);

  /* Save the state values at time t in y, we'll use x as ynew. */
  (void) memcpy(y, x,
                (uint_T)nXc*sizeof(real_T));

  /* Assumes that rtsiSetT and ModelOutputs are up-to-date */
  /* f0 = f(t,y) */
  rtsiSetdX(si, f0);
  TrajRunner_derivatives();

  /* f1 = f(t + (h/2), y + (h/2)*f0) */
  temp = 0.5 * h;
  for (i = 0; i < nXc; i++) {
    x[i] = y[i] + (temp*f0[i]);
  }

  rtsiSetT(si, t + temp);
  rtsiSetdX(si, f1);
  TrajRunner_output();
  TrajRunner_derivatives();

  /* f2 = f(t + (h/2), y + (h/2)*f1) */
  for (i = 0; i < nXc; i++) {
    x[i] = y[i] + (temp*f1[i]);
  }

  rtsiSetdX(si, f2);
  TrajRunner_output();
  TrajRunner_derivatives();

  /* f3 = f(t + h, y + h*f2) */
  for (i = 0; i < nXc; i++) {
    x[i] = y[i] + (h*f2[i]);
  }

  rtsiSetT(si, tnew);
  rtsiSetdX(si, f3);
  TrajRunner_output();
  TrajRunner_derivatives();

  /* tnew = t + h
     ynew = y + (h/6)*(f0 + 2*f1 + 2*f2 + 2*f3) */
  temp = h / 6.0;
  for (i = 0; i < nXc; i++) {
    x[i] = y[i] + temp*(f0[i] + 2.0*f1[i] + 2.0*f2[i] + f3[i]);
  }

  rtsiSetSimTimeStep(si,MAJOR_TIME_STEP);
}

/* Model output function */
void TrajRunner_output(void)
{
  /* local block i/o variables */
  real_T rtb_gripperspeed;
  real_T rtb_HILReadTimebase1_o20;
  real_T rtb_gripperpwm;
  real_T rtb_Elbow;
  real_T phidot_err[4];
  real_T rtb_Bias;
  real_T tmp_0;
  int32_T gripperMode;
  boolean_T exitg1;
  boolean_T tmp;
  boolean_T y;
  ZCEventType zcEvent;
  if (rtmIsMajorTimeStep(TrajRunner_M)) {
    /* set solver stop time */
    if (!(TrajRunner_M->Timing.clockTick0+1)) {
      rtsiSetSolverStopTime(&TrajRunner_M->solverInfo,
                            ((TrajRunner_M->Timing.clockTickH0 + 1) *
        TrajRunner_M->Timing.stepSize0 * 4294967296.0));
    } else {
      rtsiSetSolverStopTime(&TrajRunner_M->solverInfo,
                            ((TrajRunner_M->Timing.clockTick0 + 1) *
        TrajRunner_M->Timing.stepSize0 + TrajRunner_M->Timing.clockTickH0 *
        TrajRunner_M->Timing.stepSize0 * 4294967296.0));
    }
  }                                    /* end MajorTimeStep */

  /* Update absolute time of base rate at minor time step */
  if (rtmIsMinorTimeStep(TrajRunner_M)) {
    TrajRunner_M->Timing.t[0] = rtsiGetT(&TrajRunner_M->solverInfo);
  }

  tmp = rtmIsMajorTimeStep(TrajRunner_M);
  if (tmp) {
    /* S-Function (hil_read_timebase_block): '<S2>/HIL Read Timebase1' */

    /* S-Function Block: TrajRunner/Hardware Plant P(s)/HIL Read Timebase1 (hil_read_timebase_block) */
    {
      t_error result;
      result = hil_task_read(TrajRunner_DW.HILReadTimebase1_Task, 1,
        &TrajRunner_DW.HILReadTimebase1_AnalogBuffer[0],
        NULL,
        NULL,
        &TrajRunner_DW.HILReadTimebase1_OtherBuffer[0]
        );
      if (result < 0) {
        msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
          (_rt_error_message));
        rtmSetErrorStatus(TrajRunner_M, _rt_error_message);
      } else {
        TrajRunner_B.HILReadTimebase1_o1 =
          TrajRunner_DW.HILReadTimebase1_AnalogBuffer[0];
        TrajRunner_B.HILReadTimebase1_o2 =
          TrajRunner_DW.HILReadTimebase1_AnalogBuffer[1];
        TrajRunner_B.HILReadTimebase1_o3 =
          TrajRunner_DW.HILReadTimebase1_AnalogBuffer[2];
        TrajRunner_B.HILReadTimebase1_o4 =
          TrajRunner_DW.HILReadTimebase1_AnalogBuffer[3];
        TrajRunner_B.grippercurrent =
          TrajRunner_DW.HILReadTimebase1_AnalogBuffer[4];
        TrajRunner_B.HILReadTimebase1_o6 =
          TrajRunner_DW.HILReadTimebase1_OtherBuffer[0];
        TrajRunner_B.HILReadTimebase1_o7 =
          TrajRunner_DW.HILReadTimebase1_OtherBuffer[1];
        TrajRunner_B.HILReadTimebase1_o8 =
          TrajRunner_DW.HILReadTimebase1_OtherBuffer[2];
        TrajRunner_B.HILReadTimebase1_o9 =
          TrajRunner_DW.HILReadTimebase1_OtherBuffer[3];
        TrajRunner_B.HILReadTimebase1_o10 =
          TrajRunner_DW.HILReadTimebase1_OtherBuffer[4];
        TrajRunner_B.HILReadTimebase1_o11 =
          TrajRunner_DW.HILReadTimebase1_OtherBuffer[5];
        TrajRunner_B.HILReadTimebase1_o12 =
          TrajRunner_DW.HILReadTimebase1_OtherBuffer[6];
        TrajRunner_B.HILReadTimebase1_o13 =
          TrajRunner_DW.HILReadTimebase1_OtherBuffer[7];
        TrajRunner_B.HILReadTimebase1_o14 =
          TrajRunner_DW.HILReadTimebase1_OtherBuffer[8];
        rtb_gripperspeed = TrajRunner_DW.HILReadTimebase1_OtherBuffer[9];
        TrajRunner_B.HILReadTimebase1_o16 =
          TrajRunner_DW.HILReadTimebase1_OtherBuffer[10];
        TrajRunner_B.HILReadTimebase1_o17 =
          TrajRunner_DW.HILReadTimebase1_OtherBuffer[11];
        TrajRunner_B.HILReadTimebase1_o18 =
          TrajRunner_DW.HILReadTimebase1_OtherBuffer[12];
        TrajRunner_B.HILReadTimebase1_o19 =
          TrajRunner_DW.HILReadTimebase1_OtherBuffer[13];
        rtb_HILReadTimebase1_o20 = TrajRunner_DW.HILReadTimebase1_OtherBuffer[14];
        TrajRunner_B.HILReadTimebase1_o21 =
          TrajRunner_DW.HILReadTimebase1_OtherBuffer[15];
        TrajRunner_B.HILReadTimebase1_o22 =
          TrajRunner_DW.HILReadTimebase1_OtherBuffer[16];
        TrajRunner_B.HILReadTimebase1_o23 =
          TrajRunner_DW.HILReadTimebase1_OtherBuffer[17];
        TrajRunner_B.HILReadTimebase1_o24 =
          TrajRunner_DW.HILReadTimebase1_OtherBuffer[18];
        rtb_gripperpwm = TrajRunner_DW.HILReadTimebase1_OtherBuffer[19];
      }
    }

    /* S-Function (sample_time_block): '<Root>/Sample Time' */

    /* S-Function Block: TrajRunner/Sample Time (sample_time_block) */
    {
      t_error result;
      t_timeout current_time;
      t_timeout time_difference;
      result = timeout_get_high_resolution_time(&current_time);
      if (result >= 0) {
        result = timeout_subtract(&time_difference, &current_time,
          &TrajRunner_DW.SampleTime_PreviousTime);
        TrajRunner_B.SampleTime = time_difference.seconds +
          time_difference.nanoseconds * 1e-9;
        memcpy(&TrajRunner_DW.SampleTime_PreviousTime, &current_time, sizeof
               (t_timeout));
      }

      if (result < 0) {
        msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
          (_rt_error_message));
        rtmSetErrorStatus(TrajRunner_M, _rt_error_message);
        return;
      }
    }

    /* S-Function (smooth_signal_generator_block): '<Root>/Base' */
    /* S-Function Block: TrajRunner/Base (smooth_signal_generator_block) */
    {
      real_T w = TWO_PI * TrajRunner_P.Base_Frequency;
      boolean_T params_changed = (TrajRunner_P.Base_Amplitude !=
        TrajRunner_DW.Base_RWORK.Amp || w != TrajRunner_DW.Base_RWORK.W);
      real_T T = TWO_PI / TrajRunner_DW.Base_RWORK.W;
      if (TrajRunner_DW.Base_RWORK.T < 0.5 * T) {
        rtb_Bias = TrajRunner_DW.Base_RWORK.Amp;
      } else {
        rtb_Bias = -TrajRunner_DW.Base_RWORK.Amp;
      }

      /*
         If the amplitude or frequency parameter changes, then adjust the
         square wave parameters such that the square wave output is continuous.
       */
      if (params_changed) {
        /*
           Change the amplitude or frequency when the sign of the output
           changes. This technique ensures that we don't get intermediate
           jumps in amplitude and we don't get higher frequencies than
           expected due to a pulse being prematurely truncated.
         */
        if (TrajRunner_P.Base_Amplitude == 0 || rtb_Bias == 0 ||
            TrajRunner_DW.Base_RWORK.Y == 0 || (rtb_Bias < 0) !=
            (TrajRunner_DW.Base_RWORK.Y < 0)) {
          TrajRunner_DW.Base_RWORK.Amp = TrajRunner_P.Base_Amplitude;
          TrajRunner_DW.Base_RWORK.W = w;
          T = TWO_PI / w;
          if (rtb_Bias >= 0) {
            TrajRunner_DW.Base_RWORK.T = 0;
            rtb_Bias = TrajRunner_P.Base_Amplitude;
          } else {
            TrajRunner_DW.Base_RWORK.T = T / 2;
            rtb_Bias = -TrajRunner_P.Base_Amplitude;
          }
        }
      }

      TrajRunner_DW.Base_RWORK.T += 0.002;
      if (TrajRunner_DW.Base_RWORK.T >= T) {
        TrajRunner_DW.Base_RWORK.T = 0;
      }

      TrajRunner_DW.Base_RWORK.Y = rtb_Bias;
    }

    /* ManualSwitch: '<Root>/Manual Switch' */
    if (TrajRunner_P.ManualSwitch_CurrentSetting == 1) {
      /* ManualSwitch: '<Root>/Manual Switch' */
      TrajRunner_B.ManualSwitch = rtb_Bias;
    } else {
      /* ManualSwitch: '<Root>/Manual Switch' incorporates:
       *  Constant: '<Root>/Constant2'
       */
      TrajRunner_B.ManualSwitch = TrajRunner_P.Constant2_Value;
    }

    /* End of ManualSwitch: '<Root>/Manual Switch' */

    /* S-Function (smooth_signal_generator_block): '<Root>/Shoulder' */
    /* S-Function Block: TrajRunner/Shoulder (smooth_signal_generator_block) */
    {
      real_T w = TWO_PI * TrajRunner_P.Shoulder_Frequency;
      boolean_T params_changed = (TrajRunner_P.Shoulder_Amplitude !=
        TrajRunner_DW.Shoulder_RWORK.Amp || w != TrajRunner_DW.Shoulder_RWORK.W);
      real_T T = TWO_PI / TrajRunner_DW.Shoulder_RWORK.W;
      if (TrajRunner_DW.Shoulder_RWORK.T < 0.5 * T) {
        rtb_Bias = TrajRunner_DW.Shoulder_RWORK.Amp;
      } else {
        rtb_Bias = -TrajRunner_DW.Shoulder_RWORK.Amp;
      }

      /*
         If the amplitude or frequency parameter changes, then adjust the
         square wave parameters such that the square wave output is continuous.
       */
      if (params_changed) {
        /*
           Change the amplitude or frequency when the sign of the output
           changes. This technique ensures that we don't get intermediate
           jumps in amplitude and we don't get higher frequencies than
           expected due to a pulse being prematurely truncated.
         */
        if (TrajRunner_P.Shoulder_Amplitude == 0 || rtb_Bias == 0 ||
            TrajRunner_DW.Shoulder_RWORK.Y == 0 || (rtb_Bias < 0) !=
            (TrajRunner_DW.Shoulder_RWORK.Y < 0)) {
          TrajRunner_DW.Shoulder_RWORK.Amp = TrajRunner_P.Shoulder_Amplitude;
          TrajRunner_DW.Shoulder_RWORK.W = w;
          T = TWO_PI / w;
          if (rtb_Bias >= 0) {
            TrajRunner_DW.Shoulder_RWORK.T = 0;
            rtb_Bias = TrajRunner_P.Shoulder_Amplitude;
          } else {
            TrajRunner_DW.Shoulder_RWORK.T = T / 2;
            rtb_Bias = -TrajRunner_P.Shoulder_Amplitude;
          }
        }
      }

      TrajRunner_DW.Shoulder_RWORK.T += 0.002;
      if (TrajRunner_DW.Shoulder_RWORK.T >= T) {
        TrajRunner_DW.Shoulder_RWORK.T = 0;
      }

      TrajRunner_DW.Shoulder_RWORK.Y = rtb_Bias;
    }

    /* ManualSwitch: '<Root>/Manual Switch1' */
    if (TrajRunner_P.ManualSwitch1_CurrentSetting == 1) {
      /* ManualSwitch: '<Root>/Manual Switch1' */
      TrajRunner_B.ManualSwitch1 = rtb_Bias;
    } else {
      /* ManualSwitch: '<Root>/Manual Switch1' incorporates:
       *  Constant: '<Root>/Constant4'
       */
      TrajRunner_B.ManualSwitch1 = TrajRunner_P.Constant4_Value;
    }

    /* End of ManualSwitch: '<Root>/Manual Switch1' */

    /* S-Function (smooth_signal_generator_block): '<Root>/Wrist' */
    /* S-Function Block: TrajRunner/Wrist (smooth_signal_generator_block) */
    {
      real_T w = TWO_PI * TrajRunner_P.Wrist_Frequency;
      boolean_T params_changed = (TrajRunner_P.Wrist_Amplitude !=
        TrajRunner_DW.Wrist_RWORK.Amp || w != TrajRunner_DW.Wrist_RWORK.W);
      real_T T = TWO_PI / TrajRunner_DW.Wrist_RWORK.W;
      if (TrajRunner_DW.Wrist_RWORK.T < 0.5 * T) {
        rtb_Bias = TrajRunner_DW.Wrist_RWORK.Amp;
      } else {
        rtb_Bias = -TrajRunner_DW.Wrist_RWORK.Amp;
      }

      /*
         If the amplitude or frequency parameter changes, then adjust the
         square wave parameters such that the square wave output is continuous.
       */
      if (params_changed) {
        /*
           Change the amplitude or frequency when the sign of the output
           changes. This technique ensures that we don't get intermediate
           jumps in amplitude and we don't get higher frequencies than
           expected due to a pulse being prematurely truncated.
         */
        if (TrajRunner_P.Wrist_Amplitude == 0 || rtb_Bias == 0 ||
            TrajRunner_DW.Wrist_RWORK.Y == 0 || (rtb_Bias < 0) !=
            (TrajRunner_DW.Wrist_RWORK.Y < 0)) {
          TrajRunner_DW.Wrist_RWORK.Amp = TrajRunner_P.Wrist_Amplitude;
          TrajRunner_DW.Wrist_RWORK.W = w;
          T = TWO_PI / w;
          if (rtb_Bias >= 0) {
            TrajRunner_DW.Wrist_RWORK.T = 0;
            rtb_Bias = TrajRunner_P.Wrist_Amplitude;
          } else {
            TrajRunner_DW.Wrist_RWORK.T = T / 2;
            rtb_Bias = -TrajRunner_P.Wrist_Amplitude;
          }
        }
      }

      TrajRunner_DW.Wrist_RWORK.T += 0.002;
      if (TrajRunner_DW.Wrist_RWORK.T >= T) {
        TrajRunner_DW.Wrist_RWORK.T = 0;
      }

      TrajRunner_DW.Wrist_RWORK.Y = rtb_Bias;
    }

    /* ManualSwitch: '<Root>/Manual Switch3' */
    if (TrajRunner_P.ManualSwitch3_CurrentSetting == 1) {
      /* ManualSwitch: '<Root>/Manual Switch3' */
      TrajRunner_B.ManualSwitch3 = rtb_Bias;
    } else {
      /* ManualSwitch: '<Root>/Manual Switch3' incorporates:
       *  Constant: '<Root>/Constant8'
       */
      TrajRunner_B.ManualSwitch3 = TrajRunner_P.Constant8_Value;
    }

    /* End of ManualSwitch: '<Root>/Manual Switch3' */
  }

  /* ManualSwitch: '<Root>/MAIN' incorporates:
   *  ManualSwitch: '<Root>/Manual Switch2'
   */
  if (TrajRunner_P.MAIN_CurrentSetting == 1) {
    /* ManualSwitch: '<Root>/MAIN' incorporates:
     *  Constant: '<Root>/Default Cmd'
     */
    TrajRunner_B.MAIN[0] = TrajRunner_P.DefaultCmd_Value[0];
    TrajRunner_B.MAIN[1] = TrajRunner_P.DefaultCmd_Value[1];
    TrajRunner_B.MAIN[2] = TrajRunner_P.DefaultCmd_Value[2];
    TrajRunner_B.MAIN[3] = TrajRunner_P.DefaultCmd_Value[3];
  } else {
    if (TrajRunner_P.ManualSwitch2_CurrentSetting == 1) {
      /* Step: '<S6>/Step' */
      if (TrajRunner_M->Timing.t[0] < TrajRunner_P.Ramp_start) {
        tmp_0 = TrajRunner_P.Step_Y0;
      } else {
        tmp_0 = TrajRunner_P.Ramp_slope;
      }

      /* ManualSwitch: '<Root>/MAIN' incorporates:
       *  Clock: '<S6>/Clock'
       *  Constant: '<S6>/Constant'
       *  Constant: '<S6>/Constant1'
       *  ManualSwitch: '<Root>/Manual Switch2'
       *  Product: '<S6>/Product'
       *  Step: '<S6>/Step'
       *  Sum: '<S6>/Output'
       *  Sum: '<S6>/Sum'
       */
      TrajRunner_B.MAIN[2] = (TrajRunner_M->Timing.t[0] -
        TrajRunner_P.Ramp_start) * tmp_0 + TrajRunner_P.Ramp_InitialOutput;
    } else {
      /* ManualSwitch: '<Root>/MAIN' incorporates:
       *  Constant: '<Root>/Constant6'
       *  ManualSwitch: '<Root>/Manual Switch2'
       */
      TrajRunner_B.MAIN[2] = TrajRunner_P.Constant6_Value;
    }

    /* ManualSwitch: '<Root>/MAIN' */
    TrajRunner_B.MAIN[0] = TrajRunner_B.ManualSwitch;
    TrajRunner_B.MAIN[1] = TrajRunner_B.ManualSwitch1;
    TrajRunner_B.MAIN[3] = TrajRunner_B.ManualSwitch3;
  }

  /* End of ManualSwitch: '<Root>/MAIN' */
  if (tmp) {
    /* MATLAB Function: '<Root>/MATLAB Function' incorporates:
     *  Constant: '<Root>/Constant'
     *  SignalConversion generated from: '<S3>/ SFunction '
     */
    TrajRunner_DW.sfEvent_p = TrajRunner_CALL_EVENT;

    /* MATLAB Function 'MATLAB Function': '<S3>:1' */
    /* '<S3>:1:2' */
    gripperMode = (TrajRunner_B.HILReadTimebase1_o10 > 0.5);
    TrajRunner_B.newState = gripperMode;
    if (gripperMode == 1) {
      phidot_err[0] = fabs(TrajRunner_P.Constant_Value[0] -
                           TrajRunner_B.HILReadTimebase1_o6);
      phidot_err[1] = fabs(TrajRunner_P.Constant_Value[1] -
                           TrajRunner_B.HILReadTimebase1_o7);
      phidot_err[2] = fabs(TrajRunner_P.Constant_Value[2] -
                           TrajRunner_B.HILReadTimebase1_o8);
      phidot_err[3] = fabs(TrajRunner_P.Constant_Value[3] -
                           TrajRunner_B.HILReadTimebase1_o9);
      y = true;
      gripperMode = 0;
      exitg1 = false;
      while (!exitg1 && (gripperMode < 4)) {
        if (!(phidot_err[gripperMode] <=
              TrajRunner_P.Constant5_Value[gripperMode])) {
          y = false;
          exitg1 = true;
        } else {
          gripperMode++;
        }
      }

      if (y) {
        TrajRunner_B.newState = 0.0;
      }
    }

    /* End of MATLAB Function: '<Root>/MATLAB Function' */

    /* ManualSwitch: '<Root>/Manual Switch5' */
    if (TrajRunner_P.ManualSwitch5_CurrentSetting == 1) {
      /* ManualSwitch: '<Root>/Manual Switch4' */
      if (TrajRunner_P.ManualSwitch4_CurrentSetting == 1) {
        /* ManualSwitch: '<Root>/Manual Switch5' incorporates:
         *  Constant: '<Root>/CLOSE '
         */
        TrajRunner_B.ManualSwitch5 = TrajRunner_P.CLOSE_Value;
      } else {
        /* ManualSwitch: '<Root>/Manual Switch5' incorporates:
         *  Constant: '<Root>/ OPEN'
         */
        TrajRunner_B.ManualSwitch5 = TrajRunner_P.OPEN_Value;
      }
    } else {
      /* ManualSwitch: '<Root>/Manual Switch5' incorporates:
       *  ManualSwitch: '<Root>/Manual Switch4'
       */
      TrajRunner_B.ManualSwitch5 = TrajRunner_B.newState;
    }

    /* End of ManualSwitch: '<Root>/Manual Switch5' */
    /* MATLAB Function: '<Root>/MATLAB Function1' incorporates:
     *  Constant: '<Root>/Constant18'
     *  Constant: '<Root>/Constant7'
     *  ManualSwitch: '<Root>/Manual Switch7'
     *  SignalConversion generated from: '<S4>/ SFunction '
     */
    TrajRunner_DW.sfEvent = TrajRunner_CALL_EVENT;

    /* MATLAB Function 'MATLAB Function1': '<S4>:1' */
    /* '<S4>:1:2' */
    if (TrajRunner_DW.cmd_not_empty) {
      /* ManualSwitch: '<Root>/Manual Switch7' incorporates:
       *  Constant: '<Root>/ OPEN2'
       *  Constant: '<Root>/CLOSE 2'
       */
      if (TrajRunner_P.ManualSwitch7_CurrentSetting == 1) {
        tmp_0 = TrajRunner_P.CLOSE2_Value;
      } else {
        tmp_0 = TrajRunner_P.OPEN2_Value;
      }

      if (tmp_0 != 0.0) {
        TrajRunner_DW.cmd[1] -= TrajRunner_P.Constant7_Value *
          TrajRunner_P.Constant18_Value;
      } else {
        TrajRunner_DW.cmd[1] += TrajRunner_P.Constant7_Value *
          TrajRunner_P.Constant18_Value;
      }

      TrajRunner_DW.cmd[1] = fmin(fmax(TrajRunner_DW.cmd[1], -1.2217304763960306),
        1.2217304763960306);
      TrajRunner_DW.cmd[2] = -1.63712;
      TrajRunner_B.phi_cmd[0] = TrajRunner_DW.cmd[0];
      TrajRunner_B.phi_cmd[1] = TrajRunner_DW.cmd[1];
      TrajRunner_B.phi_cmd[2] = -1.63712;
      TrajRunner_B.phi_cmd[3] = TrajRunner_DW.cmd[3];
    } else {
      TrajRunner_B.phi_cmd[0] = TrajRunner_B.HILReadTimebase1_o11;
      TrajRunner_B.phi_cmd[1] = TrajRunner_B.HILReadTimebase1_o12;
      TrajRunner_B.phi_cmd[2] = TrajRunner_B.HILReadTimebase1_o13;
      TrajRunner_B.phi_cmd[3] = TrajRunner_B.HILReadTimebase1_o14;
    }

    /* End of MATLAB Function: '<Root>/MATLAB Function1' */
  }

  /* ManualSwitch: '<Root>/MAIN1' */
  if (TrajRunner_P.MAIN1_CurrentSetting == 1) {
    /* ManualSwitch: '<Root>/MAIN1' */
    TrajRunner_B.MAIN1[0] = TrajRunner_B.MAIN[0];
    TrajRunner_B.MAIN1[1] = TrajRunner_B.MAIN[1];
    TrajRunner_B.MAIN1[2] = TrajRunner_B.MAIN[2];
    TrajRunner_B.MAIN1[3] = TrajRunner_B.MAIN[3];
  } else {
    /* ManualSwitch: '<Root>/MAIN1' */
    TrajRunner_B.MAIN1[0] = TrajRunner_B.phi_cmd[0];
    TrajRunner_B.MAIN1[1] = TrajRunner_B.phi_cmd[1];
    TrajRunner_B.MAIN1[2] = TrajRunner_B.phi_cmd[2];
    TrajRunner_B.MAIN1[3] = TrajRunner_B.phi_cmd[3];
  }

  /* End of ManualSwitch: '<Root>/MAIN1' */

  /* Integrator: '<S7>/Integrator' */
  /* Limited  Integrator  */
  if (rtsiIsModeUpdateTimeStep(&TrajRunner_M->solverInfo)) {
    zcEvent = rt_ZCFcn(ANY_ZERO_CROSSING,
                       &TrajRunner_PrevZCX.Integrator_Reset_ZCE,
                       (TrajRunner_B.ManualSwitch5));

    /* evaluate zero-crossings */
    if (zcEvent != NO_ZCEVENT) {
      TrajRunner_X.Integrator_CSTATE = TrajRunner_P.Integrator_IC;
    }
  }

  if (TrajRunner_X.Integrator_CSTATE >= TrajRunner_P.Integrator_UpperSat) {
    TrajRunner_X.Integrator_CSTATE = TrajRunner_P.Integrator_UpperSat;
  } else if (TrajRunner_X.Integrator_CSTATE <= TrajRunner_P.Integrator_LowerSat)
  {
    TrajRunner_X.Integrator_CSTATE = TrajRunner_P.Integrator_LowerSat;
  }

  /* Switch: '<S7>/Switch' */
  if (TrajRunner_B.ManualSwitch5 > TrajRunner_P.Switch_Threshold) {
    /* Switch: '<S7>/Switch' incorporates:
     *  Integrator: '<S7>/Integrator'
     */
    TrajRunner_B.gripposition = TrajRunner_X.Integrator_CSTATE;
  } else {
    /* Switch: '<S7>/Switch' incorporates:
     *  Constant: '<S7>/open position'
     */
    TrajRunner_B.gripposition = TrajRunner_P.openposition_Value;
  }

  /* End of Switch: '<S7>/Switch' */
  if (tmp) {
    /* S-Function (smooth_signal_generator_block): '<S2>/Smooth Signal Generator' */
    /* S-Function Block: TrajRunner/Hardware Plant P(s)/Smooth Signal Generator (smooth_signal_generator_block) */
    {
      real_T w = TWO_PI * TrajRunner_P.SmoothSignalGenerator_Frequency;
      boolean_T params_changed = (TrajRunner_P.SmoothSignalGenerator_Amplitude
        != TrajRunner_DW.SmoothSignalGenerator_RWORK.Amp || w !=
        TrajRunner_DW.SmoothSignalGenerator_RWORK.W);

      /*
         Discrete-time:

         y_sin = sin(w*(t + dt)) = sin(w*t)*cos(w*dt) + cos(w*t)*sin(w*dt)
         y_cos = cos(w*(t + dt)) = cos(w*t)*cos(w*dt) - sin(w*t)*sin(w*dt)

         Since dt is fixed and known (the sampling period), we can compute the
         output at the next time step, t + dt, from the previous time step, t,
         simply by applying the formulae above where sin(w*dt) and cos(w*dt) are constant.

         Now, suppose the amplitude or frequency is changed. Then when the current
         value of the output is less than the new amplitude, we need to solve the
         equation:
         1. A1 * y_sin = A2 * sin(x)
         whence:
         x  = asin(A1*y_sin/A2)
         We can then compute a new value of sin(x) and cos(x).
       */
      real_T y_sin = TrajRunner_DW.SmoothSignalGenerator_RWORK.Sin_w_t;
      real_T y_cos = TrajRunner_DW.SmoothSignalGenerator_RWORK.Cos_w_t;

      /* Produce the output(s) */
      rtb_Bias = TrajRunner_DW.SmoothSignalGenerator_RWORK.Amp * y_sin;

      /* Compute the new sin and cos values */
      TrajRunner_DW.SmoothSignalGenerator_RWORK.Sin_w_t = y_sin *
        TrajRunner_DW.SmoothSignalGenerator_RWORK.Cos_w_dt + y_cos *
        TrajRunner_DW.SmoothSignalGenerator_RWORK.Sin_w_dt;
      TrajRunner_DW.SmoothSignalGenerator_RWORK.Cos_w_t = y_cos *
        TrajRunner_DW.SmoothSignalGenerator_RWORK.Cos_w_dt - y_sin *
        TrajRunner_DW.SmoothSignalGenerator_RWORK.Sin_w_dt;

      /*
         If the amplitude or frequency parameter changes, then adjust the
         sine wave parameters such that the sine wave output is continuous.
       */
      if (params_changed) {
        real_T x;

        /*
           Only adjust the amplitude once the current amplitude crosses zero. Otherwise
           we get strange behaviour when continuously modifying the input amplitude and
           frequency using input signals.
         */
        if (y_sin == 0 || TrajRunner_DW.SmoothSignalGenerator_RWORK.Sin_w_t == 0
            || (y_sin < 0) != (TrajRunner_DW.SmoothSignalGenerator_RWORK.Sin_w_t
             < 0)) {
          if (fabs(TrajRunner_DW.SmoothSignalGenerator_RWORK.Amp *
                   TrajRunner_DW.SmoothSignalGenerator_RWORK.Sin_w_t) <
              TrajRunner_P.SmoothSignalGenerator_Amplitude) {
            x = asin(TrajRunner_DW.SmoothSignalGenerator_RWORK.Amp *
                     TrajRunner_DW.SmoothSignalGenerator_RWORK.Sin_w_t /
                     TrajRunner_P.SmoothSignalGenerator_Amplitude);
            TrajRunner_DW.SmoothSignalGenerator_RWORK.Sin_w_dt = sin(w * 0.002);
            TrajRunner_DW.SmoothSignalGenerator_RWORK.Cos_w_dt = cos(w * 0.002);
            TrajRunner_DW.SmoothSignalGenerator_RWORK.Sin_w_t = sin(x);

            /*
               There are always two solutions for the phase. Choose the solution
               that matches the slope as well as the amplitude.
             */
            if ((cos(x) < 0) !=
                (TrajRunner_DW.SmoothSignalGenerator_RWORK.Cos_w_t < 0)) {
              TrajRunner_DW.SmoothSignalGenerator_RWORK.Cos_w_t = -cos(x);
            } else {
              TrajRunner_DW.SmoothSignalGenerator_RWORK.Cos_w_t = cos(x);
            }
          } else {
            /* really low amplitudes where sawtooth wave goes further in one time step after crossing zero than the new amplitude */
            x = w * 0.002;
            TrajRunner_DW.SmoothSignalGenerator_RWORK.Sin_w_t = 0;

            /* Make sure cosine output is also continuous */
            if (TrajRunner_DW.SmoothSignalGenerator_RWORK.Cos_w_t < 0) {
              TrajRunner_DW.SmoothSignalGenerator_RWORK.Cos_w_t = -1;
            } else {
              TrajRunner_DW.SmoothSignalGenerator_RWORK.Cos_w_t = +1;
            }

            TrajRunner_DW.SmoothSignalGenerator_RWORK.Sin_w_dt = sin(x);
            TrajRunner_DW.SmoothSignalGenerator_RWORK.Cos_w_dt = cos(x);
          }

          TrajRunner_DW.SmoothSignalGenerator_RWORK.Amp =
            TrajRunner_P.SmoothSignalGenerator_Amplitude;
          TrajRunner_DW.SmoothSignalGenerator_RWORK.W = w;
        }
      }
    }

    /* Bias: '<S2>/Bias' */
    rtb_Bias += TrajRunner_P.Bias_Bias;

    /* S-Function (hil_write_block): '<S2>/HIL Write' incorporates:
     *  Constant: '<Root>/Constant1'
     *  Constant: '<S1>/Constant'
     */

    /* S-Function Block: TrajRunner/Hardware Plant P(s)/HIL Write (hil_write_block) */
    {
      t_error result;
      TrajRunner_DW.HILWrite_OtherBuffer[0] = TrajRunner_B.MAIN1[0];
      TrajRunner_DW.HILWrite_OtherBuffer[1] = TrajRunner_B.MAIN1[1];
      TrajRunner_DW.HILWrite_OtherBuffer[2] = TrajRunner_B.MAIN1[2];
      TrajRunner_DW.HILWrite_OtherBuffer[3] = TrajRunner_B.MAIN1[3];
      TrajRunner_DW.HILWrite_OtherBuffer[4] = TrajRunner_B.gripposition;
      TrajRunner_DW.HILWrite_OtherBuffer[5] = TrajRunner_P.Constant1_Value[0];
      TrajRunner_DW.HILWrite_OtherBuffer[6] = TrajRunner_P.Constant1_Value[1];
      TrajRunner_DW.HILWrite_OtherBuffer[7] = TrajRunner_P.Constant1_Value[2];
      TrajRunner_DW.HILWrite_OtherBuffer[8] = TrajRunner_P.Constant1_Value[3];
      TrajRunner_DW.HILWrite_OtherBuffer[9] = TrajRunner_P.ColorConstant_color[0];
      TrajRunner_DW.HILWrite_OtherBuffer[10] = TrajRunner_P.ColorConstant_color
        [1];
      TrajRunner_DW.HILWrite_OtherBuffer[11] = TrajRunner_P.ColorConstant_color
        [2];
      TrajRunner_DW.HILWrite_OtherBuffer[12] = rtb_Bias;
      result = hil_write(TrajRunner_DW.HILInitializePositionMode_Card,
                         NULL, 0U,
                         NULL, 0U,
                         NULL, 0U,
                         TrajRunner_P.HILWrite_other_channels, 13U,
                         NULL,
                         NULL,
                         NULL,
                         &TrajRunner_DW.HILWrite_OtherBuffer[0]
                         );
      if (result < 0) {
        msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
          (_rt_error_message));
        rtmSetErrorStatus(TrajRunner_M, _rt_error_message);
      }
    }

    /* Constant: '<S8>/x0' */
    TrajRunner_B.x0 = TrajRunner_P.x0_Value;
  }

  /* Integrator: '<S8>/Integrator1' */
  if (TrajRunner_DW.Integrator1_DWORK1) {
    TrajRunner_X.Integrator1_CSTATE = TrajRunner_B.x0;
  }

  /* Integrator: '<S8>/Integrator1' */
  TrajRunner_B.Integrator1 = TrajRunner_X.Integrator1_CSTATE;
  if (tmp) {
    /* Constant: '<S7>/Soft-Grip Current (A)' */
    TrajRunner_B.goalcurrent = TrajRunner_P.SoftGripCurrentA_Value;
  }

  /* Product: '<S8>/Product' incorporates:
   *  Constant: '<S8>/Constant'
   *  Constant: '<S8>/wn'
   *  Constant: '<S8>/zt'
   *  Integrator: '<S8>/Integrator2'
   *  Product: '<S8>/Product2'
   *  Sum: '<S8>/Sum'
   *  Sum: '<S8>/Sum1'
   */
  TrajRunner_B.Product = ((TrajRunner_B.grippercurrent -
    TrajRunner_B.Integrator1) - TrajRunner_X.Integrator2_CSTATE *
    TrajRunner_P.Constant_Value_i * TrajRunner_P.undOrder25HzfilterbasedonFFT__a)
    * TrajRunner_P.undOrder25HzfilterbasedonFFT_in;

  /* Product: '<S8>/Product1' incorporates:
   *  Constant: '<S8>/wn'
   *  Integrator: '<S8>/Integrator2'
   */
  TrajRunner_B.Product1 = TrajRunner_P.undOrder25HzfilterbasedonFFT_in *
    TrajRunner_X.Integrator2_CSTATE;

  /* Gain: '<S7>/Gain2' incorporates:
   *  Sum: '<S7>/Subtract'
   */
  TrajRunner_B.Gain2 = (TrajRunner_B.goalcurrent - TrajRunner_B.Integrator1) *
    TrajRunner_P.Gain2_Gain;
  if (tmp) {
    /* S-Function (smooth_signal_generator_block): '<Root>/Elbow' */
    /* S-Function Block: TrajRunner/Elbow (smooth_signal_generator_block) */
    {
      real_T w = TWO_PI * TrajRunner_P.Elbow_Frequency;
      boolean_T params_changed = (TrajRunner_P.Elbow_Amplitude !=
        TrajRunner_DW.Elbow_RWORK.Amp || w != TrajRunner_DW.Elbow_RWORK.W);
      real_T T = TWO_PI / TrajRunner_DW.Elbow_RWORK.W;
      if (TrajRunner_DW.Elbow_RWORK.T < 0.5 * T) {
        rtb_Elbow = TrajRunner_DW.Elbow_RWORK.Amp;
      } else {
        rtb_Elbow = -TrajRunner_DW.Elbow_RWORK.Amp;
      }

      /*
         If the amplitude or frequency parameter changes, then adjust the
         square wave parameters such that the square wave output is continuous.
       */
      if (params_changed) {
        /*
           Change the amplitude or frequency when the sign of the output
           changes. This technique ensures that we don't get intermediate
           jumps in amplitude and we don't get higher frequencies than
           expected due to a pulse being prematurely truncated.
         */
        if (TrajRunner_P.Elbow_Amplitude == 0 || rtb_Elbow == 0 ||
            TrajRunner_DW.Elbow_RWORK.Y == 0 || (rtb_Elbow < 0) !=
            (TrajRunner_DW.Elbow_RWORK.Y < 0)) {
          TrajRunner_DW.Elbow_RWORK.Amp = TrajRunner_P.Elbow_Amplitude;
          TrajRunner_DW.Elbow_RWORK.W = w;
          T = TWO_PI / w;
          if (rtb_Elbow >= 0) {
            TrajRunner_DW.Elbow_RWORK.T = 0;
            rtb_Elbow = TrajRunner_P.Elbow_Amplitude;
          } else {
            TrajRunner_DW.Elbow_RWORK.T = T / 2;
            rtb_Elbow = -TrajRunner_P.Elbow_Amplitude;
          }
        }
      }

      TrajRunner_DW.Elbow_RWORK.T += 0.002;
      if (TrajRunner_DW.Elbow_RWORK.T >= T) {
        TrajRunner_DW.Elbow_RWORK.T = 0;
      }

      TrajRunner_DW.Elbow_RWORK.Y = rtb_Elbow;
    }
  }
}

/* Model update function */
void TrajRunner_update(void)
{
  /* Update for Integrator: '<S8>/Integrator1' */
  TrajRunner_DW.Integrator1_DWORK1 = false;
  if (rtmIsMajorTimeStep(TrajRunner_M)) {
    rt_ertODEUpdateContinuousStates(&TrajRunner_M->solverInfo);
  }

  /* Update absolute time for base rate */
  /* The "clockTick0" counts the number of times the code of this task has
   * been executed. The absolute time is the multiplication of "clockTick0"
   * and "Timing.stepSize0". Size of "clockTick0" ensures timer will not
   * overflow during the application lifespan selected.
   * Timer of this task consists of two 32 bit unsigned integers.
   * The two integers represent the low bits Timing.clockTick0 and the high bits
   * Timing.clockTickH0. When the low bit overflows to 0, the high bits increment.
   */
  if (!(++TrajRunner_M->Timing.clockTick0)) {
    ++TrajRunner_M->Timing.clockTickH0;
  }

  TrajRunner_M->Timing.t[0] = rtsiGetSolverStopTime(&TrajRunner_M->solverInfo);

  {
    /* Update absolute timer for sample time: [0.002s, 0.0s] */
    /* The "clockTick1" counts the number of times the code of this task has
     * been executed. The absolute time is the multiplication of "clockTick1"
     * and "Timing.stepSize1". Size of "clockTick1" ensures timer will not
     * overflow during the application lifespan selected.
     * Timer of this task consists of two 32 bit unsigned integers.
     * The two integers represent the low bits Timing.clockTick1 and the high bits
     * Timing.clockTickH1. When the low bit overflows to 0, the high bits increment.
     */
    if (!(++TrajRunner_M->Timing.clockTick1)) {
      ++TrajRunner_M->Timing.clockTickH1;
    }

    TrajRunner_M->Timing.t[1] = TrajRunner_M->Timing.clockTick1 *
      TrajRunner_M->Timing.stepSize1 + TrajRunner_M->Timing.clockTickH1 *
      TrajRunner_M->Timing.stepSize1 * 4294967296.0;
  }
}

/* Derivatives for root system: '<Root>' */
void TrajRunner_derivatives(void)
{
  XDot_TrajRunner_T *_rtXdot;
  boolean_T lsat;
  boolean_T usat;
  _rtXdot = ((XDot_TrajRunner_T *) TrajRunner_M->derivs);

  /* Derivatives for Integrator: '<S7>/Integrator' */
  lsat = (TrajRunner_X.Integrator_CSTATE <= TrajRunner_P.Integrator_LowerSat);
  usat = (TrajRunner_X.Integrator_CSTATE >= TrajRunner_P.Integrator_UpperSat);
  if ((!lsat && !usat) || (lsat && (TrajRunner_B.Gain2 > 0.0)) || (usat &&
       (TrajRunner_B.Gain2 < 0.0))) {
    _rtXdot->Integrator_CSTATE = TrajRunner_B.Gain2;
  } else {
    /* in saturation */
    _rtXdot->Integrator_CSTATE = 0.0;
  }

  /* End of Derivatives for Integrator: '<S7>/Integrator' */

  /* Derivatives for Integrator: '<S8>/Integrator1' */
  _rtXdot->Integrator1_CSTATE = TrajRunner_B.Product1;

  /* Derivatives for Integrator: '<S8>/Integrator2' */
  _rtXdot->Integrator2_CSTATE = TrajRunner_B.Product;
}

/* Model initialize function */
void TrajRunner_initialize(void)
{
  /* Start for S-Function (hil_initialize_block): '<Root>/HIL Initialize (Position Mode)' */

  /* S-Function Block: TrajRunner/HIL Initialize (Position Mode) (hil_initialize_block) */
  {
    t_int result;
    t_boolean is_switching;
    result = hil_open("qarm_usb", "0",
                      &TrajRunner_DW.HILInitializePositionMode_Card);
    if (result < 0) {
      msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
        (_rt_error_message));
      rtmSetErrorStatus(TrajRunner_M, _rt_error_message);
      return;
    }

    is_switching = false;
    result = hil_set_card_specific_options
      (TrajRunner_DW.HILInitializePositionMode_Card,
       "j0_mode=0;j1_mode=0;j2_mode=0;j3_mode=0;gripper_mode=0;j0_profile_config=1;j0_profile_velocity=0.05;j0_profile_acceleration=0.01;j1_profile_config=1;j1_profile_velocity=0.05;j1_profile_acceleration=0.01;j2_profile_config=1;j2_profile_velocity=0.05;j2_profile_acceleration=0.01;j3_profile_config=1;j3_profile_velocity=0.05;j3_profile_acceleration=0.01;",
       352);
    if (result < 0) {
      msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
        (_rt_error_message));
      rtmSetErrorStatus(TrajRunner_M, _rt_error_message);
      return;
    }

    result = hil_watchdog_clear(TrajRunner_DW.HILInitializePositionMode_Card);
    if (result < 0 && result != -QERR_HIL_WATCHDOG_CLEAR) {
      msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
        (_rt_error_message));
      rtmSetErrorStatus(TrajRunner_M, _rt_error_message);
      return;
    }

    if ((TrajRunner_P.HILInitializePositionMode_OOSta && !is_switching) ||
        (TrajRunner_P.HILInitializePositionMode_OOEnt && is_switching)) {
      {
        int_T i1;
        const real_T *p_HILInitializePositionMode_OOIni =
          TrajRunner_P.HILInitializePositionMode_OOIni;
        real_T *dw_OOValues = &TrajRunner_DW.HILInitializePositionMode_OOVal[0];
        for (i1=0; i1 < 11; i1++) {
          dw_OOValues[i1] = (p_HILInitializePositionMode_OOIni[i1]);
        }
      }

      TrajRunner_DW.HILInitializePositionMode_OOVal[11] =
        (TrajRunner_P.HILInitializePositionMode_OOIni[11]);
      TrajRunner_DW.HILInitializePositionMode_OOVal[12] =
        (TrajRunner_P.HILInitializePositionMode_OOIni[11]);
      result = hil_write_other(TrajRunner_DW.HILInitializePositionMode_Card,
        TrajRunner_P.HILInitializePositionMode_OOCha, 13U,
        &TrajRunner_DW.HILInitializePositionMode_OOVal[0]);
      if (result < 0) {
        msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
          (_rt_error_message));
        rtmSetErrorStatus(TrajRunner_M, _rt_error_message);
        return;
      }
    }

    if (TrajRunner_P.HILInitializePositionMode_OORes) {
      {
        int_T i1;
        const real_T *p_HILInitializePositionMode_OOWat =
          TrajRunner_P.HILInitializePositionMode_OOWat;
        real_T *dw_OOValues = &TrajRunner_DW.HILInitializePositionMode_OOVal[0];
        for (i1=0; i1 < 11; i1++) {
          dw_OOValues[i1] = (p_HILInitializePositionMode_OOWat[i1]);
        }
      }

      TrajRunner_DW.HILInitializePositionMode_OOVal[11] =
        (TrajRunner_P.HILInitializePositionMode_OOWat[11]);
      TrajRunner_DW.HILInitializePositionMode_OOVal[12] =
        (TrajRunner_P.HILInitializePositionMode_OOWat[11]);
      result = hil_watchdog_set_other_expiration_state
        (TrajRunner_DW.HILInitializePositionMode_Card,
         TrajRunner_P.HILInitializePositionMode_OOCha, 13U,
         &TrajRunner_DW.HILInitializePositionMode_OOVal[0]);
      if (result < 0) {
        msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
          (_rt_error_message));
        rtmSetErrorStatus(TrajRunner_M, _rt_error_message);
        return;
      }
    }
  }

  /* Start for S-Function (hil_read_timebase_block): '<S2>/HIL Read Timebase1' */

  /* S-Function Block: TrajRunner/Hardware Plant P(s)/HIL Read Timebase1 (hil_read_timebase_block) */
  {
    t_error result;
    result = hil_task_create_reader(TrajRunner_DW.HILInitializePositionMode_Card,
      TrajRunner_P.HILReadTimebase1_SamplesInBuffe,
      TrajRunner_P.HILReadTimebase1_AnalogChannels, 5U,
      NULL, 0U,
      NULL, 0U,
      TrajRunner_P.HILReadTimebase1_OtherChannels, 20U,
      &TrajRunner_DW.HILReadTimebase1_Task);
    if (result >= 0) {
      result = hil_task_set_buffer_overflow_mode
        (TrajRunner_DW.HILReadTimebase1_Task, (t_buffer_overflow_mode)
         (TrajRunner_P.HILReadTimebase1_OverflowMode - 1));
    }

    if (result < 0) {
      msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
        (_rt_error_message));
      rtmSetErrorStatus(TrajRunner_M, _rt_error_message);
    }
  }

  /* Start for S-Function (sample_time_block): '<Root>/Sample Time' */

  /* S-Function Block: TrajRunner/Sample Time (sample_time_block) */
  {
    t_error result;
    result = timeout_get_high_resolution_time
      (&TrajRunner_DW.SampleTime_PreviousTime);
    if (result < 0) {
      msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
        (_rt_error_message));
      rtmSetErrorStatus(TrajRunner_M, _rt_error_message);
      return;
    }
  }

  /* Start for S-Function (smooth_signal_generator_block): '<Root>/Base' */

  /* S-Function Block: TrajRunner/Base (smooth_signal_generator_block) */
  {
    real_T T = 1.0 / TrajRunner_P.Base_Frequency;
    TrajRunner_DW.Base_RWORK.Amp = TrajRunner_P.Base_Amplitude;
    TrajRunner_DW.Base_RWORK.W = TWO_PI * TrajRunner_P.Base_Frequency;
    TrajRunner_DW.Base_RWORK.T = fmod(TrajRunner_P.Base_InitialPhase, TWO_PI) *
      T / TWO_PI;
    if (TrajRunner_DW.Base_RWORK.T < 0) {
      TrajRunner_DW.Base_RWORK.T += T;
    }

    if (TrajRunner_DW.Base_RWORK.T < 0.5 * T) {
      TrajRunner_DW.Base_RWORK.Y = TrajRunner_P.Base_Amplitude;
    } else {
      TrajRunner_DW.Base_RWORK.Y = -TrajRunner_P.Base_Amplitude;
    }
  }

  /* Start for S-Function (smooth_signal_generator_block): '<Root>/Shoulder' */

  /* S-Function Block: TrajRunner/Shoulder (smooth_signal_generator_block) */
  {
    real_T T = 1.0 / TrajRunner_P.Shoulder_Frequency;
    TrajRunner_DW.Shoulder_RWORK.Amp = TrajRunner_P.Shoulder_Amplitude;
    TrajRunner_DW.Shoulder_RWORK.W = TWO_PI * TrajRunner_P.Shoulder_Frequency;
    TrajRunner_DW.Shoulder_RWORK.T = fmod(TrajRunner_P.Shoulder_InitialPhase,
      TWO_PI) * T / TWO_PI;
    if (TrajRunner_DW.Shoulder_RWORK.T < 0) {
      TrajRunner_DW.Shoulder_RWORK.T += T;
    }

    if (TrajRunner_DW.Shoulder_RWORK.T < 0.5 * T) {
      TrajRunner_DW.Shoulder_RWORK.Y = TrajRunner_P.Shoulder_Amplitude;
    } else {
      TrajRunner_DW.Shoulder_RWORK.Y = -TrajRunner_P.Shoulder_Amplitude;
    }
  }

  /* Start for S-Function (smooth_signal_generator_block): '<Root>/Wrist' */

  /* S-Function Block: TrajRunner/Wrist (smooth_signal_generator_block) */
  {
    real_T T = 1.0 / TrajRunner_P.Wrist_Frequency;
    TrajRunner_DW.Wrist_RWORK.Amp = TrajRunner_P.Wrist_Amplitude;
    TrajRunner_DW.Wrist_RWORK.W = TWO_PI * TrajRunner_P.Wrist_Frequency;
    TrajRunner_DW.Wrist_RWORK.T = fmod(TrajRunner_P.Wrist_InitialPhase, TWO_PI) *
      T / TWO_PI;
    if (TrajRunner_DW.Wrist_RWORK.T < 0) {
      TrajRunner_DW.Wrist_RWORK.T += T;
    }

    if (TrajRunner_DW.Wrist_RWORK.T < 0.5 * T) {
      TrajRunner_DW.Wrist_RWORK.Y = TrajRunner_P.Wrist_Amplitude;
    } else {
      TrajRunner_DW.Wrist_RWORK.Y = -TrajRunner_P.Wrist_Amplitude;
    }
  }

  /* Start for S-Function (smooth_signal_generator_block): '<S2>/Smooth Signal Generator' */

  /* S-Function Block: TrajRunner/Hardware Plant P(s)/Smooth Signal Generator (smooth_signal_generator_block) */
  {
    real_T T = 1.0 / TrajRunner_P.SmoothSignalGenerator_Frequency;
    TrajRunner_DW.SmoothSignalGenerator_RWORK.Amp =
      TrajRunner_P.SmoothSignalGenerator_Amplitude;
    TrajRunner_DW.SmoothSignalGenerator_RWORK.W = TWO_PI *
      TrajRunner_P.SmoothSignalGenerator_Frequency;
    TrajRunner_DW.SmoothSignalGenerator_RWORK.Sin_w_dt = sin
      (TrajRunner_DW.SmoothSignalGenerator_RWORK.W * 0.002);
    TrajRunner_DW.SmoothSignalGenerator_RWORK.Cos_w_dt = cos
      (TrajRunner_DW.SmoothSignalGenerator_RWORK.W * 0.002);
    TrajRunner_DW.SmoothSignalGenerator_RWORK.Sin_w_t = sin
      (TrajRunner_P.SmoothSignalGenerator_InitialPh);
    TrajRunner_DW.SmoothSignalGenerator_RWORK.Cos_w_t = cos
      (TrajRunner_P.SmoothSignalGenerator_InitialPh);
  }

  /* Start for Constant: '<S8>/x0' */
  TrajRunner_B.x0 = TrajRunner_P.x0_Value;

  /* Start for S-Function (smooth_signal_generator_block): '<Root>/Elbow' */

  /* S-Function Block: TrajRunner/Elbow (smooth_signal_generator_block) */
  {
    real_T T = 1.0 / TrajRunner_P.Elbow_Frequency;
    TrajRunner_DW.Elbow_RWORK.Amp = TrajRunner_P.Elbow_Amplitude;
    TrajRunner_DW.Elbow_RWORK.W = TWO_PI * TrajRunner_P.Elbow_Frequency;
    TrajRunner_DW.Elbow_RWORK.T = fmod(TrajRunner_P.Elbow_InitialPhase, TWO_PI) *
      T / TWO_PI;
    if (TrajRunner_DW.Elbow_RWORK.T < 0) {
      TrajRunner_DW.Elbow_RWORK.T += T;
    }

    if (TrajRunner_DW.Elbow_RWORK.T < 0.5 * T) {
      TrajRunner_DW.Elbow_RWORK.Y = TrajRunner_P.Elbow_Amplitude;
    } else {
      TrajRunner_DW.Elbow_RWORK.Y = -TrajRunner_P.Elbow_Amplitude;
    }
  }

  TrajRunner_PrevZCX.Integrator_Reset_ZCE = UNINITIALIZED_ZCSIG;

  /* InitializeConditions for Integrator: '<S7>/Integrator' */
  TrajRunner_X.Integrator_CSTATE = TrajRunner_P.Integrator_IC;

  /* InitializeConditions for Integrator: '<S8>/Integrator1' */
  if (rtmIsFirstInitCond(TrajRunner_M)) {
    TrajRunner_X.Integrator1_CSTATE = 0.0;
  }

  TrajRunner_DW.Integrator1_DWORK1 = true;

  /* End of InitializeConditions for Integrator: '<S8>/Integrator1' */

  /* InitializeConditions for Integrator: '<S8>/Integrator2' */
  TrajRunner_X.Integrator2_CSTATE = TrajRunner_P.Integrator2_IC;

  /* SystemInitialize for MATLAB Function: '<Root>/MATLAB Function' */
  TrajRunner_DW.sfEvent_p = TrajRunner_CALL_EVENT;

  /* SystemInitialize for MATLAB Function: '<Root>/MATLAB Function1' */
  TrajRunner_DW.cmd[0] = 0.0;
  TrajRunner_DW.cmd[1] = -1.1318;
  TrajRunner_DW.cmd[2] = -1.5707963267948966;
  TrajRunner_DW.cmd[3] = 0.0;
  TrajRunner_DW.cmd_not_empty = true;
  TrajRunner_DW.sfEvent = TrajRunner_CALL_EVENT;

  /* set "at time zero" to false */
  if (rtmIsFirstInitCond(TrajRunner_M)) {
    rtmSetFirstInitCond(TrajRunner_M, 0);
  }
}

/* Model terminate function */
void TrajRunner_terminate(void)
{
  /* Terminate for S-Function (hil_initialize_block): '<Root>/HIL Initialize (Position Mode)' */

  /* S-Function Block: TrajRunner/HIL Initialize (Position Mode) (hil_initialize_block) */
  {
    t_boolean is_switching;
    t_int result;
    t_uint32 num_final_other_outputs = 0;
    hil_task_stop_all(TrajRunner_DW.HILInitializePositionMode_Card);
    hil_monitor_stop_all(TrajRunner_DW.HILInitializePositionMode_Card);
    is_switching = false;
    if ((TrajRunner_P.HILInitializePositionMode_OOTer && !is_switching) ||
        (TrajRunner_P.HILInitializePositionMode_OOExi && is_switching)) {
      TrajRunner_DW.HILInitializePositionMode_OOVal[0] =
        (TrajRunner_P.HILInitializePositionMode_OOFin[0]);
      TrajRunner_DW.HILInitializePositionMode_OOVal[1] =
        (TrajRunner_P.HILInitializePositionMode_OOFin[1]);
      TrajRunner_DW.HILInitializePositionMode_OOVal[2] =
        (TrajRunner_P.HILInitializePositionMode_OOFin[2]);

      {
        int_T i1;
        real_T *dw_OOValues = &TrajRunner_DW.HILInitializePositionMode_OOVal[3];
        for (i1=0; i1 < 10; i1++) {
          dw_OOValues[i1] = (TrajRunner_P.HILInitializePositionMode_OOFin[3]);
        }
      }

      num_final_other_outputs = 13U;
    } else {
      num_final_other_outputs = 0;
    }

    if (num_final_other_outputs > 0) {
      result = hil_write_other(TrajRunner_DW.HILInitializePositionMode_Card,
        TrajRunner_P.HILInitializePositionMode_OOCha, num_final_other_outputs,
        &TrajRunner_DW.HILInitializePositionMode_OOVal[0]);
      if (result < 0) {
        msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
          (_rt_error_message));
        rtmSetErrorStatus(TrajRunner_M, _rt_error_message);
      }
    }

    hil_task_delete_all(TrajRunner_DW.HILInitializePositionMode_Card);
    hil_monitor_delete_all(TrajRunner_DW.HILInitializePositionMode_Card);
    hil_close(TrajRunner_DW.HILInitializePositionMode_Card);
    TrajRunner_DW.HILInitializePositionMode_Card = NULL;
  }
}

/*========================================================================*
 * Start of Classic call interface                                        *
 *========================================================================*/

/* Solver interface called by GRT_Main */
#ifndef USE_GENERATED_SOLVER

void rt_ODECreateIntegrationData(RTWSolverInfo *si)
{
  UNUSED_PARAMETER(si);
  return;
}                                      /* do nothing */

void rt_ODEDestroyIntegrationData(RTWSolverInfo *si)
{
  UNUSED_PARAMETER(si);
  return;
}                                      /* do nothing */

void rt_ODEUpdateContinuousStates(RTWSolverInfo *si)
{
  UNUSED_PARAMETER(si);
  return;
}                                      /* do nothing */

#endif

void MdlOutputs(int_T tid)
{
  TrajRunner_output();
  UNUSED_PARAMETER(tid);
}

void MdlUpdate(int_T tid)
{
  TrajRunner_update();
  UNUSED_PARAMETER(tid);
}

void MdlInitializeSizes(void)
{
}

void MdlInitializeSampleTimes(void)
{
}

void MdlInitialize(void)
{
}

void MdlStart(void)
{
  TrajRunner_initialize();
}

void MdlTerminate(void)
{
  TrajRunner_terminate();
}

/* Registration function */
RT_MODEL_TrajRunner_T *TrajRunner(void)
{
  /* Registration code */

  /* initialize real-time model */
  (void) memset((void *)TrajRunner_M, 0,
                sizeof(RT_MODEL_TrajRunner_T));

  {
    /* Setup solver object */
    rtsiSetSimTimeStepPtr(&TrajRunner_M->solverInfo,
                          &TrajRunner_M->Timing.simTimeStep);
    rtsiSetTPtr(&TrajRunner_M->solverInfo, &rtmGetTPtr(TrajRunner_M));
    rtsiSetStepSizePtr(&TrajRunner_M->solverInfo,
                       &TrajRunner_M->Timing.stepSize0);
    rtsiSetdXPtr(&TrajRunner_M->solverInfo, &TrajRunner_M->derivs);
    rtsiSetContStatesPtr(&TrajRunner_M->solverInfo, (real_T **)
                         &TrajRunner_M->contStates);
    rtsiSetNumContStatesPtr(&TrajRunner_M->solverInfo,
      &TrajRunner_M->Sizes.numContStates);
    rtsiSetNumPeriodicContStatesPtr(&TrajRunner_M->solverInfo,
      &TrajRunner_M->Sizes.numPeriodicContStates);
    rtsiSetPeriodicContStateIndicesPtr(&TrajRunner_M->solverInfo,
      &TrajRunner_M->periodicContStateIndices);
    rtsiSetPeriodicContStateRangesPtr(&TrajRunner_M->solverInfo,
      &TrajRunner_M->periodicContStateRanges);
    rtsiSetContStateDisabledPtr(&TrajRunner_M->solverInfo, (boolean_T**)
      &TrajRunner_M->contStateDisabled);
    rtsiSetErrorStatusPtr(&TrajRunner_M->solverInfo, (&rtmGetErrorStatus
      (TrajRunner_M)));
    rtsiSetRTModelPtr(&TrajRunner_M->solverInfo, TrajRunner_M);
  }

  rtsiSetSimTimeStep(&TrajRunner_M->solverInfo, MAJOR_TIME_STEP);
  rtsiSetIsMinorTimeStepWithModeChange(&TrajRunner_M->solverInfo, false);
  rtsiSetIsContModeFrozen(&TrajRunner_M->solverInfo, false);
  TrajRunner_M->intgData.y = TrajRunner_M->odeY;
  TrajRunner_M->intgData.f[0] = TrajRunner_M->odeF[0];
  TrajRunner_M->intgData.f[1] = TrajRunner_M->odeF[1];
  TrajRunner_M->intgData.f[2] = TrajRunner_M->odeF[2];
  TrajRunner_M->intgData.f[3] = TrajRunner_M->odeF[3];
  TrajRunner_M->contStates = ((real_T *) &TrajRunner_X);
  TrajRunner_M->contStateDisabled = ((boolean_T *) &TrajRunner_XDis);
  TrajRunner_M->Timing.tStart = (0.0);
  rtsiSetSolverData(&TrajRunner_M->solverInfo, (void *)&TrajRunner_M->intgData);
  rtsiSetSolverName(&TrajRunner_M->solverInfo,"ode4");

  /* Initialize timing info */
  {
    int_T *mdlTsMap = TrajRunner_M->Timing.sampleTimeTaskIDArray;
    mdlTsMap[0] = 0;
    mdlTsMap[1] = 1;
    TrajRunner_M->Timing.sampleTimeTaskIDPtr = (&mdlTsMap[0]);
    TrajRunner_M->Timing.sampleTimes = (&TrajRunner_M->Timing.sampleTimesArray[0]);
    TrajRunner_M->Timing.offsetTimes = (&TrajRunner_M->Timing.offsetTimesArray[0]);

    /* task periods */
    TrajRunner_M->Timing.sampleTimes[0] = (0.0);
    TrajRunner_M->Timing.sampleTimes[1] = (0.002);

    /* task offsets */
    TrajRunner_M->Timing.offsetTimes[0] = (0.0);
    TrajRunner_M->Timing.offsetTimes[1] = (0.0);
  }

  rtmSetTPtr(TrajRunner_M, &TrajRunner_M->Timing.tArray[0]);

  {
    int_T *mdlSampleHits = TrajRunner_M->Timing.sampleHitArray;
    mdlSampleHits[0] = 1;
    mdlSampleHits[1] = 1;
    TrajRunner_M->Timing.sampleHits = (&mdlSampleHits[0]);
  }

  rtmSetTFinal(TrajRunner_M, -1);
  TrajRunner_M->Timing.stepSize0 = 0.002;
  TrajRunner_M->Timing.stepSize1 = 0.002;
  rtmSetFirstInitCond(TrajRunner_M, 1);

  /* External mode info */
  TrajRunner_M->Sizes.checksums[0] = (4017489040U);
  TrajRunner_M->Sizes.checksums[1] = (2946157285U);
  TrajRunner_M->Sizes.checksums[2] = (2063413218U);
  TrajRunner_M->Sizes.checksums[3] = (1572527517U);

  {
    static const sysRanDType rtAlwaysEnabled = SUBSYS_RAN_BC_ENABLE;
    static RTWExtModeInfo rt_ExtModeInfo;
    static const sysRanDType *systemRan[15];
    TrajRunner_M->extModeInfo = (&rt_ExtModeInfo);
    rteiSetSubSystemActiveVectorAddresses(&rt_ExtModeInfo, systemRan);
    systemRan[0] = &rtAlwaysEnabled;
    systemRan[1] = &rtAlwaysEnabled;
    systemRan[2] = &rtAlwaysEnabled;
    systemRan[3] = &rtAlwaysEnabled;
    systemRan[4] = &rtAlwaysEnabled;
    systemRan[5] = &rtAlwaysEnabled;
    systemRan[6] = &rtAlwaysEnabled;
    systemRan[7] = &rtAlwaysEnabled;
    systemRan[8] = &rtAlwaysEnabled;
    systemRan[9] = &rtAlwaysEnabled;
    systemRan[10] = &rtAlwaysEnabled;
    systemRan[11] = &rtAlwaysEnabled;
    systemRan[12] = &rtAlwaysEnabled;
    systemRan[13] = &rtAlwaysEnabled;
    systemRan[14] = &rtAlwaysEnabled;
    rteiSetModelMappingInfoPtr(TrajRunner_M->extModeInfo,
      &TrajRunner_M->SpecialInfo.mappingInfo);
    rteiSetChecksumsPtr(TrajRunner_M->extModeInfo, TrajRunner_M->Sizes.checksums);
    rteiSetTPtr(TrajRunner_M->extModeInfo, rtmGetTPtr(TrajRunner_M));
  }

  TrajRunner_M->solverInfoPtr = (&TrajRunner_M->solverInfo);
  TrajRunner_M->Timing.stepSize = (0.002);
  rtsiSetFixedStepSize(&TrajRunner_M->solverInfo, 0.002);
  rtsiSetSolverMode(&TrajRunner_M->solverInfo, SOLVER_MODE_SINGLETASKING);

  /* block I/O */
  TrajRunner_M->blockIO = ((void *) &TrajRunner_B);
  (void) memset(((void *) &TrajRunner_B), 0,
                sizeof(B_TrajRunner_T));

  /* parameters */
  TrajRunner_M->defaultParam = ((real_T *)&TrajRunner_P);

  /* states (continuous) */
  {
    real_T *x = (real_T *) &TrajRunner_X;
    TrajRunner_M->contStates = (x);
    (void) memset((void *)&TrajRunner_X, 0,
                  sizeof(X_TrajRunner_T));
  }

  /* disabled states */
  {
    boolean_T *xdis = (boolean_T *) &TrajRunner_XDis;
    TrajRunner_M->contStateDisabled = (xdis);
    (void) memset((void *)&TrajRunner_XDis, 0,
                  sizeof(XDis_TrajRunner_T));
  }

  /* states (dwork) */
  TrajRunner_M->dwork = ((void *) &TrajRunner_DW);
  (void) memset((void *)&TrajRunner_DW, 0,
                sizeof(DW_TrajRunner_T));

  /* data type transition information */
  {
    static DataTypeTransInfo dtInfo;
    (void) memset((char_T *) &dtInfo, 0,
                  sizeof(dtInfo));
    TrajRunner_M->SpecialInfo.mappingInfo = (&dtInfo);
    dtInfo.numDataTypes = 22;
    dtInfo.dataTypeSizes = &rtDataTypeSizes[0];
    dtInfo.dataTypeNames = &rtDataTypeNames[0];

    /* Block I/O transition table */
    dtInfo.BTransTable = &rtBTransTable;

    /* Parameters transition table */
    dtInfo.PTransTable = &rtPTransTable;
  }

  /* Initialize Sizes */
  TrajRunner_M->Sizes.numContStates = (3);/* Number of continuous states */
  TrajRunner_M->Sizes.numPeriodicContStates = (0);
                                      /* Number of periodic continuous states */
  TrajRunner_M->Sizes.numY = (0);      /* Number of model outputs */
  TrajRunner_M->Sizes.numU = (0);      /* Number of model inputs */
  TrajRunner_M->Sizes.sysDirFeedThru = (0);/* The model is not direct feedthrough */
  TrajRunner_M->Sizes.numSampTimes = (2);/* Number of sample times */
  TrajRunner_M->Sizes.numBlocks = (89);/* Number of blocks */
  TrajRunner_M->Sizes.numBlockIO = (38);/* Number of block outputs */
  TrajRunner_M->Sizes.numBlockPrms = (219);/* Sum of parameter "widths" */
  return TrajRunner_M;
}

/*========================================================================*
 * End of Classic call interface                                          *
 *========================================================================*/
