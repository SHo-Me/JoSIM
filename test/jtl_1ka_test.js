* gnetlist.exe -g spice-sdb -O jsim -O param -O sort_mode -v -o ./js/jtl_1ka_test.js C:\Users\Joey Delport\Documents\JD_no_Mirai\gEDA_Workspace\jtl_1ka_test.sch
*********************************************************
* Spice file generated by gnetlist                      *
* spice-sdb version 4.28.2007 by SDB --                 *
* provides advanced spice netlisting capability.        *
* Documentation at http://www.brorson.com/gEDA/SPICE/   *
*********************************************************
*==============  Begin SPICE netlist of main design ============
B1         7          2          jj1        area=1
B2         6          4          jj1        area=1
IA         0          8          pwl(0      0 300p 0 303p 600u 306p 600u 309p 0)
IG         0          12         pwl(       0 0 5p 64m)
K1         Lg         L2         0.0083    
K2         Lg         L3         0.0083    
L1         8          7          2.08p     
L2         7          11         2.059p    
L3         6          11         2.059p    
L4         6          5          2.08p     
L5         0          2          0.214p    
L6         0          4          0.214p    
Lg         12         0          53.48p    
Lp1        2          1          1p        
Lp2        4          3          1p        
LVB        10         11         53.48p    
RB1        1          7          1         
RB2        3          6          1         
ROUT       5          0          2         
RVB        10         9          7.14      
VB         9          0          pwl(0      0 5p 2.5m)
.MODEL jj1 JJ(ICRIT=250uA, CAP=1.32pF, RTYPE=0, RN=90)
.tran 0.5p 1n 0 0.25p
.print DEVV L1
.print PHASE B1
.print DEVV ROUT
.end