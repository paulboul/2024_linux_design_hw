#include <stdio.h>
#include <stdint.h>
#include <math.h>

static void str_add(char *b, char *a, char *res, size_t size)
{
    int carry = 0;

    for (int i = 0; i < size; i++) {
        int tmp = (b[i] - '0') + (a[i] - '0') + carry;
        carry = tmp / 10;
        tmp = tmp % 10;
        res[i] = tmp + '0';
    }
}


//算number/10，number%10的bitwise operation版本
void divmod_10(uint32_t in, uint32_t *div, uint32_t *mod)
{
    uint32_t x = (in | 1) - (in >> 2); /* div = in/10 ==> div = 0.75*in/8 */
    uint32_t q = (x >> 4) + x;
    x = q;
    q = (q >> 8) + x;
    q = (q >> 8) + x;
    q = (q >> 8) + x;
    q = (q >> 8) + x;

    *div = (q >> 3);
    *mod = in - ((q & ~0x7) + (*div << 1));   
}

int main(int argc, char *argv[]) {

    unsigned div, mod;
    divmod_10(193, &div, &mod);
    printf("div: %d, mod: %d\n", div, mod);//div: 19, mod: 3
    
    return 0;
}

