#include <iostream>
#include <string>
using namespace std;

string cryptography(string ch);

int main() {

	string msg;
	
	getline(cin, msg);
	
	cout << cryptography(msg);

	return 0;
}

string cryptography(string ch) {
	for (int i = 0; i < ch.length() && i < 80; i++) {
		if ((ch[i] >= 'a' && ch[i] <= 'z') || (ch[i] >= 'A' && ch[i] <= 'Z')) {
			ch[i] = ch[i] + 1;
		}
			
	}		
	
	return ch;
}