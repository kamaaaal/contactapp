#include <iostream>
#include <string>
#include <vector>
#include "Contact.h"
#include "phonebook.h"

using std::cout;

int main(int argc, char *argv[])
{
    Phonebook pb;
    /*     pb.addContact();
    pb.addContact();
    pb.addContact();
    pb.listContacts();
    pb.viewContact();
    pb.deleteContact();
    pb.listContacts(); */
    while (true)
    {
        char option;
        cout << "(A) Add contact" << endl;
        cout << "(L) list contacts" << endl;
        cout << "(V) View contact" << endl;
        cout << "(E) Edit contact" << endl;
        cout << "(D) Delete Contact" << endl;
        cout << "(X) Exit App" << endl;

        cin >> option;
        cin.ignore(256, '\n'); // for not to overlap other inputs

        cout << "\n";

        if (option == 'A' || option == 'a')
        {
            pb.addContact();
        }
        else if (option == 'L' || option == 'l')
        {
            pb.listContacts();
        }
        else if (option == 'V' || option == 'v')
        {
            pb.viewContact();
        }
        else if (option == 'E' || option == 'e')
        {
            pb.editContact();
        }
        else if (option == 'D' || option == 'd')
        {
            pb.deleteContact();
        }
        else if (option == 'X' || option == 'x')
        {
            cout << "exited" << endl;
            break;
        }
    }
}