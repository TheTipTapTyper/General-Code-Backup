#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <ctype.h>


char * convertToBase(unsigned int numToConvert, int base){
	char buffer[33];

	char *pConvertedNumber;

	char allValues[] = "0123456789ABCDEF";

	if(base < 2 || base > 16){
		printf("Enter a Number Between 2 and 16");
		exit(1);	
	}

	pConvertedNumber = &buffer[sizeof(buffer)-1];

	*pConvertedNumber = '\0';
	
	do{
		int value = numToConvert % base;
		
		pConvertedNumber = pConvertedNumber -1;

		*pConvertedNumber = allValues[value];


		numToConvert /= base;
		
	}while(numToConvert != 0);

	printf("%s\n", pConvertedNumber);

	return pConvertedNumber;
}

int baseToDecimal(char * pNumber, int baseFrom){
	int i, toThePowerOf = 0;
	int result = 0;
	
	for(i = strlen(pNumber) - 1; i >= 0; i--) {
		int charCode;	
		if(isalpha(pNumber[i])) {
			
			charCode = ((int)tolower(pNumber[i])) -87;
		}else{
			charCode = 	((int)pNumber[i]) - '0';	
		}	
		result += charCode * pow(baseFrom, toThePowerOf);	
		
		toThePowerOf++; 
	}

	printf("%s in base %d equals %d in base 10\n", pNumber, baseFrom, result);

	return result;
}


int main(){
	
	

	convertToBase(466, 12);
	baseToDecimal("A000", 16 );

	return 0;
}
