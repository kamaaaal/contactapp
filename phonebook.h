#ifndef PHONEBOOK_H
#define PHONEBOOK_H

#include <iostream>
#include <string>
#include <vector>
#include "Contact.h"

using std::cin;
using std::cout;
using std::endl;
using std::string;
using std::vector;

class Phonebook
{
    //private attributes
private:
    vector<Contact> contacts;
    vector<Contact>::iterator itStart = contacts.begin();
    vector<Contact>::iterator itEnd = contacts.end();
    // vector<Contact>::iterator it = contacts.begin();
    // vector<Contact>::iterator el = contacts.erase(it);
    // public
public:
    void listContacts()
    {
        cout << "Contact List" << endl;
        if (contacts.empty())
        {
            cout << "There are no saved contacts yet" << endl;
        }
        else if (!contacts.empty())
        {
            for (vector<Contact>::iterator it = contacts.begin(); it != contacts.end(); it++)
            {
                it->brief();
            }
            cout << "\n";
        }
    }
    void addContact()
    {
        Contact newContact;
        contacts.push_back(newContact);
    }
    void addContact(string Name, string Number, string Email)
    {
        Contact newContact(Name, Number, Email);
        contacts.push_back(newContact);
        cout << "Contact Created\n";
    }
    void viewContact()
    {
        string contactName{""};
        bool hasContactFound {false};
        cout << "Enter the contact name which you want to view : ";
        getline(cin, contactName);
        for (vector<Contact>::iterator it = contacts.begin(); it != contacts.end(); it++)
        {
            if (it->getName() == contactName)
            {
                hasContactFound = true;
                it->contactDetails();
            }
        }
        if (hasContactFound == false){
            cout << "Could not find the contact you Entered"<< endl;
        }
        cout << "\n";
    }
    void editContact() {
        string contactName{""};
        bool hasContactFound {false};
        cout << "Enter the contact name which you want to Edit : ";
        getline(cin, contactName);
        for (vector<Contact>::iterator it = contacts.begin(); it != contacts.end(); it++)
        {
            if (it->getName() == contactName)
            {
                hasContactFound = true;
                it->editContact();
            }
        }
        if (hasContactFound == false){
            cout << "Could not find the contact you Entered"<< endl;
        }
        cout << "\n";
    }
    void deleteContact()
    {
        string contactName{""};
        int contactindex;
        if (contacts.empty())
        {
            cout << "There are no saved contacts yet" << endl;
        }
        else if (!contacts.empty())
        {
            cout << "Enter the contactname to be deleted : "
                 << endl;
            getline(cin, contactName);
            for (int i = 0; i < contacts.size(); i++)
            {
                if (contacts[i].getName() == contactName)
                {
                    vector<Contact>::iterator itStart = contacts.begin();
                    itStart += i;
                    contacts.erase(itStart);
                }
            }
        }
    }
};
#endif