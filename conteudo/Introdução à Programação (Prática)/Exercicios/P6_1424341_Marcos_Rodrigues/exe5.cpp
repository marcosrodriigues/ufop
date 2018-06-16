#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

string str_remove (string word, char toRemove);

int main() {
	
	string word;
	char charac;
	
	getline(cin, word);
	
	while (!word.empty()) {
		cin >> charac;
		cin.ignore();
		cout << str_remove(word, charac) << endl;;
		getline(cin, word);
	}
	
	return 0;
}

string str_remove (string word, char toRemove) {
	for (int i = 0; i < word.length(); i++) {
		if(word[i] == toRemove) {
			word.erase(i, 1);
			i--;
		}
	}
	
	return word;
}