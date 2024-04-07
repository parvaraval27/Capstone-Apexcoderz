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
                cout << "Enter 10 days sleep time(HH:MM): " << endl;
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
