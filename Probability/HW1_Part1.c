#include <stdio.h>
int main() {
	int blackCard = 80, redCard = 80, totalCard;
	char color;
	float probability;
	while(scanf("%c", &color) && color != '0') {
		totalCard = redCard + blackCard;
		if(totalCard == 0) {
			blackCard = 80;
			redCard = 80;
		}
		if(blackCard == 0 && color == 'B') {
			printf("There is no Black Card now. \n");
			printf("You just can enter R. \n");
		}
		if(redCard == 0 && color == 'R') {
			printf("There is no Red Card now. /n");
			printf("You just can enter B. /n");
		}
		if(color == 'B' && blackCard != 0) {
			blackCard--;
			totalCard = redCard + blackCard;
			probability = (float)blackCard/(float)totalCard;
			printf("%d %d = %f\n", blackCard, totalCard, probability);
		}
		else if(color == 'R' && redCard != 0) {
			redCard--;
			totalCard = redCard + blackCard;
			probability = (float)blackCard/(float)totalCard;
			printf("%d %d = %f\n", blackCard, totalCard, probability);
		}
	}
	return 0;
}
