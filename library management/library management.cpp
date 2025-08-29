#include <iostream>
#include <string>
#include <vector>
#include <limits>
#include "inventory.h"
#include "sales.h"
#include "user.h"

using namespace std;

int main() {
    User owner, operation;
    int activeUser = UserAccess::customer;
    Inventory myInventory;

   
    insertDummyUserData(&owner, &operation);
    insertDummyBooksData(&myInventory);

    
    activeUser = login(&owner, &operation);

    int choice;
    do {
        
        if (activeUser == UserAccess::owner) {
           
            cout << "0. Add item" << endl;
            cout << "1. Search" << endl;
            cout << "2. Process sales" << endl;
            cout << "3. Exit" << endl;
        }
        else if (activeUser == UserAccess::operation) {
           
            cout << "1. Search" << endl;
            cout << "2. Process sales" << endl;
            cout << "3. Exit" << endl;
        }
        else if (activeUser == UserAccess::customer) {
           
            cout << "1. Search" << endl;
            cout << "3. Exit" << endl;
        }

        cout << "Enter a choice: ";
        cin >> choice;

        // Owner: Add Item
        if (choice == 0 && activeUser == UserAccess::owner) {
            int numBooks;
            cout << "How many books do you want to add? ";
            cin >> numBooks;
            for (int i = 0; i < numBooks; i++) {
                addItem(&myInventory);
            }
            inventoryTotalQuantity(&myInventory);
            inventoryTotalPrice(&myInventory);
            cout << "Total Quantity: " << myInventory.totalQuantity << endl;
            cout << "Total Price: " << myInventory.totalPrice << endl;
        }
        
        else if (choice == 1) {
            string id;
            cout << "Enter the id of the book: ";
            cin >> id;
            Book* found = searchById(id, &myInventory);
            if (found) {
                cout << "Found book: " << found->name
                    << " | Quantity: " << found->quantity << endl;
            }
            else {
                cout << "Book not found" << endl;
            }
        }
        // Process sales (Owner + Operation)
        else if (choice == 2 && (activeUser == UserAccess::owner || activeUser == UserAccess::operation)) {
            int salesStatus;
            int borrowPeriod = 0;
            string id, name, nationalid, phone;

            cout << "Enter book id to sell/borrow: ";
            cin >> id;

           
            Book* foundBook = searchById(id, &myInventory);
            if (!foundBook) {
                cout << "Book not found, cannot process sale." << endl;
            }
            else {
                cout << "Enter sales status (0 = buy, 1 = borrow): ";
                cin >> salesStatus;
                if (salesStatus == 1) {
                    cout << "Enter borrow period (days): ";
                    cin >> borrowPeriod;
                }

               
                

               
                proccessSales(activeUser, salesStatus, foundBook,
                    borrowPeriod, &myInventory, id,
                    name, nationalid, phone);

              
                cout << "\nInventory after sales:" << endl;
                vector<Book> myBooks = getListOfInventory(&myInventory);
                for (auto& element : myBooks) {
                    cout << "ID: " << element.id
                        << " | Name: " << element.name
                        << " | Quantity: " << element.quantity << endl;
                }
            }
        }

    } while (choice != 3);

    cout << "Exiting program..." << endl;
    return 0;
}
