
#include "user.h"
#include <iostream>

void insertDummyUserData(User* owner, User* operation) {
	owner->access = UserAccess::owner;
	owner->email = "owner@mylibrary.com";
	owner->name = "ahmed";
	owner->password = "123456";

	operation->access = UserAccess::operation;
	operation->email = "operation@mylibrary.com";
	operation->name = "mohamed";
	operation->password = "123456789";
}



// helper function to validate password strength
bool isValidPassword(const string& password) {
	if (password.length() < 8) return false;

	int digitCount = 0;
	bool hasSpecial = false;
	string specialChars = "!@#$%^&*()-_=+[]{};:'\",.<>?/|\\";

	for (char c : password) {
		if (isdigit(c)) digitCount++;
		if (specialChars.find(c) != string::npos) hasSpecial = true;
	}

	return (digitCount >= 2 && hasSpecial);
}

// reset password function 
void resetPassword(User* user) {
	string newPassword;

	cout << "Reset Password" << endl;
	cout << "Here is some requirements your new password must contain: " << endl;
	cout << "1. Minimum 8 characters" << endl;
	cout << "2. Must contain at least 2 numbers" << endl;
	cout << "3. Must contain at least 1 special character (!@#$%^&*)" << endl;

	while (true) {
		cout << "Enter new password: ";
		getline(cin >> ws, newPassword);

		if (isValidPassword(newPassword)) {
			user->password = newPassword;
			cout << "Password updated successfully, Thank you!" << endl;
			break;
		}
		else {
			cout << "Password does not meet requirements, try again." << endl;
		}
	}
}

//Signup function (only for Operation)
void signup(User* operation) {
	cout << "Operation Signup" << endl;

	//Asks for new operation account details (name, email, password)
	cout << "Enter name: ";
	getline(cin >> ws, operation->name);

	cout << "Enter email: ";
	getline(cin >> ws, operation->email);

	cout << "Enter password: ";
	getline(cin >> ws, operation->password);
	//Sets access level to operation
	operation->access = UserAccess::operation;

	cout << "Signup successful for operation user: " << operation->email << endl;
}


int login(User* owner, User* operation) {

	// set the user access by default customer
	int userStatus = UserAccess::customer;

	// choose which account to login
	int choice;
	cout << "Login" << endl;
	cout << "0. Owner\n1. User (Customer)\n2. Operation\n";
	cout << "Choose a number: ";
	cin >> choice;
	cin.ignore(numeric_limits<streamsize>::max(), '\n');

	// if customer → no login needed
	if (choice == 1) {
		cout << "Logged in as Customer" << endl;
		return UserAccess::customer;
	}

	// select account to check

	User* account = nullptr;
	if (choice == 0) account = owner;
	else if (choice == 2) account = operation;


	// get login data from user
	string email, password;
	int attempts = 0;
	const int MAX_ATTEMPTS = 3;

	while (attempts < MAX_ATTEMPTS) {
		cout << "please insert your email: ";
		getline(cin >> ws, email);

		cout << "please insert your password: ";
		getline(cin >> ws, password);

		// check if correct
		if (email == "owner@mylibrary.com" && password == "123456") {
			userStatus = UserAccess::owner;
		}
		//check it is operation's email
		else if (email == "operation@mylibrary.com" && password == "123456789") {
			userStatus = UserAccess::operation;
		}
		else {
			attempts++;
			cout << "Email or Password is Wrong (" << attempts << "/" << MAX_ATTEMPTS << ")" << endl;

			if (attempts == MAX_ATTEMPTS) {
				resetPassword(account);
				userStatus = UserAccess::customer;
				break;
			}
			// option to reset password early
			char forgot;
			cout << "Forgot password? (y/n): ";
			cin >> forgot;
			cin.ignore();
			if (forgot == 'y' || forgot == 'Y') {
				resetPassword(account);
				userStatus = UserAccess::customer;
				break;
			}
		}
	}

	return userStatus;
}