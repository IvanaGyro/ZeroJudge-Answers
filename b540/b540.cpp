#include <iostream>

using namespace std;

int main(){
	int ans;
	int e[6];
	while (cin >>e[0]){
		for (int i = 1; i < 6; i++){
			cin >> e[i];
			ans = (e[0] + e[1] + e[2])*(e[0] + e[1] + e[2]) - e[0] * e[0] - e[2] * e[2] - e[4] * e[4];
		}
		cout << ans << endl;
	}
}