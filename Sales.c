/**
 * Author - Debag101
 * Desc - Sales adviser
 * Date - 1 6 2023
 * */

#include <stdio.h>

// Creating a struct to store information about the product
typedef struct {
	char name[128];
	float price;
	int usage;
	int popularity;
}pri;

// Creating a struct var
pri pr;

// Analyzes product
void analyze() {
	// Gives a score to each product
	int score = 0;
	
	// Basis of scoring
	if(pr.price < 200) 
		score++;
	if(pr.usage > 80)
		score++;
	if(pr.popularity > 7)
		score++;
	
	// Score decides if product is sellable or not
	if(score < 1) {
		printf("\n%s is a terrible product !", pr.name);
	}else if(score < 2) {
		printf("\n%s is not good enough to be sold ", pr.name);
	}else if(score < 3) {
		printf("\n%s is good enough to be sold !", pr.name);
	}
}

// Main exec starts
int main(int argc, char const *argv[]) {
	
	// Getting product name
	printf("\nEnter name of the product => ");
	fgets(pr.name,128,stdin);

	// Goto label for efficient logging of negative_price
	negative_price:
		printf("\nEnter the price of the product => ");
		scanf("%f", &pr.price);
		if(pr.price < 0) {
			printf("\nPlease enter valid price !");
			goto negative_price;
		}

	// Similar to price for correct range
	not_in_range:
		printf("\nEnter the popularity of your product from 1 - 10 => ");
		scanf("%d", &pr.popularity);
		if(pr.popularity < 0 || pr.popularity > 10) {
			printf("\nPlease enter valid range !");
			goto not_in_range;
		}

	// Similar to the above
	not_in_range_usage:
		printf("\nEnter usage of product fromo 1 - 100 => ");
		scanf("%d", &pr.usage);
		if(pr.usage < 0 || pr.usage > 100) {
			printf("\nPlease enter valid range !");
			goto not_in_range_usage;
		}
	
	// Prints analysis
	analyze();
	
	return 0;
}
