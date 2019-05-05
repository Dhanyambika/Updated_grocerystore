#include<stdio.h>
#include "grocery.h"

int main()
{
	int i;
	char c; 
	while(1)
	{
		printf("\n What you wanna do now??\n 1. View items\n 2. Add items to our stock\n 3. Item purchased from our store\n 4. Total Transaction today\n 5. Quit\n");
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
			case 5:return 0;
			default:printf("You entered an invalid option.Choose from the above options\n ");
				scanf("%d",&i);
				goto CHECK;
		}
		fflush(stdin);
	}
}
