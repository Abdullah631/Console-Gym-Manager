#include <iostream>
#include <fstream>
#include <string>
using namespace std;
class Member
{
protected:
    int gymID;
    string name;
    string address;
    string phoneNumber;

public:
    Member(int id, const string &n, const string &addr, const string &phone)
        : gymID(id), name(n), address(addr), phoneNumber(phone) {}

    virtual void displayInfo() const
    {
        cout << "Gym ID: " << gymID << endl;
        cout << "Name: " << name << endl;
        cout << "Address: " << address << endl;
        cout << "Phone Number: " << phoneNumber << endl;
    }

    virtual void saveInfoToFile(const string &filename) const
    {
        ofstream file(filename, ios::app);
        if (file.is_open())
        {
            file << "ID: " << gymID << endl;
            file << "Name: " << name << endl;
            file << "Address: " << address << endl;
            file << "Phone Number: " << phoneNumber << endl;
            file << "------------------------------------" << endl;
            file.close();
            cout << "Information saved to " << filename << " successfully." << endl;
        }
        else
        {
            cout << "Unable to open file." << endl;
        }
    }

    virtual bool searchInFile(const string &filename) const
    {
        ifstream file(filename);
        if (file.is_open())
        {
            string line;
            while (getline(file, line))
            {
                if (line.find(to_string(gymID)) != string::npos)
                {
                    cout << "Member found in file: " << filename << endl;
                    file.close();
                    return true;
                }
            }
            file.close();
        }
        cout << "Member not found in file: " << filename << endl;
        return false;
    }
    int getGymID() const
    {
        return gymID;
    }
};

class Coach : public Member
{
public:
    Coach(int id, const string &n, const string &addr, const string &phone)
        : Member(id, n, addr, phone) {}

    void displayInfo() const override
    {
        cout << "Coach Details:" << endl;
        Member::displayInfo();
    }

    void saveInfoToFile(const string &filename) const override
    {
        Member::saveInfoToFile(filename);
    }

    bool searchInFile(const string &filename) const override
    {
        return Member::searchInFile(filename);
    }
};

class Staff : public Member
{
public:
    Staff(int id, const string &n, const string &addr, const string &phone)
        : Member(id, n, addr, phone) {}

    void displayInfo() const override
    {
        cout << "Staff Details:" << endl;
        Member::displayInfo();
    }

    void saveInfoToFile(const string &filename) const override
    {
        Member::saveInfoToFile(filename);
    }

    bool searchInFile(const string &filename) const override
    {
        return Member::searchInFile(filename);
    }
};