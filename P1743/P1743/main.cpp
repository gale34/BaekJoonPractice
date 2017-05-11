#include <iostream>
#include <fstream>
#include <cstring>

using namespace std;

#define OMG 1
#define NOTHING 0

int max_food = 0;
void check_food_waste(int** food_waste, int x, int y, int n, int m);

int main()
{
    int n, m, n_food;
    int** food_waste;

    ifstream input("input1743.txt");

    input >> n >> m >> n_food;
    //cin >> n >> m >> n_food;

    food_waste = new int[n_food];

    for(int i = 0; i < n_food; i++)
    {
        food_waste[i] = new int[n_food];
        memset(food_waste[i], NOTHING, sizeof(int)*n_food);
    }

    for(int i = 0; i < n_food; i++)
    {
        int a, b;

        input >> a >> b;
        //cin >> a >> b;

        food_waste[a][b] = OMG;
    }


    return 0;
}

void check_food_waste(int** food_waste, int x, int y, int n, int m)
{
    if(food_waste[x][y] >= 1)
    {
        if()

    }
}
