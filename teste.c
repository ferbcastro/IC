#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#define absoluto(a) (a > 0 ? a : -a)

long mod (long a, long b)
{
    long quociente = a / b;

    if (a < 0)
    {
        if (b < 0)
            return a - (quociente + 1) * b;
        else 
            return a - (quociente - 1) * b;
    }

    return a - quociente * b;
}

int main ()
{
    long a = -54;
    long b = 21;

    printf ("%ld\n", mod (a, b));

    return 0;
}