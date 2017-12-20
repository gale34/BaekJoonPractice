#include <iostream>

using namespace std;

int main()
{
    int temp;
    int sum_one = 0;
    int sum_two = 0;

    for(int i = 0; i < 4; i++)
    {
        cin >> temp;
        sum_one += temp;
    }
    for(int i = 0; i < 4; i++)
    {
        cin >> temp;
        sum_two += temp;
    }

    cout << max(sum_one,sum_two) << endl;
    return 0;
}
