#include<stdio.h>
#include "grocery.h"
void view(void) {
	char c;
	system("clear");
	printf("%s\nWELCOME TO OUR GROCERY STORE\n%s\n",DECOR,DECOR);
	printf("%-20s  %7s  %10s  %12s %11s %12s\n","ITEM NAME","PRICE","QUANTITY","TOTAL","DATE","TIME");
	printf("%s\n",LINE);

	FILE *fp;
	if(fp==NULL)
		printf("Error in creating file");
	fp=fopen("grocery.txt","r+");
	while((c=fgetc(fp))!=EOF)
	printf("%c",c);
	fclose(fp);
	getchar();
	printf("%s\n",LINE);
}
