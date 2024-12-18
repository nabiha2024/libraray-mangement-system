#include <iostream>
#include <string>
using namespace std;

const int MAX_ITEMS = 100; // Maximum number of items
string item_names[MAX_ITEMS]; // Array to store item names
int item_quantities[MAX_ITEMS]; // Array to store item quantities
float item_prices[MAX_ITEMS]; // Array to store item prices
int item_count = 0; // Current number of items

// Function to add an item
void add_item() {
    if (item_count >= MAX_ITEMS) {
        cout << "Inventory is full. Cannot add more items.\n";
        return;
    }
    cout << "Enter item name: ";
    cin >> item_names[item_count];
    cout << "Enter quantity: ";
    cin >> item_quantities[item_count];
    cout << "Enter price: ";
    cin >> item_prices[item_count];
    item_count++;
    cout << "Item added successfully.\n";
}

// Function to view all items
void view_items() {
    if (item_count == 0) {
        cout << "No items to display.\n";
        return;
    }
    cout << "Inventory Items:\n";
    for (int i = 0; i < item_count; i++) {
        cout << i + 1 << ". Name: " << item_names[i]
             << ", Quantity: " << item_quantities[i]
             << ", Price: " << item_prices[i] << endl;
    }
}

// Function to update an item
void update_item() {
    if (item_count == 0) {
        cout << "No items to update.\n";
        return;
    }
    string search_name;
    cout << "Enter the name of the item to update: ";
    cin >> search_name;

    // Search for the item
    for (int i = 0; i < item_count; i++) {
        if (search_name == item_names[i] ) {
            int subChoice;
            cout << "1. Update Quantity\n";
            cout << "2. Update Price\n";
            cout << "Enter your choice: ";
            cin >> subChoice;

            if (subChoice == 1) {
                cout << "Enter new quantity: ";
                cin >> item_quantities[i];
                cout << "Quantity updated successfully.\n";
            } else if (subChoice == 2) {
                cout << "Enter new price: ";
                cin >> item_prices[i];
                cout << "Price updated successfully.\n";
            } else {
                cout << "Invalid choice.\n";
            }
            return;
        }
    }
    cout << "Item not found.\n";
}

int main() {
    int choice;

    do {
        // Display menu
        cout << "\nInventory Menu:\n";
        cout << "1. Add Item\n";
        cout << "2. View Items\n";
        cout << "3. Update Item\n";
        cout << "4. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        // Handle menu choices using functions
        switch (choice) {
            case 1:
                add_item();
                break;
            case 2:
                view_items();
                break;
            case 3:
                update_item();
                break;
            case 4:
                cout << "Exiting program.\n";
                break;
            default:
                cout << "Invalid choice. Please try again.\n";
        }
    } while (choice != 4);

    return 0;
}
