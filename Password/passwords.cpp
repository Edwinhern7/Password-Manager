/*
    ====passwords.cpp====
AUTHOR:         Edwin Hernandez
VERSION:        1.0.0  
VERSION DATE:   5/15/20
EMAIL:          Edwinhernandez2@my.unt.edu
Copyright (c) 2020 Edwin Hernandez
    ====passwords.cpp====
*/

#include <iostream>
#include <vector>
#include <fstream>
#include <time.h>
#include "password.h"
#include "passwords.h"
using namespace std;

void Passwords::Add_Password()
{
    //Extension for Password
    Password New_Password;
    //Attributes
    string website, user, pwd = " ";
    int input;

    //Enter Website Name (Google, Facebook, etc.)
    cout << "Enter Website Name (Google, Facebook, etc.): ";
    getline(cin, website);
    //Enter User login (Email Login or Username)
    cout << "Enter User Login (Email Login or Username): ";
    getline(cin, user);
    //Enter Password (Make password 6 or more chars.)
    cout << "===PASSWORD TYPE===\n";
    cout << "1. Enter Password (password must be 6 or more chars.)\n";
    cout << "2. Generate Password\n";
    //Retrieves Input Info
    cout << "Enter the number of choice and press enter: ";   
    cin >> input;
    cin.ignore();
    //Switch to determine User's choice
    switch(input)
    {
        case 1:
        {
            cout << "Enter Password (password must be 6 or more chars.): ";
            getline(cin, pwd);
            //Check if pwd < 6
            while(pwd.length() < 6)
            {
                cout << "Please Enter Password (password must be 6 or more chars.): ";
                getline(cin, pwd);
            }
            //Check if pwd is taken
            while(Passwords::IsID_Taken(pwd))
            {
                cout << "Password is already taken. Enter Password (password must be 6 or more chars.): ";
                getline(cin, pwd);
            }
            break;
        }
        case 2:
        {
            //Attributes
            string numbers = "123456789";
            string specials = "!@#$%^&*";
            string capitals = "ABCDEFGHIJKLMNPQRSTUVWXYZ";
            string lowers = "abcdefghijklmnpqrstuvwxyz";
            
            string altogether = numbers + specials + capitals + lowers;
            
            
            srand (time(NULL));
            pwd += capitals[rand() % capitals.length()];
            for(int i= 0; i < 9; ++i)
            {
                pwd += altogether[rand() % altogether.length()];
            }
            break;
        }
        default:
            cout << "Invalid Input. Exiting...\n";
            break;
    }

   
    //Use the set functions to place each info 
    New_Password.SetWebsite(website);
    New_Password.SetUser(user);
    New_Password.SetPwd(pwd);

    //Pushback Info for New_Password
    Passwords.push_back(New_Password);
} 

void Passwords::Modify_Password()
{   
    //Attributes
    string website;
    
    //Retrieve Website Info
    cout << "Enter Website Name (Google, Facebook, etc.): ";
    getline(cin, website);

    //Find the Password using the website to modify the Info
    Password* Pwd_With_Website = FindPasswordByWebsite(website);
    if(Pwd_With_Website)
    {
        int choice = -1;
        while(choice != 0)
        {   
            //Menu
            cout << "===Modify Password===\n";
            cout << "0. Exit\n";
            cout << "1. User Login\n";
            cout << "2. Password\n";
            //Enter the number of description you would like to change.
            cout << "Enter the number of description you would like to change: ";
            cin >> choice;
            cin.ignore();
            //Switch to determine User's choice
            switch(choice)
            {
                case 0:
                    break;
                case 1:
                {
                    string New_Login;
                    //Retrieve new User Login
                    cout << "Enter New User Login (Email Login or Username): ";
                    getline(cin, New_Login);
                    //Set New_login for User
                    Pwd_With_Website->SetUser(New_Login);
                    cout << "User Name Changed.\n";
                    break;
                }
                case 2:
                {
                    string New_Password;
                    //Retrieve new Password
                    cout << "Enter New Password (password must be 6 or more chars.): ";
                    getline(cin, New_Password);
                    //Set new_Password for Password
                    Pwd_With_Website->SetPwd(New_Password);
                    cout << "Password changed.\n";
                    break;
                }
                default:
                    cout << "Invalid Input. Exiting...\n";
                    break;
            }

        }
    }
    //If the Website cannot be found, Exit Modifying Password
    else
    {
        cout << "Website not found. Exiting...\n";
    }
}


void Passwords::Delete_Password()
{
    //Attributes
    string website;
    bool RemovedPassword = false;
    //Used to Find info in stored boxes
    vector<Password>::iterator ptr;

    //Retrieves Website Info 
    cout << "Enter Website Name (Google, Facebook, etc.): ";
    getline(cin, website);

    //Loop used to search for Website
    for(ptr= Passwords.begin(); ptr < Passwords.end(); ptr++)
    {
        //If Website is found, Info correlated will be deleted
        if(ptr->GetWebsite() == website)
        {
            Passwords.erase(ptr);
            cout << "Password Info has been deleted.\n";
            RemovedPassword = true;
        }    
    }
    //If Website is not found, Program will output an error msg.
    if(!RemovedPassword)
    {
            cout << "Website Name not found. Exiting...\n";
    }
}

void Passwords::Print_Single_Password_Info()
{
    //Attributes
    string website;

    //Retreive Website Info
    cout << "Enter Website Name: ";
    getline(cin, website);
    //Bypasses the Website Entered to other Function
    Print_Single_Password_Info(website);
}

void Passwords::Print_Single_Password_Info(string Website)
{
    //Find the Password using the website to modify the Info
    Password* Pwd_With_Website = FindPasswordByWebsite(Website);
    //If Website was found, Print Info
    if(Pwd_With_Website)
    {
        cout << "===PRINTING INFO===\n";
        Pwd_With_Website->Print_Info();
    }
    //Else, Error msg.
    else
    {
        cout << "Website can not be found.\n";
    }
}

void Passwords::Print_List_Passwords()
{
    cout << "\t\t===PRINTING LIST OF PASSWORDS===\n";
    //Used to Find info in stored boxes
    vector<Password>::iterator ptr;
    //Prints Info stores in boxes
    for(ptr = Passwords.begin(); ptr < Passwords.end(); ptr++)
    {
        ptr->Print_Info();
    }
}


void Passwords::Save_Data()
{
    ofstream out;
    //Create a data file to store
    out.open("Data.dat");
    //Used to Find info in stored boxes
    vector<Password>::iterator ptr;
    //Using the size allows us to load the file size 
    out << Passwords.size() << endl;
    //Saves the Info into "Data.dat" in an organized format
    for(ptr = Passwords.begin(); ptr < Passwords.end(); ptr++)
    {
        
        out << ptr->GetWebsite() << "\t\t" << ptr->GetUser() << "\t\t" << ptr->GetPwd() << endl;
    }
    out.close();
}//Saves the data of each Password into "Data.dat"

void Passwords::Load_Data()
{   
    Passwords.clear();
    ifstream in;
    int data;
    //Open a data file to store
    in.open("Data.dat");
    if(in.fail())
    {
        cerr << "Error opening file" << endl;
    } 
    in >> data;
    in.ignore();
    //Retrieve Info from given file 
    for(int i = 0; i < data; i++)
    {
        //Attributes
        Password New_Password;
        string website, user, pwd;

        //Retrieving Info
        in >> website >> user >> pwd;
        
        //Setting Info to Functions
        New_Password.SetWebsite(website);
        New_Password.SetUser(user);
        New_Password.SetPwd(pwd);

        //Storing Info and making room for other Info
        Passwords.push_back(New_Password);
    }
    in.close();
}

Password* Passwords::FindPasswordByWebsite(string Website)
{
    vector<Password>::iterator ptr;
    //Searches for Website in Stored Info
    for(ptr = Passwords.begin(); ptr < Passwords.end(); ptr++)
    {
        if(ptr->GetWebsite() == Website)
        {
            return &(*ptr);
        }
    }
    return nullptr;
}// Searches for Website 

bool Passwords::IsID_Taken(string password)
{
    vector<Password>::iterator ptr;
    //Checks if Password is taken
    for(ptr = Passwords.begin(); ptr < Passwords.end(); ptr++)   
    {
        if(ptr->GetPwd() == password)
        {
            return true;
        }
    }
    return false;
}

