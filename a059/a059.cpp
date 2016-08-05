#include <iostream>
#include <cmath>

using namespace std;

int main(){
	int t, a, b ,sum, r;
	cin >> t;
	for (int i = 0; i < t; i++){
		cin >> a;
		cin >> b;
		sum = 0;
		for (int j = a; j <= b; j++){
			r = sqrt(j);
			if (r*r == j) sum += j;
		}
		cout << "Case " << i + 1 << ": " << sum << endl;
	}
}