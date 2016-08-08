#include <iostream>

using namespace std;

int main(){
	int m, n, count, tmp;
	cin >> m;
	while (m--){
		cin >> n;
		count = 0;
		while ((tmp = n--) > 1){
			while (tmp % 5 == 0) tmp /= 5;
			while ((tmp & 1) == 0) tmp >>= 1;
			if (tmp == 1) count++;
		}
		cout << count << endl;
	}
}