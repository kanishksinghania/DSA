//searching sorting-FDS
//Get student details and apply searching,sorting functions on it
//use struct to store student data
//search-linear and binary   sort-insertion,shell,selection
#include<stdio.h>
#include<stdlib.h>
#define max 50
struct student
{
    int rollno;
    char name[20];
    int age;
};
void accept(struct student a[max],int n)
{
    for(int i=0;i<n;i++)
    {
        printf("For record %d\n",i+1);
        printf("Enter rollno:");
        scanf("%d",&a[i].rollno);
        printf("Enter name:");
        scanf("%s",a[i].name);
        printf("Enter age:");
        scanf("%d",&a[i].age);
    }
}
void display(struct student a[max],int n)
{
    printf("\nRollno\tName\tAge\n");
    for(int i=0;i<n;i++)
    {
        printf("%d\t%s\t%d\n",a[i].rollno,a[i].name,a[i].age);
    }
}
void search(struct student a[max],int n)
{
    int key;
    printf("Enter rollno of record you want to search:");
    scanf("%d",&key);
    int cnt=0;
    for(int i=0;i<n;i++)
    {
        if (a[i].rollno==key)
        {
            printf("record found!!\n");
            printf("Rollno\tName\tAge\n");
            printf("%d\t%s\t%d\n",a[i].rollno,a[i].name,a[i].age);
            cnt++;
        }
    }
    if (cnt==0)
    {printf("Record not found!!");}
}
void shell_sort(struct student A[max],int n)
{
int gap;
gap=n/2;
int swapped=0;
do
{
do
{
swapped=0;
for(int i=0;i<n-gap;i++)
{
if(A[i].rollno>A[i+gap].rollno)
{
struct student temp1;
temp1=A[i];
A[i]=A[i+gap];
A[i+gap]=temp1;
swapped=1;
}
}
}while(swapped==1);
}while((gap=gap/2)>=1);
}
void selection_sort(struct student A[max],int n)
{
int minpos;
for(int i=0;i<n;i++)
{
minpos=i;
for(int j=i+1;j<n;j++)
{
if(A[j].rollno<A[minpos].rollno)
{
minpos=j;
}
}
if(minpos!=i)
{
struct student temp1;
temp1=A[i];
A[i]=A[minpos];
A[minpos]=temp1;
}
}

}
void insertion(struct student A[max],int n)
{
    for(int i=0;i<n;i++)
    {
        int key=A[i].rollno;
        int j=i-1;
        while(j>=0 && A[j].rollno>key)
        {
            A[j+1]=A[j];
            j=j-1;
        }
        A[j+1].rollno=key;
    }
}
void binary(struct student A[max],int high,int low,int key)
{
    int mid;
    int flag=0;
    mid=(high+low)/2;
    if (A[mid].rollno==key)
    {
        printf("Value found!!\n");
        printf("Rollno\tName\tAge\n");
        printf("%d\t%s\t%d\n",A[mid].rollno,A[mid].name,A[mid].age);
        flag=1;
    }
    else if(A[mid].rollno>key)
    {
        high=mid-1;
        binary(A,high,low,key);
    }
    else if(A[mid].rollno<key)
    {
        low=mid+1;
        binary(A,high,low,key);
    }
    if (flag==0)
        printf("Record not found!!\n");
}
//main function
int main()
{
    struct student a[max];
    int key;
    int n,ch;
    int p=1;
    printf("How many records you want to enter:");
    scanf("%d",&n);
    accept(a,n);
    printf("Dispalying all records!!\n");
    display(a,n);
    while(p==1)
    {
    printf("1.Linear search\n2.Binary search\n3.Selection sort\n4.Shell sort\n5.Insertion sort\n6.Exit\n");
    printf("Enter choice:");
    scanf("%d",&ch);
    switch(ch)
    {
    case 1:
        search(a,n);
        break;
    case 2:
        printf("Enter rollno of record you want to search:");
        scanf("%d",&key);
        binary(a,n,0,key);
        break;
    case 3:
        printf("Before sorting!!");
        display(a,n);
        printf("After selection sorting!!");
        selection_sort(a,n);
        display(a,n);
        break;
    case 4:
        printf("Before sorting!!");
        display(a,n);
        printf("After shell sorting!!");
        shell_sort(a,n);
        display(a,n);
        break;
    case 5:
        printf("Before sorting!!\n");
        display(a,n);
        printf("After insertion sorting!!\n");
        insertion(a,n);
        display(a,n);
        break;
    case 6:
        printf("You chose to exit!!");
        exit(0);
    default:
        break;
    }
    printf("Do you want to continue[0-no/1-yes]:");
    scanf("%d",&p);
    }
    printf("Program ended!");
    exit(0);
    return 0;
}

//OUTPUT
/*How many records you want to enter:3
For record 1
Enter rollno:15
Enter name:Kanishk
Enter age:18
For record 2
Enter rollno:16
Enter name:Kavya
Enter age:15
For record 3
Enter rollno:26
Enter name:Singhania
Enter age:19
Dispalying all records!!

Rollno  Name    Age
15      Kanishk 18
16      Kavya   15
26      Singhania       19
1.Linear search
2.Binary search
3.Selection sort
4.Shell sort
5.Insertion sort
6.Exit
Enter choice:1
Enter rollno of record you want to search:15
record found!!
Rollno  Name    Age
15      Kanishk 18
Do you want to continue[0-no/1-yes]:1
1.Linear search
2.Binary search
3.Selection sort
4.Shell sort
5.Insertion sort
6.Exit
Enter choice:2
Enter rollno of record you want to search:16
Value found!!
Rollno  Name    Age
16      Kavya   15
Do you want to continue[0-no/1-yes]:1
1.Linear search
2.Binary search
3.Selection sort
4.Shell sort
5.Insertion sort
6.Exit
Enter choice:3
Before sorting!!
Rollno  Name    Age
15      Kanishk 18
16      Kavya   15
26      Singhania       19
After selection sorting!!
Rollno  Name    Age
15      Kanishk 18
16      Kavya   15
26      Singhania       19
Do you want to continue[0-no/1-yes]:1
1.Linear search
2.Binary search
3.Selection sort
4.Shell sort
5.Insertion sort
6.Exit
Enter choice:4
Before sorting!!
Rollno  Name    Age
15      Kanishk 18
16      Kavya   15
26      Singhania       19
After shell sorting!!
Rollno  Name    Age
15      Kanishk 18
16      Kavya   15
26      Singhania       19
Do you want to continue[0-no/1-yes]:1
1.Linear search
2.Binary search
3.Selection sort
4.Shell sort
5.Insertion sort
6.Exit
Enter choice:6
You chose to exit!!
*/