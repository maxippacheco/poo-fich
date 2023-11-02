#include<iostream>

using namespace std;

string corregir(string str) {

	if (!str.empty()) {
		str[0] = toupper(str[0]);
	
		for (size_t i=1; i<str.size(); i++)
			str[i] = tolower(str[i]);
	}
	return str;
}
int main() {
	string s1 = "sIGue AL COnEjo BlaNCo.";
	string s2 = corregir(s1);
	cout << s2;
}