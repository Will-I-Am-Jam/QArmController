/*
 * RealseCheckPositionController_dt.h
 *
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * Code generation for model "RealseCheckPositionController".
 *
 * Model version              : 13.36
 * Simulink Coder version : 26.1 (R2026a) 20-Nov-2025
 * C source code generated on : Fri Oct 16 15:18:56 2026
 *
 * Target selection: quarc_win64.tlc
 * Note: GRT includes extra infrastructure and instrumentation for prototyping
 * Embedded hardware selection: Intel->x86-64 (Windows64)
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#include "ext_types.h"

/* data type size table */
static uint_T rtDataTypeSizes[] = {
  sizeof(real_T),
  sizeof(real32_T),
  sizeof(int8_T),
  sizeof(uint8_T),
  sizeof(int16_T),
  sizeof(uint16_T),
  sizeof(int32_T),
  sizeof(uint32_T),
  sizeof(boolean_T),
  sizeof(fcn_call_T),
  sizeof(int_T),
  sizeof(pointer_T),
  sizeof(action_T),
  2*sizeof(uint32_T),
  sizeof(int32_T),
  sizeof(t_timeout),
  sizeof(t_card),
  sizeof(t_task),
  sizeof(uint_T),
  sizeof(char_T),
  sizeof(uchar_T),
  sizeof(time_T)
};

/* data type name table */
static const char_T * rtDataTypeNames[] = {
  "real_T",
  "real32_T",
  "int8_T",
  "uint8_T",
  "int16_T",
  "uint16_T",
  "int32_T",
  "uint32_T",
  "boolean_T",
  "fcn_call_T",
  "int_T",
  "pointer_T",
  "action_T",
  "timer_uint32_pair_T",
  "physical_connection",
  "t_timeout",
  "t_card",
  "t_task",
  "uint_T",
  "char_T",
  "uchar_T",
  "time_T"
};

/* data type transitions for block I/O structure */
static DataTypeTransition rtBTransitions[] = {
  { (char_T *)(&RealseCheckPositionController_B.HILReadTimebase1_o1), 0, 0, 52 }
  ,

  { (char_T *)(&RealseCheckPositionControlle_DW.SampleTime_PreviousTime), 15, 0,
    1 },

  { (char_T *)(&RealseCheckPositionControlle_DW.HILInitializePositionMode_OOVal
               [0]), 0, 0, 60 },

  { (char_T *)(&RealseCheckPositionControlle_DW.HILInitializePositionMode_Card),
    16, 0, 1 },

  { (char_T *)(&RealseCheckPositionControlle_DW.HILReadTimebase1_Task), 17, 0, 1
  },

  { (char_T *)(&RealseCheckPositionControlle_DW.Base_RWORK.Amp), 0, 0, 5 },

  { (char_T *)(&RealseCheckPositionControlle_DW.Scope1_PWORK.LoggedData), 11, 0,
    17 },

  { (char_T *)(&RealseCheckPositionControlle_DW.HILInitializePositionMode_Clock),
    6, 0, 4 },

  { (char_T *)(&RealseCheckPositionControlle_DW.Integrator1_DWORK1), 8, 0, 7 }
};

/* data type transition table for block I/O structure */
static DataTypeTransitionTable rtBTransTable = {
  9U,
  rtBTransitions
};

/* data type transitions for Parameters structure */
static DataTypeTransition rtPTransitions[] = {
  { (char_T *)(&RealseCheckPositionController_P.Ramp_InitialOutput), 0, 0, 8 },

  { (char_T *)(&RealseCheckPositionController_P.HILWrite_other_channels[0]), 7,
    0, 13 },

  { (char_T *)(&RealseCheckPositionController_P.Constant4_Value), 0, 0, 98 },

  { (char_T *)(&RealseCheckPositionController_P.HILInitializePositionMode_CKCha),
    6, 0, 3 },

  { (char_T *)(&RealseCheckPositionController_P.HILInitializePositionMode_AICha
               [0]), 7, 0, 44 },

  { (char_T *)(&RealseCheckPositionController_P.HILInitializePositionMode_Activ),
    8, 0, 37 },

  { (char_T *)(&RealseCheckPositionController_P.ManualSwitch2_CurrentSetting), 3,
    0, 9 }
};

/* data type transition table for Parameters structure */
static DataTypeTransitionTable rtPTransTable = {
  7U,
  rtPTransitions
};

/* [EOF] RealseCheckPositionController_dt.h */
