#pragma once

#include<iostream>
#include<queue>
#include<fstream>

using namespace std;

class List{
protected:
    int size;
    const int capacity = 1000;
    priority_queue<int , vector<int> , greater<int>> missNum;
    int maxIndeX;
    List();
    bool isFull();
    bool isEmpty();
public:
    int getSize();
    int getmaxIndex()const; 
    virtual void readMissNumFIle(string namefile);
    virtual void writeMissNumFile(string namefile);
};