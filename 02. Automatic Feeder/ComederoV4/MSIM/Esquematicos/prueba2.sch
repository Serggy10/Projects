*version 8.0 2761824827
u 53
V? 3
R? 2
U? 2
C? 2
Q? 2
D? 2
@libraries
@analysis
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
pageloc 1 0 3417 
@status
n 0 122:06:17:17:58:00;1658073480 e 
s 2832 122:06:17:17:58:00;1658073480 e 
*page 1 0 297 210 ma
@ports
port 48 GND_EARTH 380 300 h
@parts
part 39 VDC 380 250 h
a 0 sp 0 0 22 37 hln 100 PART=VDC
a 1 ap 9 0 24 7 hcn 100 REFDES=V1
a 1 u 13 0 -11 18 hcn 100 DC=12V
a 0 a 0:13 0 0 0 hln 100 PKGREF=V1
part 40 VDC 500 260 h
a 0 sp 0 0 22 37 hln 100 PART=VDC
a 1 ap 9 0 24 7 hcn 100 REFDES=V2
a 1 u 13 0 -11 18 hcn 100 DC=6V
a 0 a 0:13 0 0 0 hln 100 PKGREF=V2
part 42 R 660 250 v
a 0 sp 0 0 0 10 hlb 100 PART=R
a 0 s 0:13 0 0 0 hln 100 PKGTYPE=RC05
a 0 s 0:13 0 0 0 hln 100 GATE=
a 0 ap 9 0 15 0 hln 100 REFDES=R1
a 0 u 13 0 15 25 hln 100 VALUE=10k
a 0 a 0:13 0 0 0 hln 100 PKGREF=R1
part 43 Sw_tOpen 380 220 v
a 0 sp 0 0 0 24 hln 100 PART=Sw_tOpen
a 0 s 0:13 0 0 0 hln 100 PKGTYPE=
a 0 ap 9 0 0 20 hln 100 REFDES=U1
a 0 u 13 13 0 -4 hln 100 tOpen=1
a 0 a 0:13 0 0 0 hln 100 PKGREF=U1
part 44 C 620 250 v
a 0 sp 0 0 0 10 hlb 100 PART=C
a 0 s 0:13 0 0 0 hln 100 PKGTYPE=C1005
a 0 s 0:13 0 0 0 hln 100 GATE=
a 0 ap 9 0 15 0 hln 100 REFDES=C1
a 0 u 13 0 15 25 hln 100 VALUE=100u
a 0 a 0:13 0 0 0 hln 100 PKGREF=C1
part 45 BC557C 480 160 h
a 0 sp 11 0 25 40 hln 100 PART=BC557C
a 0 s 0:13 0 0 0 hln 100 PKGTYPE=TO-92-18B
a 0 s 0:13 0 0 0 hln 100 GATE=
a 0 ap 9 0 5 5 hln 100 REFDES=Q1
a 0 a 0:13 0 0 0 hln 100 PKGREF=Q1
part 47 1N4148 430 140 h
a 0 sp 11 0 15 25 hln 100 PART=1N4148
a 0 s 0:13 0 0 0 hln 100 PKGTYPE=DO-35
a 0 s 0:13 0 0 0 hln 100 GATE=
a 0 ap 9 0 15 0 hln 100 REFDES=D1
a 0 a 0:13 0 0 0 hln 100 PKGREF=D1
part 1 CAJETIN_DTE_EII 1188 840 h
a 0 s 0:11 0 0 10 hlb 100 PART=CAJETIN_DTE_EII
a 1 s 13 0 350 10 hcn 100 PAGESIZE=A4
a 1 s 13 0 180 60 hcn 100 PAGETITLE=
a 1 s 13 0 300 95 hrn 100 PAGENO=1
a 1 s 13 0 340 95 hrn 100 PAGECOUNT=1
part 49 iMarker 500 260 h
a 0 s 0 0 0 0 hln 100 PROBEVAR=
a 0 a 0 0 6 20 hlb 100 LABEL=1
part 50 iMarker 660 210 h
a 0 s 0 0 0 0 hln 100 PROBEVAR=
a 0 a 0 0 6 20 hlb 100 LABEL=3
part 51 iMarker 620 220 h
a 0 s 0 0 0 0 hln 100 PROBEVAR=
a 0 a 0 0 6 20 hlb 100 LABEL=2
part 52 iMarker 480 160 h
a 0 s 0 0 0 0 hln 100 PROBEVAR=
a 0 a 0 0 6 20 hlb 100 LABEL=4
@conn
w 3
s 380 220 380 250 2
a 0 up 33 0 382 235 hlt 100 V=
w 5
s 500 180 500 260 4
a 0 up 33 0 502 220 hlt 100 V=
w 7
s 380 290 380 300 8
s 660 250 660 300 12
s 660 300 620 300 14
a 0 up 33 0 440 299 hct 100 V=
s 620 300 500 300 18
s 620 250 620 300 16
s 500 300 380 300 41
w 20
s 660 210 660 140 19
s 660 140 620 140 23
s 620 140 620 220 25
s 460 140 500 140 28
s 500 140 620 140 46
w 31
s 380 140 430 140 30
a 0 up 33 0 440 139 hct 100 V=
s 380 140 380 160 34
s 380 160 380 180 38
s 380 160 480 160 36
@junction
j 620 300
+ w 7
+ w 7
j 620 140
+ w 20
+ w 20
j 380 160
+ w 31
+ w 31
j 380 250
+ p 39 +
+ w 3
j 380 290
+ p 39 -
+ w 7
j 500 260
+ p 40 +
+ w 5
j 500 300
+ p 40 -
+ w 7
j 660 250
+ p 42 1
+ w 7
j 660 210
+ p 42 2
+ w 20
j 380 220
+ p 43 1
+ w 3
j 380 180
+ p 43 2
+ w 31
j 620 250
+ p 44 1
+ w 7
j 620 220
+ p 44 2
+ w 20
j 500 180
+ p 45 e
+ w 5
j 500 140
+ p 45 c
+ w 20
j 480 160
+ p 45 b
+ w 31
j 460 140
+ p 47 2
+ w 20
j 430 140
+ p 47 1
+ w 31
j 380 300
+ s 48
+ w 7
j 500 260
+ p 49 pin1
+ p 40 +
j 500 260
+ p 49 pin1
+ w 5
j 660 210
+ p 50 pin1
+ p 42 2
j 660 210
+ p 50 pin1
+ w 20
j 620 220
+ p 51 pin1
+ p 44 2
j 620 220
+ p 51 pin1
+ w 20
j 480 160
+ p 52 pin1
+ p 45 b
j 480 160
+ p 52 pin1
+ w 31
@attributes
a 0 s 0:13 0 0 0 hln 100 PAGETITLE=
a 0 s 0:13 0 0 0 hln 100 PAGENO=1
a 0 s 0:13 0 0 0 hln 100 PAGESIZE=A4
a 0 s 0:13 0 0 0 hln 100 PAGECOUNT=1
@graphics
