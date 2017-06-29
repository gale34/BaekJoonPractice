#include <iostream>
#include <fstream>
#include <cstring>

using namespace std;

int checkBoundary(char** seats, int x, int y);

int r,s;
int max_hand = 0;
int total_hand = 0;

int main()
{
    int n = 0;
    char** seats;

    //ifstream input("input9518.txt");

    //input >> r >> s;

    cin >> r >> s;

    seats = new char*[r];

    for(int i = 0; i < r; i++)
    {
        seats[i] = new char[s];
        memset(seats[i], 0, sizeof(char)*s);
    }

    for(int i = 0; i < r; i++)
    {
        for(int j = 0; j < s; j++)
        {
            //input >> seats[i][j];
            cin >> seats[i][j];
        }

    }

    for(int i = 0; i < r; i++)
    {
        for(int j = 0; j < s; j++)
        {
            n = checkBoundary(seats,i,j);
            if(n > max_hand)
                max_hand = n;
        }
    }

    total_hand += max_hand;

    /*for(int i = 0; i < r; i++)
    {
        for(int j = 0; j < s; j++)
            cout << seats[i][j] << " ";

        cout << "\n";

        //cin >> number[i];
    }*/

    cout << total_hand;

    for(int i = 0; i < r; i++)
        delete [] seats[i];
    delete [] seats;


    return 0;
}

int checkBoundary(char** seats, int x, int y)
{
    int n = 0;

    if((int)seats[x][y] != 46) // not empty. seat unavailable.
    {
        if(x - 1 >= 0 && y - 1 >= 0)
        {
            if((int)seats[x-1][y-1] == 111)
                n++;
        }

        if(x - 1 >= 0)
        {
            if((int)seats[x-1][y] == 111)
                n++;
        }

        if(x - 1 >= 0 && y + 1 < s)
        {
            if((int)seats[x-1][y+1] == 111)
                n++;
        }

        if(y - 1 >= 0)
        {
            if((int)seats[x][y-1] == 111)
                n++;
        }

        if(y + 1 < s)
        {
            if((int)seats[x][y+1] == 111)
                n++;
        }

        if(x + 1 < r && y - 1 >= 0)
        {
            if((int)seats[x+1][y-1] == 111)
                n++;
        }

        if(x + 1 < r)
        {
            if((int)seats[x+1][y] == 111)
                n++;
        }

        if(x + 1 < r && y + 1 < s)
        {
            if((int)seats[x+1][y+1] == 111)
                n++;
        }

        seats[x][y] = 'O';
        total_hand += n;

        return 0;
    }
    else // empty. seat available.
    {
        if(x - 1 >= 0 && y - 1 >= 0)
        {
            if((int)seats[x-1][y-1] != 46)
                n++;
        }

        if(x - 1 >= 0)
        {
            if((int)seats[x-1][y] != 46)
                n++;
        }

        if(x - 1 >= 0 && y + 1 < s)
        {
            if((int)seats[x-1][y+1] != 46)
                n++;
        }

        if(y - 1 >= 0)
        {
            if((int)seats[x][y-1] != 46)
                n++;
        }

        if(y + 1 < s)
        {
            if((int)seats[x][y+1] != 46)
                n++;
        }

        if(x + 1 < r && y - 1 >= 0)
        {
            if((int)seats[x+1][y-1] != 46)
                n++;
        }

        if(x + 1 < r)
        {
            if((int)seats[x+1][y] != 46)
                n++;
        }

        if(x + 1 < r && y + 1 < s)
        {
            if((int)seats[x+1][y+1] != 46)
                n++;
        }

        return n;
    }
}
