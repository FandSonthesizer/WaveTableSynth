EESchema Schematic File Version 4
LIBS:24dbVCF-cache
EELAYER 26 0
EELAYER END
$Descr A4 11693 8268
encoding utf-8
Sheet 2 2
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
L Connector:Conn_01x01_Male J7
U 1 1 5C4E0F1F
P 1150 1350
F 0 "J7" H 1256 1528 50  0000 C CNN
F 1 "Res" H 1256 1437 50  0000 C CNN
F 2 "NilsLib:Stift" H 1150 1350 50  0001 C CNN
F 3 "~" H 1150 1350 50  0001 C CNN
	1    1150 1350
	1    0    0    -1  
$EndComp
$Comp
L Device:R R48
U 1 1 5C4E0F7E
P 1650 1350
F 0 "R48" V 1443 1350 50  0000 C CNN
F 1 "100k" V 1534 1350 50  0000 C CNN
F 2 "NilsLib:Widerstand_liegend" V 1580 1350 50  0001 C CNN
F 3 "~" H 1650 1350 50  0001 C CNN
	1    1650 1350
	0    1    1    0   
$EndComp
Wire Wire Line
	1350 1350 1500 1350
$Comp
L power:+12V #PWR0145
U 1 1 5C4E10B9
P 2350 1500
F 0 "#PWR0145" H 2350 1350 50  0001 C CNN
F 1 "+12V" H 2365 1673 50  0000 C CNN
F 2 "" H 2350 1500 50  0001 C CNN
F 3 "" H 2350 1500 50  0001 C CNN
	1    2350 1500
	1    0    0    -1  
$EndComp
$Comp
L power:-12V #PWR0146
U 1 1 5C4E10EA
P 2350 2100
F 0 "#PWR0146" H 2350 2200 50  0001 C CNN
F 1 "-12V" V 2365 2228 50  0000 L CNN
F 2 "" H 2350 2100 50  0001 C CNN
F 3 "" H 2350 2100 50  0001 C CNN
	1    2350 2100
	0    1    1    0   
$EndComp
Wire Wire Line
	1800 1350 2000 1350
Wire Wire Line
	2000 1350 2000 1900
Wire Wire Line
	2000 1900 2150 1900
$Comp
L Device:R_POT P2
U 1 1 5C4E114B
P 950 1900
F 0 "P2" H 880 1946 50  0000 R CNN
F 1 "100k" H 880 1855 50  0000 R CNN
F 2 "NilsLib:Trimmer_Vertical" H 950 1900 50  0001 C CNN
F 3 "~" H 950 1900 50  0001 C CNN
	1    950  1900
	1    0    0    -1  
$EndComp
$Comp
L Device:R R45
U 1 1 5C4E11B1
P 1250 1600
F 0 "R45" V 1043 1600 50  0000 C CNN
F 1 "49.9k" V 1134 1600 50  0000 C CNN
F 2 "NilsLib:Widerstand_liegend" V 1180 1600 50  0001 C CNN
F 3 "~" H 1250 1600 50  0001 C CNN
	1    1250 1600
	0    1    1    0   
$EndComp
$Comp
L Device:R R46
U 1 1 5C4E11DD
P 1250 2200
F 0 "R46" V 1043 2200 50  0000 C CNN
F 1 "49.9k" V 1134 2200 50  0000 C CNN
F 2 "NilsLib:Widerstand_liegend" V 1180 2200 50  0001 C CNN
F 3 "~" H 1250 2200 50  0001 C CNN
	1    1250 2200
	0    1    1    0   
$EndComp
Wire Wire Line
	1100 1600 950  1600
Wire Wire Line
	950  1600 950  1750
Wire Wire Line
	950  2050 950  2200
Wire Wire Line
	950  2200 1100 2200
$Comp
L Device:R R47
U 1 1 5C4E12BB
P 1550 1900
F 0 "R47" V 1343 1900 50  0000 C CNN
F 1 "100k" V 1434 1900 50  0000 C CNN
F 2 "NilsLib:Widerstand_liegend" V 1480 1900 50  0001 C CNN
F 3 "~" H 1550 1900 50  0001 C CNN
	1    1550 1900
	0    1    1    0   
$EndComp
Wire Wire Line
	1400 1900 1100 1900
Wire Wire Line
	1700 1900 2000 1900
Connection ~ 2000 1900
Wire Wire Line
	1400 1600 1500 1600
Wire Wire Line
	1400 2200 1500 2200
$Comp
L power:+12V #PWR0147
U 1 1 5C4E1505
P 1500 1600
F 0 "#PWR0147" H 1500 1450 50  0001 C CNN
F 1 "+12V" H 1515 1773 50  0000 C CNN
F 2 "" H 1500 1600 50  0001 C CNN
F 3 "" H 1500 1600 50  0001 C CNN
	1    1500 1600
	1    0    0    -1  
$EndComp
$Comp
L power:-12V #PWR0148
U 1 1 5C4E1520
P 1500 2200
F 0 "#PWR0148" H 1500 2300 50  0001 C CNN
F 1 "-12V" V 1515 2328 50  0000 L CNN
F 2 "" H 1500 2200 50  0001 C CNN
F 3 "" H 1500 2200 50  0001 C CNN
	1    1500 2200
	0    1    1    0   
$EndComp
Wire Wire Line
	2150 1700 1850 1700
Wire Wire Line
	1850 1700 1850 1750
$Comp
L power:GND #PWR0149
U 1 1 5C4E1630
P 1850 1750
F 0 "#PWR0149" H 1850 1500 50  0001 C CNN
F 1 "GND" H 1800 1900 50  0000 C CNN
F 2 "" H 1850 1750 50  0001 C CNN
F 3 "" H 1850 1750 50  0001 C CNN
	1    1850 1750
	1    0    0    -1  
$EndComp
$Comp
L Device:R R49
U 1 1 5C4E21BF
P 2500 1150
F 0 "R49" V 2293 1150 50  0000 C CNN
F 1 "120k" V 2384 1150 50  0000 C CNN
F 2 "NilsLib:Widerstand_liegend" V 2430 1150 50  0001 C CNN
F 3 "~" H 2500 1150 50  0001 C CNN
	1    2500 1150
	0    1    1    0   
$EndComp
Wire Wire Line
	2000 1350 2000 1150
Wire Wire Line
	2000 1150 2350 1150
Connection ~ 2000 1350
Wire Wire Line
	2650 1150 2850 1150
Wire Wire Line
	2850 1150 2850 1500
Wire Wire Line
	2850 1800 2750 1800
$Comp
L Device:R R50
U 1 1 5C4E2484
P 3150 1500
F 0 "R50" V 2943 1500 50  0000 C CNN
F 1 "100k" V 3034 1500 50  0000 C CNN
F 2 "NilsLib:Widerstand_liegend" V 3080 1500 50  0001 C CNN
F 3 "~" H 3150 1500 50  0001 C CNN
	1    3150 1500
	0    1    1    0   
$EndComp
Wire Wire Line
	3000 1500 2850 1500
Connection ~ 2850 1500
Wire Wire Line
	2850 1500 2850 1800
Wire Wire Line
	3300 1500 3400 1500
$Comp
L Device:R R53
U 1 1 5C4E287C
P 3850 1750
F 0 "R53" V 3643 1750 50  0000 C CNN
F 1 "100k" V 3734 1750 50  0000 C CNN
F 2 "NilsLib:Widerstand_liegend" V 3780 1750 50  0001 C CNN
F 3 "~" H 3850 1750 50  0001 C CNN
	1    3850 1750
	0    1    1    0   
$EndComp
Wire Wire Line
	3400 1500 3400 1750
Wire Wire Line
	3400 1750 3700 1750
Connection ~ 3400 1500
Wire Wire Line
	3400 1500 3500 1500
Wire Wire Line
	4000 1750 4200 1750
Wire Wire Line
	4200 1750 4200 1400
Wire Wire Line
	4200 1400 4100 1400
Wire Wire Line
	3500 1300 3450 1300
Wire Wire Line
	3450 1300 3450 1850
$Comp
L Device:R R51
U 1 1 5C4E3093
P 3200 1850
F 0 "R51" V 2993 1850 50  0000 C CNN
F 1 "100k" V 3084 1850 50  0000 C CNN
F 2 "NilsLib:Widerstand_liegend" V 3130 1850 50  0001 C CNN
F 3 "~" H 3200 1850 50  0001 C CNN
	1    3200 1850
	0    1    1    0   
$EndComp
Wire Wire Line
	3450 1850 3350 1850
Wire Wire Line
	3050 1850 3000 1850
$Comp
L power:-12V #PWR0150
U 1 1 5C4E37E4
P 3000 1850
F 0 "#PWR0150" H 3000 1950 50  0001 C CNN
F 1 "-12V" H 3015 2023 50  0000 C CNN
F 2 "" H 3000 1850 50  0001 C CNN
F 3 "" H 3000 1850 50  0001 C CNN
	1    3000 1850
	-1   0    0    1   
$EndComp
$Comp
L Device:R R52
U 1 1 5C4E3816
P 3650 1850
F 0 "R52" V 3443 1850 50  0000 C CNN
F 1 "30k" V 3534 1850 50  0000 C CNN
F 2 "NilsLib:Widerstand_liegend" V 3580 1850 50  0001 C CNN
F 3 "~" H 3650 1850 50  0001 C CNN
	1    3650 1850
	0    1    1    0   
$EndComp
Wire Wire Line
	3500 1850 3450 1850
Connection ~ 3450 1850
Wire Wire Line
	3800 1850 3800 1900
$Comp
L power:GND #PWR0151
U 1 1 5C4E408A
P 3800 1900
F 0 "#PWR0151" H 3800 1650 50  0001 C CNN
F 1 "GND" H 3805 1727 50  0000 C CNN
F 2 "" H 3800 1900 50  0001 C CNN
F 3 "" H 3800 1900 50  0001 C CNN
	1    3800 1900
	1    0    0    -1  
$EndComp
$Comp
L Amplifier_Operational:LM13700 U8
U 3 1 5C4E40E4
P 5350 1500
F 0 "U8" H 5350 1867 50  0000 C CNN
F 1 "LM13700" H 5350 1776 50  0000 C CNN
F 2 "Package_DIP:DIP-16_W7.62mm_Socket_LongPads" H 5050 1525 50  0001 C CNN
F 3 "http://www.ti.com/lit/ds/symlink/lm13700.pdf" H 5050 1525 50  0001 C CNN
	3    5350 1500
	1    0    0    -1  
$EndComp
$Comp
L Amplifier_Operational:LM13700 U8
U 4 1 5C4E417E
P 6200 1500
F 0 "U8" H 6100 1848 50  0000 C CNN
F 1 "LM13700" H 6100 1757 50  0000 C CNN
F 2 "Package_DIP:DIP-16_W7.62mm_Socket_LongPads" H 5900 1525 50  0001 C CNN
F 3 "http://www.ti.com/lit/ds/symlink/lm13700.pdf" H 5900 1525 50  0001 C CNN
	4    6200 1500
	1    0    0    -1  
$EndComp
$Comp
L Amplifier_Operational:LM13700 U8
U 5 1 5C4E41D9
P 5350 1500
F 0 "U8" H 5308 1546 50  0000 L CNN
F 1 "LM13700" H 5308 1455 50  0000 L CNN
F 2 "Package_DIP:DIP-16_W7.62mm_Socket_LongPads" H 5050 1525 50  0001 C CNN
F 3 "http://www.ti.com/lit/ds/symlink/lm13700.pdf" H 5050 1525 50  0001 C CNN
	5    5350 1500
	1    0    0    -1  
$EndComp
$Comp
L power:+12V #PWR0152
U 1 1 5C4E425A
P 5250 1200
F 0 "#PWR0152" H 5250 1050 50  0001 C CNN
F 1 "+12V" H 5265 1373 50  0000 C CNN
F 2 "" H 5250 1200 50  0001 C CNN
F 3 "" H 5250 1200 50  0001 C CNN
	1    5250 1200
	1    0    0    -1  
$EndComp
$Comp
L power:-12V #PWR0153
U 1 1 5C4E4287
P 5250 1800
F 0 "#PWR0153" H 5250 1900 50  0001 C CNN
F 1 "-12V" V 5265 1928 50  0000 L CNN
F 2 "" H 5250 1800 50  0001 C CNN
F 3 "" H 5250 1800 50  0001 C CNN
	1    5250 1800
	0    1    1    0   
$EndComp
$Comp
L Device:R R58
U 1 1 5C4E42B4
P 5300 850
F 0 "R58" V 5093 850 50  0000 C CNN
F 1 "30k" V 5184 850 50  0000 C CNN
F 2 "NilsLib:Widerstand_liegend" V 5230 850 50  0001 C CNN
F 3 "~" H 5300 850 50  0001 C CNN
	1    5300 850 
	0    1    1    0   
$EndComp
Wire Wire Line
	5650 1600 5750 1600
Wire Wire Line
	5750 850  5450 850 
Wire Wire Line
	5750 850  5750 1600
Wire Wire Line
	4200 1400 4200 850 
Wire Wire Line
	4200 850  5150 850 
Connection ~ 4200 1400
$Comp
L Device:R R55
U 1 1 5C4E5229
P 4650 1600
F 0 "R55" V 4443 1600 50  0000 C CNN
F 1 "200k" V 4534 1600 50  0000 C CNN
F 2 "NilsLib:Widerstand_liegend" V 4580 1600 50  0001 C CNN
F 3 "~" H 4650 1600 50  0001 C CNN
	1    4650 1600
	0    1    1    0   
$EndComp
Wire Wire Line
	4800 1600 4900 1600
Wire Wire Line
	4500 1600 4350 1600
$Comp
L Device:R R57
U 1 1 5C4E5E6F
P 4900 2000
F 0 "R57" H 4830 1954 50  0000 R CNN
F 1 "1k" H 4830 2045 50  0000 R CNN
F 2 "NilsLib:Widerstand_liegend" V 4830 2000 50  0001 C CNN
F 3 "~" H 4900 2000 50  0001 C CNN
	1    4900 2000
	-1   0    0    1   
$EndComp
Wire Wire Line
	4900 1850 4900 1600
Connection ~ 4900 1600
Wire Wire Line
	4900 1600 5050 1600
Wire Wire Line
	4900 2150 4900 2300
$Comp
L power:GND #PWR0154
U 1 1 5C4E6C35
P 4900 2300
F 0 "#PWR0154" H 4900 2050 50  0001 C CNN
F 1 "GND" H 4905 2127 50  0000 C CNN
F 2 "" H 4900 2300 50  0001 C CNN
F 3 "" H 4900 2300 50  0001 C CNN
	1    4900 2300
	1    0    0    -1  
$EndComp
Wire Wire Line
	5050 1400 4950 1400
Wire Wire Line
	4950 1400 4950 1000
Wire Wire Line
	4950 1000 4800 1000
Wire Wire Line
	4800 1000 4800 1050
$Comp
L power:GND #PWR0155
U 1 1 5C4E747D
P 4800 1050
F 0 "#PWR0155" H 4800 800 50  0001 C CNN
F 1 "GND" H 4805 877 50  0000 C CNN
F 2 "" H 4800 1050 50  0001 C CNN
F 3 "" H 4800 1050 50  0001 C CNN
	1    4800 1050
	1    0    0    -1  
$EndComp
Wire Wire Line
	5650 1500 5850 1500
$Comp
L Device:R R59
U 1 1 5C4E7D22
P 5850 1900
F 0 "R59" H 5780 1854 50  0000 R CNN
F 1 "30k" H 5780 1945 50  0000 R CNN
F 2 "NilsLib:Widerstand_liegend" V 5780 1900 50  0001 C CNN
F 3 "~" H 5850 1900 50  0001 C CNN
	1    5850 1900
	-1   0    0    1   
$EndComp
Wire Wire Line
	5850 1750 5850 1500
Connection ~ 5850 1500
Wire Wire Line
	5850 1500 5900 1500
Wire Wire Line
	5850 2050 5850 2150
$Comp
L power:GND #PWR0156
U 1 1 5C4E8FDA
P 5850 2150
F 0 "#PWR0156" H 5850 1900 50  0001 C CNN
F 1 "GND" H 5855 1977 50  0000 C CNN
F 2 "" H 5850 2150 50  0001 C CNN
F 3 "" H 5850 2150 50  0001 C CNN
	1    5850 2150
	1    0    0    -1  
$EndComp
$Comp
L Device:R R60
U 1 1 5C4E900F
P 6350 1850
F 0 "R60" H 6280 1804 50  0000 R CNN
F 1 "4.7k" H 6280 1895 50  0000 R CNN
F 2 "NilsLib:Widerstand_liegend" V 6280 1850 50  0001 C CNN
F 3 "~" H 6350 1850 50  0001 C CNN
	1    6350 1850
	-1   0    0    1   
$EndComp
Wire Wire Line
	6300 1600 6350 1600
Wire Wire Line
	6350 1600 6350 1700
Wire Wire Line
	6350 2000 6350 2150
$Comp
L power:-12V #PWR0157
U 1 1 5C4EAE95
P 6350 2150
F 0 "#PWR0157" H 6350 2250 50  0001 C CNN
F 1 "-12V" V 6365 2278 50  0000 L CNN
F 2 "" H 6350 2150 50  0001 C CNN
F 3 "" H 6350 2150 50  0001 C CNN
	1    6350 2150
	0    1    1    0   
$EndComp
$Comp
L Device:R R61
U 1 1 5C4EAECC
P 6750 1600
F 0 "R61" V 6543 1600 50  0000 C CNN
F 1 "150k" V 6634 1600 50  0000 C CNN
F 2 "NilsLib:Widerstand_liegend" V 6680 1600 50  0001 C CNN
F 3 "~" H 6750 1600 50  0001 C CNN
	1    6750 1600
	0    1    1    0   
$EndComp
Wire Wire Line
	6600 1600 6350 1600
Connection ~ 6350 1600
Wire Wire Line
	6900 1600 7150 1600
Wire Wire Line
	7150 1600 7150 1250
Text GLabel 7150 1250 0    50   Input ~ 0
RB
$Comp
L Amplifier_Operational:TL072 U6
U 1 1 5C4EC67E
P 2450 1800
F 0 "U6" H 2450 2167 50  0000 C CNN
F 1 "TL072" H 2450 2076 50  0000 C CNN
F 2 "Package_DIP:DIP-8_W7.62mm_Socket_LongPads" H 2450 1800 50  0001 C CNN
F 3 "http://www.ti.com/lit/ds/symlink/tl071.pdf" H 2450 1800 50  0001 C CNN
	1    2450 1800
	1    0    0    -1  
$EndComp
$Comp
L Amplifier_Operational:TL072 U6
U 3 1 5C4EC701
P 2450 1800
F 0 "U6" H 2408 1846 50  0000 L CNN
F 1 "TL072" H 2408 1755 50  0000 L CNN
F 2 "Package_DIP:DIP-8_W7.62mm_Socket_LongPads" H 2450 1800 50  0001 C CNN
F 3 "http://www.ti.com/lit/ds/symlink/tl071.pdf" H 2450 1800 50  0001 C CNN
	3    2450 1800
	1    0    0    -1  
$EndComp
$Comp
L Amplifier_Operational:TL072 U6
U 2 1 5C4EC780
P 3800 1400
F 0 "U6" H 3800 1767 50  0000 C CNN
F 1 "TL072" H 3800 1676 50  0000 C CNN
F 2 "Package_DIP:DIP-8_W7.62mm_Socket_LongPads" H 3800 1400 50  0001 C CNN
F 3 "http://www.ti.com/lit/ds/symlink/tl071.pdf" H 3800 1400 50  0001 C CNN
	2    3800 1400
	1    0    0    -1  
$EndComp
$Comp
L Amplifier_Operational:TL072 U7
U 1 1 5C4EC817
P 4850 3600
F 0 "U7" H 4850 3967 50  0000 C CNN
F 1 "TL072" H 4850 3876 50  0000 C CNN
F 2 "Package_DIP:DIP-8_W7.62mm_Socket_LongPads" H 4850 3600 50  0001 C CNN
F 3 "http://www.ti.com/lit/ds/symlink/tl071.pdf" H 4850 3600 50  0001 C CNN
	1    4850 3600
	1    0    0    -1  
$EndComp
$Comp
L Amplifier_Operational:TL072 U7
U 3 1 5C4EC88E
P 4850 3600
F 0 "U7" H 4808 3646 50  0000 L CNN
F 1 "TL072" H 4808 3555 50  0000 L CNN
F 2 "Package_DIP:DIP-8_W7.62mm_Socket_LongPads" H 4850 3600 50  0001 C CNN
F 3 "http://www.ti.com/lit/ds/symlink/tl071.pdf" H 4850 3600 50  0001 C CNN
	3    4850 3600
	1    0    0    -1  
$EndComp
$Comp
L power:-12V #PWR0158
U 1 1 5C4EC8FA
P 4750 3900
F 0 "#PWR0158" H 4750 4000 50  0001 C CNN
F 1 "-12V" V 4765 4028 50  0000 L CNN
F 2 "" H 4750 3900 50  0001 C CNN
F 3 "" H 4750 3900 50  0001 C CNN
	1    4750 3900
	0    1    1    0   
$EndComp
$Comp
L power:+12V #PWR0159
U 1 1 5C4EC937
P 4750 3300
F 0 "#PWR0159" H 4750 3150 50  0001 C CNN
F 1 "+12V" H 4765 3473 50  0000 C CNN
F 2 "" H 4750 3300 50  0001 C CNN
F 3 "" H 4750 3300 50  0001 C CNN
	1    4750 3300
	1    0    0    -1  
$EndComp
$Comp
L Device:R R54
U 1 1 5C4ECA6E
P 4200 3700
F 0 "R54" V 3993 3700 50  0000 C CNN
F 1 "30k" V 4084 3700 50  0000 C CNN
F 2 "NilsLib:Widerstand_liegend" V 4130 3700 50  0001 C CNN
F 3 "~" H 4200 3700 50  0001 C CNN
	1    4200 3700
	0    1    1    0   
$EndComp
Wire Wire Line
	4350 3700 4450 3700
Wire Wire Line
	4050 3700 3750 3700
Text GLabel 3750 3700 0    50   Input ~ 0
RA
$Comp
L Device:R R56
U 1 1 5C4EE35B
P 4850 4300
F 0 "R56" V 4643 4300 50  0000 C CNN
F 1 "120k" V 4734 4300 50  0000 C CNN
F 2 "NilsLib:Widerstand_liegend" V 4780 4300 50  0001 C CNN
F 3 "~" H 4850 4300 50  0001 C CNN
	1    4850 4300
	0    1    1    0   
$EndComp
Wire Wire Line
	5000 4300 5300 4300
Wire Wire Line
	5300 4300 5300 3600
Wire Wire Line
	5300 3600 5150 3600
Wire Wire Line
	4700 4300 4450 4300
Wire Wire Line
	4450 4300 4450 3700
Connection ~ 4450 3700
Wire Wire Line
	4450 3700 4550 3700
Wire Wire Line
	4550 3500 4500 3500
Wire Wire Line
	4500 3500 4500 3150
Wire Wire Line
	4500 3150 4350 3150
Wire Wire Line
	4350 3150 4350 3200
$Comp
L power:GND #PWR0160
U 1 1 5C4F1351
P 4350 3200
F 0 "#PWR0160" H 4350 2950 50  0001 C CNN
F 1 "GND" H 4355 3027 50  0000 C CNN
F 2 "" H 4350 3200 50  0001 C CNN
F 3 "" H 4350 3200 50  0001 C CNN
	1    4350 3200
	1    0    0    -1  
$EndComp
Wire Wire Line
	4350 2850 5300 2850
Wire Wire Line
	5300 2850 5300 3600
Wire Wire Line
	4350 1600 4350 2850
Connection ~ 5300 3600
$Comp
L Amplifier_Operational:TL072 U7
U 2 1 5C4F271B
P 6450 3400
F 0 "U7" H 6450 3767 50  0000 C CNN
F 1 "TL072" H 6450 3676 50  0000 C CNN
F 2 "Package_DIP:DIP-8_W7.62mm_Socket_LongPads" H 6450 3400 50  0001 C CNN
F 3 "http://www.ti.com/lit/ds/symlink/tl071.pdf" H 6450 3400 50  0001 C CNN
	2    6450 3400
	1    0    0    -1  
$EndComp
Wire Wire Line
	6150 3500 6150 3750
Wire Wire Line
	6150 3750 6800 3750
Wire Wire Line
	6800 3750 6800 3400
Wire Wire Line
	6800 3400 6750 3400
Wire Wire Line
	6150 3300 5850 3300
Wire Wire Line
	5850 3300 5850 3700
$Comp
L power:GND #PWR0161
U 1 1 5C4F523D
P 5850 3700
F 0 "#PWR0161" H 5850 3450 50  0001 C CNN
F 1 "GND" H 5855 3527 50  0000 C CNN
F 2 "" H 5850 3700 50  0001 C CNN
F 3 "" H 5850 3700 50  0001 C CNN
	1    5850 3700
	1    0    0    -1  
$EndComp
$Comp
L Device:C C10
U 1 1 5C4F535B
P 1250 3300
F 0 "C10" H 1365 3346 50  0000 L CNN
F 1 "100n" H 1365 3255 50  0000 L CNN
F 2 "NilsLib:Kondensator_Keramik" H 1288 3150 50  0001 C CNN
F 3 "~" H 1250 3300 50  0001 C CNN
	1    1250 3300
	1    0    0    -1  
$EndComp
$Comp
L Device:C C11
U 1 1 5C4F5E99
P 1250 3750
F 0 "C11" H 1365 3796 50  0000 L CNN
F 1 "100n" H 1365 3705 50  0000 L CNN
F 2 "NilsLib:Kondensator_Keramik" H 1288 3600 50  0001 C CNN
F 3 "~" H 1250 3750 50  0001 C CNN
	1    1250 3750
	1    0    0    -1  
$EndComp
Wire Wire Line
	1250 3600 1250 3500
$Comp
L Device:C C12
U 1 1 5C4F75C8
P 1800 3300
F 0 "C12" H 1915 3346 50  0000 L CNN
F 1 "100n" H 1915 3255 50  0000 L CNN
F 2 "NilsLib:Kondensator_Keramik" H 1838 3150 50  0001 C CNN
F 3 "~" H 1800 3300 50  0001 C CNN
	1    1800 3300
	1    0    0    -1  
$EndComp
$Comp
L Device:C C13
U 1 1 5C4F75CE
P 1800 3750
F 0 "C13" H 1915 3796 50  0000 L CNN
F 1 "100n" H 1915 3705 50  0000 L CNN
F 2 "NilsLib:Kondensator_Keramik" H 1838 3600 50  0001 C CNN
F 3 "~" H 1800 3750 50  0001 C CNN
	1    1800 3750
	1    0    0    -1  
$EndComp
Wire Wire Line
	1800 3600 1800 3500
$Comp
L Device:C C14
U 1 1 5C4F8D84
P 2200 3300
F 0 "C14" H 2315 3346 50  0000 L CNN
F 1 "100n" H 2315 3255 50  0000 L CNN
F 2 "NilsLib:Kondensator_Keramik" H 2238 3150 50  0001 C CNN
F 3 "~" H 2200 3300 50  0001 C CNN
	1    2200 3300
	1    0    0    -1  
$EndComp
$Comp
L Device:C C15
U 1 1 5C4F8D8A
P 2200 3750
F 0 "C15" H 2315 3796 50  0000 L CNN
F 1 "100n" H 2315 3705 50  0000 L CNN
F 2 "NilsLib:Kondensator_Keramik" H 2238 3600 50  0001 C CNN
F 3 "~" H 2200 3750 50  0001 C CNN
	1    2200 3750
	1    0    0    -1  
$EndComp
Wire Wire Line
	2200 3600 2200 3500
$Comp
L Device:C C16
U 1 1 5C4F8D91
P 2750 3300
F 0 "C16" H 2865 3346 50  0000 L CNN
F 1 "100n" H 2865 3255 50  0000 L CNN
F 2 "NilsLib:Kondensator_Keramik" H 2788 3150 50  0001 C CNN
F 3 "~" H 2750 3300 50  0001 C CNN
	1    2750 3300
	1    0    0    -1  
$EndComp
$Comp
L Device:C C17
U 1 1 5C4F8D97
P 2750 3750
F 0 "C17" H 2865 3796 50  0000 L CNN
F 1 "100n" H 2865 3705 50  0000 L CNN
F 2 "NilsLib:Kondensator_Keramik" H 2788 3600 50  0001 C CNN
F 3 "~" H 2750 3750 50  0001 C CNN
	1    2750 3750
	1    0    0    -1  
$EndComp
Wire Wire Line
	2750 3600 2750 3500
Wire Wire Line
	1250 3150 1250 3050
Wire Wire Line
	1250 3050 1800 3050
Wire Wire Line
	1800 3050 1800 3150
Wire Wire Line
	1800 3050 2200 3050
Wire Wire Line
	2200 3050 2200 3150
Connection ~ 1800 3050
Wire Wire Line
	2200 3050 2750 3050
Wire Wire Line
	2750 3050 2750 3150
Connection ~ 2200 3050
Wire Wire Line
	2750 3900 2750 4100
Wire Wire Line
	2750 4100 2200 4100
Wire Wire Line
	2200 4100 2200 3900
Wire Wire Line
	2200 4100 1800 4100
Wire Wire Line
	1800 4100 1800 3900
Connection ~ 2200 4100
Wire Wire Line
	1800 4100 1250 4100
Wire Wire Line
	1250 4100 1250 3900
Connection ~ 1800 4100
Wire Wire Line
	1250 3500 1800 3500
Connection ~ 1250 3500
Wire Wire Line
	1250 3500 1250 3450
Connection ~ 1800 3500
Wire Wire Line
	1800 3500 1800 3450
Wire Wire Line
	1800 3500 2200 3500
Connection ~ 2200 3500
Wire Wire Line
	2200 3500 2200 3450
Wire Wire Line
	2200 3500 2750 3500
Connection ~ 2750 3500
Wire Wire Line
	2750 3500 2750 3450
Wire Wire Line
	1250 3500 800  3500
Wire Wire Line
	800  3500 800  3650
$Comp
L power:GND #PWR0162
U 1 1 5C5115EC
P 800 3650
F 0 "#PWR0162" H 800 3400 50  0001 C CNN
F 1 "GND" H 805 3477 50  0000 C CNN
F 2 "" H 800 3650 50  0001 C CNN
F 3 "" H 800 3650 50  0001 C CNN
	1    800  3650
	1    0    0    -1  
$EndComp
$Comp
L power:+12V #PWR0163
U 1 1 5C51163F
P 1800 3050
F 0 "#PWR0163" H 1800 2900 50  0001 C CNN
F 1 "+12V" H 1815 3223 50  0000 C CNN
F 2 "" H 1800 3050 50  0001 C CNN
F 3 "" H 1800 3050 50  0001 C CNN
	1    1800 3050
	1    0    0    -1  
$EndComp
$Comp
L power:-12V #PWR0164
U 1 1 5C511692
P 2200 4100
F 0 "#PWR0164" H 2200 4200 50  0001 C CNN
F 1 "-12V" H 2215 4273 50  0000 C CNN
F 2 "" H 2200 4100 50  0001 C CNN
F 3 "" H 2200 4100 50  0001 C CNN
	1    2200 4100
	-1   0    0    1   
$EndComp
$Comp
L Amplifier_Operational:LM13700 U8
U 1 1 5C5126A5
P 8400 1300
F 0 "U8" H 8400 1667 50  0000 C CNN
F 1 "LM13700" H 8400 1576 50  0000 C CNN
F 2 "Package_DIP:DIP-16_W7.62mm_Socket_LongPads" H 8100 1325 50  0001 C CNN
F 3 "http://www.ti.com/lit/ds/symlink/lm13700.pdf" H 8100 1325 50  0001 C CNN
	1    8400 1300
	1    0    0    -1  
$EndComp
$Comp
L Amplifier_Operational:LM13700 U8
U 2 1 5C512744
P 9350 1300
F 0 "U8" H 9250 1648 50  0000 C CNN
F 1 "LM13700" H 9250 1557 50  0000 C CNN
F 2 "Package_DIP:DIP-16_W7.62mm_Socket_LongPads" H 9050 1325 50  0001 C CNN
F 3 "http://www.ti.com/lit/ds/symlink/lm13700.pdf" H 9050 1325 50  0001 C CNN
	2    9350 1300
	1    0    0    -1  
$EndComp
Wire Wire Line
	8100 1200 7950 1200
Wire Wire Line
	7950 1200 7950 1400
Wire Wire Line
	7950 1400 8100 1400
Wire Wire Line
	7950 1400 7950 1550
Connection ~ 7950 1400
$Comp
L power:GND #PWR0165
U 1 1 5C518D1F
P 7950 1550
F 0 "#PWR0165" H 7950 1300 50  0001 C CNN
F 1 "GND" H 7955 1377 50  0000 C CNN
F 2 "" H 7950 1550 50  0001 C CNN
F 3 "" H 7950 1550 50  0001 C CNN
	1    7950 1550
	1    0    0    -1  
$EndComp
NoConn ~ 8100 1300
NoConn ~ 8700 1300
NoConn ~ 8700 1400
NoConn ~ 9050 1300
NoConn ~ 9450 1400
NoConn ~ 5050 1500
$Comp
L Device:C C18
U 1 1 5C53EDBA
P 1250 5000
F 0 "C18" H 1365 5046 50  0000 L CNN
F 1 "100n" H 1365 4955 50  0000 L CNN
F 2 "NilsLib:Kondensator_Keramik" H 1288 4850 50  0001 C CNN
F 3 "~" H 1250 5000 50  0001 C CNN
	1    1250 5000
	1    0    0    -1  
$EndComp
$Comp
L Device:C C19
U 1 1 5C53EDC0
P 1250 5450
F 0 "C19" H 1365 5496 50  0000 L CNN
F 1 "100n" H 1365 5405 50  0000 L CNN
F 2 "NilsLib:Kondensator_Keramik" H 1288 5300 50  0001 C CNN
F 3 "~" H 1250 5450 50  0001 C CNN
	1    1250 5450
	1    0    0    -1  
$EndComp
Wire Wire Line
	1250 5300 1250 5200
$Comp
L Device:C C20
U 1 1 5C53EDC7
P 1800 5000
F 0 "C20" H 1915 5046 50  0000 L CNN
F 1 "100n" H 1915 4955 50  0000 L CNN
F 2 "NilsLib:Kondensator_Keramik" H 1838 4850 50  0001 C CNN
F 3 "~" H 1800 5000 50  0001 C CNN
	1    1800 5000
	1    0    0    -1  
$EndComp
$Comp
L Device:C C21
U 1 1 5C53EDCD
P 1800 5450
F 0 "C21" H 1915 5496 50  0000 L CNN
F 1 "100n" H 1915 5405 50  0000 L CNN
F 2 "NilsLib:Kondensator_Keramik" H 1838 5300 50  0001 C CNN
F 3 "~" H 1800 5450 50  0001 C CNN
	1    1800 5450
	1    0    0    -1  
$EndComp
Wire Wire Line
	1800 5300 1800 5200
$Comp
L Device:C C22
U 1 1 5C53EDD4
P 2200 5000
F 0 "C22" H 2315 5046 50  0000 L CNN
F 1 "100n" H 2315 4955 50  0000 L CNN
F 2 "NilsLib:Kondensator_Keramik" H 2238 4850 50  0001 C CNN
F 3 "~" H 2200 5000 50  0001 C CNN
	1    2200 5000
	1    0    0    -1  
$EndComp
$Comp
L Device:C C23
U 1 1 5C53EDDA
P 2200 5450
F 0 "C23" H 2315 5496 50  0000 L CNN
F 1 "100n" H 2315 5405 50  0000 L CNN
F 2 "NilsLib:Kondensator_Keramik" H 2238 5300 50  0001 C CNN
F 3 "~" H 2200 5450 50  0001 C CNN
	1    2200 5450
	1    0    0    -1  
$EndComp
Wire Wire Line
	2200 5300 2200 5200
$Comp
L Device:C C24
U 1 1 5C53EDE1
P 2750 5000
F 0 "C24" H 2865 5046 50  0000 L CNN
F 1 "100n" H 2865 4955 50  0000 L CNN
F 2 "NilsLib:Kondensator_Keramik" H 2788 4850 50  0001 C CNN
F 3 "~" H 2750 5000 50  0001 C CNN
	1    2750 5000
	1    0    0    -1  
$EndComp
$Comp
L Device:C C25
U 1 1 5C53EDE7
P 2750 5450
F 0 "C25" H 2865 5496 50  0000 L CNN
F 1 "100n" H 2865 5405 50  0000 L CNN
F 2 "NilsLib:Kondensator_Keramik" H 2788 5300 50  0001 C CNN
F 3 "~" H 2750 5450 50  0001 C CNN
	1    2750 5450
	1    0    0    -1  
$EndComp
Wire Wire Line
	2750 5300 2750 5200
Wire Wire Line
	1250 4850 1250 4750
Wire Wire Line
	1250 4750 1800 4750
Wire Wire Line
	1800 4750 1800 4850
Wire Wire Line
	1800 4750 2200 4750
Wire Wire Line
	2200 4750 2200 4850
Connection ~ 1800 4750
Wire Wire Line
	2200 4750 2750 4750
Wire Wire Line
	2750 4750 2750 4850
Connection ~ 2200 4750
Wire Wire Line
	2750 5600 2750 5800
Wire Wire Line
	2750 5800 2200 5800
Wire Wire Line
	2200 5800 2200 5600
Wire Wire Line
	2200 5800 1800 5800
Wire Wire Line
	1800 5800 1800 5600
Connection ~ 2200 5800
Wire Wire Line
	1800 5800 1250 5800
Wire Wire Line
	1250 5800 1250 5600
Connection ~ 1800 5800
Wire Wire Line
	1250 5200 1800 5200
Connection ~ 1250 5200
Wire Wire Line
	1250 5200 1250 5150
Connection ~ 1800 5200
Wire Wire Line
	1800 5200 1800 5150
Wire Wire Line
	1800 5200 2200 5200
Connection ~ 2200 5200
Wire Wire Line
	2200 5200 2200 5150
Wire Wire Line
	2200 5200 2750 5200
Connection ~ 2750 5200
Wire Wire Line
	2750 5200 2750 5150
Wire Wire Line
	1250 5200 800  5200
Wire Wire Line
	800  5200 800  5350
$Comp
L power:GND #PWR0166
U 1 1 5C53EE0D
P 800 5350
F 0 "#PWR0166" H 800 5100 50  0001 C CNN
F 1 "GND" H 805 5177 50  0000 C CNN
F 2 "" H 800 5350 50  0001 C CNN
F 3 "" H 800 5350 50  0001 C CNN
	1    800  5350
	1    0    0    -1  
$EndComp
$Comp
L power:+12V #PWR0167
U 1 1 5C53EE13
P 1800 4750
F 0 "#PWR0167" H 1800 4600 50  0001 C CNN
F 1 "+12V" H 1815 4923 50  0000 C CNN
F 2 "" H 1800 4750 50  0001 C CNN
F 3 "" H 1800 4750 50  0001 C CNN
	1    1800 4750
	1    0    0    -1  
$EndComp
$Comp
L power:-12V #PWR0168
U 1 1 5C53EE19
P 2200 5800
F 0 "#PWR0168" H 2200 5900 50  0001 C CNN
F 1 "-12V" H 2215 5973 50  0000 C CNN
F 2 "" H 2200 5800 50  0001 C CNN
F 3 "" H 2200 5800 50  0001 C CNN
	1    2200 5800
	-1   0    0    1   
$EndComp
$Comp
L Device:CP C26
U 1 1 5C5440B9
P 3300 5000
F 0 "C26" H 3418 5046 50  0000 L CNN
F 1 "10u" H 3418 4955 50  0000 L CNN
F 2 "NilsLib:Elko_D6.3mm_P2.50mm" H 3338 4850 50  0001 C CNN
F 3 "~" H 3300 5000 50  0001 C CNN
	1    3300 5000
	1    0    0    -1  
$EndComp
$Comp
L Device:CP C27
U 1 1 5C5441AD
P 3300 5450
F 0 "C27" H 3418 5496 50  0000 L CNN
F 1 "10u" H 3418 5405 50  0000 L CNN
F 2 "NilsLib:Elko_D6.3mm_P2.50mm" H 3338 5300 50  0001 C CNN
F 3 "~" H 3300 5450 50  0001 C CNN
	1    3300 5450
	1    0    0    -1  
$EndComp
Wire Wire Line
	2750 4750 3300 4750
Wire Wire Line
	3300 4750 3300 4850
Connection ~ 2750 4750
Wire Wire Line
	3300 5150 3300 5200
Wire Wire Line
	3300 5600 3250 5800
Wire Wire Line
	3250 5800 2750 5800
Connection ~ 2750 5800
Wire Wire Line
	2750 5200 3300 5200
Connection ~ 3300 5200
Wire Wire Line
	3300 5200 3300 5300
$Comp
L Connector_Generic:Conn_02x08_Odd_Even J8
U 1 1 5C559D07
P 5100 5550
F 0 "J8" H 5150 6067 50  0000 C CNN
F 1 "Conn_02x08_Odd_Even" H 5150 5976 50  0000 C CNN
F 2 "Connector_PinHeader_2.54mm:PinHeader_2x08_P2.54mm_Vertical" H 5100 5550 50  0001 C CNN
F 3 "~" H 5100 5550 50  0001 C CNN
	1    5100 5550
	1    0    0    -1  
$EndComp
Wire Wire Line
	4900 5250 4750 5250
Wire Wire Line
	4750 5250 4750 4900
Wire Wire Line
	4750 4900 5500 4900
Wire Wire Line
	5500 4900 5500 5250
Wire Wire Line
	5500 5250 5400 5250
Wire Wire Line
	4900 5350 4900 5450
Wire Wire Line
	4900 5450 4900 5550
Connection ~ 4900 5450
Wire Wire Line
	4900 5550 5400 5550
Connection ~ 4900 5550
Wire Wire Line
	5400 5550 5400 5450
Connection ~ 5400 5550
Wire Wire Line
	5400 5450 5400 5350
Connection ~ 5400 5450
Wire Wire Line
	4900 5650 5400 5650
Wire Wire Line
	5400 5650 5550 5650
Connection ~ 5400 5650
Wire Wire Line
	5400 5350 5750 5350
Connection ~ 5400 5350
$Comp
L power:GND #PWR0169
U 1 1 5C59197A
P 5950 5350
F 0 "#PWR0169" H 5950 5100 50  0001 C CNN
F 1 "GND" H 5955 5177 50  0000 C CNN
F 2 "" H 5950 5350 50  0001 C CNN
F 3 "" H 5950 5350 50  0001 C CNN
	1    5950 5350
	1    0    0    -1  
$EndComp
$Comp
L power:+12V #PWR0170
U 1 1 5C591AAB
P 5700 5650
F 0 "#PWR0170" H 5700 5500 50  0001 C CNN
F 1 "+12V" H 5715 5823 50  0000 C CNN
F 2 "" H 5700 5650 50  0001 C CNN
F 3 "" H 5700 5650 50  0001 C CNN
	1    5700 5650
	1    0    0    -1  
$EndComp
Connection ~ 4750 4900
$Comp
L power:-12V #PWR0171
U 1 1 5C591B18
P 4750 5250
F 0 "#PWR0171" H 4750 5350 50  0001 C CNN
F 1 "-12V" H 4765 5423 50  0000 C CNN
F 2 "" H 4750 5250 50  0001 C CNN
F 3 "" H 4750 5250 50  0001 C CNN
	1    4750 5250
	-1   0    0    1   
$EndComp
$Comp
L power:PWR_FLAG #FLG0101
U 1 1 5C591B9C
P 5500 4900
F 0 "#FLG0101" H 5500 4975 50  0001 C CNN
F 1 "PWR_FLAG" H 5500 5074 50  0000 C CNN
F 2 "" H 5500 4900 50  0001 C CNN
F 3 "~" H 5500 4900 50  0001 C CNN
	1    5500 4900
	1    0    0    -1  
$EndComp
Connection ~ 5500 4900
$Comp
L power:PWR_FLAG #FLG0102
U 1 1 5C591C10
P 5750 5350
F 0 "#FLG0102" H 5750 5425 50  0001 C CNN
F 1 "PWR_FLAG" H 5750 5524 50  0000 C CNN
F 2 "" H 5750 5350 50  0001 C CNN
F 3 "~" H 5750 5350 50  0001 C CNN
	1    5750 5350
	1    0    0    -1  
$EndComp
Connection ~ 5750 5350
Wire Wire Line
	5750 5350 5950 5350
$Comp
L power:PWR_FLAG #FLG0103
U 1 1 5C591C7F
P 5550 5650
F 0 "#FLG0103" H 5550 5725 50  0001 C CNN
F 1 "PWR_FLAG" H 5550 5824 50  0000 C CNN
F 2 "" H 5550 5650 50  0001 C CNN
F 3 "~" H 5550 5650 50  0001 C CNN
	1    5550 5650
	1    0    0    -1  
$EndComp
Connection ~ 5550 5650
Wire Wire Line
	5550 5650 5700 5650
NoConn ~ 4900 5750
NoConn ~ 4900 5850
NoConn ~ 4900 5950
NoConn ~ 5400 5950
NoConn ~ 5400 5850
NoConn ~ 5400 5750
Connection ~ 4750 5250
$EndSCHEMATC
