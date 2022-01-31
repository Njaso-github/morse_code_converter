#include <iostream>
#include <map>
#include <fstream>
#include <vector>
#include <cstring>

using namespace std;

int main() {
	map<char, string> m;
	ifstream ifs;
	ifs.open("morse_code_table", ios::in);
	if (!ifs.is_open()) {
		cout << "fail to open file" << endl;
		return 0;
	}
	char ch; string str;
	while (ifs >> ch >> str) {
		m.insert({ch, str});
	}
	ifs.close();
	vector<string> paragraph;
	string input;
	while (getline(cin, input)) {
		for (int i = 0; i < (int) input.size(); i++) {
			input[i] = tolower(input[i]);
		}
		paragraph.push_back(input);
	}
	for (int i = 0; i < (int) paragraph.size(); i++) {
		for (int j = 0; j < (int) paragraph[i].size(); j++) {
			if (paragraph[i][j] == ' ') {
				cout << "/ ";
			} else if (m.find(paragraph[i][j]) != m.end()) {
				cout << m[paragraph[i][j]] << " ";
			}
		}
		cout << endl;	
	}
	return 0;
}	