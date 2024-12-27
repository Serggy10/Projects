*version 8.0 2017180790
u 127
L? 2
C? 5
R? 6
U? 2
M? 2
V? 2
D? 3
@libraries
@analysis
.TRAN 1 0 0 0
+0 20ns
+1 320us
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
pageloc 1 0 7368 
@status
n 0 122:05:10:15:54:00;1654869240 e 
s 2832 122:05:10:15:54:00;1654869240 e 
*page 1 0 297 210 ma
@ports
port 120 GND_EARTH 340 330 h
@parts
part 101 L 580 140 d
a 0 sp 0 0 0 10 hlb 100 PART=L
a 0 s 0:13 0 0 0 hln 100 PKGTYPE=L2012C
a 0 s 0:13 0 0 0 hln 100 GATE=
a 0 ap 9 0 21 0 hln 100 REFDES=L1
a 0 u 13 0 31 -3 hln 100 VALUE=5.1u
a 0 a 0:13 0 0 0 hln 100 PKGREF=L1
part 102 c 550 180 v
a 0 u 13 0 15 25 hln 100 VALUE=100N
a 0 sp 0 0 0 10 hlb 100 PART=c
a 0 s 0:13 0 0 0 hln 100 PKGTYPE=C1005
a 0 s 0:13 0 0 0 hln 100 GATE=
a 0 a 0:13 0 0 0 hln 100 PKGREF=C1
a 0 ap 9 0 15 0 hln 100 REFDES=C1
part 103 r 530 320 v
a 0 sp 0 0 0 10 hlb 100 PART=r
a 0 s 0:13 0 0 0 hln 100 PKGTYPE=RC05
a 0 s 0:13 0 0 0 hln 100 GATE=
a 0 u 13 0 15 25 hln 100 VALUE=1meg
a 0 a 0:13 0 0 0 hln 100 PKGREF=R1
a 0 ap 9 0 15 0 hln 100 REFDES=R1
part 104 555b 430 210 h
a 0 sp 11 0 66 100 hlb 100 PART=555b
a 0 s 0:13 0 0 0 hln 100 PKGTYPE=TO-99
a 0 s 0:13 0 0 0 hln 100 GATE=
a 1 ap 9 0 70 8 hln 100 REFDES=U1
a 0 a 0:13 0 0 0 hln 100 PKGREF=U1
part 105 c 410 330 v
a 0 sp 0 0 0 10 hlb 100 PART=c
a 0 s 0:13 0 0 0 hln 100 PKGTYPE=C1005
a 0 s 0:13 0 0 0 hln 100 GATE=
a 0 a 0:13 0 0 0 hln 100 PKGREF=C2
a 0 ap 9 0 15 0 hln 100 REFDES=C2
part 107 IRF520 550 260 h
a 0 sp 11 0 10 40 hcn 100 PART=IRF520
a 0 s 0:13 0 0 0 hln 100 PKGTYPE=TO-220AB
a 0 s 0:13 0 0 0 hln 100 GATE=
a 0 a 0:13 0 0 0 hln 100 PKGREF=M1
a 0 ap 9 0 5 10 hcn 100 REFDES=M1
part 108 r 580 240 v
a 0 sp 0 0 0 10 hlb 100 PART=r
a 0 s 0:13 0 0 0 hln 100 PKGTYPE=RC05
a 0 s 0:13 0 0 0 hln 100 GATE=
a 0 ap 9 0 15 0 hln 100 REFDES=R2
a 0 u 13 0 15 25 hln 100 VALUE=0.01
a 0 a 0:13 0 0 0 hln 100 PKGREF=R2
part 109 VDC 280 210 h
a 0 sp 0 0 22 37 hln 100 PART=VDC
a 1 u 13 0 -11 18 hcn 100 DC=5V
a 0 a 0:13 0 0 0 hln 100 PKGREF=V1
a 1 ap 9 0 24 7 hcn 100 REFDES=V1
part 110 c 320 260 v
a 0 sp 0 0 0 10 hlb 100 PART=c
a 0 s 0:13 0 0 0 hln 100 PKGTYPE=C1005
a 0 s 0:13 0 0 0 hln 100 GATE=
a 0 u 13 0 15 25 hln 100 VALUE=20u
a 0 a 0:13 0 0 0 hln 100 PKGREF=C3
a 0 ap 9 0 15 0 hln 100 REFDES=C3
part 111 1n4148 390 210 d
a 0 sp 11 0 15 25 hln 100 PART=1n4148
a 0 s 0:13 0 0 0 hln 100 PKGTYPE=DO-35
a 0 s 0:13 0 0 0 hln 100 GATE=
a 0 a 0:13 0 0 0 hln 100 PKGREF=D1
a 0 ap 9 0 15 0 hln 100 REFDES=D1
part 113 c 380 320 v
a 0 sp 0 0 0 10 hlb 100 PART=c
a 0 s 0:13 0 0 0 hln 100 PKGTYPE=C1005
a 0 s 0:13 0 0 0 hln 100 GATE=
a 0 u 13 0 5 5 hln 100 VALUE=100p
a 0 a 0:13 0 0 0 hln 100 PKGREF=C4
a 0 ap 9 0 15 0 hln 100 REFDES=C4
part 115 1n4148 360 240 v
a 0 sp 11 0 15 25 hln 100 PART=1n4148
a 0 s 0:13 0 0 0 hln 100 PKGTYPE=DO-35
a 0 s 0:13 0 0 0 hln 100 GATE=
a 0 ap 9 0 15 0 hln 100 REFDES=D2
a 0 a 0:13 0 0 0 hln 100 PKGREF=D2
part 116 r 360 280 v
a 0 sp 0 0 0 10 hlb 100 PART=r
a 0 s 0:13 0 0 0 hln 100 PKGTYPE=RC05
a 0 s 0:13 0 0 0 hln 100 GATE=
a 0 u 13 0 15 25 hln 100 VALUE=37966
a 0 a 0:13 0 0 0 hln 100 PKGREF=R3
a 0 ap 9 0 15 0 hln 100 REFDES=R3
part 117 r 390 280 v
a 0 sp 0 0 0 10 hlb 100 PART=r
a 0 s 0:13 0 0 0 hln 100 PKGTYPE=RC05
a 0 s 0:13 0 0 0 hln 100 GATE=
a 0 u 13 0 15 25 hln 100 VALUE=15310
a 0 a 0:13 0 0 0 hln 100 PKGREF=R4
a 0 ap 9 0 15 0 hln 100 REFDES=R4
part 118 r 380 180 v
a 0 sp 0 0 0 10 hlb 100 PART=r
a 0 s 0:13 0 0 0 hln 100 PKGTYPE=RC05
a 0 s 0:13 0 0 0 hln 100 GATE=
a 0 u 13 0 19 25 hln 100 VALUE=10000
a 0 a 0:13 0 0 0 hln 100 PKGREF=R5
a 0 ap 9 0 15 0 hln 100 REFDES=R5
part 1 CAJETIN_DTE_EII 1188 840 h
a 0 s 0:11 0 0 10 hlb 100 PART=CAJETIN_DTE_EII
a 1 s 13 0 350 10 hcn 100 PAGESIZE=A4
a 1 s 13 0 180 60 hcn 100 PAGETITLE=
a 1 s 13 0 300 95 hrn 100 PAGENO=1
a 1 s 13 0 340 95 hrn 100 PAGECOUNT=1
part 122 iMarker 580 140 h
a 0 s 0 0 0 0 hln 100 PROBEVAR=
a 0 s 0 0 0 0 hln 100 PROBEVAR=
a 0 s 0 0 0 0 hln 100 PROBEVAR=
a 0 s 0 0 0 0 hln 100 PROBEVAR=I(L1)
a 0 s 0 0 0 0 hln 100 PROBEVAR=
a 0 a 0 0 6 20 hlb 100 LABEL=3
part 123 nodeMarker 530 220 h
a 0 s 0 0 0 0 hln 100 PROBEVAR=
a 0 s 0 0 0 0 hln 100 PROBEVAR=
a 0 s 0 0 0 0 hln 100 PROBEVAR=
a 0 s 0 0 0 0 hln 100 PROBEVAR=
a 0 a 0 0 4 22 hlb 100 LABEL=5
part 124 iMarker 550 260 h
a 0 s 0 0 0 0 hln 100 PROBEVAR=
a 0 s 0 0 0 0 hln 100 PROBEVAR=
a 0 s 0 0 0 0 hln 100 PROBEVAR=
a 0 s 0 0 0 0 hln 100 PROBEVAR=
a 0 a 0 0 6 20 hlb 100 LABEL=4
part 125 iMarker 280 210 h
a 0 s 0 0 0 0 hln 100 PROBEVAR=
a 0 s 0 0 0 0 hln 100 PROBEVAR=
a 0 a 0 0 6 20 hlb 100 LABEL=6
part 126 iMarker 320 230 h
a 0 s 0 0 0 0 hln 100 PROBEVAR=
a 0 s 0 0 0 0 hln 100 PROBEVAR=
a 0 a 0 0 6 20 hlb 100 LABEL=7
@conn
w 3
s 550 200 550 180 2
s 580 200 550 200 4
a 0 up 33 0 565 199 hct 100 V=
w 7
s 380 320 380 330 8
s 480 280 480 330 12
s 530 330 480 330 14
s 530 320 530 330 16
s 580 280 580 330 18
s 580 330 530 330 20
a 0 up 33 0 515 329 hct 100 V=
s 480 330 410 330 22
s 280 250 280 330 24
s 280 330 320 330 28
s 320 330 340 330 32
s 320 260 320 330 30
s 410 330 380 330 106
s 340 330 380 330 121
w 34
s 530 220 530 260 35
a 0 up 33 0 532 270 hlt 100 V=
s 530 260 530 280 39
s 550 260 530 260 37
w 41
s 550 150 550 140 40
s 550 140 580 140 42
s 430 220 410 220 44
s 410 220 410 140 48
s 410 140 480 140 50
s 480 140 550 140 54
s 480 180 480 140 52
s 280 210 280 140 57
s 280 140 320 140 61
a 0 up 33 0 430 139 hct 100 V=
s 320 140 380 140 65
s 320 230 320 140 63
s 380 140 410 140 119
w 67
s 430 230 410 230 66
s 410 230 410 300 68
a 0 up 33 0 412 265 hlt 100 V=
w 71
s 430 240 420 240 70
s 420 240 420 210 72
s 420 210 430 210 74
s 420 240 420 290 76
a 0 up 33 0 422 265 hlt 100 V=
s 420 290 390 290 80
s 390 280 390 290 82
s 390 290 380 290 85
s 360 290 360 280 87
s 380 290 360 290 114
w 90
s 380 180 380 210 89
s 400 210 400 250 93
a 0 up 33 0 402 230 hlt 100 V=
s 400 250 430 250 95
s 380 210 390 210 97
s 380 210 360 210 99
s 390 210 400 210 112
@junction
j 480 330
+ w 7
+ w 7
j 530 330
+ w 7
+ w 7
j 380 330
+ w 7
+ w 7
j 320 330
+ w 7
+ w 7
j 530 260
+ w 34
+ w 34
j 550 140
+ w 41
+ w 41
j 480 140
+ w 41
+ w 41
j 410 140
+ w 41
+ w 41
j 320 140
+ w 41
+ w 41
j 420 240
+ w 71
+ w 71
j 390 290
+ w 71
+ w 71
j 380 210
+ w 90
+ w 90
j 580 200
+ p 101 2
+ w 3
j 580 140
+ p 101 1
+ w 41
j 550 180
+ p 102 1
+ w 3
j 550 150
+ p 102 2
+ w 41
j 530 320
+ p 103 1
+ w 7
j 530 280
+ p 103 2
+ w 34
j 480 280
+ p 104 GND
+ w 7
j 530 220
+ p 104 OUTPUT
+ w 34
j 430 220
+ p 104 RESET
+ w 41
j 480 180
+ p 104 VCC
+ w 41
j 430 230
+ p 104 CONTROL
+ w 67
j 430 210
+ p 104 TRIGGER
+ w 71
j 430 240
+ p 104 THRESHOLD
+ w 71
j 430 250
+ p 104 DISCHARGE
+ w 90
j 410 330
+ p 105 1
+ w 7
j 410 300
+ p 105 2
+ w 67
j 580 280
+ p 107 s
+ w 7
j 550 260
+ p 107 g
+ w 34
j 580 200
+ p 108 2
+ p 101 2
j 580 240
+ p 108 1
+ p 107 d
j 580 200
+ p 108 2
+ w 3
j 280 250
+ p 109 -
+ w 7
j 280 210
+ p 109 +
+ w 41
j 320 260
+ p 110 1
+ w 7
j 320 230
+ p 110 2
+ w 41
j 390 210
+ p 111 1
+ w 90
j 380 320
+ p 113 1
+ w 7
j 380 290
+ p 113 2
+ w 71
j 360 210
+ p 115 2
+ w 90
j 360 240
+ p 116 2
+ p 115 1
j 360 280
+ p 116 1
+ w 71
j 390 240
+ p 117 2
+ p 111 2
j 390 280
+ p 117 1
+ w 71
j 380 140
+ p 118 2
+ w 41
j 380 180
+ p 118 1
+ w 90
j 340 330
+ s 120
+ w 7
j 580 140
+ p 122 pin1
+ p 101 1
j 580 140
+ p 122 pin1
+ w 41
j 530 220
+ p 123 pin1
+ p 104 OUTPUT
j 530 220
+ p 123 pin1
+ w 34
j 550 260
+ p 124 pin1
+ p 107 g
j 550 260
+ p 124 pin1
+ w 34
j 280 210
+ p 125 pin1
+ p 109 +
j 280 210
+ p 125 pin1
+ w 41
j 320 230
+ p 126 pin1
+ p 110 2
j 320 230
+ p 126 pin1
+ w 41
@attributes
a 0 s 0:13 0 0 0 hln 100 PAGETITLE=
a 0 s 0:13 0 0 0 hln 100 PAGENO=1
a 0 s 0:13 0 0 0 hln 100 PAGESIZE=A4
a 0 s 0:13 0 0 0 hln 100 PAGECOUNT=1
@graphics
