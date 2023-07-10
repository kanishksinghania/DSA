//Bucket sort
#include<stdio.h>
#include<stdlib.h>
#define max 100
int max1(int a[max],int n)
{
    int max2=a[0];
    for(int i=0;i<n;i++)
    {
        if(a[i]>max2)
        {
            max2=a[i];
        }
    }
    return max2;
}
void Bucket_sort(int a[max],int n)
{
    int i,j;
    int p=10000;
    int bucket[p];
    for(i=0;i<p;i++)
    {
        bucket[i]=0;
    }   
    for(j=0;j<n;j++)
    {
        ++bucket[a[j]];
    }
    for(i=0,j=0;i<p;i++)
    {
        for(;bucket[i]>0;--bucket[i])
        {
            a[j]=i;
            j++;
        }
    }
}
void accept(float a[max],int b[max],int n)
{
    for(int i=0;i<n;i++)
    {
        printf("Enter percentage:");
        scanf("%f",&a[i]);
    }
    for(int j=0;j<n;j++)
    {
        b[j]=a[j]*100;
    }
}
void display(float a[max],int n)
{
    for(int i=0;i<n;i++)
    {
        printf("%.2f\t",a[i]);
    }
    printf("\n");
}
int main()
{
printf("Entered!!\n");
float A[max];
int B[max],n;
printf("Enter n:");
scanf("%d",&n);
for(int i=0;i<n;i++)
{
    B[i]=0;
}
accept(A,B,n);
printf("\nBefore sorting!!\n");
display(A,n);
printf("\nAfter sorting!\n");
Bucket_sort(B,n);
for(int i=0;i<n;i++)
{
    printf("%0.2f\t",(double)B[i]/100);
}
printf("\nTOP 5 SCORES ARE:\n");
for(int h=n-1;h>4;h--)
{
    printf("%0.2f\n",(double)B[h]/100);
}
return 0;
}

//OUTPUT
/*Entered!!
Enter n:5
Enter percentage:50.0
Enter percentage:60.0
Enter percentage:70.0
Enter percentage:80.0
Enter percentage:90.0

Before sorting!!
50.00   60.00   70.00   80.00   90.00

After sorting!
50.00   60.00   70.00   80.00   90.00
TOP 5 SCORES ARE:
90.00
80.00
70.00
60.00
50.00
*/