#include <stdio.h>
#include <stdint.h>
#include <math.h>


int i_sqrt(int N)
{
    int msb = (int) log2(N);
    int a = 1 << msb;
    int result = 0;
    while (a != 0) {
        if ((result + a) * (result + a) <= N)
            result += a;
        a >>= 1;
    }
    return result;
}


int i_sqrt_bitwise(int N){
    int msb = 0;
    int n = N;
    while (n > 1) {
        n >>= 1;
        msb++;
    }
    int a = 1 << msb;
    int result = 0;
    while (a != 0) {
        if ((result + a) * (result + a) <= N)
            result += a;
        a >>= 1;
    }
    return result;
}

int i_sqrt_version3(int x)
{
    if (x <= 1) /* Assume x is always positive */
        return x;

    int z = 0;
    for (int m = 1UL << ((31 - __builtin_clz(x)) & ~1UL); m; m >>= 2) {
        int b = z + m;
        z >>= 1;
        if (x >= b)
            x -= b, z += m;               
    }
    return z;
}


int main(int argc, char *argv[]) {

    int N = 36;
    printf("%d\n", i_sqrt(N));
    printf("%d\n", i_sqrt_bitwise(N));
    printf("%d\n", i_sqrt_version3(N));
    
    return 0;
}

