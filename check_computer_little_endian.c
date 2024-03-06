#include <stdio.h>
#include <assert.h>

typedef unsigned char *byte_ptr;

int is_little_endian(){
	int test_num=0xff;
	byte_ptr byte_start=(byte_ptr)&test_num;
	if(byte_start[0]==0xff) printf("this computer is little endian\n"); return 1;
	printf("this computer is big endian\n");
	return 0;

}


int main(int argc,char *argv[]){

	assert(is_little_endian());
	return 0;

}
