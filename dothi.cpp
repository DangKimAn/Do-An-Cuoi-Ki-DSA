
#include "dothi.h"
int graph[1001][1001];
void readHistory(listFilm &lF , listUser &lU)
{
    ifstream ip;
    ip.open("data/history.txt", ios_base::in);
    while (!ip.eof())
    {
        int i, j;
        ip >> i >> j;
        if(i>1000 || j>1000 || i<0 || j<0)
            return;
        if (lF.getElementatIndex(j) != NULL && lU.getUseratIndex(i) != NULL )
            graph[i][j] = 1;
    }
    ip.close();
}

void writeHistory(string filename)
{
    ofstream op;
    bool x =1;
    op.open(filename, ios_base::out);
    for (int i = 1; i <= 1000; i++)
    {
        for (int j = 1; j <= 1000; j++)
            if (graph[i][j] == 1)
            {
                if(x!= 1)
                    op<<"\n";
                x=0;
                op << i << "  " << j ;
                graph[i][j] = 0;
            }
    }
    op.close();
}


user *readCurr(string filename, listUser &lU)
{
    ifstream ip;
    ip.open(filename, ios_base::in);
    int cf;
    ip >> cf;
    if (cf < 0 || cf > 1000)
        return NULL;
    ip.close();
    return lU.getUseratIndex(cf);
}

void writeCurr(string filename, user *u)
{
    ofstream op;
    op.open(filename, ios_base::out);
    if (u == NULL)
        op << -1;
    else
        op << u->getId();
    op.close();
}
