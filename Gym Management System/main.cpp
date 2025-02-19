#include <iostream>
#include <fstream>
#include <string>
#include "menu.h"
#include "login.h"
using namespace std;
int main()
{
    login l1;
    string userName;
    string password;
    int check = 0;
    const int maxAttempts = 3;
    int attempts = 0;

    do
    {
        int loginChoice;
        cout << "WELCOME TO THE SYSTEM\n";
        cout << "1. Login\n";
        cout << "2. Exit\n";
        cout << "Enter Choice: ";
        cin >> loginChoice;
        cin.ignore();

        if (loginChoice == 1)
        {
            cout << "Enter Username: ";
            getline(cin, userName);
            cout << "Enter Password: ";
            getline(cin, password);
            if (l1.log(userName, password))
            {
                int choice;
                cout << "WELCOME\n";
                do
                {
                    cout << "1. Go to Main Menu\n";
                    cout << "2. Change Admin Credentials\n";
                    cout << "3. Logout\n";
                    cout << "Enter Choice: ";
                    cin >> choice;
                    switch (choice)
                    {
                    case 1:
                    {
                        Menu m1;
                        m1.displayMenu();
                        break;
                    }
                    case 2:
                    {
                        cin.ignore();
                        string oldUn, oldPass;
                        cout << "Enter Old Username: ";
                        getline(cin, oldUn);
                        cout << "Enter Old Password: ";
                        getline(cin, oldPass);
                        if (l1.changeCredentials(oldUn, oldPass))
                        {
                            system("cls");
                            cout << "Username and password updated successfully.\n";
                        }
                        else
                        {
                            system("cls");
                            cout << "Wrong Old credentials\n";
                        }
                        break;
                    }
                    case 3:
                    {
                        break;
                    }
                    default:
                    {
                        cout << "Invalid choice\n";
                        break;
                    }
                    }
                } while (choice != 3);
            }
            else
            {
                attempts++;
                if (attempts >= maxAttempts)
                {
                    cout << "Maximum login attempts reached. Exiting...\n";
                    check = 1;
                }
                else
                {
                    cout << "Wrong credentials. Try again.\n";
                    continue;
                }
            }
        }
        else if (loginChoice == 2)
        {
            check = 1;
        }
        else
        {
            cout << "Invalid choice\n";
        }
    } while (check != 1);

    cout << "Exiting...\n";
    return 0;
}
