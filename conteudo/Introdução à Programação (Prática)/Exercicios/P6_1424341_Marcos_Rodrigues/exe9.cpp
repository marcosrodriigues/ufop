#include <string>
#include <iostream>
using namespace std;

void lastWord (string phrase);

int main() {

	string phrase;
	
	getline(cin, phrase);
	
	while (!phrase.empty()) {
		lastWord(phrase);
		getline(cin, phrase);
	}

	return 0;
}

void lastWord (string phrase) {
	int index = 0;
	for (int i = 0; i < phrase.length(); i++)
		if (phrase[i] == ' ') {
			index = i + 1;
		}
			
	
	cout << phrase.substr(index, (string::npos - index)) << endl;
}