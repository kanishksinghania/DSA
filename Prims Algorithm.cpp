#include <iostream>
using namespace std;

class graph
{
    int n;
    int edges;
    int cost[20][20];

public:
    void create_graph();
    void display_graph();
    void prims();
};
void graph::create_graph()
{
    cout << "Enter number of vertices:";
    cin >> n;
    cout << "Enter number of edges:";
    cin >> edges;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cost[i][j] = 999;
        }
    }
    for (int i = 0; i < edges; i++)
    {
        int s, d, c;
        cout << "Enter source vertex:";
        cin >> s;
        cout << "Enter destination vertex:";
        cin >> d;
        cout << "Enter cost:";
        cin >> c;
        cost[s][d] = c;
        cost[d][s] = c;
    }
}

void graph::display_graph()
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cout << cost[i][j] << "\t";
        }
        cout << endl;
    }
}

void graph::prims()
{
    int nearest[20];
    int mincost = 0;
    int T[20][20];
    int x = 0;
    int s;
    int m;
    cout << "Enter start vertex:";
    cin >> s;
    nearest[s] = -1;
    for (int i = 0; i < n; i++)
    {
        if (i != s)
        {
            nearest[i] = s;
        }
    }

    for (int i = 1; i < n; i++)
    {
        int min1 = 9999;
        for (int j = 0; j < n; j++)
        {
            if (nearest[j] != -1 && min1 > cost[j][nearest[j]])
            {
                min1 = cost[j][nearest[j]];
                m = j;
            }
        }
        mincost = mincost + cost[m][nearest[m]];
        T[x][0] = m;
        T[x][1] = nearest[m];
        T[x][2] = min1;
        x++;
        nearest[m] = -1;
        for (int k = 0; k < n; k++)
        {
            if (nearest[k] != -1 && cost[m][k] < cost[k][nearest[k]])
            {
                nearest[k] = m;
            }
        }
    }
    cout << "Mincost is:" << mincost;
    cout << endl;
    cout << "Minimum spanning tree:\t";
    cout << "V1\t"
         << "V2\t"
         << "Cost" << endl;
    for (int p = 0; p < x; p++)
    {
        for (int q = 0; q < 3; q++)
        {
            cout << T[p][q] << "\t";
        }
        cout << endl;
    }
}

int main()
{
    graph g;
    g.create_graph();
    g.display_graph();
    g.prims();
    return 0;
}
