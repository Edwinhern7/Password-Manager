/*
    ====password.cpp====
AUTHOR:         Edwin Hernandez
VERSION:        1.0.0  
VERSION DATE:   5/15/20
EMAIL:          Edwinhernandez2@my.unt.edu
Copyright (c) 2020 Edwin Hernandez
    ====password.cpp====
*/

#include <iostream>
#include "password.h"
using namespace std;

void Password::Print_Info()
{
   // cout << "WEBSITE NAME\t\tUSER_NAME\t\tPASSWORD\n";
    cout << website << "\t\t" << user << "\t\t" << pwd << endl;
}
