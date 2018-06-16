#include <iostream>
#include <string>
using namespace std;

int strLength(string str) {
	return str.length();
}

int main() {
	string phrase;
	
	getline(cin, phrase);
	
	while (!phrase.empty()) {
		cout << strLength(phrase) << endl;
		getline(cin, phrase);
	}
	
	return 0;
}