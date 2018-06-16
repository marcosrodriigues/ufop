#include <iostream>
using namespace std;

int isAlpabetic(char c) {
	
	if ((c >= 'A' && c <= 'Z') || (c >= 'a' && c <= 'z'))
		return 1;
	else 
		return 0;
		
}

int main() {

	char digit;
	
	cin >> digit;
	
	while (digit != '0') {
		cout << isAlpabetic(digit) << endl;
			
		cin >> digit;
	}

	return 0;
}