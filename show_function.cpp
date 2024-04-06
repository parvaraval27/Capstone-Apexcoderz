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
