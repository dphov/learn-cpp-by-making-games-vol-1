//
// Created by Dmitry Petukhov on 08/03/2020.
//

#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#include "Utils.h"

using namespace std;

/*
 * Problem: Write a program that will keep a list of contacts.
 * The contact will have a name (first name and last name), and a phone number (no dashes).
 * The program will read in all the saved contacts at the start of program.
 * The user will be able to either look at all their contacts or add a new contact or quit the app.
 * Once the contact is added it should be saved. The names should be no more than 256 characters.
 */

const int MAX_NAME_SIZE = 256;
const char * INPUT_ERROR_STRING = "Input error! Please try again.";
const char * CONTACTS_FILE_NAME = "Contacts.txt";

struct Contact
{
  string firstName;
  string lastName;
  int phoneNumber;
};

struct ContactsDB
{
  vector<Contact> contacts;
};

bool LoadContacts(ContactsDB & contactsDB);
void SaveContacts(const ContactsDB & contactsDB);
char GetOptionFromUser();
void ExecuteOption(char option, ContactsDB & contactsDB);
void DisplayOption(ContactsDB & contactsDB);
void AddOption(ContactsDB & contactsDB);
void RemoveOption(ContactsDB & contactsDB);

bool CompareFirstName(const Contact & c1, const Contact & c2);
bool CompareLastName(const Contact & c1, const Contact & c2);

int main()
{
    ContactsDB contactsDB;

    LoadContacts(contactsDB);

    char option;

    do
    {
        option = GetOptionFromUser();
        ExecuteOption(option, contactsDB);

    }while(option != 'q');

    SaveContacts(contactsDB);

    return 0;
}
//
//void CreateContactsFile()
//{
//    ifstream inFile;
//
//    inFile.open(CONTACTS_FILE_NAME, fstream::binary);
//    if(!inFile.is_open())
//    {
//        ofstream outFile;
//
//        outFile.open(CONTACTS_FILE_NAME, fstream::binary);
//        outFile << flush; // makes 0 byte file
//        outFile.close();
//    }
//    else
//    {
//        inFile.close();
//    }
//}

bool LoadContacts(ContactsDB& contactsDB)
{
    ifstream inFile;

    inFile.open(CONTACTS_FILE_NAME);

    if(inFile.is_open())
    {
        Contact newContact;

        while (!inFile.eof())
        {
            inFile >> ws;
            if(inFile.eof())
                break;

            inFile >> newContact.firstName >> newContact.lastName >> newContact.phoneNumber;
            contactsDB.contacts.push_back(newContact);
        }

        inFile.close();

        return true;
    }

    return false;
}

void SaveContacts(const ContactsDB& contactsDB)
{
    ofstream outFile;

    outFile.open(CONTACTS_FILE_NAME);

    if(outFile.is_open())
    {
        for(int i = 0; i < contactsDB.contacts.size(); i++)
        {
            outFile << contactsDB.contacts[i].firstName << " " << contactsDB.contacts[i].lastName << " " << contactsDB.contacts[i].phoneNumber;

            // making sure that there is no newline at the end of the file
            if(i < contactsDB.contacts.size() - 1)
            {
                outFile << endl;
            }
        }
        outFile.close();
    }
}

char GetOptionFromUser()
{
    const char options[] = {'d', 'a', 'r', 'q',};
    return GetCharacter("Please choose an option:\n\n(D)isplay Contacts\n(A)dd Contact\n(R)Remove contact\n(Q)uit\n\nWhat is your choice: ", INPUT_ERROR_STRING, options, 4, CC_LOWER_CASE);
}

void ExecuteOption(char option, ContactsDB& contactsDB)
{
    switch(option)
    {
        case 'a':
            AddOption(contactsDB);
            break;
        case 'd':
            DisplayOption(contactsDB);
            break;
        case 'r':
            RemoveOption(contactsDB);
            break;
    }
}

void AddOption(ContactsDB& contactsDB)
{
    Contact newContact;

    GetString("Please enter the first name: ", INPUT_ERROR_STRING, newContact.firstName);
    GetString("Please enter the last name: ", INPUT_ERROR_STRING, newContact.lastName);

    cout << "Please input the phone number: ";
    cin >> newContact.phoneNumber;

    contactsDB.contacts.push_back(newContact);

    SaveContacts(contactsDB);

    cout << "Saved!" << endl;
}

void DisplayOption(ContactsDB & contactsDB)
{
    if(contactsDB.contacts.size() <= 0)
    {
        cout << "You have no contacts!" << endl;
        return;
    }

    const char sortOptions[] = {'f', 'l'};

    char option;
    option = GetCharacter("Please choose a sort option:\n\n(F)irst Name\n(L)ast name\n\nWhat is your choice: ", INPUT_ERROR_STRING, sortOptions, 2, CC_LOWER_CASE);

    if(option == sortOptions[0])
    {
        //first name
        sort(contactsDB.contacts.begin(), contactsDB.contacts.end(), CompareFirstName);
    }
    else
    {
        sort(contactsDB.contacts.begin(), contactsDB.contacts.end(), CompareLastName);
    }

    for(int i = 0; i < contactsDB.contacts.size(); i++ )
    {
        cout << "Name: " << contactsDB.contacts[i].firstName << " " << contactsDB.contacts[i].lastName << endl;
        cout << "Phone number: " << contactsDB.contacts[i].phoneNumber << endl << endl;
    }
}

bool CompareFirstName(const Contact & c1, const Contact & c2)
{
    return c1.firstName < c2.firstName;
}

bool CompareLastName(const Contact & c1, const Contact & c2)
{
    return c1.lastName < c2.lastName;
}

void RemoveOption(ContactsDB &contactsDB)
{
    if(contactsDB.contacts.size() <= 0)
    {
        cout << "No contacts in the list!" << endl;
        return;
    }

    string firstName;
    string lastName;

    GetString("Please enter first name: ", INPUT_ERROR_STRING, firstName);
    GetString("Please enter last name: ", INPUT_ERROR_STRING, lastName);

    bool found = false;

    int foundIndex = -1;

    for(int i = 0; i < contactsDB.contacts.size() && !found; i++)
    {
        if(contactsDB.contacts[i].firstName == firstName && contactsDB.contacts[i].lastName == lastName)
        {
            found = true;
            foundIndex = i;
        }
    }

    if(found)
    {
        swap(contactsDB.contacts[foundIndex], contactsDB.contacts[contactsDB.contacts.size() - 1]); // put the found index at the end
        contactsDB.contacts.pop_back();
        cout << "Removed " << firstName << " " << lastName << " from contacts." << endl;
    }
    else
    {
        cout << "Could not find: " << firstName << " " << lastName << " in contacts." << endl;
    }
}
