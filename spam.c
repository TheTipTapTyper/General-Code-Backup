#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void delay() {
	int c, k;	
	for(c= 0; c < 32767; c++) {
		for(k = 0; k < 100; k++) {
			
		}
	}
}

void spam() {
	int j;	
	int num;
	char output;

	while(1) {
		for(j = 0; j < 270; j++) {
			num = rand() % 11;
						
			switch(num){
				case 0:
					output = '@';
					break;
				case 1:
					output = '#';
					break;
				case 2:
					output = '$';
					break;
				case 3:
					output = '%';
					break;
				case 4:
					output = '^';
					break;
				case 5:
					output = '&';
					break;
				case 6:
					output = '[';
					break;
				case 7:
					output = ']';
					break;
				case 8:
					output = ' ';
					break;
				case 9:
					output = ' ';
					break;
				case 10:
					output = ' ';
					break;
				default:
					break;
			}
			printf("%c", output);

		}
		printf("\n");	
	}
}

void wave() {
	int j;
	int place = 0;
	int direction = 1;
	
	while(1) {
		while(place < 265) {
			for(j = 0; j < place; j++) {
				printf(" ");
			}
			printf("*****");
			for(j = place +5; j < 270; j++) {
				printf(" ");
			}
			printf("\n");
			place++;
			delay();
		}
		while(place > 1) {
			for(j = 0; j < place; j++) {
				printf(" ");
			}
			printf("***");
			for(j = place +3; j < 270; j++) {
				printf(" ");
			}
			printf("\n");
			place--;
			delay();
		}
	}
	
}

void main() {
	spam();

}
