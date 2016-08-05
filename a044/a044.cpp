#include <iostream>

using namespace std;

int main(){
	int x;
	while (cin >> x) cout << x*(x*x + 5) / 6 + 1 << endl;
}