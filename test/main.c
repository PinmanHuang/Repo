#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

char *replicate(char *w, int t){
  int wl;
  char *nnews,*news;

  if(t==0){
     news=(char *)malloc(1);
     news[0]='\0';
     return news;
   }

  wl=strlen(w);
  news=(char *)malloc(t*wl+1);
  nnews=replicate(w,t-1);

  strcpy(news,nnews);
  strcpy(news+(t-1)*wl,w);

  free(nnews);

  return news;
}

int main()
{
   // char w[100],*s;
    char *s;
    int t;
    char w[250]="1234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890";

  //  printf("What words do you want to copy? :");
  //  scanf("%s",w);
    printf("What times do you want to copy? :");
    scanf("%d",&t);

    clock_t start = clock();
    s=replicate(w,t);
    printf("The string is:%s\n",s);
    clock_t end = clock();
	printf("total time=%f seconds",((float)(end-start))/1000.0);
    return 0;
}
