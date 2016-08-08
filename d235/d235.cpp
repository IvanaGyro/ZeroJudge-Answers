#include <iostream>
#include <string>

using namespace std;

int main(){
	string num;
	int sum, state;
	while (getline(cin, num) && num != "0"){
		sum = 0;
		state = 0;
		for (string::iterator siter = num.begin(); siter != num.end(); ++siter){
			if (state == 0){
				sum += *siter - '0';
				state = 1;
			}
			else{
				sum -= *siter - '0';
				state = 0;
			}
		}
		if (sum % 11 == 0) cout << num << " is a multiple of 11." << endl;
		else cout << num << " is not a multiple of 11." << endl;
	}
}