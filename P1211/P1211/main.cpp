#include <iostream>
#include <vector>

using namespace std;

vector<long long> tenDigits;

long long getSPsInRange(long long a, long long b);
long long getSP(long long number);
long long getSP(long long number, long long b);


int main()
{
    long long a, b;
    long long temp;
    int n = 0;
    long long answer = 0;

    cin >> a >> b;

    temp = 1;
    for(int i = 0; i < 19; i++)
    {
        tenDigits.push_back(temp);
        temp *= 10;
    }

    answer = getSPsInRange(a,b);

    cout << answer << endl;

    return 0;
}

long long getSPsInRange(long long a, long long b)
{
    long long start = 0;
    long long last = 0;

    long long startTemp = 0;

    long long answer = 0;

    for(int i = 0; i < 18; i++)
    {
        startTemp += tenDigits[i];
        //cout << startTemp << endl;

        if(start == 0 && getSP(startTemp) <= a && a <= getSP(tenDigits[i+1] - 1))
            start = startTemp;

        if(b < getSP(startTemp))
            last = tenDigits[i] - 1;
        else if(b == getSP(startTemp))
            last = startTemp;

        if(start != 0 && last != 0)
            break;
    }

    //cout << start << " " << last << endl;

    while(start <= last)
    {
        long long SP = getSP(start,b);

        if(SP >= a && SP <= b)
            answer++;
        start++;
    }

    return answer;
}

long long getSP(long long number)
{
    long long target = number;
    long long answer = number;

    while(target > 0)
    {
        answer *= target % 10;
        target /= 10;

        if(answer <= 0)
            return 0;
    }

    return answer;
}

long long getSP(long long number, long long b)
{
    long long target = number;
    long long answer = number;

    while(target > 0)
    {
        answer *= target % 10;
        target /= 10;

        if(answer <= 0)
            return 0;
        if(answer > b)
            return 0;
    }

    return answer;
}
