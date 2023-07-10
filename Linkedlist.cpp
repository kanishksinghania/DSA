#include<iostream>
using namespace std;

class node{
    public: 
    int data;
    node* next;

    node(int value) {
        data=value;
        next=NULL;
    }
};

void insert(node* &head,int value) {

    node* n= new node(value);

    if(head==NULL) {
        head=n;
        return;
    }
    node* temp;
    temp==head;
    while(temp->next!=NULL){
        temp=temp->next;
    }
    temp->next=n;
}

void display(node*head) {
    node* temp=head;
    while(temp!=NULL) {
        cout<<temp->data<<" ";
        temp=temp->next;
    }
    cout<<endl;
    }

int main() {

    node* head=NULL;
    insert(head,1);
    insert(head,2);
    insert(head,3);
    display(head);
}