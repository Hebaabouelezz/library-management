#include<iostream>
#include"sales.h"
#include<string>
using namespace std;


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
	if (UserAccess != 0 && UserAccess != 2) {
		cout << "No Access:" << endl;
		return;
	}
	//search book
	Book* foundBook = searchById(id, myInventory);
	int quantity;
	cout << "enter quantity:";
	cin >> quantity;
	
	if (salesStatus == 0) {
		double price = quantity * foundBook->sellPrice;
		cout << "price is:" << price << endl;
		getCustomerData(name, nationalId, phone);
		BookSale->quantity -= quantity;

	}
	else if (salesStatus == 1) {
		double price = quantity * borrowPeriod *foundBook->borrowPriceByDay;
		cout << "price is:" << price << endl;
		getCustomerData(name, nationalId, phone);
		BookSale->quantity -= quantity;

	}
	else
		cout << "not found";
	return;
	
}