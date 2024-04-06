void delete_inmate()
{
    bool loop=true;
    while(loop)
    {
        loop=false;
        system("cls");
        cout<<"=============================Delete====================================";
        cout<<"\n\n\tEnter input File name : ";
        cin>>Filename;
        getchar();
        system("cls");
        cout<<"=============================Delete====================================";
        cout<<"\n\n\tEnter Inmate ID to Delete : ";
        string ID;
        cin>>ID;
        ifstream in(Filename);
        bool found=false;
        vector<string> lines;
        string line;
        while(getline(in,line))
        {
            int ff=line.find(ID);
            if (ff!=string::npos)
            {
                found=true;
            }
            else
            {
                lines.push_back(line);
                lines.push_back("\n\n");
            }
            getline(in,line);
        }
        in.close();
        ofstream out(Filename,ios::out);
        for (int i=0;i<lines.size();i++)
        {
            out<<lines[i];
        }
        out.close();
        if(found)
        {
            system("cls");
            cout<<"\n\n\tInmate Deleted........";
            Sleep(2000);
        }
        else
        {
            system("cls");
            cout<<"\n\nInmate Not Found,Enter valid Inmate ID";
            cout<<"\n\n\t1.Want to delete.";
            cout<<"\n\n\t2.Back to main menu.";
            int choice;
            cin>>choice;
            switch(choice)
            {
            case 1:
            {
                loop = true;
                break;
            }
            case 2:
            {
                loop = false;
                break;
            }
            }
        }
    }
}
