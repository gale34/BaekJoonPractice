#include <iostream>
#include <fstream>
#include <cstring>

using namespace std;

#define OMG 1
#define NOTHING 0
#define UNCHECK 0
#define CHECK 1

int max_food = 0;
int current_food = 0;
void check_food_waste(int** food_waste, bool** isChecked, int x, int y, int n, int m);

int main()
{
    int n, m, n_food;
    int** food_waste;
    bool** isChecked;
    int a, b;
    //ifstream input("input1743.txt");

    //input >> n >> m >> n_food;
    cin >> n >> m >> n_food;

    food_waste = new int*[n];
    isChecked = new bool*[n];

    for(int i = 0; i < n; i++)
    {
        food_waste[i] = new int[m];
        isChecked[i] = new bool[m];
        memset(food_waste[i], NOTHING, sizeof(int)*m);
        memset(isChecked[i], UNCHECK, sizeof(int)*m);
    }

    for(int i = 0; i < n_food; i++)
    {
        //input >> a >> b;
        cin >> a >> b;

        food_waste[a-1][b-1] = OMG;
    }

    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < m; j++)
        {
            //cout << i << j << "\n";
            if(isChecked[i][j] == UNCHECK)
                check_food_waste(food_waste,isChecked, i,j, n, m);

            if(max_food < current_food)
                max_food = current_food;

            current_food = 0;
        }
    }

    cout << max_food;

    return 0;
}

void check_food_waste(int** food_waste, bool** isChecked, int x, int y, int n, int m)
{
    if(food_waste[x][y] == 1 && isChecked[x][y] == UNCHECK)
    {
        //cout << x << y << food_waste[x][y] << "\n";
        //cout << current_food << "\n";
        current_food++;
        isChecked[x][y] = CHECK;

        //LEFT
        if(x != 0)
        {
            if(isChecked[x-1][y] == UNCHECK)
                check_food_waste(food_waste,isChecked,x-1, y, n, m);
        }
        //RIGHT
        if(x != n-1)
        {
            if(isChecked[x+1][y] == UNCHECK)
                check_food_waste(food_waste,isChecked,x+1, y, n, m);
        }
        //UP
        if(y != 0)
        {
            if(isChecked[x][y-1] == UNCHECK)
                check_food_waste(food_waste,isChecked,x, y-1, n, m);
        }
        if(y != m-1)
        {
            if(isChecked[x][y+1] == UNCHECK)
                check_food_waste(food_waste,isChecked,x, y+1, n, m);
        }
    }
    else if(food_waste[x][y] == 0)
    {
        isChecked[x][y] = CHECK;
    }
}
