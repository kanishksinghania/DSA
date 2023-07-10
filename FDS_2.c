//sparse matrix and functions
//solution try
#include<stdio.h>
#include<stdlib.h>
//for matrix input
void matrices(int Arr[10][10],int m,int n)
{
    int i,j;
    for(i=0;i<m;i++)
    {
        for(j=0;j<n;j++)
        {
            printf("value for Arr[%d][%d]:",i,j);
            scanf("%d",&Arr[i][j]);
        }
    }
}
//for displaying matrix
void display(int Arr[10][10],int m,int n)
{
    for(int i=0;i<m;i++)
    {
        for(int j=0;j<n;j++)
        {
            printf("%d\t",Arr[i][j]);
        }
        printf("\n");
    }
}
//for compact form conversion
void compact(int A[10][10],int B[10][10],int m,int n)
{
    B[0][0]=m;
    B[0][1]=n;
    int k=1;
    for(int i=0;i<m;i++)
    {
        for(int j=0;j<n;j++)
        {
            if (A[i][j]!=0)
            {
                B[k][0]=i;
                B[k][1]=j;
                B[k][2]=A[i][j];
                k++;
            }
        }
    }
    B[0][2]=k-1;
}
//for transpose of compact form
void transpose(int A[10][10],int B[10][10])
{
    int m=A[0][0];
    int n=A[0][1];
    int t=A[0][2];
    B[0][0]=n;
    B[0][1]=m;
    B[0][2]=t;
    if (t<=0)
    return;
    else
    {
    int q=1;
    for(int i=0;i<m;i++)
    {
        for(int p=1;p<t+1;p++)
        {
            if(A[p][1]==i)
            {
                B[q][0]=A[p][1];
                B[q][1]=A[p][0];
                B[q][2]=A[p][2];
                q++;
            }
        }
    }
    }
}
//for converting back to sparse
void sparse(int A[10][10],int B[10][10])
{
    int g=1;
    for(int i=0;i<A[0][0];i++)
    {
        for(int j=0;j<A[0][1];j++)
        {
            if(A[g][0]==i && A[g][1]==j)
            {
                B[i][j]=A[g][2];
                g++;
            }
            else
            {
                B[i][j]=0;
            }
        }
    }
}
//Fast transpose
void fast_transpose(int A[10][10],int B[10][10])
{
    int S[10],T[10];
    int m=A[0][0];
    int n=A[0][1];
    int t=A[0][2];
    int p;
    B[0][0]=n;
    B[0][1]=m;
    B[0][2]=t;
    if (t<0)
        printf("Error!!");
    else
    {
        for(int i=0;i<n;i++)
        {
            S[i]=0;
        }
        for(int j=0;j<t;j++)
        {
            S[A[j][1]]=S[A[j][1]]+1;
        }
        T[0]=1;
        for(int h=1;h<n;h++)
        {
            T[h]=T[h-1]+S[h-1];
        }
        for(int i=1;i<t;i++)
        {
            p=A[i][1];
            B[T[p]][0]=A[i][1];
            B[T[p]][1]=A[i][0];
            B[T[p]][2]=A[i][2];
            T[p]++;
        }
    }
}
//Addition function try
void add_sparse(int A[10][10],int B[10][10],int C[10][10])
{
    int m1=A[0][0];
    int n1=A[0][1];
    int t1=A[0][2];
    int m2=B[0][0];
    int n2=B[0][1];
    int t2=B[0][2];
    if (m1==m2 && n1==n2)
    {
        if(t1==0 && t2==0)
        {
            return;
        }
        C[0][0]=m1;
        C[0][1]=n1;
    }
    int i=1,j=1,k=1;
    while(i<=t1 && j<=t2)
    {
        if(A[i][0]==B[j][0])
        {
            if(A[i][1]==B[j][1])
            {
                int temp=A[i][2]+B[j][2];
                if(temp!=0)
                {
                    C[k][0]=A[i][0];
                    C[k][1]=A[i][1];
                    C[k][2]=temp;
                    k=k+1;
                }
                i++;
                j++;
            }
            if(A[i][1]<B[j][1])
            {
                C[k][0]=A[i][0];
                C[k][1]=A[i][1];
                C[k][2]=A[i][2];
                k++;
                i++;
            }
            if(A[i][1]>B[j][1])
            {
                C[k][0]=B[j][0];
                C[k][1]=B[j][1];
                C[k][2]=B[j][2];
                k++;
                j++; 
            }
        }
        if(A[i][0]<B[j][0])
        {
            C[k][0]=A[i][0];
            C[k][1]=A[i][1];
            C[k][2]=A[i][2];
            k++;
            i++;
        }
        if(A[i][0]>B[j][0])
        {
            C[k][0]=B[j][0];
            C[k][1]=B[j][1];
            C[k][2]=B[j][2];
            k++;
            j++; 
        }
    }
    while(i<=t1)
    {
        C[k][0]=A[i][0];
        C[k][1]=A[i][1];
        C[k][2]=A[i][2];
        k++;
        i++;
    }
    while(j<=t2)
    {
        C[k][0]=B[j][0];
        C[k][1]=B[j][1];
        C[k][2]=B[j][2];
        k++;
        j++;
    }
    C[0][2]=k-1;
}
//main function
int main()
{
    int A[10][10],B[10][10],C[10][10],D[10][10],m,n;
    for(int i=0;i<10;i++){
        for(int j=0;j<10;j++){
            C[i][j]=0;
        }
    }
    printf("Enter rows:");
    scanf("%d",&m);
    printf("Enter column:");
    scanf("%d",&n);
    matrices(A,m,n);
    printf("Original sparse matrix\n");
    display(A,m,n);
    printf("Compact form matrix\n");
    compact(A,B,m,n);
    display(B,B[0][2]+1,3);
    int ch;
    printf("1. Transpose\n2. Fast Transpose\n");
    printf("Enter choice:");
    scanf("%d",&ch);
    switch(ch)
    {
        case 1:
        printf("Displaying transpose of sparse matrix\n");
        transpose(B,C);
        display(C,B[0][2]+1,3);
        break;
        case 2:
        printf("Displaying fast transpose of sparse matrix\n");
        fast_transpose(B,D);
        display(D,B[0][2]+1,3);
        break;
        default:
        exit(0);
    }
    return 0;
}

//OUTPUT
//OUTPUT 1
/*Enter rows:2
Enter column:3
value for Arr[0][0]:1
value for Arr[0][1]:0
value for Arr[0][2]:0
value for Arr[1][0]:4
value for Arr[1][1]:0
value for Arr[1][2]:0
Original sparse matrix
1       0       0
4       0       0
Compact form matrix
2       3       2
0       0       1
1       0       4
1. Transpose
2. Fast Transpose
Enter choice:2
Displaying fast transpose of sparse matrix
3       2       2
0       0       1
0       2       3
*/
//OUTPUT 2
/*Enter rows:2
Enter column:3
value for Arr[0][0]:1
value for Arr[0][1]:0
value for Arr[0][2]:0
value for Arr[1][0]:4
value for Arr[1][1]:0
value for Arr[1][2]:0
Original sparse matrix
1       0       0
4       0       0
Compact form matrix
2       3       2
0       0       1
1       0       4
1. Transpose
2. Fast Transpose
Enter choice:1
Displaying transpose of sparse matrix
3       2       2
0       0       1
0       1       4
*/
