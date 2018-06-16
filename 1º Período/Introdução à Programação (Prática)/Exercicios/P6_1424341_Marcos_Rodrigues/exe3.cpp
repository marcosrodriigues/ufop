#include <iostream>
#include <string>
using namespace std;

int indexStr(string str, char ch) {
	int index = -1;
	
	for (int i = 0; i < str.length(); i++) {
		if (str[i] == ch) {
			index = i;
			break;
		}			
	}
	
	return index;
}

int main() {
	string word;
	char charac;
	
	getline(cin, word);
	
	while (!word.empty()) {
		cin >> charac;
		cin.ignore();
		cout << indexStr(word, charac) << endl;;
		getline(cin, word);
	}
	
	return 0;
}