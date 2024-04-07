#include <bits/stdc++.h>
#include <conio.h>
#include <ctime>
#include <windows.h>
#include<mmsystem.h>

using namespace std;

#pragma comment(lib,"winmm.lib")

#define RESET "\033[0m"
#define RED "\033[31m"
#define GREEN "\033[32m"
#define YELLOW "\033[33m"
#define BLUE "\033[34m"
#define MAGENTA "\033[35m"
#define CYAN "\033[36m"
#define WHITE "\033[37m"

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
    bool close = false;
    bool filex = true;
    while (!close)
    {
        system("cls");
        string name, ID;
        int dorm;
        if (filex)
        {
            cout << "\n\n\t\t\t******INSERT********\n\n";
            cout << "Enter input file name : ";
            cin >> Filename;
            system("cls");
            filex = false;
        }
        cout << "\t******INSERT********\n\n";
        cout << "\n\n\t\tEnter ID : ";
        cin >> ID;
        i.setID(ID);
        getchar();
        if (ifexist(ID))
        {
            cout << RED << "\n\n\t\tInmate Already Exist...." << RESET;
            Sleep(2000);
        }
        else
        {
            cout << "\n\n\t\tEnter Name : ";
            getline(cin, name);
            i.setname(name);

            ofstream out(Filename, ios::app);

            if (!out)
            {
                cout << RED << "\tError: File Can't Open!" << RESET << endl;
                Sleep(2000);
                return;
            }
            else
            {
                int sumH = 0, sumM = 0;
                int H[7], M[7];
                cout << "Enter 7 days sleep time(HH:MM): " << endl;
                string day[7] = {"Monday", "Tuesday", "Wednesday", "Thursday", "Friday", "Saturday", "Sunday"};
                for (int i = 0; i < 7; i++)
                {

                    cout << day[i] << "'s Sleep time - ";
                    cin >> H[i];
                    getchar();
                    cin >> M[i];
                    sumH += H[i];
                    sumM += M[i];
                }
                int AvgH = sumH / 7;
                int AvgM = sumM / 7;

                if (AvgH == 9 and AvgM >= 0 and AvgM <= 30)
                {
                    out << "1 : ";
                }
                else if (AvgH == 9 and AvgM > 30 and AvgM <= 59)
                {
                    out << "2 : ";
                }
                else if (AvgH == 10 and AvgM >= 0 and AvgM <= 30)
                {
                    out << "3 : ";
                }
                else if (AvgH == 10 and AvgM > 30 and AvgM <= 59)
                {
                    out << "4 : ";
                }
                else if (AvgH == 11 and AvgM >= 0 and AvgM <= 30)
                {
                    out << "5 : ";
                }
                else if (AvgH == 11 and AvgM > 30 and AvgM <= 59)
                {
                    out << "6 : ";
                }

                out << i.getID() << " : " << i.getname() << " : ";
                for (int i = 0; i < 7; i++)
                {
                    out << H[i] << ":" << M[i];
                    if (i != 6)
                        out << " : ";
                }
                out << endl
                    << endl;
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
            cout << GREEN << "\n\n\tData Added Successfully" << RESET;
           Sleep(2000);
        }
        system("cls");
        int choice;
        cout << "\t1. Add more data in same file";
        cout << "\n\n\t2. Add more data in other file";
        cout << "\n\n\t3. Close";
        cout << "\n\n\tEnter choice: ";
        cin >> choice;
        if (choice == 2)
        {
            filex = true;
        }
        if (choice == 3)
        {
            close = true;
        }
    }
}

void search()
{
    system("cls");
    time_t now = time(0);
    tm *ltm = localtime(&now);
    cout << "\n\n\t\t\t**********SEARCH************\n\n";
    string ID;
    cout << "\tEnter Inmate's ID : ";
    cin >> ID;

    ifstream in(Filename);

    if (!in)
    {
        cout << RED << "\tError 404: File can't Open!" << RESET << endl;
        Sleep(2000);
        return;
    }
    else
    {
        string line;
        
        bool found = false;
        while (getline(in, line))
        {
            int ff = line.find(ID);
            if (ff != string ::npos)
            {
                system("cls");
                cout << GREEN << "\tInmate Found" << RESET;
                cout << "\n\nWait, the details are loading...";
                Sleep(3000);
                system("cls");
                stringstream ss(line);
                string word;
                getline(ss, word, ':');
                cout << "\n\n\tDorm : " << word;
                getline(ss, word, ':');
                cout << "\n\n\tId : " << word;
                getline(ss, word, ':');
                cout << "\n\n\tName : " << word;
                int ind = ltm->tm_wday+1;
                if(ind==1)
                    ind+=6;
                int H,M;
                for (int i = 0; i < 2 * ind; i++)
                  {
                      getline(ss, word, ':');
                      if (i % 2 == 0)
                      {
                          H = stoi(word);
                      }
                      else
                      {
                          M = stoi(word);
                      }
                  }
                cout << "\n\n\tSleep_time :- " << H << ":" << M;
                cout << "\n\n\n\nPress Enter to continue....";
                getchar();
                getchar();
                in.close();
                return;
            }
        }
        in.close();
        system("cls");
        cout << RED << "\tError 404 : Inmate Not Found!" << RESET;
        Sleep(2000);
        return;
    }
}

void show()
{
    ifstream in(Filename);
    system("cls");
    if (!in)
    {
        cout << RED << "Error 404 : File not found!" << RESET << endl;
        Sleep(2000);
        return;
    }
    else
    {
        time_t now = time(0);
        tm *ltm = localtime(&now);
        string line;
        cout<<setw(5)<<"<"<<"Dorm"<<">";
        cout<<setw(8)<<"<"<<"ID"<<">";
        cout<<setw(8)<<"<"<<"Sleep_time"<<">";
        cout<<setw(8)<<"<"<<"Name"<<">";
        cout<<endl<<endl;
        while (getline(in, line))
        {
            stringstream ss(line);
            string word;
            getline(ss, word, ':');
            cout << setw(5) << "<" <<stoi(word) <<">";
            getline(ss, word, ':');
            cout << setw(8)<<"<" << word<<">";
            getline(ss, word, ':');
            string name=word;
            int H = 0, M = 0;
            int ind = ltm->tm_wday+1;
            if(ind==1)
                ind+=6;
            for (int i = 0; i < 2 * ind; i++)
        {
            getline(ss, word, ':');
            if (i % 2 == 0)
            {
                H = stoi(word);
            }
            else
            {
                M = stoi(word);
            }
        }
            if(M<=9)
                cout << setw(8) <<"<"<<setw(2)<< H << ":" <<"0" << M <<setw(2)<< ">";
            else
                cout << setw(8) <<"<"<<setw(2)<< H << ":" << M <<setw(2)<< ">";

            cout << setw(15) <<"<" << name << ">";
            cout << "\n";
            getline(in, line);
            
        }

        cout << "\n\n\nPress Enter to continue....";
        getchar();
        getchar();
    }
}

void delete_inmate()
{
    bool loop = true;
    while (loop)
    {
        loop = false;
        system("cls");
        cout << "=============================Delete====================================";
        cout << "\n\n\tEnter input File name : ";
        cin >> Filename;
        getchar();
        system("cls");
        cout << "=============================Delete====================================";
        cout << "\n\n\tEnter Inmate ID to Delete : ";
        string ID;
        cin >> ID;

        ifstream in(Filename);
        bool found = false;
        vector<string> lines;
        string line;
        while (getline(in, line))
        {
            int ff = line.find(ID);
            if (ff != string ::npos)
            {
                found = true;
            }
            else
            {
                lines.push_back(line);
                lines.push_back("\n\n");
            }
            getline(in, line);
        }
        in.close();

        ofstream out(Filename, ios::out);

        for (int i = 0; i < lines.size(); i++)
        {
            out << lines[i];
        }
        out.close();

        if (found)
        {
            system("cls");
            cout << GREEN << "\n\n\tInmate Deleted........" << RESET;
            Sleep(2000);
        }
        else
        {
            system("cls");
            cout << RED << "\n\nInmate Not Found,Enter valid Inmate ID" << RESET;
            cout << "\n\n\t1.Want to delete.";
            cout << "\n\n\t2.Back to main menu.";
            int choice;
            cin >> choice;
            switch (choice)
            {
            case 1:
                loop = true;
                break;
            case 2:
                loop = false;
                break;
            }
        }
    }
}

void set_dorm()
{
    system("cls");
    cout << "\tEnter input file name : ";
    cin >> Filename;
    cout << "\n\n\tEnter Day(small letter) : ";
    string day;
    cin >> day;
    ifstream in(Filename);
    string line;
    vector<string> lines;
    int ind;
    string Allday[] = {"monday", "tuesday", "wednesday", "thursday", "friday", "saturday", "sunday"};
    for (int i = 0; i < 7; i++)
    {
        if (day.compare(Allday[i]) == 0)
        {
            ind = i + 1;
            break;
        }
    }
    while (getline(in, line))
    {
        stringstream ss(line);
        string word;
        getline(ss, word, ':');
        getline(ss, word, ':');
        getline(ss, word, ':');
        int H, M;
        for (int i = 0; i < 2 * ind; i++)
        {
            getline(ss, word, ':');
            if (i % 2 == 0)
            {
                H = stoi(word);
            }
            else
            {
                M = stoi(word);
            }
        }

        if (H == 9 and M >= 0 and M <= 30)
        {
            line[0] = '1';
        }
        else if (H == 9 and M > 30 and M <= 59)
        {
            line[0] = '2';
        }
        else if (H == 10 and M >= 0 and M <= 30)
        {
            line[0] = '3';
        }
        else if (H == 10 and M > 30 and M <= 59)
        {
            line[0] = '4';
        }
        else if (H == 11 and M >= 0 and M <= 30)
        {
            line[0] = '5';
        }
        else if ((H == 11 and M > 30 and M <= 59) or (H == 12 and M == 0))
        {
            line[0] = '6';
        }
        lines.push_back(line);
        lines.push_back("\n\n");

        getline(in, line);
    }
    in.close();

    ofstream out(Filename, ios::out);

    for (int i = 0; i < lines.size(); i++)
    {
        out << lines[i];
    }
    out.close();
    cout << "\n\n\t\tIt take few seconds wait......";
    Sleep(3000);
}

void inducer()
{

    cout << "Enter input file name : ";
    cin >> Filename;
    cout << "\n\nPress Enter any time for exit Inducer ...";
    Sleep(2000);
    system("cls");

    while (!(_kbhit()))
    {
        time_t now = time(0);
        tm *ltm = localtime(&now);

        int hour = ltm->tm_hour;
        int minute = ltm->tm_min;
        int second = ltm->tm_sec;
        int dormNo;
        if (hour == 21 and minute >= 0 and minute <= 30)
        {   
            system("cls");
            cout<<GREEN<<"\tStarting inducer in dorm 1"<<RESET<<endl<<endl;
            cout<<"Earpod ID of dorm 1 members"<<endl;
            dormNo = 1;
            ifstream in(Filename);
            if (!in)
            {
                cout << RED << "Error 404 : File not found!" << RESET << endl;
                Sleep(2000);
                return;
            }
            else
            {
                string line;
                while (getline(in, line))
                {
                    stringstream ss(line);
                    string word;
                    getline(ss, word, ':');
                    int ff=word.find("1");
                    if(ff != string::npos){
                    getline(ss, word, ':');
                    cout <<setw(2) << "<"<<stoi(word)<<">";
                    }
                    getline(in,line);
                }
                cout<<endl;
                cout<<"playig music \n";
                PlaySound(TEXT("abc.wav"),NULL,SND_FILENAME | SND_SYNC);
                cout<<"over";
            }
        }
        else if (hour == 21 and minute > 30 and minute <= 59)
        {
            
            system("cls");
            cout<<GREEN<<"\tStarting inducer in dorm 2"<<RESET<<endl<<endl;
            cout<<"Earpod ID of dorm 2 members"<<endl;
            ifstream in(Filename);
            if (!in)
            {
                cout << RED << "Error 404 : File not found!" << RESET << endl;
                Sleep(2000);
                return;
            }
            else
            {
                string line;
                while (getline(in, line))
                {
                    stringstream ss(line);
                    string word;
                    getline(ss, word, ':');
                    int ff=word.find("2");
                    if(ff != string::npos){
                    getline(ss, word, ':');
                    cout <<setw(2) << "<"<<stoi(word)<<">";
                    }
                    getline(in,line);
                }
                cout<<endl;
                cout<<"playig music \n";
                PlaySound(TEXT("abc.wav"),NULL,SND_FILENAME | SND_SYNC);
                cout<<"over";
            }
        }
        else if (hour == 22 and minute >= 0 and minute <= 30)
        {
            
            system("cls");
            cout<<GREEN<<"\tStarting inducer in dorm 3"<<RESET<<endl<<endl;
            cout<<"Earpod ID of dorm 3 members"<<endl;
            ifstream in(Filename);
            if (!in)
            {
                cout << RED << "Error 404 : File not found!" << RESET << endl;
                Sleep(2000);
                return;
            }
            else
            {
                string line;
                while (getline(in, line))
                {
                    stringstream ss(line);
                    string word;
                    getline(ss, word, ':');
                    int ff=word.find("3");
                    if(ff != string::npos){
                    getline(ss, word, ':');
                    cout <<setw(2) << "<"<<stoi(word)<<">";
                    }
                    getline(in,line);
                }
                cout<<endl;
                cout<<"playig music \n";
                PlaySound(TEXT("abc.wav"),NULL,SND_FILENAME | SND_SYNC);
                cout<<"over";
            }
        }
        else if (hour == 22 and minute > 30 and minute <= 59)
        {
            
            system("cls");
            cout<<GREEN<<"\tStarting inducer in dorm 4"<<RESET<<endl<<endl;
            cout<<"Earpod ID of dorm 4 members"<<endl;
            ifstream in(Filename);
            if (!in)
            {
                cout << RED << "Error 404 : File not found!" << RESET << endl;
                Sleep(2000);
                return;
            }
            else
            {
                string line;
                while (getline(in, line))
                {
                    stringstream ss(line);
                    string word;
                    getline(ss, word, ':');
                    int ff=word.find("4");
                    if(ff != string::npos){
                    getline(ss, word, ':');
                    cout <<setw(2) << "<"<<stoi(word)<<">";
                    }
                    getline(in,line);
                }
                cout<<endl;
                cout<<"playig music \n";
                PlaySound(TEXT("abc.wav"),NULL,SND_FILENAME | SND_SYNC);
                cout<<"over";
            }
        }
        else if (hour == 23 and minute >= 0 and minute <= 30)
        {
            
            system("cls");
            cout<<GREEN<<"\tStarting inducer in dorm 5"<<RESET<<endl<<endl;
            cout<<"Earpod ID of dorm 5 members"<<endl;
            ifstream in(Filename);
            if (!in)
            {
                cout << RED << "Error 404 : File not found!" << RESET << endl;
                Sleep(2000);
                return;
            }
            else
            {
                string line;
                while (getline(in, line))
                {
                    stringstream ss(line);
                    string word;
                    getline(ss, word, ':');
                    int ff=word.find("5");
                    if(ff != string::npos){
                    getline(ss, word, ':');
                    cout <<setw(2) << "<"<<stoi(word)<<">";
                    }
                    getline(in,line);
                }
                cout<<endl;
                cout<<"playig music \n";
                PlaySound(TEXT("abc.wav"),NULL,SND_FILENAME | SND_SYNC);
                cout<<"over";
            }
        }
        else if (hour == 23 and minute > 30 and minute <= 59)
        {
            dormNo = 6;
            system("cls");
            cout<<GREEN<<"\tStarting inducer in dorm 1"<<RESET<<endl<<endl;
            cout<<"Earpod ID of dorm 6 members"<<endl;
            ifstream in(Filename);
            if (!in)
            {
                cout << RED << "Error 404 : File not found!" << RESET << endl;
                Sleep(2000);
                return;
            }
            else
            {
                string line;
                while (getline(in, line))
                {
                    int ff=line.find("6");
                    if(ff != string::npos){
                    stringstream ss(line);
                    string word;
                    getline(ss, word, ':');
                    getline(ss, word, ':');
                    cout << setw(2) << "<"<<stoi(word)<<">";
                    }
                    getline(in,line);
                }
                cout<<endl;
                cout<<"playig music \n";
                PlaySound(TEXT("abc.wav"),NULL,SND_FILENAME | SND_SYNC);
                cout<<"over";
            }
        }

        cout << "Current time: " << hour << ":" << minute << ":" << second << "\r" << flush;
        Sleep(1000);
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
        cout << "\n\t\t\t\t\t|";
        cout << MAGENTA << "     SLEEP INDUCER     " << RESET;
        cout << "|";
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
            system("cls");
            inducer();
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
