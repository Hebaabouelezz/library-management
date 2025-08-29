#include"inventory.h"
#include<iostream>
using namespace std;



Book* searchById(string id, Inventory* myInventory) {
	
	for (auto& element : myInventory->myBooks) {
		if (id == element.id) {
			
			cout << "The Book with id: " << element.id << endl;
			cout << "The Book Name: " << element.name << endl;
			cout << "The Book Author: " << element.author << endl;
			cout << "The Book Category: " << element.category << endl;
			return &element;
		}
	}
	return nullptr;
}

vector<Book> searchBook(Inventory* myInventory) {
	//What to use to search

	int search;
	string searchString;
	double searchDouble;
	int searchInt;

	vector<Book> searchBooks;
	cout << "How to Search: name: 0,author: 1,category: 2,status: 3,quantity: 4,returnDate: 5, sellPrice: 6,borrowPriceByDay: 7 ";
	cin >> search;

	cout << "Enter the search term:";

	switch (search) {
	case searchFactor::author:
		getline(cin >> ws, searchString);
		for (auto& element : myInventory->myBooks) {
			if (searchString == element.author) {
				searchBooks.push_back(element);
				cout << "The Book with id: " << element.id << endl;
				cout << "The Book Name: " << element.name << endl;
				cout << "The Book Author: " << element.author << endl;
				cout << "The Book Category: " << element.category << endl;
				break;
			}
		}
		break;
	case searchFactor::category:
		getline(cin >> ws, searchString);
		for (auto& element : myInventory->myBooks) {
			if (searchString == element.category) {
				searchBooks.push_back(element);
				cout << "The Book with id: " << element.id << endl;
				cout << "The Book Name: " << element.name << endl;
				cout << "The Book Author: " << element.author << endl;
				cout << "The Book Category: " << element.category << endl;
				break;
			}
		}
		break;
	case searchFactor::name:
		getline(cin >> ws, searchString);
		for (auto& element : myInventory->myBooks) {
			if (searchString == element.name) {
				searchBooks.push_back(element);
				cout << "The Book with id: " << element.id << endl;
				cout << "The Book Name: " << element.name << endl;
				cout << "The Book Author: " << element.author << endl;
				cout << "The Book Category: " << element.category << endl;
				break;
			}
		}
		break;
	case searchFactor::status:
		cin >> searchInt;
		for (auto& element : myInventory->myBooks) {
			if (searchInt == element.status) {
				searchBooks.push_back(element);
				cout << "The Book with id: " << element.id << endl;
				cout << "The Book Name: " << element.name << endl;
				cout << "The Book Author: " << element.author << endl;
				cout << "The Book Category: " << element.category << endl;
				break;
			}
		}
		break;
	case searchFactor::quantity:
		cin >> searchInt;
		for (auto& element : myInventory->myBooks) {
			if (searchInt == element.quantity) {
				searchBooks.push_back(element);
				cout << "the Book quantity:" << element.quantity << endl;;
				cout << "The Book with id: " << element.id << endl;
				cout << "The Book Name: " << element.name << endl;
				cout << "The Book Author: " << element.author << endl;
				cout << "The Book Category: " << element.category << endl;
				break;
			}
		}
		break;
	case searchFactor::returnDate:
		cin >> searchInt;
		for (auto& element : myInventory->myBooks) {
			if (searchInt == element.returnDate) {
				searchBooks.push_back(element);
				cout << "the return date:" << element.returnDate << endl;;
				cout << "the Book quantity:" << element.quantity;
				cout << "The Book with id: " << element.id << endl;
				cout << "The Book Name: " << element.name << endl;
				cout << "The Book Author: " << element.author << endl;
				cout << "The Book Category: " << element.category << endl;
				break;
			}
		}
		break;
	case searchFactor::borrowPriceByDay:
		cin >> searchDouble;
		for (auto& element : myInventory->myBooks) {
			if (searchInt == element.borrowPriceByDay) {
				searchBooks.push_back(element);
				cout << "the borrow price by day:" << element.borrowPriceByDay << endl;
				cout << "the return date:" << element.returnDate << endl;
				cout << "the Book quantity:" << element.quantity;
				cout << "The Book with id: " << element.id << endl;
				cout << "The Book Name: " << element.name << endl;
				cout << "The Book Author: " << element.author << endl;
				cout << "The Book Category: " << element.category << endl;
				break;
			}
		}
		break;

	case searchFactor::sellPrice:
		cin >> searchDouble;
		for (auto& element : myInventory->myBooks) {
			if (searchDouble == element.sellPrice) {
				searchBooks.push_back(element);
				cout << "The Book with id: " << element.id << endl;
				cout << "The Book Name: " << element.name << endl;
				cout << "The Book Author: " << element.author << endl;
				cout << "The Book Category: " << element.category << endl;
				break;
			}
		}
		break;
	default:
		cout << "wrong input";
	}
	return searchBooks;

}

vector<Book> getListOfInventory(Inventory* myInventory) {
	vector<Book> searchBooks = myInventory->myBooks;
	return searchBooks;
}
vector<Book> getListOfBorrowedItems(Inventory* myInventory) {
	vector <Book> borrowedBooks;
	for (auto& element : myInventory->myBooks) {
		if (element.status == BookStatus::borrowed) {
			borrowedBooks.push_back(element);
		}
	}
	return borrowedBooks;
}
void inventoryTotalQuantity(Inventory* myInventory) {
	int total = 0;
	for (auto& element : myInventory->myBooks) {
		total += element.quantity;
		myInventory->totalQuantity = total;

	}
}
void inventoryTotalPrice(Inventory* myInventory) {
	double total = 0;
	for (auto& element : myInventory->myBooks) {
		total += element.quantity*element.sellPrice;
		myInventory->totalPrice = total;
	}

}
void addItem(Inventory* myInventory) {
	Book newBook;
	cout << "enter book id:";
	getline(cin >> ws,newBook.id);
	cout << "enter book name:";
	getline(cin >> ws, newBook.name); 
	cout << "enter author:";
	getline(cin >> ws, newBook.author);
	cout << "enter book category:";
	getline(cin >> ws, newBook.category);
	myInventory->myBooks.push_back(newBook);
	cout << "book is add";
}
