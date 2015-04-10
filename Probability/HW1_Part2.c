#include <stdio.h>
int main() {
	float probability = 1.0;
	int numCard, i;
	printf("Please enter the number of card: ");
	scanf("%d", &numCard);
	for(i = 0; i < numCard; i++) {
		probability = probability * (80 - i)/(160 - i);
	}
	printf("Probability: %.14f \n", probability);
	return 0;
}
