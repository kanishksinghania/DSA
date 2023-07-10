#include<string.h>
#include<ctype.h>
#define maxsize 100
char stack[maxsize];
char s[maxsize][maxsize];
int top=-1;
int top1=-1;
int isfull()
{
if(top==maxsize-1)
return 1;
else
return 0;
}

void push(char item)
{
if(!isfull())
{
top=top+1;
stack[top]=item;
}
}

void push1(char str[maxsize])
{
/*if(isfull()== 1)
{
printf("\nStack is full !");
}
else*/

strcpy(s[++top1],str);

}

int isempty()
{
if(top==-1)
return 1;
else
return 0;
}

char pop()
{
char temp;
if(! isempty())
{
temp=stack[top];
top=top-1;
return(temp);
}
}

void pop1(char str[maxsize])
{
 /*if(isempty()== 1)
 {
  printf("\n Stack is empty !");
 }
 else//*/
 
  strcpy(str,s[top1]);
  top1--;
 
}
 
int isp(char op)
{
	if(op=='+' || op=='-')
		return 1;
	else if(op=='*'|| op=='/')
		return 2;
	else if(op=='^')
		return 3;
	else if(op=='(')
		return 0;
	else
		return -1;
}
int icp(char op)
{
	if(op=='+' || op=='-')
		return 1;
	else if(op=='*'|| op=='/')
		return 2;
	else if(op=='^')
		return 4;
	else if(op=='(')
		return 4;
	else
		return -1;
}

void in_post(char inexp[10])
{
	int i,k;
	char postfix[maxsize];
	i=k=0;
	char tkn;
	tkn=inexp[i];
	while(tkn!='\0')
	{
		if(isalpha(tkn)!=0)
		{
		    postfix[k]=inexp[i];
		    k++;
		}
		else
		{
		   if (tkn=='(')
		   {
		      push('(');
		   }
		else
		{
		   if(tkn==')')
		    {
			while((tkn=pop())!='(')
			{
			  postfix[k]=tkn;
			  k++;
			}
		    }
		    
		  else
		   {
		      while(top!=-1 && isp(stack[top])>=icp(tkn))
			{
			  postfix[k]=pop();
			  k++;
			}
			push(tkn);
            	    }
            	 }
		}
	    i++;
	    tkn=inexp[i];
	}
	while(top!=-1)
	{
	  postfix[k]=pop();
	  k++;
	}
	printf("Postfix expr = %s\n",postfix);
}

void postinfx(char post[maxsize])
{
 int i,k;

 char s1[maxsize], s2[maxsize], s3[maxsize], temp[maxsize], inf[maxsize];
 for(i=0;post[i]!='\0';i++)
 {
 s1[0]=post[i];
 s1[1]='\0';
 if(isalpha(post[i])!=0)
 push1(s1);
 else
 {
 pop1(s2);
 pop1(s3);
 strcpy(inf,"(");
 printf("%s", inf);
 strcat(inf,s3);
 strcat(inf,s1);
 strcat(inf,s2);
 strcat(inf,")");
  printf("%s",inf);
 push1(inf);
 }
 }
 pop1(inf);
 int len=strlen(inf);
 inf[len]='\0';
 printf("\nThe infix expression is :");
 printf("\n%s",inf);
}

void postpre(char post[maxsize])
{
	char s1[maxsize],s2[maxsize],s3[maxsize],pre[maxsize];
	pre[0]='\0';
	for ( int i=0;post[i]!='\0';i++)
	{
	   s1[0]=post[i];
	   s1[1]='\0';
	   if(isalpha(post[i])!=0)
	   {
		   push1(s1);
	   }
	   else
	   {
		   pop1(s2);
		   pop1(s3);
 
		   strcpy(pre,s1);
		   strcat(pre,s3);
		   strcat(pre,s2);
 
		   push1(pre);
 
 
	   }
	}
	pop1(pre);
 
	printf("\n The prefix expr is:\n");
	printf("%s",pre);
}

int main()
{
int choice;
char inf[maxsize],pos[maxsize];
printf("Enter 1)Infix to Postfix \n2)Postfix to Infix \n 3)Postfix to Prefix \n");
scanf("%d",&choice);
switch(choice)
{
case 1:
printf("Enter Infix Expression : ");
scanf("%s",inf);
in_post(inf);
printf("\n");
break;

case 2:
printf("Enter Postfix Expression : ");
scanf("%s",pos);
postinfx(pos);
printf("\n");
break;

case 3:
printf("Enter Postfix Expression : ");
scanf("%s",pos);
postpre(pos);
printf("\n");
break;
}

return 0;
}

//OUTPUT 1
/*Enter 1)Infix to Postfix 
2)Postfix to Infix       
 3)Postfix to Prefix     
1
Enter Infix Expression : A+B*C
Postfix expr = ABC*+
*/
//OUTPUT 2
/*Enter 1)Infix to Postfix 
2)Postfix to Infix       
 3)Postfix to Prefix
2
Enter Postfix Expression : ABC*+
((B*C)((A+(B*C))
The infix expression is :
(A+(B*C))
*/
//OUTPUT 3
/*Enter 1)Infix to Postfix 
2)Postfix to Infix       
 3)Postfix to Prefix     
3
Enter Postfix Expression : ABC*+

 The prefix expr is:
+A*BC*/