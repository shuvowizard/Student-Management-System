/* Student Management System With File Handing In C++.
    Created By- Shuvo Developer.
*/
#include <iostream>
#include <conio.h>
#include <stdio.h>
#include <fstream>
#include <stdlib.h>
#include <cstdlib>
#include <string> 
#include <regex>

using namespace std;

//! Email Validation Function
bool isValidEmail(string email)
{
    /* Regular expression pattern for basic email validation.
    This pattern is simple and might not cover all edge cases.
    You can modify it to suit your needs. */

    const regex pattern(R"([a-z0-9._%+-]+@[a-z0-9.-]+\.[a-z]{2,})");
    return regex_match(email, pattern);
}

//! Student Class
class student
{
private:
    string name, roll_no, course, address, email_id;
    long long int contact_no;

public:
    void menu();
    void insert_data();
    void display_data();
    void update_data();
    void search_data();
    void deleted_data();
};

//! Peoject Menu
void student::menu()
{
menustart:
    system("cls");
    int choice;
    char x;
    cout << "\t\t\t\t\t\t>>----------------------------------------------------------------<<" << endl;
    cout << "\t\t\t\t\t\t                | STUDENT MANAGEMENT SYSTEM |" << endl;
    cout << "\t\t\t\t\t\t                        >---- UGV ----<" << endl;
    cout << "\t\t\t\t\t\t>>----------------------------------------------------------------<<" << endl;
    cout << "\t\t\t\t\t\t\t            1. Enter New Record" << endl;
    cout << "\t\t\t\t\t\t\t            2. Display Record" << endl;
    cout << "\t\t\t\t\t\t\t            3. Update Record" << endl;
    cout << "\t\t\t\t\t\t\t            4. Search Record" << endl;
    cout << "\t\t\t\t\t\t\t            5. Delete Record" << endl;
    cout << "\t\t\t\t\t\t\t            6. Exit" << endl;

    cout << "\t\t\t\t\t\t\t    ......................................." << endl;
    cout << "\t\t\t\t\t\t\t       Choose Options : 1 /2 /3 /4 /5 /6 " << endl;
    cout << "\t\t\t\t\t\t\t    ......................................." << endl;
    cout << "\n\t\t\t\t\t\t Enter Your Choose : ";
    cin >> choice;
    switch (choice)
    {
    case 1:
        do
        {
            insert_data();
            cout << "\n\n\t\t\t\t\t\t Add Another Student Record (Y, N) : ";
            cin >> x;
            if (x == 'Y' || x == 'y')
            {
                insert_data();
            }
            else if (x == 'N' || x == 'n')
            {
                goto menustart;
            }
        } while (0);
        break;
    case 2:
        display_data();
        break;
    case 3:
        update_data();
        break;
    case 4:
        search_data();
        break;
    case 5:
        deleted_data();
        break;
    case 6:
        cout << "\n\n\t\t\t Program Is Exit";
        exit(0);
    default:
        cout << "\n\n\t\t\t Invalid Choice... Please Try Again...!";
    }

    getch();
    goto menustart;
}

//! Add student details
void student::insert_data()
{
    system("cls");
    ofstream outputFile; // Opening a file for Writing
    cout << "\n\t\t\t\t\t\t>-------------------------------------------------------------------------------------------------------<" << endl;
    cout << "\t\t\t\t\t\t>------------------------------------- Add Student Details ---------------------------------------------<" << endl;
    cout << "\n\t\t\t\t\t\t Please enter data of Student...\n";
    cout << "\n\t\t\t\t\t\t\t\t       Enter Name: ";
    cin >> name;
    cout << "\n\t\t\t\t\t\t\t\t       Enter Roll No: ";
    cin >> roll_no;
    cout << "\n\t\t\t\t\t\t\t\t       Enter Course: ";
    cin >> course;

email:
    cout << "\n\t\t\t\t\t\t\t\t       Enter Email Id(name@gmail.com): ";
    cin >> email_id;
    if (isValidEmail(email_id))
    {
        cout << "\t\t\t\t\t\t\t\t       Your Email-Id is Valid!" << endl;
    }
    else
    {
        cout << "\t\t\t\t\t\t\t\t       Your Email-Id is InValid!" << endl;
        goto email;
    }

contact:
    cout << "\n\t\t\t\t\t\t\t\t       Enter Contact No(+88xxxxxx): ";
    cin >> contact_no;
    if (contact_no < 1000000000 && contact_no > 9999999999)
    {
        cout << "\t\t\t\t\t\t\t\t       Please Enter Only 10 Digits..." << endl;
        goto contact;
    }

    cout << "\n\t\t\t\t\t\t\t\t       Enter Address: ";
    cin >> address;

    outputFile.open("StudentInfo.txt", ios::app | ios::out);
    outputFile << " " << name << " " << roll_no << " " << course << " " << email_id << " " << contact_no << " " << address << endl; // Writing to Files
    outputFile.close();
    cout << "\n\n\t\t\t\t\t\t Data is stored!....." << endl;
}

//! Display Record of Student
void student::display_data()
{
    system("cls");
    ifstream inputFile; // Opening a file for reading
    int total = 0;
    cout << "\n\t\t\t\t\t\t>-----------------------------------------------------------------------------------------------<" << endl;
    cout << "\t\t\t\t\t\t>------------------------------- All Student Record Table --------------------------------------<" << endl;
    inputFile.open("StudentInfo.txt", ios::in);
    if (!inputFile.is_open()) // Perform file reading operations
    {
        cout << "\n\t\t\t\t\t\t Error opening the file... ";
        inputFile.close();
    }
    else
    {
        inputFile >> name >> roll_no >> course >> email_id >> contact_no >> address; // Reads an string from the file
        while (!inputFile.eof())
        {
            cout << "\n\n\t\t\t\t\t\t\t\t       Student No.: " << ++total << endl;
            cout << "\t\t\t\t\t\t\t\t       Name: " << name << endl;
            cout << "\t\t\t\t\t\t\t\t       Roll No.: " << roll_no << endl;
            cout << "\t\t\t\t\t\t\t\t       Course: " << course << endl;
            cout << "\t\t\t\t\t\t\t\t       Email Id: " << email_id << endl;
            cout << "\t\t\t\t\t\t\t\t       Contact No.: " << contact_no << endl;
            cout << "\t\t\t\t\t\t\t\t       Address: " << address << endl;
            inputFile >> name >> roll_no >> course >> email_id >> contact_no >> address; // Reads an string from the file
        }
        if (total == 0)
        {
            cout << "\n\n\t\t\t\t\t\t There is no student data record...!" << endl;
        }
    }
    inputFile.close();
}

//! Update Record of Student
void student::update_data()
{
    system("cls");
    fstream oldFile, newFile; // Opening a file for both reading and writing
    string rollno;
    int found = 0;
    cout << "\n\t\t\t\t\t\t>-----------------------------------------------------------------------------------------------<" << endl;
    cout << "\t\t\t\t\t\t>--------------------------------- Student Update Record ---------------------------------------<" << endl;
    oldFile.open("StudentInfo.txt", ios::in);
    if (!oldFile.is_open()) // Perform file reading operations
    {
        cout << "\n\t\t\t\t\t\t Error opening the file... ";
        oldFile.close();
    }
    else
    {
        cout << "\n\n\t\t\t\t\t\t Enter Roll No. Of Student Which You Want To Modify: ";
        cin >> rollno;
        newFile.open("info.txt", ios::app | ios::out);
        oldFile >> name >> roll_no >> course >> email_id >> contact_no >> address; // Reads an string from the oldFile
        while (!oldFile.eof())
        {
            if (rollno != roll_no)
            {
                newFile << " " << name << " " << roll_no << " " << course << " " << email_id << " " << contact_no << " " << address << endl; // Writing to newFile
            }
            else
            {
                cout << "\n\t\t\t\t\t\t Please enter new data of Student...\n";
                cout << "\n\t\t\t\t\t\t\t\t       Enter Name: ";
                cin >> name;
                cout << "\n\t\t\t\t\t\t\t\t       Enter Roll No: ";
                cin >> roll_no;
                cout << "\n\t\t\t\t\t\t\t\t       Enter Course: ";
                cin >> course;

            email:
                cout << "\n\t\t\t\t\t\t\t\t       Enter Email Id(name@gmail.com): ";
                cin >> email_id;
                if (isValidEmail(email_id))
                {
                    cout << "\t\t\t\t\t\t\t\t       Your Email-Id is Valid!" << endl;
                }
                else
                {
                    cout << "\t\t\t\t\t\t\t\t       Your Email-Id is InValid!" << endl;
                    goto email;
                }

            contact:
                cout << "\n\t\t\t\t\t\t\t\t       Enter Contact No(+88xxxxxx): ";
                cin >> contact_no;
                if (contact_no < 1000000000 && contact_no > 9999999999)
                {
                    cout << "\t\t\t\t\t\t\t\t       Please Enter Only 10 Digits..." << endl;
                    goto contact;
                }

                cout << "\n\t\t\t\t\t\t\t\t       Enter Address: ";
                cin >> address;

                newFile << " " << name << " " << roll_no << " " << course << " " << email_id << " " << contact_no << " " << address << endl; // Writing to newFile
                found++;
            }
            oldFile >> name >> roll_no >> course >> email_id >> contact_no >> address; // Reads an string from the oldFile
        }
        if (found == 0)
        {
            cout << "\n\n\t\t\t\t\t\t Student Roll No. Not Found...!" << endl;
        }
        newFile.close();
        oldFile.close();
        remove("StudentInfo.txt");
        rename("info.txt", "StudentInfo.txt");
    }
}

//! Search Record of Student
void student::search_data()
{
    system("cls");
    ifstream inputFile; // Opening a file for reading
    string rollno;
    int found = 0;
    cout << "\n\t\t\t\t\t\t>-----------------------------------------------------------------------------------------------<" << endl;
    cout << "\t\t\t\t\t\t>--------------------------------- Search Student Record ---------------------------------------<" << endl;
    inputFile.open("StudentInfo.txt", ios::in);
    if (!inputFile.is_open())
    {
        cout << "\n\t\t\t\t\t\t Error opening the file... ";
        inputFile.close();
    }
    else
    {
        cout << "\n\n\t\t\t\t\t\t Enter Roll No. Of Student Which You Want To Search: ";
        cin >> rollno;
        inputFile >> name >> roll_no >> course >> email_id >> contact_no >> address; // Reads an string from the file
        while (!inputFile.eof())
        {
            if (rollno == roll_no)
            {
                cout << "\n\n\t\t\t\t\t\t\t\t\t       Name: " << name << endl;
                cout << "\t\t\t\t\t\t\t\t\t       Roll No.: " << roll_no << endl;
                cout << "\t\t\t\t\t\t\t\t\t       Course: " << course << endl;
                cout << "\t\t\t\t\t\t\t\t\t       Email Id: " << email_id << endl;
                cout << "\t\t\t\t\t\t\t\t\t       Contact No.: " << contact_no << endl;
                cout << "\t\t\t\t\t\t\t\t\t       Address: " << address << endl;
                found++;
            }
            inputFile >> name >> roll_no >> course >> email_id >> contact_no >> address; // Reads an string from the file
        }
        if (found == 0)
        {
            cout << "\n\n\t\t\t\t\t\t Student Roll No. Not Found...!" << endl;
        }
    }
    inputFile.close();
}

//! Delete Record of Student
void student::deleted_data()
{
    system("cls");
    fstream oldFile, newFile; // Opening a file for both reading and writing
    string rollno;
    int found = 0;
    cout << "\n\t\t\t\t\t\t>-----------------------------------------------------------------------------------------------<" << endl;
    cout << "\t\t\t\t\t\t>--------------------------------- Delete Student Record ---------------------------------------<" << endl;
    oldFile.open("StudentInfo.txt", ios::in);
    if (!oldFile.is_open()) // Perform file reading operations
    {
        cout << "\n\t\t\t\t\t\t Error opening the file... ";
        oldFile.close();
    }
    else
    {
        cout << "\n\n\t\t\t\t\t\t Enter Roll No. Of Student Which You Want To Search: ";
        cin >> rollno;
        newFile.open("info.txt", ios::app | ios::out);
        oldFile >> name >> roll_no >> course >> email_id >> contact_no >> address; // Reads an string from the file
        while (!oldFile.eof())
        {
            if (rollno != roll_no)
            {
                newFile << " " << name << " " << roll_no << " " << course << " " << email_id << " " << contact_no << " " << address << endl; // Writing to newFile
            }
            else
            {
                found++;
                cout << "\n\n\t\t\t\t\t\t\t\t\t Successfully Delete Data...";
            }
            oldFile >> name >> roll_no >> course >> email_id >> contact_no >> address; // Reads an string from the file
        }
        if (found == 0)
        {
            cout << "\n\n\t\t\t\t\t\t Student Roll No. Not Found...!" << endl;
        }
        newFile.close();
        oldFile.close();
        remove("StudentInfo.txt");
        rename("info.txt", "StudentInfo.txt");
    }
}

int main()
{
    student project; // create object
    project.menu();  // object calling
    return 0;
}