(1001)
(TapaInferior)
(T7  D=3 CR=0 TAPER=118deg - ZMIN=-4.401 - taladrar)
G90 G94
G17
G21
G28 G91 Z0
G90

(Taladrar1)
T7
S5000 M3
G54
M8
G0 X-42 Y-42
Z15
Z5
G1 Z-4.401 F1000
G0 Z5
X42
G1 Z-4.401 F1000
G0 Z5
Y42
G1 Z-4.401 F1000
G0 Z5
X-42
G1 Z-4.401 F1000
G0 Z5
Z15
M9
G28 G91 Z0
G90
G28 G91 X0 Y0
G90
M5
M30
