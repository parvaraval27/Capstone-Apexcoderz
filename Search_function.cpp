#include<iostream>
#include <windows.h>
using namespace std;

string Filename;

class Inmates
{
    string name, ID;
    int dorm;

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
    void setdorm(int dorm)
    {
        this->dorm = dorm;
    }
    string getname()
    {
        return name;
    }
    string getID()
    {
        return ID;
    }
    int getdorm()
    {
        return dorm;
    }
};
void search()
{
    system("cls");
    cout<<"\n\n\t\t\t*SEARCH*\n\n";
    string ID;
    cout<<"\tEnter Inmate's ID : ";
    cin>>ID;
    ifstream in(Filename);

    if (!in)
    {
        cout<<"\tError 404: File can't Open!" << endl;
        Sleep(2000);
        return;
    }
    else
    {
        string line;
        bool found=false;
        while (getline(in,line))
        {
            int ff=line.find(ID);
            if (ff!=string::npos)
            {
                system("cls");
                cout<<"\tInmate Found";
                cout<<"\n\nWait, the details are loading...";
                Sleep(3000);
                system("cls");
                stringstream ss(line);
                string word;
                getline(ss,word,':');
                cout<<"\n\n\tDorm : "<<word;
                getline(ss,word, ':');
                cout <<"\n\n\tId : "<<word;
                getline(ss, word, ':');
                cout<<"\n\n\tName : "<<word;
                int sumH=0,sumM=0;
                for (int i=0;i<14;i++)
                {
                    getline(ss,word,':');
                    if (i%2==0)
                    {
                        sumH+=stoi(word);
                    }
                    else
                    {
                        sumM+=stoi(word);
                    }
                }
                cout<<"\n\n\tAvg Sleep_time :- " <<(int)(sumH/7)<<":"<<(int)(sumM/7);
                cout<<"\n\n\n\nPress Enter to continue....";
                getchar();
                getchar();
                in.close();
                return;
            }
        }
        in.close();
        system("cls");
        cout<<"\tError 404 : Inmate Not Found!";
        Sleep(2000);
        return;
    }
}

int main()
{
    Inmates i;
    bool exit = false;
    while (!exit)
    {
        system("cls");
        int choice;
        cout << "\n\n\t\t\t\t\t*********";
        cout << "\n\t\t\t\t\t|     SLEEP INDUCER     |";
        cout << "\n\t\t\t\t\t*********";
        cout << "\n\n 1.Enter New Inmates";
        cout << "\n\n 2.Show Inmates data";
        cout << "\n\n 3.Search Inmates";
        cout << "\n\n 4.Delete Inmates";
        cout << "\n\n 5.Set Auto Dorm";
        cout << "\n\n 6.Start Inducer";
        cout << "\n\n 7.Exit";
        cout << "\n\n Enter Choice: ";
        cin >> choice;
        cin.ignore();
        switch (choice)
        {
        case 1:
        {
            insert(i);
            break;
        }
        case 2:
        {
            system("cls");
            cout << "Enter input file name : ";
            cin >> Filename;
            show();
            break;
        }
        case 3:
        {
            system("cls");
            cout << "Enter input file name : ";
            cin >> Filename;
            search();
            break;
        }
        case 4:
        {
            delete_inmate();
            break;
        }
        case 5:
        {
            set_dorm();
            break;
        }
        case 6:
        {
            break;
        }
        case 7:
        {
            exit = true;
            break;
        }
        default:
        {
            cout << "\n\nEnter valid choice";
            Sleep(2000);
            break;
        }
        }
    }
}
