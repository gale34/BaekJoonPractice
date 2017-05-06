#include <iostream>
#include <fstream>
#include <cstring>

using namespace std;

long long count_num = 0;

void count_equality(int *number, int k, int result, int n);

int main()
{
    int n;
    int* number;

    ifstream input("input5557.txt");

    //input >> n;

    cin >> n;

    number = new int[n];
    memset(number, 0, sizeof(int)*(n));


    for(int i = 0; i < n; i++)
    {
        //input >> number[i];
        cin >> number[i];
    }

    count_equality(number,0,0,n);

    cout << count_num;

    delete [] number;

    return 0;
}

void count_equality(int *number, int k, int result, int n)
{
    if(k == 0)
        result = number[k];
    else if(k == n-1)
    {
        if(result == number[k])
            count_num++;
        return ;
    }
    else
        result += number[k];

    //cout << result;

    if(result >= 0 && result <= 20 && (result + number[k+1] <= 20 || result - number[k+1] >= 0))
        count_equality(number, k+1, result, n);

    result -= (number[k] * 2);
    if(result >= 0 && result <= 20 && (result + number[k+1] <= 20 || result - number[k+1] >= 0))
        count_equality(number, k+1, result, n);

    return ;
}
