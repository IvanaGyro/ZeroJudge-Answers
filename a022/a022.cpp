#include <iostream>
#include <string>

using namespace std;

int main(){
	string str;
	int len;
	bool isPalindrome;
	while (getline(cin, str)){
		isPalindrome = true;
		len = str.length();
		for (int i = 0; i < len / 2; i++){
			if (str[i] != str[len - i - 1]){
				isPalindrome = false;
				break;
			}
		}
		if (isPalindrome) cout << "yes" << endl;
		else cout << "no" << endl;
	}
}