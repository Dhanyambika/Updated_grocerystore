#include<stdio.h>
#include<string.h>
#include<time.h>
#include "grocery.h"

void update_price(item *old) {
	printf("Enter the new price:");
	scanf("\n%f",&old->price);
	return;
}

void update_quantity(item *old) {
	item new;
	printf("Enter the units added:");
	scanf("\n%f",&new.quantity);
	old->quantity+=new.quantity;
	return;
}
void add(void)
{
	time_t t=time(NULL);
	struct tm ti=*localtime(&t);
	int i,opt,choice;
	char c[500],*ch;
	item old,new;
	FILE *fp,*nfp;
	fp=fopen("grocery.txt","a+");
	if(fp==NULL)
		printf("Error in creating file....\n");
SELECT:
	printf("Please select the option:\n1.Add new item\n2.Upgrade existing stock\n");
	scanf("\n%d",&opt);
	switch(opt) {
	case 1:
		printf("Enter the item to be added in the order:Item name,price,quantity\n");
		scanf("\n%s%f%f",new.name,&new.price,&new.quantity);
		new.total=new.price*new.quantity;
		fprintf(fp,"%-18s %10.2f %10.2f %15.2f %5d/%d/%d %5d:%d:%d\n",new.name,new.price,new.quantity,new.total,ti.tm_mday,ti.tm_mon+1,ti.tm_year+1900,ti.tm_hour,ti.tm_min,ti.tm_sec);
		fclose(fp);
		break;
	case 2:
		printf("What you want to upgrade now?  Enter the ITEM NAME then enter option:\n1.Price\n2.quantity\n3.Both\n");
		scanf("\n%s %d",new.name,&choice);
		
		nfp=fopen("new.txt","w+");
		if(fp==NULL)
			printf("Error in creating file...\n");
		while(fgets(c,500,fp)!=NULL)
		{
			if(strstr(c,new.name)!=0)
			{
				sscanf(c,"%s %f %f",old.name,&old.price,&old.quantity);
				if(choice==1)
				{
					update_price(&old);
				}else if(choice==2)
					{
						update_quantity(&old);
					}else {
						update_price(&old);
						update_quantity(&old);
					}	
			new.total=old.price*old.quantity;
			fprintf(nfp,"%-18s %10.2f %10.2f %15.2f %5d/%d/%d %5d:%d:%d\n",old.name,old.price,old.quantity,new.total,ti.tm_mday,ti.tm_mon+1,ti.tm_year+1900,ti.tm_hour,ti.tm_min,ti.tm_sec);
			continue;
			}
			fputs(c,nfp);
		}
		fclose(fp);
		remove("grocery.txt");
		rename("new.txt","grocery.txt");
		fclose(nfp);
		break;
	default: printf("Enter the correct choice\n");
		goto SELECT;
	}
}
