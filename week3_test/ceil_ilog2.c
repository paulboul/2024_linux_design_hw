#include <stdio.h>
#include <stdint.h>
#include <math.h>
#include <assert.h>

//計算ceil(log2(n))
int ceil_ilog2(uint32_t x)
{
    uint32_t r, shift;

    x--;
    r = (x > 0xFFFF) << 4;                                                                                                                         
    x >>= r;
    shift = (x > 0xFF) << 3;
    x >>= shift;
    r |= shift;
    shift = (x > 0xF) << 2;
    x >>= shift;
    r |= shift;
    shift = (x > 0x3) << 1;
    x >>= shift;
    return (r | shift | x > 1) + 1;       
}



int main(int argc, char *argv[]) {


    for(int i=1;i<256;i++){
        printf("cell_ilog %d:%d\n",i,ceil_ilog2(i));
    }
    
    
    return 0;
}
