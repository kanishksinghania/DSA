/*
 ============================================================================
 Name        : 1.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
struct student
{
	int rollno;
	char name[20];
	char city[20];
	int marks;
};
int main ()
{
	struct student s[20];
	int n,k,ch,low,high ;
	printf("Enter number of students\n");
	scanf("%d",&n);
	accept(s,n);
	Print(s,n);

	while(1)
	{
	printf("Press 1 for linear search \n 2 for binary search \n 3 for sentinel search \n 4 to rec binary \n5 to bubble sort \n 6 to selection sort \n 7 to insertion sort \n 8 to quick sort \n 9 to shell sort\n10 to break\n");
	scanf("%d",&ch);
	if (ch==10)
		break;
	else
   {
	switch (ch)
	 {
	case 1:
		printf("Enter roll no to be searched\n");
			scanf("%d",&k);
		linsr(s,n,k);
		break;
	case 2:
		printf("Enter roll no to be searched\n");
		scanf("%d",&k);
		brsr(s,n,k);
		break ;
	case 3:
		printf("Enter roll no to be searched\n");
		scanf("%d",&k);
		snsr(s,n,k);
		break;
	case 4:
		printf("Enter roll no to be searched\n");
		scanf("%d",&k);
		low=0;
		high=n;
		bssrr(s,low,high,k);
		break;
	case 5:
		bbsrt(s,n);
		Print(s,n);
		break;
	case 6:
		sltsrt(s,n);
		Print(s,n);
		break;
	case 7:
		inssrt(s,n);
		Print(s,n);
		break;
	case 8:
		low=0;
		high=n-1;
		QS(s,low,high);
		Print(s,n);
		break;
	case 9:
		shesrt(s,n);
		Print(s,n);
	    }
   }
}
}
void accept(struct student s[20], int n)
{
	for(int i=0;i<n;i++)
	{
		printf("Enter roll no , name , city,marks\n");
		scanf("%d%s%s%d",&s[i].rollno, &s[i].name,&s[i].city, &s[i].marks);
	}
}
void Print(struct student s[20], int n)
{
	for(int i=0;i<n;i++)
		{
		printf("roll no , name , city,marks are \n");
		printf("%d\t%s\t%s\t%d\n",s[i].rollno, s[i].name,s[i].city, s[i].marks);
		}
}
void linsr(struct student s[20],int n,int k)
{
	int flag=0;
	for (int i =0;i<n;i++)
	{
		if(s[i].rollno==k)
		{
			flag=1;
			printf("Key found at location %d\n",i+1);
			printf("%d\t%s\t%s\t%d\n",s[i].rollno, s[i].name,s[i].city, s[i].marks);
			break;
		}
	}
	if(flag==0)
		printf("Key not found\n");
}
void brsr(struct student s[20], int n , int k)
{	int mid;
	int low =0;
	int high = n-1;
	while(low<=high)
	{
		mid = (low + high)/2;
		if(s[mid].rollno==k)
			{
			printf("Key found at %d\n",mid+1);
			printf("%d\t%s\t%s\t%d\n",s[mid].rollno, s[mid].name,s[mid].city, s[mid].marks);
			break;
			}
		else if(s[mid].rollno>k)
			high=mid-1;
		else if(s[mid].rollno <k)
			low=mid+1;

	}
	if(low>high)
	printf("Key not found\n");
}
void snsr(struct student s[20],int n , int k )
{
	s[n].rollno=k;
	int i =0;
	while(s[i].rollno != k)
	{
		i++;
	}
	if(i<n)
		{printf("Key present at location %d\n",i+1);
		printf("%d\t%s\t%s\t%d\n",s[i].rollno, s[i].name,s[i].city, s[i].marks);}
	else
		printf("Key not found\n");
}
void bssrr(struct student s[20],int low,int high,int k)
{
	int mid=(high+low)/2;
	if(k==s[mid].rollno)
		{printf("key found at %d\n",mid);
		printf("%d\t%s\t%s\t%d\n",s[mid].rollno, s[mid].name,s[mid].city, s[mid].marks);}
	else if (k < s[mid].rollno)
		bssrr(s,low,mid-1,k);
	else
		bssrr(s,mid+1,high,k);
}
void bbsrt(struct student s[20],int n)
{
	struct student temp;
	for(int i =0;i<n;i++)
	{
		for (int j=0;j<n;j++)
		{
			if (s[j].rollno>s[j+1].rollno)
			{
				temp=s[j+1];
				s[j+1]=s[j];
				s[j]=temp;
			}
		}
	}
}
void sltsrt(struct student s[20],int n)
{
	int min,pos;
	struct student temp;
	for (int j=0;j<n;j++)
	{
		min=s[j].rollno;
		pos=j;
		for (int i =j+1; i<n; i++)
		{
			if(min>s[i].rollno)
			{
				min=s[i].rollno;
				pos=i;
			}

		}
		temp=s[j];
		s[j]=s[pos];
		s[pos]=temp;
	}
}
void inssrt(struct student s[20],int n)
{
	int temp,pos;
	for (int i =1;i<n;i++)
	{
		temp=s[i].rollno;
		pos=i-1;
		while(s[pos].rollno>temp && pos>=0)
		{
			s[pos+1].rollno=s[pos].rollno;
			pos--;

		}
		s[pos+1].rollno=temp;
	}
}
int prtn(struct student s[20],int low,int high)
{ struct student temp;
	int i =low;
	int j=high;
	int pvt=s[low].rollno;
while(i<=j)
	{
		while(s[i].rollno<=pvt && i<high)
			i++;
		while (s[j].rollno>pvt && j>=low)
			j--;
		if(i<=j)
			{
			temp=s[i];
			s[i]=s[j];
			s[j]=temp;
			}



	if(i>j)
	{
	temp=s[low];
	s[low]=s[j];
	s[j]=temp;
	}
	}
	return j;

}
void QS(struct student s[20],int low,int high)
{
	if (low<high)
	{
	int j= prtn(s,low,high);
	QS(s,low,j-1);
	QS(s,j+1,high);
	}
}
void shesrt(struct student s[20],int n)
{	struct student temp;
	int gap =n/2;
	int swapped;
	do
	{
		do
		{
			swapped=0;
			for(int i=0;i<n-gap;i++)
				if(s[i].rollno>s[i+gap].rollno)
				{
					temp=s[i+gap];
					s[i+gap]=s[i];
					s[i+gap]=temp;
					swapped=1;
				}
		}while(swapped==1);
}while((gap=gap/2)>=1);
}
