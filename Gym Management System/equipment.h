#include <iostream>
#include <fstream>
#include <string>
using namespace std;
class Equipment
{
    int equipmentNo;
    string equipmentName;

public:
    Equipment()
    {
        equipmentNo = 0;
        equipmentName = nullptr;
    }
    Equipment(int num, const string &name)
    {
        equipmentNo = num;
        equipmentName = name;
    }
    void displayInfo() const
    {
        cout << "Equipment Number: " << equipmentNo << endl;
        cout << "Equipment Name: " << equipmentName << endl;
    }
    void saveInfoToFile(const string &filename) const
    {
        ofstream file(filename, ios::app);
        if (file.is_open())
        {
            file << "ID: " << equipmentNo << endl;
            file << "Equipment Name: " << equipmentName << endl;
            file << "------------------------------------" << endl;
            file.close();
            cout << "Information saved to " << filename << " successfully." << endl;
        }
        else
        {
            cout << "Unable to open file." << endl;
        }
    }
    int getEquipNum() const
    {
        return equipmentNo;
    }
    void displayEquipments(const string &filename)
    {
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