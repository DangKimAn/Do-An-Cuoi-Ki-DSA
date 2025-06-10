#include "rcm.h"

const int capacityofRcmByNeighbor = 8;
const int capacityofRcmByNewest = 8;
int recommendbyNeighborRank[1001];

void dfs(int id , int val , bool horizontal)
{
    if(horizontal)
    {
        for (int j = 1; j<=1000; j++)
        {
            if(graph[id][j] == 1 && (recommendbyNeighborRank[j] > val || recommendbyNeighborRank[j] ==0))
            {
                recommendbyNeighborRank[j] = val;
                dfs(j , val + 1 , 0);
            }
        }
    }
    else 
    {
        for(int i  = 1  ; i<=1000 ;i++)
        {
            if(graph[i][id] == 1)
            {
                dfs(i , val , 1);
            }
        }
    }

}



vector<int> rcmbyNeighbor(int userId , listFilm &lF)
{
    vector<int> recommendByNeighbor;
    for(int i  = 0; i <= lF.getmaxIndex() ; i++ )
        recommendbyNeighborRank[i] =0;

    dfs(userId , 1, 1);
   
    for (int i = 0; i <= lF.getmaxIndex(); i++)
    {
        if (recommendbyNeighborRank[i] > 1)
            recommendbyNeighborRank[i] = recommendbyNeighborRank[i]*1000 +i;
        else 
            recommendbyNeighborRank[i]= (int)1e9+7;
    }
    
   for(int i  =  0 ; i <= lF.getmaxIndex() ; i++)
   {
    for (int j = i ; j <= lF.getmaxIndex();j++)
        if(recommendbyNeighborRank[i] > recommendbyNeighborRank[j])
        {
            int t = recommendbyNeighborRank[i];
            recommendbyNeighborRank[i] = recommendbyNeighborRank[j];
            recommendbyNeighborRank[j] =t;
        }
   }
    for (int i = 0 ; i <= capacityofRcmByNeighbor ; i++)
    {
        if(recommendbyNeighborRank[i] == (int)(1e9+7))
            return recommendByNeighbor;
        recommendByNeighbor.push_back(recommendbyNeighborRank[i]%1000);
    }

    return recommendByNeighbor;
}

int indexofVectorhasMindate(vector <int> input, listFilm &lF)
{
    int index = 0;
    for (int i = 1  ;i < input.size() ;i++)
    {
        if (lF.getElementatIndex(input[i])->getDate() < lF.getElementatIndex(input[index])->getDate())
            index = i; 
    }
    return index;
}



vector<int> rcmbyNewest(listFilm &lF)
{
    int  indexminDate;
    vector<int> rs;
    for (int i = 0 ; i<=lF.getmaxIndex() ;i++)
    {
        if (rs.size() <= capacityofRcmByNewest && lF.getElementatIndex(i) != NULL)
        {
            rs.push_back(i);
            if (rs.size() == capacityofRcmByNewest)
                indexminDate = indexofVectorhasMindate(rs, lF);
        }
        else if (lF.getElementatIndex(i) != NULL) 
        {
            if (lF.getElementatIndex(rs[indexminDate])->getDate() < lF.getElementatIndex(i)->getDate())
            {
                rs[indexminDate] = i;
                indexminDate = indexofVectorhasMindate(rs, lF);
            }
        }
    }
    return rs;
}

