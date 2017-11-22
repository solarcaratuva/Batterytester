EESchema Schematic File Version 2
LIBS:power
LIBS:device
LIBS:switches
LIBS:relays
LIBS:motors
LIBS:transistors
LIBS:conn
LIBS:linear
LIBS:regul
LIBS:74xx
LIBS:cmos4000
LIBS:adc-dac
LIBS:memory
LIBS:xilinx
LIBS:microcontrollers
LIBS:dsp
LIBS:microchip
LIBS:analog_switches
LIBS:motorola
LIBS:texas
LIBS:intel
LIBS:audio
LIBS:interface
LIBS:digital-audio
LIBS:philips
LIBS:display
LIBS:cypress
LIBS:siliconi
LIBS:opto
LIBS:atmel
LIBS:contrib
LIBS:valves
LIBS:arduino_dummy_load_pcb-cache
EELAYER 25 0
EELAYER END
$Descr A4 11693 8268
encoding utf-8
Sheet 1 3
Title ""
Date ""
Rev ""
Comp ""
Comment1 ""
Comment2 ""
Comment3 ""
Comment4 ""
$EndDescr
$Comp
L Barrel_Jack J1
U 1 1 59F3A480
P 2550 1250
F 0 "J1" H 2550 1460 50  0000 C CNN
F 1 "Barrel_Jack" H 2550 1075 50  0000 C CNN
F 2 "Connectors:JACK_ALIM" H 2600 1210 50  0001 C CNN
F 3 "" H 2600 1210 50  0001 C CNN
	1    2550 1250
	1    0    0    1   
$EndComp
$Comp
L +9V #PWR01
U 1 1 59F3D7A4
P 3000 1100
F 0 "#PWR01" H 3000 950 50  0001 C CNN
F 1 "+9V" H 3000 1240 50  0000 C CNN
F 2 "" H 3000 1100 50  0001 C CNN
F 3 "" H 3000 1100 50  0001 C CNN
	1    3000 1100
	1    0    0    -1  
$EndComp
$Comp
L GND #PWR02
U 1 1 59F3DB9E
P 3000 1400
F 0 "#PWR02" H 3000 1150 50  0001 C CNN
F 1 "GND" H 3000 1250 50  0000 C CNN
F 2 "" H 3000 1400 50  0001 C CNN
F 3 "" H 3000 1400 50  0001 C CNN
	1    3000 1400
	1    0    0    -1  
$EndComp
$Comp
L +5V #PWR03
U 1 1 59F4A78A
P 4200 1050
F 0 "#PWR03" H 4200 900 50  0001 C CNN
F 1 "+5V" H 4200 1190 50  0000 C CNN
F 2 "" H 4200 1050 50  0001 C CNN
F 3 "" H 4200 1050 50  0001 C CNN
	1    4200 1050
	1    0    0    -1  
$EndComp
Text GLabel 2500 3250 2    60   Input ~ 0
I_SET
Text GLabel 5650 3150 2    60   Input ~ 0
BATT_A
Text GLabel 5650 3450 2    60   Input ~ 0
BATT_B
$Comp
L R R2
U 1 1 59FD1B4B
P 2300 3250
F 0 "R2" V 2350 3400 50  0000 C CNN
F 1 "47k" V 2300 3250 50  0000 C CNN
F 2 "Resistors_SMD:R_0805_HandSoldering" V 2230 3250 50  0001 C CNN
F 3 "" H 2300 3250 50  0001 C CNN
	1    2300 3250
	0    -1   -1   0   
$EndComp
$Comp
L REG REG1
U 1 1 5A04C5D0
P 3650 1250
F 0 "REG1" H 3650 1000 60  0000 C CNN
F 1 "REG" H 3650 1500 60  0000 C CNN
F 2 "" H 3600 1250 60  0001 C CNN
F 3 "" H 3600 1250 60  0001 C CNN
	1    3650 1250
	1    0    0    -1  
$EndComp
$Comp
L GND #PWR04
U 1 1 5A04F666
P 3650 4050
F 0 "#PWR04" H 3650 3800 50  0001 C CNN
F 1 "GND" H 3650 3900 50  0000 C CNN
F 2 "" H 3650 4050 50  0001 C CNN
F 3 "" H 3650 4050 50  0001 C CNN
	1    3650 4050
	1    0    0    -1  
$EndComp
$Comp
L GND #PWR05
U 1 1 5A20F379
P 1600 4000
F 0 "#PWR05" H 1600 3750 50  0001 C CNN
F 1 "GND" H 1600 3850 50  0000 C CNN
F 2 "" H 1600 4000 50  0001 C CNN
F 3 "" H 1600 4000 50  0001 C CNN
	1    1600 4000
	1    0    0    -1  
$EndComp
Text GLabel 5650 3250 2    60   Input ~ 0
I_OUT_A
$Comp
L R R3
U 1 1 5A2169A9
P 5400 3150
F 0 "R3" V 5450 3300 50  0000 C CNN
F 1 "47k" V 5400 3150 50  0000 C CNN
F 2 "Resistors_SMD:R_0805_HandSoldering" V 5330 3150 50  0001 C CNN
F 3 "" H 5400 3150 50  0001 C CNN
	1    5400 3150
	0    -1   -1   0   
$EndComp
$Comp
L R R4
U 1 1 5A216AEF
P 4250 4250
F 0 "R4" V 4300 4400 50  0000 C CNN
F 1 "47k" V 4250 4250 50  0000 C CNN
F 2 "Resistors_SMD:R_0805_HandSoldering" V 4180 4250 50  0001 C CNN
F 3 "" H 4250 4250 50  0001 C CNN
	1    4250 4250
	1    0    0    -1  
$EndComp
Text GLabel 2500 3150 2    60   Input ~ 0
CHARGE
$Comp
L R R5
U 1 1 5A22131E
P 5400 3250
F 0 "R5" V 5450 3400 50  0000 C CNN
F 1 "47k" V 5400 3250 50  0000 C CNN
F 2 "Resistors_SMD:R_0805_HandSoldering" V 5330 3250 50  0001 C CNN
F 3 "" H 5400 3250 50  0001 C CNN
	1    5400 3250
	0    -1   -1   0   
$EndComp
$Comp
L R R7
U 1 1 5A22951F
P 5400 3350
F 0 "R7" V 5450 3500 50  0000 C CNN
F 1 "47k" V 5400 3350 50  0000 C CNN
F 2 "Resistors_SMD:R_0805_HandSoldering" V 5330 3350 50  0001 C CNN
F 3 "" H 5400 3350 50  0001 C CNN
	1    5400 3350
	0    -1   -1   0   
$EndComp
$Comp
L R R6
U 1 1 5A2293D0
P 4400 4250
F 0 "R6" V 4450 4400 50  0000 C CNN
F 1 "47k" V 4400 4250 50  0000 C CNN
F 2 "Resistors_SMD:R_0805_HandSoldering" V 4330 4250 50  0001 C CNN
F 3 "" H 4400 4250 50  0001 C CNN
	1    4400 4250
	1    0    0    -1  
$EndComp
Text GLabel 5650 3350 2    60   Input ~ 0
CELL_TEMP_A
Text GLabel 5650 3650 2    60   Input ~ 0
CELL_TEMP_B
$Comp
L R R8
U 1 1 5A230070
P 4550 4250
F 0 "R8" V 4600 4400 50  0000 C CNN
F 1 "47k" V 4550 4250 50  0000 C CNN
F 2 "Resistors_SMD:R_0805_HandSoldering" V 4480 4250 50  0001 C CNN
F 3 "" H 4550 4250 50  0001 C CNN
	1    4550 4250
	1    0    0    -1  
$EndComp
$Comp
L Conn_02x08_Odd_Even J2
U 1 1 59FAC12D
P 1800 3450
F 0 "J2" H 1850 3850 50  0000 C CNN
F 1 "Conn_02x08_Odd_Even" H 2050 2950 50  0000 C CNN
F 2 "Connectors:he10-16d" H 1800 3450 50  0001 C CNN
F 3 "" H 1800 3450 50  0001 C CNN
	1    1800 3450
	1    0    0    -1  
$EndComp
$Comp
L MCP3208 U1
U 1 1 59F644BF
P 3550 3450
F 0 "U1" H 3350 3975 50  0000 R CNN
F 1 "MCP3208" H 3350 3900 50  0000 R CNN
F 2 "Housings_SOIC:SOIC-16_3.9x9.9mm_Pitch1.27mm" H 3650 3550 50  0001 C CNN
F 3 "" H 3650 3550 50  0001 C CNN
	1    3550 3450
	-1   0    0    -1  
$EndComp
$Comp
L GND #PWR06
U 1 1 59F7608A
P 4550 4500
F 0 "#PWR06" H 4550 4250 50  0001 C CNN
F 1 "GND" H 4550 4350 50  0000 C CNN
F 2 "" H 4550 4500 50  0001 C CNN
F 3 "" H 4550 4500 50  0001 C CNN
	1    4550 4500
	1    0    0    -1  
$EndComp
$Comp
L R R9
U 1 1 59F777FF
P 5400 3450
F 0 "R9" V 5450 3600 50  0000 C CNN
F 1 "47k" V 5400 3450 50  0000 C CNN
F 2 "Resistors_SMD:R_0805_HandSoldering" V 5330 3450 50  0001 C CNN
F 3 "" H 5400 3450 50  0001 C CNN
	1    5400 3450
	0    -1   -1   0   
$EndComp
$Comp
L R R10
U 1 1 59F77966
P 4700 4250
F 0 "R10" V 4750 4450 50  0000 C CNN
F 1 "47k" V 4700 4250 50  0000 C CNN
F 2 "Resistors_SMD:R_0805_HandSoldering" V 4630 4250 50  0001 C CNN
F 3 "" H 4700 4250 50  0001 C CNN
	1    4700 4250
	1    0    0    -1  
$EndComp
$Comp
L +5V #PWR07
U 1 1 59F7FE3E
P 3350 2150
F 0 "#PWR07" H 3350 2000 50  0001 C CNN
F 1 "+5V" H 3350 2290 50  0000 C CNN
F 2 "" H 3350 2150 50  0001 C CNN
F 3 "" H 3350 2150 50  0001 C CNN
	1    3350 2150
	1    0    0    -1  
$EndComp
$Comp
L C C1
U 1 1 59F8018E
P 2950 2250
F 0 "C1" H 2975 2350 50  0000 L CNN
F 1 "10uF" H 2975 2150 50  0000 L CNN
F 2 "Capacitors_SMD:C_0805_HandSoldering" H 2988 2100 50  0001 C CNN
F 3 "" H 2950 2250 50  0001 C CNN
	1    2950 2250
	0    1    1    0   
$EndComp
$Comp
L GND #PWR08
U 1 1 59F80B3F
P 3350 4050
F 0 "#PWR08" H 3350 3800 50  0001 C CNN
F 1 "GND" H 3350 3900 50  0000 C CNN
F 2 "" H 3350 4050 50  0001 C CNN
F 3 "" H 3350 4050 50  0001 C CNN
	1    3350 4050
	1    0    0    -1  
$EndComp
$Comp
L GND #PWR09
U 1 1 59F80CA3
P 2650 2250
F 0 "#PWR09" H 2650 2000 50  0001 C CNN
F 1 "GND" H 2650 2100 50  0000 C CNN
F 2 "" H 2650 2250 50  0001 C CNN
F 3 "" H 2650 2250 50  0001 C CNN
	1    2650 2250
	0    1    1    0   
$EndComp
$Comp
L GND #PWR010
U 1 1 59FD1D7D
P 4200 1450
F 0 "#PWR010" H 4200 1200 50  0001 C CNN
F 1 "GND" H 4200 1300 50  0000 C CNN
F 2 "" H 4200 1450 50  0001 C CNN
F 3 "" H 4200 1450 50  0001 C CNN
	1    4200 1450
	1    0    0    -1  
$EndComp
Wire Wire Line
	3000 1100 3000 1250
Wire Wire Line
	3000 1250 2850 1250
Connection ~ 3000 1150
Wire Wire Line
	5550 3150 5650 3150
Wire Wire Line
	5550 3250 5650 3250
Wire Wire Line
	4200 1350 4200 1450
Wire Wire Line
	4200 1050 4200 1150
Connection ~ 1600 3850
Connection ~ 1600 3650
Connection ~ 1600 3450
Connection ~ 1600 3250
Connection ~ 1600 3350
Connection ~ 1600 3550
Connection ~ 1600 3750
Wire Wire Line
	5550 3350 5650 3350
Wire Wire Line
	1600 3150 1600 4000
Wire Wire Line
	2450 3150 2500 3150
Wire Wire Line
	2500 3250 2450 3250
Wire Wire Line
	4150 3150 5250 3150
Wire Wire Line
	4150 3450 5250 3450
Wire Wire Line
	4150 3550 5250 3550
Wire Wire Line
	4150 3650 5250 3650
Wire Wire Line
	4150 3350 5250 3350
Wire Wire Line
	4150 3250 5250 3250
Wire Wire Line
	4250 4100 4250 3150
Connection ~ 4250 3150
Wire Wire Line
	4400 4100 4400 3250
Connection ~ 4400 3250
Wire Wire Line
	3350 2150 3350 2950
Wire Wire Line
	3100 2250 3350 2250
Connection ~ 3350 2250
Wire Wire Line
	2650 2250 2800 2250
Wire Wire Line
	3000 1400 3000 1350
Connection ~ 3000 1350
Wire Wire Line
	2850 1150 3100 1150
Wire Wire Line
	2850 1350 3100 1350
Wire Wire Line
	2100 3150 2150 3150
Wire Wire Line
	2100 3250 2150 3250
Wire Wire Line
	2100 3350 2950 3350
Wire Wire Line
	2950 3450 2100 3450
Wire Wire Line
	2100 3550 2950 3550
Wire Wire Line
	2950 3650 2100 3650
$Sheet
S 5850 950  1350 450 
U 59FF95E3
F0 "TEST-UNIT-A" 60
F1 "DummyLoad.sch" 60
F2 "CURRENT_SET" I L 5850 1100 60 
F3 "CELL_TEMP" O R 7200 1250 60 
F4 "CURRENT_OUT" O R 7200 1150 60 
F5 "CHARGE" I L 5850 1250 60 
F6 "V_BATT" O R 7200 1050 60 
$EndSheet
$Comp
L R R1
U 1 1 59FD15F3
P 2300 3150
F 0 "R1" V 2350 3300 50  0000 C CNN
F 1 "47k" V 2300 3150 50  0000 C CNN
F 2 "Resistors_SMD:R_0805_HandSoldering" V 2230 3150 50  0001 C CNN
F 3 "" H 2300 3150 50  0001 C CNN
	1    2300 3150
	0    -1   -1   0   
$EndComp
NoConn ~ 2100 3850
$Comp
L R R11
U 1 1 5A08A828
P 5400 3550
F 0 "R11" V 5450 3750 50  0000 C CNN
F 1 "47k" V 5400 3550 50  0000 C CNN
F 2 "Resistors_SMD:R_0805_HandSoldering" V 5330 3550 50  0001 C CNN
F 3 "" H 5400 3550 50  0001 C CNN
	1    5400 3550
	0    -1   -1   0   
$EndComp
$Comp
L R R12
U 1 1 5A08A8C0
P 4850 4250
F 0 "R12" V 4900 4450 50  0000 C CNN
F 1 "47k" V 4850 4250 50  0000 C CNN
F 2 "Resistors_SMD:R_0805_HandSoldering" V 4780 4250 50  0001 C CNN
F 3 "" H 4850 4250 50  0001 C CNN
	1    4850 4250
	1    0    0    -1  
$EndComp
Text GLabel 5750 1250 0    60   Input ~ 0
CHARGE
Wire Wire Line
	5750 1250 5850 1250
Text GLabel 5750 1100 0    60   Input ~ 0
I_SET
Wire Wire Line
	5850 1100 5750 1100
Text GLabel 7300 1250 2    60   Input ~ 0
CELL_TEMP_A
Wire Wire Line
	7200 1250 7300 1250
Text GLabel 7300 1150 2    60   Input ~ 0
I_OUT_A
Wire Wire Line
	7300 1150 7200 1150
Text GLabel 7300 1050 2    60   Input ~ 0
BATT_A
Wire Wire Line
	7300 1050 7200 1050
Wire Wire Line
	5550 3450 5650 3450
Wire Wire Line
	5650 3550 5550 3550
Wire Wire Line
	5550 3650 5650 3650
$Sheet
S 5850 1650 1350 450 
U 5A09AEA6
F0 "TEST-UNIT-B" 60
F1 "DummyLoad.sch" 60
F2 "CURRENT_SET" I L 5850 1800 60 
F3 "CELL_TEMP" O R 7200 1950 60 
F4 "CURRENT_OUT" O R 7200 1850 60 
F5 "CHARGE" I L 5850 1950 60 
F6 "V_BATT" O R 7200 1750 60 
$EndSheet
Text GLabel 5750 1950 0    60   Input ~ 0
CHARGE
Wire Wire Line
	5750 1950 5850 1950
Text GLabel 5750 1800 0    60   Input ~ 0
I_SET
Wire Wire Line
	5850 1800 5750 1800
Text GLabel 7300 1950 2    60   Input ~ 0
CELL_TEMP_B
Wire Wire Line
	7200 1950 7300 1950
Text GLabel 7300 1850 2    60   Input ~ 0
I_OUT_B
Wire Wire Line
	7300 1850 7200 1850
Text GLabel 7300 1750 2    60   Input ~ 0
BATT_B
Wire Wire Line
	7300 1750 7200 1750
Text GLabel 3650 2150 1    60   Input ~ 0
VREF
Text GLabel 2100 3750 2    60   Input ~ 0
VREF
Wire Wire Line
	3650 2150 3650 2950
$Comp
L C C2
U 1 1 5A04B350
P 2950 2550
F 0 "C2" H 2975 2650 50  0000 L CNN
F 1 "100nF" H 2975 2450 50  0000 L CNN
F 2 "Capacitors_SMD:C_0805_HandSoldering" H 2988 2400 50  0001 C CNN
F 3 "" H 2950 2550 50  0001 C CNN
	1    2950 2550
	0    1    1    0   
$EndComp
Wire Wire Line
	3100 2550 3350 2550
Connection ~ 3650 2550
$Comp
L GND #PWR012
U 1 1 5A04B5B5
P 2650 2550
F 0 "#PWR012" H 2650 2300 50  0001 C CNN
F 1 "GND" H 2650 2400 50  0000 C CNN
F 2 "" H 2650 2550 50  0001 C CNN
F 3 "" H 2650 2550 50  0001 C CNN
	1    2650 2550
	0    1    1    0   
$EndComp
Wire Wire Line
	2650 2550 2800 2550
$Comp
L C C3
U 1 1 5A04B71C
P 4050 2250
F 0 "C3" H 4075 2350 50  0000 L CNN
F 1 "10uF" H 4075 2150 50  0000 L CNN
F 2 "Capacitors_SMD:C_0805_HandSoldering" H 4088 2100 50  0001 C CNN
F 3 "" H 4050 2250 50  0001 C CNN
	1    4050 2250
	0    1    1    0   
$EndComp
$Comp
L GND #PWR013
U 1 1 5A04C217
P 4350 2250
F 0 "#PWR013" H 4350 2000 50  0001 C CNN
F 1 "GND" H 4350 2100 50  0000 C CNN
F 2 "" H 4350 2250 50  0001 C CNN
F 3 "" H 4350 2250 50  0001 C CNN
	1    4350 2250
	0    -1   -1   0   
$EndComp
Wire Wire Line
	3650 2250 3900 2250
Wire Wire Line
	4200 2250 4350 2250
Connection ~ 3650 2250
$Comp
L C C4
U 1 1 5A04CF8D
P 4050 2550
F 0 "C4" H 4075 2650 50  0000 L CNN
F 1 "100nF" H 4075 2450 50  0000 L CNN
F 2 "Capacitors_SMD:C_0805_HandSoldering" H 4088 2400 50  0001 C CNN
F 3 "" H 4050 2550 50  0001 C CNN
	1    4050 2550
	0    1    1    0   
$EndComp
Wire Wire Line
	3900 2550 3650 2550
$Comp
L GND #PWR014
U 1 1 5A04CF95
P 4350 2550
F 0 "#PWR014" H 4350 2300 50  0001 C CNN
F 1 "GND" H 4350 2400 50  0000 C CNN
F 2 "" H 4350 2550 50  0001 C CNN
F 3 "" H 4350 2550 50  0001 C CNN
	1    4350 2550
	0    -1   -1   0   
$EndComp
Wire Wire Line
	4200 2550 4350 2550
Connection ~ 3350 2550
Text GLabel 5650 3550 2    60   Input ~ 0
I_OUT_B
Wire Wire Line
	4250 4400 4250 4450
Wire Wire Line
	4250 4450 5000 4450
Wire Wire Line
	4550 4400 4550 4500
Wire Wire Line
	4400 4400 4400 4450
Connection ~ 4400 4450
Connection ~ 4550 4450
Wire Wire Line
	4700 4450 4700 4400
Wire Wire Line
	4850 4450 4850 4400
Connection ~ 4700 4450
Wire Wire Line
	4550 4100 4550 3350
Connection ~ 4550 3350
Wire Wire Line
	4700 4100 4700 3450
Connection ~ 4700 3450
Wire Wire Line
	4850 4100 4850 3550
Connection ~ 4850 3550
$Comp
L R R13
U 1 1 5A066B2C
P 5400 3650
F 0 "R13" V 5450 3850 50  0000 C CNN
F 1 "47k" V 5400 3650 50  0000 C CNN
F 2 "Resistors_SMD:R_0805_HandSoldering" V 5330 3650 50  0001 C CNN
F 3 "" H 5400 3650 50  0001 C CNN
	1    5400 3650
	0    -1   -1   0   
$EndComp
$Comp
L R R14
U 1 1 5A066D11
P 5000 4250
F 0 "R14" V 5050 4450 50  0000 C CNN
F 1 "47k" V 5000 4250 50  0000 C CNN
F 2 "Resistors_SMD:R_0805_HandSoldering" V 4930 4250 50  0001 C CNN
F 3 "" H 5000 4250 50  0001 C CNN
	1    5000 4250
	1    0    0    -1  
$EndComp
Wire Wire Line
	5000 4450 5000 4400
Connection ~ 4850 4450
Wire Wire Line
	5000 4100 5000 3650
Connection ~ 5000 3650
NoConn ~ 4150 3750
NoConn ~ 4150 3850
$EndSCHEMATC
