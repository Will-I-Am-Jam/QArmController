/*
 * TrajRunner_data.c
 *
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * Code generation for model "TrajRunner".
 *
 * Model version              : 13.46
 * Simulink Coder version : 26.1 (R2026a) 20-Nov-2025
 * C source code generated on : Thu Oct 22 21:01:32 2026
 *
 * Target selection: quarc_win64.tlc
 * Note: GRT includes extra infrastructure and instrumentation for prototyping
 * Embedded hardware selection: Intel->x86-64 (Windows64)
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#include "TrajRunner.h"

/* Block parameters (default storage) */
P_TrajRunner_T TrajRunner_P = {
  /* Mask Parameter: Ramp_InitialOutput
   * Referenced by: '<S7>/Constant1'
   */
  0.0,

  /* Mask Parameter: ColorConstant_color
   * Referenced by: '<S1>/Constant'
   */
  { 0.0, 1.0, 0.0 },

  /* Mask Parameter: undOrder25HzfilterbasedonFFT_in
   * Referenced by: '<S9>/wn'
   */
  157.07963267948966,

  /* Mask Parameter: undOrder25HzfilterbasedonFFT__a
   * Referenced by: '<S9>/zt'
   */
  1.0,

  /* Mask Parameter: Ramp_slope
   * Referenced by: '<S7>/Step'
   */
  0.26179938779914941,

  /* Mask Parameter: Ramp_start
   * Referenced by:
   *   '<S7>/Constant'
   *   '<S7>/Step'
   */
  0.0,

  /* Mask Parameter: HILWrite_other_channels
   * Referenced by: '<S2>/HIL Write'
   */
  { 1000U, 1001U, 1002U, 1003U, 1004U, 11000U, 11001U, 11002U, 11003U, 11005U,
    11006U, 11007U, 11008U },

  /* Expression: 0
   * Referenced by: '<Root>/Constant4'
   */
  0.0,

  /* Expression: 0
   * Referenced by: '<Root>/Constant8'
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

  /* Expression: 1
   * Referenced by: '<Root>/run'
   */
  1.0,

  /* Expression: 0
   * Referenced by: '<Root>/stop'
   */
  0.0,

  /* Expression: 1
   * Referenced by: '<Root>/reverse'
   */
  1.0,

  /* Expression: 0
   * Referenced by: '<Root>/forwards'
   */
  0.0,

  /* Expression: 0
   * Referenced by: '<Root>/Constant2'
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

  /* Expression: [0 0 0 0]
   * Referenced by: '<Root>/Default Cmd'
   */
  { 0.0, 0.0, 0.0, 0.0 },

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

  /* Expression: 0
   * Referenced by: '<S7>/Step'
   */
  0.0,

  /* Expression: -pi/2
   * Referenced by: '<Root>/Constant6'
   */
  -1.5707963267948966,

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

  /* Expression: [0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0;-1.04709228628267 -1.0284199515082 -1.0096456553629 -0.99078025071788 -0.971834425392249 -0.952818667953098 -0.933743235632255 -0.914618124553628 -0.895453042427873 -0.876257383833672 -0.857040208167683 -0.837810220308976 -0.818575754009205 -0.799344757987352 -0.780124784678143 -0.760922981556506 -0.741746084936902 -0.722600416126287 -0.703491879792766 -0.684425964398722 -0.665407744537264 -0.646441885003966 -0.627532646431961 -0.608683892317165 -0.589899097261526 -0.571181356265357 -0.552533394904755 -0.533957580236555 -0.515455932280849 -0.497030135939616 -0.478681553219177 -0.46041123563374 -0.442219936677102 -0.424108124259327 -0.406075993014923 -0.388123476398341 -0.370250258491653 -0.352455785457721 -0.3347392765801 -0.317099734838247 -0.29953595697326 -0.282046543005345 -0.264629905169511 - */
  { 0.0, -1.04709228628267, 0.785443430115708, 0.0, 0.0, -1.0284199515082,
    0.782915417526854, 0.0, 0.0, -1.0096456553629, 0.780090962548004, 0.0, 0.0,
    -0.99078025071788, 0.776971904741503, 0.0, 0.0, -0.971834425392249,
    0.773560244084315, 0.0, 0.0, -0.952818667953098, 0.769858130942717, 0.0, 0.0,
    -0.933743235632255, 0.765867855480423, 0.0, 0.0, -0.914618124553628,
    0.761591836590414, 0.0, 0.0, -0.895453042427873, 0.757032610441019, 0.0, 0.0,
    -0.876257383833672, 0.752192818725826, 0.0, 0.0, -0.857040208167683,
    0.747075196704776, 0.0, 0.0, -0.837810220308976, 0.741682561120522, 0.0, 0.0,
    -0.818575754009205, 0.736017798069904, 0.0, 0.0, -0.799344757987352,
    0.730083850905334, 0.0, 0.0, -0.780124784678143, 0.723883708235186, 0.0, 0.0,
    -0.760922981556506, 0.717420392086019, 0.0, 0.0, -0.741746084936902,
    0.71069694628287, 0.0, 0.0, -0.722600416126287, 0.703716425096979, 0.0, 0.0,
    -0.703491879792766, 0.696481882203343, 0.0, 0.0, -0.684425964398722,
    0.688996359983516, 0.0, 0.0, -0.665407744537264, 0.681262879202228, 0.0, 0.0,
    -0.646441885003966, 0.673284429079703, 0.0, 0.0, -0.627532646431961,
    0.665063957775183, 0.0, 0.0, -0.608683892317165, 0.656604363291081, 0.0, 0.0,
    -0.589899097261526, 0.647908484801497, 0.0, 0.0, -0.571181356265357,
    0.638979094403555, 0.0, 0.0, -0.552533394904755, 0.629818889285128, 0.0, 0.0,
    -0.533957580236555, 0.620430484298141, 0.0, 0.0, -0.515455932280849,
    0.610816404922589, 0.0, 0.0, -0.497030135939616, 0.600979080602862, 0.0, 0.0,
    -0.478681553219177, 0.590920838434791, 0.0, 0.0, -0.46041123563374,
    0.580643897178982, 0.0, 0.0, -0.442219936677102, 0.570150361573611, 0.0, 0.0,
    -0.424108124259327, 0.559442216917603, 0.0, 0.0, -0.406075993014923,
    0.548521323893325, 0.0, 0.0, -0.388123476398341, 0.537389413596185, 0.0, 0.0,
    -0.370250258491653, 0.526048082737109, 0.0, 0.0, -0.352455785457721,
    0.514498788982497, 0.0, 0.0, -0.3347392765801, 0.502742846395065, 0.0, 0.0,
    -0.317099734838247, 0.49078142093777, 0.0, 0.0, -0.29953595697326,
    0.478615526001867, 0.0, 0.0, -0.282046543005345, 0.46624601791894, 0.0, 0.0,
    -0.264629905169511, 0.45367359141544, 0.0, 0.0, -0.247284276240539,
    0.440898774966871, 0.0, 0.0, -0.230007717222157, 0.427921926007148, 0.0, 0.0,
    -0.212798124378511, 0.41474322594681, 0.0, 0.0, -0.195653235588459,
    0.40136267495166, 0.0, 0.0, -0.178570636005007, 0.38778008643093, 0.0, 0.0,
    -0.161547763003239, 0.373995081181176, 0.0, 0.0, -0.144581910400481,
    0.360007081128769, 0.0, 0.0, -0.127670231932134, 0.345815302609878, 0.0, 0.0,
    -0.110809743965547, 0.331418749122312, 0.0, 0.0, -0.0939973274325981,
    0.316816203478207, 0.0, 0.0, -0.0772297289591123, 0.302006219280376, 0.0,
    0.0, -0.0605035611659891, 0.286987111637899, 0.0, 0.0, -0.0438153021127725,
    0.271756947028166, 0.0, 0.0, -0.0271612938493659, 0.256313532202852, 0.0,
    0.0, -0.0105377400355459, 0.240654402023973, 0.0, 0.0, 0.00605929741920827,
    0.224776806103057, 0.0, 0.0, 0.0226339027514769, 0.208677694101149, 0.0, 0.0,
    0.0391903118409901, 0.192353699529582, 0.0, 0.0, 0.0557329188862888,
    0.175801121870639, 0.0, 0.0, 0.072266284349605, 0.159015906812993, 0.0, 0.0,
    0.0887951442772854, 0.14199362436834, 0.0, 0.0, 0.1053244211204,
    0.124729444602282, 0.0, 0.0, 0.121859236201675, 0.107218110673216, 0.0, 0.0,
    0.138404924000133, 0.0894539088265761, 0.0, 0.0, 0.154967048454666,
    0.0714306349368369, 0.0, 0.0, 0.171551421523014, 0.0531415571243617, 0.0,
    0.0, 0.188164124274647, 0.0345793738962524, 0.0, 0.0, 0.20481153084614,
    0.0157361671670228, 0.0, 0.0, 0.22150033564778, -0.00339665059733565, 0.0,
    0.0, 0.238237584282658, -0.022828396003981, 0.0, 0.0, 0.255030708727368,
    -0.0425691821832741, 0.0, 0.0, 0.271887567430466, -0.0626299953219034, 0.0,
    0.0, 0.288816491116013, -0.083022781783178, 0.0, 0.0, 0.305826335241173,
    -0.103760547622595, 0.0, 0.0, 0.322926540257255, -0.124857472684126, 0.0,
    0.0, 0.340127201073865, -0.146329041933936, 0.0, 0.0, 0.357439147440313,
    -0.16819219728094, 0.0, 0.0, 0.374874037356719, -0.190465513884305, 0.0, 0.0,
    0.392444466135521, -0.21316940590636, 0.0, 0.0, 0.410164094388122,
    -0.236326367902768, 0.0, 0.0, 0.428047799060633, -0.259961259643439, 0.0,
    0.0, 0.446111852755739, -0.284101644257212, 0.0, 0.0, 0.464374138051773,
    -0.308778192373779, 0.0, 0.0, 0.482854405503768, -0.334025168659379, 0.0,
    0.0, 0.501574586685825, -0.359881022187863, 0.0, 0.0, 0.520559177305619,
    -0.386389109014199, 0.0, 0.0, 0.539835710533749, -0.413598584959735, 0.0,
    0.0, 0.559435347918925, -0.44156552025221, 0.0, 0.0, 0.579393625656121,
    -0.470354307271479, 0.0, 0.0, 0.599751409210698, -0.500039461386565, 0.0,
    0.0, 0.620556132100686, -0.530707957866486, 0.0, 0.0, 0.641863429561432,
    -0.562462313702801, 0.0, 0.0, 0.663739332729231, -0.595424726729338, 0.0,
    0.0, 0.686263277934726, -0.629742752154446, 0.0, 0.0, 0.709532334788974,
    -0.665597277729352, 0.0, 0.0, 0.733667316674111, -0.703214048834994, 0.0,
    0.0, 0.758821911820839, -0.742880889450097, 0.0, 0.0, 0.785196888499669,
    -0.78497449050604, 0.0 },

  /* Expression: 20
   * Referenced by: '<Root>/Constant16'
   */
  20.0,

  /* Expression: 100
   * Referenced by: '<Root>/Constant17'
   */
  100.0,

  /* Expression: qc_get_step_size
   * Referenced by: '<Root>/Constant7'
   */
  0.002,

  /* Expression: 0.1
   * Referenced by: '<S8>/Integrator'
   */
  0.1,

  /* Expression: 0.9
   * Referenced by: '<S8>/Integrator'
   */
  0.9,

  /* Expression: 0.1
   * Referenced by: '<S8>/Integrator'
   */
  0.1,

  /* Expression: 0.1
   * Referenced by: '<S8>/open position'
   */
  0.1,

  /* Expression: 0
   * Referenced by: '<S8>/Switch'
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
   * Referenced by: '<S9>/x0'
   */
  0.0,

  /* Expression: 0.25
   * Referenced by: '<S8>/Soft-Grip Current (A)'
   */
  0.25,

  /* Expression: 2
   * Referenced by: '<S9>/Constant'
   */
  2.0,

  /* Expression: 0
   * Referenced by: '<S9>/Integrator2'
   */
  0.0,

  /* Expression: 10
   * Referenced by: '<S8>/Gain2'
   */
  10.0,

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

  /* Computed Parameter: ManualSwitch2_CurrentSetting
   * Referenced by: '<Root>/Manual Switch2'
   */
  1U,

  /* Computed Parameter: ManualSwitch4_CurrentSetting
   * Referenced by: '<Root>/Manual Switch4'
   */
  0U,

  /* Computed Parameter: HILReadTimebase1_OverflowMode
   * Referenced by: '<S2>/HIL Read Timebase1'
   */
  1U,

  /* Computed Parameter: ManualSwitch_CurrentSetting
   * Referenced by: '<Root>/Manual Switch'
   */
  0U,

  /* Computed Parameter: ManualSwitch1_CurrentSetting
   * Referenced by: '<Root>/Manual Switch1'
   */
  0U,

  /* Computed Parameter: ManualSwitch3_CurrentSetting
   * Referenced by: '<Root>/Manual Switch3'
   */
  0U,

  /* Computed Parameter: MAIN_CurrentSetting
   * Referenced by: '<Root>/MAIN'
   */
  1U,

  /* Computed Parameter: ManualSwitch5_CurrentSetting
   * Referenced by: '<Root>/Manual Switch5'
   */
  0U,

  /* Computed Parameter: ManualSwitch6_CurrentSetting
   * Referenced by: '<Root>/Manual Switch6'
   */
  0U,

  /* Computed Parameter: ManualSwitch7_CurrentSetting
   * Referenced by: '<Root>/Manual Switch7'
   */
  1U,

  /* Computed Parameter: MAIN1_CurrentSetting
   * Referenced by: '<Root>/MAIN1'
   */
  0U
};
