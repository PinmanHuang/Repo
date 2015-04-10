#include <stdio.h>
#include <stdlib.h>

int main()
{
    float probability = 1.0;
    int numCard, i;
    printf("請輸入連續抽中洛神效果張數: ");
    scanf("%d", &numCard);
    for(i = 0; i < numCard; i++)
        probability = probability*(80 - i)/(160 - i);
    if(numCard <= 80)
        printf("連續抽中%d張為洛神效果的機率為: %f \n", numCard, probability);
    else
        printf("輸入張數: %d 大於黑色牌張數: 80 \n", numCard);
    return 0;
}
