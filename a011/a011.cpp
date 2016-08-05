#include <iostream>
#include <string>

using namespace std;

int main(){
	int count, ptr, ptr2;
	string str;
	while (getline(cin, str)){
		count = 0;
		while (str.length()){
			str = str.substr((ptr = str.find_first_of("ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz"))==string::npos?str.length():ptr);
			str = str.substr((ptr2 = str.find_first_not_of("ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz")) == string::npos ? str.length() : ptr2);
			if(ptr != string::npos) count++;
		}
		cout << count << endl;
	}
}