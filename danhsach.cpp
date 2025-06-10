#include "danhsach.h"

List::List()
{
    this->size = 0;
    this->maxIndeX = 0;
    
}

bool List::isEmpty()
{
    if (this->size == 0)
        return 1;
    return 0;
}

bool List::isFull()
{
    if (this->size == this->capacity)
        return 1;
    return 0;
}

int List::getSize()
{
    return this->size;
}

int List::getmaxIndex() const
{
    return this->maxIndeX;
}

void List::readMissNumFIle(string filenname)
{
    ifstream ip;
    ip.open(filenname , ios_base ::in);
    int x;
    ip>> x;
    if(x < 1)
        return;
    this->missNum.push(x);
    while (!ip.eof())
    {
        ip>>x;
        this->missNum.push(x);
    }

}

void List::writeMissNumFile(string filename)
{
    ofstream op;
    op.open(filename, ios_base::out);
    if(missNum.empty())
    {
        op<< -1;
        return ;
    }
    bool x= false;
    while (!this->missNum.empty())
    {
        if(x== true)
            op<<"\n";
        x= true;
        op<<this->missNum.top();
        this->missNum.pop();
    }
    
}
