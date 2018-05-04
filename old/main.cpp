#include <iostream>
#include <vector>
#include "Rotator.h"
using namespace std;

vector<string> sort(vector<string> &phrases) {
	Rotator rotator(phrases);
	vector<string> rotations;
	rotations = rotator.getRotations(phrases);
	return rotations;
}

int main() {
	vector<string> phrases;
	string phrase;
	cout << "Enter phrases, press CTRL+D when done:" << endl;
	while (getline(cin, phrase)) {
		phrases.push_back(phrase);
	}
	vector<string> rotations = sort(phrases);
	vector<string>::iterator iter;
	cout << "KWICs Generated:" << endl;
	for(iter = rotations.begin(); iter != rotations.end(); iter++) {
		cout << *iter << endl;
	}

	return 0;
}
