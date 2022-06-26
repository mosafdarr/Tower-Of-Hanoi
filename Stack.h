#pragma once
#include <iostream>
using namespace std;
#define N 10
class Stack
{
private:
	int A[N], top, length;
public:
	Stack() {
		
		top = 0;
		length = 0;
	}
	bool isFull() {
		return top == N;
	}
	bool isEmpty() {
		return top == 0;
	}
	bool push(int y) {
		if (isFull())
			return false;
		A[top++] = y;
		length++;
		return true;

	}
	bool pop(int *x) {
		if (!isEmpty()) {
			 *x = A[--top];
			 length--;
			return true;
		}
		return false;
	}
	void print() {
		for (int i = 0; i < top; i++)
			cout << A[i] << " ";
	}
	bool checkIfWon(int x) {
		return length == x;
	}
	int peek() {
		if (isEmpty())
			return -1;
		int x = A[top-1];
		return x;
	
	}
};

