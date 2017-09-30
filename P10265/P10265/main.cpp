#include <iostream>
#include <vector>
#include <cstring>
#include <algorithm>

using namespace std;

int getPassengerNumber(int* memory, int* visited, int** friendship, int idx, int n);
void cycleDFS(int* memory,int** friendship, int idx, int n, int answer);
void splitComponents(int* memory,int* visited,int** friendship,int idx, vector<int>& components, int n);
int calMaxAnswer(vector<vector<int> >& components,int k, int sum, int idx);

int cycleNumber = 0;

int main()
{
    int n,k;
    int** friendship;
    int* visited;
    int* memory;
    int answer = 0;

    vector<vector<int> > components;

    cin >> n >> k;

    friendship = new int*[n+1];
    visited = new int[n+1];
    memory = new int[n+1];
    memset(memory,0,sizeof(int)*(n+1));
    memset(visited,0,sizeof(int)*(n+1));

    for(int i = 0; i < n+1; i++)
    {
        friendship[i] = new int[n+1];
        memset(friendship[i],0,sizeof(int)*(n+1));
    }

    for(int i = 1; i < n+1; i++)
    {
        int temp;
        cin >> temp;

        friendship[i][temp] = 1;
        friendship[i][0]++;
        friendship[0][temp]++;
    }

    /*for(int i = 0; i < n+1; i++)
    {
        for(int j = 0; j < n+1; j++)
            cout << friendship[i][j] << " ";
        cout << endl;
    }*/

    for(int i = 1; i < n+1; i++)
        getPassengerNumber(memory,visited,friendship,i,n);

    memset(visited,0,sizeof(int)*(n+1));
    for(int i = 1; i < n+1; i++)
    {
        vector<int> one;
        if(visited[i] == 0)
            splitComponents(memory,visited,friendship,i,one,n);
        if(!one.empty())
            components.push_back(one);
    }

    for(int i = 0; i < (int)components.size(); i++)
    {
        sort(components[i].begin(),components[i].end(),greater<int>());

        for(int j = 0; j < (int)components[i].size(); j++)
            cout << components[i][j] << " ";
        cout <<endl;
    }

    int maxAnswer = 0;
    while()
    {
        vector<int>::iterator it;

        for(int i = 0; i < (int)components.size(); i++)
        {
            if(maxAnswer < components[i].begin())
            {
                it = components[i].begin();
                maxAnswer = *it;
            }
        }

        if(maxAnswer < k)
        {

        }

    }



    //cout << endl;

    cout << answer << endl;
    return 0;
}

int getPassengerNumber(int* memory, int* visited, int** friendship, int idx, int n)
{
    int& answer = memory[idx];


    if(answer != 0)
        return answer;
    visited[idx] = 1;

    for(int i = 1; i < n+1; i++)
    {
        //cout << "test " << idx <<  ": " << answer << " " << i << endl;

        if(idx != i && visited[i] == 1 && friendship[idx][i] == 1)
        {
            //cout << idx << " cycle detect! " << i << endl;
            cycleNumber = i;
            answer += memory[i];
            break;
        }
        else if(visited[i] == 0 && friendship[idx][i] == 1)
        {
            //cout << idx << " edge detect! " << i << endl;
            answer += getPassengerNumber(memory,visited,friendship,i,n);
            break;
        }
    }

    answer++;

    if(cycleNumber == idx)
    {
        cycleDFS(memory,friendship,idx,n,answer);
        cycleNumber = 0;
    }

    return answer;
}

void cycleDFS(int* memory,int** friendship, int idx, int n, int answer)
{
    memory[idx] = answer;
    for(int i = 1; i < n+1; i++)
    {
        if(idx != i && friendship[idx][i] == 1 && memory[i] != answer)
        {
            //cout << idx << " cycle update! " << i << endl;
            cycleDFS(memory,friendship,i,n,answer);
            break;
        }
    }

}

void splitComponents(int* memory,int* visited,int** friendship,int idx, vector<int>& components, int n)
{
    visited[idx] = 1;

    for(int i = 1; i < n+1; i++)
    {
        if(visited[i] == 0 && (friendship[idx][i] == 1 || friendship[i][idx] == 1))
            splitComponents(memory,visited,friendship,i,components,n);

    }

    components.push_back(memory[idx]);
    return ;
}

int calMaxAnswer(vector<vector<int> >& components,int k, int sum, int idx)
{
    if(idx == (int)components.size())
        return 0;
    int answer = 0;

    for(int i = 0; i < (int)components[idx].size(); i++)
    {
        answer = components[idx][i];

        if(answer > k)
        answer += calMaxAnswer(components,k,)

    }
}
