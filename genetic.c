#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int generationCount;

typedef struct {
	char * str;
	float fitness;
	int generationNum;
}Member;

void calculateFitness(Member * population, int popSize, char * target);
Member * createPopulation(int memberSize, int populationSize);
Member * getNewMember(Member * parent1, Member * parent2, int mutationProbability, int numberOfPossibleMutations);
void mutate(char * str, int mutationProbability, int numberOfPossibleMutations);
void printStatistics(Member * population, int popSize);
void printPopulation(Member * population, int popSize);
void printMember(Member member);
void runOneGeneration(Member * population, int popSize, char * target, int mutationProbability, int numberOfPossibleMutations);
char randomChar();
char * getTargetString(int strSize);
int minFitness(Member * population, int popSize);
void sortByFitness(Member * population, int popSize);
void clear();

char randomChar(){
	char result = "abcdefghijklmnopqrstuvwxyz    "[rand() % 30];
	return result;
}

//creates an array of populationSize Member's, each containing a randomly generated
//str of length memberSize
Member * createPopulation(int memberSize, int populationSize) {
	//initializes the generationCount variable to 1
	generationCount = 1;

	//allocate memory for populationSize members	
	Member * population = malloc(sizeof(Member) * populationSize);
	
	//set the seed of the PRNG
	srand((unsigned int)time(NULL));	
	
	int i, j;
	for(i = 0; i < populationSize; i++){
		char* str = malloc(sizeof(char) * (memberSize + 1));
		
		//generate random string
		for(j = 0; j < memberSize; j++) {
			str[j] = randomChar(); 
		}//end for		
		
		//last char must be '\0'
		str[memberSize] = '\0';	

		//create member with str, a starting fitness of zero, and a
		//generationNum of 1
		Member temp = {str, 0, 1};
		
		//add temp to the population
		population[i] = temp;

	}//end for

	return population;

}//end createPopulation function

void printMember(Member member) {
	printf("String:\t\t%s\nFitness:\t%.2f\nGeneration:\t%d\n\n",member.str, member.fitness, member.generationNum);
}

//prints out each member's string, fitness, and generation #
void printPopulation(Member population[], int popSize){
	int i;
	printf("-------------------------------------------------\n");	
	for(i = 0; i < popSize; i++) {
		printMember(population[popSize - 1 - i]);		
	}//end for

}//end printPopulation function

void printStatistics(Member * population, int popSize){
	int num0_10, num10_20, num20_30, num30_40, num40_50, num50_60, num60_70, num70_80, num80_90, num90_100;
	num0_10 = num10_20 = num20_30 = num30_40 = num40_50 = num50_60 = num60_70 = num70_80 = num80_90 = num90_100 = 0;
	int i;
	float temp;
	float total = 0;
	for(i = 0; i < popSize; i++) {
		temp = population[i].fitness;
		if(temp >= 0 && temp < 10)
			num0_10++;
		else if(temp >= 10 && temp < 20)
			num10_20++;
		else if(temp >= 20 && temp < 30)
			num20_30++;
		else if(temp >= 30 && temp < 40)
			num30_40++;
		else if(temp >= 40 && temp < 50)
			num40_50++;
		else if(temp >= 50 && temp < 60)
			num50_60++;
		else if(temp >= 60 && temp < 70)
			num60_70++;
		else if(temp >= 70 && temp < 80)
			num70_80++;
		else if(temp >= 80 && temp < 90)
			num80_90++;
		else if(temp >= 90 && temp <= 100)
			num90_100++;

		total += temp;
	}//end for
	
	printf("Fitness Distribution (lower is better)\n");
	//printf("\tpercent with fitness between values\n");
	printf(" 0 - 10\t\t%d\n", num0_10);
	printf("10 - 20\t\t%d\n", num10_20);
	printf("20 - 30\t\t%d\n", num20_30);
	printf("30 - 40\t\t%d\n", num30_40);
	printf("40 - 50\t\t%d\n", num40_50);
	printf("50 - 60\t\t%d\n", num50_60);
	printf("60 - 70\t\t%d\n", num60_70);
	printf("70 - 80\t\t%d\n", num70_80);
	printf("80 - 90\t\t%d\n", num80_90);
	printf("90 - 100\t%d\n", num90_100);
	printf("Average:\t%.3f\n", total/popSize);
	printf("After %d generations\n", generationCount);
}

//retrieves string from user input
char * getTargetString(int strSize){
	char * str = malloc(sizeof(char) * (strSize + 1));//taking '\n' and '\0' into account
	str = fgets( str, strSize + 1, stdin);
	str[strcspn(str, "\n")] = 0;//removes newline char

	printf("\ntarget string: '%s' is %d charcters long\n\n", str, strlen(str));

	return str;
}

void calculateFitness(Member * population, int popSize, char * target){
	int i, j;
	float numSame;
	int strSize = strlen(population[0].str);	
	
	for(i = 0; i < popSize; i++) {
		numSame = 0;
		for(j = 0; j < strSize; j++)
			numSame += (target[j] == population[i].str[j]);
		population[i].fitness = 100 * numSame/strSize;	
	}//end for

}//end calculateFitness function

Member * getNewMember(Member * parent1, Member * parent2, int mutationProbability, int numberOfPossibleMutations){
	int j, i = 0;
	int geneSize;
	int turn = 0;
	int strSize = strlen(parent1->str);
	char * result = malloc(sizeof(char) * (strSize +1));

	while(i < strSize) {
		do{		
			geneSize = rand() % 6; //section of parent strings to cross are between 0-5 char long		
		}while(geneSize + i > strSize); 
		
		if(turn) {
			for(j = i; j < i + geneSize; j++) {
				result[j] = parent1->str[j];
			}//end for
			turn = 0;
		}else {
			for(j = i; j < i + geneSize; j++) {
				result[j] = parent2->str[j];
			}//end for
			turn = 1;
		}//end else
		i += geneSize;		
	
	}//end while
	
	//randomly changes a few characters
	mutate(result, mutationProbability, numberOfPossibleMutations);
	
	//allocates memory for the new member and then assigns its values
	Member * temp = malloc(sizeof(Member));
	temp->str = result;
	temp->fitness = 0;
	temp->generationNum = generationCount;
	
	return temp;

}//end getNewMember function

//sometimes changes a few characters in the specified string according to the 
//probability and numberOfPossibleMutations arguments
void mutate(char * str, int mutationProbability, int numberOfPossibleMutations){
	int strSize = strlen(str);
	int i;	
	int index;	

	//uses a PRNG to determine if mutations should occur and how many should occur
	if(mutationProbability >= rand() % 100) {
		for(i = 0; i < numberOfPossibleMutations; i++) {
			index = rand() % strSize;
			str[index] = randomChar();	
		}//end for

	}//end if

}//end mutate function

void runOneGeneration(Member * population, int popSize, char * target, int mutationProbability, int numberOfPossibleMutations){
	generationCount++;	

	calculateFitness(population, popSize, target);
	sortByFitness(population, popSize);
	//printPopulation(population, popSize);
	
	int i;
	for(i = popSize/2; i < popSize; i++) {
		population[i] = *getNewMember(&population[i - popSize/2], &population[i + 1 - popSize/2] , mutationProbability, numberOfPossibleMutations);
	}
	
	calculateFitness(population, popSize, target);
	sortByFitness(population, popSize);
	//printPopulation(population, popSize);

}

//implements an insertion sort algorithm to sort the members according to fitness
void sortByFitness(Member * population, int popSize){
	int index;
	for(index = 1; index < popSize; index++) {
		Member key = population[index];
		int position = index;

		while(position > 0 && population[position - 1].fitness < key.fitness) {
			population[position] = population[position - 1];
			position --;
		}//end while
		population[position] = key;
		
	}//end for
	
}

int minFitness(Member * population, int popSize){
	int minIndex = 0;
	int i;
	for(i =0; i < popSize; i++) {
		if(population[minIndex].fitness > population[i].fitness) {
			minIndex = i;
		}
	}//end for

	return minIndex;
}

//clears the input stream
void clear() {
	int c;	
	while((c = getchar()) != '\n' && c != EOF) {} 
}

void printMenu() {
	printf("Genetic String Guesser\n----------------------\nG\tGenerate Population\nP\tPrint Population\nS\tPrint Statistics\nR\tRun One Generation\nT\tRun Ten Generations\nO\tRun One Hundred Generations\nQ\tQuit\n?\tRe-print Menu\n\n");
}

int main() {	
	int popSize;
	int memSize;
	int mutationProbability;
	int numberOfPossibleMutations;
	char * target; 
	char input;
	printMenu();
	int i;

	printf("%p\n", &printMenu);
	
	Member * population;
	
	//runOneGeneration(population, popSize, target, mutationProbability, numberOfPossibleMutations);

	//printStatistics(population, popSize);


	

	do {
		printf("Enter a character:");		
		input = getchar();
		clear();
		input = toupper(input);

		switch(input){
			case 'G':
				//gather information from user
				printf("Enter simulation information as follows:\n");
				printf("(populationSize,stringLength,mutationProbability,numberOfPossibleMutations)\n");			
				scanf("(%d,%d,%d,%d)", &popSize, &memSize, &mutationProbability, &numberOfPossibleMutations);
				printf("Enter target string: ");
				clear();
				target = getTargetString(memSize);
				clear();
				
				//generate population, calculate initial fitness and sort
				population = createPopulation(memSize,popSize);
				calculateFitness(population, popSize, target);
				sortByFitness(population, popSize);
				
				printf("Population of %d members with string length %d created\n", popSize, memSize);
				break;
			case 'P':
				printPopulation(population, popSize);			
				break;
			case 'S':
				printStatistics(population, popSize);
				break;
			case 'R':
				runOneGeneration(population, popSize, target, mutationProbability, numberOfPossibleMutations);
				break;
			case 'T':				
				for(i = 0;i < 10; i++)
					runOneGeneration(population, popSize, target, mutationProbability, numberOfPossibleMutations);  
				break;
			case 'O':
				for(i = 0;i < 100; i++)
					runOneGeneration(population, popSize, target, mutationProbability, numberOfPossibleMutations); 				
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

