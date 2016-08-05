#include <iostream>
#include <string>

using namespace std;

int main(){
	int num, p, n;
	bool f;
	while (cin >> num){
		f = false;
		n = 0;
		while (!(num & 1)){
			n++;
			num >>= 1;
		}
		if (n != 0){
			if (!f) f = true;
			else cout << " * ";
			if (n == 1) cout << "2";
			else cout << "2^" << n;
		}
		p = 3;
		while (p * p <= num){
			n = 0;
			while (num % p == 0){
				num /= p;
				n++;
			}
			if (n != 0){
				if (!f) f = true;
				else cout << " * ";
				if (n == 1) cout << p;
				else cout << p << "^" << n;
			}
			p += 2;
		}
		if (num != 1){
			if (f) cout << " * ";
			cout << num;
		} 
		cout << endl;
	}
}