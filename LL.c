#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
	char * firstName;
	char * lastName;
	int id;
	char grade; 
	
}Data;

struct Node{
	struct Node * next;
	Data * data;
};

struct Node * first;


void clear();
//void add(Data * newData);
void removeFirst();
void removeAll();
void addStudent(Data * newData, struct Node * newNode);
//void removeStudent();
//Data* next();
//(struct Node*) peek();
//bool hasNext();
void printNode(struct Node * node);
void printAll();
void printMenu();
//bool addStudent();//takes student details from user input and adds a node at the begining of the list
void updateGrade();//takes id of student to update from user input and updates their grade, if they exist

//clears the input stream
void clear() {
	int c;	
	while((c = getchar()) != '\n' && c != EOF) {} 
}

//adds a node on to the begining of the list, or creates one if current is null
void addStudent(Data * newData, struct Node * newNode) {
	char * temp1 = malloc(sizeof(char) * 50);
	char * temp2 = malloc(sizeof(char) * 50);;
	int temp3 = 0;
	char temp4;

	printf("Enter student first name: ");
	fgets(temp1, 50, stdin);

	printf("Enter student last name: ");
	fgets(temp2, 50, stdin);

	printf("Enter student id: ");
	scanf("%d", &temp3);

	printf("Enter student grade: ");
	clear();
	temp4 = toupper(getchar());
	clear();
	printf("%d\n",temp4);
	
	temp1[strcspn(temp1, "\n")] = 0;
	temp2[strcspn(temp2, "\n")] = 0;

	newData->firstName = temp1;
	newData->lastName = temp2;
	newData->id = temp3;
	newData->grade = temp4;

	newNode->data = newData;
	
	if(first == NULL) {	
		first = newNode;
	}
	else {
		newNode->next = first;
		first = newNode;
	}
}

/*
//adds a node at the current location
void add(Data * newData) {
	if(current == NULL){ //list is empty
		addFirst(newData);
		current = NULL;
	}
	else {
		struct Node newNode = {.data = newData};
		newNode.next = current->next;		
		current->next = &newNode;
		current = &newNode;
	}
	previous = current;
}*/

void freeNode(struct Node* temp) {
	free(temp->data->firstName);
	free(temp->data->lastName);
	free(temp->data);
	free(temp);
}

//removes the first node and returns its data
void removeFirst(){
	if(first == NULL) 
		printf("List is empty");
	else {				
		struct Node * temp = first;		
		first = first->next;
		freeNode(temp);
	}
}

void removeAll(){//shout to my boi chris
	while (first) {		
		removeFirst();
	}
}

//removes the node at the current location and sets current to the previous node
/*void removeStudent() {
	int tempID = malloc(sizeof(int));	

	printf("Enter id of student to be removed: ");
	scanf("%d", tempID);

	if(previous != current){ //called after next()
		if(current == first)
			removeFirst();
		else
			previous->next = current->next; 
	}
	else //not called after next
		printf("Illegal call. Remove() must be called after next()");
	current = previous;
}*/

/*
//advances to the next node and returns its data
Data* next() {
	if(hasNext() == false){ 		
		printf("At end of list\n\n");
		Data blankData;
		return NULL;
	}	
	else {
		previous = current;	
		if(current == NULL) //not traversed yet		
			current = first;	
		else
			current = current->next;
		return current->data;	
	}	
}*/

/*
//returns the current node without removing it 
Data* peek() {
	return current->data;
}
*/

/*
//returns true is there is a next node and false if the current node is the end of the list
bool hasNext(struct Node * current) {	
	if(current == NULL){
		if(first != NULL)
			return true;
		else
			return false;
	}
	else {
		if(current->next != NULL)
			return true;
		else
			return false;
	}	
	
} */

void printNode(struct Node * node){
	if(node)	
		printf("\nFirst Name:\t%s\nLast Name:\t%s\nID:\t\t%d\nCourse Grade:\t%c\n\n",node->data->firstName,node->data->lastName,node->data->id,node->data->grade);
}

void printAll() {
	if(first != NULL) {
		struct Node * temp = first;
		
		do {
			printNode(temp);
			temp = temp->next;
		}while(temp);
	}
}

void printMenu() {
	printf("Student Grade Manager\n---------------------\nA\tAdd student\nR\tRemove Student\nU\tUpdate Grade\nL\tList Students\nC\tClear List\nQ\tQuit\n?\tRe-print Menu\n\n");
}

int main() {
	struct Node current;
	struct Node previous;
	char input;	
	printMenu();

	do{
		
		printf("Enter a character:");		
		input = getchar();
		clear();
		input = toupper(input);

		switch(input){
			case 'A':;
				Data * newData = malloc(sizeof(Data));				
				struct Node * newNode = malloc(sizeof(struct Node));								
				addStudent(newData, newNode);
				break;
			case 'R':				
				//removeStudent();
				break;
			case 'U':
				//updateGrade();
				break;
			case 'L':
				printAll();
				break;
			case 'C':
				removeAll();
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

	}while(input != 'Q');	
	







	return 0;
}
