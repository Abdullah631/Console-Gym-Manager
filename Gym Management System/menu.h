#include <iostream>
#include <fstream>
#include <string>
#include "gymmanager.h"
using namespace std;
class Menu
{
private:
    GymManager man1;

public:
    Menu() : man1() {}
    void displayMenu()
    {
        system("cls");
        int choice;
        do
        {
            system("cls");
            cout << "\nMENU:\n";
            cout << "1. Add Members\n";
            cout << "2. Equipments\n";
            cout << "3. Payments\n";
            cout << "4. Remove Members\n";
            cout << "5. Search Members\n";
            cout << "6. Back\n";
            cout << "Enter your choice: ";
            cin >> choice;

            switch (choice)
            {
            case 1:
            {
                system("cls");
                int addchoice;
                do
                {
                    cout << "\nMENU: \n";
                    cout << "1. Add Member\n";
                    cout << "2. Add Coach\n";
                    cout << "3. Add Staff\n";
                    cout << "4. Back to Main Menu\n";
                    cout << "Enter choice: ";
                    cin >> addchoice;
                    switch (addchoice)
                    {
                    case 1:
                    {
                        int gymID;
                        string name, address, phoneNumber;
                        cout << "Enter Member ID: ";
                        cin >> gymID;
                        cin.ignore();
                        cout << "Enter Name: ";
                        getline(cin, name);
                        cout << "Enter Address: ";
                        getline(cin, address);
                        cout << "Enter Phone Number: ";
                        cin >> phoneNumber;
                        Member *member = new Member(gymID, name, address, phoneNumber);
                        man1.addMember(member, "members.txt");
                        break;
                    }
                    case 2:
                    {
                        int gymID;
                        string name, address, phoneNumber;
                        cout << "Enter Coach ID: ";
                        cin >> gymID;
                        cin.ignore();
                        cout << "Enter Name: ";
                        getline(cin, name);
                        cout << "Enter Address: ";
                        getline(cin, address);
                        cout << "Enter Phone Number: ";
                        cin >> phoneNumber;
                        Coach *coach = new Coach(gymID, name, address, phoneNumber);
                        man1.addMember(coach, "coaches.txt");
                        break;
                    }
                    case 3:
                    {
                        int gymID;
                        string name, address, phoneNumber;
                        cout << "Enter Staff ID: ";
                        cin >> gymID;
                        cin.ignore();
                        cout << "Enter Name: ";
                        getline(cin, name);
                        cout << "Enter Address: ";
                        getline(cin, address);
                        cout << "Enter Phone Number: ";
                        cin >> phoneNumber;
                        Staff *staff = new Staff(gymID, name, address, phoneNumber);
                        man1.addMember(staff, "staff.txt");
                        break;
                    }
                    case 4:
                    {
                        system("cls");
                        break;
                    }
                    default:
                        cout << "Invalid Choice. Enter Valid Choice.\n";
                    }
                } while (addchoice != 4);
                break;
            }
            case 2:
            {
                system("cls");
                int equipchoice;
                do
                {
                    cout << "\nMENU: \n";
                    cout << "1. Add Equipment\n";
                    cout << "2. Remove Equipment\n";
                    cout << "3. Show Equipments\n";
                    cout << "4. Back to Main Menu\n";
                    cout << "Enter choice: ";
                    cin >> equipchoice;
                    switch (equipchoice)
                    {
                    case 1:
                    {
                        int equipNum;
                        string name;
                        cout << "Enter Equipment Number: ";
                        cin >> equipNum;
                        cin.ignore();
                        cout << "Enter Name: ";
                        getline(cin, name);
                        Equipment *e1 = new Equipment(equipNum, name);
                        man1.addEquipment(e1, "equipment.txt");
                        break;
                    }
                    case 2:
                    {
                        int equipNum;
                        cout << "Enter Equipment number of equipment to remove: ";
                        cin >> equipNum;
                        man1.removeEquipmentFromFile("equipment.txt", equipNum);
                        break;
                    }
                    case 3:
                    {
                        string filename;
                        filename = "equipment.txt";
                        man1.displayFileContents(filename);
                    }
                    case 4:
                    {
                        break;
                    }
                    default:
                        cout << "Invalid Choice. Enter Valid Choice.\n";
                    }
                } while (equipchoice != 4);
                break;
            }
            case 3:
            {
                system("cls");
                int paymentChoice;
                do
                {
                    cout << "\nMENU: \n";
                    cout << "1. Pay Membership Fees\n";
                    cout << "2. Check Fee Payment\n";
                    cout << "3. Coach Salary Payment \n";
                    cout << "4. Coach Salary Check \n";
                    cout << "5. Staff Salary Payment \n";
                    cout << "6. Staff Salary Check \n";
                    cout << "7. Back to Main Menu\n";
                    cout << "Enter choice: ";
                    cin >> paymentChoice;
                    switch (paymentChoice)
                    {
                    case 1:
                    {
                        int gymID;
                        string name;
                        string date;
                        cout << "Enter Gym ID of Member: ";
                        cin >> gymID;
                        cin.ignore();
                        cout << "Enter Name: ";
                        getline(cin, name);
                        cout << "Enter Receiving Date: ";
                        getline(cin, date);
                        Fees *f1 = new Fees(date, gymID, name);
                        man1.addFees(f1, "memberFees.txt");
                        break;
                    }
                    case 2:
                    {
                        int gymID;
                        cout << "Enter Gym ID of Member to check fees: ";
                        cin >> gymID;
                        man1.searchFeesInFile("memberFees.txt", gymID);
                        break;
                    }
                    case 3:
                    {
                        int gymID;
                        string name;
                        string date;
                        cout << "Enter Gym ID of Coach: ";
                        cin >> gymID;
                        cin.ignore();
                        cout << "Enter Name: ";
                        getline(cin, name);
                        cout << "Enter Salary Payment Date: ";
                        getline(cin, date);
                        Salary *s1 = new Salary(date, gymID, name);
                        man1.addSalaryC(s1, "CoachSalaryDetails.txt");
                        break;
                    }
                    case 4:
                    {
                        int gymID;
                        cout << "Enter Gym ID of Coach to check Salary Details: ";
                        cin >> gymID;
                        man1.searchSalaryInFile("CoachSalaryDetails.txt", gymID);
                        break;
                    }
                    case 5:
                    {
                        int gymID;
                        string name;
                        string date;
                        cout << "Enter Gym ID of Staff: ";
                        cin >> gymID;
                        cin.ignore();
                        cout << "Enter Name: ";
                        getline(cin, name);
                        cout << "Enter Salary Payment Date: ";
                        getline(cin, date);
                        Salary *s1 = new Salary(date, gymID, name);
                        man1.addSalaryS(s1, "StaffSalaryDetails.txt");
                        break;
                    }
                    case 6:
                    {
                        int gymID;
                        cout << "Enter Gym ID of Staff to check Salary Details: ";
                        cin >> gymID;
                        man1.searchSalaryInFile("StaffSalaryDetails.txt", gymID);
                        break;
                    }
                    case 7:
                    {
                        system("cls");
                        break;
                    }
                    default:
                        cout << "Invalid Choice. Enter Valid Choice.\n";
                    }
                } while (paymentChoice != 7);
                break;
            }
            case 4:
            {
                system("cls");
                int removeChoice;
                do
                {
                    cout << "\nMENU: \n";
                    cout << "1. Remove Member\n";
                    cout << "2. Remove Coach\n";
                    cout << "3. Remove Staff\n";
                    cout << "4. Back to Main Menu\n";
                    cout << "Enter choice: ";
                    cin >> removeChoice;
                    switch (removeChoice)
                    {
                    case 1:
                    {
                        int gymID;
                        cout << "Enter Gym ID of member to remove: ";
                        cin >> gymID;
                        man1.removeMemberFromFile("members.txt", gymID);
                        break;
                    }
                    case 2:
                    {
                        int gymID;
                        cout << "Enter Gym ID of coach to remove: ";
                        cin >> gymID;
                        man1.removeMemberFromFile("coaches.txt", gymID);
                        break;
                    }
                    case 3:
                    {
                        int gymID;
                        cout << "Enter Gym ID of staff to remove: ";
                        cin >> gymID;
                        man1.removeMemberFromFile("staff.txt", gymID);
                        break;
                    }
                    case 4:
                    {
                        system("cls");
                        break;
                    }
                    default:
                        cout << "Invalid Choice. Enter Valid Choice.\n";
                    }
                } while (removeChoice != 4);
                break;
            }
            case 5:
            {
                system("cls");
                int searchChoice;
                do
                {
                    cout << "\nMENU: \n";
                    cout << "1. Search Member\n";
                    cout << "2. Search Coach\n";
                    cout << "3. Search Staff\n";
                    cout << "4. Back to Main Menu\n";
                    cout << "Enter choice: ";
                    cin >> searchChoice;
                    switch (searchChoice)
                    {
                    case 1:
                    {
                        int gymID;
                        cout << "Enter Gym ID of member to search: ";
                        cin >> gymID;
                        man1.searchMemberInFile("members.txt", gymID);
                        break;
                    }
                    case 2:
                    {
                        int gymID;
                        cout << "Enter Gym ID of coach to search: ";
                        cin >> gymID;
                        man1.searchMemberInFile("coaches.txt", gymID);
                        break;
                    }
                    case 3:
                    {
                        int gymID;
                        cout << "Enter Gym ID of staff to search: ";
                        cin >> gymID;
                        man1.searchMemberInFile("staff.txt", gymID);
                        break;
                    }
                    case 4:
                    {
                        system("cls");
                        break;
                    }
                    default:
                        cout << "Invalid Choice. Enter Valid Choice.\n";
                        break;
                    }
                } while (searchChoice != 4);
                break;
            }
            case 6:
                system("cls");
                break;
            default:
                cout << "Invalid choice. Please enter a valid option.\n";
            }
        } while (choice != 6);
    }
};
