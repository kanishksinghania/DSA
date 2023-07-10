#include <iostream>
using namespace std;

class node
{
	char data;
	node *left,*right;
	friend class binarytree;
	friend class stack;
};
class binarytree
{
	node *root;
public:
	void create_tree();
	void inorder(node *);
	void preorder(node *);
	void postorder(node *);
	void create();
	void create_r(node *root);
	void inorder_nonrec(node *root);
	void preorder_nonrec(node* root);
	void postorder_nonrec(node* root);
	void display();
	
};

class stack
{
	node* st[20];
	int top=-1;
	
	public:
		void push(node* t)
		{
			top++;
			st[top]=t;
		}
		node* pop()
		{
			node* t;
			t=st[top];
			top--;
			return t;
		}
		int isempty()
		{
			if(top==-1)
			{return 1;}
			else
			{return 0;}
		}
		friend class binarytree;
};

void binarytree::create_tree() //Iterative Method
{
	char ch;
	int a;
	root=new node();
	cout<<"Enter data:";
	cin>>root->data;
	root->left=root->right=NULL;
	a=1;
	while(a==1)
	{
		node *curr,*temp;
		curr=new node();
		temp=root;
		cout<<"Enter data:";
		cin>>curr->data;
		curr->left=curr->right=NULL;
		int flag=1;
		while(flag==1)
		{
			cout<<"Where to attach data?(L/R) of "<<temp->data<<"?";
			cin>>ch;
			if(ch=='l' || ch=='L'){
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
		cout<<"Press 1 to continue and 0 to end:";
		cin>>a;
	}
}

void binarytree::create() // Recursive
{
	root=new node();
	cout<<"Enter the data:";
	cin>>root->data;
	root->left=root->right=NULL;
	create_r(root);
}
void binarytree::create_r(node *temp)
{
	char ch1,ch2;
	cout<<"Do you want to attach to left of "<<temp->data<<"[y/n]:";
	cin>>ch1;
	if(ch1=='y'|| ch1=='Y')
	{
		node *curr;
		curr=new node();
		cout<<"Enter data:";
		cin>>curr->data;
		temp->left=curr;
		create_r(curr);
	}
	cout<<"Do you want to attach to right of "<<temp->data<<"[y/n]:";
	cin>>ch2;
	if(ch2=='y'|| ch2=='Y')
	{
		node *curr;
		curr=new node();
		cout<<"Enter data:";
		cin>>curr->data;
		temp->right=curr;
		create_r(curr);
	}
}
// Recursive Traversals
void binarytree::inorder(node *root)
{
	if(root!=NULL)
	{
		inorder(root->left);
		cout<<root->data<<"->";
		inorder(root->right);
	}
}

void binarytree::preorder(node *root)
{
	if(root!=NULL)
	{
		cout<<root->data<<"->";
		preorder(root->left);
		preorder(root->right);
	}
}

void binarytree::postorder(node *root)
{
	if(root!=NULL)
	{
		postorder(root->left);
		postorder(root->right);
		cout<<root->data<<"->";
	}
}

// Iterative Traversals

void binarytree::inorder_nonrec(node* root)
{
	stack s;
	node *temp;
	temp=root;
	while(1)
	{
		while(temp!=NULL)
		{
			s.push(temp);
			temp=temp->left;
		}
		if(s.isempty()==1)
			{break;}
		temp=s.pop();
		cout<<temp->data<<"->";
		temp=temp->right;
	}
}

void binarytree::preorder_nonrec(node* root)
{
	stack s;
	node *temp;
	temp=root;
	while(1)
	{
		while(temp!=NULL)
		{
			cout<<temp->data<<"->";
			s.push(temp);
			temp=temp->left;
		}
		if(s.isempty()==1)
			{break;}
		temp=s.pop();
		temp=temp->right;
	}
}

void binarytree::postorder_nonrec(node* root)
{
	stack s;
	node *temp;
	temp=root;
	while(1)
	{
		while(temp!=NULL)
		{
			s.push(temp);
			temp=temp->left;
		}
		
		if(s.st[s.top]->right==NULL)
		{
			temp=s.pop();
			cout<<temp->data<<"->";
		}
		while(s.isempty()==0 && s.st[s.top]->right==temp)
		{
			temp=s.pop();
			cout<<temp->data<<"->";
		}
		if(s.isempty()==1)
			break;
		temp=s.st[s.top]->right;
	}
}

void binarytree::display() {
	int n;
	cout<<"What do you want to perform?"<<endl;
	while(1) {
        cout<<endl<<"1.Non-recursive tree creation\n2.Recursive tree creation\n3.Recursive In-order\n4.Recursive Pre-order\n5.Recursive Post-order\n6.Non-Recursive In-order\n7.Non-Recursive Pre-order\n8.Non-Recursive Post-order\n9.Exit\n"<<endl;
        cout<<"Enter choice:";
        cin>>n;
	switch(n)
	    {
		
		case 1:
			create_tree();
			break;

		case 2:
			create();
			break;

		case 3:
			cout<<"In-order traversal:";
			inorder(root);
			cout<<endl;
		    	break;
		case 4:
			cout<<"Pre-order traversal:";
			preorder(root);
			cout<<endl;
		    	break;
		case 5:
			cout<<"Post-order traversal:";
			postorder(root);
			cout<<endl;
		    	break;

		case 6:
		cout<<"In-order non-recursive traversal:";
		inorder_nonrec(root);
		cout<<endl;
		break;

		case 7:
			cout<<"Pre-order non-recursive traversal:";
			preorder_nonrec(root);
			cout<<endl;
			break;

		case 8:
			cout<<"Post-order non-recursive traversal:";
			postorder_nonrec(root);
			cout<<endl;
			break;

		default:
		    cout<<"YOU CHOSE TO EXIT!!"<<endl;
		    exit(0);
    		}
    
    	}

}
int main() {
binarytree tree1;
tree1.display();
}