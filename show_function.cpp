void show()
{
    ifstream in(Filename);
    system("cls");
    if (!in)
    {
        cout<<"Error 404 : File not found!"<<endl;
        Sleep(2000);
        return;
    }
    else
    {
        string line;
        while (getline(in,line))
        {
            stringstream ss(line);
            string word;
            getline(ss, word,':');
            cout<<"\n\n\tDorm : "<<word;
            getline(ss, word,':');
            cout<<"\n\n\tId : "<<word;
            getline(ss, word,':');
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

            cout<<"\n\n\tAvg Sleep_time :- "<<(int)(sumH/7)<<":"<<(int)(sumM/7);

            cout<<"\n"<<endl;
            getline(in,line);
        }

        cout<<"\n\n\nPress Enter to continue....";
        getchar();
        getchar();
    }
}
