#include<iostream>
#include<string>
using namespace std;
// Define a structure 'book' to store details related to a book
struct book{
    string bookname;           // Name of the book
    bool isavailable = 0;      // Availability status of the book (0 for not available, 1 for available)
    int noofbooks = 0;         // Total number of books available
    string author;             // Author of the book
    int booksborrowed = 0;     // Number of books borrowed
};
// Function to add a new book to the library or increase the count if already present
void addbook(book bookarray[10]){
    string nameofbook;
    cout << "ADDING A BOOK" << endl;
    cin.sync(); // Clear input buffer before taking the input
    getline(cin, nameofbook); // Read the name of the book
    
    bool found = 0; // Flag to check if the book already exists in the array
    // Loop through the array to check if the book is already present
    for(int i = 0; i < 10; i++){
        if(bookarray[i].bookname == nameofbook){
            found = 1;
            bookarray[i].noofbooks += 1; // If found, increase the count of the book
            cout << "BOOK ADDED SUCCESSFULLY\n";
            cout << bookarray[i].noofbooks << endl; // Display the new number of books
        }
    }
    
    // If book not found, print an error message
    if(found == 0){
        cout << "BOOK NOT FOUND\n";
    }
}
// Function to search for a book in the library
void searchbook(book bookarray[10]){
    cout << "SEARCH A BOOK" << endl;
    string bookname;
    cin.sync(); // Clear input buffer before taking the input
    getline(cin, bookname); // Read the name of the book
    
    bool found = 0; // Flag to check if the book is found
    // Loop through the array to find the book
    for(int i = 0; i < 10; i++){
        if(bookarray[i].bookname == bookname){
            found = 1;
            cout << "Name of book is " << bookarray[i].bookname << endl;
            cout << "The author of book is " << bookarray[i].author << endl;
        }
    }
    
    // If book not found, print an error message
    if(found == 0){
        cout << "BOOK NOT FOUND\n";
    }
}
// Function to borrow a book from the library
void borrow(book bookarray[10]){
    cout << "BORROWING A BOOK" << endl;
    string nameofbook;
    cin.sync(); // Clear input buffer before taking the input
    getline(cin, nameofbook); // Read the name of the book
    
    bool found = 0; // Flag to check if the book is found
    // Loop through the array to find the book
    for(int i = 0; i < 10; i++){
        if(bookarray[i].bookname == nameofbook){
            found = 1;
            // If the book is available (count > 0), decrease the count and increase borrowed count
            if(bookarray[i].noofbooks > 0){
                bookarray[i].noofbooks -= 1;
                cout << "BOOK IS BORROWED\n";
                bookarray[i].booksborrowed += 1;
            }
            else{
                cout << "BOOK NOT IN STOCK\n"; // If no books are available, show a message
            }
        }
    }
    
    // If book not found, print an error message
    if(found == 0){
        cout << "BOOK NOT FOUND\n";
    }
}
// Function to return a borrowed book to the library
void returnBook(book bookarray[10]){
    cout << "RETURNING A BOOK" << endl;
    string nameofbook;
    cin.sync(); // Clear input buffer before taking the input
    getline(cin, nameofbook); // Read the name of the book
    
    bool found = 0; // Flag to check if the book is found
    // Loop through the array to find the book
    for(int i = 0; i < 10; i++){
        if(bookarray[i].bookname == nameofbook){
            found = 1;
            // If the book has been borrowed, return it by decreasing borrowed count and increasing available count
            if(bookarray[i].booksborrowed > 0){
                bookarray[i].noofbooks += 1;
                cout << "BOOK IS RETURNED\n";
                bookarray[i].booksborrowed -= 1;
            }
            else{
                cout << "BOOK NOT BORROWED\n"; // If no books have been borrowed, show a message
            }
        }
    }
    
    // If book not found, print an error message
    if(found == 0){
        cout << "BOOK NOT FOUND\n";
    }
}
// Main function to drive the library management system
int main(){
    cout << "======WELCOME TO LIBRARY MANAGEMENT SYSTEM===== " << endl;
    
    // Array to hold information of 10 books
    book bookarray[10];
    bookarray[0].bookname = "THE LORD OF FLIES";
    bookarray[1].bookname = "THE HUNGER GAMES";
    bookarray[2].bookname = "THE GAME OF THRONES";
    bookarray[3].bookname = "THE ALCHEMIST";
    bookarray[4].bookname = "THE HOBBIT";
    bookarray[5].bookname = "ABU JINNS";
    bookarray[6].bookname = "SAPIENS";
    bookarray[7].bookname = "CRIME AND PUNISHMENT";
    bookarray[8].bookname = "FRANKENSTEIN";
    bookarray[9].bookname = "GREAT EXPECTATIONS";
    
    // Initialize author names for each book
    bookarray[0].author = "William Golding";
    bookarray[1].author = "Suzanne Collins";
    bookarray[2].author = "George R.R. Martin";
    bookarray[3].author = "Paulo Coelho";
    bookarray[4].author = "J.R.R. Tolkien";
    bookarray[5].author = "Ayesha Muzaffar";
    bookarray[6].author = "Yuval Noah";
    bookarray[7].author = "Fyodor Dostoevsky";
    bookarray[8].author = "Mary Shelley";
    bookarray[9].author = "Charles Dickens";
    
    bool continueLibrary = 1; // Flag to continue the library menu
    
    // Loop to keep showing the library options until the user chooses to exit
    do{
        int choice;
        cout << "1. ADDING A BOOK" << endl;
        cout << "2. SEARCHING A BOOK" << endl;
        cout << "3. BORROWING A BOOK" << endl;
        cout << "4. RETURNING A BOOK" << endl;
        cout << "5. EXIT" << endl;
        cout << "ENTER YOUR CHOICE (1-5)" << endl;
        cin >> choice;
        
        // Switch case to execute the corresponding function based on user choice
        switch(choice){
            case 1:
                addbook(bookarray); // Call the function to add a book
                break;
            case 2:
                searchbook(bookarray); // Call the function to search for a book
                break;
            case 3:
                borrow(bookarray); // Call the function to borrow a book
                break;
            case 4:
                returnBook(bookarray); // Call the function to return a borrowed book
                break;
            case 5:
                continueLibrary = 0; // Exit the program if the user chooses 5
                break;
            default:
                cout << "Invalid choice. Please enter a valid option." << endl; // Invalid choice handling
        }
    }
    while(continueLibrary == 1); // Continue showing options until the user chooses to exit
    
    return 0;
}