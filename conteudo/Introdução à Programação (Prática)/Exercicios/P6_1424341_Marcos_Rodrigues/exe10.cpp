#include <string>
#include <iostream>
using namespace std;

string concaternar (string first_word, string second_word);

int main() {

	string word_01, word_02;
	
	getline(cin, word_01);
	getline(cin, word_02);
	
	while (!word_01.empty() || !word_02.empty()) {
		cout << concaternar(word_01, word_02) << endl; 
		getline(cin, word_01);
		getline(cin, word_02);
	}

	return 0;
}

string concaternar (string first_word, string second_word) {
	return first_word + second_word;
}