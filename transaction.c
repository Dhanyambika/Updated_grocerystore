#include<stdio.h>
#include<string.h>
#include "grocery.h"

void transaction(void) {
	int count=0,opt,day,month,year;
	float total,grand_total;
	char c[500],date[50];
	time_t t=time(NULL);
	struct tm ti=*localtime(&t);
	FILE *fp;
	sprintf(date,"%s/%d_%d_%d","files",ti.tm_mday,ti.tm_mon+1,ti.tm_year+1900);
	strcat(date,".txt");
	fp=fopen(date,"r");
	if(fp==NULL)
		printf("error in opening file....\n");
SELECT:
	printf("what do you want to see??\n1.List of all updates today\n2.Total Transaction today\n");
	scanf("%d",&opt);
	printf("%-20s  %7s  %10s  %12s %11s %12s\n","ITEM NAME","PRICE","QUANTITY","TOTAL","DATE","TIME");
	printf("%s\n",LINE);
	switch(opt)
	{
		case 1:
			while(fgets(c,500,fp)!=NULL)
			{
				sscanf(c,"%*s %*f %*f %*f %d/%d/%d",&day,&month,&year);
				if(day==ti.tm_mday && month==ti.tm_mon+1 && year==ti.tm_year+1900)	
				{
					fputs(c, stdout);
					count++;
				}
			}
			break;
		case 2:
			while(fgets(c,500,fp)!=NULL)
			{
				sscanf(c,"%*s %*f %*f %f %d/%d/%d",&total,&day,&month,&year);
				if(day==ti.tm_mday && month==ti.tm_mon+1 && year==ti.tm_year+1900)	
				{
					fputs(c, stdout);
					count++;
					grand_total+=total;
				}
			}
			printf("%s\n",LINE);
			printf("Grand total of transaction today=%7.2f\n",grand_total);
			break;
		default :printf("Please select correct option\n");
			goto SELECT;
			break;
	}
	if(count==0)
		printf("No transactions today\n");
	printf("Total number of transactions today=%d\n",count);				
	fclose(fp);
	printf("%s\n",LINE);
}
