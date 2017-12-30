#include<stdio.h>
struct invent
{
char *name[20];
int n;
float price;
};
main()
{struct invent product[3],*ptr;
printf("input");
for(ptr=product;ptr<product+3;ptr++)
scanf("%s%d%f",(*ptr).name,(*ptr).n,(*ptr).price);
printf("output");
ptr=product;
while(ptr<product+3)
{printf("%-20s%5d%10.2f\n,ptr.name,ptr.n,ptr.price");
ptr++;
}}
