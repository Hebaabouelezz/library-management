#pragma once

#include<string>
#include "inventory.h"
#include"user.h"

using namespace std;

enum salesStatus
{
	buy,
	borrow

};

struct Customer
{
	string name;
	string nationalId;
	string phoneNumber;


};

struct DummyDataBook
{
	string id;
	string name;
	string author;
	string category;
	int status = 0;
	int quantity= 0;
	int returnDate = 0;
	double sellPrice = 0;
	double borrowPriceByDay = 0;
};

void insertDummyBooksData(Inventory*myInventory);

void proccessSales(int UserAccess,int salesStatus, Book* BookSale, int borrowPeriod, Inventory* myInventory, string id, string &name, string &nationalId, string &phone);
void getCustomerData(string &name, string &nationalId, string &phone);
