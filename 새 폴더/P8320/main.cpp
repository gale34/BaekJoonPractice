#include <iostream>
#include <cmath>

using namespace std;

int makeRect(int n);

int main()
{
    int n;
    int answer = 0;

    cin >> n;

    answer = makeRect(n);

    cout << answer;
    return 0;
}

int makeRect(int n)
{
    int answer = 0;
    int sq = 1;

    if(n == 1)
        return 1;

    answer = makeRect(n-1);

    sq = floor(sqrt(n));

    for(int i = 1; i <= sq; i++)
    {
        if(n % i == 0)
            answer++;
    }

    return answer;
}
