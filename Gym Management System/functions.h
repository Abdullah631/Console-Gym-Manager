#include<iostream>
#include<fstream>
#include<string>
using namespace std;
bool remove1(const std::string& filename, int gymID) {
    std::ifstream inFile(filename);
    std::ofstream tempFile("temp.txt");
    bool found = false;
    std::string line;

    while (getline(inFile, line)) {
        if (line.find("ID: " + std::to_string(gymID)) != std::string::npos) {
            found = true;
            while (getline(inFile, line) && line != "------------------------------------") {
            }
        } else {
            tempFile << line << std::endl;
        }
    }

    inFile.close();
    tempFile.close();

    remove(filename.c_str());
    rename("temp.txt", filename.c_str());

    return found;
}
bool search(const std::string& filename, int gymID) {
    std::ifstream file(filename);
    bool found = false;

    if (file.is_open()) {
        std::string line;

        while (getline(file, line)) {
            if (line.find("ID: " + std::to_string(gymID)) != std::string::npos) {
                found = true;
                std::cout << "Member found in file: " << filename << std::endl;

                while (getline(file, line) && line != "------------------------------------") {
                    std::cout << line << std::endl;
                }

                break;
            }
        }

        file.close();
    }

    return found;
}

bool doesExist(const std::string& filename,int id) {
    std::ifstream file(filename);
    if (file.is_open()) {
        std::string line;

        while (getline(file, line)) {
            if (line.find("ID: " + std::to_string(id)) != std::string::npos) {
                file.close();
                return true;
            }
        }

        file.close();
    }

    return false;
}
