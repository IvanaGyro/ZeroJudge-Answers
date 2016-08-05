#include <iostream>

using namespace std;

int main(){
	int n, buf, ans;
	while (cin >> n){
		for (n; n; n--){
			cin >> buf;
			ans = buf % 10;
			buf /= 10;
			while (buf){
				ans *= buf % 10;
				buf /= 10;
			}
			cout << ans << endl;
		}
	}

}