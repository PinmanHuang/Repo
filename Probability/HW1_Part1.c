#include <stdio.h>
int main() {
	int blackCard = 80, redCard = 80, totalCard, counter = 0;
	char color;
	float probability;
	while(scanf("%c", &color) && color != '0') {
		if(blackCard == 0 && color == 'B' && totalCard != 0) {
			printf("There is no Black Card now. \n");
			printf("You just can enter R. \n");
			continue;
		}
		if(redCard == 0 && color == 'R' && totalCard != 0) {
			printf("There is no Red Card now. \n");
			printf("You just can enter B. \n");
			continue;
		}
		if(color == 'B' && blackCard != 0) {
			blackCard--;
		}
		if(color == 'R' && redCard != 0) {
			redCard--;
		}
		totalCard = redCard + blackCard;
		if(totalCard == 0) {
			blackCard = 80;
			redCard = 80;
			totalCard = redCard + blackCard;
		}
		probability = (float)blackCard/(float)totalCard;
		printf("%d / %d = %f\n", blackCard, totalCard, probability);
		printf("%d\n", counter);
		counter++;
	}
	return 0;
}
