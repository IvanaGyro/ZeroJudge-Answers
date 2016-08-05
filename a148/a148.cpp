#include <iostream>

using namespace std;

int main(){
	int num, sum, buf;
	while (cin >> num){
		sum = 0;
		for (int i = 0; i < num; i++){
			cin >> buf;
			sum += buf;
		}
		if (sum > num * 59) cout << "no" << endl;
		else cout << "yes" << endl;
	}
}