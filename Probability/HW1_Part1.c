#include <stdio.h>
#include <stdlib.h>

int main() {
	int blackCard = 80, redCard = 80, counter = 0, color;
	float probability;
	printf("1: �¦�P\t 2: ����P\n");
	printf("�п�J1��2��ܩ�쪺�P���A��J-1�����{��\n");
	while(scanf("%d", &color) && color != -1) {
        if(color == -1)
            break;
        else if(color == 1) {
            if(blackCard != 0)
                blackCard--;
            else {
                printf("�ثe�w�g�S���µP�i�H��X \n");
                printf("�u���J2��ܥثe��X���P \n");
                continue;
            }
		}
		else if(color == 2) {
            if(redCard != 0)
                redCard--;
            else {
                printf("�ثe�w�g�S�����P�i�H��X \n");
                printf("�u���J1��ܥثe��X�µP \n");
                continue;
            }
		}
		else {
            printf("Error: ��J�P�����~�A�п�J1��2��ܩ�쪺�P���A��J-1�����{�� \n");
            continue;
		}
		if(blackCard == 0 && redCard == 0) {
			blackCard = 80;
			redCard = 80;
		}
		printf("�U�@���⤤�P���������ĪG���v: %d/%d = %f \n", blackCard, blackCard+redCard, (float)blackCard/(blackCard+redCard));
	}
	return 0;
}
