#include <iostream>
#include <fstream>
#include <cstring>
using namespace std;

void normal_face(char **face, int n);
void symmetrical_face(char **face, int n);
void vertically_symmetric_face(char **face, int n);

int main()
{
    int n, condition;
    char** face;


    ifstream input("input11586.txt");

    input >> n;
    //cin >> n;

    face = new char*[n];

    for(int i = 0; i < n; i++)
    {
        face[i] = new char[n];
        memset(face[i], 0, sizeof(char)*n);
    }

    for(int i = 0; i < n; i++)
        for(int j = 0; j < n; j++)
        {
            input >> face[i][j];
            //cin >> face[i][j];
        }


    input >> condition;
    //cin >> condition;

    if(condition == 1)
        normal_face(face,n);
    else if(condition == 2)
        symmetrical_face(face,n);
    else if(condition == 3)
        vertically_symmetric_face(face,n);

    //cout << "Hello world!" << endl;
    return 0;
}

void normal_face(char **face, int n)
{
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < n; j++)
            cout << face[i][j];
        if(i == n-1)
            break;
        cout << "\n";
    }
}

void symmetrical_face(char **face, int n)
{
    for(int i = 0; i < n; i++)
    {
        for(int j = n-1; j >= 0; j--)
            cout << face[i][j];
        if(i == n-1)
            break;
        cout << "\n";
    }
}

void vertically_symmetric_face(char **face, int n)
{
    for(int i = n-1; i >= 0; i--)
    {
        for(int j = 0; j < n; j++)
            cout << face[i][j];
        if(i == 0)
            break;
        cout << "\n";
    }
}

