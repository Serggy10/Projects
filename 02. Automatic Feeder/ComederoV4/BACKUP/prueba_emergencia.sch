*version 8.0 3353072521
u 176
P? 2
U? 3
R? 2
V? 3
? 4
@libraries
@analysis
.TRAN 1 0 0 0
+0 20ns
+1 2s
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
pageloc 1 0 4066 
@status
n 0 122:06:20:12:20:20;1658312420 e 
s 0 122:06:20:12:20:51;1658312451 e 
c 122:06:20:12:22:07;1658312527
*page 1 0 297 210 ma
@ports
port 174 GND_EARTH 260 330 h
@parts
part 95 C_ELECTROLITICO 300 250 h
a 0 x 0:13 0 0 0 hln 100 PKGTYPE=PLP3481/AA
a 0 x 0:13 0 0 0 hln 100 PKGREF=C1
a 0 x 9 0 15 0 hln 100 REFDES=C1
a 0 s 0 0 0 10 hlb 100 PART=C_ELECTROLITICO
a 0 u 13 0 3 19 hln 100 VALUE=470u
part 89 1N4148 250 200 h
a 0 s 0:13 0 0 0 hln 100 PKGTYPE=DO-35
a 0 s 0:13 0 0 0 hln 100 GATE=
a 0 x 0:13 0 0 0 hln 100 PKGREF=D1
a 0 sp 11 0 -3 37 hln 100 PART=1N4148
a 0 xp 9 0 9 28 hln 100 REFDES=D1
part 88 1N4148 290 160 d
a 0 s 0:13 0 0 0 hln 100 PKGTYPE=DO-35
a 0 s 0:13 0 0 0 hln 100 GATE=
a 0 x 0:13 0 0 0 hln 100 PKGREF=D2
a 0 sp 11 0 27 49 hln 100 PART=1N4148
a 0 xp 9 0 15 28 hln 100 REFDES=D2
part 120 VDC 130 120 u
a 0 sp 0 0 22 37 hln 100 PART=VDC
a 0 a 0:13 0 0 0 hln 100 PKGREF=V1
a 1 ap 9 0 24 7 hcn 100 REFDES=V1
a 1 u 13 0 -11 18 hcn 100 DC=12V
part 169 Sw_tOpen 270 80 h
a 0 sp 0 0 0 24 hln 100 PART=Sw_tOpen
a 0 s 0:13 0 0 0 hln 100 PKGTYPE=
a 0 a 0:13 0 0 0 hln 100 PKGREF=U2
a 0 ap 9 0 0 20 hln 100 REFDES=U2
a 0 u 13 13 0 -4 hln 100 tOpen=1
part 106 R 330 350 u
a 0 sp 0 0 0 10 hlb 100 PART=R
a 0 s 0:13 0 0 0 hln 100 PKGTYPE=RC05
a 0 s 0:13 0 0 0 hln 100 GATE=
a 0 a 0:13 0 0 0 hln 100 PKGREF=R1
a 0 ap 9 0 15 0 hln 100 REFDES=R1
a 0 u 13 0 15 25 hln 100 VALUE=60
part 137 VDC 250 290 h
a 0 sp 0 0 22 37 hln 100 PART=VDC
a 0 a 0:13 0 0 0 hln 100 PKGREF=V2
a 1 ap 9 0 24 7 hcn 100 REFDES=V2
a 1 u 13 0 -11 18 hcn 100 DC=6
part 93 BC557B 230 250 h
a 0 s 11 0 25 40 hln 100 PART=BC557B
a 0 s 0:13 0 0 0 hln 100 GATE=
a 0 x 0:13 0 0 0 hln 100 PKGTYPE=TO-92-5C
a 0 x 0:13 0 0 0 hln 100 PKGREF=Q1
a 0 x 9 0 0 0 hln 100 REFDES=Q1
part 1 CAJETIN_DTE_EII 1188 840 h
a 0 s 0:11 0 0 10 hlb 100 PART=CAJETIN_DTE_EII
a 1 s 13 0 350 10 hcn 100 PAGESIZE=A4
a 1 s 13 0 180 60 hcn 100 PAGETITLE=
a 1 s 13 0 300 95 hrn 100 PAGENO=1
a 1 s 13 0 340 95 hrn 100 PAGECOUNT=1
part 139 iMarker 130 80 h
a 0 s 0 0 0 0 hln 100 PROBEVAR=
a 0 a 0 0 6 20 hlb 100 LABEL=2
part 173 iMarker 290 350 h
a 0 s 0 0 0 0 hln 100 PROBEVAR=I(R1)
a 0 a 0 0 6 20 hlb 100 LABEL=3
part 138 iMarker 250 330 h
a 0 s 0 0 0 0 hln 100 PROBEVAR=I(V2)
a 0 a 0 0 6 20 hlb 100 LABEL=1
@conn
w 112
a 0 up 0:33 0 0 0 hln 100 V=
s 270 80 130 80 170
a 0 up 33 0 200 79 hct 100 V=
w 155
a 0 up 0:33 0 0 0 hln 100 V=
s 290 200 290 250 81
s 290 200 280 200 141
s 290 250 300 250 79
s 290 250 290 350 116
a 0 up 33 0 292 300 hlt 100 V=
s 290 190 290 200 75
w 172
a 0 up 0:33 0 0 0 hln 100 V=
s 340 80 310 80 163
s 340 230 340 80 68
a 0 up 33 0 342 155 hlt 100 V=
s 340 250 340 230 63
s 270 230 340 230 66
s 340 250 330 250 60
s 340 350 340 250 113
s 270 330 270 230 73
s 330 350 340 350 111
s 250 330 260 330 71
s 260 330 270 330 175
w 162
a 0 up 0:33 0 0 0 hln 100 V=
s 130 160 130 250 157
s 130 250 230 250 26
s 290 160 130 160 147
a 0 up 33 0 210 159 hct 100 V=
s 130 120 130 160 28
w 23
a 0 sr 3 0 252 285 hln 100 LABEL=+6V
a 0 up 0:33 0 0 0 hln 100 V=
s 250 290 250 270 22
a 0 sr 3 0 252 285 hln 100 LABEL=+6V
a 0 up 33 0 252 286 hlt 100 V=
w 37
a 0 up 0:33 0 0 0 hln 100 V=
s 250 200 250 230 36
a 0 up 33 0 252 215 hlt 100 V=
@junction
j 340 250
+ w 172
+ w 172
j 290 250
+ w 155
+ w 155
j 300 250
+ p 95 1
+ w 155
j 290 350
+ p 106 2
+ w 155
j 340 230
+ w 172
+ w 172
j 330 250
+ p 95 2
+ w 172
j 330 350
+ p 106 1
+ w 172
j 250 290
+ p 137 +
+ w 23
j 250 330
+ p 137 -
+ w 172
j 130 80
+ p 139 pin1
+ w 112
j 250 200
+ p 89 1
+ w 37
j 280 200
+ p 89 2
+ w 155
j 290 190
+ p 88 2
+ w 155
j 290 200
+ w 155
+ w 155
j 290 160
+ p 88 1
+ w 162
j 130 160
+ w 162
+ w 162
j 130 80
+ p 120 -
+ p 139 pin1
j 130 120
+ p 120 +
+ w 162
j 130 80
+ p 120 -
+ w 112
j 270 80
+ p 169 1
+ w 112
j 310 80
+ p 169 2
+ w 172
j 290 350
+ p 173 pin1
+ p 106 2
j 290 350
+ p 173 pin1
+ w 155
j 260 330
+ s 174
+ w 172
j 250 330
+ p 138 pin1
+ p 137 -
j 250 330
+ p 138 pin1
+ w 172
j 250 230
+ p 93 c
+ w 37
j 230 250
+ p 93 b
+ w 162
j 250 270
+ p 93 e
+ w 23
@attributes
a 0 s 0:13 0 0 0 hln 100 PAGETITLE=
a 0 s 0:13 0 0 0 hln 100 PAGENO=1
a 0 s 0:13 0 0 0 hln 100 PAGESIZE=A4
a 0 s 0:13 0 0 0 hln 100 PAGECOUNT=1
@graphics
