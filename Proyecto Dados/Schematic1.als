* Schematics Aliases *

.ALIASES
D_D2            D2(1=$N_0001 2=$N_0002 )
R_R3            R3(1=$N_0002 2=$N_0003 )
R_R2            R2(1=$N_0004 2=$N_0003 )
R_R1            R1(1=$N_0003 2=$N_0005 )
D_D1            D1(1=$N_0004 2=$N_0001 )
C_C2            C2(1=$N_0006 2=$N_0005 )
V_V4            V4(+=$N_0005 -=0 )
M_Q1            Q1(d=$N_0006 g=$N_0007 s=0 s=0 )
C_C4            C4(1=0 2=$N_0001 )
C_C3            C3(1=0 2=$N_0008 )
X_U1            U1(GND=0 TRIGGER=$N_0001 OUTPUT=$N_0007 RESET=$N_0005
+  CONTROL=$N_0008 THRESHOLD=$N_0001 DISCHARGE=$N_0003 VCC=$N_0005 )
C_C1            C1(1=$N_0005 2=0 )
R_R4            R4(1=0 2=$N_0007 )
.ENDALIASES

