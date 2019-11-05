#include "pch.h"
#include <iostream>
#include <string>

using namespace std;

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

bool checkArgument(string arg[3]) {
	for (int i = 0; i < 3; i += 2) {
		if (!isInt(arg[i])) {
			cerr << "Error! Invalid Number Input" << endl;
			return false;
		}
		else if (stoi(arg[i]) < -32768 || stoi(arg[i]) > 32767) {
			cerr << "Error! Invalid Number Input Range" << endl;
			return false;
		}
	}
	if (arg[1] != "%" && arg[1] != "/" && arg[1] != "+" && arg[1] != "-" && arg[1] != "*") {
		cerr << "Error! Invalid Operator" << endl;
		return false;
	} else if (arg[1] == "/" && arg[2] == "0") {
		cerr << "Error! Division by zero" << endl;
		return false;
	} else {	
		return true;
	}
}

int result(int arg1, int arg2, string op) {
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
	string argument;
	string arg[3];
	int arg_element = 0;
	int prev_element = 0;
	bool exit = false;
	while (argument != "Exit") {
		fill(arg, arg + 3, "");
		arg_element = 0;
		prev_element = 0;
		cout << "Enter an arithmatic expression: ";
		getline(cin, argument);
		for (int next_element = 1; next_element <= argument.size(); next_element++) {
			if (argument[prev_element] == ' ' && argument[next_element] != ' ') {
				arg_element++;
			} else if (arg_element > 2) {
				cerr << "Error! Input argument contain dummy value" << endl;
				continue;
			} else if (argument[prev_element] != ' ') {
				arg[arg_element] += argument[prev_element];
			}
			prev_element++;
		}
		if (checkArgument(arg)) {
			cout << "The result is " << result(stoi(arg[0]), stoi(arg[2]), arg[1]) << endl;
		}
	}
	return 0;
} 