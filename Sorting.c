#include<stdio.h>
int main() { 
    /*int bs[10],n;
    printf("Enter the number of elements to be arranged: ");
    scanf("%d", &n);
    printf("Enter the elements: ");
    for(int i=0;i<n;i++) {
        scanf("%d", &bs[i]);
    }

    printf("Elements in sorted order are: \n");
    int temp;
    for(int i=0;i<n;i++) {
        for(int j=i+1;j<n;j++) {
            temp = bs[i];
            if(bs[i] > bs[j]) {
                bs[i] = bs[j];
                bs[j] = temp;
            }
        }
        
    }
    for(int i=0;i<n;i++) {
    printf("%d ", bs[i]);
    }


int ss[10],n;
    printf("Enter the number of elements to be arranged: ");
    scanf("%d", &n);
    printf("Enter the elements: ");
    for(int i=0;i<n;i++) {
        scanf("%d", &ss[i]);
}
printf("Elements after selection sorting are: \n");
int min,temp;
for(int i=0;i<n;i++) {
    min = i;
    for(int j=i+1;j<n;j++) {
        temp = ss[j];        
        if(ss[j] < ss[min]) {
        ss[j] = ss[min];
        ss[min] = temp;
    }
}
}
 for(int i=0;i<n;i++) {
    printf("%d ", ss[i]);
    }


int is[10],n;
 printf("Enter the number of elements to be arranged: ");
    scanf("%d", &n);
    printf("Enter the elements: ");
    for(int i=0;i<n;i++) {
        scanf("%d", &is[i]);
    }
printf("Elements after insertion sorting are: \n");
int temp,j;
for(int i=1;i<n;i++) {
    temp = is[i];
    j = i-1;
        while(j>=0 && temp < is[j] ) {
            is[j+1] = is[j];
            j--;
        }
        is[j+1] = temp;
        
    }
   

 for(int i=0;i<n;i++) {
    printf("%d ", is[i]);
    }
    
int shell[10],n;
 printf("Enter the number of elements to be arranged: ");
    scanf("%d", &n);
    printf("Enter the elements: ");
    for(int i=0;i<n;i++) {
        scanf("%d", &shell[i]);
    }

int temp,gap,i;
gap = n/2;
temp=0;
while(gap > 0) {
for(i=0;i<(n-gap);i++) {
    if(shell[i] > shell[i+gap]) {
        temp = shell[i];
        shell[i] = shell[i+gap];
        shell[i+gap] = temp;
        gap++;
    }
    }
    gap=gap/2;
    }
    for(int i=0;i<n;i++) {
    printf("%d ", shell[i]);
    }
    
int input[10],n;
 printf("Enter the number of elements to be arranged: ");
    scanf("%d", &n);
    printf("Enter the elements: ");
    for(int i=0;i<n;i++) {
        scanf("%d", &input[i]);
}
int max=0;
max = input[0];
for(int i=1;i<n;i++) {
    if(max<=input[i])
    max = input[i];
}

printf("Elements after bucket sorting are: \n");
int bucket[max+1];
for(int i=0;i<max+1;i++) {
    bucket[i] = 0;
    } 
for(int j=0;j<n+1;j++) {
    ++bucket[input[j]];
    }
int j=0;
for(int i=0;i<max+1;i++) {
        while(bucket[i]>0) {
            input[j]=i;
            bucket[i]--;
            j++;   
    }
}
     for(int i=0;i<n;i++) {
    printf("%d ", input[i]);
    }
int ls[10],n;
 printf("Enter the number of students: ");
    scanf("%d", &n);
printf("Enter the roll no. of students: \n");
for(int i=0;i<n;i++) {
    scanf("%d", &ls[i]);
    }  

int choice,count;
printf("Enter the roll no. you want: ");
scanf("%d", &choice);
for(int i=0;i<n;i++) {
    if(ls[i] == choice) {
    printf("Record found at position %d", i+1);
    count++;
    }
    if(count==n) {

    printf("Record not found");
    }
}*/
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





