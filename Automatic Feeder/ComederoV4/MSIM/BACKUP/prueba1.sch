*version 8.0 999182495
u 260
V? 5
Q? 3
U? 9
C? 5
R? 9
? 9
D? 4
@libraries
@analysis
.TRAN 1 0 0 0
+0 20ns
+1 4s
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
pageloc 1 0 5477 
@status
n 0 122:06:17:18:54:53;1658076893 e 
s 2832 122:06:17:18:54:53;1658076893 e 
*page 1 0 297 210 ma
@ports
port 124 GND_EARTH 390 210 h
@parts
part 123 1N4148 440 50 h
a 0 sp 11 0 15 25 hln 100 PART=1N4148
a 0 s 0:13 0 0 0 hln 100 PKGTYPE=DO-35
a 0 s 0:13 0 0 0 hln 100 GATE=
a 0 ap 9 0 15 0 hln 100 REFDES=D1
a 0 a 0:13 0 0 0 hln 100 PKGREF=D1
part 121 BC557C 490 100 h
a 0 sp 11 0 25 40 hln 100 PART=BC557C
a 0 s 0:13 0 0 0 hln 100 PKGTYPE=TO-92-18B
a 0 s 0:13 0 0 0 hln 100 GATE=
a 0 a 0:13 0 0 0 hln 100 PKGREF=Q2
a 0 ap 9 0 5 5 hln 100 REFDES=Q2
part 236 Sw_tOpen 740 110 v
a 0 sp 0 0 0 24 hln 100 PART=Sw_tOpen
a 0 s 0:13 0 0 0 hln 100 PKGTYPE=
a 0 a 0:13 0 0 0 hln 100 PKGREF=U7
a 0 ap 9 0 22 -20 hln 100 REFDES=U7
a 0 u 13 13 32 -10 hln 100 tOpen=1
part 119 Sw_tOpen 390 150 v
a 0 sp 0 0 0 24 hln 100 PART=Sw_tOpen
a 0 s 0:13 0 0 0 hln 100 PKGTYPE=
a 0 u 13 13 0 -4 hln 100 tOpen=1
a 0 a 0:13 0 0 0 hln 100 PKGREF=U2
a 0 ap 9 0 0 20 hln 100 REFDES=U2
part 240 Sw_tClose 780 70 d
a 0 sp 0 0 0 24 hln 100 PART=Sw_tClose
a 0 s 0:13 0 0 0 hln 100 PKGTYPE=
a 0 a 0:13 0 0 0 hln 100 PKGREF=U8
a 0 ap 9 0 0 20 hln 100 REFDES=U8
a 0 u 13 13 -2 -4 hln 100 tClose=1
part 115 VDC 390 160 h
a 0 x 0:13 0 0 0 hln 100 PKGREF=Transf
a 1 xp 9 0 24 7 hcn 100 REFDES=Transf
a 0 sp 0 0 22 37 hln 100 PART=VDC
a 1 u 13 0 -11 18 hcn 100 DC=12V
part 116 VDC 510 170 h
a 0 x 0:13 0 0 0 hln 100 PKGREF=Pila
a 1 xp 9 0 24 7 hcn 100 REFDES=Pila
a 0 sp 0 0 22 37 hln 100 PART=VDC
a 1 u 13 0 -11 18 hcn 100 DC=6V
part 120 C 630 160 v
a 0 sp 0 0 0 10 hlb 100 PART=C
a 0 s 0:13 0 0 0 hln 100 PKGTYPE=C1005
a 0 s 0:13 0 0 0 hln 100 GATE=
a 0 a 0:13 0 0 0 hln 100 PKGREF=C2
a 0 u 13 0 13 5 hln 100 VALUE=100u
a 0 ap 9 0 23 4 hln 100 REFDES=C2
part 177 R 740 160 v
a 0 sp 0 0 0 10 hlb 100 PART=R
a 0 s 0:13 0 0 0 hln 100 PKGTYPE=RC05
a 0 s 0:13 0 0 0 hln 100 GATE=
a 0 a 0:13 0 0 0 hln 100 PKGREF=R4
a 0 ap 9 0 25 0 hln 100 REFDES=R4
a 0 u 13 0 15 -1 hln 100 VALUE=120
part 253 R 450 170 v
a 0 sp 0 0 0 10 hlb 100 PART=R
a 0 s 0:13 0 0 0 hln 100 PKGTYPE=RC05
a 0 s 0:13 0 0 0 hln 100 GATE=
a 0 a 0:13 0 0 0 hln 100 PKGREF=R8
a 0 ap 9 0 25 38 hln 100 REFDES=R8
a 0 u 13 0 13 53 hln 100 VALUE=1MEG
part 235 R 780 160 v
a 0 sp 0 0 0 10 hlb 100 PART=R
a 0 s 0:13 0 0 0 hln 100 PKGTYPE=RC05
a 0 s 0:13 0 0 0 hln 100 GATE=
a 0 a 0:13 0 0 0 hln 100 PKGREF=R7
a 0 ap 9 0 23 36 hln 100 REFDES=R7
a 0 u 13 0 15 41 hln 100 VALUE=53.5
part 1 CAJETIN_DTE_EII 1188 840 h
a 0 s 0:11 0 0 10 hlb 100 PART=CAJETIN_DTE_EII
a 1 s 13 0 350 10 hcn 100 PAGESIZE=A4
a 1 s 13 0 180 60 hcn 100 PAGETITLE=
a 1 s 13 0 340 95 hrn 100 PAGECOUNT=1
a 1 s 13 0 300 95 hrn 100 PAGENO=1
part 127 iMarker 630 130 h
a 0 s 0 0 0 0 hln 100 PROBEVAR=
a 0 a 0 0 6 20 hlb 100 LABEL=2
part 125 iMarker 510 170 h
a 0 s 0 0 0 0 hln 100 PROBEVAR=
a 0 a 0 0 6 20 hlb 100 LABEL=1
part 128 iMarker 490 100 v
a 0 s 0 0 0 0 hln 100 PROBEVAR=
a 0 a 0 0 6 20 hlb 100 LABEL=4
part 251 iMarker 740 120 h
a 0 s 0 0 0 0 hln 100 PROBEVAR=
a 0 a 0 0 6 20 hlb 100 LABEL=7
part 252 iMarker 780 120 h
a 0 s 0 0 0 0 hln 100 PROBEVAR=
a 0 a 0 0 6 20 hlb 100 LABEL=8
@conn
w 81
a 0 up 0:33 0 0 0 hln 100 V=
s 510 120 510 170 80
a 0 up 33 0 512 145 hlt 100 V=
w 79
a 0 up 0:33 0 0 0 hln 100 V=
s 390 150 390 160 78
a 0 up 33 0 392 155 hlt 100 V=
w 179
a 0 up 0:33 0 0 0 hln 100 V=
s 630 50 630 130 101
s 470 50 510 50 122
a 0 up 33 0 570 49 hct 100 V=
s 630 50 740 50 171
s 510 50 630 50 218
s 510 80 510 50 215
s 740 70 740 50 238
s 740 50 780 50 243
s 780 50 780 70 245
w 239
a 0 up 0:33 0 0 0 hln 100 V=
s 740 120 740 110 192
a 0 up 33 0 742 115 hlt 100 V=
w 242
a 0 up 0:33 0 0 0 hln 100 V=
s 780 110 780 120 241
a 0 up 33 0 782 115 hlt 100 V=
w 107
a 0 up 0:33 0 0 0 hln 100 V=
s 390 50 440 50 106
a 0 up 33 0 450 49 hct 100 V=
s 390 110 390 100 226
s 390 100 390 50 234
s 390 100 450 100 112
a 0 up 33 0 440 99 hct 100 V=
s 450 100 490 100 256
s 450 130 450 100 254
w 248
a 0 up 0:33 0 0 0 hln 100 V=
s 780 160 780 210 247
s 740 160 740 210 182
s 390 200 390 210 84
s 630 210 510 210 94
s 630 160 630 210 92
s 510 210 450 210 117
a 0 up 33 0 450 209 hct 100 V=
s 740 210 630 210 136
a 0 up 33 0 410 209 hct 100 V=
s 780 210 740 210 249
s 450 210 390 210 259
s 450 170 450 210 257
@junction
j 630 50
+ w 179
+ w 179
j 630 130
+ p 127 pin1
+ p 120 2
j 510 170
+ p 125 pin1
+ p 116 +
j 630 210
+ w 248
+ w 248
j 630 130
+ p 120 2
+ w 179
j 470 50
+ p 123 2
+ w 179
j 630 130
+ p 127 pin1
+ w 179
j 740 120
+ p 177 2
+ w 239
j 510 120
+ p 121 e
+ w 81
j 510 170
+ p 116 +
+ w 81
j 510 170
+ p 125 pin1
+ w 81
j 510 80
+ p 121 c
+ w 179
j 510 50
+ w 179
+ w 179
j 490 100
+ p 121 b
+ w 107
j 390 150
+ p 119 1
+ w 79
j 390 160
+ p 115 +
+ w 79
j 440 50
+ p 123 1
+ w 107
j 390 110
+ p 119 2
+ w 107
j 390 100
+ w 107
+ w 107
j 490 100
+ p 128 pin1
+ p 121 b
j 490 100
+ p 128 pin1
+ w 107
j 740 110
+ p 236 1
+ w 239
j 740 70
+ p 236 2
+ w 179
j 780 110
+ p 240 2
+ w 242
j 780 120
+ p 235 2
+ w 242
j 740 50
+ w 179
+ w 179
j 780 70
+ p 240 1
+ w 179
j 780 160
+ p 235 1
+ w 248
j 740 160
+ p 177 1
+ w 248
j 390 200
+ p 115 -
+ w 248
j 510 210
+ p 116 -
+ w 248
j 630 160
+ p 120 1
+ w 248
j 390 210
+ s 124
+ w 248
j 740 210
+ w 248
+ w 248
j 740 120
+ p 251 pin1
+ p 177 2
j 740 120
+ p 251 pin1
+ w 239
j 780 120
+ p 252 pin1
+ p 235 2
j 780 120
+ p 252 pin1
+ w 242
j 450 130
+ p 253 2
+ w 107
j 450 100
+ w 107
+ w 107
j 450 170
+ p 253 1
+ w 248
j 450 210
+ w 248
+ w 248
@attributes
a 0 s 0:13 0 0 0 hln 100 PAGETITLE=
a 0 s 0:13 0 0 0 hln 100 PAGENO=1
a 0 s 0:13 0 0 0 hln 100 PAGESIZE=A4
a 0 s 0:13 0 0 0 hln 100 PAGECOUNT=1
@graphics
