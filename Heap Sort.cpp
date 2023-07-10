// Aryan Bansal
// Panel F
// Roll no 26
// Heap sort
#include <iostream>

#define MAX 20

using namespace std;

class Heap
{
private:
    int n;
    int marks[MAX];

public:
    void Accept();
    void Display();
    void Adjust(int a[MAX], int n, int i);
    void HeapSort();
};

void Heap::Accept()
{
    cout << "N: ";
    cin >> n;

    for (int i = 1; i <= n; i++)
    {
        cout << "Marks: ";
        cin >> marks[i];
    }
}

void Heap::Display()
{
    for (int i = 1; i <= n; i++)
    {
        cout << marks[i] << " ";
    }
    cout << endl;
}

void Heap::Adjust(int a[MAX], int n, int i)
{
    while ((2 * i) <= n)
    {
        int j = 2 * i;

        if (a[j + 1] > a[j] && j < n)
        {
            j++;
        }

        if (a[i] < a[j])
        {
            int temp = a[i];
            a[i] = a[j];
            a[j] = temp;
        }

        if (a[j] > a[i])
            break;

        i = j;
    }
}

void Heap::HeapSort()
{
    for (int i = n / 2; i >= 1; i--)
    {
        Adjust(marks, n, i);
    }

    while (n > 1)
    {
        int temp = marks[1];
        marks[1] = marks[n];
        marks[n] = temp;

        cout << marks[n] << " ";

        n--;
        Adjust(marks, n, 1);
    }
    cout << marks[n] << endl;
}

int main()
{
    Heap h;
    h.Accept();
    h.Display();
    h.HeapSort();

    return 0;
}