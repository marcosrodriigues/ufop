#include <iostream>
#include <string>
using namespace std;

void strpack(string ch);

int main() {

	string word;
	getline(cin, word);
	
	strpack(word);
	
	return 0;
}

void strpack(string ch) {
	string str;
	int j = 0;

	for (int i = 0; i < ch.length(); i++) {
		if (j == 0) {
			str += ch[i];
			j++;
		} else {
			if (str[j - 1] != ch[i]) {
				str += ch[i];
				j++;
			}
		}
	}	
	cout << str;
}