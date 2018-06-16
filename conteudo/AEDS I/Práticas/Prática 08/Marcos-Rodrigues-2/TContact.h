#include <string>
using namespace std;

typedef struct Contact {
	string name;
	int birthday;
	long phone;
}TContact;

typedef struct Dictionary{
	TContact *contact;
	int n, max;
}TDictionary;

TDictionary* newDictionary(int n);
void insertDictionary(TDictionary *dict, TContact contact);
int searchSequential(TDictionary *dict, long phone, int *compare);
int searchBinary(TDictionary *dict, long phone, int *compare);
int insideSearchBinary(TDictionary *dict, long phone, int *compare);