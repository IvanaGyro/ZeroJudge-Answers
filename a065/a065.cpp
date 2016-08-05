#include <iostream>
#include <string>

using namespace std;

int main(){
	string str;
	while (getline(cin, str)){
		for (int i = 1; i < 7; i++){
			cout << static_cast<int>(str[i]>str[i - 1] ? str[i] - str[i - 1] : str[i - 1] - str[i]);
		}
		cout << endl;
	}
}