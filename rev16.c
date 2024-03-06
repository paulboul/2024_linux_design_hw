#include <stdio.h>
#include <assert.h>
#include <stdint.h>


//16 位元無號整數逐位元反轉順序
uint16_t rev16(uint16_t n) {  
    n = ((n & 0xff00) >> 8) | ((n & 0x00ff) << 8); 
    n = ((n & 0xf0f0) >> 4) | ((n & 0x0f0f) << 4);
    n = ((n & 0xcccc) >> 2) | ((n & 0x3333) << 2); 
    n = ((n & 0xaaaa) >> 1) | ((n & 0x5555) << 1); 
    return n; 
}
int main(int argc, char *argv[]) {

    uint16_t n = 0x0001;
    uint16_t m = 0x8fff;
    printf("%d\n",rev16(n));
    printf("%d\n",rev16(m));
    
    
    return 0;
}
