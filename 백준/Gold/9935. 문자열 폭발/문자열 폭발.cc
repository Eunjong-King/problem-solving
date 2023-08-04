#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

vector<char> v;
string org, tnt;

bool isExplode() {
	if((v.size() - 1 - tnt.size() + 2) < 0) {
		return false;
	}
	
	for(int i=0; i<tnt.size() - 1; i++) {
		if(v.size() - 1 - tnt.size() + 2 + i >= v.size() || v[v.size() - 1 - tnt.size() + 2 + i] != tnt.at(i)) {
			return false;
		}
	}
	return true;
}

int main() {
	cin >> org >> tnt;
	
	char trigger = tnt[tnt.length() - 1];
	
	for(int i=0; i<org.length(); i++) {
		if(org.at(i) == trigger) {
			if(isExplode()) {
				v.erase(v.end() - tnt.length() + 1, v.end());
			} else {
				v.push_back(org.at(i));
			}
		} else {
			v.push_back(org.at(i));
		}
	}
	
	if(v.size() == 0) {
		cout << "FRULA" << endl;
	} else {
		for(char c : v) {
			cout << c;
		}
		cout << endl;
	}
	
	return 0;
}