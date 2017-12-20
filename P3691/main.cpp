#include <iostream>
#include <string>
#include <vector>
#include <cstdio>

using namespace std;

int getMaxQuality(vector<vector<pair<int,int> > > partsList, int x, int b);

int main()
{
    //freopen("input.txt","r",stdin);

    int t;

    cin >> t;

    for(int i = 0; i < t; i++)
    {
        vector<vector<pair<int,int> > > partsList;

        int n, b;
        string type, name;
        int price, quality;

        string temp = "";
        vector<pair<int,int> > tempList;

        int answer = 0;

        cin >> n >> b;

        for(int j = 0; j < n; j++)
        {
            cin >> type >> name >> price >> quality;
            if(j == 0)
                temp = type;

            if(temp.compare(type) != 0)
            {
                partsList.push_back(tempList);
                tempList.clear();
            }
            tempList.push_back(make_pair(price,quality));
            temp = type;
        }
        partsList.push_back(tempList);

        /*for(int j = 0; j < partsList.size(); j++)
        {
            for(int k = 0; k < partsList[j].size(); k++)
                cout << partsList[j][k].first << ":" << partsList[j][k].second << " ";
            cout << endl;
        }*/
        answer = getMaxQuality(partsList,0,b);

        cout << answer << endl;
    }
    return 0;
}

int getMaxQuality(vector<vector<pair<int,int> > > partsList, int x, int b)
{
    int answer = 1000000001;

    while(partsList[x].size() == 1 && x >= partsList.size())
    {
        b -= partsList[x][0].first;
        answer = min(answer,partsList[x][0].second);
        if(b < 0)
            return answer;
        x++;
    }

    if(x >= partsList.size())
        return answer;

    answer = min(0,answer);
    for(int i = 0; i < partsList[x].size(); i++)
    {
        int temp = 1000000001;
        b -= partsList[x][i].first;
        if(b < 0)
        {
            b += partsList[x][i].first;
            continue;
        }
        temp = min(partsList[x][i].second, getMaxQuality(partsList,x+1,b));
        answer = max(temp,answer);

        b += partsList[x][i].first;
    }

    return answer;
}
