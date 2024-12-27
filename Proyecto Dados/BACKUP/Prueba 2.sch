*version 8.0 315016038
u 142
V? 3
P? 2
? 6
L? 2
@libraries
@analysis
.TRAN 1 1 1 0
+0 20000ns
+1 0.0001s
+2 0.00001
@targets
@attributes
@translators
a 0 u 13 0 0 0 hln 100 TANGO=PCB
a 0 u 13 0 0 0 hln 100 SCICARDS=PCB
a 0 u 13 0 0 0 hln 100 PROTEL=PCB
a 0 u 13 0 0 0 hln 100 PCBOARDS=PCB
a 0 u 13 0 0 0 hln 100 PCAD=PCB
a 0 u 13 0 0 0 hln 100 PADS=PCB
a 0 u 13 0 0 0 hln 100 ORCAD=PCB
a 0 u 13 0 0 0 hln 100 EDIF=PCB
a 0 u 13 0 0 0 hln 100 CADSTAR=PCB
a 0 u 13 0 0 0 hln 100 PSPICE=PSPICE
a 0 u 13 0 0 0 hln 100 XILINX=XILINX
a 0 u 13 0 0 0 hln 100 POLARIS=PSPICE
@setup
unconnectedPins 0
connectViaLabel 0
connectViaLocalLabels 0
NoStim4ExtIFPortsWarnings 1
AutoGenStim4ExtIFPorts 1
@index
pageloc 1 0 7242 
@status
n 2453 122:06:04:20:14:08;1656958448 e 
s 0 122:06:04:20:14:12;1656958452 e 
i PCBOARDS 122:06:04:18:19:36;1656951576 e 2453 
c 122:06:04:20:17:45;1656958665
*page 1 0 297 210 ma
@ports
port 114 GND_EARTH 270 310 h
@parts
part 91 1n4148 540 260 V
a 0 s 0:13 0 0 0 hln 100 PKGTYPE=DO-35
a 0 s 0:13 0 0 0 hln 100 GATE=
a 0 x 0:13 0 0 0 hln 100 PKGREF=D2
a 0 xp 9 0 17 4 hln 100 REFDES=D2
a 0 sp 11 0 7 1 hln 100 PART=1n4148
part 96 r 590 190 V
a 0 sp 0 0 0 10 hlb 100 PART=r
a 0 s 0:13 0 0 0 hln 100 PKGTYPE=RC05
a 0 s 0:13 0 0 0 hln 100 GATE=
a 0 u 13 0 5 1 hln 100 VALUE=10k
a 0 x 0:13 0 0 0 hln 100 PKGREF=R1
a 0 xp 9 0 15 0 hln 100 REFDES=R1
part 97 1n4148 590 230 D
a 0 s 0:13 0 0 0 hln 100 PKGTYPE=DO-35
a 0 s 0:13 0 0 0 hln 100 GATE=
a 0 x 0:13 0 0 0 hln 100 PKGREF=D1
a 0 sp 11 0 23 51 hln 100 PART=1n4148
a 0 xp 9 0 15 34 hln 100 REFDES=D1
part 98 c 330 200 v
a 0 x 0:13 0 0 0 hln 100 PKGTYPE=CK05
a 0 x 0:13 0 0 0 hln 100 PKGREF=C2
a 0 xp 9 0 11 34 hln 100 REFDES=C2
a 0 sp 0 0 0 10 hlb 100 PART=c
a 0 s 0:13 0 0 0 hln 100 GATE=
a 0 u 13 0 1 37 hln 100 VALUE=100n
part 107 Jump1 240 140 h
a 0 sp 11 0 0 30 hln 100 PART=Jump1
a 0 s 0:13 0 0 0 hln 100 PKGTYPE=Jump1
a 0 s 0:13 0 0 0 hln 100 GATE=
a 0 x 13 0 -2 12 hln 100 PKGREF=P1
a 0 xp 0 0 0 0 hln 100 REFDES=P1
part 95 r 590 230 V
a 0 sp 0 0 0 10 hlb 100 PART=r
a 0 s 0:13 0 0 0 hln 100 PKGTYPE=RC05
a 0 s 0:13 0 0 0 hln 100 GATE=
a 0 x 0:13 0 0 0 hln 100 PKGREF=R2
a 0 xp 9 0 23 2 hln 100 REFDES=R2
a 0 u 13 0 11 3 hln 100 VALUE=10000
part 116 L 370 210 v
a 0 sp 0 0 0 10 hlb 100 PART=L
a 0 s 0:13 0 0 0 hln 100 PKGTYPE=L2012C
a 0 s 0:13 0 0 0 hln 100 GATE=
a 0 a 0:13 0 0 0 hln 100 PKGREF=L1
a 0 ap 9 0 33 28 hln 100 REFDES=L1
a 0 u 13 0 23 41 hln 100 VALUE=5.11u
part 99 VDC 270 220 h
a 0 sp 0 0 22 37 hln 100 PART=VDC
a 1 u 13 0 -11 18 hcn 100 DC=5V
a 0 a 0:13 0 0 0 hln 100 PKGREF=V1
a 1 ap 9 0 24 7 hcn 100 REFDES=V1
part 102 c 500 310 V
a 0 x 0:13 0 0 0 hln 100 PKGTYPE=CK05
a 0 sp 0 0 0 10 hlb 100 PART=c
a 0 s 0:13 0 0 0 hln 100 GATE=
a 0 x 0:13 0 0 0 hln 100 PKGREF=C3
a 0 xp 9 0 15 0 hln 100 REFDES=C3
a 0 u 13 0 3 1 hln 100 VALUE=1n
part 104 555D 480 230 H
a 0 sp 11 0 66 100 hlb 100 PART=555D
a 0 s 0:13 0 0 0 hln 100 PKGTYPE=DIP8
a 0 s 0:13 0 0 0 hln 100 GATE=
a 0 x 0:13 0 0 0 hln 100 PKGREF=U1
a 1 xp 9 0 70 8 hln 100 REFDES=U1
part 105 C_ELECTROLITICO 310 230 d
a 0 sp 0 0 0 10 hlb 100 PART=C_ELECTROLITICO
a 0 s 0:13 0 0 0 hln 100 GATE=
a 0 x 0:13 0 0 0 hln 100 PKGREF=C1
a 0 u 13 0 25 33 hln 100 VALUE=22U
a 0 xp 9 0 17 30 hln 100 REFDES=C1
a 0 x 0:13 0 0 0 hln 100 PKGTYPE=PLP3481/AA
part 106 r 370 300 v
a 0 sp 0 0 0 10 hlb 100 PART=r
a 0 s 0:13 0 0 0 hln 100 PKGTYPE=RC05
a 0 s 0:13 0 0 0 hln 100 GATE=
a 0 u 13 0 15 7 hln 100 VALUE=1MEG
a 0 x 0:13 0 0 0 hln 100 PKGREF=R4
a 0 xp 9 0 25 6 hln 100 REFDES=R4
part 108 Jump1 240 280 h
a 0 sp 11 0 0 30 hln 100 PART=Jump1
a 0 s 0:13 0 0 0 hln 100 PKGTYPE=Jump1
a 0 s 0:13 0 0 0 hln 100 GATE=
a 0 x 13 0 -2 14 hln 100 PKGREF=P2
a 0 xp 0 0 0 0 hln 100 REFDES=P2
part 110 Jump1 240 300 h
a 0 sp 11 0 0 30 hln 100 PART=Jump1
a 0 s 0:13 0 0 0 hln 100 PKGTYPE=Jump1
a 0 s 0:13 0 0 0 hln 100 GATE=
a 0 x 13 0 -2 14 hln 100 PKGREF=P3
a 0 xp 0 0 0 0 hln 100 REFDES=P3
part 101 C 590 310 V
a 0 u 13 0 3 -1 hln 100 VALUE=100p
a 0 x 0:13 0 0 0 hln 100 PKGTYPE=CK05
a 0 sp 0 0 0 10 hlb 100 PART=C
a 0 s 0:13 0 0 0 hln 100 GATE=
a 0 x 0:13 0 0 0 hln 100 PKGREF=C4
a 0 xp 9 0 15 0 hln 100 REFDES=C4
part 93 r 540 230 V
a 0 sp 0 0 0 10 hlb 100 PART=r
a 0 s 0:13 0 0 0 hln 100 PKGTYPE=RC05
a 0 s 0:13 0 0 0 hln 100 GATE=
a 0 x 0:13 0 0 0 hln 100 PKGREF=R3
a 0 xp 9 0 23 4 hln 100 REFDES=R3
a 0 u 13 0 13 3 hln 100 VALUE=30000
part 100 IRF520 360 240 H
a 0 s 0:13 0 0 0 hln 100 PKGTYPE=TO-220AB
a 0 s 0:13 0 0 0 hln 100 GATE=
a 0 sp 11 0 -4 32 hcn 100 PART=IRF520
a 0 x 0:13 0 0 0 hln 100 PKGREF=Q1
a 0 xp 9 0 3 16 hcn 100 REFDES=Q1
part 1 CAJETIN_DTE_EII 1188 840 h
a 0 s 0:11 0 0 10 hlb 100 PART=CAJETIN_DTE_EII
a 1 s 13 0 350 10 hcn 100 PAGESIZE=A4
a 1 s 13 0 180 60 hcn 100 PAGETITLE=
a 1 s 13 0 340 95 hrn 100 PAGECOUNT=1
a 1 s 13 0 300 95 hrn 100 PAGENO=1
part 121 iMarker 370 210 h
a 0 s 0 0 0 0 hln 100 PROBEVAR=-I(L1)
a 0 a 0 0 6 20 hlb 100 LABEL=2
part 127 nodeMarker 370 240 h
a 0 s 0 0 0 0 hln 100 PROBEVAR=
a 0 a 0 0 4 22 hlb 100 LABEL=5
@conn
w 11
a 0 up 0:33 0 0 0 hln 100 V=
s 500 250 480 250 10
s 500 280 500 250 12
a 0 up 33 0 502 265 hlt 100 V=
w 15
a 0 up 0:33 0 0 0 hln 100 V=
s 480 260 510 260 14
s 510 260 510 230 16
s 510 230 480 230 18
a 0 up 33 0 495 229 hct 100 V=
s 510 260 540 260 22
s 590 280 590 260 24
s 540 260 590 260 92
a 0 up 33 0 565 259 hct 100 V=
w 40
a 0 up 0:33 0 0 0 hln 100 V=
s 430 200 430 150 39
s 330 170 330 150 47
s 430 150 500 150 51
s 480 240 500 240 53
s 500 240 500 150 55
s 270 220 270 150 49
s 270 150 310 150 57
a 0 up 33 0 420 149 hct 100 V=
s 310 150 330 150 61
s 310 230 310 150 59
s 500 150 590 150 62
s 330 150 370 150 112
a 0 up 33 0 380 149 hct 100 V=
s 370 150 430 150 117
w 34
a 0 up 0:33 0 0 0 hln 100 V=
s 330 220 330 210 35
a 0 up 33 0 332 210 hlt 100 V=
s 330 210 330 200 120
s 370 210 330 210 118
w 3
a 0 up 0:33 0 0 0 hln 100 V=
s 520 270 480 270 2
a 0 up 33 0 500 269 hct 100 V=
s 520 190 520 270 4
a 0 up 33 0 522 230 hlt 100 V=
s 590 190 540 190 8
s 540 190 520 190 94
w 136
a 0 up 0:33 0 0 0 hln 100 V=
s 270 310 270 320 64
s 310 310 270 310 66
s 310 260 310 310 68
s 330 310 310 310 70
s 330 260 330 310 72
s 430 310 370 310 76
a 0 up 33 0 385 309 hct 100 V=
s 370 310 330 310 80
s 370 300 370 310 78
s 430 300 430 310 81
s 430 310 500 310 85
s 270 260 270 290 89
s 500 310 590 310 103
a 0 up 33 0 545 309 hct 100 V=
s 270 290 270 310 109
w 27
a 0 up 0:33 0 0 0 hln 100 V=
s 370 240 380 240 32
s 370 260 370 240 30
a 0 up 33 0 372 250 hlt 100 V=
s 370 240 360 240 140
@junction
j 510 260
+ w 15
+ w 15
j 430 150
+ w 40
+ w 40
j 330 150
+ w 40
+ w 40
j 310 150
+ w 40
+ w 40
j 500 150
+ w 40
+ w 40
j 310 310
+ w 136
+ w 136
j 330 310
+ w 136
+ w 136
j 370 310
+ w 136
+ w 136
j 430 310
+ w 136
+ w 136
j 270 310
+ w 136
+ w 136
j 540 260
+ p 91 1
+ w 15
j 590 150
+ p 96 2
+ w 40
j 590 260
+ p 97 2
+ w 15
j 270 220
+ p 99 +
+ w 40
j 330 220
+ p 100 d
+ w 34
j 500 280
+ p 102 2
+ w 11
j 310 230
+ p 105 1
+ w 40
j 270 150
+ p 107 pin1
+ w 40
j 270 310
+ s 114
+ p 110 pin1
j 590 280
+ p 101 2
+ w 15
j 370 150
+ p 116 2
+ w 40
j 370 210
+ p 116 1
+ w 34
j 330 210
+ w 34
+ w 34
j 370 210
+ p 121 pin1
+ p 116 1
j 370 210
+ p 121 pin1
+ w 34
j 480 250
+ p 104 CONTROL
+ w 11
j 480 230
+ p 104 TRIGGER
+ w 15
j 480 260
+ p 104 THRESHOLD
+ w 15
j 380 240
+ p 104 OUTPUT
+ w 27
j 480 240
+ p 104 RESET
+ w 40
j 430 200
+ p 104 VCC
+ w 40
j 370 260
+ p 106 2
+ w 27
j 590 190
+ p 96 1
+ w 3
j 480 270
+ p 104 DISCHARGE
+ w 3
j 370 240
+ p 127 pin1
+ w 27
j 540 230
+ p 93 1
+ p 91 2
j 540 190
+ p 93 2
+ w 3
j 590 190
+ p 95 2
+ w 3
j 590 190
+ p 96 1
+ p 95 2
j 590 230
+ p 97 1
+ p 95 1
j 270 260
+ p 99 -
+ w 136
j 330 260
+ p 100 s
+ w 136
j 500 310
+ p 102 1
+ w 136
j 430 300
+ p 104 GND
+ w 136
j 310 260
+ p 105 2
+ w 136
j 370 300
+ p 106 1
+ w 136
j 270 290
+ p 108 pin1
+ w 136
j 270 310
+ p 110 pin1
+ w 136
j 270 310
+ s 114
+ w 136
j 590 310
+ p 101 1
+ w 136
j 330 200
+ p 98 1
+ w 34
j 330 170
+ p 98 2
+ w 40
j 360 240
+ p 100 g
+ w 27
@attributes
a 0 s 0:13 0 0 0 hln 100 PAGETITLE=
a 0 s 0:13 0 0 0 hln 100 PAGENO=1
a 0 s 0:13 0 0 0 hln 100 PAGESIZE=A4
a 0 s 0:13 0 0 0 hln 100 PAGECOUNT=1
@graphics
