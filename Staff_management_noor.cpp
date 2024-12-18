#include <iostream>
#include <string>
using namespace std;

// Structure to store staff details
struct Staff {
    int id;
    string name;
    string role;
};

// Functions 
void addStaff(Staff staffList[], int &count) {
    cout << "Enter Staff ID: ";
    cin >> staffList[count].id;
    cin.ignore(); // To clear newline from input buffer
    cout << "Enter Staff Name:  ";
    getline(cin, staffList[count].name);
    cout << "Enter Staff Role: ";
    cin>> staffList[count].role;
    count++;
    cout << "Staff added successfully.\n";
}

void showStaff(Staff staffList[], int count) {
    if (count == 0) {
        cout << "No staff available.\n";
    } else {
        for (int i = 0; i < count; i++) {
            cout << "ID: " << staffList[i].id 
                 << " Name: " << staffList[i].name 
                 << " Role: " << staffList[i].role << endl;
        }
    }
}

void searchStaff(Staff staffList[], int count) {
    int searchId;
    cout << "Enter Staff ID to search: ";
    cin >> searchId;

    bool found = false;
    for (int i = 0; i < count; i++) {
        if (staffList[i].id == searchId) {
            cout << "Staff Found - ID: " << staffList[i].id 
                 << " Name: " << staffList[i].name 
                 << " Role: " << staffList[i].role << endl;
            found = true;
            break;
        }
    }
    if (!found) {
        cout << "Staff with ID " << searchId << " not found.\n";
    }
}

void displayMenuOfStaff(){
	
	Staff staffList[50];
    int count = 0, choice;

    do {
        // Menu
        cout << "\nHospital Staff Management\n";
        cout << "1. Add Staff\n";
        cout << "2. Show All Staff\n";
        cout << "3. Search Staff\n";
        cout << "4. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        // Switch case for menu options
        switch (choice) {
            case 1:
                addStaff(staffList, count);
                break;
            case 2:
                showStaff(staffList, count);
                break;
            case 3:
                searchStaff(staffList, count);
                break;
            case 4:
                cout << "Exiting program. Goodbye!\n";
                break;
            default:
                cout << "Invalid choice. Try again.\n";
        }
    } while (choice != 4);
}
    
    int main(){
    	displayMenuOfStaff();
    	
    	return 0;
	}
   

