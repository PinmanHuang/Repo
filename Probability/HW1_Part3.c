#include <stdio.h>
#include <stdlib.h>

int main()
{
    int numCard, type, i;
    float probability = 1.0;
    char *card[3];
    card[0] = "�򥻵P";
    card[1] = "�A�n�P";
    card[2] = "�˳ƵP";
    printf("1: �򥻵P\t 2: �A�n�P\t 3: �˳ƵP\n");
    printf("�п�J�P��(1,2,3): ");
    scanf("%d", &type);
    printf("�п�J�i��: ");
    scanf("%d", &numCard);
    for(i = 0; i < numCard; i++) {
        if(type == 1){
            if(numCard <= 34)
                probability = probability*(34 - i)/(80 - i);
            else {
                printf("��J�i��: %d �W�L�¦�P�B�O�򥻱Ʊi��: 34 \n", numCard);
                probability = 0;
                break;
            }
        }
        else if(type == 2){
            if(numCard <= 30)
                probability = probability*(30 - i)/(80 - i);
            else {
                printf("��J�i��: %d �W�L�¦�P�B�O�A�n�P�i��: 30 \n", numCard);
                probability = 0;
                break;
            }
        }
        else if(type == 3){
            if(numCard <= 16)
                probability = probability*(16 - i)/(80 - i);
            else {
                printf("��J�i��: %d �W�L�¦�P�B�O�˳ƵP�i��: 16 \n", numCard);
                probability = 0;
                break;
            }
        }
        else {
            printf("�P����J���~ \n");
            probability = 0;
            break;
        }
    }
    if(probability == 0)
        exit(EXIT_SUCCESS);
    else
        printf("��� %s �s��⤤ %d �i���v����: %f", card[type-1], numCard, probability);
    return 0;
}
