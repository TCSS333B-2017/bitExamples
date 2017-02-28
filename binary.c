#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(){
	char strArray[]="Hello World";
	unsigned char ucArray[]={0x1,0xFF};
	char charArray[]={1,-1};
	unsigned int uintArray[]={0x1,0xFF};
	int intArray[]={1,-1};
 FILE *fptext=fopen("text.bin","w");
 fwrite(strArray,sizeof(strArray),1,fptext);
	fclose(fptext);
	FILE *fpNum=fopen("num.bin","w");
 fwrite(uintArray,sizeof(uintArray),1,fptext);
 fwrite(intArray,sizeof(intArray),1,fptext);
	fclose(fpNum);
	return 0;
}
