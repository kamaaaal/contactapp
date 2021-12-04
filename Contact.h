#ifndef CONTACT_H
#define CONTACT_H

#include <iostream>
#include <string>

using std::cin;
using std::cout;
using std::endl;
using std::string;

class Contact
{
    // private Attributes
private:
    int contactID;
    string name{""};
    string number{""};
    string email{""};
    //public attributes
public:
    // constructor
    Contact(string name, string number, string email)
        : name{name}, number{number}, email{email}
    {
    }
    Contact()
    {
        cout << "Enter contact Name : ";
        getline(cin, this->name);
        cout << "Enter Phone Number : ";
        getline(cin, this->number);
        cout << "Enter Email : ";
        getline(cin, this->email);
    }
    string getName()
    {
        return this->name;
    }
    void brief()
    {
        cout << this->name << " - " << this->number << endl;
    }
    void contactDetails()
    {
        cout << this->name << endl;
        cout << this->number << endl;
        cout << this->email << endl;
    }
    void editContact()
    {
        string tempName;
        string tempNumber;
        string tempEmail;
        char option;

        // printing original details
        cout << "\nOriginal details" << endl;
        this->contactDetails();

        // implementation for edit
        cout << "EDIT CONTACT (simply press Enter on fields which you dont want to edit)" << endl;
        cout << "Enter new name: ";
        getline(cin, tempName);
        cout << "Enter new phone Number: ";
        getline(cin, tempNumber);
        cout << "Enter new Email: ";
        getline(cin, tempEmail);

        cout << "Do you want to save the changes(y/n): ";
        cin >> option;

        if (option == 'y' || option == 'Y')
        {
            this->name = tempName.empty() ? this->name : tempName;
            this->number = tempNumber.empty() ? this->number : tempNumber;
            this->email = tempEmail.empty() ? this->email : tempEmail;
            cout << "changes are made" << endl;
        }
        else if (option == 'n' || option == 'N')
        {
            cout << "Discarded Changes" << endl;
        }
    }
};
#endif