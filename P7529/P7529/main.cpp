#include <iostream>
#include <string>
#include <cstdio>
#include <cmath>
#include <iomanip>

#define CHANCE_8 0
#define CHANCE_4 1
#define CHANCE_2 2
#define CHANCE_1 3

using namespace std;

void inputData(string* countryList,double** probabilityList);
void calProbWin(string* countryList,double** probabilityList, double** probabilityToWin);

int main()
{

    freopen("input.txt","r",stdin);

    int n;
    string* countryList = new string[16];
    double** probabilityList = new double*[16];

    double** probabilityToWin = new double*[4];

    for(int i = 0; i < 16; i++)
    {
        probabilityList[i] = new double[16];
        if(i < 4)
            probabilityToWin[i] = new double[16];
    }

    cin >> n;

    for(int i = 0; i < n; i++)
    {
        int str_length = 0;

        inputData(countryList,probabilityList);

        cout << "Scenario #" << i+1 << ":" << endl;

        calProbWin(countryList,probabilityList,probabilityToWin);

        cout << fixed;
        //cout << setw(17);
        cout.precision(2);


        for(int j = 0; j < 16; j++)
        {
            str_length = 0;
            str_length += countryList[j].length();

            /*if(probabilityToWin[3][j]*100 >= 10.0)
                str_length += 4;
            else
                str_length += 3;*/

            cout << countryList[j] << setfill(' ') << setw(17-str_length) << probabilityToWin[3][j]*100 << endl;
        }

        cout << endl;
    }

    //delete countryList;

    for(int i = 0; i < 16; i++)
    {
        delete [] probabilityList[i];

        if(i < 4)
            delete [] probabilityToWin[i];
    }
    delete [] probabilityToWin;
    delete [] probabilityList;
    return 0;
}

void inputData(string* countryList,double** probabilityList)
{
    for(int i = 0; i < 16; i++)
        cin >> countryList[i];

    for(int i = 0; i < 16; i++)
    {
        int temp = 0;
        for(int j = 0; j < 16; j++)
        {
            cin >> temp;
            probabilityList[i][j] = (double)temp/100;
        }

    }
}

void calProbWin(string* countryList,double** probabilityList,double** probabilityToWin)
{
    for(int i = 0; i < 4; i++)
    {
        for(int j = 0; j < 16; j++)
        {

            int target = 0;
            int temp = pow(2,i+1);
            int temp2 = pow(2,i);

            if((j%temp) < temp2)
                target = (j/temp) * temp  + temp2;
            else
                target = (j/temp) * temp;

            if(i == 0)
                probabilityToWin[i][j] = probabilityList[j][target];
            else
            {
                probabilityToWin[i][j] = 0;
                for(int k = 0; k < temp2; k++)
                    probabilityToWin[i][j] += probabilityToWin[i-1][target+k]*probabilityList[j][target+k];

                probabilityToWin[i][j] *= probabilityToWin[i-1][j];
            }

        }

    }
}
