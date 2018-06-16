#include <iostream>
#include <string>
using namespace std;

string str_replace (string phrase, string word_replaced, string word_replace);

int main() {
	
	string phrase, firstWord, secondWord;
	getline(cin, phrase);
	getline(cin, firstWord);
	getline(cin, secondWord);
	
	size_t position = phrase.find(firstWord);
	
	while (position != string::npos) {
		phrase = str_replace(phrase, firstWord, secondWord);
		position = phrase.find(firstWord);
	}
	
	cout << phrase;
	return 0;
} 

string str_replace (string phrase, string word_replaced, string word_replace) {
	return phrase.replace(phrase.find(word_replaced), word_replaced.length(), word_replace);
}