#include <iostream>

using namespace std;

int main(){
	int n, m, count, sum;
	while (cin >> n){
		cin >> m;
		sum = n;
		for (count = 1; sum <= m; count++){
			sum += n + count;
		}
		cout << count << endl;
	}
}