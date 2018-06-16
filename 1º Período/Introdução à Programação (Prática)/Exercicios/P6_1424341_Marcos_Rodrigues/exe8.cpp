#include <string>
#include <iostream>
using namespace std;

int count_words(string word);

int main () {
	string word;
	
	getline(cin, word);
	
	while (!word.empty()) {
		cout << count_words(word) << endl;;
		getline(cin, word);
	}
	
	return 0;
}

int count_words(string word) {
	int count = 1;
	
	for (int i = 0; i < word.length(); i++)
		count = (word[i] == ' ') ? count + 1 : count;
		
	return count;
	
}