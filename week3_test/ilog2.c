#include <stdio.h>
#include <stdint.h>
#include <math.h>

int ilog2(int i)
{
    int log = -1;
    while (i) {
        i >>= 1;
        log++;
    }
    return log;
}

static size_t ilog2_version2(size_t i)
{
    size_t result = 0;
    while (i >= 65536) {
        result += 16;
        i >>= 16;
    }
    while (i >= 256) {
        result += 8;
        i >>= 8;
    }
    while (i >= 16) {
        result += 4;
        i >>= 4;
    }
    while (i >= 2) {
        result += 1;
        i >>= 1;
    }
    return result;
}

int ilog32(uint32_t v)

{
    return (31 - __builtin_clz(v | 1));
}


int main(int argc, char *argv[]) {


    int n=1024;
    printf("%d\n",ilog2(n));
    printf("%ld\n",ilog2_version2(n));
    printf("%d\n",ilog32(n));
    
    return 0;
}
