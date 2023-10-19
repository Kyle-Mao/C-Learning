#include <stdio.h>
#include <windows.h>

int main()
{
    int t, h, m, s;
    t = 1;
    while (1)
    {
        h = t / 3600;
        m = (t - h * 3600) / 60;
        s = t - h * 3600 - m * 60;
        printf("%02d:%02d:%02d", h, m, s);
        Sleep(1000);
        printf("\b\b\b\b\b\b\b\b");
        t++;
    }

    return 0;
}
