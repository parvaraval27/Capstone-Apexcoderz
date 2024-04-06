#include <bits/stdc++.h>
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
void insert(Inmates i)
{
    bool close=false;
    bool filex=true;
    while(!close)
    {
        system("cls");
        string name,ID;
        int dorm;
        if (filex)
        {
            cout<<"\n\n\t\t\t******INSERT********\n\n";
            cout<<"Enter input file name : ";
            cin>>Filename;
            system("cls");
            filex=false;
        }
        cout<<"\t****INSERT****\n\n";
        cout<<"\n\n\tEnter ID : ";
        cin>>ID;
        i.setID(ID);
        if(ifexist(ID)){
            cout<<"\n\n\tInmate Already Exist....";
            Sleep(2000);
        }
        else{
        cout <<"\n\n\t\tEnter Name : ";
        getline(cin,name);
        i.setname(name);

        ofstream out(Filename,ios::app);

        if (!out)
        {
            cout<<"\tError: File Can't Open!"<<endl;
            Sleep(2000);
            return;
        }
        else
        {
            int sumH=0,sumM=0;
            int H[7],M[7];
            cout<<"Enter 10 days sleep time(HH:MM): "<<endl;
            string day[7] = {"Monday", "Tuesday", "Wednesday", "Thursday", "Friday", "Saturday", "Sunday"};
            for(int i=0; i<7;i++)
            {

                cout<<day[i]<<"'s Sleep time - ";
                cin>>H[i];
                getchar();
                cin >> M[i];
                sumH+=H[i];
                sumM+=M[i];
            }
            int AvgH=sumH/7;
            int AvgM=sumM/7;

            if (AvgH==9 and AvgM>=0 and AvgM<= 30)
            {
                out<<"1 : ";
            }
            else if (AvgH==9 and AvgM>30 and AvgM<=59)
            {
                out<<"2 : ";
            }
            else if (AvgH==10 and AvgM>=0 and AvgM<= 30)
            {
                out<<"3 : ";
            }
            else if (AvgH==10 and AvgM>30 and AvgM<=59)
            {
                out<<"4 : ";
            }
            else if (AvgH==11 and AvgM>=0 and AvgM<=30)
            {
                out<<"5 : ";
            }
            else if (AvgH==11 and AvgM>30 and AvgM<=59)
            {
                out << "6 : ";
            }

            out<<i.getID()<<" : "<<i.getname()<<" : ";
            for (int i=0; i<7;i++)
            {
                out<<H[i]<<":"<< M[i];
                if (i!=6)
                    out<<" : ";
            }
            out<<endl
                <<endl;
        }
        out.close();
        system("cls");
        cout<<"Loading";
        for (int i=0;i<5;i++)
        {
            cout<<".";
            Sleep(800);
        }
        system("cls");
        cout<<"\n\n\tData Added Successfully";
        Sleep(2000);
        }
        system("cls");
        int choice;
        cout<<"\t1. Add more data in same file";
        cout<<"\n\n\t2. Add more data in other file";
        cout<<"\n\n\t3. Close";
        cout<<"\n\n\tEnter choice: ";
        cin>>choice;
        if(choice==2)
        {
            filex=true;
        }
        if(choice==3)
        {
            close=true;
        }
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
