#include<stdio.h>
#include<ctype.h>
#define max 100

char stack[max];
int top=-1;
int isfull() {
    if(top==max-1)
    return 1;
    else 
    return 0;
}

int isempty() {
    if(top==-1)
    return 1;
    else
    return 0;
}

void push(int elem) {
    if(isfull()==1) {
        printf("Stack is full.");
    }
    else {
        top++;
        stack[top]=elem;
    }
}

int pop() {
    int high;
    high=stack[top];
    top--;
    return high;
}

int operation(int a, int b, int c) {
    int answer;
    switch(c) {
        case'+':
        answer=a+b;
        break;
        case'-':
        answer=a-b;
        break;
        case'*':
        answer=a*b;
        break;
        case'/':
        answer=a/b;
        break;
        default:
        printf("Invalid operator!!");
        break;
        return answer;
        }
    }

void evaluation(char pe[max]) {
    int n;
    for(int i=0;pe[i]!='\0';i++) {
        if(isalpha(pe[i])!=0) {
            printf("Enter the value of %c: ",pe[i]);
            scanf("%d", &n);
            push(n);
        }
        else {
            int a,b,answer;
            a=pop();
            b=pop();
            answer=operation(a,b,pe[i]);
            push(answer);
        }

    }
    printf("Evaluation Result is: %d", stack[top]);
}
int main () {
    char s[max];
    printf("Enter the postfix expression: ");
    scanf("%s", &s);
    evaluation(s);
    return 0;
}