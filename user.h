#pragma once
#include<iostream>
#include "danhsach.h"
#include <fstream>
#include<string>
#include<map>
#include<queue>
using namespace std;

class user{
    string username;
    string password;
    bool Admin;
    int id;



public:

    user();
     
    user(string username ,string password , bool isAdmin );

    string getUsername() const;

    void setUsername(string username);
    
    bool isAdmin()const;

    int getId() const;

    void setId(int);

    string getPaasword () const;

    void setPassword(string password);
    ~user();
    
};

class listUser : public List {  
    user *arr[1001];    
public: 
    listUser();
    ~listUser();
    int addUser(user * p);
    bool deleteUser(int id);
    user *login(string , string);
    user *getUseratIndex(int i );
    bool setUseratIndex(int i , user *u);
    void readUser(string namefile);
    void writeUser(string namefile);
};  

