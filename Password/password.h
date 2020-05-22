/*
    ====password.h====
AUTHOR:         Edwin Hernandez
VERSION:        1.0.0  
VERSION DATE:   5/15/20
EMAIL:          Edwinhernandez2@my.unt.edu
Copyright (c) 2020 Edwin Hernandez
    ====password.h====
*/

#ifndef password_h
#define password_h
#include <iostream>
using namespace std;

class Password
{
    private:
        string website;
        string user;
        string pwd;

    public:
        
        //Setters
        void SetWebsite(string Website)
        {
            website = Website;
        };
        void SetUser(string User)
        {   
            user = User;
        };
        void SetPwd(string Pwd)
        {
            pwd = Pwd;
        };

        void Print_Info();

        //Getters
        string GetWebsite()
        {
            return website;
        };
        string GetUser()
        {
            return user;
        };
        string GetPwd()
        {
            return pwd;
        };

};

#endif