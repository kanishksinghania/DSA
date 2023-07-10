#include <stdio.h>
#include <stdlib.h>
#define max 10

int rear;
int front;
int queue[max];

void insert(int x,int rear,int front,int queue[max]) {
    if(rear==max-1) {
        printf("Queue is full.");
    }
    else {
        queue[rear]=x;
        rear++;
    }
}

void deletion(int x,int rear,int front,int queue[max]) {
    if(rear==-1 && front==-1) {
        printf("Queue is empty.");
    }
    else {
        x=queue[front];
        front++;
    }
}

void peekfront(int rear,int front,int queue[max]) {
    if (front==-1 && rear==-1)
        printf("Queue is empty!\n");
    else
        printf("%d",queue[front]);
}

void peekrear(int rear,int front,int queue[max]) {
    if (front==-1 && rear==-1)
        printf("Queue is empty!\n");
    else
        printf("%d",queue[rear]);
}

void display(int rear,int front,int queue[max]) {
    if (front==-1 && rear==-1)
        printf("Queue is empty!\n");
    for (int i=front;i<=rear;i++)
        printf("%d\t",queue[i]);
}

int main()
{
    int queue[max];
    int front=-1;
    int rear=-1;
    int t=0;
    while(t==0)
    {
        printf("1. insert\n2. deletion\n3. peekfront\n4. peekrear\n5. diplay\n");
        int c;
        printf("\nEnter choice:");
        scanf("%d",&c);
        
        switch (c)
        {
            case 1:
            printf("\nEnter Element : ");
            int elem;
            scanf("%d",&elem);
            insert(elem,rear,front,queue);
            break;
            
            case 2:
            deletion(elem,rear,front,queue);
            break;
            
            case 3:
            peekfront(rear,front,queue);
            break;
            
            case 4:
            peekrear(rear,front,queue);
            break;

            case 5:
            display(rear,front,queue);
            break;
            
            default:
            printf("\nInvalid Choice");
            exit(0);
        }
        printf("\nEnter 0 to continue 1 to exit:");
        scanf("%d",&t);
    }
    printf("Program Done!!");
    return 0;
}

