#include <string>
#include <iostream>
using namespace std;

string str_replace (string phrase, char first_character, char second_character);

int main() {

	string phrase;
	char ch_01, ch_02;
	
	getline(cin, phrase);
	while (!phrase.empty()) {
		cin >> ch_01 >> ch_02;
		cin.ignore();
		
		size_t position = phrase.find(ch_01);

		while (position != string::npos) {
			phrase = str_replace(phrase, ch_01, ch_02);
			position = phrase.find(ch_01);
		}

		cout << phrase << endl;
		getline(cin, phrase);
	}
	
	return 0;
}

string str_replace (string phrase, char first_character, char second_character) {
	return phrase.replace(phrase.find(first_character), 1, 1, second_character);
}