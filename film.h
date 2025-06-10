#pragma once

#include<iostream>
#include <map>
#include<queue>
#include "danhsach.h"
#include"fstream"
using namespace std;

class film{
    string name;
    string category;
    string director;
    float rating;
    int id;
    string date;   
    string time;
    string description;
public:
    film();
    film(string name, string tirme , string category , string director , float rating,string date, string description );
    ~film();
    string getName() const;

    void setName(string name);
    
    string getTime() const;
    
    void setTime(string time);

    string getDate() const;

    void setDate(string date);

    string getCategory() const;

    void setCategory(string category);
    
    string getDirector() const;

    void setDirector(string director);
    
    float getRating() const;

    void setRating(float rating);

    int getID() const;

    void setId(int);

    string getDescription()const;

    void setDescription(string des);

};

class listFilm : public List{  
    film *arr[1001];
public:  
    listFilm();
    ~listFilm();
    film *getElementatIndex(int i );
    bool setElementatIndex(int , film *f);
    bool addFilm(film * p);
    bool deleteFilm(int id);
    void readFilm(string namefile);
    void writeFilm(string namefile);
};
