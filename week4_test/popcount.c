#include <stdio.h>


int x = 5328; // 00000000000000000001010011010000

int hammingDistance(int x, int y)//兩個整數間的 Hamming distance 為其二進位的每個位元的差
{
    return __builtin_popcount(x ^ y);
}

int totalHammingDistance(int* nums, int numsSize)
{
    int total = 0;;
    for (int i = 0;i < numsSize;i++)
        for (int j = 0; j < numsSize;j++)
            total += __builtin_popcount(nums[i] ^ nums[j]); 
    return total >> 1;
}


//計算數值的二進位表示中，有多少位元是 1
unsigned popcount_naive(unsigned v)
{
    unsigned n = 0;
    while (v){
        v &= (v - 1);
        n = -(~n);
    }
        
    return n;
}


unsigned popcount_branchless(unsigned v)
{
    unsigned n;
    n = (v >> 1) & 0x77777777;
    v -= n;
    n = (n >> 1) & 0x77777777;
    v -= n;
    n = (n >> 1) & 0x77777777;
    v -= n;

    v = (v + (v >> 4)) & 0x0F0F0F0F;
    v *= 0x01010101;                                     

    return v >> 24;
}

int main(){

    int n=3;
    printf("%d\n",popcount_naive(n));//2
    printf("%d\n",popcount_branchless(n));//2
    printf("%d\n",  __builtin_popcount(x)); // 5

    //兩個整數間的 Hamming distance 為其二進位的每個位元的差
    int a=1,b=4;
    printf("%d\n",hammingDistance(a,b));

  

    return 0;
}









