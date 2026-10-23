/*
 * TrajRunner.h
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

#ifndef TrajRunner_h_
#define TrajRunner_h_
#ifndef TrajRunner_COMMON_INCLUDES_
#define TrajRunner_COMMON_INCLUDES_
#include <math.h>
#include "rtwtypes.h"
#include "simstruc.h"
#include "fixedpoint.h"
#include "rtw_extmode.h"
#include "sysran_types.h"
#include "rtw_continuous.h"
#include "rtw_solver.h"
#include "rt_nonfinite.h"
#include "math.h"
#include "dt_info.h"
#include "ext_work.h"
#include "hil.h"
#include "quanser_messages.h"
#include "quanser_time.h"
#include "quanser_extern.h"
#endif                                 /* TrajRunner_COMMON_INCLUDES_ */

#include "TrajRunner_types.h"
#include "rt_zcfcn.h"
#include <string.h>
#include "rt_defines.h"
#include "zero_crossing_types.h"

/* Macros for accessing real-time model data structure */
#ifndef rtmGetBlockIO
#define rtmGetBlockIO(rtm)             ((rtm)->blockIO)
#endif

#ifndef rtmSetBlockIO
#define rtmSetBlockIO(rtm, val)        ((rtm)->blockIO = (val))
#endif

#ifndef rtmGetChecksums
#define rtmGetChecksums(rtm)           ((rtm)->Sizes.checksums)
#endif

#ifndef rtmSetChecksums
#define rtmSetChecksums(rtm, val)      ((rtm)->Sizes.checksums = (val))
#endif

#ifndef rtmGetConstBlockIO
#define rtmGetConstBlockIO(rtm)        ((rtm)->constBlockIO)
#endif

#ifndef rtmSetConstBlockIO
#define rtmSetConstBlockIO(rtm, val)   ((rtm)->constBlockIO = (val))
#endif

#ifndef rtmGetContStateDisabled
#define rtmGetContStateDisabled(rtm)   ((rtm)->contStateDisabled)
#endif

#ifndef rtmSetContStateDisabled
#define rtmSetContStateDisabled(rtm, val) ((rtm)->contStateDisabled = (val))
#endif

#ifndef rtmGetContStates
#define rtmGetContStates(rtm)          ((rtm)->contStates)
#endif

#ifndef rtmSetContStates
#define rtmSetContStates(rtm, val)     ((rtm)->contStates = (val))
#endif

#ifndef rtmGetContTimeOutputInconsistentWithStateAtMajorStepFlag
#define rtmGetContTimeOutputInconsistentWithStateAtMajorStepFlag(rtm) ((rtm)->CTOutputIncnstWithState)
#endif

#ifndef rtmSetContTimeOutputInconsistentWithStateAtMajorStepFlag
#define rtmSetContTimeOutputInconsistentWithStateAtMajorStepFlag(rtm, val) ((rtm)->CTOutputIncnstWithState = (val))
#endif

#ifndef rtmGetCtrlRateMdlRefTiming
#define rtmGetCtrlRateMdlRefTiming(rtm) ()
#endif

#ifndef rtmSetCtrlRateMdlRefTiming
#define rtmSetCtrlRateMdlRefTiming(rtm, val) ()
#endif

#ifndef rtmGetCtrlRateMdlRefTimingPtr
#define rtmGetCtrlRateMdlRefTimingPtr(rtm) ()
#endif

#ifndef rtmSetCtrlRateMdlRefTimingPtr
#define rtmSetCtrlRateMdlRefTimingPtr(rtm, val) ()
#endif

#ifndef rtmGetCtrlRateNumTicksToNextHit
#define rtmGetCtrlRateNumTicksToNextHit(rtm) ()
#endif

#ifndef rtmSetCtrlRateNumTicksToNextHit
#define rtmSetCtrlRateNumTicksToNextHit(rtm, val) ()
#endif

#ifndef rtmGetDataMapInfo
#define rtmGetDataMapInfo(rtm)         ()
#endif

#ifndef rtmSetDataMapInfo
#define rtmSetDataMapInfo(rtm, val)    ()
#endif

#ifndef rtmGetDefaultParam
#define rtmGetDefaultParam(rtm)        ((rtm)->defaultParam)
#endif

#ifndef rtmSetDefaultParam
#define rtmSetDefaultParam(rtm, val)   ((rtm)->defaultParam = (val))
#endif

#ifndef rtmGetDerivCacheNeedsReset
#define rtmGetDerivCacheNeedsReset(rtm) ((rtm)->derivCacheNeedsReset)
#endif

#ifndef rtmSetDerivCacheNeedsReset
#define rtmSetDerivCacheNeedsReset(rtm, val) ((rtm)->derivCacheNeedsReset = (val))
#endif

#ifndef rtmGetDirectFeedThrough
#define rtmGetDirectFeedThrough(rtm)   ((rtm)->Sizes.sysDirFeedThru)
#endif

#ifndef rtmSetDirectFeedThrough
#define rtmSetDirectFeedThrough(rtm, val) ((rtm)->Sizes.sysDirFeedThru = (val))
#endif

#ifndef rtmGetErrorStatusFlag
#define rtmGetErrorStatusFlag(rtm)     ((rtm)->errorStatus)
#endif

#ifndef rtmSetErrorStatusFlag
#define rtmSetErrorStatusFlag(rtm, val) ((rtm)->errorStatus = (val))
#endif

#ifndef rtmGetFinalTime
#define rtmGetFinalTime(rtm)           ((rtm)->Timing.tFinal)
#endif

#ifndef rtmSetFinalTime
#define rtmSetFinalTime(rtm, val)      ((rtm)->Timing.tFinal = (val))
#endif

#ifndef rtmGetFirstInitCondFlag
#define rtmGetFirstInitCondFlag(rtm)   ((rtm)->Timing.firstInitCondFlag)
#endif

#ifndef rtmSetFirstInitCondFlag
#define rtmSetFirstInitCondFlag(rtm, val) ((rtm)->Timing.firstInitCondFlag = (val))
#endif

#ifndef rtmGetIntgData
#define rtmGetIntgData(rtm)            ((rtm)->intgData)
#endif

#ifndef rtmSetIntgData
#define rtmSetIntgData(rtm, val)       ((rtm)->intgData = (val))
#endif

#ifndef rtmGetMdlRefGlobalRuntimeEventIndices
#define rtmGetMdlRefGlobalRuntimeEventIndices(rtm) ()
#endif

#ifndef rtmSetMdlRefGlobalRuntimeEventIndices
#define rtmSetMdlRefGlobalRuntimeEventIndices(rtm, val) ()
#endif

#ifndef rtmGetMdlRefGlobalTID
#define rtmGetMdlRefGlobalTID(rtm)     ()
#endif

#ifndef rtmSetMdlRefGlobalTID
#define rtmSetMdlRefGlobalTID(rtm, val) ()
#endif

#ifndef rtmGetMdlRefGlobalTimerIndices
#define rtmGetMdlRefGlobalTimerIndices(rtm) ()
#endif

#ifndef rtmSetMdlRefGlobalTimerIndices
#define rtmSetMdlRefGlobalTimerIndices(rtm, val) ()
#endif

#ifndef rtmGetMdlRefTriggerTID
#define rtmGetMdlRefTriggerTID(rtm)    ()
#endif

#ifndef rtmSetMdlRefTriggerTID
#define rtmSetMdlRefTriggerTID(rtm, val) ()
#endif

#ifndef rtmGetModelMappingInfo
#define rtmGetModelMappingInfo(rtm)    ((rtm)->SpecialInfo.mappingInfo)
#endif

#ifndef rtmSetModelMappingInfo
#define rtmSetModelMappingInfo(rtm, val) ((rtm)->SpecialInfo.mappingInfo = (val))
#endif

#ifndef rtmGetModelName
#define rtmGetModelName(rtm)           ((rtm)->modelName)
#endif

#ifndef rtmSetModelName
#define rtmSetModelName(rtm, val)      ((rtm)->modelName = (val))
#endif

#ifndef rtmGetNonInlinedSFcns
#define rtmGetNonInlinedSFcns(rtm)     ()
#endif

#ifndef rtmSetNonInlinedSFcns
#define rtmSetNonInlinedSFcns(rtm, val) ()
#endif

#ifndef rtmGetNumBlockIO
#define rtmGetNumBlockIO(rtm)          ((rtm)->Sizes.numBlockIO)
#endif

#ifndef rtmSetNumBlockIO
#define rtmSetNumBlockIO(rtm, val)     ((rtm)->Sizes.numBlockIO = (val))
#endif

#ifndef rtmGetNumBlockParams
#define rtmGetNumBlockParams(rtm)      ((rtm)->Sizes.numBlockPrms)
#endif

#ifndef rtmSetNumBlockParams
#define rtmSetNumBlockParams(rtm, val) ((rtm)->Sizes.numBlockPrms = (val))
#endif

#ifndef rtmGetNumBlocks
#define rtmGetNumBlocks(rtm)           ((rtm)->Sizes.numBlocks)
#endif

#ifndef rtmSetNumBlocks
#define rtmSetNumBlocks(rtm, val)      ((rtm)->Sizes.numBlocks = (val))
#endif

#ifndef rtmGetNumContStates
#define rtmGetNumContStates(rtm)       ((rtm)->Sizes.numContStates)
#endif

#ifndef rtmSetNumContStates
#define rtmSetNumContStates(rtm, val)  ((rtm)->Sizes.numContStates = (val))
#endif

#ifndef rtmGetNumDWork
#define rtmGetNumDWork(rtm)            ((rtm)->Sizes.numDwork)
#endif

#ifndef rtmSetNumDWork
#define rtmSetNumDWork(rtm, val)       ((rtm)->Sizes.numDwork = (val))
#endif

#ifndef rtmGetNumInputPorts
#define rtmGetNumInputPorts(rtm)       ((rtm)->Sizes.numIports)
#endif

#ifndef rtmSetNumInputPorts
#define rtmSetNumInputPorts(rtm, val)  ((rtm)->Sizes.numIports = (val))
#endif

#ifndef rtmGetNumNonSampledZCs
#define rtmGetNumNonSampledZCs(rtm)    ((rtm)->Sizes.numNonSampZCs)
#endif

#ifndef rtmSetNumNonSampledZCs
#define rtmSetNumNonSampledZCs(rtm, val) ((rtm)->Sizes.numNonSampZCs = (val))
#endif

#ifndef rtmGetNumOutputPorts
#define rtmGetNumOutputPorts(rtm)      ((rtm)->Sizes.numOports)
#endif

#ifndef rtmSetNumOutputPorts
#define rtmSetNumOutputPorts(rtm, val) ((rtm)->Sizes.numOports = (val))
#endif

#ifndef rtmGetNumPeriodicContStates
#define rtmGetNumPeriodicContStates(rtm) ((rtm)->Sizes.numPeriodicContStates)
#endif

#ifndef rtmSetNumPeriodicContStates
#define rtmSetNumPeriodicContStates(rtm, val) ((rtm)->Sizes.numPeriodicContStates = (val))
#endif

#ifndef rtmGetNumSFcnParams
#define rtmGetNumSFcnParams(rtm)       ((rtm)->Sizes.numSFcnPrms)
#endif

#ifndef rtmSetNumSFcnParams
#define rtmSetNumSFcnParams(rtm, val)  ((rtm)->Sizes.numSFcnPrms = (val))
#endif

#ifndef rtmGetNumSFunctions
#define rtmGetNumSFunctions(rtm)       ((rtm)->Sizes.numSFcns)
#endif

#ifndef rtmSetNumSFunctions
#define rtmSetNumSFunctions(rtm, val)  ((rtm)->Sizes.numSFcns = (val))
#endif

#ifndef rtmGetNumSampleTimes
#define rtmGetNumSampleTimes(rtm)      ((rtm)->Sizes.numSampTimes)
#endif

#ifndef rtmSetNumSampleTimes
#define rtmSetNumSampleTimes(rtm, val) ((rtm)->Sizes.numSampTimes = (val))
#endif

#ifndef rtmGetNumU
#define rtmGetNumU(rtm)                ((rtm)->Sizes.numU)
#endif

#ifndef rtmSetNumU
#define rtmSetNumU(rtm, val)           ((rtm)->Sizes.numU = (val))
#endif

#ifndef rtmGetNumY
#define rtmGetNumY(rtm)                ((rtm)->Sizes.numY)
#endif

#ifndef rtmSetNumY
#define rtmSetNumY(rtm, val)           ((rtm)->Sizes.numY = (val))
#endif

#ifndef rtmGetOdeF
#define rtmGetOdeF(rtm)                ((rtm)->odeF)
#endif

#ifndef rtmSetOdeF
#define rtmSetOdeF(rtm, val)           ((rtm)->odeF = (val))
#endif

#ifndef rtmGetOdeY
#define rtmGetOdeY(rtm)                ((rtm)->odeY)
#endif

#ifndef rtmSetOdeY
#define rtmSetOdeY(rtm, val)           ((rtm)->odeY = (val))
#endif

#ifndef rtmGetOffsetTimeArray
#define rtmGetOffsetTimeArray(rtm)     ((rtm)->Timing.offsetTimesArray)
#endif

#ifndef rtmSetOffsetTimeArray
#define rtmSetOffsetTimeArray(rtm, val) ((rtm)->Timing.offsetTimesArray = (val))
#endif

#ifndef rtmGetOffsetTimePtr
#define rtmGetOffsetTimePtr(rtm)       ((rtm)->Timing.offsetTimes)
#endif

#ifndef rtmSetOffsetTimePtr
#define rtmSetOffsetTimePtr(rtm, val)  ((rtm)->Timing.offsetTimes = (val))
#endif

#ifndef rtmGetOptions
#define rtmGetOptions(rtm)             ((rtm)->Sizes.options)
#endif

#ifndef rtmSetOptions
#define rtmSetOptions(rtm, val)        ((rtm)->Sizes.options = (val))
#endif

#ifndef rtmGetParamIsMalloced
#define rtmGetParamIsMalloced(rtm)     ()
#endif

#ifndef rtmSetParamIsMalloced
#define rtmSetParamIsMalloced(rtm, val) ()
#endif

#ifndef rtmGetPath
#define rtmGetPath(rtm)                ((rtm)->path)
#endif

#ifndef rtmSetPath
#define rtmSetPath(rtm, val)           ((rtm)->path = (val))
#endif

#ifndef rtmGetPerTaskSampleHits
#define rtmGetPerTaskSampleHits(rtm)   ()
#endif

#ifndef rtmSetPerTaskSampleHits
#define rtmSetPerTaskSampleHits(rtm, val) ()
#endif

#ifndef rtmGetPerTaskSampleHitsArray
#define rtmGetPerTaskSampleHitsArray(rtm) ((rtm)->Timing.perTaskSampleHitsArray)
#endif

#ifndef rtmSetPerTaskSampleHitsArray
#define rtmSetPerTaskSampleHitsArray(rtm, val) ((rtm)->Timing.perTaskSampleHitsArray = (val))
#endif

#ifndef rtmGetPerTaskSampleHitsPtr
#define rtmGetPerTaskSampleHitsPtr(rtm) ((rtm)->Timing.perTaskSampleHits)
#endif

#ifndef rtmSetPerTaskSampleHitsPtr
#define rtmSetPerTaskSampleHitsPtr(rtm, val) ((rtm)->Timing.perTaskSampleHits = (val))
#endif

#ifndef rtmGetPeriodicContStateIndices
#define rtmGetPeriodicContStateIndices(rtm) ((rtm)->periodicContStateIndices)
#endif

#ifndef rtmSetPeriodicContStateIndices
#define rtmSetPeriodicContStateIndices(rtm, val) ((rtm)->periodicContStateIndices = (val))
#endif

#ifndef rtmGetPeriodicContStateRanges
#define rtmGetPeriodicContStateRanges(rtm) ((rtm)->periodicContStateRanges)
#endif

#ifndef rtmSetPeriodicContStateRanges
#define rtmSetPeriodicContStateRanges(rtm, val) ((rtm)->periodicContStateRanges = (val))
#endif

#ifndef rtmGetPrevZCSigState
#define rtmGetPrevZCSigState(rtm)      ((rtm)->prevZCSigState)
#endif

#ifndef rtmSetPrevZCSigState
#define rtmSetPrevZCSigState(rtm, val) ((rtm)->prevZCSigState = (val))
#endif

#ifndef rtmGetProxyFunctions
#define rtmGetProxyFunctions(rtm)      ()
#endif

#ifndef rtmSetProxyFunctions
#define rtmSetProxyFunctions(rtm, val) ()
#endif

#ifndef rtmGetRTWExtModeInfo
#define rtmGetRTWExtModeInfo(rtm)      ((rtm)->extModeInfo)
#endif

#ifndef rtmSetRTWExtModeInfo
#define rtmSetRTWExtModeInfo(rtm, val) ((rtm)->extModeInfo = (val))
#endif

#ifndef rtmGetRTWGeneratedSFcn
#define rtmGetRTWGeneratedSFcn(rtm)    ((rtm)->Sizes.rtwGenSfcn)
#endif

#ifndef rtmSetRTWGeneratedSFcn
#define rtmSetRTWGeneratedSFcn(rtm, val) ((rtm)->Sizes.rtwGenSfcn = (val))
#endif

#ifndef rtmGetRTWLogInfo
#define rtmGetRTWLogInfo(rtm)          ()
#endif

#ifndef rtmSetRTWLogInfo
#define rtmSetRTWLogInfo(rtm, val)     ()
#endif

#ifndef rtmGetRTWRTModelMethodsInfo
#define rtmGetRTWRTModelMethodsInfo(rtm) ()
#endif

#ifndef rtmSetRTWRTModelMethodsInfo
#define rtmSetRTWRTModelMethodsInfo(rtm, val) ()
#endif

#ifndef rtmGetRTWSfcnInfo
#define rtmGetRTWSfcnInfo(rtm)         ((rtm)->sfcnInfo)
#endif

#ifndef rtmSetRTWSfcnInfo
#define rtmSetRTWSfcnInfo(rtm, val)    ((rtm)->sfcnInfo = (val))
#endif

#ifndef rtmGetRTWSolverInfo
#define rtmGetRTWSolverInfo(rtm)       ((rtm)->solverInfo)
#endif

#ifndef rtmSetRTWSolverInfo
#define rtmSetRTWSolverInfo(rtm, val)  ((rtm)->solverInfo = (val))
#endif

#ifndef rtmGetRTWSolverInfoPtr
#define rtmGetRTWSolverInfoPtr(rtm)    ((rtm)->solverInfoPtr)
#endif

#ifndef rtmSetRTWSolverInfoPtr
#define rtmSetRTWSolverInfoPtr(rtm, val) ((rtm)->solverInfoPtr = (val))
#endif

#ifndef rtmGetReservedForXPC
#define rtmGetReservedForXPC(rtm)      ((rtm)->SpecialInfo.xpcData)
#endif

#ifndef rtmSetReservedForXPC
#define rtmSetReservedForXPC(rtm, val) ((rtm)->SpecialInfo.xpcData = (val))
#endif

#ifndef rtmGetRootDWork
#define rtmGetRootDWork(rtm)           ((rtm)->dwork)
#endif

#ifndef rtmSetRootDWork
#define rtmSetRootDWork(rtm, val)      ((rtm)->dwork = (val))
#endif

#ifndef rtmGetSFunctions
#define rtmGetSFunctions(rtm)          ((rtm)->childSfunctions)
#endif

#ifndef rtmSetSFunctions
#define rtmSetSFunctions(rtm, val)     ((rtm)->childSfunctions = (val))
#endif

#ifndef rtmGetSampleHitArray
#define rtmGetSampleHitArray(rtm)      ((rtm)->Timing.sampleHitArray)
#endif

#ifndef rtmSetSampleHitArray
#define rtmSetSampleHitArray(rtm, val) ((rtm)->Timing.sampleHitArray = (val))
#endif

#ifndef rtmGetSampleHitPtr
#define rtmGetSampleHitPtr(rtm)        ((rtm)->Timing.sampleHits)
#endif

#ifndef rtmSetSampleHitPtr
#define rtmSetSampleHitPtr(rtm, val)   ((rtm)->Timing.sampleHits = (val))
#endif

#ifndef rtmGetSampleTimeArray
#define rtmGetSampleTimeArray(rtm)     ((rtm)->Timing.sampleTimesArray)
#endif

#ifndef rtmSetSampleTimeArray
#define rtmSetSampleTimeArray(rtm, val) ((rtm)->Timing.sampleTimesArray = (val))
#endif

#ifndef rtmGetSampleTimePtr
#define rtmGetSampleTimePtr(rtm)       ((rtm)->Timing.sampleTimes)
#endif

#ifndef rtmSetSampleTimePtr
#define rtmSetSampleTimePtr(rtm, val)  ((rtm)->Timing.sampleTimes = (val))
#endif

#ifndef rtmGetSampleTimeTaskIDArray
#define rtmGetSampleTimeTaskIDArray(rtm) ((rtm)->Timing.sampleTimeTaskIDArray)
#endif

#ifndef rtmSetSampleTimeTaskIDArray
#define rtmSetSampleTimeTaskIDArray(rtm, val) ((rtm)->Timing.sampleTimeTaskIDArray = (val))
#endif

#ifndef rtmGetSampleTimeTaskIDPtr
#define rtmGetSampleTimeTaskIDPtr(rtm) ((rtm)->Timing.sampleTimeTaskIDPtr)
#endif

#ifndef rtmSetSampleTimeTaskIDPtr
#define rtmSetSampleTimeTaskIDPtr(rtm, val) ((rtm)->Timing.sampleTimeTaskIDPtr = (val))
#endif

#ifndef rtmGetSelf
#define rtmGetSelf(rtm)                ()
#endif

#ifndef rtmSetSelf
#define rtmSetSelf(rtm, val)           ()
#endif

#ifndef rtmGetSimMode
#define rtmGetSimMode(rtm)             ((rtm)->simMode)
#endif

#ifndef rtmSetSimMode
#define rtmSetSimMode(rtm, val)        ((rtm)->simMode = (val))
#endif

#ifndef rtmGetSimTimeStep
#define rtmGetSimTimeStep(rtm)         ((rtm)->Timing.simTimeStep)
#endif

#ifndef rtmSetSimTimeStep
#define rtmSetSimTimeStep(rtm, val)    ((rtm)->Timing.simTimeStep = (val))
#endif

#ifndef rtmGetStartTime
#define rtmGetStartTime(rtm)           ((rtm)->Timing.tStart)
#endif

#ifndef rtmSetStartTime
#define rtmSetStartTime(rtm, val)      ((rtm)->Timing.tStart = (val))
#endif

#ifndef rtmGetStepSize
#define rtmGetStepSize(rtm)            ((rtm)->Timing.stepSize)
#endif

#ifndef rtmSetStepSize
#define rtmSetStepSize(rtm, val)       ((rtm)->Timing.stepSize = (val))
#endif

#ifndef rtmGetStopRequestedFlag
#define rtmGetStopRequestedFlag(rtm)   ((rtm)->Timing.stopRequestedFlag)
#endif

#ifndef rtmSetStopRequestedFlag
#define rtmSetStopRequestedFlag(rtm, val) ((rtm)->Timing.stopRequestedFlag = (val))
#endif

#ifndef rtmGetStubFunctions
#define rtmGetStubFunctions(rtm)       ()
#endif

#ifndef rtmSetStubFunctions
#define rtmSetStubFunctions(rtm, val)  ()
#endif

#ifndef rtmGetTaskCounters
#define rtmGetTaskCounters(rtm)        ()
#endif

#ifndef rtmSetTaskCounters
#define rtmSetTaskCounters(rtm, val)   ()
#endif

#ifndef rtmGetTaskTimeArray
#define rtmGetTaskTimeArray(rtm)       ((rtm)->Timing.tArray)
#endif

#ifndef rtmSetTaskTimeArray
#define rtmSetTaskTimeArray(rtm, val)  ((rtm)->Timing.tArray = (val))
#endif

#ifndef rtmGetTimePtr
#define rtmGetTimePtr(rtm)             ((rtm)->Timing.t)
#endif

#ifndef rtmSetTimePtr
#define rtmSetTimePtr(rtm, val)        ((rtm)->Timing.t = (val))
#endif

#ifndef rtmGetTimingData
#define rtmGetTimingData(rtm)          ((rtm)->Timing.timingData)
#endif

#ifndef rtmSetTimingData
#define rtmSetTimingData(rtm, val)     ((rtm)->Timing.timingData = (val))
#endif

#ifndef rtmGetU
#define rtmGetU(rtm)                   ((rtm)->inputs)
#endif

#ifndef rtmSetU
#define rtmSetU(rtm, val)              ((rtm)->inputs = (val))
#endif

#ifndef rtmGetVarNextHitTimesListPtr
#define rtmGetVarNextHitTimesListPtr(rtm) ((rtm)->Timing.varNextHitTimesList)
#endif

#ifndef rtmSetVarNextHitTimesListPtr
#define rtmSetVarNextHitTimesListPtr(rtm, val) ((rtm)->Timing.varNextHitTimesList = (val))
#endif

#ifndef rtmGetY
#define rtmGetY(rtm)                   ((rtm)->outputs)
#endif

#ifndef rtmSetY
#define rtmSetY(rtm, val)              ((rtm)->outputs = (val))
#endif

#ifndef rtmGetZCCacheNeedsReset
#define rtmGetZCCacheNeedsReset(rtm)   ((rtm)->zCCacheNeedsReset)
#endif

#ifndef rtmSetZCCacheNeedsReset
#define rtmSetZCCacheNeedsReset(rtm, val) ((rtm)->zCCacheNeedsReset = (val))
#endif

#ifndef rtmGetZCSignalValues
#define rtmGetZCSignalValues(rtm)      ((rtm)->zcSignalValues)
#endif

#ifndef rtmSetZCSignalValues
#define rtmSetZCSignalValues(rtm, val) ((rtm)->zcSignalValues = (val))
#endif

#ifndef rtmGet_TimeOfLastOutput
#define rtmGet_TimeOfLastOutput(rtm)   ((rtm)->Timing.timeOfLastOutput)
#endif

#ifndef rtmSet_TimeOfLastOutput
#define rtmSet_TimeOfLastOutput(rtm, val) ((rtm)->Timing.timeOfLastOutput = (val))
#endif

#ifndef rtmGetclockTickHPtrsArray
#define rtmGetclockTickHPtrsArray(rtm) ()
#endif

#ifndef rtmSetclockTickHPtrsArray
#define rtmSetclockTickHPtrsArray(rtm, val) ()
#endif

#ifndef rtmGetclockTickPtrsArray
#define rtmGetclockTickPtrsArray(rtm)  ()
#endif

#ifndef rtmSetclockTickPtrsArray
#define rtmSetclockTickPtrsArray(rtm, val) ()
#endif

#ifndef rtmGetdX
#define rtmGetdX(rtm)                  ((rtm)->derivs)
#endif

#ifndef rtmSetdX
#define rtmSetdX(rtm, val)             ((rtm)->derivs = (val))
#endif

#ifndef rtmGetrateTransitionPtrsArray
#define rtmGetrateTransitionPtrsArray(rtm) ()
#endif

#ifndef rtmSetrateTransitionPtrsArray
#define rtmSetrateTransitionPtrsArray(rtm, val) ()
#endif

#ifndef rtmGettaskTimePtrsArray
#define rtmGettaskTimePtrsArray(rtm)   ()
#endif

#ifndef rtmSettaskTimePtrsArray
#define rtmSettaskTimePtrsArray(rtm, val) ()
#endif

#ifndef rtmGettimingBridge
#define rtmGettimingBridge(rtm)        ()
#endif

#ifndef rtmSettimingBridge
#define rtmSettimingBridge(rtm, val)   ()
#endif

#ifndef rtmGetChecksumVal
#define rtmGetChecksumVal(rtm, idx)    ((rtm)->Sizes.checksums[idx])
#endif

#ifndef rtmSetChecksumVal
#define rtmSetChecksumVal(rtm, idx, val) ((rtm)->Sizes.checksums[idx] = (val))
#endif

#ifndef rtmGetDWork
#define rtmGetDWork(rtm, idx)          ((rtm)->dwork[idx])
#endif

#ifndef rtmSetDWork
#define rtmSetDWork(rtm, idx, val)     ((rtm)->dwork[idx] = (val))
#endif

#ifndef rtmGetOffsetTime
#define rtmGetOffsetTime(rtm, idx)     ((rtm)->Timing.offsetTimes[idx])
#endif

#ifndef rtmSetOffsetTime
#define rtmSetOffsetTime(rtm, idx, val) ((rtm)->Timing.offsetTimes[idx] = (val))
#endif

#ifndef rtmGetSFunction
#define rtmGetSFunction(rtm, idx)      ((rtm)->childSfunctions[idx])
#endif

#ifndef rtmSetSFunction
#define rtmSetSFunction(rtm, idx, val) ((rtm)->childSfunctions[idx] = (val))
#endif

#ifndef rtmGetSampleTime
#define rtmGetSampleTime(rtm, idx)     ((rtm)->Timing.sampleTimes[idx])
#endif

#ifndef rtmSetSampleTime
#define rtmSetSampleTime(rtm, idx, val) ((rtm)->Timing.sampleTimes[idx] = (val))
#endif

#ifndef rtmGetSampleTimeTaskID
#define rtmGetSampleTimeTaskID(rtm, idx) ((rtm)->Timing.sampleTimeTaskIDPtr[idx])
#endif

#ifndef rtmSetSampleTimeTaskID
#define rtmSetSampleTimeTaskID(rtm, idx, val) ((rtm)->Timing.sampleTimeTaskIDPtr[idx] = (val))
#endif

#ifndef rtmGetVarNextHitTimeList
#define rtmGetVarNextHitTimeList(rtm, idx) ((rtm)->Timing.varNextHitTimesList[idx])
#endif

#ifndef rtmSetVarNextHitTimeList
#define rtmSetVarNextHitTimeList(rtm, idx, val) ((rtm)->Timing.varNextHitTimesList[idx] = (val))
#endif

#ifndef rtmIsContinuousTask
#define rtmIsContinuousTask(rtm, tid)  ((tid) == 0)
#endif

#ifndef rtmGetErrorStatus
#define rtmGetErrorStatus(rtm)         ((rtm)->errorStatus)
#endif

#ifndef rtmSetErrorStatus
#define rtmSetErrorStatus(rtm, val)    ((rtm)->errorStatus = (val))
#endif

#ifndef rtmSetFirstInitCond
#define rtmSetFirstInitCond(rtm, val)  ((rtm)->Timing.firstInitCondFlag = (val))
#endif

#ifndef rtmIsFirstInitCond
#define rtmIsFirstInitCond(rtm)        ((rtm)->Timing.firstInitCondFlag)
#endif

#ifndef rtmIsMajorTimeStep
#define rtmIsMajorTimeStep(rtm)        (((rtm)->Timing.simTimeStep) == MAJOR_TIME_STEP)
#endif

#ifndef rtmIsMinorTimeStep
#define rtmIsMinorTimeStep(rtm)        (((rtm)->Timing.simTimeStep) == MINOR_TIME_STEP)
#endif

#ifndef rtmIsSampleHit
#define rtmIsSampleHit(rtm, sti, tid)  ((rtmIsMajorTimeStep((rtm)) && (rtm)->Timing.sampleHits[(rtm)->Timing.sampleTimeTaskIDPtr[sti]]))
#endif

#ifndef rtmGetStopRequested
#define rtmGetStopRequested(rtm)       ((rtm)->Timing.stopRequestedFlag)
#endif

#ifndef rtmSetStopRequested
#define rtmSetStopRequested(rtm, val)  ((rtm)->Timing.stopRequestedFlag = (val))
#endif

#ifndef rtmGetStopRequestedPtr
#define rtmGetStopRequestedPtr(rtm)    (&((rtm)->Timing.stopRequestedFlag))
#endif

#ifndef rtmGetT
#define rtmGetT(rtm)                   (rtmGetTPtr((rtm))[0])
#endif

#ifndef rtmSetT
#define rtmSetT(rtm, val)                                        /* Do Nothing */
#endif

#ifndef rtmGetTFinal
#define rtmGetTFinal(rtm)              ((rtm)->Timing.tFinal)
#endif

#ifndef rtmSetTFinal
#define rtmSetTFinal(rtm, val)         ((rtm)->Timing.tFinal = (val))
#endif

#ifndef rtmGetTPtr
#define rtmGetTPtr(rtm)                ((rtm)->Timing.t)
#endif

#ifndef rtmSetTPtr
#define rtmSetTPtr(rtm, val)           ((rtm)->Timing.t = (val))
#endif

#ifndef rtmGetTStart
#define rtmGetTStart(rtm)              ((rtm)->Timing.tStart)
#endif

#ifndef rtmSetTStart
#define rtmSetTStart(rtm, val)         ((rtm)->Timing.tStart = (val))
#endif

#ifndef rtmGetTaskTime
#define rtmGetTaskTime(rtm, sti)       (rtmGetTPtr((rtm))[(rtm)->Timing.sampleTimeTaskIDPtr[sti]])
#endif

#ifndef rtmSetTaskTime
#define rtmSetTaskTime(rtm, sti, val)  (rtmGetTPtr((rtm))[sti] = (val))
#endif

#ifndef rtmGetTimeOfLastOutput
#define rtmGetTimeOfLastOutput(rtm)    ((rtm)->Timing.timeOfLastOutput)
#endif

#ifdef rtmGetRTWSolverInfo
#undef rtmGetRTWSolverInfo
#endif

#define rtmGetRTWSolverInfo(rtm)       &((rtm)->solverInfo)

/* Definition for use in the target main file */
#define TrajRunner_rtModel             RT_MODEL_TrajRunner_T

/* Block signals (default storage) */
typedef struct {
  real_T HILReadTimebase1_o1;          /* '<S2>/HIL Read Timebase1' */
  real_T HILReadTimebase1_o2;          /* '<S2>/HIL Read Timebase1' */
  real_T HILReadTimebase1_o3;          /* '<S2>/HIL Read Timebase1' */
  real_T HILReadTimebase1_o4;          /* '<S2>/HIL Read Timebase1' */
  real_T grippercurrent;               /* '<S2>/HIL Read Timebase1' */
  real_T HILReadTimebase1_o6;          /* '<S2>/HIL Read Timebase1' */
  real_T HILReadTimebase1_o7;          /* '<S2>/HIL Read Timebase1' */
  real_T HILReadTimebase1_o8;          /* '<S2>/HIL Read Timebase1' */
  real_T HILReadTimebase1_o9;          /* '<S2>/HIL Read Timebase1' */
  real_T HILReadTimebase1_o10;         /* '<S2>/HIL Read Timebase1' */
  real_T HILReadTimebase1_o11;         /* '<S2>/HIL Read Timebase1' */
  real_T HILReadTimebase1_o12;         /* '<S2>/HIL Read Timebase1' */
  real_T HILReadTimebase1_o13;         /* '<S2>/HIL Read Timebase1' */
  real_T HILReadTimebase1_o14;         /* '<S2>/HIL Read Timebase1' */
  real_T HILReadTimebase1_o16;         /* '<S2>/HIL Read Timebase1' */
  real_T HILReadTimebase1_o17;         /* '<S2>/HIL Read Timebase1' */
  real_T HILReadTimebase1_o18;         /* '<S2>/HIL Read Timebase1' */
  real_T HILReadTimebase1_o19;         /* '<S2>/HIL Read Timebase1' */
  real_T HILReadTimebase1_o21;         /* '<S2>/HIL Read Timebase1' */
  real_T HILReadTimebase1_o22;         /* '<S2>/HIL Read Timebase1' */
  real_T HILReadTimebase1_o23;         /* '<S2>/HIL Read Timebase1' */
  real_T HILReadTimebase1_o24;         /* '<S2>/HIL Read Timebase1' */
  real_T SampleTime;                   /* '<Root>/Sample Time' */
  real_T ManualSwitch;                 /* '<Root>/Manual Switch' */
  real_T ManualSwitch1;                /* '<Root>/Manual Switch1' */
  real_T ManualSwitch3;                /* '<Root>/Manual Switch3' */
  real_T MAIN[4];                      /* '<Root>/MAIN' */
  real_T ManualSwitch5;                /* '<Root>/Manual Switch5' */
  real_T MAIN1[4];                     /* '<Root>/MAIN1' */
  real_T gripposition;                 /* '<S8>/Switch' */
  real_T x0;                           /* '<S9>/x0' */
  real_T Integrator1;                  /* '<S9>/Integrator1' */
  real_T goalcurrent;                  /* '<S8>/Soft-Grip Current (A)' */
  real_T Product;                      /* '<S9>/Product' */
  real_T Product1;                     /* '<S9>/Product1' */
  real_T Gain2;                        /* '<S8>/Gain2' */
  real_T phi[4];                       /* '<Root>/MATLAB Function2' */
  real_T p4[3];                        /* '<Root>/MATLAB Function1' */
  real_T v4[3];                        /* '<Root>/MATLAB Function1' */
} B_TrajRunner_T;

/* Block states (default storage) for system '<Root>' */
typedef struct {
  t_timeout SampleTime_PreviousTime;   /* '<Root>/Sample Time' */
  real_T HILInitializePositionMode_OOVal[13];
                                   /* '<Root>/HIL Initialize (Position Mode)' */
  real_T HILReadTimebase1_AnalogBuffer[5];/* '<S2>/HIL Read Timebase1' */
  real_T HILReadTimebase1_OtherBuffer[20];/* '<S2>/HIL Read Timebase1' */
  real_T HILWrite_OtherBuffer[13];     /* '<S2>/HIL Write' */
  real_T idx;                          /* '<Root>/MATLAB Function2' */
  real_T count;                        /* '<Root>/MATLAB Function2' */
  t_card HILInitializePositionMode_Card;
                                   /* '<Root>/HIL Initialize (Position Mode)' */
  t_task HILReadTimebase1_Task;        /* '<S2>/HIL Read Timebase1' */
  struct {
    real_T Amp;
    real_T W;
    real_T T;
    real_T Y;
  } Base_RWORK;                        /* '<Root>/Base' */

  struct {
    real_T Amp;
    real_T W;
    real_T T;
    real_T Y;
  } Shoulder_RWORK;                    /* '<Root>/Shoulder' */

  struct {
    real_T Amp;
    real_T W;
    real_T T;
    real_T Y;
  } Wrist_RWORK;                       /* '<Root>/Wrist' */

  struct {
    real_T Amp;
    real_T W;
    real_T Sin_w_dt;
    real_T Cos_w_dt;
    real_T Sin_w_t;
    real_T Cos_w_t;
  } SmoothSignalGenerator_RWORK;       /* '<S2>/Smooth Signal Generator' */

  struct {
    real_T Amp;
    real_T W;
    real_T T;
    real_T Y;
  } Elbow_RWORK;                       /* '<Root>/Elbow' */

  struct {
    void *LoggedData;
  } Scope1_PWORK;                      /* '<Root>/Scope1' */

  struct {
    void *LoggedData[6];
  } Measurements_PWORK;                /* '<Root>/Measurements' */

  struct {
    void *LoggedData[2];
  } Scope_PWORK;                       /* '<Root>/Scope' */

  void *HILWrite_PWORK;                /* '<S2>/HIL Write' */
  struct {
    void *LoggedData[2];
  } CurrentFilteration_PWORK;          /* '<S8>/Current Filteration' */

  struct {
    void *LoggedData[2];
  } GoalvsActualGripCurrent_PWORK;     /* '<S8>/Goal vs. Actual Grip Current' */

  int32_T HILInitializePositionMode_Clock;
                                   /* '<Root>/HIL Initialize (Position Mode)' */
  int32_T sfEvent;                     /* '<Root>/MATLAB Function2' */
  int32_T sfEvent_e;                   /* '<Root>/MATLAB Function1' */
  int32_T sfEvent_p;                   /* '<Root>/MATLAB Function' */
  boolean_T Integrator1_DWORK1;        /* '<S9>/Integrator1' */
  boolean_T doneDoubleBufferReInit;    /* '<Root>/MATLAB Function2' */
  boolean_T idx_not_empty;             /* '<Root>/MATLAB Function2' */
  boolean_T count_not_empty;           /* '<Root>/MATLAB Function2' */
  boolean_T doneDoubleBufferReInit_i;  /* '<Root>/MATLAB Function1' */
  boolean_T doneDoubleBufferReInit_n;  /* '<Root>/MATLAB Function' */
} DW_TrajRunner_T;

/* Continuous states (default storage) */
typedef struct {
  real_T Integrator_CSTATE;            /* '<S8>/Integrator' */
  real_T Integrator1_CSTATE;           /* '<S9>/Integrator1' */
  real_T Integrator2_CSTATE;           /* '<S9>/Integrator2' */
} X_TrajRunner_T;

/* State derivatives (default storage) */
typedef struct {
  real_T Integrator_CSTATE;            /* '<S8>/Integrator' */
  real_T Integrator1_CSTATE;           /* '<S9>/Integrator1' */
  real_T Integrator2_CSTATE;           /* '<S9>/Integrator2' */
} XDot_TrajRunner_T;

/* State disabled  */
typedef struct {
  boolean_T Integrator_CSTATE;         /* '<S8>/Integrator' */
  boolean_T Integrator1_CSTATE;        /* '<S9>/Integrator1' */
  boolean_T Integrator2_CSTATE;        /* '<S9>/Integrator2' */
} XDis_TrajRunner_T;

/* Zero-crossing (trigger) state */
typedef struct {
  ZCSigState Integrator_Reset_ZCE;     /* '<S8>/Integrator' */
} PrevZCX_TrajRunner_T;

#ifndef ODE4_INTG
#define ODE4_INTG

/* ODE4 Integration Data */
typedef struct {
  real_T *y;                           /* output */
  real_T *f[4];                        /* derivatives */
} ODE4_IntgData;

#endif

/* Backward compatible GRT Identifiers */
#define rtB                            TrajRunner_B
#define BlockIO                        B_TrajRunner_T
#define rtX                            TrajRunner_X
#define ContinuousStates               X_TrajRunner_T
#define rtXdot                         TrajRunner_XDot
#define StateDerivatives               XDot_TrajRunner_T
#define tXdis                          TrajRunner_XDis
#define StateDisabled                  XDis_TrajRunner_T
#define rtP                            TrajRunner_P
#define Parameters                     P_TrajRunner_T
#define rtDWork                        TrajRunner_DW
#define D_Work                         DW_TrajRunner_T
#define rtPrevZCSigState               TrajRunner_PrevZCX
#define PrevZCSigStates                PrevZCX_TrajRunner_T

/* Parameters (default storage) */
struct P_TrajRunner_T_ {
  real_T Ramp_InitialOutput;           /* Mask Parameter: Ramp_InitialOutput
                                        * Referenced by: '<S7>/Constant1'
                                        */
  real_T ColorConstant_color[3];       /* Mask Parameter: ColorConstant_color
                                        * Referenced by: '<S1>/Constant'
                                        */
  real_T undOrder25HzfilterbasedonFFT_in;
                              /* Mask Parameter: undOrder25HzfilterbasedonFFT_in
                               * Referenced by: '<S9>/wn'
                               */
  real_T undOrder25HzfilterbasedonFFT__a;
                              /* Mask Parameter: undOrder25HzfilterbasedonFFT__a
                               * Referenced by: '<S9>/zt'
                               */
  real_T Ramp_slope;                   /* Mask Parameter: Ramp_slope
                                        * Referenced by: '<S7>/Step'
                                        */
  real_T Ramp_start;                   /* Mask Parameter: Ramp_start
                                        * Referenced by:
                                        *   '<S7>/Constant'
                                        *   '<S7>/Step'
                                        */
  uint32_T HILWrite_other_channels[13];
                                      /* Mask Parameter: HILWrite_other_channels
                                       * Referenced by: '<S2>/HIL Write'
                                       */
  real_T Constant4_Value;              /* Expression: 0
                                        * Referenced by: '<Root>/Constant4'
                                        */
  real_T Constant8_Value;              /* Expression: 0
                                        * Referenced by: '<Root>/Constant8'
                                        */
  real_T CLOSE_Value;                  /* Expression: 1
                                        * Referenced by: '<Root>/CLOSE '
                                        */
  real_T OPEN_Value;                   /* Expression: 0
                                        * Referenced by: '<Root>/ OPEN'
                                        */
  real_T run_Value;                    /* Expression: 1
                                        * Referenced by: '<Root>/run'
                                        */
  real_T stop_Value;                   /* Expression: 0
                                        * Referenced by: '<Root>/stop'
                                        */
  real_T reverse_Value;                /* Expression: 1
                                        * Referenced by: '<Root>/reverse'
                                        */
  real_T forwards_Value;               /* Expression: 0
                                        * Referenced by: '<Root>/forwards'
                                        */
  real_T Constant2_Value;              /* Expression: 0
                                        * Referenced by: '<Root>/Constant2'
                                        */
  real_T HILInitializePositionMode_OOTer;
                                   /* Expression: set_other_outputs_at_terminate
                                    * Referenced by: '<Root>/HIL Initialize (Position Mode)'
                                    */
  real_T HILInitializePositionMode_OOExi;
                                  /* Expression: set_other_outputs_at_switch_out
                                   * Referenced by: '<Root>/HIL Initialize (Position Mode)'
                                   */
  real_T HILInitializePositionMode_OOSta;/* Expression: set_other_outputs_at_start
                                          * Referenced by: '<Root>/HIL Initialize (Position Mode)'
                                          */
  real_T HILInitializePositionMode_OOEnt;
                                   /* Expression: set_other_outputs_at_switch_in
                                    * Referenced by: '<Root>/HIL Initialize (Position Mode)'
                                    */
  real_T HILInitializePositionMode_AOFin;/* Expression: final_analog_outputs
                                          * Referenced by: '<Root>/HIL Initialize (Position Mode)'
                                          */
  real_T HILInitializePositionMode_OOFin[4];/* Expression: final_other_outputs
                                             * Referenced by: '<Root>/HIL Initialize (Position Mode)'
                                             */
  real_T HILInitializePositionMode_AOHig;/* Expression: analog_output_maximums
                                          * Referenced by: '<Root>/HIL Initialize (Position Mode)'
                                          */
  real_T HILInitializePositionMode_AOLow;/* Expression: analog_output_minimums
                                          * Referenced by: '<Root>/HIL Initialize (Position Mode)'
                                          */
  real_T HILInitializePositionMode_AOIni;/* Expression: initial_analog_outputs
                                          * Referenced by: '<Root>/HIL Initialize (Position Mode)'
                                          */
  real_T HILInitializePositionMode_OOIni[12];/* Expression: initial_other_outputs
                                              * Referenced by: '<Root>/HIL Initialize (Position Mode)'
                                              */
  real_T HILInitializePositionMode_OOWat[12];/* Expression: watchdog_other_outputs
                                              * Referenced by: '<Root>/HIL Initialize (Position Mode)'
                                              */
  real_T DefaultCmd_Value[4];          /* Expression: [0 0 0 0]
                                        * Referenced by: '<Root>/Default Cmd'
                                        */
  real_T Base_InitialPhase;            /* Expression: initial_phase
                                        * Referenced by: '<Root>/Base'
                                        */
  real_T Base_Amplitude;               /* Expression: i_amplitude
                                        * Referenced by: '<Root>/Base'
                                        */
  real_T Base_Frequency;               /* Expression: i_frequency
                                        * Referenced by: '<Root>/Base'
                                        */
  real_T Shoulder_InitialPhase;        /* Expression: initial_phase
                                        * Referenced by: '<Root>/Shoulder'
                                        */
  real_T Shoulder_Amplitude;           /* Expression: i_amplitude
                                        * Referenced by: '<Root>/Shoulder'
                                        */
  real_T Shoulder_Frequency;           /* Expression: i_frequency
                                        * Referenced by: '<Root>/Shoulder'
                                        */
  real_T Step_Y0;                      /* Expression: 0
                                        * Referenced by: '<S7>/Step'
                                        */
  real_T Constant6_Value;              /* Expression: -pi/2
                                        * Referenced by: '<Root>/Constant6'
                                        */
  real_T Wrist_InitialPhase;           /* Expression: initial_phase
                                        * Referenced by: '<Root>/Wrist'
                                        */
  real_T Wrist_Amplitude;              /* Expression: i_amplitude
                                        * Referenced by: '<Root>/Wrist'
                                        */
  real_T Wrist_Frequency;              /* Expression: i_frequency
                                        * Referenced by: '<Root>/Wrist'
                                        */
  real_T Constant_Value[3];            /* Expression: [0.4500 0 0.4500]
                                        * Referenced by: '<Root>/Constant'
                                        */
  real_T Constant12_Value[3];          /* Expression: [0 0 0]
                                        * Referenced by: '<Root>/Constant12'
                                        */
  real_T Constant5_Value[3];           /* Expression: [0.1 0.1 0.1]
                                        * Referenced by: '<Root>/Constant5'
                                        */
  real_T Constant11_Value[3];          /* Expression: [0.2 0.2 0.2]
                                        * Referenced by: '<Root>/Constant11'
                                        */
  real_T Constant13_Value[3];          /* Expression: [0.1 0.1 0.1]
                                        * Referenced by: '<Root>/Constant13'
                                        */
  real_T Constant1_Value[4];           /* Expression: [0 0 0 0]
                                        * Referenced by: '<Root>/Constant1'
                                        */
  real_T Constant15_Value[404];
  /* Expression: [0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0;-1.04709228628267 -1.0284199515082 -1.0096456553629 -0.99078025071788 -0.971834425392249 -0.952818667953098 -0.933743235632255 -0.914618124553628 -0.895453042427873 -0.876257383833672 -0.857040208167683 -0.837810220308976 -0.818575754009205 -0.799344757987352 -0.780124784678143 -0.760922981556506 -0.741746084936902 -0.722600416126287 -0.703491879792766 -0.684425964398722 -0.665407744537264 -0.646441885003966 -0.627532646431961 -0.608683892317165 -0.589899097261526 -0.571181356265357 -0.552533394904755 -0.533957580236555 -0.515455932280849 -0.497030135939616 -0.478681553219177 -0.46041123563374 -0.442219936677102 -0.424108124259327 -0.406075993014923 -0.388123476398341 -0.370250258491653 -0.352455785457721 -0.3347392765801 -0.317099734838247 -0.29953595697326 -0.282046543005345 -0.264629905169511 -0.247284276240539 -0.230007717222157 -0.212798124378511 -0.195653235588459 -0.178570636005007 -0.161547763003239 -0.144581910400481 -0.127670231932134 -0.110809743965547 -0.0939973274325981 -0.0772297289591123 -0.0605035611659891 -0.0438153021127725 -0.0271612938493659 -0.0105377400355459 0.00605929741920827 0.0226339027514769 0.0391903118409901 0.0557329188862888 0.072266284349605 0.0887951442772854 0.1053244211204 0.121859236201675 0.138404924000133 0.154967048454666 0.171551421523014 0.188164124274647 0.20481153084614 0.22150033564778 0.238237584282658 0.255030708727368 0.271887567430466 0.288816491116013 0.305826335241173 0.322926540257255 0.340127201073865 0.357439147440313 0.374874037356719 0.392444466135521 0.410164094388122 0.428047799060633 0.446111852755739 0.464374138051773 0.482854405503768 0.501574586685825 0.520559177305619 0.539835710533749 0.559435347918925 0.579393625656121 0.599751409210698 0.620556132100686 0.641863429561432 0.663739332729231 0.686263277934726 0.709532334788974 0.733667316674111 0.758821911820839 0.785196888499669;0.785443430115708 0.782915417526854 0.780090962548004 0.776971904741503 0.773560244084315 0.769858130942717 0.765867855480423 0.761591836590414 0.757032610441019 0.752192818725826 0.747075196704776 0.741682561120522 0.736017798069904 0.730083850905334 0.723883708235186 0.717420392086019 0.71069694628287 0.703716425096979 0.696481882203343 0.688996359983516 0.681262879202228 0.673284429079703 0.665063957775183 0.656604363291081 0.647908484801497 0.638979094403555 0.629818889285128 0.620430484298141 0.610816404922589 0.600979080602862 0.590920838434791 0.580643897178982 0.570150361573611 0.559442216917603 0.548521323893325 0.537389413596185 0.526048082737109 0.514498788982497 0.502742846395065 0.49078142093777 0.478615526001867 0.46624601791894 0.45367359141544 0.440898774966871 0.427921926007148 0.41474322594681 0.40136267495166 0.38778008643093 0.373995081181176 0.360007081128769 0.345815302609878 0.331418749122312 0.316816203478207 0.302006219280376 0.286987111637899 0.271756947028166 0.256313532202852 0.240654402023973 0.224776806103057 0.208677694101149 0.192353699529582 0.175801121870639 0.159015906812993 0.14199362436834 0.124729444602282 0.107218110673216 0.0894539088265761 0.0714306349368369 0.0531415571243617 0.0345793738962524 0.0157361671670228 -0.00339665059733565 -0.022828396003981 -0.0425691821832741 -0.0626299953219034 -0.083022781783178 -0.103760547622595 -0.124857472684126 -0.146329041933936 -0.16819219728094 -0.190465513884305 -0.21316940590636 -0.236326367902768 -0.259961259643439 -0.284101644257212 -0.308778192373779 -0.334025168659379 -0.359881022187863 -0.386389109014199 -0.413598584959735 -0.44156552025221 -0.470354307271479 -0.500039461386565 -0.530707957866486 -0.562462313702801 -0.595424726729338 -0.629742752154446 -0.665597277729352 -0.703214048834994 -0.742880889450097 -0.78497449050604;0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0]
   * Referenced by: '<Root>/Constant15'
   */
  real_T Constant16_Value;             /* Expression: 20
                                        * Referenced by: '<Root>/Constant16'
                                        */
  real_T Constant17_Value;             /* Expression: 100
                                        * Referenced by: '<Root>/Constant17'
                                        */
  real_T Constant7_Value;              /* Expression: qc_get_step_size
                                        * Referenced by: '<Root>/Constant7'
                                        */
  real_T Integrator_IC;                /* Expression: 0.1
                                        * Referenced by: '<S8>/Integrator'
                                        */
  real_T Integrator_UpperSat;          /* Expression: 0.9
                                        * Referenced by: '<S8>/Integrator'
                                        */
  real_T Integrator_LowerSat;          /* Expression: 0.1
                                        * Referenced by: '<S8>/Integrator'
                                        */
  real_T openposition_Value;           /* Expression: 0.1
                                        * Referenced by: '<S8>/open position'
                                        */
  real_T Switch_Threshold;             /* Expression: 0
                                        * Referenced by: '<S8>/Switch'
                                        */
  real_T SmoothSignalGenerator_InitialPh;/* Expression: initial_phase
                                          * Referenced by: '<S2>/Smooth Signal Generator'
                                          */
  real_T SmoothSignalGenerator_Amplitude;/* Expression: i_amplitude
                                          * Referenced by: '<S2>/Smooth Signal Generator'
                                          */
  real_T SmoothSignalGenerator_Frequency;/* Expression: i_frequency
                                          * Referenced by: '<S2>/Smooth Signal Generator'
                                          */
  real_T Bias_Bias;                    /* Expression: 0.5
                                        * Referenced by: '<S2>/Bias'
                                        */
  real_T x0_Value;                     /* Expression: input_init
                                        * Referenced by: '<S9>/x0'
                                        */
  real_T SoftGripCurrentA_Value;       /* Expression: 0.25
                                        * Referenced by: '<S8>/Soft-Grip Current (A)'
                                        */
  real_T Constant_Value_i;             /* Expression: 2
                                        * Referenced by: '<S9>/Constant'
                                        */
  real_T Integrator2_IC;               /* Expression: 0
                                        * Referenced by: '<S9>/Integrator2'
                                        */
  real_T Gain2_Gain;                   /* Expression: 10
                                        * Referenced by: '<S8>/Gain2'
                                        */
  real_T Elbow_InitialPhase;           /* Expression: initial_phase
                                        * Referenced by: '<Root>/Elbow'
                                        */
  real_T Elbow_Amplitude;              /* Expression: i_amplitude
                                        * Referenced by: '<Root>/Elbow'
                                        */
  real_T Elbow_Frequency;              /* Expression: i_frequency
                                        * Referenced by: '<Root>/Elbow'
                                        */
  int32_T HILInitializePositionMode_CKCha;
                          /* Computed Parameter: HILInitializePositionMode_CKCha
                           * Referenced by: '<Root>/HIL Initialize (Position Mode)'
                           */
  int32_T HILInitializePositionMode_DOWat;
                          /* Computed Parameter: HILInitializePositionMode_DOWat
                           * Referenced by: '<Root>/HIL Initialize (Position Mode)'
                           */
  int32_T HILReadTimebase1_Clock;  /* Computed Parameter: HILReadTimebase1_Clock
                                    * Referenced by: '<S2>/HIL Read Timebase1'
                                    */
  uint32_T HILInitializePositionMode_AICha[5];
                          /* Computed Parameter: HILInitializePositionMode_AICha
                           * Referenced by: '<Root>/HIL Initialize (Position Mode)'
                           */
  uint32_T HILInitializePositionMode_OOCha[13];
                          /* Computed Parameter: HILInitializePositionMode_OOCha
                           * Referenced by: '<Root>/HIL Initialize (Position Mode)'
                           */
  uint32_T HILReadTimebase1_SamplesInBuffe;
                          /* Computed Parameter: HILReadTimebase1_SamplesInBuffe
                           * Referenced by: '<S2>/HIL Read Timebase1'
                           */
  uint32_T HILReadTimebase1_AnalogChannels[5];
                          /* Computed Parameter: HILReadTimebase1_AnalogChannels
                           * Referenced by: '<S2>/HIL Read Timebase1'
                           */
  uint32_T HILReadTimebase1_OtherChannels[20];
                           /* Computed Parameter: HILReadTimebase1_OtherChannels
                            * Referenced by: '<S2>/HIL Read Timebase1'
                            */
  boolean_T HILInitializePositionMode_Activ;
                          /* Computed Parameter: HILInitializePositionMode_Activ
                           * Referenced by: '<Root>/HIL Initialize (Position Mode)'
                           */
  boolean_T HILInitializePositionMode_AOTer;
                          /* Computed Parameter: HILInitializePositionMode_AOTer
                           * Referenced by: '<Root>/HIL Initialize (Position Mode)'
                           */
  boolean_T HILInitializePositionMode_AOExi;
                          /* Computed Parameter: HILInitializePositionMode_AOExi
                           * Referenced by: '<Root>/HIL Initialize (Position Mode)'
                           */
  boolean_T HILInitializePositionMode_DOTer;
                          /* Computed Parameter: HILInitializePositionMode_DOTer
                           * Referenced by: '<Root>/HIL Initialize (Position Mode)'
                           */
  boolean_T HILInitializePositionMode_DOExi;
                          /* Computed Parameter: HILInitializePositionMode_DOExi
                           * Referenced by: '<Root>/HIL Initialize (Position Mode)'
                           */
  boolean_T HILInitializePositionMode_POTer;
                          /* Computed Parameter: HILInitializePositionMode_POTer
                           * Referenced by: '<Root>/HIL Initialize (Position Mode)'
                           */
  boolean_T HILInitializePositionMode_POExi;
                          /* Computed Parameter: HILInitializePositionMode_POExi
                           * Referenced by: '<Root>/HIL Initialize (Position Mode)'
                           */
  boolean_T HILInitializePositionMode_CKPSt;
                          /* Computed Parameter: HILInitializePositionMode_CKPSt
                           * Referenced by: '<Root>/HIL Initialize (Position Mode)'
                           */
  boolean_T HILInitializePositionMode_CKPEn;
                          /* Computed Parameter: HILInitializePositionMode_CKPEn
                           * Referenced by: '<Root>/HIL Initialize (Position Mode)'
                           */
  boolean_T HILInitializePositionMode_CKSta;
                          /* Computed Parameter: HILInitializePositionMode_CKSta
                           * Referenced by: '<Root>/HIL Initialize (Position Mode)'
                           */
  boolean_T HILInitializePositionMode_CKEnt;
                          /* Computed Parameter: HILInitializePositionMode_CKEnt
                           * Referenced by: '<Root>/HIL Initialize (Position Mode)'
                           */
  boolean_T HILInitializePositionMode_AIPSt;
                          /* Computed Parameter: HILInitializePositionMode_AIPSt
                           * Referenced by: '<Root>/HIL Initialize (Position Mode)'
                           */
  boolean_T HILInitializePositionMode_AIPEn;
                          /* Computed Parameter: HILInitializePositionMode_AIPEn
                           * Referenced by: '<Root>/HIL Initialize (Position Mode)'
                           */
  boolean_T HILInitializePositionMode_AOPSt;
                          /* Computed Parameter: HILInitializePositionMode_AOPSt
                           * Referenced by: '<Root>/HIL Initialize (Position Mode)'
                           */
  boolean_T HILInitializePositionMode_AOPEn;
                          /* Computed Parameter: HILInitializePositionMode_AOPEn
                           * Referenced by: '<Root>/HIL Initialize (Position Mode)'
                           */
  boolean_T HILInitializePositionMode_AOSta;
                          /* Computed Parameter: HILInitializePositionMode_AOSta
                           * Referenced by: '<Root>/HIL Initialize (Position Mode)'
                           */
  boolean_T HILInitializePositionMode_AOEnt;
                          /* Computed Parameter: HILInitializePositionMode_AOEnt
                           * Referenced by: '<Root>/HIL Initialize (Position Mode)'
                           */
  boolean_T HILInitializePositionMode_AORes;
                          /* Computed Parameter: HILInitializePositionMode_AORes
                           * Referenced by: '<Root>/HIL Initialize (Position Mode)'
                           */
  boolean_T HILInitializePositionMode_DOPSt;
                          /* Computed Parameter: HILInitializePositionMode_DOPSt
                           * Referenced by: '<Root>/HIL Initialize (Position Mode)'
                           */
  boolean_T HILInitializePositionMode_DOPEn;
                          /* Computed Parameter: HILInitializePositionMode_DOPEn
                           * Referenced by: '<Root>/HIL Initialize (Position Mode)'
                           */
  boolean_T HILInitializePositionMode_DOSta;
                          /* Computed Parameter: HILInitializePositionMode_DOSta
                           * Referenced by: '<Root>/HIL Initialize (Position Mode)'
                           */
  boolean_T HILInitializePositionMode_DOEnt;
                          /* Computed Parameter: HILInitializePositionMode_DOEnt
                           * Referenced by: '<Root>/HIL Initialize (Position Mode)'
                           */
  boolean_T HILInitializePositionMode_DORes;
                          /* Computed Parameter: HILInitializePositionMode_DORes
                           * Referenced by: '<Root>/HIL Initialize (Position Mode)'
                           */
  boolean_T HILInitializePositionMode_EIPSt;
                          /* Computed Parameter: HILInitializePositionMode_EIPSt
                           * Referenced by: '<Root>/HIL Initialize (Position Mode)'
                           */
  boolean_T HILInitializePositionMode_EIPEn;
                          /* Computed Parameter: HILInitializePositionMode_EIPEn
                           * Referenced by: '<Root>/HIL Initialize (Position Mode)'
                           */
  boolean_T HILInitializePositionMode_EISta;
                          /* Computed Parameter: HILInitializePositionMode_EISta
                           * Referenced by: '<Root>/HIL Initialize (Position Mode)'
                           */
  boolean_T HILInitializePositionMode_EIEnt;
                          /* Computed Parameter: HILInitializePositionMode_EIEnt
                           * Referenced by: '<Root>/HIL Initialize (Position Mode)'
                           */
  boolean_T HILInitializePositionMode_POPSt;
                          /* Computed Parameter: HILInitializePositionMode_POPSt
                           * Referenced by: '<Root>/HIL Initialize (Position Mode)'
                           */
  boolean_T HILInitializePositionMode_POPEn;
                          /* Computed Parameter: HILInitializePositionMode_POPEn
                           * Referenced by: '<Root>/HIL Initialize (Position Mode)'
                           */
  boolean_T HILInitializePositionMode_POSta;
                          /* Computed Parameter: HILInitializePositionMode_POSta
                           * Referenced by: '<Root>/HIL Initialize (Position Mode)'
                           */
  boolean_T HILInitializePositionMode_POEnt;
                          /* Computed Parameter: HILInitializePositionMode_POEnt
                           * Referenced by: '<Root>/HIL Initialize (Position Mode)'
                           */
  boolean_T HILInitializePositionMode_PORes;
                          /* Computed Parameter: HILInitializePositionMode_PORes
                           * Referenced by: '<Root>/HIL Initialize (Position Mode)'
                           */
  boolean_T HILInitializePositionMode_OORes;
                          /* Computed Parameter: HILInitializePositionMode_OORes
                           * Referenced by: '<Root>/HIL Initialize (Position Mode)'
                           */
  boolean_T HILInitializePositionMode_DOFin;
                          /* Computed Parameter: HILInitializePositionMode_DOFin
                           * Referenced by: '<Root>/HIL Initialize (Position Mode)'
                           */
  boolean_T HILInitializePositionMode_DOIni;
                          /* Computed Parameter: HILInitializePositionMode_DOIni
                           * Referenced by: '<Root>/HIL Initialize (Position Mode)'
                           */
  boolean_T HILReadTimebase1_Active;
                                  /* Computed Parameter: HILReadTimebase1_Active
                                   * Referenced by: '<S2>/HIL Read Timebase1'
                                   */
  boolean_T HILWrite_Active;           /* Computed Parameter: HILWrite_Active
                                        * Referenced by: '<S2>/HIL Write'
                                        */
  uint8_T ManualSwitch2_CurrentSetting;
                             /* Computed Parameter: ManualSwitch2_CurrentSetting
                              * Referenced by: '<Root>/Manual Switch2'
                              */
  uint8_T ManualSwitch4_CurrentSetting;
                             /* Computed Parameter: ManualSwitch4_CurrentSetting
                              * Referenced by: '<Root>/Manual Switch4'
                              */
  uint8_T HILReadTimebase1_OverflowMode;
                            /* Computed Parameter: HILReadTimebase1_OverflowMode
                             * Referenced by: '<S2>/HIL Read Timebase1'
                             */
  uint8_T ManualSwitch_CurrentSetting;
                              /* Computed Parameter: ManualSwitch_CurrentSetting
                               * Referenced by: '<Root>/Manual Switch'
                               */
  uint8_T ManualSwitch1_CurrentSetting;
                             /* Computed Parameter: ManualSwitch1_CurrentSetting
                              * Referenced by: '<Root>/Manual Switch1'
                              */
  uint8_T ManualSwitch3_CurrentSetting;
                             /* Computed Parameter: ManualSwitch3_CurrentSetting
                              * Referenced by: '<Root>/Manual Switch3'
                              */
  uint8_T MAIN_CurrentSetting;        /* Computed Parameter: MAIN_CurrentSetting
                                       * Referenced by: '<Root>/MAIN'
                                       */
  uint8_T ManualSwitch5_CurrentSetting;
                             /* Computed Parameter: ManualSwitch5_CurrentSetting
                              * Referenced by: '<Root>/Manual Switch5'
                              */
  uint8_T ManualSwitch6_CurrentSetting;
                             /* Computed Parameter: ManualSwitch6_CurrentSetting
                              * Referenced by: '<Root>/Manual Switch6'
                              */
  uint8_T ManualSwitch7_CurrentSetting;
                             /* Computed Parameter: ManualSwitch7_CurrentSetting
                              * Referenced by: '<Root>/Manual Switch7'
                              */
  uint8_T MAIN1_CurrentSetting;      /* Computed Parameter: MAIN1_CurrentSetting
                                      * Referenced by: '<Root>/MAIN1'
                                      */
};

/* Real-time Model Data Structure */
struct tag_RTM_TrajRunner_T {
  const char_T *path;
  const char_T *modelName;
  struct SimStruct_tag * *childSfunctions;
  const char_T *errorStatus;
  SS_SimMode simMode;
  RTWExtModeInfo *extModeInfo;
  RTWSolverInfo solverInfo;
  RTWSolverInfo *solverInfoPtr;
  void *sfcnInfo;
  void *blockIO;
  const void *constBlockIO;
  void *defaultParam;
  ZCSigState *prevZCSigState;
  real_T *contStates;
  int_T *periodicContStateIndices;
  real_T *periodicContStateRanges;
  real_T *derivs;
  void *zcSignalValues;
  void *inputs;
  void *outputs;
  boolean_T *contStateDisabled;
  boolean_T zCCacheNeedsReset;
  boolean_T derivCacheNeedsReset;
  boolean_T CTOutputIncnstWithState;
  real_T odeY[3];
  real_T odeF[4][3];
  ODE4_IntgData intgData;
  void *dwork;

  /*
   * Sizes:
   * The following substructure contains sizes information
   * for many of the model attributes such as inputs, outputs,
   * dwork, sample times, etc.
   */
  struct {
    uint32_T checksums[4];
    uint32_T options;
    int_T numContStates;
    int_T numPeriodicContStates;
    int_T numU;
    int_T numY;
    int_T numSampTimes;
    int_T numBlocks;
    int_T numBlockIO;
    int_T numBlockPrms;
    int_T numDwork;
    int_T numSFcnPrms;
    int_T numSFcns;
    int_T numIports;
    int_T numOports;
    int_T numNonSampZCs;
    int_T sysDirFeedThru;
    int_T rtwGenSfcn;
  } Sizes;

  /*
   * SpecialInfo:
   * The following substructure contains special information
   * related to other components that are dependent on RTW.
   */
  struct {
    const void *mappingInfo;
    void *xpcData;
  } SpecialInfo;

  /*
   * Timing:
   * The following substructure contains information regarding
   * the timing information for the model.
   */
  struct {
    time_T stepSize;
    uint32_T clockTick0;
    uint32_T clockTickH0;
    time_T stepSize0;
    uint32_T clockTick1;
    uint32_T clockTickH1;
    time_T stepSize1;
    boolean_T firstInitCondFlag;
    time_T tStart;
    time_T tFinal;
    time_T timeOfLastOutput;
    void *timingData;
    real_T *varNextHitTimesList;
    SimTimeStep simTimeStep;
    boolean_T stopRequestedFlag;
    time_T *sampleTimes;
    time_T *offsetTimes;
    int_T *sampleTimeTaskIDPtr;
    int_T *sampleHits;
    int_T *perTaskSampleHits;
    time_T *t;
    time_T sampleTimesArray[2];
    time_T offsetTimesArray[2];
    int_T sampleTimeTaskIDArray[2];
    int_T sampleHitArray[2];
    int_T perTaskSampleHitsArray[4];
    time_T tArray[2];
  } Timing;
};

/* Block parameters (default storage) */
extern P_TrajRunner_T TrajRunner_P;

/* Block signals (default storage) */
extern B_TrajRunner_T TrajRunner_B;

/* Continuous states (default storage) */
extern X_TrajRunner_T TrajRunner_X;

/* Disabled states (default storage) */
extern XDis_TrajRunner_T TrajRunner_XDis;

/* Block states (default storage) */
extern DW_TrajRunner_T TrajRunner_DW;

/* Zero-crossing (trigger) state */
extern PrevZCX_TrajRunner_T TrajRunner_PrevZCX;

/* Model entry point functions */
extern void TrajRunner_initialize(void);
extern void TrajRunner_output(void);
extern void TrajRunner_update(void);
extern void TrajRunner_terminate(void);

/*====================*
 * External functions *
 *====================*/
extern TrajRunner_rtModel *TrajRunner(void);
extern void MdlInitializeSizes(void);
extern void MdlInitializeSampleTimes(void);
extern void MdlInitialize(void);
extern void MdlStart(void);
extern void MdlOutputs(int_T tid);
extern void MdlUpdate(int_T tid);
extern void MdlTerminate(void);

/* Real-time Model object */
extern RT_MODEL_TrajRunner_T *const TrajRunner_M;

/*-
 * The generated code includes comments that allow you to trace directly
 * back to the appropriate location in the model.  The basic format
 * is <system>/block_name, where system is the system number (uniquely
 * assigned by Simulink) and block_name is the name of the block.
 *
 * Use the MATLAB hilite_system command to trace the generated code back
 * to the model.  For example,
 *
 * hilite_system('<S3>')    - opens system 3
 * hilite_system('<S3>/Kp') - opens and selects block Kp which resides in S3
 *
 * Here is the system hierarchy for this model
 *
 * '<Root>' : 'TrajRunner'
 * '<S1>'   : 'TrajRunner/Color Constant'
 * '<S2>'   : 'TrajRunner/Hardware Plant P(s)'
 * '<S3>'   : 'TrajRunner/MATLAB Function'
 * '<S4>'   : 'TrajRunner/MATLAB Function1'
 * '<S5>'   : 'TrajRunner/MATLAB Function2'
 * '<S6>'   : 'TrajRunner/Powered by QUARC'
 * '<S7>'   : 'TrajRunner/Ramp'
 * '<S8>'   : 'TrajRunner/Hardware Plant P(s)/Gripper Control'
 * '<S9>'   : 'TrajRunner/Hardware Plant P(s)/Gripper Control/2nd Order 25Hz filter (based on FFT)'
 */
#endif                                 /* TrajRunner_h_ */
