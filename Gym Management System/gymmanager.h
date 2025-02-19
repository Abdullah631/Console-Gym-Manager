#include <iostream>
#include <fstream>
#include "equipment.h"
#include "members.h"
#include "payment.h"
#include <string>
#include "functions.h"
using namespace std;
class GymManager
{
public:
    ofstream gymMembersFile;
    void removeMemberFromFile(const string &filename, int gymID) const
    {
        if (remove1(filename,gymID))
        {
            cout << "Member removed from file: " << filename << endl;
        }
        else
        {
            cout << "Member not found in file: " << filename << endl;
        }
    }
    void removeEquipmentFromFile(const string &filename, int num) const
    {
        if (remove1(filename,num))
        {
            cout << "Equipment removed from file: " << filename << endl;
        }
        else
        {
            cout << "Equipment not found in file: " << filename << endl;
        }
    }
    void searchMemberInFile(const string &filename, int gymID) const
    {
        if (search(filename,gymID))
        {

        }
        else{
            cout<<"Member Not found in the file: "<<filename<<endl;
        }
    }
    void searchFeesInFile(const string &filename, int gymID) const
    {
        if (search(filename,gymID))
        {

        }
        else{
            cout<<"Member has not paid the fees of this month yet"<<endl;
        }
    }
    void searchSalaryInFile(const string &filename, int gymID) const
    {
        if (search(filename,gymID))
        {

        }
        else{
            cout<<"Salary Has not been paid yet."<<endl;
        }
    }
    void addMember(Member *member, const string &filename)
    {
        int id;
        id=member->getGymID();
        if(doesExist(filename,id)){
            cout<<"Member with ID "<<id<<" already exists in the file "<<filename<<endl;
        }
        else{
            member->saveInfoToFile(filename);
        }
    }
    void addFees(Fees *f, const string &filename)
    {

        int id;
        id=f->getGymID();
        if(doesExist(filename,id)){
            cout<<"Member with ID "<<id<<" already paid the fees of this month"<<endl;
        }
        else{
            f->saveInfoToFile(filename);
        }
    }
    void addSalaryC(Salary *s, const string &filename)
    {
        int id;
        id=s->getGymID();
        if(doesExist(filename,id)){
            cout<<"Coach with ID "<<id<<" has received salary of this month."<<endl;
        }
        else{
            s->saveInfoToFile(filename);
        }
    }
    void addSalaryS(Salary *s, const string &filename)
    {
        int id;
        id=s->getGymID();
        if(doesExist(filename,id)){
            cout<<"Staff with ID "<<id<<" has received salary of this month."<<endl;
        }
        else{
            s->saveInfoToFile(filename);
        }
    }
    bool addEquipment(Equipment *e1, const string &filename)
    {
        int id;
        id=e1->getEquipNum();
        if(doesExist(filename,id)){
            cout<<"Equipment with ID "<<id<<" already exists in the file "<<filename<<endl;
        }
        else{
            e1->saveInfoToFile(filename);
        }
    }
    void displayFileContents(const string &filename)
    {
        system("cls");
        ifstream file(filename);

        if (!file.is_open())
        {
            cout << "Unable to open file: " << filename << endl;
            return;
        }

        string line;
        cout << "Content of " << filename << ":" << endl;
        while (getline(file, line))
        {
            cout << line << endl;
        }

        file.close();
    }
};