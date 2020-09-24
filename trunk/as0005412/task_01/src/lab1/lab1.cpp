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