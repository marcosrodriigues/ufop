#include <iostream>
#include <string>
using namespace std;

int numberSequence(string word, string wordToCheck);

int main() {

	string word_01, word_02;
	
	getline(cin, word_01);
	
	while (!word_01.empty()) {
		getline(cin, word_02);
		cout << numberSequence(word_01, word_02) << endl; 
		getline(cin, word_01);
	}

	return 0;
}

int numberSequence(string word, string wordToCheck) {

	int count = 0, sum = 0;
	
	for (int i = 0; i < word.length(); i++) {
		sum = 0;
		for (int j = 0; j < wordToCheck.length(); j++) {
			if (word[i + j] == wordToCheck[j])
				sum++;
		}
		if (sum == wordToCheck.length())
			count++;
	}

	return count;
}