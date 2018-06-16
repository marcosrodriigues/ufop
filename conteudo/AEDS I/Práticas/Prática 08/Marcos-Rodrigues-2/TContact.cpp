#include "TContact.h"
#include <stdlib.h>
#include <iostream>
using namespace std;

TDictionary* newDictionary(int n) {
    TDictionary *dict = new TDictionary;
    dict->n = 0;
    dict->max = n; 
    dict->contact = new TContact[n];

    return dict;
}

void insertDictionary(TDictionary *dict, TContact contact) {
	if (dict->n == (dict->max)){
		dict->max *= 2;
		dict->contact = (TContact*)realloc(dict->contact,sizeof(TContact) * dict->max);
	}

	dict->contact[dict->n++] = contact;
}

int searchSequential(TDictionary *dict, long phone, int *compare) {
	*compare = 0;
	for (int i = 0; i < dict->n - 1; ++i) {
		(*compare)++;
		if (dict->contact[i].phone == phone) 
			return i;
	}
	return -1;
}

int searchBinary(TDictionary *dict, long phone, int *compare) {
	(*compare)++;
	if (dict->n == 0)	
		return -1;

	int left = 0;
	int right = dict->max - 1;
	int middle;

	do {
		middle = (left + right) / 2;
		(*compare)++; //sum just one if, because it's compare just the if, the else always happen if 'if' doesn't it, so, it isn't a new compare
		if (phone > dict->contact[middle].phone) left = middle + 1;
		else right = middle - 1;
		*compare = *compare + 2; //sum two more compare, one for first comparation and another one for the other
	} while (phone != dict->contact[middle].phone && left <= right);

	(*compare)++;
	if (dict->contact[middle].phone == phone) return middle;

	return -1;
}