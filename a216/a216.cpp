#include <iostream>

using namespace std;

int main(){
	long long n;
	while (cin >> n){
		cout << n*(n + 1) / 2 << " " << n*(n + 1)*(n + 2) / 6 << endl;
	}
}