#include <stdio.h>
#include <stdlib.h>
int main(){
	unsigned int random;
	random = rand();	// random value!

	printf("%d\n",random^ 0xdeadbeef);
	return 0;
}