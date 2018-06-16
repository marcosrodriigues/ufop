#include <iostream>
#include <iomanip>
using namespace std;

double meters(double feet) {
	return feet * 3.281;
}

int main() {
	
	double feet;
	
	cin >> feet;
	
	while (feet != 0.0) {
		cout << setprecision(5) << meters(feet) << endl;
		cin >> feet;
	}
	
	return 0;
}