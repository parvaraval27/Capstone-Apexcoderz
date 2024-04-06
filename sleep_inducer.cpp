#include <bits/stdc++.h>
#include <windows.h>
using namespace std;

class Inmates
{
    string name, ID;
    int dome;

public:
    Inmates() {}
    void setname(string name)
    {
        this->name = name;
    }
    void setID(string ID)
    {
        this->ID = ID;
    }
    void setdome(int dome)
    {
        this->dome = dome;
    }
    string getname()
    {
        return name;
    }
    string getID()
    {
        return ID;
    }
    int getdome()
    {
        return dome;
    }
};

void insert(Inmates i)
{
    bool close = false;
    while (!close)
    {
        system("cls");
        cout << "\n\n\t\t\t**INSERT\n\n";
        string name, ID;
        int dome;

        cout << "\tEnter Name : ";
        cin >> name;
        i.setname(name);
        cout << "\n\n\tEnter ID : ";
        cin >> ID;
        i.setID(ID);
        cout << "\n\n\tEnter Dome no. : ";
        cin >> dome;
        i.setdome(dome);

        ofstream out("inmates.txt", ios::app);

        if (!out)
        {
            cout << "\tError: File Can't Open!" << endl;
            return;
        }
        else
        {
            out << i.getdome() << " : " << i.getID() << " : " << i.getname() << " : ";

            switch (dome)
            {
            case 1:
            {
                out << "10 : 00" << endl
                    << endl;
                break;
            }
            case 2:
            {
                out << "10 : 30" << endl
                    << endl;
                break;
            }
            case 3:
            {
                out << "11 : 00" << endl
                    << endl;
            }
            }
        }
        out.close();
        system("cls");
        cout << "Loading";
        for (int i = 0; i < 5; i++)
        {
            cout << ".";
            Sleep(800);
        }
        system("cls");
        cout << "\n\n\tData Added Successfully";
        Sleep(2000);

        system("cls");
        int choice;
        cout << "\t1.Add more data";
        cout << "\n\n\t2.close.";
        cout << "\n\n\tEnter choise: ";
        cin >> choice;
        if (choice == 2)
        {
            close = true;
        }
    }
}

void search()

void show()



int main()
{
    Inmates i;
    bool exit = false;
    while (!exit)
    {
        system("cls");
        int choice;
        cout << "\n\n\t\t\t*** SLEEP INDUCER ***";
        cout << "\n\n 1.Enter New Inmates";
        cout << "\n\n 2.Show Inmates data";
        cout << "\n\n 3.Search Inmates";
        cout << "\n\n 4.Exit";
        cout << "\n\n Enter Choice: ";
        cin >> choice;

        switch (choice)
        {
        case 1:
        {
            insert(i);
            break;
        }
        case 2:
        {
            show();
            break;
        }
        case 3:
        {
            search();
            break;
        }
        case 4:
        {
            exit = true;
            break;
        }
        default:
        {
            cout << "\n\nEnter valid choice";
            break;
        }
        }
    }
}
