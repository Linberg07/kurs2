#pragma once
#include<iostream>
using namespace std;

class Stack {
private:
	class Elem {
	public:
		Elem* pNext;
		char data;
		Elem(char data = NULL, Elem* pNext = nullptr) {
			this->data = data;
			this->pNext = pNext;
		}
		~Elem() {
			this->data = NULL;
			this->pNext = nullptr;
		}
	};

	Elem* top;
public:
	Stack() {
		top = nullptr;
		size = 0;
	}
	size_t size;
	void push(char data);
	char pop();
	char getDataNow();
};

void Stack::push(char data)
{
	if (top == NULL) top = new Elem(data);
	else {
		top = new Elem(data, top);
	}
	size++;
}

char Stack::pop()
{
	if (size == 0) return 0;
	Elem* temp = top;
	char data = top->data;
	top = top->pNext;
	size--;
	delete temp;
	return data;
}

char Stack::getDataNow()
{
	if (size == 0) return 0;
	return top->data;
}
