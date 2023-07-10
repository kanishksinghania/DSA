// graph using adjacency list
// assignment-5
// Aryan Bansal Panel F 26
#include <iostream>
#include <string.h>
using namespace std;

class gnode
{
    int id;
    string name;
    gnode *next;
    friend class graph;
};

class stack
{
    int s[20];
    int top = -1;

public:
    void push(int a)
    {
        top++;
        s[top] = a;
    }
    int pop()
    {
        int p;
        p = s[top];
        top--;
        return p;
    }
    int isempty()
    {
        if (top == -1)
        {
            return 1;
        }
        else
        {
            return 0;
        }
    }
};

class queue
{
    int q[20];
    int front = -1;
    int rear = -1;

public:
    int isempty()
    {
        if (front == rear)
        {
            return 1;
        }
        else
        {
            return 0;
        }
    }
    void enqueue(int a)
    {
        rear++;
        q[rear] = a;
    }
    int dequeue()
    {
        front++;
        return q[front];
    }
};
class graph
{
    gnode *head[20];
    int n;
    int visited[20];
    friend class stack;
    friend class queue;

public:
    graph()
    {
        cout << "Enter no. of vertices:";
        cin >> n;
        for (int i = 0; i < n; i++)
        {
            head[i] = new gnode();
            cout << "Enter ID of Head:";
            cin >> head[i]->id;
            cout << "Enter Name of Head:";
            cin >> head[i]->name;
        }
    }
    void create()
    {
        for (int i = 0; i < n; i++)
        {
            int p;
            cout << "Enter no. of adjacent vertices of node " << head[i]->name << " : ";
            cin >> p;
            gnode *temp;
            temp = head[i];
            for (int j = 0; j < p; j++)
            {
                gnode *curr;
                curr = new gnode();
                cout << "Enter id:";
                cin >> curr->id;
                cout << "Enter name:";
                cin >> curr->name;
                if (curr->id == temp->id)
                {
                    cout << "Cannot contain self loop!!" << endl;
                }
                else
                {
                    temp->next = curr;
                    temp = temp->next;
                    curr->next = NULL;
                }
            }
        }
    }
    void DFS();
    void DFS_rec(int a);
    void DFS_nonrec();
    void BFS();
};
void graph::DFS()
{
    int s;
    cout << endl
         << "Enter id of start vertex:";
    cin >> s;
    for (int i = 0; i < n; i++)
    {
        visited[i] = 0;
    }
    visited[s] = 1;
    DFS_rec(s);
}
void graph::DFS_rec(int a)
{
    cout << "[" << head[a]->id << "," << head[a]->name << "] ->";
    gnode *temp;
    temp = head[a]->next;
    while (temp != NULL)
    {
        if (visited[temp->id] == 0)
        {
            visited[temp->id] = 1;
            DFS_rec(temp->id);
        }
        temp = temp->next;
    }
}
void graph::BFS()
{
    int v;
    queue q;
    cout << endl
         << "Enter id of start vertex:";
    cin >> v;
    for (int i = 0; i < n; i++)
    {
        visited[i] = 0;
    }
    visited[v] = 1;
    q.enqueue(v);
    while (!q.isempty())
    {
        gnode *temp;
        v = q.dequeue();
        cout << "[" << head[v]->id << "," << head[v]->name << "] ->";
        temp = head[v]->next;
        while (temp != NULL)
        {
            if (visited[temp->id] == 0)
            {
                q.enqueue(temp->id);
                visited[temp->id] = 1;
            }
            temp = temp->next;
        }
    }
}
void graph::DFS_nonrec()
{
    int a;
    cout << endl
         << "Enter start vertex: ";
    cin >> a;
    stack s;
    for (int i = 0; i < n; i++)
    {
        visited[i] = 0;
    }
    s.push(a);
    visited[a] = 1;
    while (!s.isempty())
    {
        gnode *temp;
        a = s.pop();
        cout << "[" << head[a]->id << "," << head[a]->name << "] ->";
        temp = head[a]->next;
        while (temp != NULL)
        {
            if (visited[temp->id] == 0)
            {
                s.push(temp->id);
                visited[temp->id] = 1;
            }
            temp = temp->next;
        }
    }
}
int main()
{
    graph g1;
    g1.create();
    int ch;
    do
    {
        cout << endl
             << "1.Recursive DFS\n2.Non-recursive DFS\n3.BFS\n4.Exit" << endl;
        cout << "Enter choice: ";
        cin >> ch;
        switch (ch)
        {
        case 1:
            cout << endl
                 << "DFS traversal: ";
            g1.DFS();
            break;
        case 2:
            cout << endl
                 << "DFS non recursive: ";
            g1.DFS_nonrec();
            break;
        case 3:
            cout << endl
                 << "BFS traversal: ";
            g1.BFS();
            break;
        default:
            cout << "Exitng...";
        }
    } while (ch != 4);
    return 0;
}