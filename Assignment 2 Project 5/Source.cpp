#include <iostream>
#include <fstream>
#include <vector>
#include <sstream>

using namespace std;

// Structure for the student data
struct STUDENT_DATA {
    string First_Name;
    string Last_Name;
    string Email;
};

int main() {

#ifdef PRE_RELEASE
    std::cout << "Pre-Release version.\n";
    std::ifstream file("StudentData_Emails.txt");
#else
    std::cout << "Standard version.\n";
    std::ifstream file("StudentData.txt");
#endif

    vector<STUDENT_DATA> Students;
    string line;

    // Opening the file
    if (file.is_open())
    {
        // Reading the file
        while (getline(file, line))
        {
            stringstream ss(line);
            string First_Name, Last_Name, Email;

#ifdef PRE_RELEASE
            // In pre-release, we expect First_Name, Last_Name, and Email
            if (getline(ss, First_Name, ',') && getline(ss, Last_Name, ',') && getline(ss, Email)) {
                STUDENT_DATA student = { First_Name, Last_Name, Email };
#else
            // In standard, we only expect First_Name and Last_Name
            if (getline(ss, First_Name, ',') && getline(ss, Last_Name)) {
                STUDENT_DATA student = { First_Name, Last_Name, "" }; // No email in standard version
#endif
                Students.push_back(student);
            }
            }
        file.close();
        }
    else
    {
        cerr << "The file cannot be opened.\n";
        return 1;
    }

    // Loop to print the student information
    for (const auto& student : Students)
    {
#ifdef PRE_RELEASE
        // Print First Name, Last Name, and Email
        cout << "First Name: " << student.First_Name << ", Last Name: " << student.Last_Name << ", Email: " << student.Email << endl;
#else
        // Only print First Name and Last Name
        cout << "First Name: " << student.First_Name << ", Last Name: " << student.Last_Name << endl;
#endif
    }

    return 0;
    }

