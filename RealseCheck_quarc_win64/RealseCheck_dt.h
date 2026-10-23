/*
 * RealseCheck_dt.h
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
  { (char_T *)(&RealseCheck_B.HILReadTimebase1_o1), 0, 0, 41 }
  ,

  { (char_T *)(&RealseCheck_DW.SampleTime_PreviousTime), 15, 0, 1 },

  { (char_T *)(&RealseCheck_DW.HILInitializePositionMode_OOVal[0]), 0, 0, 51 },

  { (char_T *)(&RealseCheck_DW.HILInitializePositionMode_Card), 16, 0, 1 },

  { (char_T *)(&RealseCheck_DW.HILReadTimebase1_Task), 17, 0, 1 },

  { (char_T *)(&RealseCheck_DW.Base_RWORK.Amp), 0, 0, 5 },

  { (char_T *)(&RealseCheck_DW.Scope1_PWORK.LoggedData), 11, 0, 14 },

  { (char_T *)(&RealseCheck_DW.HILInitializePositionMode_Clock), 6, 0, 3 },

  { (char_T *)(&RealseCheck_DW.Integrator1_DWORK1), 8, 0, 3 }
};

/* data type transition table for block I/O structure */
static DataTypeTransitionTable rtBTransTable = {
  9U,
  rtBTransitions
};

/* data type transitions for Parameters structure */
static DataTypeTransition rtPTransitions[] = {
  { (char_T *)(&RealseCheck_P.ColorConstant_color[0]), 0, 0, 5 },

  { (char_T *)(&RealseCheck_P.HILWrite_other_channels[0]), 7, 0, 13 },

  { (char_T *)(&RealseCheck_P.DefaultCmd_Value[0]), 0, 0, 92 },

  { (char_T *)(&RealseCheck_P.HILInitializePositionMode_CKCha), 6, 0, 3 },

  { (char_T *)(&RealseCheck_P.HILInitializePositionMode_AICha[0]), 7, 0, 44 },

  { (char_T *)(&RealseCheck_P.HILInitializePositionMode_Activ), 8, 0, 37 },

  { (char_T *)(&RealseCheck_P.ManualSwitch_CurrentSetting), 3, 0, 8 }
};

/* data type transition table for Parameters structure */
static DataTypeTransitionTable rtPTransTable = {
  7U,
  rtPTransitions
};

/* [EOF] RealseCheck_dt.h */
