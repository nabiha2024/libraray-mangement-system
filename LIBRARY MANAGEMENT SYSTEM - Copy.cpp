#include<iostream>
#include<string>
using namespace std;

struct Book{
	string name;
	string author;
};

void addBook(Book books[], int &bookCount) {
    string bookName, bookAuthorName;
    cout << "Enter book name: ";
    cin.ignore(); 
    getline(cin, bookName);
    cout << "Enter author name: ";
    getline(cin, bookAuthorName);

    // Check if the book already exists
    for (int i = 0; i < bookCount; i++) {
        if (books[i].name == bookName) {
            cout << "Book already exist." << endl;
            return;
        }
    }
        	// Add new book
        	books[bookCount].name = bookName;
            books[bookCount].author = bookAuthorName;
            bookCount++;
    cout << "New book added successfully!" << endl;
}


void borrowBook(Book books[], int bookCount) {
    string bookName;
    cout << "Enter the name of the book you want to borrow: ";
    cin.ignore();
    getline(cin, bookName);

    for (int i = 0; i < bookCount; i++) {
        if (books[i].name == bookName) {
                cout << "You have successfully borrowed the book: " << bookName << endl;
                return;
            }
        }
                     cout << "Book not found!" << endl;
                     return;
        
   
}

void returnBook(Book books[], int bookCount) {
    string bookName;
    cout << "Enter the name of the book you want to return: ";
    cin.ignore();
    getline(cin, bookName);

    for (int i = 0; i < bookCount; i++) {
        if (books[i].name == bookName) {
            cout << "You have successfully returned the book: " << bookName << endl;
            return;
        }
    }
		cout << "This book is not borrowed from this library." << endl;
		return;
}

void displayBooks(Book books[], int bookCount) {
    cout << "\n=====Books in the Library ======\n";
    cout<<"\n";
    for (int i = 0; i < bookCount; i++) {
        cout << i+1 <<" Book Name: " << books[i].name << "\n Author: " << books[i].author << endl;
    }
}

int main() {
    Book books[100];
    int bookCount = 9;
    
    books[0].name ="THE LORD OF FLIES";
    books[1].name ="THE HUNGER GAMES";
    books[2].name ="THE GAME OF THRONES";
    books[3].name ="THE ALCHEMIST";
    books[4].name ="THE HOBBIT";
    books[5].name ="ABU JINNS";
    books[6].name ="SAPIENS";
    books[7].name ="CRIME AND PUNISHMENT";
	books[8].name ="FRANKENSTEIN";
    books[9].name ="GREAT EXPECTATIONS";
    
	books[0].author ="Wiliam Golding";
    books[1].author ="Suzanne Collinse";
    books[2].author ="George R.R Martins";
    books[3].author ="Paulo Coelho";
    books[4].author ="J.R.R. Tolken";
    books[5].author ="Ayesha Muzaffar";
    books[6].author ="Yuval Noah";
    books[7].author ="Fyodor Dostoevsky";
	books[8].author ="Mary Shelly";
    books[9].author ="Charles Dickens";
    
    int choice;
    do {
	    cout << "\n=======================================\n";
        cout << "\n=======Library Management System=======\n";
        cout << "\n=======================================\n";
        cout << "\n 1. Add Book\n";
        cout << "\n 2. Borrow Book\n";
        cout << "\n 3. Return Book\n";
        cout << "\n 4. Display Books\n";
        cout << "\n 5. Exit\n";
        cout << "\nEnter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                addBook(books, bookCount);
                break;
            case 2:
                borrowBook(books, bookCount);
                break;
            case 3:
                returnBook(books, bookCount);
                break;
            case 4:
                displayBooks(books, bookCount);
                break;
            case 5:
                cout << "Exiting program. Goodbye!" << endl;
                break;
            default:
                cout << "Invalid choice! Please try again." << endl;
        }
    }while(choice!=5);

    return 0;
}
