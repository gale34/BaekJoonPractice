#include <iostream>
#include <vector>
#include <cstring>

using namespace std;

bool isPalindrome(vector<int>& number);
void makeNNumber(vector<int> number,vector<int>& answer, int n);

int main()
{
    string n;
    vector<int> number;
    int countPalindrome = 0;

    cin >> n;

    number.reserve(n.size());
    for(int i = 0; i < n.size(); i++)
        number.push_back((int)(n.at(i) - 48));


    for(int i = 2; i < 11; i++)
    {
        if(i != 10)
        {
            vector<int> answer;
            makeNNumber(number,answer,i);

            if(isPalindrome(answer))
            {
                countPalindrome++;
                cout << i << " ";

                for(vector<int>::reverse_iterator rit = answer.rbegin(); rit != answer.rend(); rit++)
                    cout << *rit;

                cout << endl;
            }
            vector<int>().swap(answer);
        }
        else
        {
            if(isPalindrome(number))
            {
                countPalindrome++;
                cout << i << " ";

                for(vector<int>::reverse_iterator rit = number.rbegin(); rit != number.rend(); rit++)
                    cout << *rit;

                cout << endl;
            }
            vector<int>().swap(number);
        }

    }

    if(countPalindrome == 0)
        cout << "NIE";
    return 0;
}


void makeNNumber(vector<int> number,vector<int>& answer, int n)
{
    answer.reserve(number.size()*4);
    while(1)
    {
        vector<int> nextPortion;
        int next = 0;
        int idx = 0;
        int countR = 0;

        for(int i = 0; i < (int)number.size(); i++)
        {
            nextPortion.push_back(0);

            number[i] += next*10;
            next = number[i] % n;
            nextPortion[i] = number[i] / n;
        }

        answer.push_back(next);

        for(idx = 0; idx < nextPortion.size(); idx++)
        {
            if(nextPortion[idx] != 0)
                break;
            else
                countR++;
        }

        if(countR != 0)
            nextPortion.erase(nextPortion.begin(),nextPortion.begin()+countR);

        if((int)nextPortion.size() == 1 && nextPortion[0] < n)
        {
            answer.push_back(nextPortion[0]);
            break;
        }
        else if(nextPortion.empty() && next < n)
            break;

        vector<int>().swap(number);
        number = nextPortion;
        vector<int>().swap(nextPortion);
    }
    return ;
}

bool isPalindrome(vector<int>& number)
{
    int mid = ((int)number.size() - 1) / 2;

    for(int i = 0; i <= mid; i++)
    {
        if(number[i] != number[(int)number.size() - i - 1] )
            return false;
    }

    return true;
}
