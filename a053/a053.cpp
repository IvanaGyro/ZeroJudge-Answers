#include <iostream>

using namespace std;

int main(){
	int num, sum = 0;
	cin >> num;
	if (num >= 40) sum = 100;
	else{
		if (num > 20){
			sum += num - 20;
			num = 20;
		}
		if (num > 10){
			sum += (num - 10) * 2;
			num = 10;
		}
		sum += num * 6;
	}
	cout << sum << endl;
}