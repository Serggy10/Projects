(1001)
(TapaInferiorContorno)
(T1  D=1.8 CR=0 - ZMIN=-3.2 - fresa con punta plana)
G90 G94
G17
G21
G28 G91 Z0
G90

(2D Contorneado1)
T1
S5000 M3
G54
M8
G0 X-0.18 Y52.94
Z7
Z2
G1 Z1.75 F333.3
Z-0.57
G19 G2 Y52.76 Z-0.75 J-0.18 K0 F1000
G1 Y52.58
G17 G3 X0 Y52.4 I0.18 J0
G1 X51.5
G2 X52.4 Y51.5 I0 J-0.9
G1 Y-51.5
G2 X51.5 Y-52.4 I-0.9 J0
G1 X-51.5
G2 X-52.4 Y-51.5 I0 J0.9
G1 Y51.5
G2 X-51.5 Y52.4 I0.9 J0
G1 X0
G3 X0.18 Y52.58 I0 J0.18
G1 Y52.76
G19 G3 Y52.94 Z-0.57 J0 K0.18
G0 Z2
X-0.18
G1 Z1 F333.3
Z-1.32
G2 Y52.76 Z-1.5 J-0.18 K0 F1000
G1 Y52.58
G17 G3 X0 Y52.4 I0.18 J0
G1 X51.5
G2 X52.4 Y51.5 I0 J-0.9
G1 Y-51.5
G2 X51.5 Y-52.4 I-0.9 J0
G1 X-51.5
G2 X-52.4 Y-51.5 I0 J0.9
G1 Y51.5
G2 X-51.5 Y52.4 I0.9 J0
G1 X0
G3 X0.18 Y52.58 I0 J0.18
G1 Y52.76
G19 G3 Y52.94 Z-1.32 J0 K0.18
G0 Z2
X-0.18
G1 Z0.25 F333.3
Z-2
Y52.76 F1000
Y52.58
G17 G3 X0 Y52.4 I0.18 J0
G1 X3.4
Z-2.25 F333.3
X17.2 F1000
Z-2
X24
Z-2.25 F333.3
X37.8 F1000
Z-2
X44.6
Z-2.25 F333.3
X51.5 F1000
G2 X52.4 Y51.5 I0 J-0.9
G1 Y44.6
Z-2
Y37.8
Z-2.25 F333.3
Y24 F1000
Z-2
Y17.2
Z-2.25 F333.3
Y3.4 F1000
Z-2
Y-3.4
Z-2.25 F333.3
Y-17.2 F1000
Z-2
Y-24
Z-2.25 F333.3
Y-37.8 F1000
Z-2
Y-44.6
Z-2.25 F333.3
Y-51.5 F1000
G2 X51.5 Y-52.4 I-0.9 J0
G1 X44.6
Z-2
X37.8
Z-2.25 F333.3
X24 F1000
Z-2
X17.2
Z-2.25 F333.3
X3.4 F1000
Z-2
X-3.4
Z-2.25 F333.3
X-17.2 F1000
Z-2
X-24
Z-2.25 F333.3
X-37.8 F1000
Z-2
X-44.6
Z-2.25 F333.3
X-51.5 F1000
G2 X-52.4 Y-51.5 I0 J0.9
G1 Y-44.6
Z-2
Y-37.8
Z-2.25 F333.3
Y-24 F1000
Z-2
Y-17.2
Z-2.25 F333.3
Y-3.4 F1000
Z-2
Y3.4
Z-2.25 F333.3
Y17.2 F1000
Z-2
Y24
Z-2.25 F333.3
Y37.8 F1000
Z-2
Y44.6
Z-2.25 F333.3
Y51.5 F1000
G2 X-51.5 Y52.4 I0.9 J0
G1 X-44.6
Z-2
X-37.8
Z-2.25 F333.3
X-24 F1000
Z-2
X-17.2
Z-2.25 F333.3
X-3.4 F1000
Z-2
X0
G3 X0.18 Y52.58 I0 J0.18
G1 Y52.94
G0 Z2
X-0.18
G1 Z-0.5 F333.3
Z-2
Y52.76 F1000
Y52.58
G3 X0 Y52.4 I0.18 J0
G1 X3.4
Z-3 F333.3
X17.2 F1000
Z-2
X24
Z-3 F333.3
X37.8 F1000
Z-2
X44.6
Z-3 F333.3
X51.5 F1000
G2 X52.4 Y51.5 I0 J-0.9
G1 Y44.6
Z-2
Y37.8
Z-3 F333.3
Y24 F1000
Z-2
Y17.2
Z-3 F333.3
Y3.4 F1000
Z-2
Y-3.4
Z-3 F333.3
Y-17.2 F1000
Z-2
Y-24
Z-3 F333.3
Y-37.8 F1000
Z-2
Y-44.6
Z-3 F333.3
Y-51.5 F1000
G2 X51.5 Y-52.4 I-0.9 J0
G1 X44.6
Z-2
X37.8
Z-3 F333.3
X24 F1000
Z-2
X17.2
Z-3 F333.3
X3.4 F1000
Z-2
X-3.4
Z-3 F333.3
X-17.2 F1000
Z-2
X-24
Z-3 F333.3
X-37.8 F1000
Z-2
X-44.6
Z-3 F333.3
X-51.5 F1000
G2 X-52.4 Y-51.5 I0 J0.9
G1 Y-44.6
Z-2
Y-37.8
Z-3 F333.3
Y-24 F1000
Z-2
Y-17.2
Z-3 F333.3
Y-3.4 F1000
Z-2
Y3.4
Z-3 F333.3
Y17.2 F1000
Z-2
Y24
Z-3 F333.3
Y37.8 F1000
Z-2
Y44.6
Z-3 F333.3
Y51.5 F1000
G2 X-51.5 Y52.4 I0.9 J0
G1 X-44.6
Z-2
X-37.8
Z-3 F333.3
X-24 F1000
Z-2
X-17.2
Z-3 F333.3
X-3.4 F1000
Z-2
X0
G3 X0.18 Y52.58 I0 J0.18
G1 Y52.94
G0 Z2
X-0.18
G1 Z-1.25 F333.3
Z-2
Y52.76 F1000
Y52.58
G3 X0 Y52.4 I0.18 J0
G1 X3.4
Z-3.2 F333.3
X17.2 F1000
Z-2
X24
Z-3.2 F333.3
X37.8 F1000
Z-2
X44.6
Z-3.2 F333.3
X51.5 F1000
G2 X52.4 Y51.5 I0 J-0.9
G1 Y44.6
Z-2
Y37.8
Z-3.2 F333.3
Y24 F1000
Z-2
Y17.2
Z-3.2 F333.3
Y3.4 F1000
Z-2
Y-3.4
Z-3.2 F333.3
Y-17.2 F1000
Z-2
Y-24
Z-3.2 F333.3
Y-37.8 F1000
Z-2
Y-44.6
Z-3.2 F333.3
Y-51.5 F1000
G2 X51.5 Y-52.4 I-0.9 J0
G1 X44.6
Z-2
X37.8
Z-3.2 F333.3
X24 F1000
Z-2
X17.2
Z-3.2 F333.3
X3.4 F1000
Z-2
X-3.4
Z-3.2 F333.3
X-17.2 F1000
Z-2
X-24
Z-3.2 F333.3
X-37.8 F1000
Z-2
X-44.6
Z-3.2 F333.3
X-51.5 F1000
G2 X-52.4 Y-51.5 I0 J0.9
G1 Y-44.6
Z-2
Y-37.8
Z-3.2 F333.3
Y-24 F1000
Z-2
Y-17.2
Z-3.2 F333.3
Y-3.4 F1000
Z-2
Y3.4
Z-3.2 F333.3
Y17.2 F1000
Z-2
Y24
Z-3.2 F333.3
Y37.8 F1000
Z-2
Y44.6
Z-3.2 F333.3
Y51.5 F1000
G2 X-51.5 Y52.4 I0.9 J0
G1 X-44.6
Z-2
X-37.8
Z-3.2 F333.3
X-24 F1000
Z-2
X-17.2
Z-3.2 F333.3
X-3.4 F1000
Z-2
X0
G3 X0.18 Y52.58 I0 J0.18
G1 Y52.94
G0 Z7
M9
G28 G91 Z0
G90
G28 G91 X0 Y0
G90
M5
M30