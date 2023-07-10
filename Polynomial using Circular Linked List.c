#include<stdio.h>
#include<stdlib.h>
#include<math.h>
struct poly {
	int coeff;
	int expo;
	struct poly *next;
};

void create1(struct poly *H)
{
	struct poly *temp;
	temp=H;
	int ch=1;
	while(ch!=0)
	{
		struct poly *curr;
		curr=(struct poly *)malloc(sizeof(struct poly));
		printf("Enter coefficient:");
		scanf("%d",&curr->coeff);
		printf("enter exponent:");
		scanf("%d",&curr->expo);
		curr->next=H;
		temp->next=curr;
		temp=curr;
		printf("Enter 1 to add more or 0 to stop:");
		scanf("%d",&ch);
	}
} 

void display(struct poly *H)
{
		struct poly *curr;
		curr=H->next;
		while(curr!=H)
		{
            if(curr->expo!=0)
			{printf("[%dx^(%d)]+",curr->coeff,curr->expo);}
            else
            {printf("[%d]",curr->coeff);}
			curr=curr->next;
		}
}

void Add(struct poly *H1,struct poly *H2,struct poly *H3)
{
	struct poly *curr1,*curr2,*curr3,*temp;
	curr1=H1->next;
	curr2=H2->next;
	curr3=H3;
	while(curr1->expo!=-1 || curr2->expo!=-1)
	{
        temp=(struct poly *)malloc(sizeof(struct poly));
		if(curr1->expo > curr2->expo)
		{
			temp->coeff=curr1->coeff;
			temp->expo=curr1->expo;
			curr3->next=temp;
			temp->next=H3;
			curr3=curr3->next;
			curr1=curr1->next;
		}
		else if(curr2->expo > curr1->expo)
		{
			temp->coeff=curr2->coeff;
			temp->expo=curr2->expo;
            curr3->next=temp;
            temp->next=H3;
			curr3=curr3->next;
			curr2=curr2->next;
		}
		else if(curr1->expo == curr2->expo)
		{
			temp->coeff=(curr1->coeff) + (curr2->coeff);
			temp->expo=curr1->expo;
            curr3->next=temp;
            temp->next=H3;
			curr3=curr3->next;
			curr1=curr1->next;
			curr2=curr2->next;
		}
	}
}

int evaluate(struct poly *H)
{
    struct poly *curr;
    int x;
    int sum1=0;
    printf("\nEnter value of x:");
    scanf("%d",&x);
    curr=H->next;
    while(curr!=H)
    {
        int a1=pow(x,(curr->expo));
        int a2=a1*(curr->coeff);
        sum1+=a2;
        curr=curr->next;
    }
    return sum1;
}
//main menu
//main function
int main()
{
	struct poly *Head1;
	struct poly *Head2;
	struct poly *Head3;
    struct poly *Head4;
    int evaluation;
	Head1=(struct poly *)malloc(sizeof(struct poly));
	Head2=(struct poly *)malloc(sizeof(struct poly));
	Head3=(struct poly *)malloc(sizeof(struct poly));
    Head4=(struct poly *)malloc(sizeof(struct poly));
	Head1->coeff=-1;
	Head1->expo=-1;
	Head2->coeff=-1;
	Head2->expo=-1;
	Head1->next=Head1;
	Head2->next=Head2;
	Head3->next=Head3;
    Head4->next=Head4;
	int a;
	a=1;
	while(a!=5) {

	printf("\nSELECT FROM MENU BELOW:\n");
	printf("1.CREATE POLYNOMIAL\n2.DISPLAY POLYNOMIAL\n3.ADD POLYNOMIAL\n4.EVALUATE POLYNOMIAL\n5.EXIT\n");
	printf("Enter choice:");
	scanf("%d",&a);
		switch(a)
		{
			case 1:
				printf("Entering first polynomial\n");
				create1(Head1);
				printf("Entering second polynomial\n");
				create1(Head2);
				break;
			case 2:
				printf("\nFirst polynomial:");
				display(Head1);
				printf("\nSecond polynomial:");
				display(Head2);
				break;
			case 3:
				Add(Head1,Head2,Head3);
				printf("\nAddition is:");
				display(Head3);
				break;
			case 4:
				evaluation=evaluate(Head1);
    			printf("Evaluation of first polynomial is :%d\n",evaluation);
				break;
			default:
				printf("Exiting....\n");
		}
	}
	return 0;
}