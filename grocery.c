#include<stdio.h>
#include "grocery.h"

int main()
{
	int i;
	char c; 
	system("clear");
	printf("WELCOME TO GROCERY SHOP\n");
	do {
		printf("\n What you wanna do now??\n 1.View items\n 2. Add items to our stock\n 3. Item purchased from our store\n 4.. Total Transaction today\n");
		scanf("%d",&i);
CHECK:
		switch(i)
		{
			case 1:view();
				break;
			case 2:add();
				break;
			case 3:delete();
				break;
			case 4:transaction();
				break;
			default:printf("You entered an invalid option.Choose from the above options\n ");
				scanf("%d",&i);
				goto CHECK;
		}
		fflush(stdin);
		printf("Do you want to continue? Y/N\n");
		scanf("\n%c",&c);
	}while(c=='Y'||c=='y');
		return 0;
}
