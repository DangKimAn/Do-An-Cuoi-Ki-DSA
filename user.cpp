
#include "user.h"

user ::user(string username, string password, bool isAdmin)
{
    this->username = username;
    this->password = password;
    this->Admin = isAdmin;
}
user::user() {};
bool user::isAdmin() const { return this->Admin; }
string user::getUsername() const
{
    return this->username;
}

void user::setUsername(string username)
{
    this->username = username;
}

string user::getPaasword() const
{
    return this->password;
}

void user::setPassword(string password)
{
    this->password = password;
}

user::~user() {}

int user::getId() const
{
    return this->id;
}

void user::setId(int id)
{
    this->id = id;
}

listUser::listUser() : List()
{
    for (int i = 0; i <= this->capacity; i++)
        this->arr[i] = NULL;
}

listUser::~listUser()
{
    for (int i = 0; i <= this->capacity; ++i)
    {
        if (arr[i] != NULL)
        {
            delete arr[i];
            arr[i] = NULL;
        }
    }
}

// tra ve 3 trang thai
//  0. dang ki khong thanh cong
// 1. dang ky  thanh cong
// 2. kenh da  day
int listUser ::addUser(user *p)
{

    system("cls");
    if (this->isFull() == 1)
    {
        cout << "So luong nguoi dung da day, vui long quay lai dang ki sau";
        return 2;
    }
    for (int i = 0; i <= this->maxIndeX; i++)
    {
        if (this->arr[i] != NULL && this->arr[i]->getUsername() == p->getUsername())
        {
            cout << "username nay da ton tai, vui long nhap username khac\n";
            return 0;
        }
    }

    if (this->missNum.empty())
    {
        this->arr[this->size] = p;
        this->arr[this->size]->setId(this->size);
        this->size++;
        this->maxIndeX++;
    }
    else
    {
        this->arr[this->missNum.top()] = p;
        this->size++;
        this->arr[this->missNum.top()]->setId(this->missNum.top());
        this->missNum.pop();
    }
    cout << "Chuc mung ban da dang ki thanh cong\n";
    // cout <<"Vui long nhan 'Enter' de tiep tuc \n";
    return 1;
}

bool listUser::deleteUser(int id)
{
    if (this->isEmpty())
        return 0;
    if(this->getUseratIndex(id) == NULL)
        return 0;
    delete this->arr[id];
    this->arr[id] = NULL;
    this->missNum.push(id);
    this->size--;
    return 1;
}

user *listUser::login(string username, string password)
{
    system("cls");
    for (int i = 0; i <= this->maxIndeX; i++)
    {
        if (this->arr[i] != NULL && this->arr[i]->getUsername() == username && this->arr[i]->getPaasword() == password)
        {
            cout << "Chuc mung ban, dang nhap thanh cong!\n";
            system("pause");
            return this->arr[i];
        }
        else if (this->arr[i] != NULL && this->arr[i]->getUsername() == username && this->arr[i]->getPaasword() != password)
        {
            cout << "Sai mat khau, vui long nhap lai mat khau.\n";
            return NULL;
        }
    }

    cout << "Ten dang nhap khong ton tai, vui long nhap lai ten dang nhap\n";
    return NULL;
}

user *listUser::getUseratIndex(int i)
{
    return this->arr[i];
}
bool listUser::setUseratIndex(int i, user *u)
{
    this->arr[i] = u;
    this->size++;
    if (this->maxIndeX < i)
        this->maxIndeX = i;
    return 1;
}

void listUser::readUser(string namefile)
{
    ifstream ip;
    ip.open(namefile, ios_base::in);
    while (!ip.eof())
    {
        string username;
        string password;
        bool admin;
        int index;
        ip >> username >> password >> admin >> index;
        user *p = new user(username, password, admin);
        p->setId(index);
        this->setUseratIndex(index, p);
    }
}

void listUser::writeUser(string namefile)
{
    ofstream op;
    op.open(namefile, ios_base::in);
    bool x = true;
    for (int i = 0; i <= this->getmaxIndex(); i++)
    {
        if (this->arr[i] != NULL)
        {
            if (x == 0)
                op << "\n";
            x = 0;
            op << this->arr[i]->getUsername() << "\n";
            op << this->arr[i]->getPaasword() << "\n";
            op << this->arr[i]->isAdmin() << "\n";
            op << this->arr[i]->getId();
        }
    }
}