#include<stdio.h>
#include<string.h>

struct employee
{
    char name[25];
    int id;
    char rank[10];
    float salary;
    char blood_group[5];
} a[200], emp;

int t_emp = 0;


void enter ()
{
    int i, x, j, id;
    char n[30],s[10],b[5];
    float r;

    printf("\nEnter number of employees' information to add?\n\nChoice: ");
    scanf("%d",&x);

    if(x <= 0)
    {
        printf("\nSorry, Invalid number.");
    }

    if(t_emp >= 200)
    {
        printf("\nLimit is 200.");
    }

    else
    {
        getchar();
        for(i=t_emp,j=1; i < x + t_emp; i++,j++)
        {
            printf("\n\n-> Employee information for %d\n",j);

            printf("\n-> Enter the name: ");
            gets(n);
            strcpy(a[i].name,n);

            printf("\n-> Enter employee ID(Use only number): ");
            scanf("%d",&id);
            a[i].id=id;

            printf("\n-> Enter rank: ");
            getchar();
            gets(s);
            strcpy(a[i].rank,s);

            printf("\n-> Enter salary : ");
            scanf("%f",&r);
            a[i].salary = r;

            printf("\n-> Enter employee's blood group: ");
            getchar();
            gets(b);
            strcpy(a[i].blood_group,b);


        }
        t_emp = t_emp + x;
    }
}


void remove_info()
{
    int d,i,count = 0;
    if(t_emp <= 0)
        printf("Sorry, no information for remove.");
    else
    {
        printf("Enter the id to remove: ");

        scanf("%d", &d);



        for(i=0; i<t_emp; i++)
        {
            if(a[i].id==d)
            {
                strcpy(a[i].name,a[t_emp-1].name);
                a[i].id=a[t_emp-1].id;
                strcpy(a[i].rank,a[t_emp-1].rank);
                a[i].salary =a[t_emp-1].salary ;
                strcpy(a[i].blood_group,a[t_emp-1].blood_group);
                t_emp--;
                printf("\nSuccessfully removed.\n");
                count++;
                break;
            }

        }
        if(count==0)
            printf("\nSorry, ID not found !!!");
    }

}


void edit()
{
    if(t_emp<=0)
    {
        printf("\nSorry, no data to edit.");
        return;
    }
    int i,d;
    float r;
    char s[10];

    printf("\n-> Enter employee ID for Editing information: ");
    scanf("%d",&d);

    for(i=0; i<t_emp; i++)
    {

        if(a[i].id==d)
        {
            printf("\n-> Enter New rank: ");
            getchar();
            gets(s);
            strcpy(a[i].rank,s);
            printf("\n-> Enter New salary: ");
            scanf("%f",&r);
            a[i].salary = r;
            printf("\nInformation has been updated !!");

        }
    }
}


void see_serial()
{
    int i,j,d,left,right,middle;
    printf("\n-> Enter Id for know position: ");
    scanf("%d", &d);
    for(i=0; i<t_emp; i++)
    {
        for(j=0; j<t_emp-1; j++)
        {
            if(a[j].salary <a[j+1].salary )
            {
                strcpy(emp.name,a[j].name);
                strcpy(a[j].name,a[j+1].name);
                strcpy(a[j+1].name,emp.name);

                emp.id=a[j].id;
                a[j].id=a[j+1].id;
                a[j+1].id=emp.id;

                strcpy(emp.rank,a[j].rank);
                strcpy(a[j].rank,a[j+1].rank);
                strcpy(a[j+1].rank,emp.rank);

                emp.salary =a[j].salary ;
                a[j].salary =a[j+1].salary ;
                a[j+1].salary =emp.salary ;

                strcpy(emp.blood_group,a[j].blood_group);
                strcpy(a[j].blood_group,a[j+1].blood_group);
                strcpy(a[j+1].blood_group,emp.blood_group);

            }
        }

    }
    left = 0;
    right = t_emp-1;
    middle = (left+right)/2;
    while(left <= right)
    {
        if(d < a[middle].id)
        {
            left = middle+1;
        }
        else if(d > a[middle].id)
        {
            right = middle-1;
        }
        else if(d == a[middle].id)
        {
            printf("Name : ");
            puts(a[middle].name);
            printf("\n salary : %.2f\n",a[middle].salary );
            printf("Serial according to salary : %d",middle+1);
            break;
        }
        middle = (left+right)/2;
    }
    if(left > right)
    {
        printf("ID Not Found");
    }
}


void search()
{
    int i,d,j;
    printf("Enter Id for know details : ");
    scanf("%d",&d);
    for(j=0; j<t_emp; j++)
    {
        if(a[j].id==d)
        {
            printf("\nName :  ");
            puts(a[j].name);
            printf("Employee ID :  %d",a[j].id);
            printf("\nRank :  ");
            puts(a[j].rank);
            printf("\nSalary :  %.2f",a[j].salary );
            printf("\nBlood group :  ");
            puts(a[j].blood_group);
            break;
        }

    }
    if(j==t_emp)
        printf("ID not found");

}


void emp_showID()
{
    if(t_emp<=0)
        printf("\nEmpty list\n ");
    else
    {
        int i,j,min_idx;
        for (i = 0; i < t_emp-1; i++)
        {
            min_idx = i;
            for (j = i+1; j < t_emp; j++)
            {
                if (a[j].id < a[min_idx].id)
                {
                    min_idx = j;
                }
            }
            strcpy(emp.name,a[min_idx].name);
            strcpy(a[min_idx].name,a[i].name);
            strcpy(a[i].name,emp.name);

            emp.id=a[min_idx].id;
            a[min_idx].id=a[i].id;
            a[i].id=emp.id;

            strcpy(emp.rank,a[min_idx].rank);
            strcpy(a[min_idx].rank,a[i].rank);
            strcpy(a[i].rank,emp.rank);

            emp.salary =a[min_idx].salary ;
            a[min_idx].salary =a[i].salary ;
            a[i].salary =emp.salary ;

            strcpy(emp.blood_group,a[min_idx].blood_group);
            strcpy(a[min_idx].blood_group,a[i].blood_group);
            strcpy(a[i].blood_group,emp.blood_group);

        }
        printf("\nAll listed employees ID's are : \n");
        for (i=0; i<t_emp; i++)
        {
            printf("\n%d\n",a[i].id);
        }
    }
}


int main()
{
    int i, b, p;
    printf("\n***** Welcome to Human Resource Management System *****\n");
    printf("\nDeveloped by <<< Team Everest >>>\nSection: O3\n\n");
    printf("============= Group Members Information =============\n\n");

    printf("\n    Md. Mahfujur Rahman  ------> ID: 192-15-13207");
    printf("\n    Samiul Arafah Dhrubo ------> ID: 192-15-13051");
    printf("\n    Lamia Binte Iqbal    ------> ID: 192-15-13222");
    printf("\n    Saima Binta Younus   ------> ID: 192-15-13137");
    printf("\n    Abdullah Al Ryan     ------> ID: 192-15-13088\n");

    while(1)
    {

        printf("\n\n Choose 1 for enter employees Informations");
        printf("\n Choose 2 for remove Employees information");
        printf("\n Choose 3 for updating Employee information");
        printf("\n Choose 4 for knowing the position based on their salary");
        printf("\n Choose 5 for Search employee Information");
        printf("\n Choose 6 for Total number of Listed employees");
        printf("\n Choose 7 for see all listed ID in Ascending order");
        printf("\n Choose 8 for Exit \n");

        printf("\nEnter your Choice: ");
        scanf("%d",&b);

        system("cls");

        if(b == 1)
            enter();

        if(b == 2)
            remove_info();

        if(b == 3)
            edit();

        if(b == 4)
            see_serial();
        {
            if(b == 5)
                search();
        }

        if(b == 6)
            printf("\nTotal employee in this list : %d", t_emp);

        if(b == 7)
            emp_showID();
        if(b == 8)
            break;
    }

}
