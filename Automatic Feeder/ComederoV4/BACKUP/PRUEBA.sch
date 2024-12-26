*version 8.0 1713128314
u 19
V? 2
R? 3
? 2
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
pageloc 1 0 1715 
@status
n 0 122:06:19:22:28:01;1658262481 e 
s 2832 122:06:19:22:28:10;1658262490 e 
*page 1 0 297 210 ma
@ports
port 15 GND_EARTH 320 220 h
@parts
part 4 R 380 220 v
a 0 sp 0 0 0 10 hlb 100 PART=R
a 0 s 0:13 0 0 0 hln 100 PKGTYPE=RC05
a 0 s 0:13 0 0 0 hln 100 GATE=
a 0 a 0:13 0 0 0 hln 100 PKGREF=R2
a 0 ap 9 0 15 0 hln 100 REFDES=R2
a 0 u 13 0 15 25 hln 100 VALUE=3K
part 2 VDC 290 170 h
a 0 sp 0 0 22 37 hln 100 PART=VDC
a 0 a 0:13 0 0 0 hln 100 PKGREF=V1
a 1 ap 9 0 24 7 hcn 100 REFDES=V1
a 1 u 13 0 -11 18 hcn 100 DC=5v
part 3 R 340 160 h
a 0 sp 0 0 0 10 hlb 100 PART=R
a 0 s 0:13 0 0 0 hln 100 PKGTYPE=RC05
a 0 s 0:13 0 0 0 hln 100 GATE=
a 0 a 0:13 0 0 0 hln 100 PKGREF=R1
a 0 ap 9 0 15 0 hln 100 REFDES=R1
a 0 u 13 0 15 25 hln 100 VALUE=47K
part 1 CAJETIN_DTE_EII 1188 840 h
a 0 s 0:11 0 0 10 hlb 100 PART=CAJETIN_DTE_EII
a 1 s 13 0 350 10 hcn 100 PAGESIZE=A4
a 1 s 13 0 180 60 hcn 100 PAGETITLE=
a 1 s 13 0 300 95 hrn 100 PAGENO=1
a 1 s 13 0 340 95 hrn 100 PAGECOUNT=1
part 18 nodeMarker 380 160 h
a 0 s 0 0 0 0 hln 100 PROBEVAR=
a 0 a 0 0 4 22 hlb 100 LABEL=1
@conn
w 6
a 0 up 0:33 0 0 0 hln 100 V=
s 290 170 290 160 5
s 290 160 340 160 7
a 0 up 33 0 315 159 hct 100 V=
w 12
a 0 up 0:33 0 0 0 hln 100 V=
s 380 220 320 220 11
a 0 up 33 0 350 219 hct 100 V=
s 290 220 290 210 13
s 320 220 290 220 16
w 10
a 0 up 0:33 0 0 0 hln 100 V=
s 380 160 380 180 9
a 0 up 33 0 382 170 hlt 100 V=
@junction
j 290 170
+ p 2 +
+ w 6
j 340 160
+ p 3 1
+ w 6
j 380 180
+ p 4 2
+ w 10
j 380 160
+ p 3 2
+ w 10
j 380 220
+ p 4 1
+ w 12
j 290 210
+ p 2 -
+ w 12
j 320 220
+ s 15
+ w 12
j 380 160
+ p 18 pin1
+ p 3 2
j 380 160
+ p 18 pin1
+ w 10
@attributes
a 0 s 0:13 0 0 0 hln 100 PAGETITLE=
a 0 s 0:13 0 0 0 hln 100 PAGENO=1
a 0 s 0:13 0 0 0 hln 100 PAGESIZE=A4
a 0 s 0:13 0 0 0 hln 100 PAGECOUNT=1
@graphics
