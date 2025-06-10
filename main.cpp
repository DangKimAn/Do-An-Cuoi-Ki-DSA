#include <iostream>
#include "film.h"
#include "user.h"
#include "dothi.h"
#include "menu.h"
#include "rcm.h"
using namespace std;

int main()
{
   // cout<<1<<"\n";
    listUser *lU  = new listUser();
    lU->readUser("data/user.txt");
   // cout<<1<<"\n";
    listFilm *lF = new listFilm();
    lF->readFilm("data/film.txt");
    readHistory(*lF , *lU);
   // cout<<1<<"\n";
    lU->readMissNumFIle("data/missNumUser.txt");
   // cout<<1<<"\n";
    lF->readMissNumFIle("data/missNumFilm.txt");
   // cout<<1<<"\n";
    user *u = readCurr("data/curr.txt" , *lU);
    while (true)
    {  
        system("cls");
        if(u == NULL)        
            u = menulogin(*lU);
        if (u != NULL)
        {   
            system("cls");
            if(u->isAdmin() == true)
            {
                
                bool check  = menuAdmin(u , *lF,*lU);
                if(check)
                {
                    u = NULL;
                    continue;
                }
                else
                    break;
            }
            else
            {
                bool check  = menuUser(u , *lF,*lU);
                if(check)
                {
                    u = NULL;
                    continue;
                }
                else
                    break;
            }
        }
        break;
    }
    system("cls");
    lU->writeMissNumFile("data/missNumUser.txt");
    lF->writeMissNumFile("data/missNumFilm.txt");
    writeCurr("data/curr.txt" , u);
    lF->writeFilm("data/film.txt");
    lU->writeUser("data/user.txt");
    writeHistory("data/history.txt");
    delete lU;
    delete lF;
    return 0;
}