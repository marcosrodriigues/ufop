#include "TPilha.h"
#include <iostream>
using namespace std;

int main() {
	int maxValue = 0, currentVal = 0;
	TPilha *stack = new TPilha;
	TItem item;

	do {
		cin >> maxValue;
	} while (maxValue < 2 || maxValue > 50);

	TPilha_New(stack);

	for (int i = 0; i < maxValue; ++i) {
		cin >> currentVal;
		TPilha_Push(stack, currentVal);
	}

	TPilha_OrganizeWithQuickSort(stack->item, stack->ultimo);

	for (int i = 0; i < stack->ultimo; ++i) {
		cout << stack->item[i].number << " ";
	}

	cout << endl;

	return 0;
}