#include<iostream>
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
