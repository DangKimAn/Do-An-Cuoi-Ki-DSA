
#include "film.h"

film ::film(string name, string time, string category, string director, float rating, string date, string description)
{
    this->name = name;
    this->category = category;
    this->director = director;
    this->rating = rating;
    this->date = date;
    this->time = time;
    this->description = description;
}

film::film(){}

film::~film(){}
string film ::getName() const
{
    return this->name;
}

void film::setName(string name)
{
    this->name = name;
}

string film::getTime() const
{
    return this->time;
}

void film::setTime(string time)
{
    this->time = time;
}

string film::getDescription() const
{
    return this->description;
}

void film::setDescription(string des)
{
    this->description = des;
}

string film ::getDate() const
{
    return this->date;
}

void film::setDate(string date)
{
    this->date = date;
}

string film::getCategory() const
{
    return this->category;
}

void film::setCategory(string category)
{
    this->category = category;
}

string film::getDirector() const
{
    return this->director;
}

void film::setDirector(string director)
{
    this->director = director;
}

float film::getRating() const
{
    return this->rating;
}

void film::setRating(float rating)
{
    this->rating = rating;
}

int film::getID() const
{
    return this->id;
}

void film::setId(int id)
{
    this->id = id;
}

listFilm::listFilm() : List()
{

    for (int i = 0; i <= this->capacity; i++)
        this->arr[i] = NULL;
}

listFilm::~listFilm()
{
    for (int i = 0; i <= this->capacity ; i++)
    {
        if (this->arr[i] != NULL)
        {
            delete this->arr[i];
            this->arr[i] = NULL;
        }
    }
    //delete[] this->arr;
}

bool listFilm ::addFilm(film *p)
{
    system("cls");
    if (this->isFull() == 1)
    {
        cout << "Dung luong da day, khong the them phim nua, vui long xoa bot phim \n\n";
        return 0;
    }

    if (this->missNum.empty())
    {
        p->setId(this->size);
        this->arr[this->size] = p;
        this->size++;
        this->maxIndeX++;
    }
    else
    {
        this->arr[this->missNum.top()] = p;
        this->arr[this->missNum.top()]->setId(this->missNum.top());
        this->size++;
        this->missNum.pop();
    }
    cout << "\n\nChuc mung ban da them phim thanh cong\n\n\t\t";
    system("pause");
    return 1;
}

bool listFilm::deleteFilm(int id)
{
    if (this->isEmpty())
        return 0;
    delete this->arr[id] ;
    this->arr[id] = NULL;
    this->missNum.push(id);
    this->size--;
    return 1;
}

film *listFilm::getElementatIndex(int i)
{
    return this->arr[i];
}

bool listFilm ::setElementatIndex(int i, film *f)
{
    this->arr[i] = f;
    this->size++;
    if (this->maxIndeX < i)
        this->maxIndeX = i;
    return 1;
}

void listFilm::readFilm(string namefile)
{
    ifstream ip;
    ip.open(namefile, ios_base::in);
    while (!ip.eof())
    {
        string name, time, category, director, date, des, imDb, index;
        getline(ip, name);
        getline(ip, time);
        getline(ip, category);
        getline(ip, director);
        getline(ip, imDb);
        getline(ip, date);
        getline(ip, des);
        getline(ip, index);
        film *p = new film(name, time, category, director, stof(imDb), date, des);
        p->setId(stoi(index));
        this->setElementatIndex(stoi(index), p);
    }
}

void listFilm::writeFilm(string namefile)
{
    ofstream op;
    bool x = true;
    op.open(namefile, ios::out);
    for (int i = 0; i <= this->getmaxIndex(); i++)
    {
        if (this->arr[i] != NULL)
        {
            if (x == false)
                op << "\n";
            x = false;
            op << this->arr[i]->getName() << "\n";
            op << this->arr[i]->getTime() << "\n";
            op << this->arr[i]->getCategory() << "\n";
            op << this->arr[i]->getDirector() << "\n";
            op << this->arr[i]->getRating() << "\n";
            op << this->arr[i]->getDate() << "\n";
            op << this->arr[i]->getDescription() << "\n";
            op << this->arr[i]->getID();
        }
    }
}
