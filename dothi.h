#pragma  once 
#include<iostream>
#include<fstream>
#include "user.h"
#include "film.h"

using namespace std ;

// gioi han 1000 user , 1000 fimlm
// 1- 999 bieu thi cho 1000 user 
// moi hang bieu dien cho 1000 film id 1 -> 9999

// giao diem graph[i][j] =1  => id i da xem film j 
// 0 => i chua xem film j 
extern int graph[1001][1001];
// mang recommend bieu dien film co duoc de xuat cho nguoi dung hay khong 
// recommend[i] = 0 => film thu i khong duoc de xuat cho nguoi dung
// recommend[i] !=0 => film thu i co the duoc de xuat cho nguoi dung 
// recommend[i] !+ 0 va cang nho, ti le de xuat cang cao 


// rcm bieu dien cac film se duoc de xuat cho user co id i 
void readHistory(listFilm &lF , listUser &lU);
void writeHistory(string filename);
user * readCurr(string filename , listUser &lU);
void writeCurr(string filename , user *u ); 