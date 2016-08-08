#include <iostream>

using namespace std;

int main(){
	int x = 1, y = 17;
	int m, n;
	int ans, sum;
	int lines;
	cin >> lines;
	while (lines--){
		cin >> n;
		ans = 0;
		sum = 0;
		x = 1;
		while (n--){
			x *= 10;
			ans = x / y;
			sum += ans;
			x %= y;
		}
		cout << ans << " " << sum << endl;
	}
}