#include <stdio.h>
#include <windows.h>

int main()
{
    int t, h, m, s, z;
    t = 1;
    while (1)
    {
        h = t / 3600;
        m = (t - h * 3600) / 60;
        s = t - h * 3600 - m * 60;
        printf("%02d:%02d:%02d", h, m, s);
        for (z = 0; z < 100; z++)
        {
            printf(":%02d", z);
            Sleep(10);
            printf("\b\b\b");
        }

        printf("\b\b\b\b\b\b\b\b");
        t++;
    }

    return 0;
}
