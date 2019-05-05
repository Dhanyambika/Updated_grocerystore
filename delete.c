#include<stdio.h>
#include<string.h>
#include "grocery.h"

void delete(void) {
	item old,new;
	time_t t=time(NULL);
	struct tm ti=*localtime(&t);
	char *ch,c[100],day[50];
	int i,len,opt;
	FILE *fp1,*fp2;
	sprintf(day,"%s/%d_%d_%d","files",ti.tm_mday,ti.tm_mon+1,ti.tm_year+1900);
	strcat(day,".txt");
	fp1=fopen(day,"r");
	fp2=fopen("new.txt","w");
	if(fp1==NULL||fp2==NULL)
		printf("Error in creating file......\n");

SELECT:
	printf("Enter the option:\n1.Items to be removed from list\n2.Item purchased from our store(lessened)\n");
	scanf("\n%d",&opt);
	switch(opt) {
	case 1:
		printf("Enter the item name\n");
		scanf("%s",old.name);
		while(fgets(c,100,fp1)!=NULL)
		{
			if((strstr(c,old.name))==0)
				fputs(c,fp2);
		}
		fclose(fp1);
		remove(day);
		rename("new.txt",day);
		fclose(fp2);
		break;
	case 2:
		printf("Enter the ITEM NAME then enter QUANTITY lessened from the stock:\n");
		scanf("\n%s %f",old.name,&new.quantity);
		while(fgets(c,500,fp1)!=NULL)
		{
			if(strstr(c,old.name)!=0)
			{
				sscanf(c,"%s %f %f",old.name,&old.price,&old.quantity);
				if(old.quantity<new.quantity)
				{
					printf("Quantity remaining is lesser than the given value..Do you want to remove it?\n");
					goto SELECT;
				}
				old.quantity-=new.quantity;
				new.total=old.price*old.quantity;
				fprintf(fp2,"%-18s %10.2f %10.2f %15.2f %5d/%d/%d %5d:%d:%d\n",old.name,old.price,old.quantity,new.total,ti.tm_mday,ti.tm_mon+1,ti.tm_year+1900,ti.tm_hour,ti.tm_min,ti.tm_sec);
				continue;
			}
			fputs(c,fp2);
		}
		fclose(fp1);
		remove(day);
		rename("new.txt",day);
		fclose(fp2);
		break;
	default: printf("Enter the correct choice\n");
		goto SELECT;
	}
}
