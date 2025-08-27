#pragma once

#include <string>
#include <vector>
#include <iostream>

using namespace std;

enum BookStatus
{
	sold,
	borrowed,
	exists

};

enum searchFactor
{
	name,
	author,
	category,
	status,
	quantity,
	returnDate,
	sellPrice,
	borrowPriceByDay
};

struct Book
{
	string id;
	string name;
	string author;
	string category;
	int status=0;
	int quantity=0;
	int returnDate=0;
	double sellPrice=0;
	double borrowPriceByDay=0;
};


struct Inventory
{
	string title;
	vector <Book> myBooks;
	double totalQuantity=0.0;
	double totalPrice=0.0;
};


void inventoryTotalQuantity(Inventory* myInventory);
void inventoryTotalPrice(Inventory* myInventory);
void addItem(Inventory* myinventory);
Book* searchById(string id, Inventory* myInventory);
vector<Book>  searchBook(Inventory* myInventory);
vector<Book> getListOfInventory(Inventory* myInventory);
vector<Book> getListOfBorrowedItems(Inventory* myInventory); 
