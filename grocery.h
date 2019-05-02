#ifndef GROCERY_Hi
#define GROCERY_H

#include<time.h>
#define DECOR "*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*"
#define LINE "-----------------------------------------------------------------------------------"

extern int count;

time_t t;
struct tm ti;

typedef struct{
	char name[20];
	float price;
	float quantity;
	float total;
}item;

void view(void);
void add(void);
void delete(void);
void transaction(void);

#endif
