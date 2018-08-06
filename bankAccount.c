#include <stdio.h>
#include <string.h>
#include <ctype.h>

void printMenu(){
	printf("Choose\t\tAction\nA\t\tAdd BankAccount\nC\t\tMake Credit\nD\t\tMake Debit\nI\t\tApply Monthly Interest\nL\t\tList Bank Accounts\nQ\t\tQuit\n?\t\tDisplay Help\n\n");
}

typedef struct{
	float creditBalance;
	float debitBalance;
	char* name;
	int id;

} bankAccount;

void clear() {
	int c;	
	while((c = getchar()) != '\n' && c != EOF) {} 
}

void main(){
	char input;	
	printMenu();

	while(input != 'Q') {	
		input = getchar();
		clear();
		input = toupper(input);	
		printf("%c\n", input);
		switch(input) {
			case 'A':
				printf("worked\n\n");
				break;
			case 'C':
				
				break;
			case 'D':
				
				break;
			case 'I':
				
				break;
			case 'L':
				
				break;
			case 'Q':
				
				break;
			case '?':
				printMenu();
				break;
			default:
				if(input == '\n') break;			
				printf("Invalid input, try again\n\n");
				break;

		}
	}//end while
}



