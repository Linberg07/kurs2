#include<iostream>
#include <sstream>
#include "stack.h"
#include "function.h"
using namespace std;



void postfix_implementation(string& infix, string& postfix, Stack stack) {
	for (int i = 0; i < infix.length(); i++) {
		if (infix[i] == '^') {
			postfix = postfix + " ";
			if (stack.size != 0) {
				while ((stack.size > 0) && (stack.getDataNow() != '+') && (stack.getDataNow() != '-') && (stack.getDataNow() != '*') && (stack.getDataNow() != '/') && (stack.getDataNow() != '(')) {
					postfix = postfix + stack.pop() + " ";
				}
			}
			else {
				stack.push(infix[i]);
			}
		}
		else if ((infix[i] == '*') || (infix[i] == '/')) {
			postfix = postfix + " ";
			if (stack.size != 0) {
				while ((stack.size > 0) && (stack.getDataNow() != '+') && (stack.getDataNow() != '-') && (stack.getDataNow() != '(')) {
					postfix = postfix + stack.pop() + " ";
				}
				stack.push(infix[i]);
			}
			else {
				stack.push(infix[i]);
			}
		}
		else if ((infix[i] == '+') || (infix[i] == '-')) {
			postfix = postfix + " ";
			if (stack.size != 0) {
				while ((stack.size > 0) && (stack.getDataNow() != '(')) {
					postfix = postfix + stack.pop() + " ";
				}
				stack.push(infix[i]);
			}
			else {
				stack.push(infix[i]);
			}
		}

		else if (infix[i] == '(') stack.push(infix[i]);
		else if (infix[i] == ')') {
			char temp = stack.getDataNow();
			while (temp != '(') {
				temp = stack.pop();
				if (temp != '(') postfix = postfix + temp;
				temp = stack.getDataNow();
			}
			stack.pop();
		}
		else {
			postfix = postfix + infix[i];
		}
	}
	for (int i = 0; i <= stack.size; i++) {
		postfix = postfix + stack.pop();
	}
}



int main() {
	Stack stack;

	string infix;
	cin >> infix;
	string postfix;

	if (check_string(infix) == 0) return 0;
	
	postfix_implementation(infix, postfix,stack);
	
	

	
	infix = implementation(infix);
	
	cout << endl;
	cout << "PostFix: " << postfix<<endl;
	
	cout << "Result: " << infix;

	
	
	
	
	
}


