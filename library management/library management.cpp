#include <iostream>
#include <string>
#include <vector>
#include<limits>
#include "inventory.h"
#include "sales.h"
#include "user.h"

using namespace std;

int main() {
    User owner, operation;
    int activeUser = UserAccess::customer;

    // Insert dummy user data for login
    insertDummyUserData(&owner, &operation);

    // Login
    
    activeUser = login(&owner,&operation);
    
    // Setup inventory
    Inventory myInventory;
    myInventory.title = "My Library Inventory";

    // Add books to inventory (owner only)
    if (activeUser == UserAccess::owner) {
        cout << "\nAdd Books to Inventory\n";
        int numBooks;
        cout << "How many books do you want to add? ";
        cin >> numBooks;
        cin.ignore(numeric_limits<streamsize>::max(), '\n');

        for (int i = 0; i < numBooks; i++) {
            addItem(&myInventory);
        }

        inventoryTotalQuantity(&myInventory);
        inventoryTotalPrice(&myInventory);

        cout << "\nTotal Quantity: " << myInventory.totalQuantity << endl;
        cout << "Total Price: " << myInventory.totalPrice << endl;
    }

    // Process sales (owner or operation)
    if (activeUser == UserAccess::owner||activeUser== UserAccess::operation) {
        cout << "\nProcess Sales\n";
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        string id;
        cout << "Enter book id to sell/borrow: ";
        getline(cin , id);

        int salesStatus = 0;
        cout << "Enter sales status (0 = buy, 1 = borrow): ";
        cin >> salesStatus;

        int borrowPeriod = 0;
        if (salesStatus == 1) {
            cout << "Enter borrow period (days): ";
            cin >> borrowPeriod;
        }
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        Book BookSale;
        string name, nationalid, phone;

        cout << "Enter customer name: ";
        getline(cin , name);
        cout << "Enter customer national ID: ";
        getline(cin , nationalid);
        cout << "Enter customer phone: ";
        getline(cin , phone);

        proccessSales(activeUser, salesStatus, &BookSale, borrowPeriod, &myInventory, id, name, nationalid, phone);
}
        cout << "\nInventory after sales\n";
        vector<Book> myBooks = getListOfInventory(&myInventory);
        for (auto& element : myBooks) {
            cout << "ID: " << element.id
                << ", Name: " << element.name
                << ", Quantity: " << element.quantity << endl;
        }
    

    return 0;
}