#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main(){
	string str;
	int idx, val, sum = 0, len;
	vector<int> vidx, vval;
	string::size_type sz, szc;
	getline(cin, str);
	str += ' ';
	szc = 0;
	len = str.length();
	while (szc != len){
		idx = stoi(str.substr(szc), &sz);
		szc += sz+1;
		val = stoi(str.substr(szc), &sz);
		szc += sz +1;
		vidx.push_back(idx);
		vval.push_back(val);
	}
	getline(cin, str);
	str += ' ';
	szc = 0;
	len = str.length();
	while (szc != len){
		idx = stoi(str.substr(szc), &sz);
		szc += sz + 1;
		val = stoi(str.substr(szc), &sz);
		szc += sz + 1;
		for (int i = 0; i < vidx.size(); i++){
			if (idx == vidx[i]){
				sum += vval[i] * val;
				break;
			} 
		}
	}
	cout << sum << endl;
}
