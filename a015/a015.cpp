#include <iostream>

using namespace std;

int main(){
	int r, c;
	int m[100][100];
	while (cin >> r){
		cin >> c;
		for (int i = 0; i < r; i++){
			for (int j = 0; j < c; j++){
				cin >> m[i][j];
			}
		}

		for (int i = 0; i < c; i++){
			for (int j = 0; j < r; j++){
				cout << m[j][i] << " ";
			}
			cout << endl;
		}
	}
}