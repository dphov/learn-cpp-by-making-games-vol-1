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

int main()
{
    ContactsDB contactsDB;
    contactsDB.optrContacts = nullptr;
    contactsDB.numberOfContacts = 0;
    contactsDB.capacity = 0;

    LoadContacts(contactsDB);


    char option;

    do
    {
        option = GetOptionFromUser();
        ExecuteOption(option, contactsDB);

    }while(option != 'q');

    return 0;
}

bool LoadContacts(ContactsDB& contactsDB)
{
    return false;
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