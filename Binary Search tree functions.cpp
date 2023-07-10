#include<iostream>
#include<string.h>
using namespace std;

//Node class
class node
{
	char word[20];
	char mean[20];
	node *left,*right;
	friend class BST;	
};

//Queue class for BFS
class Queue
{
	node *Q[10];
	int front=-1;
	int rear=-1;
	
	public:
		void insert(node *t)
		{
			rear++;
			Q[rear]=t;
		}
		node* Delete()
		{
			node *t;
			front++;
			t=Q[front];
			return t;
		}
		int isempty()
		{
			if(rear==front)
			{return 1;}
			else
			{return 0;}
		}
		friend class BST;
};

//main bst class for tree creation
class BST
{
	node *root;
	public:
		void create_BST();
		void inorder(node *root);
		void display_tree();
		void levelwise();
		node* copy_tree(node *root);
		void display_copy(BST t);
		void mirror_image(node *root);
		void mirror_display();
};

//Create tree function
void BST::create_BST()
{
	node *temp;
	root=new node();
	cout<<"Enter root word:";
	cin>>root->word;
	cout<<"Enter root meaning:";
	cin>>root->mean;
	root->left=root->right=NULL;
	char ch;
	do
	{
		temp=root;
		node *curr;
		curr=new node();
		cout<<"Enter curr word:";
		cin>>curr->word;
		cout<<"Enter curr meaning:";
		cin>>curr->mean;
		int flag=1;
		curr->left=curr->right=NULL;
		while(flag==1)
		{
			if(strcmp(curr->word,temp->word)<0)
			{
				if(temp->left==NULL)
				{
					temp->left=curr;
					flag=0;
					break;
				}
				else
				{
					temp=temp->left;
					flag=1;
				}
			}
			else
			{
				if(temp->right==NULL)
				{
					temp->right=curr;
					flag=0;
					break;
				}
				else
				{
					temp=temp->right;
					flag=1;
				}
			}
		}
		cout<<"Do you want to add more node?[Y/N]";
		cin>>ch;
	}while(ch=='y'||ch=='Y');
}

//Inorder traversal
void BST::inorder(node *root)
{
	if(root!=NULL)
	{
		inorder(root->left);
		cout<<"["<<root->word<<","<<root->mean<<"]"<<"->";
		inorder(root->right);
	}
}

//display function
void BST::display_tree()
{
	cout<<"Inorder traversal:";
	inorder(root);
}

//Levelwise traversal
void BST::levelwise()
{
	Queue Q;
	node *temp;
	temp=root;
	Q.insert(temp);
	while(Q.isempty()==0)
	{
		temp=Q.Delete();
		cout<<"["<<temp->word<<","<<temp->mean<<"]"<<"->";
		if(temp->left!=NULL)
		{
			Q.insert(temp->left);
		}
		if(temp->right!=NULL)
		{
			Q.insert(temp->right);
		}
	}
}

//copy tree function recursive
node* BST::copy_tree(node *root)
{
	node* temp;
	temp=NULL;
	if(root!=NULL)
	{
		temp=new node();
		strcpy(temp->word,root->word);
		strcpy(temp->mean,root->mean);
		temp->left=copy_tree(root->left);
		temp->right=copy_tree(root->right);
	}
	return temp;
}

//Display copy tree function
void BST:: display_copy(BST t)
{
	root=copy_tree(t.root);
	inorder(root);
}

//Mirror image function
void BST::mirror_image(node *root)
{
	node *temp;
	temp=root->left;
	root->left=root->right;
	root->right=temp;
	free(temp);
	if(root->left!=NULL)
	{mirror_image(root->left);}
	else if(root->right!=NULL)
	{mirror_image(root->right);}
}

//Display mirror image function
void BST::mirror_display()
{
	mirror_image(root);
	inorder(root);
}

//Main function
int main()
{
	BST tree,ctree;
    int ch;
    while(ch!=6)
    {
        cout<<endl<<"MENU"<<endl;
        cout<<"1.CREATE BST\n2.DISPLAY BST\n3.LEVELWISE TRAVERSAL\n4.COPY TREE\n5.MIRROR IMAGE\n6.EXIT"<<endl;
        cout<<endl<<"Enter choice:";
        cin>>ch;
        switch(ch)
        {
            case 1:
                tree.create_BST();
                cout<<"Tree created!!"<<endl;
                break;
            case 2:
                cout<<"Inorder trvaersal:";
                tree.display_tree();
                cout<<endl;
                break;
            case 3:
                cout<<endl<<"LEVELWISE TRAVERSAL"<<endl;
	            tree.levelwise();
                cout<<endl;
                break;
            case 4:
                cout<<endl<<"COPIED TREE"<<endl;
	            ctree.display_copy(tree);
                cout<<endl;
                break;
            case 5:
                cout<<endl<<"MIRROR IMAGE"<<endl;
	            tree.mirror_display();
                cout<<endl;
                break;
            default:
                cout<<"EXITING...";
        }   
    }
	return 0;
}	