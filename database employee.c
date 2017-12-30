#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <string.h>
int main()
{
    FILE *fp, *fd;
    char another, choice;
    struct emp
    {
        char ename[40];
        int age;
        float basic;
    };
    struct emp e;
    char empname[40];
    long int rs;
    fp = fopen("EMP.DAT","rb+");
    if(fp == NULL)
    {
        fp = fopen("EMP.DAT","wb+");
        if(fp == NULL)
        {
            printf("Cannot open file");
            exit(1);
        }
    }
    rs = sizeof(e);
    while(1)
    {
        system("cls");
        printf("1. Add Record\n");
        printf("2. List Records\n");
        printf("3. Modify Records\n");
        printf("4. Delete Records\n");
        printf("5. Delete All Records\n");
        printf("6. Exit\n");
        printf("Your Choice: \n");
        choice  = getche();
        switch(choice)
        {
            case '1':
                system("cls");
                fseek(fp,0,SEEK_END);
                another = 'y';
                while(another == 'y')
                {
                    printf("\nEnter new name: \n");
                    scanf("%s",&e.ename);
                    printf("Enter age:  \n ");
                    scanf("%d",&e.age);
                    {while(e.age>100)
                    {printf("Age invalid\n");
                        printf("Enter another age:  \n");
                        scanf("%d",&e.age);
                    }}
                    printf("Enter the salary:  \n ");
                    scanf("%f",&e.basic);
                    {while(e.basic<0)
                    {printf("Salary invalid\n");
                        printf("Enter another salary:  \n");
                        scanf("%d",&e.basic);
                    }}
                    fwrite(&e,rs,1,fp);
                    printf("\nAdd another record(y/n)\n");

                    another = getche();
                }
                break;
            case '2':
                system("cls");
                rewind(fp);
                while(fread(&e,rs,1,fp)==1)
                {
                    printf("\n%s %d %.2f",e.ename,e.age,e.basic);
                }
                getch();
                break;
            case '3':
                system("cls");
                another = 'y';
                while(another == 'y')
                {
                    printf("Enter the employee name to modify: ");
                    scanf("%s",&empname);
                    rewind(fp);
                    while(fread(&e,rs,1,fp)==1)
                    {
                        if(strcmp(e.ename,empname) == 0)
                        {

                            printf("Enter age:  \n ");
                            scanf("%d",&e.age);
                            {while(e.age>100)
                            {printf("Age invalid\n");
                                printf("Enter another age:  \n");
                                scanf("%d",&e.age);
                            }}
                            printf("Enter the salary:  \n ");
                            scanf("%f",&e.basic);
                            {while(e.basic<0)
                            {printf("Salary invalid\n");
                                printf("Enter another salary:  \n");
                                scanf("%d",&e.basic);
                            }}
                            fseek(fp,-rs,SEEK_CUR);
                            fwrite(&e,rs,1,fp);
                            {if(e.age>100)
                                printf("Age invalid");
                            }
                            break;
                        }
                    }
                    printf("\nModify another record(y/n)");

                    another = getche();
                }
                break;
            case '4':
                system("cls");
                another = 'y';
                while(another == 'y')
                {
                    printf("\nEnter name of employee to delete: ");
                    scanf("%s",&empname);
                    fd = fopen("Temp.dat","wb");
                    rewind(fp);
                    while(fread(&e,rs,1,fp) == 1)
                    {
                        if(strcmp(e.ename,empname) != 0)
                        {
                            fwrite(&e,rs,1,fd);
                        }
                    }
                    fclose(fp);
                    fclose(fd);
                    remove("EMP.DAT");
                    rename("Temp.dat","EMP.DAT");
                    fp = fopen("EMP.DAT", "rb+");
                    printf("Delete another record(y/n)");

                    another = getche();
                }
                break;
            case '5':
                fp = fopen("EMP.dat","wb");
                fclose(fp);
                break;
            case '6':
                fclose(fp);
                exit(0);
        }
    }
    return 0;
}
