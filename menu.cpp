#include "menu.h"
vector<int> allFilmRcmtoUser;

bool dangky(listUser *lU)
{
    while (true)
    {
        system("cls");
        string username, password;
        cout << "username: ";
        cin >> username;
        cout << "password: ";
        cin >> password;
        user *u = new user(username, password, 0);
        int kq = lU->addUser(u);
        if (kq == 1)
        {
            system("pause");
            return 1;
        }
        if (kq == 2)
        {
            system("pause");
            return 0;
        }
        bool check = menuText("      nhap lai     ", 1);
        system("cls");
        if (check == 0)
            return 0;
    }

    return 0;
}

user *dangnhap(listUser *lU)
{
    system("cls");
    user *u = NULL;
    while (true)
    {
        string username, password;
        cout << "username: ";
        cin >> username;
        cout << "password: ";
        cin >> password;
        u = lU->login(username, password);

        if (u != NULL)
        {
            return u;
        }
        bool check = menuText("      nhap lai     ", 1);
        system("cls");
        if (check == 0)
            return NULL;
    }
    return u;
}

user *menulogin(listUser &lU)
{
    char select;

    do
    {
        system("cls");
        cout << "+----------------------------------------------------------------------------+\n";
        cout << "|                        MENU DANG NHAP - DANG KY                            |\n";
        cout << "|                                                                            |\n";
        cout << "|        [1] DANG NHAP           [2] DAMG KI            [0] THOAT            |\n";
        cout << "|                                                                            |\n";
        cout << "+----------------------------------------------------------------------------+\n\n\n";
        cout << "Vui long nhap lua chon cua ban     :  ";

        cin >> select;
        if (select == '1')
        {
            user *u = dangnhap(&lU);
            if (u != NULL)
                return u;
        }
        else if (select == '2')
            dangky(&lU);
        else if (select != '0')
        {
            system("cls");
            cout << "Lua chon cua ban sai , vui long nhap lua chon phu hop honn\n\n";
            bool check = menuText("      nhap lai     ", 1);
            system("cls");
            if (check == 0)
                return NULL;
        }
    } while (select != '0');

    return NULL;
}

void getStringinMenu(int i, vector<int> recommend, listFilm &lF, string property)
{
    if (i >= recommend.size())
    {
        cout << "                          ";
        return;
    }

    if (property == "id")
    {
        if (recommend[i] < 10)
            cout << "            " << recommend[i] << "             ";
        else if (recommend[i] < 100)
            cout << "            " << recommend[i] << "            ";
        else if (recommend[i] < 1000)
            cout << "           " << recommend[i] << "            ";
        else if (recommend[i] == 1000)
            cout << "           " << recommend[i] << "           ";
    }

    if (property == "name")
    {
        cout << "  TEN : " << setw(16) << left << lF.getElementatIndex(recommend[i])->getName().substr(0, 16) << "  ";
    }

    else if (property == "time")
    {
        cout << "  THOI LUONG : " << setw(9) << left << lF.getElementatIndex(recommend[i])->getTime().substr(0, 9) << "  ";
    }

    else if (property == "category")
    {
        cout << "  THE LOAI : " << setw(11) << left << lF.getElementatIndex(recommend[i])->getCategory().substr(0, 11) << "  ";
    }

    else if (property == "directory")
    {
        cout << "  TAC GIA : " << setw(12) << left << lF.getElementatIndex(recommend[i])->getDirector().substr(0, 12) << "  ";
    }

    else if (property == "rating")
    {
        cout << "  DANH GIA : " << setw(11) << left << lF.getElementatIndex(recommend[i])->getRating() << "  ";
    }

    else if (property == "date")
    {
        cout << "  CONG CHIEU :" << setw(9) << left << lF.getElementatIndex(recommend[i])->getDate() << "  ";
    }

    return;
}

vector<int> menuRecommend(string title, vector<int> recommend, listFilm &lF)
{
    cout << "\n"
         << title << " :\n\n";
    for (int i = 0; i < recommend.size(); i += 3)
    {
        cout << "+----------------------------------------+----------------------------------------+----------------------------------------+\n";
        cout << "|      ____________________________      |      ____________________________      |      ____________________________      |\n";
        cout << "|      |                          |      |      |                          |      |      |                          |      |\n";
        cout << "|      |";
        getStringinMenu(i, recommend, lF, "id");
        cout << "|      |      |";
        getStringinMenu(i + 1, recommend, lF, "id");
        cout << "|      |      |";
        getStringinMenu(i + 2, recommend, lF, "id");
        cout << "|      |\n";
        cout << "|      |                          |      |      |                          |      |      |                          |      |\n";
        cout << "|      |";
        getStringinMenu(i, recommend, lF, "name");
        cout << "|      |      |";
        getStringinMenu(i + 1, recommend, lF, "name");
        cout << "|      |      |";
        getStringinMenu(i + 2, recommend, lF, "name");
        cout << "|      |\n";
        cout << "|      |";
        getStringinMenu(i, recommend, lF, "time");
        cout << "|      |      |";
        getStringinMenu(i + 1, recommend, lF, "time");
        cout << "|      |      |";
        getStringinMenu(i + 2, recommend, lF, "time");
        cout << "|      |\n";
        cout << "|      |";
        getStringinMenu(i, recommend, lF, "category");
        cout << "|      |      |";
        getStringinMenu(i + 1, recommend, lF, "category");
        cout << "|      |      |";
        getStringinMenu(i + 2, recommend, lF, "category");
        cout << "|      |\n";
        cout << "|      |";
        getStringinMenu(i, recommend, lF, "directory");
        cout << "|      |      |";
        getStringinMenu(i + 1, recommend, lF, "directory");
        cout << "|      |      |";
        getStringinMenu(i + 2, recommend, lF, "directory");
        cout << "|      |\n";
        cout << "|      |";
        getStringinMenu(i, recommend, lF, "rating");
        cout << "|      |      |";
        getStringinMenu(i + 1, recommend, lF, "rating");
        cout << "|      |      |";
        getStringinMenu(i + 2, recommend, lF, "rating");
        cout << "|      |\n";
        cout << "|      |";
        getStringinMenu(i, recommend, lF, "date");
        cout << "|      |      |";
        getStringinMenu(i + 1, recommend, lF, "date");
        cout << "|      |      |";
        getStringinMenu(i + 2, recommend, lF, "date");
        cout << "|      |\n";
        cout << "|      |__________________________|      |      |__________________________|      |      |__________________________|      |\n";
        cout << "|                                        |                                        |                                        |\n";
        cout << "+----------------------------------------+----------------------------------------+----------------------------------------+\n";
    }
    return recommend;
}

void watchFilm(int userid, int filmid, listFilm &lF)
{
    system("cls");

    cout << "     TEN : " << lF.getElementatIndex(filmid)->getName() << "\n";

    cout << "     THOI LUONG : " << lF.getElementatIndex(filmid)->getTime() << "\n";

    cout << "     THE LOAI : " << lF.getElementatIndex(filmid)->getCategory() << "\n";

    cout << "     TAC GIA : " << lF.getElementatIndex(filmid)->getDirector() << "\n";

    cout << "     DANH GIA : " << lF.getElementatIndex(filmid)->getRating() << "\n";

    cout << "     CONG CHIEU : " << lF.getElementatIndex(filmid)->getDate() << "\n";

    cout << "     MO TA :  " << lF.getElementatIndex(filmid)->getDescription() << "\n";

    bool select = menuText("      xem phim     ", 1);
    if (select == 0)
        return; 
    graph[userid][filmid] = 1;
    system("cls");
    cout << "\n\n\n\n\n\n\n\n\n                         DA XEM \n\n\n\n\n\n\n\n\n";
}

bool search(string namesearch, string namefilm)
{

    if (namesearch.length() > namefilm.length())
        return false;
    for (int i = 0; i + namesearch.length() <= namefilm.length(); i++)
    {
        for (int j = 0; j < namesearch.length(); j++)
        {
            if (tolower(namesearch[j]) != tolower(namefilm[i + j]))
                break;

            if (j == namesearch.length() - 1)
                return true;
        }
    }
    return false;
}

bool menuText(string text, int flag)
{

    char select;
    do
    {
        
         cout << "+----------------------------------------------------------------------------+\n";
    if (flag == 0)
        cout << "|                  Ban co chac chan " << text << "khong                 |\n";
    else
        cout << "|                    Ban co muon " << text << "khong                    |\n";

    cout << "|                                                                            |\n";
    cout << "|                 [1] DONG Y                      [2] KHONG                  |\n";
    cout << "|                                                                            |\n";
    cout << "+----------------------------------------------------------------------------+\n\n\n";
        cout << "         Nhap lua chon cua ban:       ";
        cin >> select;
        system("cls");
        if (select == '2')
            return false;
        else if (select == '1')
            return true;
        cout << "Lua chon cua ban khong phu hop , vui long chon lua chon khac :  \n";
    } while (true);
    return false;
}

bool deleteuser(user *User, listUser &lU, int maxIndexlistFilm)
{
    system("cls");
    bool check = menuText("    xoa tai khoan  ");

    if (check == 0)
    {
        cout << "\n                 Xoa khong thanh cong                \n";
        return false;
    }
    else if (check == 1)
    {
        lU.deleteUser(User->getId());
        for (int i = 0; i <= maxIndexlistFilm; i++)
            graph[User->getId()][i] = 0;
        cout << "\n                    Xoa thanh cong                \n";
        return true;
    }
    return false;
}

bool menuUser(user *User, listFilm &lF, listUser &lU)

{
    string stringsearcch;
    // cout << " asujdyasvdyuas asvbdyasbvdyhbvasd savdyhusavduyhasd";
    vector<int> rcmneighbour = rcmbyNeighbor(User->getId(), lF);
    vector<int> rcmnewest = rcmbyNewest(lF);
    for (auto i : rcmneighbour)
        allFilmRcmtoUser.push_back(i);

    for (auto i : rcmnewest)
        allFilmRcmtoUser.push_back(i);
    menuRecommend("Tron bo phim moi", rcmnewest, lF);
    menuRecommend("Phim duoc de xuat voi ban", rcmneighbour, lF);
    bool check;
    char select;
    do
    {
        cout << "1. Chon phim duoc de xuat\n";
        cout << "2. Tim kiem phim theo ten\n";
        cout << "3. Xem lich su\n";
        cout << "4. Dang xuat\n";
        cout << "5. Tat chuong trinh\n";
        cout << "6. Xoa tai khoan\n";
        cout << "Nhap lua chon cua ban : ";
        cin >> select;

        system("cls");
        switch (select)
        {
        case '1':
        again:    
            menuRecommend("Recommend by newest Film  ", rcmnewest, lF);
            menuRecommend("Recommend by neighbour history ", rcmneighbour, lF);
            run(lF, lU, 3, User->getId());
            break;
        case '2':
            run(lF, lU, 2, User->getId());
            break;
        case '3':
            historyUser(User->getId(), lF);
            break;
        case '4':
            check = menuText("     dang xuat     ");
            if (check)
                return true;
            else
                continue;
        case '5':
            cout << " Tai khoan cua ban se khong dang xuat khi ban xuat chuong trinh \n\n\n";
            check = menuText(" tat chuong trinh  ");
            if (check)
                return false;
        case '6':
            check = deleteuser(User, lU, lF.getmaxIndex());
            system("pause");
            if (check)
                return true;
        default:
            cout << "Lua chon cua ban khong phu hop, vui long chon lua chon chuan hon nhe: \n\n";
            system("pause");
        }
        system("cls");
    } while (select);
    return false;
}

bool menuAdmin(user *User, listFilm &lF, listUser &lU)
{
    bool check;
    char select;
    film *f;
    do
    {
        system("cls");
        cout << "1. Chon phim\n";
        cout << "2. Them phim\n";
        cout << "3. Xoa phim\n";
        cout << "4. Xoa user\n";
        cout << "5. Dang xuat\n";
        cout << "6. Tat chuong trinh\n";
        cout << "Nhap lua chon cua ban :   ";
        cin >> select;
        system("cls");
        switch (select)
        {
        case '1':
            run(lF, lU, 2, 0);
            break;
        case '2':
            f = inputFilm();
            lF.addFilm(f);
            break;
        case '3':
            run(lF, lU, 1);
            continue;
        case '4':
            run(lF, lU, 0);
            continue;
        case '5':
            check = menuText("     dang xuat     ");
            if (check)
                return 1;
            else
                continue;
            break;
        case '6':
            cout << " Tai khoan cua ban se khong dang xuat khi ban xuat chuong trinh \n\n\n";
            check = menuText(" tat chuong trinh  ");
            if (check)
                return 0;
            break;
        default:
            cout << "Lua chon cua ban khong dung, vui long nhap lai lua chon chuan hon nhe\n";
            system("pause");
            break;
        }

    } while (select);
    return false;
}

film *inputFilm()
{
    string name, time, category, director, date, description;
    float rating;
    cout << "\t\t\tVui long nhap cac thong tin cua phim : \n\n\n";
    cout << "\n\n Ten phim  :  ";
    cin.ignore();
    getline(cin, name);
    cout << "\n\nNhap thoi luong cua phim theo format hh::mm:ss : ";
    getline(cin, time);
    cout << "\n\nNhap the loai cua phim : ";
    getline(cin, category);
    cout << "\n\nNhap dao dien cua phim : ";
    getline(cin, director);
    cout << "\n\nNhap ngay phat hanh cua phim  theo format yyyy/mm/dd:  ";
    getline(cin, date);
    cout << "\n\nNhap vai dong mo ta cua phim : ";
    getline(cin, description);
    cout << "\n\nNhap mot so thuc la danh gia cua phim : ";
    cin >> rating;
    film *f = new film(name, time, category, director, rating, date, description);
    return f;
}

bool run(listFilm &lF, listUser &lU, int flag, int userId)
{
    bool firsttime = 1;
    bool de;
    int jumpflag;

nhapten:
    string name;
    vector<int> nums;
    if (flag < 3)
    {
        if (flag)
            cout << "\n\nNhap tem phim ban muon : ";
        else
            cout << "\n\nNhap tem tai khoan ban muon :  ";

        cin.ignore();
        getline(cin, name);

        /*Thu tu ngu nhap vao */
        // cout<<"'"<<name<<"'"<<'\n';
        // system("pause");
    }
nhapid:
    if (flag == 1 || flag == 2)
    {
        if (firsttime == 1)
            for (int i = 0; i <= lF.getmaxIndex(); i++)
                if (lF.getElementatIndex(i) != NULL && search(name, lF.getElementatIndex(i)->getName()))
                    nums.push_back(i);
        menuRecommend("Danh sach cac phim co tu khoa tim kiem ", nums, lF);
    }
    else if (flag == 0)
    {
        if (firsttime == 1)
            for (int i = 1; i <= lU.getmaxIndex(); i++)
                if (lU.getUseratIndex(i) != NULL && search(name, lU.getUseratIndex(i)->getUsername()))
                    nums.push_back(i);
        printListUser(nums, lU);
    }
    else if (flag == 3)
        nums = allFilmRcmtoUser;
    firsttime = 0;
    if (nums.empty())
    {
        system("cls");
        cout << "Tu khoa tim kiem khong he ton tai trong bat ki ten nao \n";
        jumpflag = 1;
    }
    else
    {
        cout << "Nhap id ban muon :\n";
        cout << "(Nhap vao mot so am hoac so lon hon 999 neu ban muon thoat chuc nang nay) :   ";
        int id;
        cin >> id;
        if (id < 0 || id >= 1000)
            return 0;
        int searchflag = 0;
        for (int i = 0; i < nums.size(); i++)
        {
            if (id == nums[i])
            {
                searchflag = 1;
                break;
            }
        }
        if (searchflag == 1)
        {
            if (flag == 1)
            {
                system("cls");
                de = menuText("    xoa phim       ");
                if (de == 0)
                {
                    cout << "\n                 Xoa khong thanh cong                \n";
                    return false;
                }
                else if (de == 1)
                {
                    lF.deleteFilm(lF.getElementatIndex(id)->getID());
                    for (int i = 0; i <= lU.getmaxIndex(); i++)
                        graph[i][lF.getElementatIndex(i)->getID()] = 0;
                    cout << "\n                 Xoa thanh cong                \n";
                    return true;
                }
            }
            else if (flag == 0)
            {
                deleteuser(lU.getUseratIndex(id), lU, lF.getmaxIndex());
                return true;
            }
            else if (flag == 2 || flag == 3)
            {
                watchFilm(userId, id, lF);
                system("pause");
                system("cls");
                return 1;
            }
        }
        else
        {
            system("cls");
            cout << "Id : " << id << ", ban da chon khong ton tai trong danh sach \n";
            jumpflag = 2;
        }
    }

    if (menuText("      nhap lai     ", 1) == 1)
    {
        if (jumpflag == 1)
            goto nhapten;
        else if (jumpflag == 2)
            goto nhapid;
        else if (jumpflag == 3)
            return 0;
    }
    else
    {
        system("cls");
        return 1;
    }
    return 0;
}

void historyUser(int id, listFilm &lF)
{
    vector<int> ls;
    for (int i = 0; i <= lF.getmaxIndex(); i++)
        if (graph[id][i] == 1 && lF.getElementatIndex(i) != NULL)
            ls.push_back(i);

    if (ls.empty())
        cout << "Lich su xem cua ban dang trong \n\n";
    else
        menuRecommend("Lich su xem cua ban ", ls, lF);

    system("pause");
    return;
}

void printListUser(vector<int> v, listUser &lU)
{
    if (v.empty())
    {
        cout << "khong ton tai nguoi co ten tren \n\n";
        return;
    }
    for (int i : v)
    {
        cout << "\t\t\t" << lU.getUseratIndex(i)->getId() << "\n";
        cout << "usename :  " << lU.getUseratIndex(i)->getUsername() << "\n";
        cout << "password:   " << lU.getUseratIndex(i)->getPaasword() << "\n";
        cout << "\n----------------------------------------------------\n";
    }
}