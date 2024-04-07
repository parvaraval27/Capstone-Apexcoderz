void search(Inmates i)
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
        unordered_map<string, pair<pair<string, string>, pair<string,string>>> inmates;

        while (getline(in, line))
        {
            stringstream ss(line);
            string word;
            getline(ss, word, ':');
            string dorm=word;
            getline(ss, word, ':');
            i.setID(to_string(stoi(word)));
            getline(ss, word, ':');
            i.setname(word);
            int ind = ltm->tm_wday + 1;
            if (ind == 1)
                ind += 6;
            string H, M;
            for (int j = 0; j < 2 * ind; j++)
            {
                getline(ss, word, ':');
                if (j % 2 == 0)
                {
                    H = word;
                }
                else
                {
                    M = word;
                }
            }
            inmates[i.getID()] = make_pair(make_pair(i.getname(), dorm), make_pair(H, M));
            getline(in,line);
        }
        in.close();

        auto it = inmates.find(ID);

        if (it != inmates.end())
        {
            system("cls");
            cout << GREEN << "\n\tInmate Found....." << RESET << endl;
            cout << "\n\nInmate's Details are Loading, Please wait.....";
            Sleep(3000);
            system("cls");
            cout << "\n\n\tDorm : " << (((it->second).first).second);
            cout << "\n\n\tID : " << it->first;
            cout << "\n\n\tName : " << ((it->second).first).first;
            cout << "\n\n\tSleep_time - " << ((it->second).second).first << ":" << ((it->second).second).second;
            cout << "\n\n\n\tPress Enter to continue.....";
            getchar();
            getchar();
        }
        else
        {
            system("cls");
            cout << RED << "\n\n\tError 404 : Inmate Not Found";
            Sleep(2000);
        }
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
        cout << setw(5) << "<"
             << "Dorm"
             << ">";
        cout << setw(8) << "<"
             << "ID"
             << ">";
        cout << setw(8) << "<"
             << "Sleep_time"
             << ">";
        cout << setw(12) << "<"
             << "Name"
             << ">";
        cout << endl
             << endl;
        while (getline(in, line))
        {
            stringstream ss(line);
            string word;
            getline(ss, word, ':');
            cout << setw(5) << "<" << stoi(word) << ">";
            getline(ss, word, ':');
            cout << setw(8) << "<" << word << ">";
            getline(ss, word, ':');
            string name = word;
            int H = 0, M = 0;
            int ind = ltm->tm_wday + 1;
            if (ind == 1)
                ind += 6;
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
            if (M <= 9)
                cout << setw(8) << "<" << setw(2) << H << ":"
                     << "0" << M << setw(2) << ">";
            else
                cout << setw(8) << "<" << setw(2) << H << ":" << M << setw(2) << ">";

            cout << setw(15) << "<" << name << ">";
            cout << "\n";
            getline(in, line);
        }

        cout << "\n\n\nPress Enter to continue....";
        getchar();
        getchar();
    }
}
