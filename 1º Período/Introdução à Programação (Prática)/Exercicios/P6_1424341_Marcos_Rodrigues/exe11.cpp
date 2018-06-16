#include <iostream>
#include <string>
#include <sstream>
using namespace std;

string indexs (string word, char ch);

int main() {

	string word;
	char ch;
	
	getline (cin, word);
	
	while (!word.empty()) {
		cin >> ch;
		cin.ignore();
		cout << indexs(word, ch) << endl;
		getline(cin, word);
	}
	
	return 0;
}

string indexs (string word, char ch) {
	const int MAX = 100;
	int valores[MAX];
	int j = 0;
	string toReturn;
	
	for (int i = 0; i < MAX; i++)
		valores[i] = -1;
		
	for (int i = 0; i < word.length(); i++) {
		if (word[i] == ch) {
			valores[j] = i;
			j++;
		}
	}
	
	j = 0;
	stringstream stream;
	stream << "";
	while (valores[j] != -1) {
		stream << valores[j] << " ";
		j++;
	}
	
	toReturn = stream.str();
	if (!toReturn.empty())
		toReturn = toReturn.erase(toReturn.length() - 1);
	
	return "[" + toReturn + "]";
}