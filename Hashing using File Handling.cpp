#include <iostream>
#include <fstream>
#include <string.h>

using namespace std;

class employee
{
    int eid;
    char name[20];
    int sal;
    friend class hashing;
};

class hashing
{
    
public:
    // constructor
    hashing()
    {
        employee e;
        fstream file("emp_aryan2.txt", ios::out | ios::binary);
        file.seekp(0, ios::end);
        for (int i = 0; i < 10; i++)
        {
            e.eid = -1;
            strcpy(e.name, "----");
            e.sal = 0;
            file.write((char *)&e, sizeof(e));
        }
        file.close();
    }
    // dsiplay function
    void display()
    {
        employee temp;
        fstream file("emp_aryan2.txt", ios::in | ios::binary);
        while (file.read((char *)&temp, sizeof(temp)))
        {
            cout << temp.eid << "  " << temp.name << "  " << temp.sal << endl;
        }
    }

    // linear probing without replacement
    void linearprobwor()
    {
        employee e;
        fstream file("emp_aryan2.txt", ios::in | ios::out | ios::binary);
        char ch;
        do
        {
            int loc;
            employee temp;
            cout << "Enter empid:";
            cin >> e.eid;
            cout << "Enter name:";
            cin >> e.name;
            cout << "Enter salary:";
            cin >> e.sal;
            loc = e.eid % 10;
            file.seekg(loc * sizeof(e), ios::beg);
            file.read((char *)&temp, sizeof(temp));
            if (temp.eid == -1)
            {
                file.seekp(loc * (sizeof(e)), ios::beg);
                file.write((char *)&e, sizeof(e));
            }
            else
            {
                for (int i = loc + 1; i != loc; i = (i + 1) % 10)
                {
                    file.seekg(i * sizeof(e), ios::beg);
                    file.read((char *)&temp, sizeof(temp));
                    if (temp.eid == -1)
                    {
                        file.seekp(i * (sizeof(e)), ios::beg);
                        file.write((char *)&e, sizeof(e));
                        break;
                    }
                    if (i == loc)
                    {
                        cout << "hashtable full!!!";
                    }
                }
            }
            cout << "Do you want to continue??[y/n]";
            cin >> ch;
        } while (ch == 'y');
        file.close();
        display();
    }

    // linear probing with replacement
    void linearprobwr()
    {
        employee e;
        char ch;
        fstream file("emp_aryan2.txt", ios::in | ios::out | ios::binary);
        do
        {
            int loc;
            employee temp, temp1;
            cout << "Enter empid:";
            cin >> e.eid;
            cout << "Enter name:";
            cin >> e.name;
            cout << "Enter salary:";
            cin >> e.sal;
            loc = e.eid % 10;
            file.seekg(loc * sizeof(e), ios::beg);
            file.read((char *)&temp, sizeof(temp));
            if (temp.eid == -1)
            {
                file.seekp(loc * (sizeof(e)), ios::beg);
                file.write((char *)&e, sizeof(e));
            }
            else
            {
                int newloc;
                newloc = (temp.eid) % 10;
                if (newloc == loc)
                {
                    for (int i = loc + 1; i != loc; i = (i + 1) % 10)
                    {
                        file.seekg(i * sizeof(e), ios::beg);
                        file.read((char *)&temp, sizeof(temp));
                        if (temp.eid == -1)
                        {
                            file.seekp(i * (sizeof(e)), ios::beg);
                            file.write((char *)&e, sizeof(e));
                            break;
                        }
                        if (i == loc)
                        {
                            cout << "hashtable full!!!";
                        }
                    }
                }
                // agar newloc!=loc
                else
                {
                    file.seekp(loc * sizeof(e), ios::beg);
                    file.write((char *)&e, sizeof(e));

                    for (int i = newloc + 1; i != newloc; i = (i + 1) % 10)
                    {
                        file.seekg(i * sizeof(e), ios::beg);
                        file.read((char *)&temp1, sizeof(temp1));
                        if (temp.eid == -1)
                        {
                            file.seekp(i * (sizeof(e)), ios::beg);
                            file.write((char *)&e, sizeof(e));
                            break;
                        }
                        if (i == newloc)
                        {
                            cout << "hashtable full!!!";
                        }
                    }
                }
            }
            cout << "Want to continue??[y/n]:";
            cin >> ch;
        } while (ch == 'y');
        file.close();
        display();
    }
};

int main()
{
    hashing h;
    h.display();
    // h.linearprobwor();
    h.linearprobwr();
    return 0;
}