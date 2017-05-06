#include <iostream>
#include <fstream>
#include <cstring>

using namespace std;

int main()
{
    int n,b,h,w;
    int** hotel;
    int hotel_fee = 500001;
    int temp = 0;

    ifstream input("input1.txt");

    input >> n >> b >> h >> w;
    //cin >> n >> b >> h >> w;

    hotel = new int*[h];

    for(int i = 0; i < h; i++)
    {
        hotel[i] = new int[w+1];
        memset(hotel[i], 0, sizeof(int)*(w+1));
    }

    for(int i = 0; i < h; i++)
    {
        input >> hotel[i][0];
        //cin >> hotel[i][0];

        for(int j = 1; j < w+1; j++)
        {
            input >> hotel[i][j];
            //cin >> hotel[i][j];
        }

    }

    for(int i = 0; i < h; i++)
    {
        temp = 0;
        for(int j = 1; j <= w; j++)
        {
            temp = n * hotel[i][0];
            if(hotel[i][j] >= n && temp <= b && temp < hotel_fee)
            {
                hotel_fee = temp;
                break;
            }
        }
    }

    if(hotel_fee == 500001)
        cout << "stay home";
    else
        cout << hotel_fee;

    for(int i = 0; i < h; i++)
        delete [] hotel[i];
    delete [] hotel;

    return 0;
}
