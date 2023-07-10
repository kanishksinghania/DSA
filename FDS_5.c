//Linked list creation and traversal
#include<stdio.h>
#include<stdlib.h>
#define max 100
struct Node
{
    int prn;
    char name[max];
    struct Node *next;
};

//creation function
void create(struct Node*H)
{
    char ch;
    struct Node *last,*curr;
    last=H;
    do
    {
        curr=(struct Node *)malloc(sizeof(struct Node));
        printf("Enter Name:");
        scanf("%s",curr->name);
        printf("Enter PRN:");
        scanf("%d",&curr->prn);
        curr->next=NULL;
        last->next=curr;
        last=curr;
        printf("Continue? 'Y' for Yes and 'N' for No.\n");
        scanf(" %c",&ch);
    }while (ch=='Y' || ch=='y');
}

//display function
void display(struct Node *H)
{
    struct Node *curr;
    if (H->next==NULL)
    {printf("Linked list is empty!!\n");}
    else
    {
        curr=H->next;
        int cnt=0;
        while(curr  !=NULL)
        {
            cnt++;
            printf("Element no: %d\n",cnt);
            printf("PRN:%d\n",curr->prn);
            printf("Name:%s\n",curr->name);
            curr=curr->next;
        }
    }
}
//length calc function
int length(struct Node *H)
{
    struct Node *curr;
    curr=H->next;
    int cnt=0;
    while(curr !=NULL)
    {
        cnt++;
        curr=curr->next;
    }
    return cnt;
}
//insert at position function
void insert_by_pos(struct Node *H,int pos,int length)
{
    struct Node *curr,*present;
    curr=H;
    int i=1;
    present=(struct Node *)malloc(sizeof(struct Node));
    if(pos>length+1)
    {printf("NO data insertion!\n");}
    else
        {
            while(curr!=NULL && i<pos)
            {
                i++;
                curr=curr->next;
            }
           
            printf("PRN:");
            scanf("%d",&present->prn);
            printf("Name:");
            scanf("%s",present->name);
            present->next=NULL;
            present->next=curr->next;
            curr->next=present;
            if (pos==1)
            printf("New President added!\n");
            else if(pos>1 && pos<length)
            printf("New mwmber added!\n");
            else if(pos==length+1)
            printf("New secretry added!!\n");
        }
}
//delete at position function
void delete_node(struct Node *H,int pos,int length)
{
    struct Node *curr,*prev,*temp;
    curr=H;
    int i=1;
    if (pos==length)
    {printf("Cant delete!\n");}
    else
    {
    while(i<=pos && curr!=NULL)
    {
        i++;
        prev=curr;
        curr=curr->next;
    }
    temp=curr;
    prev->next=curr->next;
    curr->next=NULL;
    free(curr);
    if (pos==(length-1))
    {printf("Secretary deleted!\n");}
    else if(pos==1)
    {printf("President deleted!\n");}
    else
    {printf("Member deleted!\n");}
    }
}
//reverse function
void reverse(struct Node *H)
{
    struct Node *curr,*prev,*future;
    prev=NULL;
    curr=H->next;
    while(curr!=NULL)
    {
        future=curr->next;
        curr->next=prev;
        prev=curr;
        curr=future;
    }
    H->next=prev;
}
//sort function
void sort_l(struct Node *H)
{
    struct Node *prev,*curr,*temp;
    int len=length(H);
    for(int i=1;i<len-1;i++)
    {
        prev=H;
        curr=H->next;
        for(int j=0;j<len-i;j++)
        {
            temp=curr->next;
            if(curr->prn > temp->prn)
            {
                prev->next=temp;
                curr->next=temp->next;
                temp->next=curr;
                prev=temp;
            }
            else
            {
                prev=curr;
                curr=curr->next;
            }
        }
    }
}
//Merge function
void merge(struct Node *H1, struct Node *H2)
{
	struct Node *temp, *curr1, *curr2;
	curr1=H1->next;
	curr2=H2->next;
	int flag;
	if(curr1->prn<curr2->prn)
	{
		temp=H1;
		flag=1;
	}
	else
	{
		temp=H2;
		flag=0;
	}
	while(curr1!=NULL && curr2!=NULL)
	{
		if (curr1->prn < curr2->prn)
		{
			temp->next=curr1;
			temp=curr1;
			curr1=curr1->next;
		}
		else
		{
			temp->next=curr2;
			temp=curr2;
			curr2=curr2->next;
		}
	}
	if(curr1==NULL) temp->next=curr2;
	if(curr2==NULL) temp->next=curr1;
	if(flag == 1) display(H1);
	else display(H2);
}

int main()
{
    struct Node *head,*head2;
    head=(struct Node *)malloc(sizeof(struct Node));
    head->next=NULL;
    create(head);
    display(head);
    while(1)
    {
    int ch;
    int len,pos,pos2;
    printf("1.Length\n2.Insert\n3.Delete\n4.Reverse\n5.Sort\n6.Merge\n7.Exit\n");
    printf("Enter choice:");
    scanf("%d",&ch);
    switch(ch)
    {
        case 1:
            len=length(head);
            printf("The length is %d\n",len);
            break;
        case 2:
            len=length(head);
            printf("Enter position number:");
            scanf("%d",&pos);
            insert_by_pos(head,pos,len);
            display(head);
            printf("Insertion done!!\n");
            break;
        case 3:
            len=length(head);
            printf("Enter position to be deleted:");
            scanf("%d",&pos2);
            delete_node(head,pos2,len);
            display(head);
            break;
        case 4:
            reverse(head);
            display(head);
            printf("Linked list reversed!!\n");
            break;
        case 5:
            sort_l(head);
            display(head);
            printf("Sorting done!!\n");
            break;
        case 6:
            head2=(struct Node *)malloc(sizeof(struct Node));
            head2->next=NULL;
            create(head2);
            display(head2);
            printf("Second linked list created!!\n");
            printf("Now merging!!\n");
            merge(head,head2);
            break;
        case 7:
            printf("exiting from program!!\n");
            exit(0);
        default:
            exit(0);
    }
    }
    return 0;
}

//OUTPUT
/*Enter Name:Kanishk
Enter PRN:1032211295
Continue? 'Y' for Yes and 'N' for No.
Y
Enter Name:Aryan
Enter PRN:1032211329
Continue? 'Y' for Yes and 'N' for No.
Y
Enter Name:Pulkit
Enter PRN:1032211319
Continue? 'Y' for Yes and 'N' for No.
N
Element no: 1
PRN:1032211295
Name:Kanishk
Element no: 2
PRN:1032211329
Name:Aryan
Element no: 3
PRN:1032211319
Name:Pulkit
1.Length
2.Insert
3.Delete
4.Reverse
5.Sort
6.Merge
7.Exit
Enter choice:1
The length is 3
1.Length
2.Insert
3.Delete
4.Reverse
5.Sort
6.Merge
7.Exit
Enter choice:2
Enter position number:4
PRN:1032211699
Name:Singhania
New secretry added!!
Element no: 1
PRN:1032211295
Name:Kanishk
Element no: 2
PRN:1032211329
Name:Aryan
Element no: 3
PRN:1032211319
Name:Pulkit
Element no: 4
PRN:1032211699
Name:Singhania
Insertion done!!
1.Length
2.Insert
3.Delete
4.Reverse
5.Sort
6.Merge
7.Exit
Enter choice:3
Enter position to be deleted:4
Cant delete!
Element no: 1
PRN:1032211295
Name:Kanishk
Element no: 2
PRN:1032211329
Name:Aryan
Element no: 3
PRN:1032211319
Name:Pulkit
Element no: 4
PRN:1032211699
Name:Singhania
1.Length
2.Insert
3.Delete
4.Reverse
5.Sort
6.Merge
7.Exit
Enter choice:4
Element no: 1
PRN:1032211699
Name:Singhania
Element no: 2
PRN:1032211319
Name:Pulkit
Element no: 3
PRN:1032211329
Name:Aryan
Element no: 4
PRN:1032211295
Name:Kanishk
Linked list reversed!!
1.Length
2.Insert
3.Delete
4.Reverse
5.Sort
6.Merge
7.Exit
Enter choice:5
Element no: 1
PRN:1032211319
Name:Pulkit
Element no: 2
PRN:1032211295
Name:Kanishk
Element no: 3
PRN:1032211329
Name:Aryan
Element no: 4
PRN:1032211699
Name:Singhania
Sorting done!!
1.Length
2.Insert
3.Delete
4.Reverse
5.Sort
6.Merge
7.Exit
Enter choice:6
Enter Name:Manish 
Enter PRN:1032211278
Continue? 'Y' for Yes and 'N' for No.
N
Element no: 1
PRN:1032211278
Name:Manish
Second linked list created!!
Now merging!!
Element no: 1
PRN:1032211278
Name:Manish
Element no: 2
PRN:1032211319
Name:Pulkit
Element no: 3
PRN:1032211295
Name:Kanishk
Element no: 4
PRN:1032211329
Name:Aryan
Element no: 5
PRN:1032211699
Name:Singhania
1.Length
2.Insert
3.Delete
4.Reverse
5.Sort
6.Merge
7.Exit
Enter choice:7
exiting from program!!
*/