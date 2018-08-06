#include <stdio.h>
#include <string.h>
#include <stdlib.h> 

struct product{
	float price;
	char name[30];
};


main(){
	struct	product *pProduct;
		
	int i, j;
	
	int numberOfProducts;

	printf("Enter the number of Products: ");

	scanf("%d", &numberOfProducts);

	pProduct = (struct product *) malloc(numberOfProducts * sizeof(struct product));

	for(i = 0; i < numberOfProducts; i++){
		printf("Product name: ");
		scanf("%s", &(pProduct + i)->name);

		printf("Product price: ");
		scanf("%f",&(pProduct + i)->price);
		
	}

	printf("Products you entered: ");
	
	for(j = 0; j < i; j++) {
		printf("Product: %s\nWith Price: %f\n", (pProduct+j)->name, (pProduct+j)->price);
	}


}

