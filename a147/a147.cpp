#include <iostream>

using namespace std;

int main(){
	int n;
	while (cin >> n){
		for (int i = 1; i < n; i++){
			if (i % 7)cout << i << " ";
		}
		cout << endl;
	}
}