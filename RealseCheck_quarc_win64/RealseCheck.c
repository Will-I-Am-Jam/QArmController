/*
 * RealseCheck.c
 *
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * Code generation for model "RealseCheck".
 *
 * Model version              : 13.26
 * Simulink Coder version : 26.1 (R2026a) 20-Nov-2025
 * C source code generated on : Fri Oct 16 11:30:05 2026
 *
 * Target selection: quarc_win64.tlc
 * Note: GRT includes extra infrastructure and instrumentation for prototyping
 * Embedded hardware selection: Intel->x86-64 (Windows64)
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#include "RealseCheck.h"
#include "rtwtypes.h"
#include <math.h>
#include <emmintrin.h>
#include "RealseCheck_private.h"
#include "zero_crossing_types.h"
#include <string.h>
#include "RealseCheck_dt.h"

/* Named constants for MATLAB Function: '<Root>/MATLAB Function' */
#define RealseCheck_CALL_EVENT         (-1)

/* Block signals (default storage) */
B_RealseCheck_T RealseCheck_B;

/* Continuous states */
X_RealseCheck_T RealseCheck_X;

/* Disabled State Vector */
XDis_RealseCheck_T RealseCheck_XDis;

/* Block states (default storage) */
DW_RealseCheck_T RealseCheck_DW;

/* Previous zero-crossings (trigger) states */
PrevZCX_RealseCheck_T RealseCheck_PrevZCX;

/* Real-time model */
static RT_MODEL_RealseCheck_T RealseCheck_M_;
RT_MODEL_RealseCheck_T *const RealseCheck_M = &RealseCheck_M_;

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
  RealseCheck_derivatives();

  /* f1 = f(t + (h/2), y + (h/2)*f0) */
  temp = 0.5 * h;
  for (i = 0; i < nXc; i++) {
    x[i] = y[i] + (temp*f0[i]);
  }

  rtsiSetT(si, t + temp);
  rtsiSetdX(si, f1);
  RealseCheck_output();
  RealseCheck_derivatives();

  /* f2 = f(t + (h/2), y + (h/2)*f1) */
  for (i = 0; i < nXc; i++) {
    x[i] = y[i] + (temp*f1[i]);
  }

  rtsiSetdX(si, f2);
  RealseCheck_output();
  RealseCheck_derivatives();

  /* f3 = f(t + h, y + h*f2) */
  for (i = 0; i < nXc; i++) {
    x[i] = y[i] + (h*f2[i]);
  }

  rtsiSetT(si, tnew);
  rtsiSetdX(si, f3);
  RealseCheck_output();
  RealseCheck_derivatives();

  /* tnew = t + h
     ynew = y + (h/6)*(f0 + 2*f1 + 2*f2 + 2*f3) */
  temp = h / 6.0;
  for (i = 0; i < nXc; i++) {
    x[i] = y[i] + temp*(f0[i] + 2.0*f1[i] + 2.0*f2[i] + f3[i]);
  }

  rtsiSetSimTimeStep(si,MAJOR_TIME_STEP);
}

/* Model output function */
void RealseCheck_output(void)
{
  /* local block i/o variables */
  real_T rtb_gripperspeed;
  real_T rtb_HILReadTimebase1_o20;
  real_T rtb_gripperpwm;
  real_T rtb_Base;
  real_T rtb_Shoulder;
  real_T rtb_Elbow;
  real_T rtb_Wrist;
  __m128d tmp_3;
  __m128d tmp_5;
  real_T T01[16];
  real_T T01_tmp_3[16];
  real_T T01_tmp_4[16];
  real_T T01_tmp_5[16];
  real_T T02[16];
  real_T T03[16];
  real_T T04[16];
  real_T tmp_0[12];
  real_T tmp_1[4];
  real_T c_b[3];
  real_T v_err[3];
  real_T tmp_2[2];
  real_T T01_tmp;
  real_T p_err_idx_0;
  real_T p_err_idx_1;
  real_T rtb_Bias;
  real_T rtb_ManualSwitch2;
  int32_T T01_tmp_tmp;
  int32_T gripperMode;
  int32_T i;
  int32_T tmp_4;
  int32_T tmp_6;
  int8_T T01_tmp_2[16];
  int8_T T01_tmp_0[4];
  int8_T T01_tmp_1[4];
  boolean_T outside;
  boolean_T tmp;
  ZCEventType zcEvent;
  static const int8_T f[16] = { 1, 0, 0, 0, 0, 1, 0, 0, 0, 0, 1, 0, 0, 0, 0, 1 };

  static const real_T e[16] = { 1.0, 0.0, 0.0, 0.0, 0.0, 1.0, 0.0, 0.0, 0.0, 0.0,
    1.0, 0.0, 0.0, 0.0, 0.14, 1.0 };

  static const real_T g[16] = { 1.0, 0.0, 0.0, 0.0, 0.0, 6.123233995736766E-17,
    -1.0, 0.0, 0.0, 1.0, 6.123233995736766E-17, 0.0, 0.0, 0.0, 0.0, 1.0 };

  static const real_T h[16] = { 1.0, 0.0, 0.0, 0.0, 0.0, 1.0, 0.0, 0.0, 0.0, 0.0,
    1.0, 0.0, 0.35355339059327373, 0.0, 0.0, 1.0 };

  static const real_T j[16] = { 1.0, 0.0, 0.0, 0.0, 0.0, 1.0, 0.0, 0.0, 0.0, 0.0,
    1.0, 0.0, 0.0, 0.0, 0.4, 1.0 };

  boolean_T exitg1;
  if (rtmIsMajorTimeStep(RealseCheck_M)) {
    /* set solver stop time */
    if (!(RealseCheck_M->Timing.clockTick0+1)) {
      rtsiSetSolverStopTime(&RealseCheck_M->solverInfo,
                            ((RealseCheck_M->Timing.clockTickH0 + 1) *
        RealseCheck_M->Timing.stepSize0 * 4294967296.0));
    } else {
      rtsiSetSolverStopTime(&RealseCheck_M->solverInfo,
                            ((RealseCheck_M->Timing.clockTick0 + 1) *
        RealseCheck_M->Timing.stepSize0 + RealseCheck_M->Timing.clockTickH0 *
        RealseCheck_M->Timing.stepSize0 * 4294967296.0));
    }
  }                                    /* end MajorTimeStep */

  /* Update absolute time of base rate at minor time step */
  if (rtmIsMinorTimeStep(RealseCheck_M)) {
    RealseCheck_M->Timing.t[0] = rtsiGetT(&RealseCheck_M->solverInfo);
  }

  tmp = rtmIsMajorTimeStep(RealseCheck_M);
  if (tmp) {
    /* S-Function (hil_read_timebase_block): '<S2>/HIL Read Timebase1' */

    /* S-Function Block: RealseCheck/Hardware Plant P(s)/HIL Read Timebase1 (hil_read_timebase_block) */
    {
      t_error result;
      result = hil_task_read(RealseCheck_DW.HILReadTimebase1_Task, 1,
        &RealseCheck_DW.HILReadTimebase1_AnalogBuffer[0],
        NULL,
        NULL,
        &RealseCheck_DW.HILReadTimebase1_OtherBuffer[0]
        );
      if (result < 0) {
        msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
          (_rt_error_message));
        rtmSetErrorStatus(RealseCheck_M, _rt_error_message);
      } else {
        RealseCheck_B.HILReadTimebase1_o1 =
          RealseCheck_DW.HILReadTimebase1_AnalogBuffer[0];
        RealseCheck_B.HILReadTimebase1_o2 =
          RealseCheck_DW.HILReadTimebase1_AnalogBuffer[1];
        RealseCheck_B.HILReadTimebase1_o3 =
          RealseCheck_DW.HILReadTimebase1_AnalogBuffer[2];
        RealseCheck_B.HILReadTimebase1_o4 =
          RealseCheck_DW.HILReadTimebase1_AnalogBuffer[3];
        RealseCheck_B.grippercurrent =
          RealseCheck_DW.HILReadTimebase1_AnalogBuffer[4];
        RealseCheck_B.HILReadTimebase1_o6 =
          RealseCheck_DW.HILReadTimebase1_OtherBuffer[0];
        RealseCheck_B.HILReadTimebase1_o7 =
          RealseCheck_DW.HILReadTimebase1_OtherBuffer[1];
        RealseCheck_B.HILReadTimebase1_o8 =
          RealseCheck_DW.HILReadTimebase1_OtherBuffer[2];
        RealseCheck_B.HILReadTimebase1_o9 =
          RealseCheck_DW.HILReadTimebase1_OtherBuffer[3];
        RealseCheck_B.HILReadTimebase1_o10 =
          RealseCheck_DW.HILReadTimebase1_OtherBuffer[4];
        RealseCheck_B.HILReadTimebase1_o11 =
          RealseCheck_DW.HILReadTimebase1_OtherBuffer[5];
        RealseCheck_B.HILReadTimebase1_o12 =
          RealseCheck_DW.HILReadTimebase1_OtherBuffer[6];
        RealseCheck_B.HILReadTimebase1_o13 =
          RealseCheck_DW.HILReadTimebase1_OtherBuffer[7];
        RealseCheck_B.HILReadTimebase1_o14 =
          RealseCheck_DW.HILReadTimebase1_OtherBuffer[8];
        rtb_gripperspeed = RealseCheck_DW.HILReadTimebase1_OtherBuffer[9];
        RealseCheck_B.HILReadTimebase1_o16 =
          RealseCheck_DW.HILReadTimebase1_OtherBuffer[10];
        RealseCheck_B.HILReadTimebase1_o17 =
          RealseCheck_DW.HILReadTimebase1_OtherBuffer[11];
        RealseCheck_B.HILReadTimebase1_o18 =
          RealseCheck_DW.HILReadTimebase1_OtherBuffer[12];
        RealseCheck_B.HILReadTimebase1_o19 =
          RealseCheck_DW.HILReadTimebase1_OtherBuffer[13];
        rtb_HILReadTimebase1_o20 = RealseCheck_DW.HILReadTimebase1_OtherBuffer
          [14];
        RealseCheck_B.HILReadTimebase1_o21 =
          RealseCheck_DW.HILReadTimebase1_OtherBuffer[15];
        RealseCheck_B.HILReadTimebase1_o22 =
          RealseCheck_DW.HILReadTimebase1_OtherBuffer[16];
        RealseCheck_B.HILReadTimebase1_o23 =
          RealseCheck_DW.HILReadTimebase1_OtherBuffer[17];
        RealseCheck_B.HILReadTimebase1_o24 =
          RealseCheck_DW.HILReadTimebase1_OtherBuffer[18];
        rtb_gripperpwm = RealseCheck_DW.HILReadTimebase1_OtherBuffer[19];
      }
    }

    /* S-Function (sample_time_block): '<Root>/Sample Time' */

    /* S-Function Block: RealseCheck/Sample Time (sample_time_block) */
    {
      t_error result;
      t_timeout current_time;
      t_timeout time_difference;
      result = timeout_get_high_resolution_time(&current_time);
      if (result >= 0) {
        result = timeout_subtract(&time_difference, &current_time,
          &RealseCheck_DW.SampleTime_PreviousTime);
        RealseCheck_B.SampleTime = time_difference.seconds +
          time_difference.nanoseconds * 1e-9;
        memcpy(&RealseCheck_DW.SampleTime_PreviousTime, &current_time, sizeof
               (t_timeout));
      }

      if (result < 0) {
        msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
          (_rt_error_message));
        rtmSetErrorStatus(RealseCheck_M, _rt_error_message);
        return;
      }
    }

    /* S-Function (smooth_signal_generator_block): '<Root>/Base' */
    /* S-Function Block: RealseCheck/Base (smooth_signal_generator_block) */
    {
      real_T w = TWO_PI * RealseCheck_P.Base_Frequency;
      boolean_T params_changed = (RealseCheck_P.Base_Amplitude !=
        RealseCheck_DW.Base_RWORK.Amp || w != RealseCheck_DW.Base_RWORK.W);
      real_T T = TWO_PI / RealseCheck_DW.Base_RWORK.W;
      if (RealseCheck_DW.Base_RWORK.T < 0.5 * T) {
        rtb_Base = RealseCheck_DW.Base_RWORK.Amp;
      } else {
        rtb_Base = -RealseCheck_DW.Base_RWORK.Amp;
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
        if (RealseCheck_P.Base_Amplitude == 0 || rtb_Base == 0 ||
            RealseCheck_DW.Base_RWORK.Y == 0 || (rtb_Base < 0) !=
            (RealseCheck_DW.Base_RWORK.Y < 0)) {
          RealseCheck_DW.Base_RWORK.Amp = RealseCheck_P.Base_Amplitude;
          RealseCheck_DW.Base_RWORK.W = w;
          T = TWO_PI / w;
          if (rtb_Base >= 0) {
            RealseCheck_DW.Base_RWORK.T = 0;
            rtb_Base = RealseCheck_P.Base_Amplitude;
          } else {
            RealseCheck_DW.Base_RWORK.T = T / 2;
            rtb_Base = -RealseCheck_P.Base_Amplitude;
          }
        }
      }

      RealseCheck_DW.Base_RWORK.T += 0.002;
      if (RealseCheck_DW.Base_RWORK.T >= T) {
        RealseCheck_DW.Base_RWORK.T = 0;
      }

      RealseCheck_DW.Base_RWORK.Y = rtb_Base;
    }

    /* S-Function (smooth_signal_generator_block): '<Root>/Shoulder' */
    /* S-Function Block: RealseCheck/Shoulder (smooth_signal_generator_block) */
    {
      real_T w = TWO_PI * RealseCheck_P.Shoulder_Frequency;
      boolean_T params_changed = (RealseCheck_P.Shoulder_Amplitude !=
        RealseCheck_DW.Shoulder_RWORK.Amp || w !=
        RealseCheck_DW.Shoulder_RWORK.W);
      real_T T = TWO_PI / RealseCheck_DW.Shoulder_RWORK.W;
      if (RealseCheck_DW.Shoulder_RWORK.T < 0.5 * T) {
        rtb_Shoulder = RealseCheck_DW.Shoulder_RWORK.Amp;
      } else {
        rtb_Shoulder = -RealseCheck_DW.Shoulder_RWORK.Amp;
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
        if (RealseCheck_P.Shoulder_Amplitude == 0 || rtb_Shoulder == 0 ||
            RealseCheck_DW.Shoulder_RWORK.Y == 0 || (rtb_Shoulder < 0) !=
            (RealseCheck_DW.Shoulder_RWORK.Y < 0)) {
          RealseCheck_DW.Shoulder_RWORK.Amp = RealseCheck_P.Shoulder_Amplitude;
          RealseCheck_DW.Shoulder_RWORK.W = w;
          T = TWO_PI / w;
          if (rtb_Shoulder >= 0) {
            RealseCheck_DW.Shoulder_RWORK.T = 0;
            rtb_Shoulder = RealseCheck_P.Shoulder_Amplitude;
          } else {
            RealseCheck_DW.Shoulder_RWORK.T = T / 2;
            rtb_Shoulder = -RealseCheck_P.Shoulder_Amplitude;
          }
        }
      }

      RealseCheck_DW.Shoulder_RWORK.T += 0.002;
      if (RealseCheck_DW.Shoulder_RWORK.T >= T) {
        RealseCheck_DW.Shoulder_RWORK.T = 0;
      }

      RealseCheck_DW.Shoulder_RWORK.Y = rtb_Shoulder;
    }

    /* S-Function (smooth_signal_generator_block): '<Root>/Elbow' */
    /* S-Function Block: RealseCheck/Elbow (smooth_signal_generator_block) */
    {
      real_T w = TWO_PI * RealseCheck_P.Elbow_Frequency;
      boolean_T params_changed = (RealseCheck_P.Elbow_Amplitude !=
        RealseCheck_DW.Elbow_RWORK.Amp || w != RealseCheck_DW.Elbow_RWORK.W);
      real_T T = TWO_PI / RealseCheck_DW.Elbow_RWORK.W;
      if (RealseCheck_DW.Elbow_RWORK.T < 0.5 * T) {
        rtb_Elbow = RealseCheck_DW.Elbow_RWORK.Amp;
      } else {
        rtb_Elbow = -RealseCheck_DW.Elbow_RWORK.Amp;
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
        if (RealseCheck_P.Elbow_Amplitude == 0 || rtb_Elbow == 0 ||
            RealseCheck_DW.Elbow_RWORK.Y == 0 || (rtb_Elbow < 0) !=
            (RealseCheck_DW.Elbow_RWORK.Y < 0)) {
          RealseCheck_DW.Elbow_RWORK.Amp = RealseCheck_P.Elbow_Amplitude;
          RealseCheck_DW.Elbow_RWORK.W = w;
          T = TWO_PI / w;
          if (rtb_Elbow >= 0) {
            RealseCheck_DW.Elbow_RWORK.T = 0;
            rtb_Elbow = RealseCheck_P.Elbow_Amplitude;
          } else {
            RealseCheck_DW.Elbow_RWORK.T = T / 2;
            rtb_Elbow = -RealseCheck_P.Elbow_Amplitude;
          }
        }
      }

      RealseCheck_DW.Elbow_RWORK.T += 0.002;
      if (RealseCheck_DW.Elbow_RWORK.T >= T) {
        RealseCheck_DW.Elbow_RWORK.T = 0;
      }

      RealseCheck_DW.Elbow_RWORK.Y = rtb_Elbow;
    }

    /* S-Function (smooth_signal_generator_block): '<Root>/Wrist' */
    /* S-Function Block: RealseCheck/Wrist (smooth_signal_generator_block) */
    {
      real_T w = TWO_PI * RealseCheck_P.Wrist_Frequency;
      boolean_T params_changed = (RealseCheck_P.Wrist_Amplitude !=
        RealseCheck_DW.Wrist_RWORK.Amp || w != RealseCheck_DW.Wrist_RWORK.W);
      real_T T = TWO_PI / RealseCheck_DW.Wrist_RWORK.W;
      if (RealseCheck_DW.Wrist_RWORK.T < 0.5 * T) {
        rtb_Wrist = RealseCheck_DW.Wrist_RWORK.Amp;
      } else {
        rtb_Wrist = -RealseCheck_DW.Wrist_RWORK.Amp;
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
        if (RealseCheck_P.Wrist_Amplitude == 0 || rtb_Wrist == 0 ||
            RealseCheck_DW.Wrist_RWORK.Y == 0 || (rtb_Wrist < 0) !=
            (RealseCheck_DW.Wrist_RWORK.Y < 0)) {
          RealseCheck_DW.Wrist_RWORK.Amp = RealseCheck_P.Wrist_Amplitude;
          RealseCheck_DW.Wrist_RWORK.W = w;
          T = TWO_PI / w;
          if (rtb_Wrist >= 0) {
            RealseCheck_DW.Wrist_RWORK.T = 0;
            rtb_Wrist = RealseCheck_P.Wrist_Amplitude;
          } else {
            RealseCheck_DW.Wrist_RWORK.T = T / 2;
            rtb_Wrist = -RealseCheck_P.Wrist_Amplitude;
          }
        }
      }

      RealseCheck_DW.Wrist_RWORK.T += 0.002;
      if (RealseCheck_DW.Wrist_RWORK.T >= T) {
        RealseCheck_DW.Wrist_RWORK.T = 0;
      }

      RealseCheck_DW.Wrist_RWORK.Y = rtb_Wrist;
    }

    /* ManualSwitch: '<Root>/MAIN' incorporates:
     *  ManualSwitch: '<Root>/Manual Switch'
     */
    if (RealseCheck_P.MAIN_CurrentSetting == 1) {
      /* ManualSwitch: '<Root>/MAIN' incorporates:
       *  Constant: '<Root>/Default Cmd'
       */
      RealseCheck_B.MAIN[0] = RealseCheck_P.DefaultCmd_Value[0];
      RealseCheck_B.MAIN[1] = RealseCheck_P.DefaultCmd_Value[1];
      RealseCheck_B.MAIN[2] = RealseCheck_P.DefaultCmd_Value[2];
      RealseCheck_B.MAIN[3] = RealseCheck_P.DefaultCmd_Value[3];
    } else {
      if (RealseCheck_P.ManualSwitch_CurrentSetting == 1) {
        /* ManualSwitch: '<Root>/Manual Switch' incorporates:
         *  ManualSwitch: '<Root>/MAIN'
         */
        RealseCheck_B.MAIN[0] = rtb_Base;
      } else {
        /* ManualSwitch: '<Root>/MAIN' incorporates:
         *  Constant: '<Root>/Constant2'
         *  ManualSwitch: '<Root>/Manual Switch'
         */
        RealseCheck_B.MAIN[0] = RealseCheck_P.Constant2_Value;
      }

      /* ManualSwitch: '<Root>/Manual Switch1' */
      if (RealseCheck_P.ManualSwitch1_CurrentSetting == 1) {
        /* ManualSwitch: '<Root>/MAIN' */
        RealseCheck_B.MAIN[1] = rtb_Shoulder;
      } else {
        /* ManualSwitch: '<Root>/MAIN' incorporates:
         *  Constant: '<Root>/Constant4'
         */
        RealseCheck_B.MAIN[1] = RealseCheck_P.Constant4_Value;
      }

      /* End of ManualSwitch: '<Root>/Manual Switch1' */

      /* ManualSwitch: '<Root>/Manual Switch2' */
      if (RealseCheck_P.ManualSwitch2_CurrentSetting == 1) {
        /* ManualSwitch: '<Root>/MAIN' incorporates:
         *  Constant: '<Root>/offset'
         *  Sum: '<Root>/Sum'
         */
        RealseCheck_B.MAIN[2] = rtb_Elbow + RealseCheck_P.offset_Value;
      } else {
        /* ManualSwitch: '<Root>/MAIN' incorporates:
         *  Constant: '<Root>/Constant6'
         */
        RealseCheck_B.MAIN[2] = RealseCheck_P.Constant6_Value;
      }

      /* End of ManualSwitch: '<Root>/Manual Switch2' */

      /* ManualSwitch: '<Root>/Manual Switch3' */
      if (RealseCheck_P.ManualSwitch3_CurrentSetting == 1) {
        /* ManualSwitch: '<Root>/MAIN' */
        RealseCheck_B.MAIN[3] = rtb_Wrist;
      } else {
        /* ManualSwitch: '<Root>/MAIN' incorporates:
         *  Constant: '<Root>/Constant8'
         */
        RealseCheck_B.MAIN[3] = RealseCheck_P.Constant8_Value;
      }

      /* End of ManualSwitch: '<Root>/Manual Switch3' */
    }

    /* End of ManualSwitch: '<Root>/MAIN' */

    /* MATLAB Function: '<Root>/MATLAB Function1' incorporates:
     *  SignalConversion generated from: '<S4>/ SFunction '
     */
    RealseCheck_DW.sfEvent = RealseCheck_CALL_EVENT;

    /* MATLAB Function 'MATLAB Function1': '<S4>:1' */
    /* '<S4>:1:60' */
    /* '<S4>:1:72' */
    /* '<S4>:1:14' */
    /* '<S4>:1:18' */
    /* '<S4>:1:32' */
    /* '<S4>:1:36' */
    /* '<S4>:1:37' */
    /* '<S4>:1:38' */
    /* '<S4>:1:39' */
    /* '<S4>:1:47' */
    /* '<S4>:1:90' */
    /* '<S4>:1:91' */
    /* '<S4>:1:93' */
    /* '<S4>:1:94' */
    /* '<S4>:1:88' */
    /* '<S4>:1:93' */
    /* '<S4>:1:98' */
    /* '<S4>:1:103' */
    /* '<S4>:1:108' */
    rtb_ManualSwitch2 = sin(RealseCheck_B.HILReadTimebase1_o6);
    T01_tmp = cos(RealseCheck_B.HILReadTimebase1_o6);
    T01_tmp_0[0] = 0;
    T01_tmp_1[0] = 0;
    T01_tmp_0[1] = 0;
    T01_tmp_1[1] = 0;
    T01_tmp_0[2] = 1;
    T01_tmp_1[2] = 0;
    T01_tmp_0[3] = 0;
    T01_tmp_1[3] = 1;
    for (gripperMode = 0; gripperMode < 16; gripperMode++) {
      T01_tmp_2[gripperMode] = f[gripperMode];
    }

    T01_tmp_3[0] = T01_tmp;
    T01_tmp_3[4] = -rtb_ManualSwitch2;
    T01_tmp_3[8] = 0.0;
    T01_tmp_3[12] = 0.0;
    T01_tmp_3[1] = rtb_ManualSwitch2;
    T01_tmp_3[5] = T01_tmp;
    T01_tmp_3[9] = 0.0;
    T01_tmp_3[13] = 0.0;
    for (gripperMode = 0; gripperMode < 4; gripperMode++) {
      T01_tmp_tmp = gripperMode << 2;
      T01_tmp_3[T01_tmp_tmp + 2] = T01_tmp_0[gripperMode];
      T01_tmp_3[T01_tmp_tmp + 3] = T01_tmp_1[gripperMode];
      T01_tmp_4[T01_tmp_tmp] = 0.0;
      T01_tmp_4[T01_tmp_tmp + 1] = 0.0;
      T01_tmp_4[T01_tmp_tmp + 2] = 0.0;
      T01_tmp_4[T01_tmp_tmp + 3] = 0.0;
    }

    for (gripperMode = 0; gripperMode < 4; gripperMode++) {
      T01_tmp_tmp = gripperMode << 2;
      T01_tmp = T01_tmp_4[T01_tmp_tmp];
      p_err_idx_0 = T01_tmp_4[T01_tmp_tmp + 1];
      rtb_ManualSwitch2 = T01_tmp_4[T01_tmp_tmp + 2];
      p_err_idx_1 = T01_tmp_4[T01_tmp_tmp + 3];
      for (i = 0; i < 4; i++) {
        tmp_4 = i << 2;
        tmp_6 = T01_tmp_tmp + i;
        tmp_5 = _mm_set1_pd(e[tmp_6]);
        tmp_3 = _mm_add_pd(_mm_mul_pd(_mm_loadu_pd(&T01_tmp_3[tmp_4]), tmp_5),
                           _mm_set_pd(p_err_idx_0, T01_tmp));
        _mm_storeu_pd(&tmp_2[0], tmp_3);
        T01_tmp = tmp_2[0];
        p_err_idx_0 = tmp_2[1];
        tmp_5 = _mm_add_pd(_mm_mul_pd(_mm_loadu_pd(&T01_tmp_3[tmp_4 + 2]), tmp_5),
                           _mm_set_pd(p_err_idx_1, rtb_ManualSwitch2));
        _mm_storeu_pd(&tmp_2[0], tmp_5);
        rtb_ManualSwitch2 = tmp_2[0];
        p_err_idx_1 = tmp_2[1];
        T04[tmp_6] = 0.0;
      }

      T01_tmp_4[T01_tmp_tmp + 3] = p_err_idx_1;
      T01_tmp_4[T01_tmp_tmp + 2] = rtb_ManualSwitch2;
      T01_tmp_4[T01_tmp_tmp + 1] = p_err_idx_0;
      T01_tmp_4[T01_tmp_tmp] = T01_tmp;
    }

    for (gripperMode = 0; gripperMode < 4; gripperMode++) {
      T01_tmp_tmp = gripperMode << 2;
      T01_tmp = T04[T01_tmp_tmp];
      p_err_idx_0 = T04[T01_tmp_tmp + 1];
      rtb_ManualSwitch2 = T04[T01_tmp_tmp + 2];
      p_err_idx_1 = T04[T01_tmp_tmp + 3];
      for (i = 0; i < 4; i++) {
        tmp_4 = i << 2;
        tmp_6 = T01_tmp_tmp + i;
        tmp_5 = _mm_set1_pd(T01_tmp_2[tmp_6]);
        tmp_3 = _mm_add_pd(_mm_mul_pd(_mm_loadu_pd(&T01_tmp_4[tmp_4]), tmp_5),
                           _mm_set_pd(p_err_idx_0, T01_tmp));
        _mm_storeu_pd(&tmp_2[0], tmp_3);
        T01_tmp = tmp_2[0];
        p_err_idx_0 = tmp_2[1];
        tmp_5 = _mm_add_pd(_mm_mul_pd(_mm_loadu_pd(&T01_tmp_4[tmp_4 + 2]), tmp_5),
                           _mm_set_pd(p_err_idx_1, rtb_ManualSwitch2));
        _mm_storeu_pd(&tmp_2[0], tmp_5);
        rtb_ManualSwitch2 = tmp_2[0];
        p_err_idx_1 = tmp_2[1];
        T01[tmp_6] = 0.0;
      }

      T04[T01_tmp_tmp + 3] = p_err_idx_1;
      T04[T01_tmp_tmp + 2] = rtb_ManualSwitch2;
      T04[T01_tmp_tmp + 1] = p_err_idx_0;
      T04[T01_tmp_tmp] = T01_tmp;
    }

    /* '<S4>:1:48' */
    /* '<S4>:1:90' */
    /* '<S4>:1:91' */
    /* '<S4>:1:93' */
    /* '<S4>:1:94' */
    /* '<S4>:1:88' */
    /* '<S4>:1:93' */
    /* '<S4>:1:98' */
    /* '<S4>:1:103' */
    /* '<S4>:1:108' */
    /* '<S4>:1:49' */
    /* '<S4>:1:90' */
    /* '<S4>:1:91' */
    /* '<S4>:1:93' */
    /* '<S4>:1:94' */
    /* '<S4>:1:88' */
    /* '<S4>:1:93' */
    /* '<S4>:1:98' */
    /* '<S4>:1:103' */
    /* '<S4>:1:108' */
    /* '<S4>:1:50' */
    /* '<S4>:1:90' */
    /* '<S4>:1:91' */
    /* '<S4>:1:93' */
    /* '<S4>:1:94' */
    /* '<S4>:1:88' */
    /* '<S4>:1:93' */
    /* '<S4>:1:98' */
    /* '<S4>:1:103' */
    /* '<S4>:1:108' */
    /* '<S4>:1:52' */
    rtb_ManualSwitch2 = sin((RealseCheck_B.HILReadTimebase1_o7 +
      0.14189705460416394) - 1.5707963267948966);
    T01_tmp = cos((RealseCheck_B.HILReadTimebase1_o7 + 0.14189705460416394) -
                  1.5707963267948966);
    T01_tmp_3[0] = T01_tmp;
    T01_tmp_3[4] = -rtb_ManualSwitch2;
    T01_tmp_3[8] = 0.0;
    T01_tmp_3[12] = 0.0;
    T01_tmp_3[1] = rtb_ManualSwitch2;
    T01_tmp_3[5] = T01_tmp;
    T01_tmp_3[9] = 0.0;
    T01_tmp_3[13] = 0.0;
    for (gripperMode = 0; gripperMode < 4; gripperMode++) {
      T01_tmp_tmp = gripperMode << 2;
      T01_tmp_3[T01_tmp_tmp + 2] = T01_tmp_0[gripperMode];
      T01_tmp_3[T01_tmp_tmp + 3] = T01_tmp_1[gripperMode];
      T01_tmp = T01[T01_tmp_tmp];
      p_err_idx_0 = T01[T01_tmp_tmp + 1];
      rtb_ManualSwitch2 = T01[T01_tmp_tmp + 2];
      p_err_idx_1 = T01[T01_tmp_tmp + 3];
      for (i = 0; i < 4; i++) {
        tmp_4 = i << 2;
        tmp_6 = T01_tmp_tmp + i;
        tmp_5 = _mm_set1_pd(g[tmp_6]);
        tmp_3 = _mm_add_pd(_mm_mul_pd(_mm_loadu_pd(&T04[tmp_4]), tmp_5),
                           _mm_set_pd(p_err_idx_0, T01_tmp));
        _mm_storeu_pd(&tmp_2[0], tmp_3);
        T01_tmp = tmp_2[0];
        p_err_idx_0 = tmp_2[1];
        tmp_5 = _mm_add_pd(_mm_mul_pd(_mm_loadu_pd(&T04[tmp_4 + 2]), tmp_5),
                           _mm_set_pd(p_err_idx_1, rtb_ManualSwitch2));
        _mm_storeu_pd(&tmp_2[0], tmp_5);
        rtb_ManualSwitch2 = tmp_2[0];
        p_err_idx_1 = tmp_2[1];
        T01_tmp_4[tmp_6] = 0.0;
      }

      T01[T01_tmp_tmp + 3] = p_err_idx_1;
      T01[T01_tmp_tmp + 2] = rtb_ManualSwitch2;
      T01[T01_tmp_tmp + 1] = p_err_idx_0;
      T01[T01_tmp_tmp] = T01_tmp;
    }

    for (gripperMode = 0; gripperMode < 4; gripperMode++) {
      T01_tmp_tmp = gripperMode << 2;
      T01_tmp = T01_tmp_4[T01_tmp_tmp];
      p_err_idx_0 = T01_tmp_4[T01_tmp_tmp + 1];
      rtb_ManualSwitch2 = T01_tmp_4[T01_tmp_tmp + 2];
      p_err_idx_1 = T01_tmp_4[T01_tmp_tmp + 3];
      for (i = 0; i < 4; i++) {
        tmp_4 = i << 2;
        tmp_6 = T01_tmp_tmp + i;
        tmp_5 = _mm_set1_pd(T01_tmp_2[tmp_6]);
        tmp_3 = _mm_add_pd(_mm_mul_pd(_mm_loadu_pd(&T01_tmp_3[tmp_4]), tmp_5),
                           _mm_set_pd(p_err_idx_0, T01_tmp));
        _mm_storeu_pd(&tmp_2[0], tmp_3);
        T01_tmp = tmp_2[0];
        p_err_idx_0 = tmp_2[1];
        tmp_5 = _mm_add_pd(_mm_mul_pd(_mm_loadu_pd(&T01_tmp_3[tmp_4 + 2]), tmp_5),
                           _mm_set_pd(p_err_idx_1, rtb_ManualSwitch2));
        _mm_storeu_pd(&tmp_2[0], tmp_5);
        rtb_ManualSwitch2 = tmp_2[0];
        p_err_idx_1 = tmp_2[1];
        T04[tmp_6] = 0.0;
      }

      T01_tmp_4[T01_tmp_tmp + 3] = p_err_idx_1;
      T01_tmp_4[T01_tmp_tmp + 2] = rtb_ManualSwitch2;
      T01_tmp_4[T01_tmp_tmp + 1] = p_err_idx_0;
      T01_tmp_4[T01_tmp_tmp] = T01_tmp;
    }

    for (gripperMode = 0; gripperMode < 4; gripperMode++) {
      T01_tmp_tmp = gripperMode << 2;
      T01_tmp = T04[T01_tmp_tmp];
      p_err_idx_0 = T04[T01_tmp_tmp + 1];
      rtb_ManualSwitch2 = T04[T01_tmp_tmp + 2];
      p_err_idx_1 = T04[T01_tmp_tmp + 3];
      for (i = 0; i < 4; i++) {
        tmp_4 = i << 2;
        tmp_6 = T01_tmp_tmp + i;
        tmp_5 = _mm_set1_pd(h[tmp_6]);
        tmp_3 = _mm_add_pd(_mm_mul_pd(_mm_loadu_pd(&T01_tmp_4[tmp_4]), tmp_5),
                           _mm_set_pd(p_err_idx_0, T01_tmp));
        _mm_storeu_pd(&tmp_2[0], tmp_3);
        T01_tmp = tmp_2[0];
        p_err_idx_0 = tmp_2[1];
        tmp_5 = _mm_add_pd(_mm_mul_pd(_mm_loadu_pd(&T01_tmp_4[tmp_4 + 2]), tmp_5),
                           _mm_set_pd(p_err_idx_1, rtb_ManualSwitch2));
        _mm_storeu_pd(&tmp_2[0], tmp_5);
        rtb_ManualSwitch2 = tmp_2[0];
        p_err_idx_1 = tmp_2[1];
        T01_tmp_3[tmp_6] = 0.0;
      }

      T04[T01_tmp_tmp + 3] = p_err_idx_1;
      T04[T01_tmp_tmp + 2] = rtb_ManualSwitch2;
      T04[T01_tmp_tmp + 1] = p_err_idx_0;
      T04[T01_tmp_tmp] = T01_tmp;
    }

    /* '<S4>:1:53' */
    rtb_ManualSwitch2 = sin(RealseCheck_B.HILReadTimebase1_o8 -
      0.14189705460416394);
    T01_tmp = cos(RealseCheck_B.HILReadTimebase1_o8 - 0.14189705460416394);
    T01_tmp_4[0] = T01_tmp;
    T01_tmp_4[4] = -rtb_ManualSwitch2;
    T01_tmp_4[8] = 0.0;
    T01_tmp_4[12] = 0.0;
    T01_tmp_4[1] = rtb_ManualSwitch2;
    T01_tmp_4[5] = T01_tmp;
    T01_tmp_4[9] = 0.0;
    T01_tmp_4[13] = 0.0;
    for (gripperMode = 0; gripperMode < 4; gripperMode++) {
      T01_tmp_tmp = gripperMode << 2;
      T01_tmp = T01_tmp_3[T01_tmp_tmp];
      p_err_idx_0 = T01_tmp_3[T01_tmp_tmp + 1];
      rtb_ManualSwitch2 = T01_tmp_3[T01_tmp_tmp + 2];
      p_err_idx_1 = T01_tmp_3[T01_tmp_tmp + 3];
      for (i = 0; i < 4; i++) {
        tmp_4 = i << 2;
        tmp_6 = T01_tmp_tmp + i;
        tmp_5 = _mm_set1_pd(T01_tmp_2[tmp_6]);
        tmp_3 = _mm_add_pd(_mm_mul_pd(_mm_loadu_pd(&T04[tmp_4]), tmp_5),
                           _mm_set_pd(p_err_idx_0, T01_tmp));
        _mm_storeu_pd(&tmp_2[0], tmp_3);
        T01_tmp = tmp_2[0];
        p_err_idx_0 = tmp_2[1];
        tmp_5 = _mm_add_pd(_mm_mul_pd(_mm_loadu_pd(&T04[tmp_4 + 2]), tmp_5),
                           _mm_set_pd(p_err_idx_1, rtb_ManualSwitch2));
        _mm_storeu_pd(&tmp_2[0], tmp_5);
        rtb_ManualSwitch2 = tmp_2[0];
        p_err_idx_1 = tmp_2[1];
        T02[tmp_6] = 0.0;
      }

      T01_tmp_3[T01_tmp_tmp + 3] = p_err_idx_1;
      T01_tmp_3[T01_tmp_tmp + 2] = rtb_ManualSwitch2;
      T01_tmp_3[T01_tmp_tmp + 1] = p_err_idx_0;
      T01_tmp_3[T01_tmp_tmp] = T01_tmp;
      T01_tmp_4[T01_tmp_tmp + 2] = T01_tmp_0[gripperMode];
      T01_tmp_4[T01_tmp_tmp + 3] = T01_tmp_1[gripperMode];
      T01_tmp = T02[T01_tmp_tmp];
      p_err_idx_0 = T02[T01_tmp_tmp + 1];
      rtb_ManualSwitch2 = T02[T01_tmp_tmp + 2];
      p_err_idx_1 = T02[T01_tmp_tmp + 3];
      for (i = 0; i < 4; i++) {
        tmp_4 = i << 2;
        tmp_6 = T01_tmp_tmp + i;
        tmp_5 = _mm_set1_pd(T01_tmp_3[tmp_6]);
        tmp_3 = _mm_add_pd(_mm_mul_pd(_mm_loadu_pd(&T01[tmp_4]), tmp_5),
                           _mm_set_pd(p_err_idx_0, T01_tmp));
        _mm_storeu_pd(&tmp_2[0], tmp_3);
        T01_tmp = tmp_2[0];
        p_err_idx_0 = tmp_2[1];
        tmp_5 = _mm_add_pd(_mm_mul_pd(_mm_loadu_pd(&T01[tmp_4 + 2]), tmp_5),
                           _mm_set_pd(p_err_idx_1, rtb_ManualSwitch2));
        _mm_storeu_pd(&tmp_2[0], tmp_5);
        rtb_ManualSwitch2 = tmp_2[0];
        p_err_idx_1 = tmp_2[1];
        T01_tmp_5[tmp_6] = 0.0;
      }

      T02[T01_tmp_tmp + 3] = p_err_idx_1;
      T02[T01_tmp_tmp + 2] = rtb_ManualSwitch2;
      T02[T01_tmp_tmp + 1] = p_err_idx_0;
      T02[T01_tmp_tmp] = T01_tmp;
    }

    for (gripperMode = 0; gripperMode < 4; gripperMode++) {
      T01_tmp_tmp = gripperMode << 2;
      T01_tmp = T01_tmp_5[T01_tmp_tmp];
      p_err_idx_0 = T01_tmp_5[T01_tmp_tmp + 1];
      rtb_ManualSwitch2 = T01_tmp_5[T01_tmp_tmp + 2];
      p_err_idx_1 = T01_tmp_5[T01_tmp_tmp + 3];
      for (i = 0; i < 4; i++) {
        tmp_4 = i << 2;
        tmp_6 = T01_tmp_tmp + i;
        tmp_5 = _mm_set1_pd(T01_tmp_2[tmp_6]);
        tmp_3 = _mm_add_pd(_mm_mul_pd(_mm_loadu_pd(&T01_tmp_4[tmp_4]), tmp_5),
                           _mm_set_pd(p_err_idx_0, T01_tmp));
        _mm_storeu_pd(&tmp_2[0], tmp_3);
        T01_tmp = tmp_2[0];
        p_err_idx_0 = tmp_2[1];
        tmp_5 = _mm_add_pd(_mm_mul_pd(_mm_loadu_pd(&T01_tmp_4[tmp_4 + 2]), tmp_5),
                           _mm_set_pd(p_err_idx_1, rtb_ManualSwitch2));
        _mm_storeu_pd(&tmp_2[0], tmp_5);
        rtb_ManualSwitch2 = tmp_2[0];
        p_err_idx_1 = tmp_2[1];
        T01_tmp_3[tmp_6] = 0.0;
      }

      T01_tmp_5[T01_tmp_tmp + 3] = p_err_idx_1;
      T01_tmp_5[T01_tmp_tmp + 2] = rtb_ManualSwitch2;
      T01_tmp_5[T01_tmp_tmp + 1] = p_err_idx_0;
      T01_tmp_5[T01_tmp_tmp] = T01_tmp;
    }

    for (gripperMode = 0; gripperMode < 4; gripperMode++) {
      T01_tmp_tmp = gripperMode << 2;
      T01_tmp = T01_tmp_3[T01_tmp_tmp];
      p_err_idx_0 = T01_tmp_3[T01_tmp_tmp + 1];
      rtb_ManualSwitch2 = T01_tmp_3[T01_tmp_tmp + 2];
      p_err_idx_1 = T01_tmp_3[T01_tmp_tmp + 3];
      for (i = 0; i < 4; i++) {
        tmp_4 = i << 2;
        tmp_6 = T01_tmp_tmp + i;
        tmp_5 = _mm_set1_pd(T01_tmp_2[tmp_6]);
        tmp_3 = _mm_add_pd(_mm_mul_pd(_mm_loadu_pd(&T01_tmp_5[tmp_4]), tmp_5),
                           _mm_set_pd(p_err_idx_0, T01_tmp));
        _mm_storeu_pd(&tmp_2[0], tmp_3);
        T01_tmp = tmp_2[0];
        p_err_idx_0 = tmp_2[1];
        tmp_5 = _mm_add_pd(_mm_mul_pd(_mm_loadu_pd(&T01_tmp_5[tmp_4 + 2]), tmp_5),
                           _mm_set_pd(p_err_idx_1, rtb_ManualSwitch2));
        _mm_storeu_pd(&tmp_2[0], tmp_5);
        rtb_ManualSwitch2 = tmp_2[0];
        p_err_idx_1 = tmp_2[1];
        T01_tmp_4[tmp_6] = 0.0;
      }

      T01_tmp_3[T01_tmp_tmp + 3] = p_err_idx_1;
      T01_tmp_3[T01_tmp_tmp + 2] = rtb_ManualSwitch2;
      T01_tmp_3[T01_tmp_tmp + 1] = p_err_idx_0;
      T01_tmp_3[T01_tmp_tmp] = T01_tmp;
    }

    /* '<S4>:1:54' */
    rtb_ManualSwitch2 = sin(RealseCheck_B.HILReadTimebase1_o9);
    T01_tmp = cos(RealseCheck_B.HILReadTimebase1_o9);
    T04[0] = T01_tmp;
    T04[4] = -rtb_ManualSwitch2;
    T04[8] = 0.0;
    T04[12] = 0.0;
    T04[1] = rtb_ManualSwitch2;
    T04[5] = T01_tmp;
    T04[9] = 0.0;
    T04[13] = 0.0;
    for (gripperMode = 0; gripperMode < 4; gripperMode++) {
      T01_tmp_tmp = gripperMode << 2;
      T01_tmp = T01_tmp_4[T01_tmp_tmp];
      p_err_idx_0 = T01_tmp_4[T01_tmp_tmp + 1];
      rtb_ManualSwitch2 = T01_tmp_4[T01_tmp_tmp + 2];
      p_err_idx_1 = T01_tmp_4[T01_tmp_tmp + 3];
      for (i = 0; i < 4; i++) {
        tmp_4 = i << 2;
        tmp_6 = T01_tmp_tmp + i;
        tmp_5 = _mm_set1_pd(g[tmp_6]);
        tmp_3 = _mm_add_pd(_mm_mul_pd(_mm_loadu_pd(&T01_tmp_3[tmp_4]), tmp_5),
                           _mm_set_pd(p_err_idx_0, T01_tmp));
        _mm_storeu_pd(&tmp_2[0], tmp_3);
        T01_tmp = tmp_2[0];
        p_err_idx_0 = tmp_2[1];
        tmp_5 = _mm_add_pd(_mm_mul_pd(_mm_loadu_pd(&T01_tmp_3[tmp_4 + 2]), tmp_5),
                           _mm_set_pd(p_err_idx_1, rtb_ManualSwitch2));
        _mm_storeu_pd(&tmp_2[0], tmp_5);
        rtb_ManualSwitch2 = tmp_2[0];
        p_err_idx_1 = tmp_2[1];
        T03[tmp_6] = 0.0;
      }

      T01_tmp_4[T01_tmp_tmp + 3] = p_err_idx_1;
      T01_tmp_4[T01_tmp_tmp + 2] = rtb_ManualSwitch2;
      T01_tmp_4[T01_tmp_tmp + 1] = p_err_idx_0;
      T01_tmp_4[T01_tmp_tmp] = T01_tmp;
      T04[T01_tmp_tmp + 2] = T01_tmp_0[gripperMode];
      T04[T01_tmp_tmp + 3] = T01_tmp_1[gripperMode];
      T01_tmp = T03[T01_tmp_tmp];
      p_err_idx_0 = T03[T01_tmp_tmp + 1];
      rtb_ManualSwitch2 = T03[T01_tmp_tmp + 2];
      p_err_idx_1 = T03[T01_tmp_tmp + 3];
      for (i = 0; i < 4; i++) {
        tmp_4 = i << 2;
        tmp_6 = T01_tmp_tmp + i;
        tmp_5 = _mm_set1_pd(T01_tmp_4[tmp_6]);
        tmp_3 = _mm_add_pd(_mm_mul_pd(_mm_loadu_pd(&T02[tmp_4]), tmp_5),
                           _mm_set_pd(p_err_idx_0, T01_tmp));
        _mm_storeu_pd(&tmp_2[0], tmp_3);
        T01_tmp = tmp_2[0];
        p_err_idx_0 = tmp_2[1];
        tmp_5 = _mm_add_pd(_mm_mul_pd(_mm_loadu_pd(&T02[tmp_4 + 2]), tmp_5),
                           _mm_set_pd(p_err_idx_1, rtb_ManualSwitch2));
        _mm_storeu_pd(&tmp_2[0], tmp_5);
        rtb_ManualSwitch2 = tmp_2[0];
        p_err_idx_1 = tmp_2[1];
        T01_tmp_5[tmp_6] = 0.0;
      }

      T03[T01_tmp_tmp + 3] = p_err_idx_1;
      T03[T01_tmp_tmp + 2] = rtb_ManualSwitch2;
      T03[T01_tmp_tmp + 1] = p_err_idx_0;
      T03[T01_tmp_tmp] = T01_tmp;
    }

    for (gripperMode = 0; gripperMode < 4; gripperMode++) {
      T01_tmp_tmp = gripperMode << 2;
      T01_tmp = T01_tmp_5[T01_tmp_tmp];
      p_err_idx_0 = T01_tmp_5[T01_tmp_tmp + 1];
      rtb_ManualSwitch2 = T01_tmp_5[T01_tmp_tmp + 2];
      p_err_idx_1 = T01_tmp_5[T01_tmp_tmp + 3];
      for (i = 0; i < 4; i++) {
        tmp_4 = i << 2;
        tmp_6 = T01_tmp_tmp + i;
        tmp_5 = _mm_set1_pd(j[tmp_6]);
        tmp_3 = _mm_add_pd(_mm_mul_pd(_mm_loadu_pd(&T04[tmp_4]), tmp_5),
                           _mm_set_pd(p_err_idx_0, T01_tmp));
        _mm_storeu_pd(&tmp_2[0], tmp_3);
        T01_tmp = tmp_2[0];
        p_err_idx_0 = tmp_2[1];
        tmp_5 = _mm_add_pd(_mm_mul_pd(_mm_loadu_pd(&T04[tmp_4 + 2]), tmp_5),
                           _mm_set_pd(p_err_idx_1, rtb_ManualSwitch2));
        _mm_storeu_pd(&tmp_2[0], tmp_5);
        rtb_ManualSwitch2 = tmp_2[0];
        p_err_idx_1 = tmp_2[1];
        T01_tmp_3[tmp_6] = 0.0;
      }

      T01_tmp_5[T01_tmp_tmp + 3] = p_err_idx_1;
      T01_tmp_5[T01_tmp_tmp + 2] = rtb_ManualSwitch2;
      T01_tmp_5[T01_tmp_tmp + 1] = p_err_idx_0;
      T01_tmp_5[T01_tmp_tmp] = T01_tmp;
    }

    for (gripperMode = 0; gripperMode < 4; gripperMode++) {
      T01_tmp_tmp = gripperMode << 2;
      T01_tmp = T01_tmp_3[T01_tmp_tmp];
      p_err_idx_0 = T01_tmp_3[T01_tmp_tmp + 1];
      rtb_ManualSwitch2 = T01_tmp_3[T01_tmp_tmp + 2];
      p_err_idx_1 = T01_tmp_3[T01_tmp_tmp + 3];
      for (i = 0; i < 4; i++) {
        tmp_4 = i << 2;
        tmp_6 = T01_tmp_tmp + i;
        tmp_5 = _mm_set1_pd(T01_tmp_2[tmp_6]);
        tmp_3 = _mm_add_pd(_mm_mul_pd(_mm_loadu_pd(&T01_tmp_5[tmp_4]), tmp_5),
                           _mm_set_pd(p_err_idx_0, T01_tmp));
        _mm_storeu_pd(&tmp_2[0], tmp_3);
        T01_tmp = tmp_2[0];
        p_err_idx_0 = tmp_2[1];
        tmp_5 = _mm_add_pd(_mm_mul_pd(_mm_loadu_pd(&T01_tmp_5[tmp_4 + 2]), tmp_5),
                           _mm_set_pd(p_err_idx_1, rtb_ManualSwitch2));
        _mm_storeu_pd(&tmp_2[0], tmp_5);
        rtb_ManualSwitch2 = tmp_2[0];
        p_err_idx_1 = tmp_2[1];
        T01_tmp_4[tmp_6] = 0.0;
      }

      T01_tmp_3[T01_tmp_tmp + 3] = p_err_idx_1;
      T01_tmp_3[T01_tmp_tmp + 2] = rtb_ManualSwitch2;
      T01_tmp_3[T01_tmp_tmp + 1] = p_err_idx_0;
      T01_tmp_3[T01_tmp_tmp] = T01_tmp;
    }

    for (gripperMode = 0; gripperMode < 4; gripperMode++) {
      T01_tmp_tmp = gripperMode << 2;
      T01_tmp = T01_tmp_4[T01_tmp_tmp];
      p_err_idx_0 = T01_tmp_4[T01_tmp_tmp + 1];
      rtb_ManualSwitch2 = T01_tmp_4[T01_tmp_tmp + 2];
      p_err_idx_1 = T01_tmp_4[T01_tmp_tmp + 3];
      for (i = 0; i < 4; i++) {
        tmp_4 = i << 2;
        tmp_6 = T01_tmp_tmp + i;
        tmp_5 = _mm_set1_pd(T01_tmp_2[tmp_6]);
        tmp_3 = _mm_add_pd(_mm_mul_pd(_mm_loadu_pd(&T01_tmp_3[tmp_4]), tmp_5),
                           _mm_set_pd(p_err_idx_0, T01_tmp));
        _mm_storeu_pd(&tmp_2[0], tmp_3);
        T01_tmp = tmp_2[0];
        p_err_idx_0 = tmp_2[1];
        tmp_5 = _mm_add_pd(_mm_mul_pd(_mm_loadu_pd(&T01_tmp_3[tmp_4 + 2]), tmp_5),
                           _mm_set_pd(p_err_idx_1, rtb_ManualSwitch2));
        _mm_storeu_pd(&tmp_2[0], tmp_5);
        rtb_ManualSwitch2 = tmp_2[0];
        p_err_idx_1 = tmp_2[1];
        T04[tmp_6] = 0.0;
      }

      T01_tmp_4[T01_tmp_tmp + 3] = p_err_idx_1;
      T01_tmp_4[T01_tmp_tmp + 2] = rtb_ManualSwitch2;
      T01_tmp_4[T01_tmp_tmp + 1] = p_err_idx_0;
      T01_tmp_4[T01_tmp_tmp] = T01_tmp;
      T01_tmp = T04[T01_tmp_tmp];
      p_err_idx_0 = T04[T01_tmp_tmp + 1];
      rtb_ManualSwitch2 = T04[T01_tmp_tmp + 2];
      p_err_idx_1 = T04[T01_tmp_tmp + 3];
      for (i = 0; i < 4; i++) {
        tmp_4 = i << 2;
        tmp_5 = _mm_set1_pd(T01_tmp_4[T01_tmp_tmp + i]);
        tmp_3 = _mm_add_pd(_mm_mul_pd(_mm_loadu_pd(&T03[tmp_4]), tmp_5),
                           _mm_set_pd(p_err_idx_0, T01_tmp));
        _mm_storeu_pd(&tmp_2[0], tmp_3);
        T01_tmp = tmp_2[0];
        p_err_idx_0 = tmp_2[1];
        tmp_5 = _mm_add_pd(_mm_mul_pd(_mm_loadu_pd(&T03[tmp_4 + 2]), tmp_5),
                           _mm_set_pd(p_err_idx_1, rtb_ManualSwitch2));
        _mm_storeu_pd(&tmp_2[0], tmp_5);
        rtb_ManualSwitch2 = tmp_2[0];
        p_err_idx_1 = tmp_2[1];
      }

      T04[T01_tmp_tmp + 3] = p_err_idx_1;
      T04[T01_tmp_tmp + 2] = rtb_ManualSwitch2;
      T04[T01_tmp_tmp + 1] = p_err_idx_0;
      T04[T01_tmp_tmp] = T01_tmp;
    }

    /* '<S4>:1:56' */
    /* '<S4>:1:57' */
    /* '<S4>:1:60' */
    /* '<S4>:1:61' */
    /* '<S4>:1:62' */
    /* '<S4>:1:63' */
    /* '<S4>:1:65' */
    /* '<S4>:1:66' */
    /* '<S4>:1:67' */
    /* '<S4>:1:72' */
    _mm_storeu_pd(&tmp_2[0], _mm_sub_pd(_mm_set1_pd(T04[12]), _mm_set_pd(T02[12],
      T01[12])));
    v_err[0] = tmp_2[0];
    c_b[0] = tmp_2[1];
    tmp_5 = _mm_sub_pd(_mm_loadu_pd(&T04[12]), _mm_set_pd(T01[13], T03[12]));
    _mm_storeu_pd(&tmp_2[0], tmp_5);

    /* MATLAB Function: '<Root>/MATLAB Function1' */
    T01_tmp = tmp_2[0];
    v_err[1] = tmp_2[1];
    _mm_storeu_pd(&tmp_2[0], _mm_sub_pd(_mm_set1_pd(T04[13]), _mm_set_pd(T03[13],
      T02[13])));
    c_b[1] = tmp_2[0];
    p_err_idx_0 = tmp_2[1];
    _mm_storeu_pd(&tmp_2[0], _mm_sub_pd(_mm_set1_pd(T04[14]), _mm_set_pd(T02[14],
      T01[14])));
    v_err[2] = tmp_2[0];
    c_b[2] = tmp_2[1];
    rtb_ManualSwitch2 = T04[14] - T03[14];

    /* '<S4>:1:74' */
    /* '<S4>:1:75' */
    /* '<S4>:1:78' */
    p_err_idx_1 = 0.0 * T04[14];
    tmp_0[0] = p_err_idx_1 - T04[13];
    tmp_0[1] = T04[12] - p_err_idx_1;
    _mm_storeu_pd(&tmp_0[2], _mm_sub_pd(_mm_mul_pd(_mm_set_pd(tmp_2[0], 0.0),
      _mm_set_pd(T01[9], T04[13])), _mm_mul_pd(_mm_set_pd(v_err[1], 0.0),
      _mm_set_pd(T01[10], T04[12]))));
    tmp_5 = _mm_sub_pd(_mm_mul_pd(_mm_loadu_pd(&v_err[0]), _mm_set_pd(T01[8],
      T01[10])), _mm_mul_pd(_mm_set_pd(v_err[0], tmp_2[0]), _mm_loadu_pd(&T01[8])));
    _mm_storeu_pd(&tmp_0[4], tmp_5);
    tmp_5 = _mm_sub_pd(_mm_mul_pd(_mm_set_pd(c_b[0], tmp_2[1]), _mm_loadu_pd
      (&T02[9])), _mm_mul_pd(_mm_loadu_pd(&c_b[1]), _mm_set_pd(T02[8], T02[10])));
    _mm_storeu_pd(&tmp_0[6], tmp_5);
    _mm_storeu_pd(&tmp_0[8], _mm_sub_pd(_mm_mul_pd(_mm_set_pd(T03[9], c_b[1]),
      _mm_set_pd(rtb_ManualSwitch2, T02[8])), _mm_mul_pd(_mm_set_pd(p_err_idx_0,
      c_b[0]), _mm_set_pd(T03[10], T02[9]))));
    _mm_storeu_pd(&tmp_0[10], _mm_sub_pd(_mm_mul_pd(_mm_set_pd(T03[8], T01_tmp),
      _mm_set_pd(p_err_idx_0, T03[10])), _mm_mul_pd(_mm_set_pd(T01_tmp, T03[8]),
      _mm_set_pd(T03[9], rtb_ManualSwitch2))));

    /* SignalConversion generated from: '<S4>/ SFunction ' incorporates:
     *  MATLAB Function: '<Root>/MATLAB Function1'
     */
    tmp_1[0] = RealseCheck_B.HILReadTimebase1_o11;
    tmp_1[1] = RealseCheck_B.HILReadTimebase1_o12;
    tmp_1[2] = RealseCheck_B.HILReadTimebase1_o13;
    tmp_1[3] = RealseCheck_B.HILReadTimebase1_o14;

    /* MATLAB Function: '<Root>/MATLAB Function1' */
    p_err_idx_0 = 0.0;
    rtb_ManualSwitch2 = 0.0;
    T01_tmp = 0.0;
    for (gripperMode = 0; gripperMode < 4; gripperMode++) {
      tmp_5 = _mm_add_pd(_mm_mul_pd(_mm_loadu_pd(&tmp_0[3 * gripperMode]),
        _mm_set1_pd(tmp_1[gripperMode])), _mm_set_pd(rtb_ManualSwitch2,
        p_err_idx_0));
      _mm_storeu_pd(&tmp_2[0], tmp_5);
      p_err_idx_0 = tmp_2[0];
      rtb_ManualSwitch2 = tmp_2[1];
      T01_tmp += tmp_0[3 * gripperMode + 2] * tmp_1[gripperMode];
    }

    /* MATLAB Function: '<Root>/MATLAB Function' */
    /* '<S4>:1:79' */
    RealseCheck_DW.sfEvent_p = RealseCheck_CALL_EVENT;

    /* MATLAB Function: '<Root>/MATLAB Function1' */
    /* MATLAB Function 'MATLAB Function': '<S3>:1' */
    /* '<S3>:1:31' */
    /* '<S3>:1:32' */
    RealseCheck_B.v4[0] = p_err_idx_0;
    RealseCheck_B.p4[0] = T04[12];

    /* MATLAB Function: '<Root>/MATLAB Function' incorporates:
     *  Constant: '<Root>/Constant'
     *  Constant: '<Root>/Constant12'
     *  MATLAB Function: '<Root>/MATLAB Function1'
     */
    _mm_storeu_pd(&tmp_2[0], _mm_sub_pd(_mm_set_pd
      (RealseCheck_P.Constant12_Value[0], RealseCheck_P.Constant_Value[0]),
      _mm_set_pd(p_err_idx_0, T04[12])));
    p_err_idx_0 = tmp_2[0];
    v_err[0] = tmp_2[1];

    /* MATLAB Function: '<Root>/MATLAB Function1' */
    RealseCheck_B.v4[1] = rtb_ManualSwitch2;
    RealseCheck_B.p4[1] = T04[13];

    /* MATLAB Function: '<Root>/MATLAB Function' incorporates:
     *  Constant: '<Root>/Constant'
     *  Constant: '<Root>/Constant12'
     *  MATLAB Function: '<Root>/MATLAB Function1'
     */
    _mm_storeu_pd(&tmp_2[0], _mm_sub_pd(_mm_set_pd
      (RealseCheck_P.Constant12_Value[1], RealseCheck_P.Constant_Value[1]),
      _mm_set_pd(rtb_ManualSwitch2, T04[13])));
    p_err_idx_1 = tmp_2[0];
    v_err[1] = tmp_2[1];

    /* MATLAB Function: '<Root>/MATLAB Function1' */
    RealseCheck_B.v4[2] = T01_tmp;
    RealseCheck_B.p4[2] = T04[14];

    /* MATLAB Function: '<Root>/MATLAB Function' incorporates:
     *  Constant: '<Root>/Constant'
     *  Constant: '<Root>/Constant12'
     *  MATLAB Function: '<Root>/MATLAB Function1'
     */
    _mm_storeu_pd(&tmp_2[0], _mm_sub_pd(_mm_set_pd
      (RealseCheck_P.Constant12_Value[2], RealseCheck_P.Constant_Value[2]),
      _mm_set_pd(T01_tmp, T04[14])));
    if (RealseCheck_B.HILReadTimebase1_o10 > 0.5) {
      /* '<S3>:1:34' */
      /* '<S3>:1:35' */
      gripperMode = 1;
    } else {
      /* '<S3>:1:37' */
      gripperMode = 0;
    }

    /* '<S3>:1:40' */
    rtb_ManualSwitch2 = gripperMode;
    if (gripperMode == 1) {
      /* '<S3>:1:42' */
      /* '<S3>:1:46' */
      c_b[0] = fabs(v_err[0]);
      v_err[0] = fabs(p_err_idx_0);
      c_b[1] = fabs(v_err[1]);
      v_err[1] = fabs(p_err_idx_1);
      c_b[2] = fabs(tmp_2[1]);
      v_err[2] = fabs(tmp_2[0]);
      outside = true;
      gripperMode = 0;
      exitg1 = false;
      while (!exitg1 && (gripperMode < 3)) {
        if (!(v_err[gripperMode] <= RealseCheck_P.Constant5_Value[gripperMode]))
        {
          outside = false;
          exitg1 = true;
        } else {
          gripperMode++;
        }
      }

      if (outside) {
        /* '<S3>:1:47' */
        gripperMode = 0;
        exitg1 = false;
        while (!exitg1 && (gripperMode < 3)) {
          if (!(c_b[gripperMode] <= RealseCheck_P.Constant13_Value[gripperMode]))
          {
            outside = false;
            exitg1 = true;
          } else {
            gripperMode++;
          }
        }

        if (outside) {
          /* '<S3>:1:47' */
          /* '<S3>:1:49' */
          rtb_ManualSwitch2 = 0.0;
        }
      }
    } else {
      /* '<S3>:1:54' */
      c_b[0] = fabs(p_err_idx_0);
      c_b[1] = fabs(p_err_idx_1);
      c_b[2] = fabs(tmp_2[0]);
      outside = false;
      exitg1 = false;
      while (!exitg1 && (gripperMode < 3)) {
        if (c_b[gripperMode] >= RealseCheck_P.Constant11_Value[gripperMode]) {
          outside = true;
          exitg1 = true;
        } else {
          gripperMode++;
        }
      }

      if (outside) {
        /* '<S3>:1:55' */
        /* '<S3>:1:56' */
        rtb_ManualSwitch2 = 1.0;
      }
    }

    /* ManualSwitch: '<Root>/Manual Switch5' */
    if (RealseCheck_P.ManualSwitch5_CurrentSetting == 1) {
      /* ManualSwitch: '<Root>/Manual Switch4' */
      if (RealseCheck_P.ManualSwitch4_CurrentSetting == 1) {
        /* ManualSwitch: '<Root>/Manual Switch5' incorporates:
         *  Constant: '<Root>/CLOSE '
         */
        RealseCheck_B.ManualSwitch5 = RealseCheck_P.CLOSE_Value;
      } else {
        /* ManualSwitch: '<Root>/Manual Switch5' incorporates:
         *  Constant: '<Root>/ OPEN'
         */
        RealseCheck_B.ManualSwitch5 = RealseCheck_P.OPEN_Value;
      }
    } else {
      /* ManualSwitch: '<Root>/Manual Switch5' incorporates:
       *  ManualSwitch: '<Root>/Manual Switch4'
       */
      RealseCheck_B.ManualSwitch5 = rtb_ManualSwitch2;
    }

    /* End of ManualSwitch: '<Root>/Manual Switch5' */
  }

  /* Integrator: '<S6>/Integrator' */
  /* Limited  Integrator  */
  if (rtsiIsModeUpdateTimeStep(&RealseCheck_M->solverInfo)) {
    zcEvent = rt_ZCFcn(ANY_ZERO_CROSSING,
                       &RealseCheck_PrevZCX.Integrator_Reset_ZCE,
                       (RealseCheck_B.ManualSwitch5));

    /* evaluate zero-crossings */
    if (zcEvent != NO_ZCEVENT) {
      RealseCheck_X.Integrator_CSTATE = RealseCheck_P.Integrator_IC;
    }
  }

  if (RealseCheck_X.Integrator_CSTATE >= RealseCheck_P.Integrator_UpperSat) {
    RealseCheck_X.Integrator_CSTATE = RealseCheck_P.Integrator_UpperSat;
  } else if (RealseCheck_X.Integrator_CSTATE <=
             RealseCheck_P.Integrator_LowerSat) {
    RealseCheck_X.Integrator_CSTATE = RealseCheck_P.Integrator_LowerSat;
  }

  /* Switch: '<S6>/Switch' */
  if (RealseCheck_B.ManualSwitch5 > RealseCheck_P.Switch_Threshold) {
    /* Switch: '<S6>/Switch' incorporates:
     *  Integrator: '<S6>/Integrator'
     */
    RealseCheck_B.gripposition = RealseCheck_X.Integrator_CSTATE;
  } else {
    /* Switch: '<S6>/Switch' incorporates:
     *  Constant: '<S6>/open position'
     */
    RealseCheck_B.gripposition = RealseCheck_P.openposition_Value;
  }

  /* End of Switch: '<S6>/Switch' */
  if (tmp) {
    /* S-Function (smooth_signal_generator_block): '<S2>/Smooth Signal Generator' */
    /* S-Function Block: RealseCheck/Hardware Plant P(s)/Smooth Signal Generator (smooth_signal_generator_block) */
    {
      real_T w = TWO_PI * RealseCheck_P.SmoothSignalGenerator_Frequency;
      boolean_T params_changed = (RealseCheck_P.SmoothSignalGenerator_Amplitude
        != RealseCheck_DW.SmoothSignalGenerator_RWORK.Amp || w !=
        RealseCheck_DW.SmoothSignalGenerator_RWORK.W);

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
      real_T y_sin = RealseCheck_DW.SmoothSignalGenerator_RWORK.Sin_w_t;
      real_T y_cos = RealseCheck_DW.SmoothSignalGenerator_RWORK.Cos_w_t;

      /* Produce the output(s) */
      rtb_Bias = RealseCheck_DW.SmoothSignalGenerator_RWORK.Amp * y_sin;

      /* Compute the new sin and cos values */
      RealseCheck_DW.SmoothSignalGenerator_RWORK.Sin_w_t = y_sin *
        RealseCheck_DW.SmoothSignalGenerator_RWORK.Cos_w_dt + y_cos *
        RealseCheck_DW.SmoothSignalGenerator_RWORK.Sin_w_dt;
      RealseCheck_DW.SmoothSignalGenerator_RWORK.Cos_w_t = y_cos *
        RealseCheck_DW.SmoothSignalGenerator_RWORK.Cos_w_dt - y_sin *
        RealseCheck_DW.SmoothSignalGenerator_RWORK.Sin_w_dt;

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
        if (y_sin == 0 || RealseCheck_DW.SmoothSignalGenerator_RWORK.Sin_w_t ==
            0 || (y_sin < 0) !=
            (RealseCheck_DW.SmoothSignalGenerator_RWORK.Sin_w_t < 0)) {
          if (fabs(RealseCheck_DW.SmoothSignalGenerator_RWORK.Amp *
                   RealseCheck_DW.SmoothSignalGenerator_RWORK.Sin_w_t) <
              RealseCheck_P.SmoothSignalGenerator_Amplitude) {
            x = asin(RealseCheck_DW.SmoothSignalGenerator_RWORK.Amp *
                     RealseCheck_DW.SmoothSignalGenerator_RWORK.Sin_w_t /
                     RealseCheck_P.SmoothSignalGenerator_Amplitude);
            RealseCheck_DW.SmoothSignalGenerator_RWORK.Sin_w_dt = sin(w * 0.002);
            RealseCheck_DW.SmoothSignalGenerator_RWORK.Cos_w_dt = cos(w * 0.002);
            RealseCheck_DW.SmoothSignalGenerator_RWORK.Sin_w_t = sin(x);

            /*
               There are always two solutions for the phase. Choose the solution
               that matches the slope as well as the amplitude.
             */
            if ((cos(x) < 0) !=
                (RealseCheck_DW.SmoothSignalGenerator_RWORK.Cos_w_t < 0)) {
              RealseCheck_DW.SmoothSignalGenerator_RWORK.Cos_w_t = -cos(x);
            } else {
              RealseCheck_DW.SmoothSignalGenerator_RWORK.Cos_w_t = cos(x);
            }
          } else {
            /* really low amplitudes where sawtooth wave goes further in one time step after crossing zero than the new amplitude */
            x = w * 0.002;
            RealseCheck_DW.SmoothSignalGenerator_RWORK.Sin_w_t = 0;

            /* Make sure cosine output is also continuous */
            if (RealseCheck_DW.SmoothSignalGenerator_RWORK.Cos_w_t < 0) {
              RealseCheck_DW.SmoothSignalGenerator_RWORK.Cos_w_t = -1;
            } else {
              RealseCheck_DW.SmoothSignalGenerator_RWORK.Cos_w_t = +1;
            }

            RealseCheck_DW.SmoothSignalGenerator_RWORK.Sin_w_dt = sin(x);
            RealseCheck_DW.SmoothSignalGenerator_RWORK.Cos_w_dt = cos(x);
          }

          RealseCheck_DW.SmoothSignalGenerator_RWORK.Amp =
            RealseCheck_P.SmoothSignalGenerator_Amplitude;
          RealseCheck_DW.SmoothSignalGenerator_RWORK.W = w;
        }
      }
    }

    /* Bias: '<S2>/Bias' */
    rtb_Bias += RealseCheck_P.Bias_Bias;

    /* S-Function (hil_write_block): '<S2>/HIL Write' incorporates:
     *  Constant: '<Root>/Constant1'
     *  Constant: '<S1>/Constant'
     */

    /* S-Function Block: RealseCheck/Hardware Plant P(s)/HIL Write (hil_write_block) */
    {
      t_error result;
      RealseCheck_DW.HILWrite_OtherBuffer[0] = RealseCheck_B.MAIN[0];
      RealseCheck_DW.HILWrite_OtherBuffer[1] = RealseCheck_B.MAIN[1];
      RealseCheck_DW.HILWrite_OtherBuffer[2] = RealseCheck_B.MAIN[2];
      RealseCheck_DW.HILWrite_OtherBuffer[3] = RealseCheck_B.MAIN[3];
      RealseCheck_DW.HILWrite_OtherBuffer[4] = RealseCheck_B.gripposition;
      RealseCheck_DW.HILWrite_OtherBuffer[5] = RealseCheck_P.Constant1_Value[0];
      RealseCheck_DW.HILWrite_OtherBuffer[6] = RealseCheck_P.Constant1_Value[1];
      RealseCheck_DW.HILWrite_OtherBuffer[7] = RealseCheck_P.Constant1_Value[2];
      RealseCheck_DW.HILWrite_OtherBuffer[8] = RealseCheck_P.Constant1_Value[3];
      RealseCheck_DW.HILWrite_OtherBuffer[9] =
        RealseCheck_P.ColorConstant_color[0];
      RealseCheck_DW.HILWrite_OtherBuffer[10] =
        RealseCheck_P.ColorConstant_color[1];
      RealseCheck_DW.HILWrite_OtherBuffer[11] =
        RealseCheck_P.ColorConstant_color[2];
      RealseCheck_DW.HILWrite_OtherBuffer[12] = rtb_Bias;
      result = hil_write(RealseCheck_DW.HILInitializePositionMode_Card,
                         NULL, 0U,
                         NULL, 0U,
                         NULL, 0U,
                         RealseCheck_P.HILWrite_other_channels, 13U,
                         NULL,
                         NULL,
                         NULL,
                         &RealseCheck_DW.HILWrite_OtherBuffer[0]
                         );
      if (result < 0) {
        msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
          (_rt_error_message));
        rtmSetErrorStatus(RealseCheck_M, _rt_error_message);
      }
    }

    /* Constant: '<S7>/x0' */
    RealseCheck_B.x0 = RealseCheck_P.x0_Value;
  }

  /* Integrator: '<S7>/Integrator1' */
  if (RealseCheck_DW.Integrator1_DWORK1) {
    RealseCheck_X.Integrator1_CSTATE = RealseCheck_B.x0;
  }

  /* Integrator: '<S7>/Integrator1' */
  RealseCheck_B.Integrator1 = RealseCheck_X.Integrator1_CSTATE;
  if (tmp) {
    /* Constant: '<S6>/Soft-Grip Current (A)' */
    RealseCheck_B.goalcurrent = RealseCheck_P.SoftGripCurrentA_Value;
  }

  /* Product: '<S7>/Product' incorporates:
   *  Constant: '<S7>/Constant'
   *  Constant: '<S7>/wn'
   *  Constant: '<S7>/zt'
   *  Integrator: '<S7>/Integrator2'
   *  Product: '<S7>/Product2'
   *  Sum: '<S7>/Sum'
   *  Sum: '<S7>/Sum1'
   */
  RealseCheck_B.Product = ((RealseCheck_B.grippercurrent -
    RealseCheck_B.Integrator1) - RealseCheck_X.Integrator2_CSTATE *
    RealseCheck_P.Constant_Value_i *
    RealseCheck_P.undOrder25HzfilterbasedonFFT__a) *
    RealseCheck_P.undOrder25HzfilterbasedonFFT_in;

  /* Product: '<S7>/Product1' incorporates:
   *  Constant: '<S7>/wn'
   *  Integrator: '<S7>/Integrator2'
   */
  RealseCheck_B.Product1 = RealseCheck_P.undOrder25HzfilterbasedonFFT_in *
    RealseCheck_X.Integrator2_CSTATE;

  /* Gain: '<S6>/Gain2' incorporates:
   *  Sum: '<S6>/Subtract'
   */
  RealseCheck_B.Gain2 = (RealseCheck_B.goalcurrent - RealseCheck_B.Integrator1) *
    RealseCheck_P.Gain2_Gain;
}

/* Model update function */
void RealseCheck_update(void)
{
  /* Update for Integrator: '<S7>/Integrator1' */
  RealseCheck_DW.Integrator1_DWORK1 = false;
  if (rtmIsMajorTimeStep(RealseCheck_M)) {
    rt_ertODEUpdateContinuousStates(&RealseCheck_M->solverInfo);
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
  if (!(++RealseCheck_M->Timing.clockTick0)) {
    ++RealseCheck_M->Timing.clockTickH0;
  }

  RealseCheck_M->Timing.t[0] = rtsiGetSolverStopTime(&RealseCheck_M->solverInfo);

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
    if (!(++RealseCheck_M->Timing.clockTick1)) {
      ++RealseCheck_M->Timing.clockTickH1;
    }

    RealseCheck_M->Timing.t[1] = RealseCheck_M->Timing.clockTick1 *
      RealseCheck_M->Timing.stepSize1 + RealseCheck_M->Timing.clockTickH1 *
      RealseCheck_M->Timing.stepSize1 * 4294967296.0;
  }
}

/* Derivatives for root system: '<Root>' */
void RealseCheck_derivatives(void)
{
  XDot_RealseCheck_T *_rtXdot;
  boolean_T lsat;
  boolean_T usat;
  _rtXdot = ((XDot_RealseCheck_T *) RealseCheck_M->derivs);

  /* Derivatives for Integrator: '<S6>/Integrator' */
  lsat = (RealseCheck_X.Integrator_CSTATE <= RealseCheck_P.Integrator_LowerSat);
  usat = (RealseCheck_X.Integrator_CSTATE >= RealseCheck_P.Integrator_UpperSat);
  if ((!lsat && !usat) || (lsat && (RealseCheck_B.Gain2 > 0.0)) || (usat &&
       (RealseCheck_B.Gain2 < 0.0))) {
    _rtXdot->Integrator_CSTATE = RealseCheck_B.Gain2;
  } else {
    /* in saturation */
    _rtXdot->Integrator_CSTATE = 0.0;
  }

  /* End of Derivatives for Integrator: '<S6>/Integrator' */

  /* Derivatives for Integrator: '<S7>/Integrator1' */
  _rtXdot->Integrator1_CSTATE = RealseCheck_B.Product1;

  /* Derivatives for Integrator: '<S7>/Integrator2' */
  _rtXdot->Integrator2_CSTATE = RealseCheck_B.Product;
}

/* Model initialize function */
void RealseCheck_initialize(void)
{
  /* Start for S-Function (hil_initialize_block): '<Root>/HIL Initialize (Position Mode)' */

  /* S-Function Block: RealseCheck/HIL Initialize (Position Mode) (hil_initialize_block) */
  {
    t_int result;
    t_boolean is_switching;
    result = hil_open("qarm_usb", "0",
                      &RealseCheck_DW.HILInitializePositionMode_Card);
    if (result < 0) {
      msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
        (_rt_error_message));
      rtmSetErrorStatus(RealseCheck_M, _rt_error_message);
      return;
    }

    is_switching = false;
    result = hil_set_card_specific_options
      (RealseCheck_DW.HILInitializePositionMode_Card,
       "j0_mode=0;j1_mode=0;j2_mode=0;j3_mode=0;gripper_mode=0;j0_profile_config=0;j0_profile_velocity=1.6;j0_profile_acceleration=1.0472;j1_profile_config=0;j1_profile_velocity=1.6;j1_profile_acceleration=1.0472;j2_profile_config=0;j2_profile_velocity=1.6;j2_profile_acceleration=1.0472;j3_profile_config=0;j3_profile_velocity=1.6;j3_profile_acceleration=1.0472;",
       356);
    if (result < 0) {
      msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
        (_rt_error_message));
      rtmSetErrorStatus(RealseCheck_M, _rt_error_message);
      return;
    }

    result = hil_watchdog_clear(RealseCheck_DW.HILInitializePositionMode_Card);
    if (result < 0 && result != -QERR_HIL_WATCHDOG_CLEAR) {
      msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
        (_rt_error_message));
      rtmSetErrorStatus(RealseCheck_M, _rt_error_message);
      return;
    }

    if ((RealseCheck_P.HILInitializePositionMode_OOSta && !is_switching) ||
        (RealseCheck_P.HILInitializePositionMode_OOEnt && is_switching)) {
      {
        int_T i1;
        const real_T *p_HILInitializePositionMode_OOIni =
          RealseCheck_P.HILInitializePositionMode_OOIni;
        real_T *dw_OOValues = &RealseCheck_DW.HILInitializePositionMode_OOVal[0];
        for (i1=0; i1 < 11; i1++) {
          dw_OOValues[i1] = (p_HILInitializePositionMode_OOIni[i1]);
        }
      }

      RealseCheck_DW.HILInitializePositionMode_OOVal[11] =
        (RealseCheck_P.HILInitializePositionMode_OOIni[11]);
      RealseCheck_DW.HILInitializePositionMode_OOVal[12] =
        (RealseCheck_P.HILInitializePositionMode_OOIni[11]);
      result = hil_write_other(RealseCheck_DW.HILInitializePositionMode_Card,
        RealseCheck_P.HILInitializePositionMode_OOCha, 13U,
        &RealseCheck_DW.HILInitializePositionMode_OOVal[0]);
      if (result < 0) {
        msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
          (_rt_error_message));
        rtmSetErrorStatus(RealseCheck_M, _rt_error_message);
        return;
      }
    }

    if (RealseCheck_P.HILInitializePositionMode_OORes) {
      {
        int_T i1;
        const real_T *p_HILInitializePositionMode_OOWat =
          RealseCheck_P.HILInitializePositionMode_OOWat;
        real_T *dw_OOValues = &RealseCheck_DW.HILInitializePositionMode_OOVal[0];
        for (i1=0; i1 < 11; i1++) {
          dw_OOValues[i1] = (p_HILInitializePositionMode_OOWat[i1]);
        }
      }

      RealseCheck_DW.HILInitializePositionMode_OOVal[11] =
        (RealseCheck_P.HILInitializePositionMode_OOWat[11]);
      RealseCheck_DW.HILInitializePositionMode_OOVal[12] =
        (RealseCheck_P.HILInitializePositionMode_OOWat[11]);
      result = hil_watchdog_set_other_expiration_state
        (RealseCheck_DW.HILInitializePositionMode_Card,
         RealseCheck_P.HILInitializePositionMode_OOCha, 13U,
         &RealseCheck_DW.HILInitializePositionMode_OOVal[0]);
      if (result < 0) {
        msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
          (_rt_error_message));
        rtmSetErrorStatus(RealseCheck_M, _rt_error_message);
        return;
      }
    }
  }

  /* Start for S-Function (hil_read_timebase_block): '<S2>/HIL Read Timebase1' */

  /* S-Function Block: RealseCheck/Hardware Plant P(s)/HIL Read Timebase1 (hil_read_timebase_block) */
  {
    t_error result;
    result = hil_task_create_reader
      (RealseCheck_DW.HILInitializePositionMode_Card,
       RealseCheck_P.HILReadTimebase1_SamplesInBuffe,
       RealseCheck_P.HILReadTimebase1_AnalogChannels, 5U,
       NULL, 0U,
       NULL, 0U,
       RealseCheck_P.HILReadTimebase1_OtherChannels, 20U,
       &RealseCheck_DW.HILReadTimebase1_Task);
    if (result >= 0) {
      result = hil_task_set_buffer_overflow_mode
        (RealseCheck_DW.HILReadTimebase1_Task, (t_buffer_overflow_mode)
         (RealseCheck_P.HILReadTimebase1_OverflowMode - 1));
    }

    if (result < 0) {
      msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
        (_rt_error_message));
      rtmSetErrorStatus(RealseCheck_M, _rt_error_message);
    }
  }

  /* Start for S-Function (sample_time_block): '<Root>/Sample Time' */

  /* S-Function Block: RealseCheck/Sample Time (sample_time_block) */
  {
    t_error result;
    result = timeout_get_high_resolution_time
      (&RealseCheck_DW.SampleTime_PreviousTime);
    if (result < 0) {
      msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
        (_rt_error_message));
      rtmSetErrorStatus(RealseCheck_M, _rt_error_message);
      return;
    }
  }

  /* Start for S-Function (smooth_signal_generator_block): '<Root>/Base' */

  /* S-Function Block: RealseCheck/Base (smooth_signal_generator_block) */
  {
    real_T T = 1.0 / RealseCheck_P.Base_Frequency;
    RealseCheck_DW.Base_RWORK.Amp = RealseCheck_P.Base_Amplitude;
    RealseCheck_DW.Base_RWORK.W = TWO_PI * RealseCheck_P.Base_Frequency;
    RealseCheck_DW.Base_RWORK.T = fmod(RealseCheck_P.Base_InitialPhase, TWO_PI) *
      T / TWO_PI;
    if (RealseCheck_DW.Base_RWORK.T < 0) {
      RealseCheck_DW.Base_RWORK.T += T;
    }

    if (RealseCheck_DW.Base_RWORK.T < 0.5 * T) {
      RealseCheck_DW.Base_RWORK.Y = RealseCheck_P.Base_Amplitude;
    } else {
      RealseCheck_DW.Base_RWORK.Y = -RealseCheck_P.Base_Amplitude;
    }
  }

  /* Start for S-Function (smooth_signal_generator_block): '<Root>/Shoulder' */

  /* S-Function Block: RealseCheck/Shoulder (smooth_signal_generator_block) */
  {
    real_T T = 1.0 / RealseCheck_P.Shoulder_Frequency;
    RealseCheck_DW.Shoulder_RWORK.Amp = RealseCheck_P.Shoulder_Amplitude;
    RealseCheck_DW.Shoulder_RWORK.W = TWO_PI * RealseCheck_P.Shoulder_Frequency;
    RealseCheck_DW.Shoulder_RWORK.T = fmod(RealseCheck_P.Shoulder_InitialPhase,
      TWO_PI) * T / TWO_PI;
    if (RealseCheck_DW.Shoulder_RWORK.T < 0) {
      RealseCheck_DW.Shoulder_RWORK.T += T;
    }

    if (RealseCheck_DW.Shoulder_RWORK.T < 0.5 * T) {
      RealseCheck_DW.Shoulder_RWORK.Y = RealseCheck_P.Shoulder_Amplitude;
    } else {
      RealseCheck_DW.Shoulder_RWORK.Y = -RealseCheck_P.Shoulder_Amplitude;
    }
  }

  /* Start for S-Function (smooth_signal_generator_block): '<Root>/Elbow' */

  /* S-Function Block: RealseCheck/Elbow (smooth_signal_generator_block) */
  {
    real_T T = 1.0 / RealseCheck_P.Elbow_Frequency;
    RealseCheck_DW.Elbow_RWORK.Amp = RealseCheck_P.Elbow_Amplitude;
    RealseCheck_DW.Elbow_RWORK.W = TWO_PI * RealseCheck_P.Elbow_Frequency;
    RealseCheck_DW.Elbow_RWORK.T = fmod(RealseCheck_P.Elbow_InitialPhase, TWO_PI)
      * T / TWO_PI;
    if (RealseCheck_DW.Elbow_RWORK.T < 0) {
      RealseCheck_DW.Elbow_RWORK.T += T;
    }

    if (RealseCheck_DW.Elbow_RWORK.T < 0.5 * T) {
      RealseCheck_DW.Elbow_RWORK.Y = RealseCheck_P.Elbow_Amplitude;
    } else {
      RealseCheck_DW.Elbow_RWORK.Y = -RealseCheck_P.Elbow_Amplitude;
    }
  }

  /* Start for S-Function (smooth_signal_generator_block): '<Root>/Wrist' */

  /* S-Function Block: RealseCheck/Wrist (smooth_signal_generator_block) */
  {
    real_T T = 1.0 / RealseCheck_P.Wrist_Frequency;
    RealseCheck_DW.Wrist_RWORK.Amp = RealseCheck_P.Wrist_Amplitude;
    RealseCheck_DW.Wrist_RWORK.W = TWO_PI * RealseCheck_P.Wrist_Frequency;
    RealseCheck_DW.Wrist_RWORK.T = fmod(RealseCheck_P.Wrist_InitialPhase, TWO_PI)
      * T / TWO_PI;
    if (RealseCheck_DW.Wrist_RWORK.T < 0) {
      RealseCheck_DW.Wrist_RWORK.T += T;
    }

    if (RealseCheck_DW.Wrist_RWORK.T < 0.5 * T) {
      RealseCheck_DW.Wrist_RWORK.Y = RealseCheck_P.Wrist_Amplitude;
    } else {
      RealseCheck_DW.Wrist_RWORK.Y = -RealseCheck_P.Wrist_Amplitude;
    }
  }

  /* Start for S-Function (smooth_signal_generator_block): '<S2>/Smooth Signal Generator' */

  /* S-Function Block: RealseCheck/Hardware Plant P(s)/Smooth Signal Generator (smooth_signal_generator_block) */
  {
    real_T T = 1.0 / RealseCheck_P.SmoothSignalGenerator_Frequency;
    RealseCheck_DW.SmoothSignalGenerator_RWORK.Amp =
      RealseCheck_P.SmoothSignalGenerator_Amplitude;
    RealseCheck_DW.SmoothSignalGenerator_RWORK.W = TWO_PI *
      RealseCheck_P.SmoothSignalGenerator_Frequency;
    RealseCheck_DW.SmoothSignalGenerator_RWORK.Sin_w_dt = sin
      (RealseCheck_DW.SmoothSignalGenerator_RWORK.W * 0.002);
    RealseCheck_DW.SmoothSignalGenerator_RWORK.Cos_w_dt = cos
      (RealseCheck_DW.SmoothSignalGenerator_RWORK.W * 0.002);
    RealseCheck_DW.SmoothSignalGenerator_RWORK.Sin_w_t = sin
      (RealseCheck_P.SmoothSignalGenerator_InitialPh);
    RealseCheck_DW.SmoothSignalGenerator_RWORK.Cos_w_t = cos
      (RealseCheck_P.SmoothSignalGenerator_InitialPh);
  }

  /* Start for Constant: '<S7>/x0' */
  RealseCheck_B.x0 = RealseCheck_P.x0_Value;
  RealseCheck_PrevZCX.Integrator_Reset_ZCE = UNINITIALIZED_ZCSIG;

  /* InitializeConditions for Integrator: '<S6>/Integrator' */
  RealseCheck_X.Integrator_CSTATE = RealseCheck_P.Integrator_IC;

  /* InitializeConditions for Integrator: '<S7>/Integrator1' */
  if (rtmIsFirstInitCond(RealseCheck_M)) {
    RealseCheck_X.Integrator1_CSTATE = 0.0;
  }

  RealseCheck_DW.Integrator1_DWORK1 = true;

  /* End of InitializeConditions for Integrator: '<S7>/Integrator1' */

  /* InitializeConditions for Integrator: '<S7>/Integrator2' */
  RealseCheck_X.Integrator2_CSTATE = RealseCheck_P.Integrator2_IC;

  /* SystemInitialize for MATLAB Function: '<Root>/MATLAB Function1' */
  RealseCheck_DW.sfEvent = RealseCheck_CALL_EVENT;

  /* SystemInitialize for MATLAB Function: '<Root>/MATLAB Function' */
  RealseCheck_DW.sfEvent_p = RealseCheck_CALL_EVENT;

  /* set "at time zero" to false */
  if (rtmIsFirstInitCond(RealseCheck_M)) {
    rtmSetFirstInitCond(RealseCheck_M, 0);
  }
}

/* Model terminate function */
void RealseCheck_terminate(void)
{
  /* Terminate for S-Function (hil_initialize_block): '<Root>/HIL Initialize (Position Mode)' */

  /* S-Function Block: RealseCheck/HIL Initialize (Position Mode) (hil_initialize_block) */
  {
    t_boolean is_switching;
    t_int result;
    t_uint32 num_final_other_outputs = 0;
    hil_task_stop_all(RealseCheck_DW.HILInitializePositionMode_Card);
    hil_monitor_stop_all(RealseCheck_DW.HILInitializePositionMode_Card);
    is_switching = false;
    if ((RealseCheck_P.HILInitializePositionMode_OOTer && !is_switching) ||
        (RealseCheck_P.HILInitializePositionMode_OOExi && is_switching)) {
      RealseCheck_DW.HILInitializePositionMode_OOVal[0] =
        (RealseCheck_P.HILInitializePositionMode_OOFin[0]);
      RealseCheck_DW.HILInitializePositionMode_OOVal[1] =
        (RealseCheck_P.HILInitializePositionMode_OOFin[1]);
      RealseCheck_DW.HILInitializePositionMode_OOVal[2] =
        (RealseCheck_P.HILInitializePositionMode_OOFin[2]);

      {
        int_T i1;
        real_T *dw_OOValues = &RealseCheck_DW.HILInitializePositionMode_OOVal[3];
        for (i1=0; i1 < 10; i1++) {
          dw_OOValues[i1] = (RealseCheck_P.HILInitializePositionMode_OOFin[3]);
        }
      }

      num_final_other_outputs = 13U;
    } else {
      num_final_other_outputs = 0;
    }

    if (num_final_other_outputs > 0) {
      result = hil_write_other(RealseCheck_DW.HILInitializePositionMode_Card,
        RealseCheck_P.HILInitializePositionMode_OOCha, num_final_other_outputs,
        &RealseCheck_DW.HILInitializePositionMode_OOVal[0]);
      if (result < 0) {
        msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
          (_rt_error_message));
        rtmSetErrorStatus(RealseCheck_M, _rt_error_message);
      }
    }

    hil_task_delete_all(RealseCheck_DW.HILInitializePositionMode_Card);
    hil_monitor_delete_all(RealseCheck_DW.HILInitializePositionMode_Card);
    hil_close(RealseCheck_DW.HILInitializePositionMode_Card);
    RealseCheck_DW.HILInitializePositionMode_Card = NULL;
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
  RealseCheck_output();
  UNUSED_PARAMETER(tid);
}

void MdlUpdate(int_T tid)
{
  RealseCheck_update();
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
  RealseCheck_initialize();
}

void MdlTerminate(void)
{
  RealseCheck_terminate();
}

/* Registration function */
RT_MODEL_RealseCheck_T *RealseCheck(void)
{
  /* Registration code */

  /* initialize real-time model */
  (void) memset((void *)RealseCheck_M, 0,
                sizeof(RT_MODEL_RealseCheck_T));

  {
    /* Setup solver object */
    rtsiSetSimTimeStepPtr(&RealseCheck_M->solverInfo,
                          &RealseCheck_M->Timing.simTimeStep);
    rtsiSetTPtr(&RealseCheck_M->solverInfo, &rtmGetTPtr(RealseCheck_M));
    rtsiSetStepSizePtr(&RealseCheck_M->solverInfo,
                       &RealseCheck_M->Timing.stepSize0);
    rtsiSetdXPtr(&RealseCheck_M->solverInfo, &RealseCheck_M->derivs);
    rtsiSetContStatesPtr(&RealseCheck_M->solverInfo, (real_T **)
                         &RealseCheck_M->contStates);
    rtsiSetNumContStatesPtr(&RealseCheck_M->solverInfo,
      &RealseCheck_M->Sizes.numContStates);
    rtsiSetNumPeriodicContStatesPtr(&RealseCheck_M->solverInfo,
      &RealseCheck_M->Sizes.numPeriodicContStates);
    rtsiSetPeriodicContStateIndicesPtr(&RealseCheck_M->solverInfo,
      &RealseCheck_M->periodicContStateIndices);
    rtsiSetPeriodicContStateRangesPtr(&RealseCheck_M->solverInfo,
      &RealseCheck_M->periodicContStateRanges);
    rtsiSetContStateDisabledPtr(&RealseCheck_M->solverInfo, (boolean_T**)
      &RealseCheck_M->contStateDisabled);
    rtsiSetErrorStatusPtr(&RealseCheck_M->solverInfo, (&rtmGetErrorStatus
      (RealseCheck_M)));
    rtsiSetRTModelPtr(&RealseCheck_M->solverInfo, RealseCheck_M);
  }

  rtsiSetSimTimeStep(&RealseCheck_M->solverInfo, MAJOR_TIME_STEP);
  rtsiSetIsMinorTimeStepWithModeChange(&RealseCheck_M->solverInfo, false);
  rtsiSetIsContModeFrozen(&RealseCheck_M->solverInfo, false);
  RealseCheck_M->intgData.y = RealseCheck_M->odeY;
  RealseCheck_M->intgData.f[0] = RealseCheck_M->odeF[0];
  RealseCheck_M->intgData.f[1] = RealseCheck_M->odeF[1];
  RealseCheck_M->intgData.f[2] = RealseCheck_M->odeF[2];
  RealseCheck_M->intgData.f[3] = RealseCheck_M->odeF[3];
  RealseCheck_M->contStates = ((real_T *) &RealseCheck_X);
  RealseCheck_M->contStateDisabled = ((boolean_T *) &RealseCheck_XDis);
  RealseCheck_M->Timing.tStart = (0.0);
  rtsiSetSolverData(&RealseCheck_M->solverInfo, (void *)&RealseCheck_M->intgData);
  rtsiSetSolverName(&RealseCheck_M->solverInfo,"ode4");

  /* Initialize timing info */
  {
    int_T *mdlTsMap = RealseCheck_M->Timing.sampleTimeTaskIDArray;
    mdlTsMap[0] = 0;
    mdlTsMap[1] = 1;
    RealseCheck_M->Timing.sampleTimeTaskIDPtr = (&mdlTsMap[0]);
    RealseCheck_M->Timing.sampleTimes = (&RealseCheck_M->
      Timing.sampleTimesArray[0]);
    RealseCheck_M->Timing.offsetTimes = (&RealseCheck_M->
      Timing.offsetTimesArray[0]);

    /* task periods */
    RealseCheck_M->Timing.sampleTimes[0] = (0.0);
    RealseCheck_M->Timing.sampleTimes[1] = (0.002);

    /* task offsets */
    RealseCheck_M->Timing.offsetTimes[0] = (0.0);
    RealseCheck_M->Timing.offsetTimes[1] = (0.0);
  }

  rtmSetTPtr(RealseCheck_M, &RealseCheck_M->Timing.tArray[0]);

  {
    int_T *mdlSampleHits = RealseCheck_M->Timing.sampleHitArray;
    mdlSampleHits[0] = 1;
    mdlSampleHits[1] = 1;
    RealseCheck_M->Timing.sampleHits = (&mdlSampleHits[0]);
  }

  rtmSetTFinal(RealseCheck_M, -1);
  RealseCheck_M->Timing.stepSize0 = 0.002;
  RealseCheck_M->Timing.stepSize1 = 0.002;
  rtmSetFirstInitCond(RealseCheck_M, 1);

  /* External mode info */
  RealseCheck_M->Sizes.checksums[0] = (3474281895U);
  RealseCheck_M->Sizes.checksums[1] = (975685958U);
  RealseCheck_M->Sizes.checksums[2] = (817352766U);
  RealseCheck_M->Sizes.checksums[3] = (2741323858U);

  {
    static const sysRanDType rtAlwaysEnabled = SUBSYS_RAN_BC_ENABLE;
    static RTWExtModeInfo rt_ExtModeInfo;
    static const sysRanDType *systemRan[13];
    RealseCheck_M->extModeInfo = (&rt_ExtModeInfo);
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
    rteiSetModelMappingInfoPtr(RealseCheck_M->extModeInfo,
      &RealseCheck_M->SpecialInfo.mappingInfo);
    rteiSetChecksumsPtr(RealseCheck_M->extModeInfo,
                        RealseCheck_M->Sizes.checksums);
    rteiSetTPtr(RealseCheck_M->extModeInfo, rtmGetTPtr(RealseCheck_M));
  }

  RealseCheck_M->solverInfoPtr = (&RealseCheck_M->solverInfo);
  RealseCheck_M->Timing.stepSize = (0.002);
  rtsiSetFixedStepSize(&RealseCheck_M->solverInfo, 0.002);
  rtsiSetSolverMode(&RealseCheck_M->solverInfo, SOLVER_MODE_SINGLETASKING);

  /* block I/O */
  RealseCheck_M->blockIO = ((void *) &RealseCheck_B);
  (void) memset(((void *) &RealseCheck_B), 0,
                sizeof(B_RealseCheck_T));

  /* parameters */
  RealseCheck_M->defaultParam = ((real_T *)&RealseCheck_P);

  /* states (continuous) */
  {
    real_T *x = (real_T *) &RealseCheck_X;
    RealseCheck_M->contStates = (x);
    (void) memset((void *)&RealseCheck_X, 0,
                  sizeof(X_RealseCheck_T));
  }

  /* disabled states */
  {
    boolean_T *xdis = (boolean_T *) &RealseCheck_XDis;
    RealseCheck_M->contStateDisabled = (xdis);
    (void) memset((void *)&RealseCheck_XDis, 0,
                  sizeof(XDis_RealseCheck_T));
  }

  /* states (dwork) */
  RealseCheck_M->dwork = ((void *) &RealseCheck_DW);
  (void) memset((void *)&RealseCheck_DW, 0,
                sizeof(DW_RealseCheck_T));

  /* data type transition information */
  {
    static DataTypeTransInfo dtInfo;
    (void) memset((char_T *) &dtInfo, 0,
                  sizeof(dtInfo));
    RealseCheck_M->SpecialInfo.mappingInfo = (&dtInfo);
    dtInfo.numDataTypes = 22;
    dtInfo.dataTypeSizes = &rtDataTypeSizes[0];
    dtInfo.dataTypeNames = &rtDataTypeNames[0];

    /* Block I/O transition table */
    dtInfo.BTransTable = &rtBTransTable;

    /* Parameters transition table */
    dtInfo.PTransTable = &rtPTransTable;
  }

  /* Initialize Sizes */
  RealseCheck_M->Sizes.numContStates = (3);/* Number of continuous states */
  RealseCheck_M->Sizes.numPeriodicContStates = (0);
                                      /* Number of periodic continuous states */
  RealseCheck_M->Sizes.numY = (0);     /* Number of model outputs */
  RealseCheck_M->Sizes.numU = (0);     /* Number of model inputs */
  RealseCheck_M->Sizes.sysDirFeedThru = (0);/* The model is not direct feedthrough */
  RealseCheck_M->Sizes.numSampTimes = (2);/* Number of sample times */
  RealseCheck_M->Sizes.numBlocks = (71);/* Number of blocks */
  RealseCheck_M->Sizes.numBlockIO = (38);/* Number of block outputs */
  RealseCheck_M->Sizes.numBlockPrms = (202);/* Sum of parameter "widths" */
  return RealseCheck_M;
}

/*========================================================================*
 * End of Classic call interface                                          *
 *========================================================================*/
