void inducer()
{

    cout<<"Enter input file name : ";
    cin>>Filename;
    cout << "\n\nPress Enter any time for exit Inducer ...";
    Sleep(2000);
    system("cls");

    while(!(_kbhit()))
    {
        time_t now=time(0);
        tm *ltm=localtime(&now);

        int hour=ltm->tm_hour;
        int minute=ltm->tm_min;
        int second=ltm->tm_sec;
        int dormNo;
        if (hour==21 and minute>=0 and minute<=30)
        {   
            system("cls");
            cout<<GREEN<<"\tStarting inducer in dorm 1"<<RESET<<endl<<endl;
            cout<<"Earpod ID of dorm 1 members"<<endl;
            dormNo=1;
            ifstream in(Filename);
            if (!in)
            {
                cout<<RED<<"Error 404 : File not found!"<<RESET<<endl;
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
                    int ff=word.find("1");
                    if(ff!=string::npos){
                    getline(ss, word,':');
                    cout<<"<"<<stoi(word)<<">";
                    }
                    getline(in,line);
                }
                cout<<endl;
                cout<<"playig music \n";
                PlaySound(TEXT("abc.wav"),NULL,SND_FILENAME | SND_SYNC);
                cout<<"over";
            }
        }
        else if(hour==21 and minute>30 and minute<=59)
        {
            dormNo=2;
        }
        else if(hour==22 and minute>=0 and minute<=30)
        {
            dormNo=3;
        }
        else if(hour==22 and minute>30 and minute<=59)
        {
            dormNo=4;
        }
        else if(hour==23 and minute>=0 and minute<=30)
        {
            dormNo=5;
        }
        else if(hour==23 and minute>30 and minute<=59)
        {
            dormNo = 6;
            system("cls");
            cout<<GREEN<<"\tStarting inducer in dorm 1"<<RESET<<endl<<endl;
            cout<<"Earpod ID of dorm 6 members"<<endl;
            ifstream in(Filename);
            if(!in)
            {
                cout<<RED<<"Error 404 : File not found!"<<RESET<<endl;
                Sleep(2000);
                return;
            }
            else
            {
                string line;
                while (getline(in,line))
                {
                    int ff=line.find("6");
                    if(ff!= string::npos){
                    stringstream ss(line);
                    string word;
                    getline(ss, word,':');
                    getline(ss, word,':');
                    cout<<"<"<<stoi(word)<<">";
                    }
                    getline(in,line);
                }
                cout<<endl;
                cout<<"playig music \n";
                PlaySound(TEXT("abc.wav"),NULL,SND_FILENAME | SND_SYNC);
                cout<<"over";
            }
        }

        cout<<"Current time: "<<hour<<":"<<minute<<":"<<second<<"\r"<<flush;
        Sleep(1000);
    }
}
