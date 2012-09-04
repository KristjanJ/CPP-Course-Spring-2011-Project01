#include "functions.h"

#include <cstdlib>

long minimum(long a, long b)
{
    if (a > b)
    {
        return b;
    }
    else
    {
        return a;
    }
}

long maximum(long a, long b)
{
    if (a > b)
    {
        return a;
    }
    else
    {
        return b;
    }
}

long sum(long a, long b)
{
    long result = a + b;

    return result;
}

long product(long a, long b)
{
    long result = a * b;

    return result;
}

long gcd(long a, long b)
{
    long result = 0;

    long x = 0;
    long y = 0;

    if (a > b)
    {
        x = a;
        y = b;
    }
    else
    {
        x = b;
        y = a;
    }

    if (y != 0)
    {
        long temp = 0;

        do
        {
            temp = x % y;
            x = y;
            y = temp;
        } while (y != 0);

        result = std::abs(x);
    }

    return result;
}
