#include <iostream>
#include <string>
#include <fstream>
using namespace std;

class Payment
{
protected:
    string paymentDate;

public:
    Payment(string date) : paymentDate(date) {}

    void displayPayment()
    {
        cout << "Payment Date: " << paymentDate << endl;
    }
};

class Fees : public Payment
{
private:
    int memberId;
    string name;

public:
    Fees(string date, int id, string n) : Payment(date), memberId(id), name(n) {}

    void displayFeesInfo()
    {
        system("cls");
        displayPayment();
        cout << "Member ID: " << memberId << endl;
        cout << "Name: " << name << endl;
        displayPayment();
    }
    int getGymID() const
    {
        return memberId;
    }
    void saveInfoToFile(const string &filename) const
    {
        system("cls");
        ofstream file(filename, ios::app);
        if (file.is_open())
        {
            file << "ID: " << memberId << endl;
            file << "Name: " << name << endl;
            file << "Fees Payment Date: " << paymentDate << endl;
            file << "------------------------------------" << endl;
            file.close();
            cout << "Information saved to " << filename << " successfully." << endl;
        }
        else
        {
            cout << "Unable to open file." << endl;
        }
    }
};

class Salary : public Payment
{
private:
    int staffId;
    string name;

public:
    Salary(string date, int id, string n) : Payment(date), staffId(id), name(n) {}

    void displaySalaryInfo()
    {
        system("cls");
        displayPayment();
        cout << "Staff ID: " << staffId << endl;
        cout << "Name: " << name << endl;
        displayPayment();
    }
    int getGymID() const
    {
        return staffId;
    }
    void saveInfoToFile(const string &filename) const
    {
        system("cls");
        ofstream file(filename, ios::app);
        if (file.is_open())
        {
            file << "ID: " << staffId << endl;
            file << "Name: " << name << endl;
            file << "Salary Payment Date: " << paymentDate << endl;
            file << "------------------------------------" << endl;
            file.close();
            cout << "Information saved to " << filename << " successfully." << endl;
        }
        else
        {
            cout << "Unable to open file." << endl;
        }
    }
};