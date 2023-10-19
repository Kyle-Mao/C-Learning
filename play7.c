// C Program. 20231017 21:31
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <windows.h>
#include <math.h>

void main()
{
    srand(time(0));
    int a, s = 50;
    long long int start, end;
    start = time(NULL); // 开始时间戳

    printf("■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■");
    while (1)
    {
        a = rand() % 2;
        if (a == 1)
        {
            printf("■");
            s++;
        }
        else
        {
            printf("\b \b");
            s--;
            if (s == 100 || s == 0)
            {
                break;
            }
        }
        Sleep(1);
    }
    end = time(NULL);

    printf("\n");
    if (s == 100)
    {
        printf("Good Luck!");
    }
    else
    {
        printf("Bad Luck!");
    }
    printf(" You survived for %lld seconds.", end - start);
}