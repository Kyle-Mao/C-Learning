#include <stdio.h>
#include <windows.h>
#include <math.h>

void main()
{
    system("color 19");

    int sound(z)
    {
        Beep(261.6 * z / 2, 1000);
        Beep(293.6 * z / 2, 1000);
        Beep(329.6 * z / 2, 1000);
        Beep(349.2 * z / 2, 1000);
        Beep(392 * z / 2, 1000);
        Beep(440 * z / 2, 1000);
        Beep(493.8 * z / 2, 1000);
        return 0;
    }

    sound(1);
    sound(2);
    sound(4);
    sound(8);

    Beep(400, 1.5);
    int A = 220;
    double x;
    double p = pow(2, 1.0 / 12);
    for (int i = 0; i < 20; i++)
    {
        x = A * pow(p, i);
        printf("%lf\n", x);
        Beep(x, 400);
    }
}