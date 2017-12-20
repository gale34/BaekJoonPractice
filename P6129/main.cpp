#include <iostream>
#include <cstdio>

using namespace std;

#define NORTH 0
#define EAST 1
#define SOUTH 2
#define WEST 3

pair<int, int> start;
pair<int, int> finish;

int dx[4] = {-1,0,1,0};
int dy[4] = {0,1,0,-1};

void makepath();

int main()
{
    freopen("input.txt","r",stdin);

    int n;
    char** field;

    cin >> n;

    field = new char*[n];
    for(int i = 0; i < n; i++)
        field[i] = new char[n];

    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < n; j++)
        {
            cin >> field[i][j];
            if(field[i][j] == 'A')
            {
                start.first = i;
                start.first = j;
            }
            if(field[i][j] == 'B')
            {
                finish.first = i;
                finish.first = j;
            }
        }
    }


    for(int i = 0; i < n; i++)
        delete [] field[i];
    delete [] field;

    return 0;
}

int makepath(int n, int x, int y, char** field, bool** isVisited)
{
    if(x < 0 || x >= n || y < 0 || y >= n)
        return ;

    if(field[x][y] == '.')
    {
        isVisited[x][y] = true;
        return ;
    }

    for(int i = 0; i < 4; i++)

}


