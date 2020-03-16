//
// Created by Dmitry Petukhov on 08/03/2020.
//

#include <iostream>
#include <fstream>
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
const char * CONTACTS_FILE_NAME = "Contacts.bin";

struct Contact
{
  char firstName[MAX_NAME_SIZE];
  char lastName[MAX_NAME_SIZE];
  int phoneNumber;
};

struct ContactsDB
{
  Contact * optrContacts;
  int numberOfContacts;
  int capacity;
};

bool LoadContacts(ContactsDB& contactsDB);
char GetOptionFromUser();
void ExecuteOption(char option, ContactsDB& contactsDB);
void AddOption(ContactsDB& contactsDB);
void DisplayOption(const ContactsDB& contactsDB);
void ResizeContactsDB(ContactsDB& contactsDB, int newCapacity);
void SaveContacts(const ContactsDB& contactsDB);
void CreateContactsFile();

int main()
{
    ContactsDB contactsDB;
    contactsDB.optrContacts = nullptr;
    contactsDB.numberOfContacts = 0;
    contactsDB.capacity = 0;

    CreateContactsFile();

    if(!LoadContacts(contactsDB))
    {
        cout << "Error reading file: " << CONTACTS_FILE_NAME << endl;
        return 0;
    }

    char option;

    do
    {
        option = GetOptionFromUser();
        ExecuteOption(option, contactsDB);

    }while(option != 'q');

    SaveContacts(contactsDB);

    if(contactsDB.optrContacts != nullptr)
    {
        delete [] contactsDB.optrContacts;
        contactsDB.optrContacts = nullptr;
    }

    return 0;
}

void CreateContactsFile()
{
    ifstream inFile;

    inFile.open(CONTACTS_FILE_NAME, fstream::binary);
    if(!inFile.is_open())
    {
        ofstream outFile;

        outFile.open(CONTACTS_FILE_NAME, fstream::binary);
        outFile << flush; // makes 0 byte file
        outFile.close();
    }
    else
    {
        inFile.close();
    }
}

bool LoadContacts(ContactsDB& contactsDB)
{
    ifstream inFile;

    inFile.open(CONTACTS_FILE_NAME, fstream::binary);

    if(inFile.is_open())
    {
        inFile.seekg(0, inFile.end);
        int lengthOfFileInBytes = inFile.tellg();
        inFile.seekg(0, inFile.beg);

        int numberOfContacts = lengthOfFileInBytes / sizeof(Contact);
        int capacity = numberOfContacts * 2 + 10;

        contactsDB.optrContacts = new Contact[capacity];
        contactsDB.numberOfContacts = numberOfContacts;
        contactsDB.capacity = capacity;

        inFile.read((char*)contactsDB.optrContacts, lengthOfFileInBytes);

        inFile.close();

        return true;
    }

    return false;
}

void SaveContacts(const ContactsDB& contactsDB)
{
    ofstream outFile;

    outFile.open(CONTACTS_FILE_NAME, fstream::binary);

    if(outFile.is_open())
    {
        outFile.write((char*)contactsDB.optrContacts, contactsDB.numberOfContacts * sizeof(Contact));
        outFile.close();
    }
}

char GetOptionFromUser()
{
    const char options[] = {'d', 'a', 'q'};
    return GetCharacter("Please choose an option:\n\n(D)isplay Contacts\n(A)dd Contacts\n(Q)uit\n\nWhat is your choice: ", INPUT_ERROR_STRING, options, 3, CC_LOWER_CASE);
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
    }
}

void AddOption(ContactsDB& contactsDB)
{
    if(contactsDB.numberOfContacts == contactsDB.capacity)
    {
        ResizeContactsDB(contactsDB, contactsDB.capacity * 2 + 10);
    }

    GetString("Please enter the first name: ", INPUT_ERROR_STRING, contactsDB.optrContacts[contactsDB.numberOfContacts].firstName, MAX_NAME_SIZE - 1); // - 1 because without null character
    GetString("Please enter the last name: ", INPUT_ERROR_STRING, contactsDB.optrContacts[contactsDB.numberOfContacts].lastName, MAX_NAME_SIZE - 1);

    cout << "Please input the phone number: ";
    cin >> contactsDB.optrContacts[contactsDB.numberOfContacts].phoneNumber;

    contactsDB.numberOfContacts++;

    SaveContacts(contactsDB);

    cout << "Saved!" << endl;

}

void DisplayOption(const ContactsDB& contactsDB)
{
    for(int i = 0; i < contactsDB.numberOfContacts; i++ )
    {
        cout << "Name: " << contactsDB.optrContacts[i].firstName << " " << contactsDB.optrContacts[i].lastName << endl;
        cout << "Phone number: " << contactsDB.optrContacts[i].phoneNumber << endl << endl;
    }
}

void ResizeContactsDB(ContactsDB& contactsDB, int newCapacity)
{
    // make new array of size newCapacity
    Contact* newContactsPtr = new Contact[newCapacity];

    // copy all existing contacts into the new array

    for(int i = 0; i < contactsDB.numberOfContacts; i++)
    {
        strcpy(newContactsPtr[i].firstName, contactsDB.optrContacts[i].firstName);
        strcpy(newContactsPtr[i].lastName, contactsDB.optrContacts[i].lastName);
        newContactsPtr[i].phoneNumber = contactsDB.optrContacts[i].phoneNumber;
    }

    // delete the old array
    if(contactsDB.optrContacts != nullptr)
    {
        delete [] contactsDB.optrContacts;
        contactsDB.optrContacts = nullptr;
    }

    // set the contactsDB.optrContacts = new array
    contactsDB.optrContacts = newContactsPtr;
    contactsDB.capacity = newCapacity;
}
