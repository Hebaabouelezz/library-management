#include "user.h"
#include <iostream>

void insertDummyUserData(User* owner, User* operation) {
	owner->email = "owner@mylibrary.com";
	owner->password = "123456789";

	operation->email = "operation@mylibrary.com";
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
	int choice;
	cout << "Login"<<endl;
	cout << "0. Owner"<<endl;
	cout << "1. User (Customer)"<<endl;
	cout << "2. Operation"<<endl;
	cout << "Choose a number: ";
	cin >> choice;

	string email, password;
	cout << "please insert your email: ";
	cin >> email;
	cout << "please insert your password: ";
	cin >> password;

	if (choice == 0) {
		if (email == owner->email && password == owner->password) {
			cout << "Login successful (Owner)"<<endl;
			return UserAccess::owner;
		}
		else {
			
			return UserAccess::customer; 
		}
	}
	else if (choice == 2) {
		if (email == operation->email && password == operation->password) {
			cout << "Login successful (Operation)"<<endl;
			return UserAccess::operation;
		}
		else {
			
			return UserAccess::customer; 
		}
	}
	else if (choice == 1) {
		cout << "Login successful (Customer)"<<endl;
		return UserAccess::customer;
	}
	else {
		cout << "Invalid choice, defaulting to Customer"<<endl;
		return UserAccess::customer;
	}
}
