#include <iostream>
#include <string>

using namespace std;

int main(){
	int num, mask;
	string str;
	while (cin >> num){
		mask = 0x40000000;
		str = "";
		if (num & 0x80000000) str = "1";
		else{
			while (!(mask & num)) mask >>= 1;
		}
		while (mask){
			if (mask & num) str += '1';
			else str += '0';
			mask >>= 1;
		}
		cout << str << endl;
	}
}

