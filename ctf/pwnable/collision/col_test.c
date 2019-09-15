#include <stdio.h>
#include <string.h>

unsigned long hashcode = 0x21DD09EC;
unsigned long check_password(const char* p){
	int* ip = (int*)p;
	int i;
	int res=0;
	for(i=0; i<5; i++){
		res += ip[i];
		printf("%x\n",ip[i]);
	}
	return res;
}

int main(int argc, char* argv[]){
	char buf[20] = "%0H?%0%?@0%?00%?2I%%";
	
    // char *ch = "\x21";
	// //SetConsoleOutputCP(437);
    printf("%lx\n",check_password(buf));
    
	
}       
