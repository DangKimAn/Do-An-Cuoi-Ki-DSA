#pragma once
#include "iostream"
#include "dothi.h"
#include<algorithm>
#include<vector>
using namespace std ;


void dfs(int id , int val , bool horizontal);
vector<int> rcmbyNeighbor(int userId , listFilm &lF);
int indexofVectorhasMindate(vector <int> input, listFilm &lF);
vector<int> rcmbyNewest(listFilm &lF);