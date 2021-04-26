#include <iostream>
#include <fstream>
#include <string>
#include <map>
#include <queue>

using namespace std;
ifstream fin("stl.in");

class Compare {
public:
	bool operator() (map<string, int>::iterator s1, map<string, int>::iterator s2)
	{
		if (s1->second < s2->second) return true;
		if (s1->second > s2->second) return false;
		if (s1->first < s2->first) return false;
		return true;
	}
};

bool isSeparator(char c) {
	if (c == ' ' || c == ',' || c == '.' || c == '!' || c == '?')
		return 1;
	return 0;
}

string toLowerCase(string& str) {
	for (unsigned int i = 0; i < str.length(); i++)
		if (str[i] >= 'A' && str[i] <= 'Z')
			str[i] = str[i] - 'A' + 'a';
	return str;
}

int main() {
	string s;
	map<string, int> Words;
	getline(fin, s);
	int i = 0;
	int j = 0;
	for (i = 0; i < s.length(); i++) {
		if (isSeparator(s[i])) {
			string aux(s, i-j, j);
			aux = toLowerCase(aux);
			if (aux != "")
			   Words[aux]++;
			j = 0;
		}
		else j++;
	}
	map<string, int>::iterator it;
	priority_queue<map<string, int>::iterator, vector<std::map<std::string, int>::iterator>, Compare> p;
	for (it = Words.begin(); it != Words.end(); it++)
		p.push(it);
	while (!p.empty()) {
		cout << p.top()->first << " => " << p.top()->second << endl;
		p.pop();
	}
	return 0;
}