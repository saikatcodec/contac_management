/**
 * ! Don't Run this file
 * @authors Group - 3 ID(22 - 32)
 * @brief Contact class provides contact method such that Add new contact, view contact,
 *        Delete, Update a contact
 * @file "phone.txt" file is used to store contact in permanently
 */
#include <fstream>
#include <iostream>
#include <list>
#include <vector>
using namespace std;

class Contact {
   private:
    string line;
    list<pair<string, string>> nums;

    /**
     * @brief Split a string into two part on basis of ':'
     *
     * @param line take a string
     * @return a pair that has two part name and phone
     */
    pair<string, string> makeSplit(string line) {
        int pos = line.find(':');
        string name = line.substr(0, pos);
        string phone = line.substr(pos + 2);

        return {name, phone};
    }

    /**
     * @brief Read the file to get name and phone number, and store it in the vector
     *          to perform the operation
     */
    void readFile() {
        ifstream file(".phone.txt");
        if (file.is_open()) {
            while (getline(file, line)) {
                nums.push_back(makeSplit(line));
            }
        } else {
            cout << "WARNING! You have no contact saved." << endl;
        }
    }

    /**
     * @brief Save the pair of vector in file system to store permanently
     */
    void writeFile() {
        ofstream file(".phone.txt");
        nums.sort();
        if (file.is_open()) {
            for (auto pair : nums) {
                file << pair.first << ": " << pair.second << endl;
            }
        } else {
            cout << "Error occurred" << endl;
        }
    }

   public:
    /**
     * @details When an instance created, the file is read and store all the number
     *          in the pair of vector
     */
    Contact() {
        readFile();
    }

    /**
     * @brief Create new contact, make pair and add the pair in vector
     *
     * @param name name of person
     * @param phone phone number of the person
     *
     * @return true if successfully creates contact
     */
    bool createContact(string name, string phone) {
        nums.push_back({name, phone});
        nums.sort();
        writeFile();
        return true;
    }

    /**
     * @brief Apply linear search with the specific key
     *
     * @param key take string to search the contact
     *
     * @return return the search results
     */
    vector<pair<string, string>> search(string key) {
        vector<pair<string, string>> results;
        for (auto p : nums) {
            if (p.first.find(key) != string::npos) {
                results.push_back(p);
            }
        }

        return results;
    }

    /**
     * @brief To delete the contact from the list
     *
     * @param keyName keyword of name
     * @param keyPhone phone number that wants to be deleted
     */
    void deleteNum(string keyName, string keyPhone) {
        nums.remove({keyName, keyPhone});
        writeFile();
    }

    /**
     * @brief Update the name of the contact
     *
     * @param keyName Name of the existing contact
     * @param keyPhone Phone number of the contact
     * @param name New name of the contact
     */
    void nameUpdate(string keyName, string keyPhone, string name) {
        for (auto &p : nums) {
            if (p.first == keyName && p.second == keyPhone) {
                p.first.assign(name);
            }
        }
        writeFile();
    }

    /**
     * @brief Update the phone number of the contact
     *
     * @param keyName Name of the existing contact
     * @param keyPhone Phone number of the contact
     * @param phone New phone number of the contact
     */
    void phoneUpdate(string keyName, string keyPhone, string phone) {
        for (auto &p : nums) {
            if (p.first == keyName && p.second == keyPhone) {
                p.second.assign(phone);
            }
        }
        writeFile();
    }

    /**
     * @brief Print out all the contact from the list
     */
    void printAll() {
        if (nums.empty()) {
            cout << endl;
            cout << "\tSORRY! No contact found." << endl;
            cout << endl;

            return;
        }
        for (auto p : nums) {
            cout << "\tName: " << p.first << endl;
            cout << "\tPhone: " << p.second << endl;
            cout << endl;
        }
    }

    /**
     * @details Destructure of the class, call the writeFile() function
     */
    ~Contact() {
        writeFile();
    }
};