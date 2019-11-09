#include "pch.h"
#include <iostream>

using namespace std;

// Converting from string to int
int converToInt(string number) {
	string new_numstring = "";
	for (int i = 0; i < number.length(); i++) {
		if (number[i] == '.') {
			break;
		} else {
			new_numstring += number[i];
		}
	}
	int toint = 0;
	int start_digit = 0;
	if (new_numstring[0] == '-') {
		start_digit = 1;
	}
	for (char i = start_digit; i < new_numstring.length(); i++) {
		if (new_numstring[i] == '.') {
			break;
		}
		toint += (new_numstring[i] - 48) * (pow(10, (new_numstring.length() - 1)))/pow(10, i);
	}
	if (new_numstring[0] == '-') {
		return (-1 * toint);
	} else {
		return toint;
	}
}

// Checking if the number is the correct integer
bool isInt(string number) {
	bool isdot = false;
	int start_digit = 0;
	if (number[0] != '-' && number[0] < '0' || number[0] > '9') {
		return false;
	} else if (number[0] == '-') {
		start_digit = 1;
	} else {
		start_digit = 0;
	}
	for (char i = start_digit; i < number.length(); i++) {
		if (!isdot) {
			if (number[i] == '.') {
				isdot = true;
			} else if (number[i] < '0' || number[i] > '9') {
				return false;
			}
		} else if (number[i] != '0') {
			return false;
		}
	}
	return true;
}

// Checking if the expression is correct
bool checkArgument(string arg[3]) {
	for (int i = 0; i < 3; i += 2) {
		if (!isInt(arg[i])) {
			cerr << "Error! Invalid Number Input" << endl;
			return false;
		} else if (converToInt(arg[i]) < -32768 || converToInt(arg[i]) > 32767) {
			cerr << "Error! Invalid Number Input Range" << endl;
			return false;
		}
	}
	if (arg[1] != "%" && arg[1] != "/" && arg[1] != "+" && arg[1] != "-" && arg[1] != "*") {
		cerr << "Error! Invalid Operator" << endl;
		return false;
	} else if (arg[1] == "/" && converToInt(arg[2]) == 0) {
		cerr << "Error! Division by zero" << endl;
		return false;
	} else {	
		return true;
	}
}

// Calculate the result
int result(int arg1, int arg2, string op) {//
	if (op == "+") {
		return arg1 + arg2;
	} else if (op == "-") {
		return arg1 - arg2;
	} else if (op == "*") {
		return arg1 * arg2;
	} else if (op == "/") {
		return arg1 / arg2;
	} else {
		return arg1 % arg2;
	}
}

int main() {
	char argument[100];
	int arg_element = 0;
	int prev_element = 0;
	while (true) {
		string arg[3];
		arg_element = 0;
		prev_element = 0;
		cout << "Enter an arithmatic expression: ";
		cin.getline(argument, 99);
		if (strcmp(argument, "Exit") == 0) {
			break;
		}
		for (int next_element = 1; next_element <= strlen(argument); next_element++) {
			if (argument[prev_element] == ' ' && argument[next_element] != ' ') {
				arg_element++;
			} else if (arg_element > 2) {
				cerr << "Error! Input argument contain dummy value" << endl;
				break;
			} else if (argument[prev_element] != ' ') {
				arg[arg_element] += argument[prev_element];
			}
			prev_element++;
		}
		if (prev_element == strlen(argument) && checkArgument(arg)) {
			cout << "The result is " << result(converToInt(arg[0]), converToInt(arg[2]), arg[1]) << endl;
		}
	}
	cout << "LABORATORY GROUP BINHHONGLONG" << endl;
	cout << "S3757333,s3757333@rmit.edu.vn,Dang,Long" << endl;
	cout << "S3715271,s3715271@rmit.edu.vn,Phan,Binh" << endl;
	cout << "S3757165,s3757165@rmit.edu.vn,Quan,Hong" << endl;
	cout << "S3681446,s3681446@rmit.edu.vn,Dinh,Nhat" << endl;
	return 0;
} 