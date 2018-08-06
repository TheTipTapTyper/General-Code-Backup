#include <stdlib.h>
#include <stdio.h>

typedef struct {
	int devid;
	int* device;
} lutEntry;

typedef struct {
	unsigned int devid;
	unsigned int lutMask0;
	unsigned int lutMask1;
	lutEntry* lut_0; //32 entries
	lutEntry* lut_1; //32 entries
} device;

typedef struct {
	device* knureon; //four of them
	device* lfi; //only one per qcc
} qcc;

int maleLuts(qcc* sys, int numOfQccs){
	

	return 0;
}

int makeKnureons(qcc* sys, int numOfQccs){
	int i, j, k, l;
	unsigned int currentDevid = 0x000000;
	unsigned char node = 0, card = 0, knu = 0;
	
	//set up for each qcc
	for(l = 0; l < numOfQccs;l++){			
		sys[l].knureon = malloc(sizeof(device) * 4);		
		
		//set up for each knureon
		for(i = 0; i < 4; i++){
			
			sys[l].knureon[i].devid = currentDevid; 			
			sys[l].knureon[i].lut_0 = malloc(sizeof(lutEntry));
			sys[l].knureon[i].lut_1 = malloc(sizeof(lutEntry));
			
			//set values for LUT0 entries		
			for(j = 0; j < 28; j++){
				sys[l].knureon[i].lut_0[j].device = malloc(sizeof(device));
				
			}

			//set values for LUT1 entries
			for(k = 0; k < 28; k++){

			}
			currentDevid++;
			knu++;
		}//end knureon for
		
		card++;		
		if(card == 8){
			card = 0;
			node ++;
		}
		
	}//end qcc for

	return 0;
}

void printBits(size_t const size, void const * const ptr)
{
    unsigned char *b = (unsigned char*) ptr;
    unsigned char byte;
    int i, j;

    for (i=size-1;i>=0;i--)
    {
        for (j=7;j>=0;j--)
        {
            byte = (b[i] >> j) & 1;
            printf("%u", byte);
        }
    }
    puts("");
}

int main() {
	unsigned int colMask = 0x0000E3;
	unsigned int rowMask = 0x00001F;
	unsigned int lfiFrqRdmaMask = 0xFF0000;
	unsigned int lfiToKnureonMask = 0xFFFFFF;
		

	qcc* miwok = malloc(sizeof(qcc) * 64);

	makeKnureons(miwok, 64);

	//unsigned char myBinaryNo = 0b10110110 & 4;
	
	//printBits(sizeof(myBinaryNo), &myBinaryNo);
	printf("%x\n",450560);	
	
	return 0;
}

