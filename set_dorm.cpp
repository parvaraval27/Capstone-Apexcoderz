void set_dorm()
{
    system("cls");
    cout<<"\tEnter input file name : ";
    cin>>Filename;
    cout<<"\n\n\tEnter Day(small letter) : ";
    string day;
    cin>>day;
    ifstream in(Filename);
    string line;
    vector<string> lines;
    int ind;
    string Allday[] = {"monday","tuesday","wednesday","thursday","friday","saturday","sunday"};
    for (int i=0;i<7;i++)
    {
        if(day.compare(Allday[i])==0)
        {
            ind=i+1;
            break;
        }
    }
    while(getline(in,line))
    {
        stringstream ss(line);
        string word;
        getline(ss,word,':');
        getline(ss,word,':');
        getline(ss,word,':');
        int H, M;
        for (int i=0;i<2*ind;i++)
        {
            getline(ss,word,':');
            if(i%2==0)
            {
                H=stoi(word);
            }
            else
            {
                M=stoi(word);
            }
        }

        if (H==9 and M>=0 and M<=30)
        {
            line[0]='1';
        }
        else if(H==9 and M>30 and M<=59)
        {
            line[0]='2';
        }
        else if(H==10 and M>=0 and M<=30)
        {
            line[0]='3';
        }
        else if(H==10 and M>30 and M<=59)
        {
            line[0]='4';
        }
        else if(H==11 and M>=0 and M<=30)
        {
            line[0]='5';
        }
        else if(H==11 and M>30 and M<=59)
        {
            line[0]='6';
        }
        lines.push_back(line);
        lines.push_back("\n\n");

        getline(in,line);
    }
    in.close();

    ofstream out(Filename,ios::out);

    for (int i=0;i<lines.size();i++)
    {
        out<<lines[i];
    }
    out.close();
    cout<<"\n\n\t\tIt take few seconds wait......";
    Sleep(3000);
}
