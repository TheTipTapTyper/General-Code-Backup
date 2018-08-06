#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

typedef struct {
	char firstName[50];
	char lastName[50];
	int id;
	char grade; 
	
}Data;

struct Node{
	struct Node * next;
	Data * data;
};

int main(){
	struct Node * test = malloc(sizeof(struct Node));

	if(test == NULL)
		printf("true");
	else
		printf("false");
	
	
		
	return 0;
}
