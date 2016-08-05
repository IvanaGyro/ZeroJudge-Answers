#include <iostream>

using namespace std;

int main(){
	int m, n;
	while (cin >> n){
		cin >> m;
		if (m == n) cout << m << endl;
		else cout << m + 1 << endl;
	}
}