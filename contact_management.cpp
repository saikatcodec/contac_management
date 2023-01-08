/**
 * * Run This File
 * @author Group - 3 ID(22 - 32)
 * @brief Driver code.
 */
#include <stdlib.h>

#include <iostream>
#include <vector>
using namespace std;
#include "Contact.cpp"

// Prototyping the function

void Clear();
bool search(Contact &, string);
void create(Contact &);
void deletePhn(Contact &, string);
void update(Contact &);

int main() {
    // At first, Clear the console
    Clear();
    // Welcome texts of the app
    cout << endl;
    cout << "##############################" << endl;
    cout << "           CONTACT            " << endl;
    cout << "   Save your contact here.    " << endl;
    cout << "##############################" << endl;
    cout << endl;
    cout << "==============================" << endl;
    cout << "           MAIN MENU          " << endl;
    cout << "==============================" << endl;
    cout << "   [1] Search contact" << endl;
    cout << "   [2] Create new contact" << endl;
    cout << "   [3] Update existing contact" << endl;
    cout << "   [4] Delete a existing contact" << endl;
    cout << "   [5] See all contact" << endl;
    cout << "   [0] Exit from the app" << endl;
    cout << endl;

    // Create instance of Contact class
    Contact contact = Contact();

    int menu;
    bool start = true;
    while (start) {
        cout << "Enter menu number: ";
        cin >> menu;

        switch (menu) {
            // Search Option
            case 1: {
                string key;
                cout << "============" << endl;
                cout << "\tSEARCH" << endl;
                cout << "\t  ============" << endl;
                cout << "\tEnter name to search the contact: ";
                cin.ignore();
                getline(cin, key);
                bool flag = search(contact, key);
                break;
            }
            // Create New Contact Option
            case 2: {
                create(contact);
                break;
            }
            // Update Option
            case 3: {
                string key;
                cout << "============" << endl;
                cout << "\tUPDATE" << endl;
                cout << "\t  ============" << endl;
                cout << "\tEnter name to inquiry the contact: ";
                cin.ignore();
                getline(cin, key);
                if (search(contact, key)) {
                    update(contact);
                }
                break;
            }
            // Delete Option
            case 4: {
                string key;
                cout << "============" << endl;
                cout << "\tDELETE" << endl;
                cout << "\t  ============" << endl;
                cout << "\tEnter name to inquiry the contact: ";
                cin.ignore();
                getline(cin, key);
                if (search(contact, key)) {
                    deletePhn(contact, key);
                }
                break;
            }
            // All Option
            case 5: {
                cout << "============" << endl;
                cout << "\tLIST OF ALL CONTACT" << endl;
                cout << "\t  ============" << endl;
                contact.printAll();
                break;
            }
            // Exit Option
            case 0: {
                start = false;
                break;
            }
            // Error Section
            default: {
                cout << endl;
                cout << "WARNING! Error Ocurred" << endl;
                cout << "Entered wrong menu number" << endl;
                cout << endl;
            }
        }
    }

    // Exiting message
    cout << endl;
    cout << "##############################" << endl;
    cout << "     Closing the app......    " << endl;
    cout << "         Thanks from          " << endl;
    cout << "         Group - 3 ID(22 - 32)" << endl;
    cout << "##############################" << endl;

    return 0;
}

/**
 * @brief To clear the console
 */
void Clear() {
// For Windows
#if defined _WIN32
    system("cls");
// For Linux
#elif defined(__LINUX__) || defined(__gnu_linux__) || defined(__linux__)
    system("clear");
// For Mac(Apple Device)
#elif defined(__APPLE__)
    system("clear");
#endif
}

/**
 * @brief To search the number with respect to the name. And
 *          multiple name can be showed
 *
 * @param contact contact passes like a reference
 * @param key The searching keyword
 *
 * @return true if results found
 */
bool search(Contact &contact, string key) {
    vector<pair<string, string>> results;
    results = contact.search(key);
    if (results.empty()) {
        cout << "\tSORRY! No contact found." << endl;
        cout << endl;
        return false;
    } else {
        for (auto result : results) {
            cout << "\t\tName: " << result.first << endl;
            cout << "\t\tPhone: " << result.second << endl;
            cout << endl;
        }
        return true;
    }
}

/**
 * @brief To create contact. And save to the file
 *
 * @param contact passes like a contact reference
 */
void create(Contact &contact) {
    string name, phone;
    cout << "============" << endl;
    cout << "\tCREATE NEW CONTACT" << endl;
    cout << "\t  ============" << endl;
    cout << "\tEnter name: ";
    cin.ignore();
    getline(cin, name);
    cout << "\tEnter phone number: ";
    cin >> phone;
    if (contact.createContact(name, phone)) {
        cout << "\tContact saved successfully" << endl;
    } else {
        cout << "\tError ocurred while saving contact" << endl;
    }

    cout << endl;
}

/**
 * @brief To delete the contact
 *
 * @param contact reference of contact
 * @param key keyword of name
 */
void deletePhn(Contact &contact, string key) {
    string number;
    cout << "\tEnter full name of contact: ";
    getline(cin, key);
    cout << "\tEnter the phone number to confirm the operation: ";
    cin >> number;

    contact.deleteNum(key, number);
    cout << "\tDelete Successfully" << endl;
    cout << endl;
}

/**
 * @brief To update the contact
 *
 * @param contact reference of contact
 */
void update(Contact &contact) {
    int choice;
    cout << "\t[1] Update the name" << endl;
    cout << "\t[2] Update the phone number" << endl;
    cout << endl;
    cout << "\tChoose the menu: ";
    cin >> choice;
    if (choice > 2) {
        cout << "\tERROR! Select right menu number." << endl;
        cout << endl;
        return;
    }
    string number, key;
    cout << "\tEnter full name of contact: ";
    cin.ignore();
    getline(cin, key);
    cout << "\tEnter the phone number to confirm the operation: ";
    cin >> number;

    if (choice == 1) {
        string name;
        cout << "\tNew name of the contact: ";
        cin.ignore();
        getline(cin, name);
        contact.nameUpdate(key, number, name);
    } else if (choice == 2) {
        string newNumber;
        cout << "\tNew number of the contact: ";
        cin >> newNumber;
        contact.phoneUpdate(key, number, newNumber);
    }
    cout << endl;
}