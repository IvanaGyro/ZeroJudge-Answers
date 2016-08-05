#include <iostream>

using namespace std;

int main(){
	int times, n, k0 = 0, k1 = 0, k2 = 0;
	cin >> times;
	for (times; times; times--){
		cin >> n;
		if (n % 3 == 0) k0++;
		else if (n % 3 == 1)k1++;
		else k2++;
	}
	cout << k0 << " " << k1 << " " << k2 << endl;
}