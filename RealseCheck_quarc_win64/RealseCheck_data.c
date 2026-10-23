/*
 * RealseCheck_data.c
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

/* Block parameters (default storage) */
P_RealseCheck_T RealseCheck_P = {
  /* Mask Parameter: ColorConstant_color
   * Referenced by: '<S1>/Constant'
   */
  { 0.0, 1.0, 0.0 },

  /* Mask Parameter: undOrder25HzfilterbasedonFFT_in
   * Referenced by: '<S7>/wn'
   */
  157.07963267948966,

  /* Mask Parameter: undOrder25HzfilterbasedonFFT__a
   * Referenced by: '<S7>/zt'
   */
  1.0,

  /* Mask Parameter: HILWrite_other_channels
   * Referenced by: '<S2>/HIL Write'
   */
  { 1000U, 1001U, 1002U, 1003U, 1004U, 11000U, 11001U, 11002U, 11003U, 11005U,
    11006U, 11007U, 11008U },

  /* Expression: [0 0 0 0]
   * Referenced by: '<Root>/Default Cmd'
   */
  { 0.0, 0.0, 0.0, 0.0 },

  /* Expression: -pi/4
   * Referenced by: '<Root>/Constant4'
   */
  -0.78539816339744828,

  /* Expression: -pi/8
   * Referenced by: '<Root>/offset'
   */
  -0.39269908169872414,

  /* Expression: -pi/2
   * Referenced by: '<Root>/Constant6'
   */
  -1.5707963267948966,

  /* Expression: 0
   * Referenced by: '<Root>/Constant8'
   */
  0.0,

  /* Expression: 0
   * Referenced by: '<Root>/Constant2'
   */
  0.0,

  /* Expression: 1
   * Referenced by: '<Root>/CLOSE '
   */
  1.0,

  /* Expression: 0
   * Referenced by: '<Root>/ OPEN'
   */
  0.0,

  /* Expression: set_other_outputs_at_terminate
   * Referenced by: '<Root>/HIL Initialize (Position Mode)'
   */
  1.0,

  /* Expression: set_other_outputs_at_switch_out
   * Referenced by: '<Root>/HIL Initialize (Position Mode)'
   */
  0.0,

  /* Expression: set_other_outputs_at_start
   * Referenced by: '<Root>/HIL Initialize (Position Mode)'
   */
  0.0,

  /* Expression: set_other_outputs_at_switch_in
   * Referenced by: '<Root>/HIL Initialize (Position Mode)'
   */
  0.0,

  /* Expression: final_analog_outputs
   * Referenced by: '<Root>/HIL Initialize (Position Mode)'
   */
  0.0,

  /* Expression: final_other_outputs
   * Referenced by: '<Root>/HIL Initialize (Position Mode)'
   */
  { 1.0, 0.0, 0.0, 0.0 },

  /* Expression: analog_output_maximums
   * Referenced by: '<Root>/HIL Initialize (Position Mode)'
   */
  INFINITY,

  /* Expression: analog_output_minimums
   * Referenced by: '<Root>/HIL Initialize (Position Mode)'
   */
  -INFINITY,

  /* Expression: initial_analog_outputs
   * Referenced by: '<Root>/HIL Initialize (Position Mode)'
   */
  0.0,

  /* Expression: initial_other_outputs
   * Referenced by: '<Root>/HIL Initialize (Position Mode)'
   */
  { 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 1.0, 1.0, 1.0 },

  /* Expression: watchdog_other_outputs
   * Referenced by: '<Root>/HIL Initialize (Position Mode)'
   */
  { 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0 },

  /* Expression: initial_phase
   * Referenced by: '<Root>/Base'
   */
  0.0,

  /* Expression: i_amplitude
   * Referenced by: '<Root>/Base'
   */
  0.39269908169872414,

  /* Expression: i_frequency
   * Referenced by: '<Root>/Base'
   */
  0.125,

  /* Expression: initial_phase
   * Referenced by: '<Root>/Shoulder'
   */
  0.0,

  /* Expression: i_amplitude
   * Referenced by: '<Root>/Shoulder'
   */
  1.0471975511965976,

  /* Expression: i_frequency
   * Referenced by: '<Root>/Shoulder'
   */
  0.25,

  /* Expression: initial_phase
   * Referenced by: '<Root>/Elbow'
   */
  3.1415926535897931,

  /* Expression: i_amplitude
   * Referenced by: '<Root>/Elbow'
   */
  0.78539816339744828,

  /* Expression: i_frequency
   * Referenced by: '<Root>/Elbow'
   */
  0.25,

  /* Expression: initial_phase
   * Referenced by: '<Root>/Wrist'
   */
  0.0,

  /* Expression: i_amplitude
   * Referenced by: '<Root>/Wrist'
   */
  0.39269908169872414,

  /* Expression: i_frequency
   * Referenced by: '<Root>/Wrist'
   */
  0.125,

  /* Expression: [0.4500 0 0.4500]
   * Referenced by: '<Root>/Constant'
   */
  { 0.45, 0.0, 0.45 },

  /* Expression: [0 0 0]
   * Referenced by: '<Root>/Constant12'
   */
  { 0.0, 0.0, 0.0 },

  /* Expression: [0.1 0.1 0.1]
   * Referenced by: '<Root>/Constant5'
   */
  { 0.1, 0.1, 0.1 },

  /* Expression: [0.2 0.2 0.2]
   * Referenced by: '<Root>/Constant11'
   */
  { 0.2, 0.2, 0.2 },

  /* Expression: [0.1 0.1 0.1]
   * Referenced by: '<Root>/Constant13'
   */
  { 0.1, 0.1, 0.1 },

  /* Expression: [0 0 0 0]
   * Referenced by: '<Root>/Constant1'
   */
  { 0.0, 0.0, 0.0, 0.0 },

  /* Expression: 0.1
   * Referenced by: '<S6>/Integrator'
   */
  0.1,

  /* Expression: 0.9
   * Referenced by: '<S6>/Integrator'
   */
  0.9,

  /* Expression: 0.1
   * Referenced by: '<S6>/Integrator'
   */
  0.1,

  /* Expression: 0.1
   * Referenced by: '<S6>/open position'
   */
  0.1,

  /* Expression: 0
   * Referenced by: '<S6>/Switch'
   */
  0.0,

  /* Expression: initial_phase
   * Referenced by: '<S2>/Smooth Signal Generator'
   */
  0.0,

  /* Expression: i_amplitude
   * Referenced by: '<S2>/Smooth Signal Generator'
   */
  0.5,

  /* Expression: i_frequency
   * Referenced by: '<S2>/Smooth Signal Generator'
   */
  0.5,

  /* Expression: 0.5
   * Referenced by: '<S2>/Bias'
   */
  0.5,

  /* Expression: input_init
   * Referenced by: '<S7>/x0'
   */
  0.0,

  /* Expression: 0.25
   * Referenced by: '<S6>/Soft-Grip Current (A)'
   */
  0.25,

  /* Expression: 2
   * Referenced by: '<S7>/Constant'
   */
  2.0,

  /* Expression: 0
   * Referenced by: '<S7>/Integrator2'
   */
  0.0,

  /* Expression: 10
   * Referenced by: '<S6>/Gain2'
   */
  10.0,

  /* Computed Parameter: HILInitializePositionMode_CKCha
   * Referenced by: '<Root>/HIL Initialize (Position Mode)'
   */
  0,

  /* Computed Parameter: HILInitializePositionMode_DOWat
   * Referenced by: '<Root>/HIL Initialize (Position Mode)'
   */
  0,

  /* Computed Parameter: HILReadTimebase1_Clock
   * Referenced by: '<S2>/HIL Read Timebase1'
   */
  0,

  /* Computed Parameter: HILInitializePositionMode_AICha
   * Referenced by: '<Root>/HIL Initialize (Position Mode)'
   */
  { 5U, 6U, 7U, 8U, 9U },

  /* Computed Parameter: HILInitializePositionMode_OOCha
   * Referenced by: '<Root>/HIL Initialize (Position Mode)'
   */
  { 11005U, 11006U, 11007U, 11008U, 1000U, 1001U, 1002U, 1003U, 1004U, 11000U,
    11001U, 11002U, 11003U },

  /* Computed Parameter: HILReadTimebase1_SamplesInBuffe
   * Referenced by: '<S2>/HIL Read Timebase1'
   */
  500U,

  /* Computed Parameter: HILReadTimebase1_AnalogChannels
   * Referenced by: '<S2>/HIL Read Timebase1'
   */
  { 5U, 6U, 7U, 8U, 9U },

  /* Computed Parameter: HILReadTimebase1_OtherChannels
   * Referenced by: '<S2>/HIL Read Timebase1'
   */
  { 1000U, 1001U, 1002U, 1003U, 1004U, 3000U, 3001U, 3002U, 3003U, 3004U, 10000U,
    10001U, 10002U, 10003U, 10004U, 11000U, 11001U, 11002U, 11003U, 11004U },

  /* Computed Parameter: HILInitializePositionMode_Activ
   * Referenced by: '<Root>/HIL Initialize (Position Mode)'
   */
  true,

  /* Computed Parameter: HILInitializePositionMode_AOTer
   * Referenced by: '<Root>/HIL Initialize (Position Mode)'
   */
  false,

  /* Computed Parameter: HILInitializePositionMode_AOExi
   * Referenced by: '<Root>/HIL Initialize (Position Mode)'
   */
  false,

  /* Computed Parameter: HILInitializePositionMode_DOTer
   * Referenced by: '<Root>/HIL Initialize (Position Mode)'
   */
  false,

  /* Computed Parameter: HILInitializePositionMode_DOExi
   * Referenced by: '<Root>/HIL Initialize (Position Mode)'
   */
  false,

  /* Computed Parameter: HILInitializePositionMode_POTer
   * Referenced by: '<Root>/HIL Initialize (Position Mode)'
   */
  false,

  /* Computed Parameter: HILInitializePositionMode_POExi
   * Referenced by: '<Root>/HIL Initialize (Position Mode)'
   */
  false,

  /* Computed Parameter: HILInitializePositionMode_CKPSt
   * Referenced by: '<Root>/HIL Initialize (Position Mode)'
   */
  false,

  /* Computed Parameter: HILInitializePositionMode_CKPEn
   * Referenced by: '<Root>/HIL Initialize (Position Mode)'
   */
  false,

  /* Computed Parameter: HILInitializePositionMode_CKSta
   * Referenced by: '<Root>/HIL Initialize (Position Mode)'
   */
  false,

  /* Computed Parameter: HILInitializePositionMode_CKEnt
   * Referenced by: '<Root>/HIL Initialize (Position Mode)'
   */
  false,

  /* Computed Parameter: HILInitializePositionMode_AIPSt
   * Referenced by: '<Root>/HIL Initialize (Position Mode)'
   */
  false,

  /* Computed Parameter: HILInitializePositionMode_AIPEn
   * Referenced by: '<Root>/HIL Initialize (Position Mode)'
   */
  false,

  /* Computed Parameter: HILInitializePositionMode_AOPSt
   * Referenced by: '<Root>/HIL Initialize (Position Mode)'
   */
  false,

  /* Computed Parameter: HILInitializePositionMode_AOPEn
   * Referenced by: '<Root>/HIL Initialize (Position Mode)'
   */
  false,

  /* Computed Parameter: HILInitializePositionMode_AOSta
   * Referenced by: '<Root>/HIL Initialize (Position Mode)'
   */
  false,

  /* Computed Parameter: HILInitializePositionMode_AOEnt
   * Referenced by: '<Root>/HIL Initialize (Position Mode)'
   */
  false,

  /* Computed Parameter: HILInitializePositionMode_AORes
   * Referenced by: '<Root>/HIL Initialize (Position Mode)'
   */
  false,

  /* Computed Parameter: HILInitializePositionMode_DOPSt
   * Referenced by: '<Root>/HIL Initialize (Position Mode)'
   */
  false,

  /* Computed Parameter: HILInitializePositionMode_DOPEn
   * Referenced by: '<Root>/HIL Initialize (Position Mode)'
   */
  false,

  /* Computed Parameter: HILInitializePositionMode_DOSta
   * Referenced by: '<Root>/HIL Initialize (Position Mode)'
   */
  false,

  /* Computed Parameter: HILInitializePositionMode_DOEnt
   * Referenced by: '<Root>/HIL Initialize (Position Mode)'
   */
  false,

  /* Computed Parameter: HILInitializePositionMode_DORes
   * Referenced by: '<Root>/HIL Initialize (Position Mode)'
   */
  false,

  /* Computed Parameter: HILInitializePositionMode_EIPSt
   * Referenced by: '<Root>/HIL Initialize (Position Mode)'
   */
  false,

  /* Computed Parameter: HILInitializePositionMode_EIPEn
   * Referenced by: '<Root>/HIL Initialize (Position Mode)'
   */
  false,

  /* Computed Parameter: HILInitializePositionMode_EISta
   * Referenced by: '<Root>/HIL Initialize (Position Mode)'
   */
  false,

  /* Computed Parameter: HILInitializePositionMode_EIEnt
   * Referenced by: '<Root>/HIL Initialize (Position Mode)'
   */
  false,

  /* Computed Parameter: HILInitializePositionMode_POPSt
   * Referenced by: '<Root>/HIL Initialize (Position Mode)'
   */
  false,

  /* Computed Parameter: HILInitializePositionMode_POPEn
   * Referenced by: '<Root>/HIL Initialize (Position Mode)'
   */
  false,

  /* Computed Parameter: HILInitializePositionMode_POSta
   * Referenced by: '<Root>/HIL Initialize (Position Mode)'
   */
  false,

  /* Computed Parameter: HILInitializePositionMode_POEnt
   * Referenced by: '<Root>/HIL Initialize (Position Mode)'
   */
  false,

  /* Computed Parameter: HILInitializePositionMode_PORes
   * Referenced by: '<Root>/HIL Initialize (Position Mode)'
   */
  false,

  /* Computed Parameter: HILInitializePositionMode_OORes
   * Referenced by: '<Root>/HIL Initialize (Position Mode)'
   */
  false,

  /* Computed Parameter: HILInitializePositionMode_DOFin
   * Referenced by: '<Root>/HIL Initialize (Position Mode)'
   */
  false,

  /* Computed Parameter: HILInitializePositionMode_DOIni
   * Referenced by: '<Root>/HIL Initialize (Position Mode)'
   */
  false,

  /* Computed Parameter: HILReadTimebase1_Active
   * Referenced by: '<S2>/HIL Read Timebase1'
   */
  true,

  /* Computed Parameter: HILWrite_Active
   * Referenced by: '<S2>/HIL Write'
   */
  true,

  /* Computed Parameter: ManualSwitch_CurrentSetting
   * Referenced by: '<Root>/Manual Switch'
   */
  0U,

  /* Computed Parameter: ManualSwitch1_CurrentSetting
   * Referenced by: '<Root>/Manual Switch1'
   */
  1U,

  /* Computed Parameter: ManualSwitch2_CurrentSetting
   * Referenced by: '<Root>/Manual Switch2'
   */
  1U,

  /* Computed Parameter: ManualSwitch3_CurrentSetting
   * Referenced by: '<Root>/Manual Switch3'
   */
  0U,

  /* Computed Parameter: ManualSwitch4_CurrentSetting
   * Referenced by: '<Root>/Manual Switch4'
   */
  0U,

  /* Computed Parameter: HILReadTimebase1_OverflowMode
   * Referenced by: '<S2>/HIL Read Timebase1'
   */
  1U,

  /* Computed Parameter: MAIN_CurrentSetting
   * Referenced by: '<Root>/MAIN'
   */
  1U,

  /* Computed Parameter: ManualSwitch5_CurrentSetting
   * Referenced by: '<Root>/Manual Switch5'
   */
  0U
};
