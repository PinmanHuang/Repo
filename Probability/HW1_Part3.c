#include <stdio.h>
#include <stdlib.h>

int main()
{
    int numCard, type, i;
    float probability = 1.0;
    char *card[3];
    card[0] = "基本牌";
    card[1] = "錦囊牌";
    card[2] = "裝備牌";
    printf("1: 基本牌\t 2: 錦囊牌\t 3: 裝備牌\n");
    printf("請輸入牌型(1,2,3): ");
    scanf("%d", &type);
    printf("請輸入張數: ");
    scanf("%d", &numCard);
    for(i = 0; i < numCard; i++) {
        if(type == 1){
            if(numCard <= 34)
                probability = probability*(34 - i)/(80 - i);
            else {
                printf("輸入張數: %d 超過黑色牌且是基本排張數: 34 \n", numCard);
                probability = 0;
                break;
            }
        }
        else if(type == 2){
            if(numCard <= 30)
                probability = probability*(30 - i)/(80 - i);
            else {
                printf("輸入張數: %d 超過黑色牌且是錦囊牌張數: 30 \n", numCard);
                probability = 0;
                break;
            }
        }
        else if(type == 3){
            if(numCard <= 16)
                probability = probability*(16 - i)/(80 - i);
            else {
                printf("輸入張數: %d 超過黑色牌且是裝備牌張數: 16 \n", numCard);
                probability = 0;
                break;
            }
        }
        else {
            printf("牌型輸入錯誤 \n");
            probability = 0;
            break;
        }
    }
    if(probability == 0)
        exit(EXIT_SUCCESS);
    else
        printf("選擇 %s 連續抽中 %d 張機率約為: %f", card[type-1], numCard, probability);
    return 0;
}
