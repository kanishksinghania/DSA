#include<iostream>
#include <string.h>
using namespace std;

class node
{
    char data;
    node *left, *right;
    int lbit, rbit;
    friend class TBT;
};


class TBT
{
    node *root;
    node *head;

public:
    void Create_tbt();
    void inorder_TBT();
    node *inorder_succ(node *temp);
    void preorder_TBT();
};

void TBT::Create_tbt()
{
    head = new node();
    root = new node();
    cout << "Enter root data:";
    cin >> root->data;
    head->left = root;
    head->right = head;
    head->lbit = head->rbit = 0;
    root->lbit = root->rbit = 1;
    root->left = root->right = head;
    char choice;
    do
    {
        node *temp, *curr;
        temp = root;
        curr = new node();
        cout << "Enter curr->data:";
        cin >> curr->data;
        int flag = 1;
        while (flag == 1)
        {
            char ch;
            cout << "Where to attach[L/R] of " << temp->data << "??:";
            cin >> ch;
            if (ch == 'L' || ch == 'l')
            {
                if (temp->lbit == 1)
                {
                    curr->left = temp->left;
                    temp->left = curr;
                    curr->right = temp;
                    curr->lbit = curr->rbit = 1;
                    temp->lbit = 0;
                    flag = 0;
                    break;
                }
                else
                {
                    temp = temp->left;
                    flag = 1;
                }
            }
            else if (ch == 'R' || ch == 'r')
            {
                if (temp->rbit == 1)
                {
                    curr->right = temp->right;
                    temp->right = curr;
                    curr->left = temp;
                    curr->lbit = curr->rbit = 1;
                    temp->rbit = 0;
                    flag = 0;
                    break;
                }
                else
                {
                    temp = temp->right;
                    flag = 1;
                }
            }
        }
        cout << "Want to continue?[Y/N]: ";
        cin >> choice;
    } while (choice == 'Y' || choice == 'y');
}
node *TBT::inorder_succ(node *temp)
{
    node *temp1;
    temp1 = temp->right;
    if (temp->rbit == 0)
    {
        while (temp1->lbit == 0)
        {
            temp1 = temp1->left;
        }
    }
    return temp1;
}

void TBT::inorder_TBT()
{
    node *temp;
    temp = head;
    while (1)
    {
        temp = inorder_succ(temp);
        if (temp != head)
        {
            cout << temp->data << " -> ";
        }
        else
        {
            break;
        }
    }
}
void TBT::preorder_TBT()
{
    node *temp;
    temp = head->left;
    while (temp != head)
    {
        cout << temp->data << " -> ";
        while (temp->lbit != 1)
        {
            temp = temp->left;
            cout << temp->data << " -> ";
        }
        while (temp->rbit == 1)
        {
            temp = temp->right;
        }
        temp = temp->right;
    }
}

int main()
{
    TBT tree1;
    tree1.Create_tbt();
    cout << endl
         << "Inorder traversal: ";
    tree1.inorder_TBT();
    cout << endl
         << "Preorder traversal: ";
    tree1.preorder_TBT();
    return 0;
}