
#pragma once
#include <vector>
#include "user.h"
#include "film.h"
#include <math.h>
#include "rcm.h"
#include <iomanip>
#include <string>
#include<vector>
using namespace std;


// chạy chương trình
bool run(listFilm &lF, listUser &lU, int flag , int userId = -1);



// đăng kí, đăng nhập

bool dangky(listUser *lU);
user *dangnhap(listUser *lU);
user *menulogin(listUser &lU);


// các hàm xử lí
void historyUser(int id ,listFilm &lF);

bool deleteuser(user * User , listUser &lU , int maxIndexlistFilm);
void watchFilm(int userid, int filmid, listFilm &lF);
bool search(string namesearch, string namefilm);
void printListUser(vector <int > v , listUser &lU);

film * inputFilm();


// menu xu li
bool menuText(string text, int flag = 1 );
void getStringinMenu(int i, vector<int> recommend, listFilm &lF, string property);
vector<int> menuRecommend(string title, vector<int> recommend, listFilm &lF);



// menu chinh 
bool menuAdmin (user *User , listFilm &lF, listUser &lU);
bool menuUser(user *User, listFilm &lF , listUser &lU);

