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

void proccessSales(int UserAccess,int salesStatus, Book* BookSale, int borrowPeriod, Inventory* myInventory, string id, string &name, string &nationalId, string &phone);
void getCustomerData(string &name, string &nationalId, string &phone);