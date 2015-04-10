#include <stdio.h>

int main() {
	int num, kind, i;
	float probability = 1.0;
	printf("1: base \t2: brocade \t3: \n");
	printf("Please enter the number of card: ");
	scanf("%d", &num);
	printf("Please enter the kind of card: ");
	scanf("%d", &kind);
	for(i = 0; i < num; i++) {
		if(kind == 1)
			probability = probability*(30 - i)/(80 - i);
		else if(kind == 2)
			probability = probability*(34 - i)/(80 - i);
		else if(kind == 3)
			probability = probability*(16 - i)/(80 - i);
		else
			printf("Error: you enter wrong. \n");
	}
	printf("probability: %.10f \n", probability);
	return 0;
}
