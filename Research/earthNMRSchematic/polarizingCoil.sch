EESchema Schematic File Version 4
LIBS:earthNMRSchematic-cache
EELAYER 26 0
EELAYER END
$Descr A4 11693 8268
encoding utf-8
Sheet 4 4
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
L Device:R R?
U 1 1 5BD5C07B
P 4400 3850
AR Path="/5BD5C07B" Ref="R?"  Part="1" 
AR Path="/5BD58EEA/5BD5C07B" Ref="R1"  Part="1" 
F 0 "R1" H 4470 3896 50  0000 L CNN
F 1 "10" H 4470 3805 50  0000 L CNN
F 2 "" V 4330 3850 50  0001 C CNN
F 3 "~" H 4400 3850 50  0001 C CNN
	1    4400 3850
	1    0    0    -1  
$EndComp
$Comp
L pspice:DIODE D?
U 1 1 5BD5C083
P 5150 3850
AR Path="/5BD5C083" Ref="D?"  Part="1" 
AR Path="/5BD58EEA/5BD5C083" Ref="D1"  Part="1" 
F 0 "D1" V 5196 3722 50  0000 R CNN
F 1 "DIODE" V 5105 3722 50  0000 R CNN
F 2 "" H 5150 3850 50  0001 C CNN
F 3 "" H 5150 3850 50  0001 C CNN
	1    5150 3850
	0    -1   -1   0   
$EndComp
$Comp
L Device:CP1 1000uF?
U 1 1 5BD5C08B
P 6050 3650
AR Path="/5BD5C08B" Ref="1000uF?"  Part="1" 
AR Path="/5BD58EEA/5BD5C08B" Ref="CP1"  Part="1" 
F 0 "CP1" H 6150 3700 50  0000 L CNN
F 1 "1000u" H 6165 3605 50  0000 L CNN
F 2 "" H 6050 3650 50  0001 C CNN
F 3 "~" H 6050 3650 50  0001 C CNN
	1    6050 3650
	1    0    0    -1  
$EndComp
$Comp
L Device:L L?
U 1 1 5BD5C0AC
P 7900 3800
AR Path="/5BD5C0AC" Ref="L?"  Part="1" 
AR Path="/5BD58EEA/5BD5C0AC" Ref="L1"  Part="1" 
F 0 "L1" H 7953 3846 50  0000 L CNN
F 1 "1m" H 7953 3755 50  0000 L CNN
F 2 "" H 7900 3800 50  0001 C CNN
F 3 "~" H 7900 3800 50  0001 C CNN
	1    7900 3800
	1    0    0    -1  
$EndComp
Wire Wire Line
	7900 3250 7900 3650
Wire Wire Line
	7900 3950 7900 4450
Text Notes 8150 3550 3    50   ~ 0
Polarization Coil\n
Wire Wire Line
	5150 3250 5150 3650
Wire Wire Line
	5150 4050 5150 4450
Wire Wire Line
	3500 3250 4400 3250
Wire Wire Line
	3500 4450 4400 4450
Wire Wire Line
	4400 3250 4400 3700
Wire Wire Line
	4400 4000 4400 4450
Connection ~ 4400 4450
Wire Wire Line
	4400 4450 5150 4450
$Comp
L pspice:VSOURCE V1
U 1 1 5BD67164
P 3500 3850
F 0 "V1" H 3728 3896 50  0000 L CNN
F 1 "5V" H 3728 3805 50  0000 L CNN
F 2 "" H 3500 3850 50  0001 C CNN
F 3 "" H 3500 3850 50  0001 C CNN
F 4 "V" H 3500 3850 50  0001 C CNN "Spice_Primitive"
F 5 "dc 5" H 3500 3850 50  0001 C CNN "Spice_Model"
F 6 "Y" H 3500 3850 50  0001 C CNN "Spice_Netlist_Enabled"
	1    3500 3850
	1    0    0    -1  
$EndComp
Wire Wire Line
	3500 3250 3500 3550
Wire Wire Line
	3500 4150 3500 4450
$Comp
L Device:R R?
U 1 1 5BD67B6B
P 6050 4150
AR Path="/5BD67B6B" Ref="R?"  Part="1" 
AR Path="/5BD58EEA/5BD67B6B" Ref="R2"  Part="1" 
F 0 "R2" H 6120 4196 50  0000 L CNN
F 1 "22" H 6120 4105 50  0000 L CNN
F 2 "" V 5980 4150 50  0001 C CNN
F 3 "~" H 6050 4150 50  0001 C CNN
	1    6050 4150
	1    0    0    -1  
$EndComp
Wire Wire Line
	6050 3800 6050 4000
Connection ~ 5150 4450
Wire Wire Line
	6050 4300 6050 4450
Wire Wire Line
	6050 3250 6050 3500
Connection ~ 5150 3250
Connection ~ 4400 3250
Wire Wire Line
	4400 3250 5150 3250
Connection ~ 6050 3250
Wire Wire Line
	6050 3250 7900 3250
Connection ~ 6050 4450
Wire Wire Line
	6050 4450 7900 4450
Wire Wire Line
	5150 3250 6050 3250
Wire Wire Line
	5150 4450 6050 4450
$EndSCHEMATC
