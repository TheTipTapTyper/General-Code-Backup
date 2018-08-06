#include <errno.h>
#include <stdio.h>
#include <stdlib.h>

int main(){

	FILE *pFile;

	size_t dataInFile;

	long fileSize;

	pFile = fopen("randomnums.bin", "rb+");

	if(pFile == NULL) {
		perror("Error Occured");
		printf("Error Code: %d\n", errno);

		printf("File being created\n\n");

		pFile = fopen("randomnums.bin", "wb+");

		if(pFile == NULL) {
			perror("Error Occured");
			printf("Fatal Error Code: %d\n", errno);
			exit(1);
		}
	}

	int randomNumbers[20];
	int i;
	for(i = 0; i < 20; i++) {
		randomNumbers[i] = rand() % 100;
		printf("Number %d is %d\n",i,randomNumbers[i]);
	}

	fwrite(randomNumbers, sizeof(int), 20, pFile);

	long randomIndexNumber;
	int numberAtIndex;

	printf("Which random number do you want? ");

	scanf("%ld", &randomIndexNumber);

	fseek(pFile, randomIndexNumber * sizeof(int), SEEK_SET);

	fread(&numberAtIndex, sizeof(int), 1, pFile);

	printf("Number at index %d is %ld\n", randomIndexNumber, numberAtIndex);
	
	fclose(pFile);
	
	return 0;
}
