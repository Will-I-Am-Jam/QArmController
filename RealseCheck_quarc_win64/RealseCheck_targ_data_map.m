    function targMap = targDataMap(),

    ;%***********************
    ;% Create Parameter Map *
    ;%***********************
    
        nTotData      = 0; %add to this count as we go
        nTotSects     = 7;
        sectIdxOffset = 0;

        ;%
        ;% Define dummy sections & preallocate arrays
        ;%
        dumSection.nData = -1;
        dumSection.data  = [];

        dumData.logicalSrcIdx = -1;
        dumData.dtTransOffset = -1;

        ;%
        ;% Init/prealloc paramMap
        ;%
        paramMap.nSections           = nTotSects;
        paramMap.sectIdxOffset       = sectIdxOffset;
            paramMap.sections(nTotSects) = dumSection; %prealloc
        paramMap.nTotData            = -1;

        ;%
        ;% Auto data (RealseCheck_P)
        ;%
            section.nData     = 3;
            section.data(3)  = dumData; %prealloc

                    ;% RealseCheck_P.ColorConstant_color
                    section.data(1).logicalSrcIdx = 0;
                    section.data(1).dtTransOffset = 0;

                    ;% RealseCheck_P.undOrder25HzfilterbasedonFFT_in
                    section.data(2).logicalSrcIdx = 1;
                    section.data(2).dtTransOffset = 3;

                    ;% RealseCheck_P.undOrder25HzfilterbasedonFFT__a
                    section.data(3).logicalSrcIdx = 2;
                    section.data(3).dtTransOffset = 4;

            nTotData = nTotData + section.nData;
            paramMap.sections(1) = section;
            clear section

            section.nData     = 1;
            section.data(1)  = dumData; %prealloc

                    ;% RealseCheck_P.HILWrite_other_channels
                    section.data(1).logicalSrcIdx = 3;
                    section.data(1).dtTransOffset = 0;

            nTotData = nTotData + section.nData;
            paramMap.sections(2) = section;
            clear section

            section.nData     = 51;
            section.data(51)  = dumData; %prealloc

                    ;% RealseCheck_P.DefaultCmd_Value
                    section.data(1).logicalSrcIdx = 4;
                    section.data(1).dtTransOffset = 0;

                    ;% RealseCheck_P.Constant4_Value
                    section.data(2).logicalSrcIdx = 5;
                    section.data(2).dtTransOffset = 4;

                    ;% RealseCheck_P.offset_Value
                    section.data(3).logicalSrcIdx = 6;
                    section.data(3).dtTransOffset = 5;

                    ;% RealseCheck_P.Constant6_Value
                    section.data(4).logicalSrcIdx = 7;
                    section.data(4).dtTransOffset = 6;

                    ;% RealseCheck_P.Constant8_Value
                    section.data(5).logicalSrcIdx = 8;
                    section.data(5).dtTransOffset = 7;

                    ;% RealseCheck_P.Constant2_Value
                    section.data(6).logicalSrcIdx = 9;
                    section.data(6).dtTransOffset = 8;

                    ;% RealseCheck_P.CLOSE_Value
                    section.data(7).logicalSrcIdx = 10;
                    section.data(7).dtTransOffset = 9;

                    ;% RealseCheck_P.OPEN_Value
                    section.data(8).logicalSrcIdx = 11;
                    section.data(8).dtTransOffset = 10;

                    ;% RealseCheck_P.HILInitializePositionMode_OOTer
                    section.data(9).logicalSrcIdx = 12;
                    section.data(9).dtTransOffset = 11;

                    ;% RealseCheck_P.HILInitializePositionMode_OOExi
                    section.data(10).logicalSrcIdx = 13;
                    section.data(10).dtTransOffset = 12;

                    ;% RealseCheck_P.HILInitializePositionMode_OOSta
                    section.data(11).logicalSrcIdx = 14;
                    section.data(11).dtTransOffset = 13;

                    ;% RealseCheck_P.HILInitializePositionMode_OOEnt
                    section.data(12).logicalSrcIdx = 15;
                    section.data(12).dtTransOffset = 14;

                    ;% RealseCheck_P.HILInitializePositionMode_AOFin
                    section.data(13).logicalSrcIdx = 16;
                    section.data(13).dtTransOffset = 15;

                    ;% RealseCheck_P.HILInitializePositionMode_OOFin
                    section.data(14).logicalSrcIdx = 17;
                    section.data(14).dtTransOffset = 16;

                    ;% RealseCheck_P.HILInitializePositionMode_AOHig
                    section.data(15).logicalSrcIdx = 18;
                    section.data(15).dtTransOffset = 20;

                    ;% RealseCheck_P.HILInitializePositionMode_AOLow
                    section.data(16).logicalSrcIdx = 19;
                    section.data(16).dtTransOffset = 21;

                    ;% RealseCheck_P.HILInitializePositionMode_AOIni
                    section.data(17).logicalSrcIdx = 20;
                    section.data(17).dtTransOffset = 22;

                    ;% RealseCheck_P.HILInitializePositionMode_OOIni
                    section.data(18).logicalSrcIdx = 21;
                    section.data(18).dtTransOffset = 23;

                    ;% RealseCheck_P.HILInitializePositionMode_OOWat
                    section.data(19).logicalSrcIdx = 22;
                    section.data(19).dtTransOffset = 35;

                    ;% RealseCheck_P.Base_InitialPhase
                    section.data(20).logicalSrcIdx = 23;
                    section.data(20).dtTransOffset = 47;

                    ;% RealseCheck_P.Base_Amplitude
                    section.data(21).logicalSrcIdx = 24;
                    section.data(21).dtTransOffset = 48;

                    ;% RealseCheck_P.Base_Frequency
                    section.data(22).logicalSrcIdx = 25;
                    section.data(22).dtTransOffset = 49;

                    ;% RealseCheck_P.Shoulder_InitialPhase
                    section.data(23).logicalSrcIdx = 26;
                    section.data(23).dtTransOffset = 50;

                    ;% RealseCheck_P.Shoulder_Amplitude
                    section.data(24).logicalSrcIdx = 27;
                    section.data(24).dtTransOffset = 51;

                    ;% RealseCheck_P.Shoulder_Frequency
                    section.data(25).logicalSrcIdx = 28;
                    section.data(25).dtTransOffset = 52;

                    ;% RealseCheck_P.Elbow_InitialPhase
                    section.data(26).logicalSrcIdx = 29;
                    section.data(26).dtTransOffset = 53;

                    ;% RealseCheck_P.Elbow_Amplitude
                    section.data(27).logicalSrcIdx = 30;
                    section.data(27).dtTransOffset = 54;

                    ;% RealseCheck_P.Elbow_Frequency
                    section.data(28).logicalSrcIdx = 31;
                    section.data(28).dtTransOffset = 55;

                    ;% RealseCheck_P.Wrist_InitialPhase
                    section.data(29).logicalSrcIdx = 32;
                    section.data(29).dtTransOffset = 56;

                    ;% RealseCheck_P.Wrist_Amplitude
                    section.data(30).logicalSrcIdx = 33;
                    section.data(30).dtTransOffset = 57;

                    ;% RealseCheck_P.Wrist_Frequency
                    section.data(31).logicalSrcIdx = 34;
                    section.data(31).dtTransOffset = 58;

                    ;% RealseCheck_P.Constant_Value
                    section.data(32).logicalSrcIdx = 35;
                    section.data(32).dtTransOffset = 59;

                    ;% RealseCheck_P.Constant12_Value
                    section.data(33).logicalSrcIdx = 36;
                    section.data(33).dtTransOffset = 62;

                    ;% RealseCheck_P.Constant5_Value
                    section.data(34).logicalSrcIdx = 37;
                    section.data(34).dtTransOffset = 65;

                    ;% RealseCheck_P.Constant11_Value
                    section.data(35).logicalSrcIdx = 38;
                    section.data(35).dtTransOffset = 68;

                    ;% RealseCheck_P.Constant13_Value
                    section.data(36).logicalSrcIdx = 39;
                    section.data(36).dtTransOffset = 71;

                    ;% RealseCheck_P.Constant1_Value
                    section.data(37).logicalSrcIdx = 40;
                    section.data(37).dtTransOffset = 74;

                    ;% RealseCheck_P.Integrator_IC
                    section.data(38).logicalSrcIdx = 41;
                    section.data(38).dtTransOffset = 78;

                    ;% RealseCheck_P.Integrator_UpperSat
                    section.data(39).logicalSrcIdx = 42;
                    section.data(39).dtTransOffset = 79;

                    ;% RealseCheck_P.Integrator_LowerSat
                    section.data(40).logicalSrcIdx = 43;
                    section.data(40).dtTransOffset = 80;

                    ;% RealseCheck_P.openposition_Value
                    section.data(41).logicalSrcIdx = 44;
                    section.data(41).dtTransOffset = 81;

                    ;% RealseCheck_P.Switch_Threshold
                    section.data(42).logicalSrcIdx = 45;
                    section.data(42).dtTransOffset = 82;

                    ;% RealseCheck_P.SmoothSignalGenerator_InitialPh
                    section.data(43).logicalSrcIdx = 46;
                    section.data(43).dtTransOffset = 83;

                    ;% RealseCheck_P.SmoothSignalGenerator_Amplitude
                    section.data(44).logicalSrcIdx = 47;
                    section.data(44).dtTransOffset = 84;

                    ;% RealseCheck_P.SmoothSignalGenerator_Frequency
                    section.data(45).logicalSrcIdx = 48;
                    section.data(45).dtTransOffset = 85;

                    ;% RealseCheck_P.Bias_Bias
                    section.data(46).logicalSrcIdx = 49;
                    section.data(46).dtTransOffset = 86;

                    ;% RealseCheck_P.x0_Value
                    section.data(47).logicalSrcIdx = 50;
                    section.data(47).dtTransOffset = 87;

                    ;% RealseCheck_P.SoftGripCurrentA_Value
                    section.data(48).logicalSrcIdx = 51;
                    section.data(48).dtTransOffset = 88;

                    ;% RealseCheck_P.Constant_Value_i
                    section.data(49).logicalSrcIdx = 52;
                    section.data(49).dtTransOffset = 89;

                    ;% RealseCheck_P.Integrator2_IC
                    section.data(50).logicalSrcIdx = 53;
                    section.data(50).dtTransOffset = 90;

                    ;% RealseCheck_P.Gain2_Gain
                    section.data(51).logicalSrcIdx = 54;
                    section.data(51).dtTransOffset = 91;

            nTotData = nTotData + section.nData;
            paramMap.sections(3) = section;
            clear section

            section.nData     = 3;
            section.data(3)  = dumData; %prealloc

                    ;% RealseCheck_P.HILInitializePositionMode_CKCha
                    section.data(1).logicalSrcIdx = 55;
                    section.data(1).dtTransOffset = 0;

                    ;% RealseCheck_P.HILInitializePositionMode_DOWat
                    section.data(2).logicalSrcIdx = 56;
                    section.data(2).dtTransOffset = 1;

                    ;% RealseCheck_P.HILReadTimebase1_Clock
                    section.data(3).logicalSrcIdx = 57;
                    section.data(3).dtTransOffset = 2;

            nTotData = nTotData + section.nData;
            paramMap.sections(4) = section;
            clear section

            section.nData     = 5;
            section.data(5)  = dumData; %prealloc

                    ;% RealseCheck_P.HILInitializePositionMode_AICha
                    section.data(1).logicalSrcIdx = 58;
                    section.data(1).dtTransOffset = 0;

                    ;% RealseCheck_P.HILInitializePositionMode_OOCha
                    section.data(2).logicalSrcIdx = 59;
                    section.data(2).dtTransOffset = 5;

                    ;% RealseCheck_P.HILReadTimebase1_SamplesInBuffe
                    section.data(3).logicalSrcIdx = 60;
                    section.data(3).dtTransOffset = 18;

                    ;% RealseCheck_P.HILReadTimebase1_AnalogChannels
                    section.data(4).logicalSrcIdx = 61;
                    section.data(4).dtTransOffset = 19;

                    ;% RealseCheck_P.HILReadTimebase1_OtherChannels
                    section.data(5).logicalSrcIdx = 62;
                    section.data(5).dtTransOffset = 24;

            nTotData = nTotData + section.nData;
            paramMap.sections(5) = section;
            clear section

            section.nData     = 37;
            section.data(37)  = dumData; %prealloc

                    ;% RealseCheck_P.HILInitializePositionMode_Activ
                    section.data(1).logicalSrcIdx = 63;
                    section.data(1).dtTransOffset = 0;

                    ;% RealseCheck_P.HILInitializePositionMode_AOTer
                    section.data(2).logicalSrcIdx = 64;
                    section.data(2).dtTransOffset = 1;

                    ;% RealseCheck_P.HILInitializePositionMode_AOExi
                    section.data(3).logicalSrcIdx = 65;
                    section.data(3).dtTransOffset = 2;

                    ;% RealseCheck_P.HILInitializePositionMode_DOTer
                    section.data(4).logicalSrcIdx = 66;
                    section.data(4).dtTransOffset = 3;

                    ;% RealseCheck_P.HILInitializePositionMode_DOExi
                    section.data(5).logicalSrcIdx = 67;
                    section.data(5).dtTransOffset = 4;

                    ;% RealseCheck_P.HILInitializePositionMode_POTer
                    section.data(6).logicalSrcIdx = 68;
                    section.data(6).dtTransOffset = 5;

                    ;% RealseCheck_P.HILInitializePositionMode_POExi
                    section.data(7).logicalSrcIdx = 69;
                    section.data(7).dtTransOffset = 6;

                    ;% RealseCheck_P.HILInitializePositionMode_CKPSt
                    section.data(8).logicalSrcIdx = 70;
                    section.data(8).dtTransOffset = 7;

                    ;% RealseCheck_P.HILInitializePositionMode_CKPEn
                    section.data(9).logicalSrcIdx = 71;
                    section.data(9).dtTransOffset = 8;

                    ;% RealseCheck_P.HILInitializePositionMode_CKSta
                    section.data(10).logicalSrcIdx = 72;
                    section.data(10).dtTransOffset = 9;

                    ;% RealseCheck_P.HILInitializePositionMode_CKEnt
                    section.data(11).logicalSrcIdx = 73;
                    section.data(11).dtTransOffset = 10;

                    ;% RealseCheck_P.HILInitializePositionMode_AIPSt
                    section.data(12).logicalSrcIdx = 74;
                    section.data(12).dtTransOffset = 11;

                    ;% RealseCheck_P.HILInitializePositionMode_AIPEn
                    section.data(13).logicalSrcIdx = 75;
                    section.data(13).dtTransOffset = 12;

                    ;% RealseCheck_P.HILInitializePositionMode_AOPSt
                    section.data(14).logicalSrcIdx = 76;
                    section.data(14).dtTransOffset = 13;

                    ;% RealseCheck_P.HILInitializePositionMode_AOPEn
                    section.data(15).logicalSrcIdx = 77;
                    section.data(15).dtTransOffset = 14;

                    ;% RealseCheck_P.HILInitializePositionMode_AOSta
                    section.data(16).logicalSrcIdx = 78;
                    section.data(16).dtTransOffset = 15;

                    ;% RealseCheck_P.HILInitializePositionMode_AOEnt
                    section.data(17).logicalSrcIdx = 79;
                    section.data(17).dtTransOffset = 16;

                    ;% RealseCheck_P.HILInitializePositionMode_AORes
                    section.data(18).logicalSrcIdx = 80;
                    section.data(18).dtTransOffset = 17;

                    ;% RealseCheck_P.HILInitializePositionMode_DOPSt
                    section.data(19).logicalSrcIdx = 81;
                    section.data(19).dtTransOffset = 18;

                    ;% RealseCheck_P.HILInitializePositionMode_DOPEn
                    section.data(20).logicalSrcIdx = 82;
                    section.data(20).dtTransOffset = 19;

                    ;% RealseCheck_P.HILInitializePositionMode_DOSta
                    section.data(21).logicalSrcIdx = 83;
                    section.data(21).dtTransOffset = 20;

                    ;% RealseCheck_P.HILInitializePositionMode_DOEnt
                    section.data(22).logicalSrcIdx = 84;
                    section.data(22).dtTransOffset = 21;

                    ;% RealseCheck_P.HILInitializePositionMode_DORes
                    section.data(23).logicalSrcIdx = 85;
                    section.data(23).dtTransOffset = 22;

                    ;% RealseCheck_P.HILInitializePositionMode_EIPSt
                    section.data(24).logicalSrcIdx = 86;
                    section.data(24).dtTransOffset = 23;

                    ;% RealseCheck_P.HILInitializePositionMode_EIPEn
                    section.data(25).logicalSrcIdx = 87;
                    section.data(25).dtTransOffset = 24;

                    ;% RealseCheck_P.HILInitializePositionMode_EISta
                    section.data(26).logicalSrcIdx = 88;
                    section.data(26).dtTransOffset = 25;

                    ;% RealseCheck_P.HILInitializePositionMode_EIEnt
                    section.data(27).logicalSrcIdx = 89;
                    section.data(27).dtTransOffset = 26;

                    ;% RealseCheck_P.HILInitializePositionMode_POPSt
                    section.data(28).logicalSrcIdx = 90;
                    section.data(28).dtTransOffset = 27;

                    ;% RealseCheck_P.HILInitializePositionMode_POPEn
                    section.data(29).logicalSrcIdx = 91;
                    section.data(29).dtTransOffset = 28;

                    ;% RealseCheck_P.HILInitializePositionMode_POSta
                    section.data(30).logicalSrcIdx = 92;
                    section.data(30).dtTransOffset = 29;

                    ;% RealseCheck_P.HILInitializePositionMode_POEnt
                    section.data(31).logicalSrcIdx = 93;
                    section.data(31).dtTransOffset = 30;

                    ;% RealseCheck_P.HILInitializePositionMode_PORes
                    section.data(32).logicalSrcIdx = 94;
                    section.data(32).dtTransOffset = 31;

                    ;% RealseCheck_P.HILInitializePositionMode_OORes
                    section.data(33).logicalSrcIdx = 95;
                    section.data(33).dtTransOffset = 32;

                    ;% RealseCheck_P.HILInitializePositionMode_DOFin
                    section.data(34).logicalSrcIdx = 96;
                    section.data(34).dtTransOffset = 33;

                    ;% RealseCheck_P.HILInitializePositionMode_DOIni
                    section.data(35).logicalSrcIdx = 97;
                    section.data(35).dtTransOffset = 34;

                    ;% RealseCheck_P.HILReadTimebase1_Active
                    section.data(36).logicalSrcIdx = 98;
                    section.data(36).dtTransOffset = 35;

                    ;% RealseCheck_P.HILWrite_Active
                    section.data(37).logicalSrcIdx = 99;
                    section.data(37).dtTransOffset = 36;

            nTotData = nTotData + section.nData;
            paramMap.sections(6) = section;
            clear section

            section.nData     = 8;
            section.data(8)  = dumData; %prealloc

                    ;% RealseCheck_P.ManualSwitch_CurrentSetting
                    section.data(1).logicalSrcIdx = 100;
                    section.data(1).dtTransOffset = 0;

                    ;% RealseCheck_P.ManualSwitch1_CurrentSetting
                    section.data(2).logicalSrcIdx = 101;
                    section.data(2).dtTransOffset = 1;

                    ;% RealseCheck_P.ManualSwitch2_CurrentSetting
                    section.data(3).logicalSrcIdx = 102;
                    section.data(3).dtTransOffset = 2;

                    ;% RealseCheck_P.ManualSwitch3_CurrentSetting
                    section.data(4).logicalSrcIdx = 103;
                    section.data(4).dtTransOffset = 3;

                    ;% RealseCheck_P.ManualSwitch4_CurrentSetting
                    section.data(5).logicalSrcIdx = 104;
                    section.data(5).dtTransOffset = 4;

                    ;% RealseCheck_P.HILReadTimebase1_OverflowMode
                    section.data(6).logicalSrcIdx = 105;
                    section.data(6).dtTransOffset = 5;

                    ;% RealseCheck_P.MAIN_CurrentSetting
                    section.data(7).logicalSrcIdx = 106;
                    section.data(7).dtTransOffset = 6;

                    ;% RealseCheck_P.ManualSwitch5_CurrentSetting
                    section.data(8).logicalSrcIdx = 107;
                    section.data(8).dtTransOffset = 7;

            nTotData = nTotData + section.nData;
            paramMap.sections(7) = section;
            clear section


            ;%
            ;% Non-auto Data (parameter)
            ;%


        ;%
        ;% Add final counts to struct.
        ;%
        paramMap.nTotData = nTotData;



    ;%**************************
    ;% Create Block Output Map *
    ;%**************************
    
        nTotData      = 0; %add to this count as we go
        nTotSects     = 1;
        sectIdxOffset = 0;

        ;%
        ;% Define dummy sections & preallocate arrays
        ;%
        dumSection.nData = -1;
        dumSection.data  = [];

        dumData.logicalSrcIdx = -1;
        dumData.dtTransOffset = -1;

        ;%
        ;% Init/prealloc sigMap
        ;%
        sigMap.nSections           = nTotSects;
        sigMap.sectIdxOffset       = sectIdxOffset;
            sigMap.sections(nTotSects) = dumSection; %prealloc
        sigMap.nTotData            = -1;

        ;%
        ;% Auto data (RealseCheck_B)
        ;%
            section.nData     = 34;
            section.data(34)  = dumData; %prealloc

                    ;% RealseCheck_B.HILReadTimebase1_o1
                    section.data(1).logicalSrcIdx = 0;
                    section.data(1).dtTransOffset = 0;

                    ;% RealseCheck_B.HILReadTimebase1_o2
                    section.data(2).logicalSrcIdx = 1;
                    section.data(2).dtTransOffset = 1;

                    ;% RealseCheck_B.HILReadTimebase1_o3
                    section.data(3).logicalSrcIdx = 2;
                    section.data(3).dtTransOffset = 2;

                    ;% RealseCheck_B.HILReadTimebase1_o4
                    section.data(4).logicalSrcIdx = 3;
                    section.data(4).dtTransOffset = 3;

                    ;% RealseCheck_B.grippercurrent
                    section.data(5).logicalSrcIdx = 4;
                    section.data(5).dtTransOffset = 4;

                    ;% RealseCheck_B.HILReadTimebase1_o6
                    section.data(6).logicalSrcIdx = 5;
                    section.data(6).dtTransOffset = 5;

                    ;% RealseCheck_B.HILReadTimebase1_o7
                    section.data(7).logicalSrcIdx = 6;
                    section.data(7).dtTransOffset = 6;

                    ;% RealseCheck_B.HILReadTimebase1_o8
                    section.data(8).logicalSrcIdx = 7;
                    section.data(8).dtTransOffset = 7;

                    ;% RealseCheck_B.HILReadTimebase1_o9
                    section.data(9).logicalSrcIdx = 8;
                    section.data(9).dtTransOffset = 8;

                    ;% RealseCheck_B.HILReadTimebase1_o10
                    section.data(10).logicalSrcIdx = 9;
                    section.data(10).dtTransOffset = 9;

                    ;% RealseCheck_B.HILReadTimebase1_o11
                    section.data(11).logicalSrcIdx = 10;
                    section.data(11).dtTransOffset = 10;

                    ;% RealseCheck_B.HILReadTimebase1_o12
                    section.data(12).logicalSrcIdx = 11;
                    section.data(12).dtTransOffset = 11;

                    ;% RealseCheck_B.HILReadTimebase1_o13
                    section.data(13).logicalSrcIdx = 12;
                    section.data(13).dtTransOffset = 12;

                    ;% RealseCheck_B.HILReadTimebase1_o14
                    section.data(14).logicalSrcIdx = 13;
                    section.data(14).dtTransOffset = 13;

                    ;% RealseCheck_B.HILReadTimebase1_o16
                    section.data(15).logicalSrcIdx = 14;
                    section.data(15).dtTransOffset = 14;

                    ;% RealseCheck_B.HILReadTimebase1_o17
                    section.data(16).logicalSrcIdx = 15;
                    section.data(16).dtTransOffset = 15;

                    ;% RealseCheck_B.HILReadTimebase1_o18
                    section.data(17).logicalSrcIdx = 16;
                    section.data(17).dtTransOffset = 16;

                    ;% RealseCheck_B.HILReadTimebase1_o19
                    section.data(18).logicalSrcIdx = 17;
                    section.data(18).dtTransOffset = 17;

                    ;% RealseCheck_B.HILReadTimebase1_o21
                    section.data(19).logicalSrcIdx = 18;
                    section.data(19).dtTransOffset = 18;

                    ;% RealseCheck_B.HILReadTimebase1_o22
                    section.data(20).logicalSrcIdx = 19;
                    section.data(20).dtTransOffset = 19;

                    ;% RealseCheck_B.HILReadTimebase1_o23
                    section.data(21).logicalSrcIdx = 20;
                    section.data(21).dtTransOffset = 20;

                    ;% RealseCheck_B.HILReadTimebase1_o24
                    section.data(22).logicalSrcIdx = 21;
                    section.data(22).dtTransOffset = 21;

                    ;% RealseCheck_B.SampleTime
                    section.data(23).logicalSrcIdx = 22;
                    section.data(23).dtTransOffset = 22;

                    ;% RealseCheck_B.MAIN
                    section.data(24).logicalSrcIdx = 23;
                    section.data(24).dtTransOffset = 23;

                    ;% RealseCheck_B.ManualSwitch5
                    section.data(25).logicalSrcIdx = 24;
                    section.data(25).dtTransOffset = 27;

                    ;% RealseCheck_B.gripposition
                    section.data(26).logicalSrcIdx = 25;
                    section.data(26).dtTransOffset = 28;

                    ;% RealseCheck_B.x0
                    section.data(27).logicalSrcIdx = 26;
                    section.data(27).dtTransOffset = 29;

                    ;% RealseCheck_B.Integrator1
                    section.data(28).logicalSrcIdx = 27;
                    section.data(28).dtTransOffset = 30;

                    ;% RealseCheck_B.goalcurrent
                    section.data(29).logicalSrcIdx = 28;
                    section.data(29).dtTransOffset = 31;

                    ;% RealseCheck_B.Product
                    section.data(30).logicalSrcIdx = 29;
                    section.data(30).dtTransOffset = 32;

                    ;% RealseCheck_B.Product1
                    section.data(31).logicalSrcIdx = 30;
                    section.data(31).dtTransOffset = 33;

                    ;% RealseCheck_B.Gain2
                    section.data(32).logicalSrcIdx = 31;
                    section.data(32).dtTransOffset = 34;

                    ;% RealseCheck_B.p4
                    section.data(33).logicalSrcIdx = 32;
                    section.data(33).dtTransOffset = 35;

                    ;% RealseCheck_B.v4
                    section.data(34).logicalSrcIdx = 34;
                    section.data(34).dtTransOffset = 38;

            nTotData = nTotData + section.nData;
            sigMap.sections(1) = section;
            clear section


            ;%
            ;% Non-auto Data (signal)
            ;%


        ;%
        ;% Add final counts to struct.
        ;%
        sigMap.nTotData = nTotData;



    ;%*******************
    ;% Create DWork Map *
    ;%*******************
    
        nTotData      = 0; %add to this count as we go
        nTotSects     = 8;
        sectIdxOffset = 1;

        ;%
        ;% Define dummy sections & preallocate arrays
        ;%
        dumSection.nData = -1;
        dumSection.data  = [];

        dumData.logicalSrcIdx = -1;
        dumData.dtTransOffset = -1;

        ;%
        ;% Init/prealloc dworkMap
        ;%
        dworkMap.nSections           = nTotSects;
        dworkMap.sectIdxOffset       = sectIdxOffset;
            dworkMap.sections(nTotSects) = dumSection; %prealloc
        dworkMap.nTotData            = -1;

        ;%
        ;% Auto data (RealseCheck_DW)
        ;%
            section.nData     = 1;
            section.data(1)  = dumData; %prealloc

                    ;% RealseCheck_DW.SampleTime_PreviousTime
                    section.data(1).logicalSrcIdx = 0;
                    section.data(1).dtTransOffset = 0;

            nTotData = nTotData + section.nData;
            dworkMap.sections(1) = section;
            clear section

            section.nData     = 4;
            section.data(4)  = dumData; %prealloc

                    ;% RealseCheck_DW.HILInitializePositionMode_OOVal
                    section.data(1).logicalSrcIdx = 1;
                    section.data(1).dtTransOffset = 0;

                    ;% RealseCheck_DW.HILReadTimebase1_AnalogBuffer
                    section.data(2).logicalSrcIdx = 2;
                    section.data(2).dtTransOffset = 13;

                    ;% RealseCheck_DW.HILReadTimebase1_OtherBuffer
                    section.data(3).logicalSrcIdx = 3;
                    section.data(3).dtTransOffset = 18;

                    ;% RealseCheck_DW.HILWrite_OtherBuffer
                    section.data(4).logicalSrcIdx = 4;
                    section.data(4).dtTransOffset = 38;

            nTotData = nTotData + section.nData;
            dworkMap.sections(2) = section;
            clear section

            section.nData     = 1;
            section.data(1)  = dumData; %prealloc

                    ;% RealseCheck_DW.HILInitializePositionMode_Card
                    section.data(1).logicalSrcIdx = 5;
                    section.data(1).dtTransOffset = 0;

            nTotData = nTotData + section.nData;
            dworkMap.sections(3) = section;
            clear section

            section.nData     = 1;
            section.data(1)  = dumData; %prealloc

                    ;% RealseCheck_DW.HILReadTimebase1_Task
                    section.data(1).logicalSrcIdx = 6;
                    section.data(1).dtTransOffset = 0;

            nTotData = nTotData + section.nData;
            dworkMap.sections(4) = section;
            clear section

            section.nData     = 5;
            section.data(5)  = dumData; %prealloc

                    ;% RealseCheck_DW.Base_RWORK.Amp
                    section.data(1).logicalSrcIdx = 7;
                    section.data(1).dtTransOffset = 0;

                    ;% RealseCheck_DW.Shoulder_RWORK.Amp
                    section.data(2).logicalSrcIdx = 8;
                    section.data(2).dtTransOffset = 1;

                    ;% RealseCheck_DW.Elbow_RWORK.Amp
                    section.data(3).logicalSrcIdx = 9;
                    section.data(3).dtTransOffset = 2;

                    ;% RealseCheck_DW.Wrist_RWORK.Amp
                    section.data(4).logicalSrcIdx = 10;
                    section.data(4).dtTransOffset = 3;

                    ;% RealseCheck_DW.SmoothSignalGenerator_RWORK.Amp
                    section.data(5).logicalSrcIdx = 11;
                    section.data(5).dtTransOffset = 4;

            nTotData = nTotData + section.nData;
            dworkMap.sections(5) = section;
            clear section

            section.nData     = 6;
            section.data(6)  = dumData; %prealloc

                    ;% RealseCheck_DW.Scope1_PWORK.LoggedData
                    section.data(1).logicalSrcIdx = 12;
                    section.data(1).dtTransOffset = 0;

                    ;% RealseCheck_DW.Measurements_PWORK.LoggedData
                    section.data(2).logicalSrcIdx = 13;
                    section.data(2).dtTransOffset = 1;

                    ;% RealseCheck_DW.Scope_PWORK.LoggedData
                    section.data(3).logicalSrcIdx = 14;
                    section.data(3).dtTransOffset = 7;

                    ;% RealseCheck_DW.HILWrite_PWORK
                    section.data(4).logicalSrcIdx = 15;
                    section.data(4).dtTransOffset = 9;

                    ;% RealseCheck_DW.CurrentFilteration_PWORK.LoggedData
                    section.data(5).logicalSrcIdx = 16;
                    section.data(5).dtTransOffset = 10;

                    ;% RealseCheck_DW.GoalvsActualGripCurrent_PWORK.LoggedData
                    section.data(6).logicalSrcIdx = 17;
                    section.data(6).dtTransOffset = 12;

            nTotData = nTotData + section.nData;
            dworkMap.sections(6) = section;
            clear section

            section.nData     = 3;
            section.data(3)  = dumData; %prealloc

                    ;% RealseCheck_DW.HILInitializePositionMode_Clock
                    section.data(1).logicalSrcIdx = 18;
                    section.data(1).dtTransOffset = 0;

                    ;% RealseCheck_DW.sfEvent
                    section.data(2).logicalSrcIdx = 19;
                    section.data(2).dtTransOffset = 1;

                    ;% RealseCheck_DW.sfEvent_p
                    section.data(3).logicalSrcIdx = 20;
                    section.data(3).dtTransOffset = 2;

            nTotData = nTotData + section.nData;
            dworkMap.sections(7) = section;
            clear section

            section.nData     = 3;
            section.data(3)  = dumData; %prealloc

                    ;% RealseCheck_DW.Integrator1_DWORK1
                    section.data(1).logicalSrcIdx = 21;
                    section.data(1).dtTransOffset = 0;

                    ;% RealseCheck_DW.doneDoubleBufferReInit
                    section.data(2).logicalSrcIdx = 22;
                    section.data(2).dtTransOffset = 1;

                    ;% RealseCheck_DW.doneDoubleBufferReInit_n
                    section.data(3).logicalSrcIdx = 23;
                    section.data(3).dtTransOffset = 2;

            nTotData = nTotData + section.nData;
            dworkMap.sections(8) = section;
            clear section


            ;%
            ;% Non-auto Data (dwork)
            ;%


        ;%
        ;% Add final counts to struct.
        ;%
        dworkMap.nTotData = nTotData;



    ;%
    ;% Add individual maps to base struct.
    ;%

    targMap.paramMap  = paramMap;
    targMap.signalMap = sigMap;
    targMap.dworkMap  = dworkMap;

    ;%
    ;% Add checksums to base struct.
    ;%


    targMap.checksum0 = 3474281895;
    targMap.checksum1 = 975685958;
    targMap.checksum2 = 817352766;
    targMap.checksum3 = 2741323858;

