#include <stdio.h>
#include <stdlib.h>

int main()
{
    float probability = 1.0;
    int numCard, i;
    printf("�п�J�s��⤤�����ĪG�i��: ");
    scanf("%d", &numCard);
    for(i = 0; i < numCard; i++)
        probability = probability*(80 - i)/(160 - i);
    if(numCard <= 80)
        printf("�s��⤤%d�i�������ĪG�����v��: %f \n", numCard, probability);
    else
        printf("��J�i��: %d �j��¦�P�i��: 80 \n", numCard);
    return 0;
}
