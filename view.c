#include<stdio.h>
#include<string.h>
#include "grocery.h"
void view(void) {
	char c,day[50];
	time_t t=time(NULL);
	struct tm ti=*localtime(&t);
	system("clear");
	printf("%s\nWELCOME TO OUR GROCERY STORE\n%s\n",DECOR,DECOR);
	printf("%-20s  %7s  %10s  %12s %11s %12s\n","ITEM NAME","PRICE","QUANTITY","TOTAL","DATE","TIME");
	printf("%s\n",LINE);

	FILE *fp;
	sprintf(day,"%s/%d_%d_%d","files",ti.tm_mday,ti.tm_mon+1,ti.tm_year+1900);
	strcat(day,".txt");
	fp=fopen(day,"r+");
	if(fp==NULL)
		printf("Error in creating file");
	while((c=fgetc(fp))!=EOF)
	printf("%c",c);
	fclose(fp);
	getchar();
	printf("%s\n",LINE);
}
