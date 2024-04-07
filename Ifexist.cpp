bool ifexist(string ID)
{
    ifstream in(Filename);

    string line;
    while (getline(in, line))
    {
        int ff = line.find(ID);
        if (ff != string ::npos)
        {
            return true;
        }
    }

    return false;
}
