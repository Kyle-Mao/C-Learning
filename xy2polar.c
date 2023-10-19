// C Program. 20231017 19:42
#include <stdio.h>
#include <math.h>
#define PI 3.14159265358979

void main()
{
    double x, y, r, o;
    scanf("(%lf,%lf)", &x, &y);

    r = sqrt(x * x + y * y);
    o = atan(y / x);
    if (x < 0 && y > 0)
    {
        o += PI;
    }
    if (x < 0 && y < 0)
    {
        o -= PI;
    }

    printf("( %.10g, %.10g )", r, o);
}