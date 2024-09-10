#include <iostream>
#include <fstream>
#include <stdexcept>
#include  "Header.h" 

using namespace std;


int main() {
    int arr[MAX_SIZE];
    int size = readDataFromFile("A1input.txt", arr, MAX_SIZE);

    if (size == -1) {
        return 1; // Exit if there was an issue reading the file
    }

    int choice, value, index, oldValue;
    bool success;

    while (true) {
        cout << "Menu:\n";
        cout << "1. Find value\n";
        cout << "2. Modify value\n";
        cout << "3. Add value\n";
        cout << "4. Replace or remove value\n";
        cout << "5. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
        case 1:
            cout << "Enter value to find: ";
            cin >> value;
            index = findValue(arr, size, value);
            if (index != -1) {
                cout << "Value found at index: " << index << endl;
            }
            else {
                cout << "Value not found." << endl;
            }
            break;

        case 2:
            try {
                cout << "Enter index to modify: ";
                cin >> index;
                cout << "Enter new value: ";
                cin >> value;
                modifyValue(arr, size, index, value, oldValue);
                cout << "Old value: " << oldValue << ", New value: " << value << endl;
            }
            catch (const out_of_range& e) {
                cout << "Error: " << e.what() << endl;
            }
            break;

        case 3:
            cout << "Enter value to add: ";
            cin >> value;
            success = addValue(arr, size, value);
            if (success) {
                cout << "Value added successfully." << endl;
            }
            else {
                cout << "Array is full, cannot add value." << endl;
            }
            break;

        case 4:
            try {
                cout << "Enter index to replace or remove: ";
                cin >> index;
                cout << "Replace with 0 (1) or Remove (2)? ";
                cin >> value;
                replaceOrRemove(arr, size, index, value == 2);
                cout << (value == 2 ? "Value removed." : "Value replaced with 0.") << endl;
            }
            catch (const out_of_range& e) {
                cout << "Error: " << e.what() << endl;
            }
            break;

        case 5:
            cout << "Exiting..." << endl;
            return 0;

        default:
            cout << "Invalid choice. Please try again." << endl;
        }
    }

    return 0;
}