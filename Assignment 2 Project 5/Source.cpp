#include <iostream>
#include <fstream>
#include <vector>
#include <sstream>

using namespace std;

// Structure for the student data
struct STUDENT_DATA {
    string First_Name;
    string Last_Name;
};

int main() {

//Step #3: Initial Source Code
    // Opening the file StudentData.txt
    ifstream file("StudentData.txt");
    if (!file.is_open()) {
        cerr << "The file StudentData.txt cannot be opened.\n";
        return 1;
    }

    vector<STUDENT_DATA> Students;
    string line;

    // reading the file StudentData.txt
    while (getline(file, line)) {
        stringstream ss(line);
        string First_Name, Last_Name;
        if (getline(ss, First_Name, ',') && getline(ss, Last_Name)) {
            STUDENT_DATA student = { First_Name, Last_Name};
            Students.push_back(student);
        }
    }

//Step #4: Adding in some _DEBUG functionality
    #ifdef _DEBUG
        cout << "DEBUG MODE: NAMES OF THE STUDENTS\n";
        for (const auto& student : Students) {
            cout << "First Name: " << student.First_Name << ", Last Name: " << student.Last_Name << endl;
        }
    #endif

    //Loop to print the names of the student and mking sure that the txt file is opened
    for (const auto& student : Students) {
        cout << "First Name: " << student.First_Name << ", Last Name: " << student.Last_Name << endl;
    }

    return 0;
}

