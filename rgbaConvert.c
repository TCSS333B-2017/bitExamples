#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdint.h>
typedef struct {
	unsigned char r,g,b,a;
}rgba;


int main(){
 rgba pixel={0xFF,0x7F,0x3F,0x1F};
 uint16_t pix16=0;
 //11111111 01111111 00111111 00011111 original 32 bit
 
 //111101110110001   downsampled 16 bit
 
 uint16_t r16= pixel.r;
 uint16_t g16= pixel.g;
 uint16_t b16= pixel.b;
 uint16_t a16= pixel.a;
 
 //using shifts to push 1's of the edge and zero them
 //00000000 RRRRrrrr
 //00000000 0000RRRR >> 4
 //RRRR0000 00000000 << 12
 
 //using a mask to select the bits
 //00000000 RRRRrrrr
 // &
 //00000000 11110000
 //gives
 //00000000 RRRR0000
 //RRRR0000 00000000 << 8
 
 r16 = (r16 & 0xF0) << 8;
 g16 = (g16 & 0xF0) << 4;
 b16 = (b16 & 0xF0);
 a16 = (a16 & 0xF0) >> 4;
 
 //using | to combine the different bits
 pix16=r16 | g16 | b16 | a16;
 FILE *fp=fopen("rgba.bin","w");
 fwrite(&pixel,sizeof(pixel),1,fp);
 fwrite(&pix16,sizeof(pix16),1,fp);
 fclose(fp);
}
