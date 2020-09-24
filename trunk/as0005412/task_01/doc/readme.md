#Laboratory Work #1
####Completed by the 3rd year student of
####Faculty of Electronic-Information Systems
####the group АС-54и, Safrin A. A.
####Checked by Ivanyuk D. S. 
######Task:
Write program (C++), which simulates these linear and nonlinear models.
######Code:
```c++
#include <iostream>
#include <stdio.h>


int main()
{
    float a, b, c, d, y = 0, u;
    int n, i;
    printf("Type constants\na:");
    std::cin >> a;
    printf("b:");
    std::cin >> b;
    printf("c:");
    std::cin >> c;
    printf("d:");
    std::cin >> d;
    printf("u:");
    std::cin >> u;
    printf("Type number of iterations:");
    std::cin >> n;
    printf("Linear equation:\n");
        for (i = 0; i <= n; i++)
        {
            y = a * y + b * u;
            printf("%d\ty(t)=%f\n", i, y);
        }
        printf("Nonlinear equation:\n");
        for (i = 0; i <= n; i++)
        {
            y = a * y - b * y * y + c * u + d * sin(u);
            printf("%d\ty(t)=%f\n", i, y);
        }

}
```
######Result:
```
Type constants
a:3
b:0.001
c:6
d:-10
u:5
Type number of iterations:10
Linear equation:
0	y(t)=0.005000
1	y(t)=0.020000
2	y(t)=0.065000
3	y(t)=0.200000
4	y(t)=0.605000
5	y(t)=1.820000
6	y(t)=5.465000
7	y(t)=16.400000
8	y(t)=49.204998
9	y(t)=147.619995
10	y(t)=442.864990
Nonlinear equation:
0	y(t)=1172.054810
1	y(t)=2182.041504
2	y(t)=1824.408081
3	y(t)=2184.348389
4	y(t)=1821.255737
5	y(t)=2186.383789
6	y(t)=1818.466187
7	y(t)=2188.168213
8	y(t)=1816.014038
9	y(t)=2189.724121
10	y(t)=1813.869507
```