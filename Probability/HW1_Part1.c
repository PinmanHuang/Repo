#include <stdio.h>
#include <stdlib.h>

int main() {
	int blackCard = 80, redCard = 80, counter = 0, color;
	float probability;
	printf("1: 黑色牌\t 2: 紅色牌\n");
	printf("請輸入1或2表示抽到的牌型，輸入-1結束程式\n");
	while(scanf("%d", &color) && color != -1) {
        if(color == -1)
            break;
        else if(color == 1) {
            if(blackCard != 0)
                blackCard--;
            else {
                printf("目前已經沒有黑牌可以抽出 \n");
                printf("只能輸入2表示目前抽出紅牌 \n");
                continue;
            }
		}
		else if(color == 2) {
            if(redCard != 0)
                redCard--;
            else {
                printf("目前已經沒有紅牌可以抽出 \n");
                printf("只能輸入1表示目前抽出黑牌 \n");
                continue;
            }
		}
		else {
            printf("Error: 輸入牌型錯誤，請輸入1或2表示抽到的牌型，輸入-1結束程式 \n");
            continue;
		}
		if(blackCard == 0 && redCard == 0) {
			blackCard = 80;
			redCard = 80;
		}
		printf("下一次抽中牌滿足洛神效果機率: %d/%d = %f \n", blackCard, blackCard+redCard, (float)blackCard/(blackCard+redCard));
	}
	return 0;
}
