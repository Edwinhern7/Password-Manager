/*
    ====main.cpp====
AUTHOR:         Edwin Hernandez
VERSION:        1.0.0  
VERSION DATE:   5/15/20
EMAIL:          Edwinhernandez2@my.unt.edu
Copyright (c) 2020 Edwin Hernandez
    ====main.cpp====
*/

#include <iostream>
#include "passwords.h"
using namespace std;

//Allows the computer to understand there is a function below the program that would be used
void PrintHeader();

//Extension name for the file "passwords.cpp"
Passwords PASSWORDS;

int main()
{
    //Attributes
    int input;
    
    do
    {
        //Displays Menu
        PrintHeader();
        //Retrieves Input Info
        cout << "Enter the number of choice and press enter: ";   
        cin >> input;
        cin.ignore();
        //Switch to determine User's choice
        switch(input)
        {
            case 0:
                //Exits Program
                cout << "\n";
                cout << "Come Again!\n";
                break;
            case 1:
                //Prompts user to add password
                PASSWORDS.Add_Password();
                break;
            case 2:
                //Prompts user to modify password
                PASSWORDS.Modify_Password();
                break;
            case 3:
                //Prompts user to Remove Passwords
                PASSWORDS.Delete_Password();
                break;
            case 4:
                //Search Password
                PASSWORDS.Print_Single_Password_Info();
                break;
            case 5:
                //Print List of Passwords
                PASSWORDS.Print_List_Passwords();
                break;
            case 6:
                //Prompt user to Save Data
                PASSWORDS.Save_Data();
                break;
            case 7:
                //Prompt user to Load Data
                PASSWORDS.Load_Data();
                break;
            default:
                //Display when Input does not match the choices listed in the Menu display
                cout << "Invalid Input. Please Enter the Number of choice and press enter: ";
                break;
        }
     }while(input != 0); //Prompts the Menu display and allows user to input choice unless choice = 0
    
    return 0;
}


void PrintHeader()
{
    cout << "===Password Manager===\n";
    cout << "0. Exit\n";
    cout << "1. Add Password\n";
    cout << "2. Edit Password\n";
    cout << "3. Remove Passowrd\n";
    cout << "4. Search/Find Password\n";
    cout << "5. Print List of Passwords\n";
    cout << "\n";
    cout << "6. Save\n";
    cout << "7. Load\n";    
}//Menu Info