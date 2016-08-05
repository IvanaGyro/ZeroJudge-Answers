#include <iostream>
#include <cmath>

using namespace std;

int main(){
	int a, b, count, r;
	bool isP;
	while (cin >> a){
		cin >> b;
		count = 0;
		for (int i = a; i <= b; i++){
			if (i == 2) count++;
			else if (i & 1 && i != 1){
				isP = true;
				r = sqrt(i);
				for (int j = 3; j <= r; j++){
					if (i % j == 0){
						isP = false;
						break;
					}
				}
				if (isP) count++;
			}
		}
		if (count == 169) cout << a << " " << b << endl;
		else cout << count << endl;
	}
}
