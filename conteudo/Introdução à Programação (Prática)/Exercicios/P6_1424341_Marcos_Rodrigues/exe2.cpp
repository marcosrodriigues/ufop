#include <iostream>
#include <string>
using namespace std;

int countStr(string str, char car) {
	int count = 0;
	
	for (int i = 0; i < sizeof(str); i++) {
		if (str[i] == car)
			count++;
	}
	
	return count;
}

int main() {
	string word;
	char charac;
	
	getline(cin, word);
	
	while (!word.empty()) {
		cin >> charac;
		cin.ignore();
		cout << countStr(word, charac) << endl;
		getline(cin, word);
		
	}
	
	return 0;
}