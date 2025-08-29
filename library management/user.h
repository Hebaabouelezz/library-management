#pragma once

#include <string>
using namespace std;

enum UserAccess
{
	owner,
	customer,
	operation

};

struct User
{
	string name = "customer";
	string email;
	string password;
	int access = 0;
};


// Insert dummy accounts for owner & operation
void insertDummyUserData(User* owner, User* operation);

// Login function now takes owner & operation accounts
int login(User* owner, User* operation);

// Signup function for creating a new account
void signup(User* customer);

// Reset password function with rules (8 chars, 2 numbers, 1 special char)
void resetPassword(User* account);











