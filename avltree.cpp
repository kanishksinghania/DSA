#include <iostream>

#include <cstdio>

#include <sstream>

#include <algorithm>

using namespace std;

struct node
{

    int data;

    struct node *left;

    struct node *right;

} *root;

class avltree
{

public:
    int height(node *);

    int diff(node *);

    node *rr_rotation(node *);

    node *ll_rotation(node *);

    node *lr_rotation(node *);

    node *rl_rotation(node *);

    node *balance(node *);

    node *insert(node *, int);

    void inorder(node *);

    void preorder(node *);

    void postorder(node *);

    avltree()
    {

        root = NULL;
    }
};

// insert function

node *avltree::insert(node *root, int value)
{

    if (root == NULL)
    {

        root = new node;

        root->data = value;

        root->left = root->right = NULL;

        return root;
    }

    else if (value < root->data)
    {

        root->left = insert(root->left, value);

        root = balance(root);
    }

    else if (value >= root->data)
    {

        root->right = insert(root->right, value);

        root = balance(root);
    }

    return root;
}

// diff function

int avltree::diff(node *temp)
{

    int l_height = height(temp->left);

    int r_height = height(temp->right);

    int b_factor = (l_height - r_height);

    return b_factor;
}

node *avltree::rr_rotation(node *parent)
{

    node *temp;

    temp = parent->right;

    parent->right = temp->left;

    temp->left = parent;

    return temp;
}

node *avltree::ll_rotation(node *parent)
{

    node *temp;

    temp = parent->left;

    parent->left = temp->right;

    temp->right = parent;

    return temp;
}

node *avltree::lr_rotation(node *parent)
{

    node *temp;

    temp = parent->left;

    parent->left = rr_rotation(temp);

    return ll_rotation(parent);
}

node *avltree::rl_rotation(node *parent)
{

    node *temp;

    temp = parent->right;

    parent->right = ll_rotation(temp);

    return rr_rotation(parent);
}

// inorder function

void avltree ::inorder(node *tree)
{

    if (tree == NULL)

        return;

    inorder(tree->left);

    cout << tree->data << " ";

    inorder(tree->right);
}

void avltree ::preorder(node *tree)
{

    if (tree == NULL)

        return;

    cout << tree->data << " ";

    preorder(tree->left);

    preorder(tree->right);
}

void avltree ::postorder(node *tree)
{

    if (tree == NULL)

        return;

    postorder(tree->left);

    postorder(tree->right);

    cout << tree->data << " ";
}

// balance function

node *avltree::balance(node *temp)
{

    int bal_factor = diff(temp);

    if (bal_factor > 1)
    {

        if (diff(temp->left) > 0)

            temp = ll_rotation(temp);

        else

            temp = lr_rotation(temp);
    }

    else if (bal_factor < -1)
    {

        if (diff(temp->right) > 0)

            temp = rl_rotation(temp);

        else

            temp = rr_rotation(temp);
    }

    return temp;
}

// height function

int avltree::height(node *temp)
{

    int h = 0;

    if (temp != NULL)
    {

        int l_height = height(temp->left);

        int r_height = height(temp->right);

        int max_height = max(l_height, r_height);

        h = max_height + 1;
    }

    return h;
}

int main()
{

    int item;

    char ch;

    avltree a;

    do
    {

        cout << "Enter Values to be Inserted : ";

        cin >> item;

        root = a.insert(root, item);

        cout << "Do You Want to Continue ";

        cin >> ch;

    } while (ch == 'y');

    cout << "Inorder Traversal : ";

    a.inorder(root);

    cout << "\n Preorder Traversal : ";

    a.preorder(root);

    cout << "\n Postorder Traversal : ";

    a.postorder(root);

    return 0;
}