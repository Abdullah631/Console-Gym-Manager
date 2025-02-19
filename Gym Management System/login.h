#include <iostream>
#include <fstream>
#include <cstring>
using namespace std;
class login
{
public:
    bool log(const string &uN, const string &p)
    {
        system("cls");

        fstream f1("text.bin", ios::binary | ios::in);
        if (!f1)
        {
            cout << "Error opening file.\n";
            return false;
        }

        string storedUsername;
        getline(f1, storedUsername);

        string storedPassword;
        getline(f1, storedPassword);

        f1.close();

        if (uN == storedUsername && p == storedPassword)
        {
            return true;
        }
        else
        {
            return false;
        }
    }

    bool changeCredentials(const string &oldUsername, const string &oldPassword)
    {
        system("cls");
        fstream file;
        string newUsername;
        string newPassword;
        file.open("text.bin", ios::in | ios::out | ios::binary);

        if (!file)
        {
            cout << "File not found or unable to open.\n";
            return false;
        }

        string storedUsername, storedPassword;

        getline(file, storedUsername);
        getline(file, storedPassword);

        if (storedUsername == oldUsername && storedPassword == oldPassword)
        {
            file.close();
            file.open("text.bin", ios::out | ios::binary | ios::trunc);

            if (!file)
            {
                cout << "Error clearing file.\n";
                return false;
            }

            cout << "\nEnter New Username: ";
            getline(cin, newUsername);
            cout << "Enter New Password: ";
            getline(cin, newPassword);
            file << newUsername << "\n"
                 << newPassword << "\n";
            file.flush();
            file.close();
            return true;
        }
        else
        {
            file.close();
            return false;
        }
    }
};