#ifndef GROCERY_H
#define GROCERY_H

#define DECOR "*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*"
#define LINE "----------------------------------------------------------"

extern int count;
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
