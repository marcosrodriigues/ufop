#include <iostream>
#include <string>
using namespace std;

string removeString(string word, string wordToRemove);

int main() {

	string word_01, word_02;
	
	getline(cin, word_01);
	
	while (!word_01.empty()) {
		getline(cin, word_02);
		cout << removeString(word_01, word_02) << endl; 
		getline(cin, word_01);
	}

	return 0;
}

string removeString(string word, string wordToRemove) {
	
	for (int i = 0; i < word.length(); i++) {
		for (int j = 0; j < wordToRemove.length(); j++) {
			if (word[i] == wordToRemove[j]) {
				word.erase(i, 1);
				i--;
			}
				
		}
	}
	
	return word;
}