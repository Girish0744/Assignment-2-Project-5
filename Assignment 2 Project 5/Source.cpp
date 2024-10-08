#include <iostream>
#include <fstream>
#include <vector>
#include <sstream>

using namespace std;

#define PRE_RELEASE true

// Structure for the student data
struct STUDENT_DATA {
    string First_Name;
    string Last_Name;
    string Email;
};

int main() {
    // Checking the condition that we are in pre-release mode
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
                Students.push_back(student);
            }
#else
            // In standard, we only expect First_Name and Last_Name
            if (getline(ss, First_Name, ',') && getline(ss, Last_Name)) {
                STUDENT_DATA student = { First_Name, Last_Name, "" }; // No email in standard version
                Students.push_back(student);
            }
#endif
        }
        file.close();
    }
    else
    {
        cerr << "The file cannot be opened.\n";
        return 1;
    }

    // To make sure if there is Debug or Release
#ifdef _DEBUG
    // Debug Mode
#ifdef PRE_RELEASE
        // Debug Pre-Release will print everything 
    for (const auto& student : Students)
    {
        cout << "First Name: " << student.First_Name
            << ", Last Name: " << student.Last_Name
            << ", Email: " << student.Email << endl;
    }
#else
        // Debug Standard will print only the names
    for (const auto& student : Students)
    {
        cout << "First Name: " << student.First_Name
            << ", Last Name: " << student.Last_Name << endl;
    }
#endif
#else
    // Release Mode
#ifdef PRE_RELEASE
        // Release Pre-Release will print only emails
    for (const auto& student : Students)
    {
        cout << "Email: " << student.Email << endl;
    }
#else
        // Release Standard will print "Just running in Standard mode"
    cout << "Just running in Standard mode.\n";
#endif
#endif

    return 0;
}
