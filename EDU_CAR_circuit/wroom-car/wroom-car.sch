EESchema Schematic File Version 4
EELAYER 30 0
EELAYER END
$Descr A4 11693 8268
encoding utf-8
Sheet 1 1
Title "SMART 2WD CAR - WiFi CONTROL"
Date ""
Rev "1.0"
Comp "KIMSON"
Comment1 ""
Comment2 ""
Comment3 ""
Comment4 ""
$EndDescr
$Comp
L Connector:Conn_01x16_Male P1
U 1 1 5F6103F0
P 1950 2500
F 0 "P1" V 1800 3200 79  0000 C CNN
F 1 "Conn_01x16_Male" V 1876 2428 50  0001 C CNN
F 2 "Connector_PinHeader_2.54mm:PinHeader_1x16_P2.54mm_Vertical" H 1950 2500 50  0001 C CNN
F 3 "~" H 1950 2500 50  0001 C CNN
	1    1950 2500
	1    0    0    -1  
$EndComp
Text GLabel 2450 1800 2    55   Input ~ 0
A0
$Comp
L power:GND #PWR0111
U 1 1 5F64BD38
P 2400 3300
F 0 "#PWR0111" H 2400 3050 50  0001 C CNN
F 1 "GND" H 2405 3127 50  0000 C CNN
F 2 "" H 2400 3300 50  0001 C CNN
F 3 "" H 2400 3300 50  0001 C CNN
	1    2400 3300
	0    -1   -1   0   
$EndComp
$Comp
L power:+5V #PWR0112
U 1 1 5F64C7B2
P 2750 3100
F 0 "#PWR0112" H 2750 2950 50  0001 C CNN
F 1 "+5V" H 2750 3250 50  0000 C CNN
F 2 "" H 2750 3100 50  0001 C CNN
F 3 "" H 2750 3100 50  0001 C CNN
	1    2750 3100
	0    1    1    0   
$EndComp
Wire Wire Line
	2150 3300 2250 3300
Wire Wire Line
	2150 3200 2250 3200
Wire Wire Line
	2250 3200 2250 3300
Connection ~ 2250 3300
Wire Wire Line
	2250 3300 2400 3300
Text GLabel 2450 2200 2    55   Input ~ 0
RIGHT
Text GLabel 2700 2400 2    55   Input ~ 0
APWM
Wire Wire Line
	2150 2200 2450 2200
Text GLabel 2700 2000 2    55   Input ~ 0
ECHO
Text Notes 1829 2000 3    79   ~ 0
ESP-WROOM-02 D1
$Comp
L Device:C C1
U 1 1 5FE9D87C
P 5550 3800
F 0 "C1" H 5665 3846 79  0000 L CNN
F 1 "100nF" H 5665 3755 50  0000 L CNN
F 2 "Capacitor_SMD:C_0805_2012Metric" H 5588 3650 50  0001 C CNN
F 3 "~" H 5550 3800 50  0001 C CNN
F 4 "C62912" H 5550 3800 50  0001 C CNN "LCSC"
	1    5550 3800
	1    0    0    -1  
$EndComp
$Comp
L power:GND #PWR01
U 1 1 5FE9E910
P 5550 4000
F 0 "#PWR01" H 5550 3750 50  0001 C CNN
F 1 "GND" H 5555 3827 50  0000 C CNN
F 2 "" H 5550 4000 50  0001 C CNN
F 3 "" H 5550 4000 50  0001 C CNN
	1    5550 4000
	1    0    0    -1  
$EndComp
Wire Wire Line
	5550 3950 5550 4000
Wire Wire Line
	2700 2000 2150 2000
Wire Wire Line
	2150 1800 2450 1800
$Comp
L Driver_Motor:TB6612FNG U1
U 1 1 5FFBC19E
P 4550 4650
F 0 "U1" H 5050 5400 79  0000 C CNN
F 1 "TB6612FNG" H 5200 5300 50  0000 C CNN
F 2 "Package_SO:SSOP-24_5.3x8.2mm_P0.65mm" H 5850 3750 50  0001 C CNN
F 3 "https://toshiba.semicon-storage.com/us/product/linear/motordriver/detail.TB6612FNG.html" H 5000 5250 50  0001 C CNN
F 4 "C88224" H 4550 4650 50  0001 C CNN "LCSC"
	1    4550 4650
	1    0    0    -1  
$EndComp
$Comp
L Device:CP1 C2
U 1 1 5FFC0323
P 6000 3800
F 0 "C2" H 6115 3846 79  0000 L CNN
F 1 "22uF" H 6115 3755 50  0000 L CNN
F 2 "Capacitor_Tantalum_SMD:CP_EIA-3528-12_Kemet-T_Pad1.50x2.35mm_HandSolder" H 6000 3800 50  0001 C CNN
F 3 "~" H 6000 3800 50  0001 C CNN
F 4 "C8020" H 6000 3800 50  0001 C CNN "LCSC"
	1    6000 3800
	1    0    0    -1  
$EndComp
Wire Wire Line
	5150 4950 5850 4950
Wire Wire Line
	5150 4750 6050 4750
Wire Wire Line
	5850 4950 5850 4650
Wire Wire Line
	5850 4650 6050 4650
$Comp
L power:+5V #PWR09
U 1 1 5FFD3458
P 4250 3550
F 0 "#PWR09" H 4250 3400 50  0001 C CNN
F 1 "+5V" H 4265 3723 50  0000 C CNN
F 2 "" H 4250 3550 50  0001 C CNN
F 3 "" H 4250 3550 50  0001 C CNN
	1    4250 3550
	1    0    0    -1  
$EndComp
Wire Wire Line
	4250 3550 4250 3600
$Comp
L power:GND #PWR014
U 1 1 5FFD933A
P 6000 4000
F 0 "#PWR014" H 6000 3750 50  0001 C CNN
F 1 "GND" H 6005 3827 50  0000 C CNN
F 2 "" H 6000 4000 50  0001 C CNN
F 3 "" H 6000 4000 50  0001 C CNN
	1    6000 4000
	1    0    0    -1  
$EndComp
Wire Wire Line
	6000 3950 6000 4000
$Comp
L power:VS #PWR012
U 1 1 5FFDB8EF
P 4650 3550
F 0 "#PWR012" H 4450 3400 50  0001 C CNN
F 1 "VS" H 4665 3723 50  0000 C CNN
F 2 "" H 4650 3550 50  0001 C CNN
F 3 "" H 4650 3550 50  0001 C CNN
	1    4650 3550
	1    0    0    -1  
$EndComp
Wire Wire Line
	4650 3550 4650 3600
Wire Wire Line
	4650 3600 4750 3600
Wire Wire Line
	4850 3600 4850 3650
Connection ~ 4650 3600
Wire Wire Line
	4650 3600 4650 3650
Wire Wire Line
	4750 3650 4750 3600
Connection ~ 4750 3600
Wire Wire Line
	6000 3600 6000 3650
$Comp
L Device:R_US R3
U 1 1 5FFF6A18
P 2750 4400
F 0 "R3" H 2818 4446 79  0000 L CNN
F 1 "10K" H 2818 4355 50  0000 L CNN
F 2 "Resistor_SMD:R_0805_2012Metric" V 2790 4390 50  0001 C CNN
F 3 "~" H 2750 4400 50  0001 C CNN
F 4 "C17414" H 2750 4400 50  0001 C CNN "LCSC"
	1    2750 4400
	1    0    0    -1  
$EndComp
$Comp
L Device:R_US R1
U 1 1 5FFF73F7
P 2050 5200
F 0 "R1" H 2118 5246 79  0000 L CNN
F 1 "10K" H 2118 5155 50  0000 L CNN
F 2 "Resistor_SMD:R_0805_2012Metric" V 2090 5190 50  0001 C CNN
F 3 "~" H 2050 5200 50  0001 C CNN
F 4 "C17414" H 2050 5200 50  0001 C CNN "LCSC"
	1    2050 5200
	1    0    0    -1  
$EndComp
Wire Wire Line
	3050 4850 3150 4850
Wire Wire Line
	2750 4550 2750 4600
$Comp
L power:+5V #PWR05
U 1 1 5FFFE942
P 2750 4200
F 0 "#PWR05" H 2750 4050 50  0001 C CNN
F 1 "+5V" H 2765 4373 50  0000 C CNN
F 2 "" H 2750 4200 50  0001 C CNN
F 3 "" H 2750 4200 50  0001 C CNN
	1    2750 4200
	1    0    0    -1  
$EndComp
$Comp
L power:+5V #PWR02
U 1 1 5FFFF0A2
P 2050 5000
F 0 "#PWR02" H 2050 4850 50  0001 C CNN
F 1 "+5V" H 2065 5173 50  0000 C CNN
F 2 "" H 2050 5000 50  0001 C CNN
F 3 "" H 2050 5000 50  0001 C CNN
	1    2050 5000
	1    0    0    -1  
$EndComp
Wire Wire Line
	2750 4200 2750 4250
Wire Wire Line
	2050 5000 2050 5050
Wire Wire Line
	2050 5350 2050 5400
Wire Wire Line
	3900 5050 3950 5050
Wire Wire Line
	2750 4600 3150 4600
Wire Wire Line
	3150 4600 3150 4750
Wire Wire Line
	3150 4750 3950 4750
Connection ~ 2750 4600
Wire Wire Line
	2750 4600 2750 4650
Wire Wire Line
	2350 5650 2450 5650
Wire Wire Line
	3950 4950 3800 4950
Wire Wire Line
	3800 5400 2050 5400
Connection ~ 2050 5400
Wire Wire Line
	2050 5400 2050 5450
$Comp
L power:GND #PWR06
U 1 1 6001FA7F
P 2750 5100
F 0 "#PWR06" H 2750 4850 50  0001 C CNN
F 1 "GND" H 2755 4927 50  0000 C CNN
F 2 "" H 2750 5100 50  0001 C CNN
F 3 "" H 2750 5100 50  0001 C CNN
	1    2750 5100
	1    0    0    -1  
$EndComp
$Comp
L power:GND #PWR03
U 1 1 600203B8
P 2050 5950
F 0 "#PWR03" H 2050 5700 50  0001 C CNN
F 1 "GND" H 2055 5777 50  0000 C CNN
F 2 "" H 2050 5950 50  0001 C CNN
F 3 "" H 2050 5950 50  0001 C CNN
	1    2050 5950
	1    0    0    -1  
$EndComp
Wire Wire Line
	2750 5050 2750 5100
Wire Wire Line
	2050 5850 2050 5950
$Comp
L Device:R_US R4
U 1 1 60032924
P 3150 5050
F 0 "R4" H 3218 5096 79  0000 L CNN
F 1 "10K" H 3218 5005 50  0000 L CNN
F 2 "Resistor_SMD:R_0805_2012Metric" V 3190 5040 50  0001 C CNN
F 3 "~" H 3150 5050 50  0001 C CNN
F 4 "C17414" H 3150 5050 50  0001 C CNN "LCSC"
	1    3150 5050
	1    0    0    -1  
$EndComp
$Comp
L Device:R_US R2
U 1 1 6003360F
P 2450 5850
F 0 "R2" H 2518 5896 79  0000 L CNN
F 1 "10K" H 2518 5805 50  0000 L CNN
F 2 "Resistor_SMD:R_0805_2012Metric" V 2490 5840 50  0001 C CNN
F 3 "~" H 2450 5850 50  0001 C CNN
F 4 "C17414" H 2450 5850 50  0001 C CNN "LCSC"
	1    2450 5850
	1    0    0    -1  
$EndComp
Wire Wire Line
	2450 5700 2450 5650
Connection ~ 2450 5650
Wire Wire Line
	2450 5650 3900 5650
$Comp
L power:GND #PWR04
U 1 1 60037F46
P 2450 6050
F 0 "#PWR04" H 2450 5800 50  0001 C CNN
F 1 "GND" H 2455 5877 50  0000 C CNN
F 2 "" H 2450 6050 50  0001 C CNN
F 3 "" H 2450 6050 50  0001 C CNN
	1    2450 6050
	1    0    0    -1  
$EndComp
Wire Wire Line
	2450 6000 2450 6050
$Comp
L power:GND #PWR07
U 1 1 600452CB
P 3150 5200
F 0 "#PWR07" H 3150 4950 50  0001 C CNN
F 1 "GND" H 3150 5050 50  0000 C CNN
F 2 "" H 3150 5200 50  0001 C CNN
F 3 "" H 3150 5200 50  0001 C CNN
	1    3150 5200
	1    0    0    -1  
$EndComp
Wire Wire Line
	3150 4900 3150 4850
Connection ~ 3150 4850
Wire Wire Line
	3150 4850 3700 4850
Wire Wire Line
	3800 4950 3800 5400
Wire Wire Line
	3900 5050 3900 5550
Text GLabel 3650 4950 0    55   Input ~ 0
AIN
Text GLabel 3650 5550 0    55   Input ~ 0
BIN
Wire Wire Line
	3650 5550 3900 5550
Connection ~ 3900 5550
Wire Wire Line
	3900 5550 3900 5650
Wire Wire Line
	3650 4950 3700 4950
Wire Wire Line
	3700 4950 3700 4850
Connection ~ 3700 4850
Wire Wire Line
	3700 4850 3950 4850
$Comp
L Transistor_FET:2N7002 Q2
U 1 1 6009C255
P 2850 4850
F 0 "Q2" H 3055 4896 79  0000 L CNN
F 1 "2N7002" H 3055 4805 50  0000 L CNN
F 2 "Package_TO_SOT_SMD:SOT-23" H 3050 4775 50  0001 L CIN
F 3 "https://www.fairchildsemi.com/datasheets/2N/2N7002.pdf" H 2850 4850 50  0001 L CNN
F 4 "C116584" H 2850 4850 50  0001 C CNN "LCSC"
	1    2850 4850
	-1   0    0    -1  
$EndComp
$Comp
L Transistor_FET:2N7002 Q1
U 1 1 600A2E79
P 2150 5650
F 0 "Q1" H 2355 5696 79  0000 L CNN
F 1 "2N7002" H 2355 5605 50  0000 L CNN
F 2 "Package_TO_SOT_SMD:SOT-23" H 2350 5575 50  0001 L CIN
F 3 "https://www.fairchildsemi.com/datasheets/2N/2N7002.pdf" H 2150 5650 50  0001 L CNN
F 4 "C116584" H 2150 5650 50  0001 C CNN "LCSC"
	1    2150 5650
	-1   0    0    -1  
$EndComp
Text Notes 7700 6100 0    100  ~ 0
ESP-WROOM-02 \n1-A0      SENS\n2-D1   5 TRIG\n3-D2   4 ECHO\n4-D3   0 LEFT SENS(FLASH) \n5-D4   2 RIGHT SENS(SDA)\n6-D5  14 AIN(SCL)\n7-D6  12 APWM \n8-D7  13 BPWM \n9-D8  15 BIN  \n10-D9   3 RX  BT\n11-D10 1 TX  BT\nD0 16 LED (Default)
Text GLabel 2700 2300 2    55   Input ~ 0
AIN
Text GLabel 2700 1900 2    55   Input ~ 0
TRIG
Text GLabel 2450 2100 2    55   Input ~ 0
LEFT
Text GLabel 2700 2500 2    55   Input ~ 0
BPWM
Text GLabel 2700 2600 2    55   Input ~ 0
BIN
Text GLabel 2450 2700 2    55   Input ~ 0
RXD
Text GLabel 2450 2800 2    55   Input ~ 0
TXD
Wire Wire Line
	2700 1900 2150 1900
Wire Wire Line
	2450 2100 2150 2100
Wire Wire Line
	2700 2300 2150 2300
Wire Wire Line
	2700 2400 2150 2400
Wire Wire Line
	2700 2500 2150 2500
Wire Wire Line
	2700 2600 2150 2600
Wire Wire Line
	2450 2700 2150 2700
Wire Wire Line
	2450 2800 2150 2800
Text GLabel 2700 2900 2    55   Input ~ 0
3V3
Wire Wire Line
	2700 2900 2250 2900
Wire Wire Line
	2150 3000 2250 3000
Wire Wire Line
	2250 3000 2250 2900
Connection ~ 2250 2900
Wire Wire Line
	2250 2900 2150 2900
$Comp
L hc-06:HC-06 BT1
U 1 1 60041116
P 5500 2600
F 0 "BT1" H 5400 3050 100 0000 L CNN
F 1 "HC-06" H 5250 2900 100 0000 L CNN
F 2 "Connector_PinHeader_2.54mm:PinHeader_1x04_P2.54mm_Vertical" H 5500 2600 100 0001 C CNN
F 3 "" H 5500 2600 100 0001 C CNN
	1    5500 2600
	1    0    0    -1  
$EndComp
$Comp
L HC-SR04:HC-SR04 US1
U 1 1 60056CA1
P 4050 2250
F 0 "US1" V 4650 2400 50  0000 R CNN
F 1 "HC-SR04" V 4550 2400 50  0000 R CNN
F 2 "myOwnLib:HC-SR04" H 4050 2250 50  0001 C CNN
F 3 "" H 4050 2250 50  0001 C CNN
	1    4050 2250
	0    -1   -1   0   
$EndComp
Text GLabel 5200 2950 3    55   Input ~ 0
TXD
Text GLabel 5400 2950 3    55   Input ~ 0
RXD
Text GLabel 4000 2500 3    55   Input ~ 0
TRIG
Text GLabel 4100 2500 3    55   Input ~ 0
ECHO
Text GLabel 5800 2950 3    55   Input ~ 0
3V3
$Comp
L power:+5V #PWR011
U 1 1 6005950E
P 3550 2250
F 0 "#PWR011" H 3550 2100 50  0001 C CNN
F 1 "+5V" H 3565 2423 50  0000 C CNN
F 2 "" H 3550 2250 50  0001 C CNN
F 3 "" H 3550 2250 50  0001 C CNN
	1    3550 2250
	1    0    0    -1  
$EndComp
$Comp
L power:GND #PWR013
U 1 1 60059F0D
P 4200 2450
F 0 "#PWR013" H 4200 2200 50  0001 C CNN
F 1 "GND" H 4205 2277 50  0000 C CNN
F 2 "" H 4200 2450 50  0001 C CNN
F 3 "" H 4200 2450 50  0001 C CNN
	1    4200 2450
	1    0    0    -1  
$EndComp
$Comp
L power:GND #PWR015
U 1 1 6005A9FA
P 5600 2900
F 0 "#PWR015" H 5600 2650 50  0001 C CNN
F 1 "GND" H 5605 2727 50  0000 C CNN
F 2 "" H 5600 2900 50  0001 C CNN
F 3 "" H 5600 2900 50  0001 C CNN
	1    5600 2900
	1    0    0    -1  
$EndComp
Wire Wire Line
	5800 2800 5800 2950
Wire Wire Line
	5600 2800 5600 2900
Wire Wire Line
	5400 2800 5400 2950
Wire Wire Line
	5200 2800 5200 2950
Wire Wire Line
	4200 2350 4200 2450
Wire Wire Line
	4000 2350 4000 2500
Wire Wire Line
	4100 2350 4100 2500
Wire Wire Line
	3550 2250 3550 2450
Wire Wire Line
	3550 2450 3900 2450
Wire Wire Line
	3900 2450 3900 2350
$Comp
L Connector:Screw_Terminal_01x02 M2
U 1 1 6012A1D7
P 6250 4650
F 0 "M2" H 6330 4642 50  0000 L CNN
F 1 "Screw_Terminal_01x02" H 6330 4551 50  0001 L CNN
F 2 "TerminalBlock_Phoenix:TerminalBlock_Phoenix_MPT-0,5-2-2.54_1x02_P2.54mm_Horizontal" H 6250 4650 50  0001 C CNN
F 3 "~" H 6250 4650 50  0001 C CNN
	1    6250 4650
	1    0    0    -1  
$EndComp
Wire Wire Line
	2750 3100 2150 3100
Wire Wire Line
	5550 3650 5550 3600
Connection ~ 5550 3600
Wire Wire Line
	5550 3600 6000 3600
Connection ~ 4250 3600
Wire Wire Line
	4250 3600 4250 3650
Wire Wire Line
	4750 3600 4850 3600
Connection ~ 4850 3600
Wire Wire Line
	4850 3600 5550 3600
Connection ~ 6000 3600
$Comp
L Connector:TestPoint TP1
U 1 1 602F64A6
P 6000 3500
F 0 "TP1" H 6058 3618 50  0000 L CNN
F 1 "TestPoint" H 6058 3527 50  0000 L CNN
F 2 "TestPoint:TestPoint_Pad_2.0x2.0mm" H 6200 3500 50  0001 C CNN
F 3 "~" H 6200 3500 50  0001 C CNN
	1    6000 3500
	1    0    0    -1  
$EndComp
Wire Wire Line
	6000 3500 6000 3600
Wire Wire Line
	4250 3600 4650 3600
$Comp
L Connector:Screw_Terminal_01x02 M1
U 1 1 60129AA9
P 6250 4350
F 0 "M1" H 6330 4342 50  0000 L CNN
F 1 "Screw_Terminal_01x02" H 6330 4251 50  0001 L CNN
F 2 "TerminalBlock_Phoenix:TerminalBlock_Phoenix_MPT-0,5-2-2.54_1x02_P2.54mm_Horizontal" H 6250 4350 50  0001 C CNN
F 3 "~" H 6250 4350 50  0001 C CNN
	1    6250 4350
	1    0    0    -1  
$EndComp
$EndSCHEMATC
