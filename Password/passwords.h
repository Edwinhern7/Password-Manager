/*
    ====passwords.h====
AUTHOR:         Edwin Hernandez
VERSION:        1.0.0  
VERSION DATE:   5/15/20
EMAIL:          Edwinhernandez2@my.unt.edu
Copyright (c) 2020 Edwin Hernandez
    ====passwords.h====
*/

#ifndef passwords_h
#define passwords_h
#include <iostream>
#include <vector>
#include "password.h"
using namespace std;

class Passwords
{
    private:
        vector<Password> Passwords;
    public:
        void Add_Password(); 
        void Modify_Password();
        void Delete_Password();
        void Print_Single_Password_Info();
        void Print_Single_Password_Info(string User);
        void Print_List_Passwords();
        bool IsID_Taken(string password);

        void Save_Data();
        void Load_Data();

        Password* FindPasswordByWebsite(string Website);
        Password* FindPasswordByUser(string User);
        
};

#endif