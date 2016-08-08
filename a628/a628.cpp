#include <iostream>
#include <iomanip>

using namespace std;

int main(){
	int state, count, edge;
	int n, x, y, ptr;
	int **arr;
	while (cin >> n){
		arr = new int*[n];
		for (int i = 0; i < n; ++i)arr[i] = new int[n];
		x = n / 2;
		y = n / 2;
		state = 0;
		edge = 1;
		count = 0;
		arr[x][y] = 0;

		for (ptr = 1; ptr < n*n; ++ptr){
			switch (state){
			case 0:
				++x;
				break;
			case 1:
				--y;
				break;
			case 2:
				--x;
				break;
			case 3:
				++y;
				break;
			}
			arr[x][y] = ptr;
			if (++count % edge == 0) ++state %= 4;
			if (count == edge << 1){
				++edge;
				count = 0;
			}
		}
		for (int i = 0; i < n; ++i){
			for (int j = 0; j < n; ++j){
				cout << setw(4) << arr[j][i];
			}
			cout << endl;
		}
		cout << endl;
	}
}

