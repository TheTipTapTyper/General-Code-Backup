#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main(){
	char buffer[1000];

	FILE * pFile;

	pFile = fopen("testFile.txt","w+");
	
	int i, j;	
	int num;
	char output;

	for(i = 0; i < 60; i++) {
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
			fprintf(pFile,"%c", output);

		}
		fprintf(pFile,"\n");	
	}

	
	//printf("%d", fscanf(pFile, "%s", buffer));	
	rewind(pFile);	
	while(fgets(buffer, 1000, pFile) != NULL) {
		printf("%s", buffer);
	}

	return 0;
}
