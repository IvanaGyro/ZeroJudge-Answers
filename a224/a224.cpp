#include <iostream>
#include <string>

using namespace std;

int isEn_toidx(char& ch){
	if (ch >= 'A' && ch <= 'Z') return ch - 'A';
	if (ch >= 'a' && ch <= 'z') return ch - 'a';
	return -1;
}

int main(){
	string s;
	int idx, sum;
	int count[26];
	while (getline(cin, s)){
		sum = 0;
		for (int i = 0; i < 26; ++i) count[i] = 0;
		for (int i = 0; i < s.length(); ++i){
			if ((idx = isEn_toidx(s[i])) >= 0){
				if (count[idx]) count[idx] = 0;
				else count[idx] = 1;
			}
		}
		for (int i = 0; i < 26; ++i) sum += count[i];
		if (sum <= 1) cout << "yes !" << endl;
		else cout << "no..." << endl;
	}
}