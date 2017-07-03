#include <iostream>

using namespace std;

#define ROYAL 1
#define STRAIGHTFLUSH 2
#define FOURKIND 3
#define FULLHOUSE 4
#define FLUSH 5
#define STRAIGHT 6
#define THREEKIND 7
#define TWOPAIRS 8
#define ONEPAIR 9
#define HIGHCARD 10


int isRoyalStraightFlush(char CombiCard[5][3]);
int isStraightFlush(char CombiCard[5][3]);

int main()
{
    char cards[][3] = {"SA", "SK", "SQ", "SJ", "ST", "S9", "S8", "S7", "S6", "S5", "S4", "S3", "S2",
                        "HA", "HK", "HQ", "HJ", "HT", "H9", "H8", "H7", "H6", "H5", "H4", "H3", "H2",
                        "DA", "DK", "DQ", "DJ", "DT", "D9", "D8", "D7", "D6", "D5", "D4", "D3", "D2",
                        "CA", "CK", "CQ", "CJ", "CT", "C9", "C8", "C7", "C6", "C5", "C4", "C3", "C2"};
    cout << "Hello world!" << endl;
    return 0;
}

int isRoyalStraightFlush(char CombiCard[5][3])
{
    int royalTest[5];
    for(int i = 0; i < 5; i++)
        royalTest[i] = 0;

    if((int)CombiCard[0][0] != (int)CombiCard[1][0])
        return 0;
    else
    {
        if(!isStraightFlush(CombiCard))
            return 0;
        else
        {
            for(int i = 0; i < 5; i++)
            {
                if((int)CombiCard[i][1] == 65) // A
                    royalTest[0]++;
                else if((int)CombiCard[i][1] == 75) // K
                    royalTest[1]++;
                else if((int)CombiCard[i][1] == 81) // Q
                    royalTest[2]++;
                else if((int)CombiCard[i][1] == 74) // J
                    royalTest[3]++;
                else if((int)CombiCard[i][1] == 84) // Ten
                    royalTest[4]++;
            }

            for(int i = 0; i < 5; i++)
            {
                if(royalTest[i] != 1)
                    return 0;
            }

            return ROYAL;
        }

    }
}

int isStraightFlush(char CombiCard[5][3])
{
    if((int)CombiCard[0][0] != (int)CombiCard[1][0])
        return 0;
    else
    {
        if(isStraight(CombiCard) && isFlush(CombiCard))
            return STRAIGHTFLUSH;
        else
            return 0;
    }
}

int isFourKind(char CombiCard[5][3])
{
    int fourKindTest = 0;

    for(int i = 0; i < 5; i++)
    {
        for(int j = 0; j < 5; j++)
        {
            if(i == j)
                continue;
            else
            {
                if((int)CombiCard[i][1] == (int)CombiCard[j][1])
                    fourKindTest++;
            }
        }
        if(fourKindTest == 4)
            return FOURKIND;

        fourKindTest = 0;
    }

    return 0;
}
