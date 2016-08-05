#include <iostream>
#include <cmath>

using namespace std;

int main(){
	int n, m, tmp, r, sum;
	bool found;
	while (cin >> n){
		cin >> m;
		found = false;	
		for (int i = n; i <= m; i++){	
			r = 0;
			tmp = i;
			while (tmp){
				r++;
				tmp /= 10;
			}
			sum = 0;
			tmp = i;
			while (tmp){
				sum += pow(tmp % 10, r);
				tmp /= 10;
			}
			if (sum == i){
				found = true;
				cout << i << " ";
			}
		}
		if (!found) cout << "none" << endl;
		else cout << endl;
	}
}