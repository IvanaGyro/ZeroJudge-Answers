#include <iostream>
#include <string>

using namespace std;

int main(){
	string str;
	while (getline(cin, str)){
		for (string::iterator striter = str.begin(); striter != str.end(); striter++){
			*striter -= 7;
		}
		cout << str << endl;
	}
}