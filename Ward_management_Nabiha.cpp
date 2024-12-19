#include<iostream>
#include<string>

using namespace std;

const int NUM_WARDS = 3, NUM_BEDS = 6;

// Function to display the ward status
void displayStatus(string wards[NUM_WARDS][NUM_BEDS]) {
    cout << "\nWard Status:\n";
    for (int i = 0; i < NUM_WARDS; i++) {
        cout << "Ward " << i + 1 << ": ";
        for (int j = 0; j < NUM_BEDS; j++) {
            if (wards[i][j].empty()) {
                cout << "[Empty] ";
            } else {
                cout << "[" << wards[i][j] << "] ";
            }
        }
        cout << endl;
    }
}

// Function to manage bed allocation and discharge
void manageBed(string wards[NUM_WARDS][NUM_BEDS], bool allocate) {
    int ward, bed;
    cout << "Enter ward (1-" << NUM_WARDS << ") and bed (1-" << NUM_BEDS << "): ";
    cin >> ward >> bed;

    if (ward < 1 || ward > NUM_WARDS || bed < 1 || bed > NUM_BEDS) {
        cout << "Invalid input. Try again.\n";
    }

    string &current = wards[ward - 1][bed - 1];
    if (allocate) {
        if (!current.empty()) {
            cout << "Bed occupied. Try another.\n";
        } else {
            cout << "Enter patient name: ";
            cin.ignore();
            getline(cin, current);
            cout << "Bed allocated to " << current << ".\n";
        }
    } else {
        if (current.empty()) {
            cout << "Bed already empty.\n";
        } else {
            cout << "Discharging " << current << "...\n";
        }
    }
}

void displayMenuOfWards() {
    string wards[NUM_WARDS][NUM_BEDS];
    int choice;

    do {
        cout << "\nHospital Ward and Bed Management System\n";
        cout << "1. Display Ward Status\n";
        cout << "2. Allocate Bed\n";
        cout << "3. Discharge Bed\n";
        cout << "4. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                displayStatus(wards);
                break;
            case 2:
                manageBed(wards, true);
                break;
            case 3:
                manageBed(wards, false);
                break;
            case 4:
                cout << "Exiting program. Goodbye!\n";
                break;
            default:
                cout << "Invalid choice. Please try again.\n";
        }
    } while (choice != 4);
}

int main(){
	displayMenuOfWards();
	
	return 0;
}
   