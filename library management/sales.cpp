#include<iostream>
#include"sales.h"
#include<string>
using namespace std;

void insertDummyBooksData(Inventory*myInventory) {
	Book book;
	book.id = "11111";
	book.name = "c++";
	book.author = "heba";
	book.category = "programming";
	book.sellPrice = 50;
	myInventory->myBooks.push_back(book);
}


void getCustomerData(string &name, string &nationalId, string &phone) {
	cout << "enter customer name:";
	getline(cin >> ws, name);
	cout << "enter customer nationalId:";
	getline(cin >> ws, nationalId);
	cout << "enter customer phone:";
	getline(cin >> ws, phone);
}


void proccessSales(int UserAccess,int salesStatus, Book* BookSale, int borrowPeriod, Inventory* myInventory,string id,string &name, string &nationalId, string &phone) {
	//check it is owner's and operation's or customer's email
	
	//search book
	Book* foundBook = searchById(id, myInventory);
	if (!foundBook) {
		cout << "book not found" << endl;
		return;
	}
	int quantity;
	cout << "enter quantity:";
	cin >> quantity;
	
	if (salesStatus == 0) {
		double price = quantity * foundBook->sellPrice;
		cout << "price is:" << price << endl;
		getCustomerData(name, nationalId, phone);
		BookSale->quantity -= quantity;
		cout << "book bought successfully"<<endl;

	}
	else if (salesStatus == 1) {
		double price = quantity * borrowPeriod *foundBook->borrowPriceByDay;
		cout << "price is:" << price << endl;
		getCustomerData(name, nationalId, phone);
		BookSale->quantity -= quantity;
		cout << "book borrowed successfully"<<endl;

	}
	else
		cout << "not found";
	return;
	
}
