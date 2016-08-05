#include <iostream>

using namespace std;

void clear1dm(int* m, int x){
	for (int i = 0; i < x; i++){
		m[i] = 0;
	}
}

int main(){
	int m[9][9];
	int f[9];
	bool ok = true;

	while (cin >> m[0][0]){
		ok = true;
		for (int j = 1; j < 9; j++) cin >> m[0][j];
		for (int i = 1; i < 9; i++){
			for (int j = 0; j < 9; j++){
				cin >> m[i][j];
			}
		}

		for (int i = 0; i < 9; i++){
			clear1dm(f, 9);
			for (int j = 0; j < 9; j++){
				if (f[m[i][j]-1] == 0 && ok) f[m[i][j]-1] = 1;
				else{
					ok = false;
					i = 9;
					j = 9;
				}
			}
		}

		for (int i = 0; i < 9; i++){
			clear1dm(f, 9);
			for (int j = 0; j < 9; j++){
				if (f[m[j][i]-1] == 0 && ok) f[m[j][i]-1] = 1;
				else{
					ok = false;
					i = 9;
					j = 9;
				}
			}
		}

		for (int i = 0; i < 9; i += 3){
			for (int j = 0; j < 9; j += 3){
				clear1dm(f, 9);
				for (int x = 0; x < 3; x++){
					for (int y = 0; y < 3; y++){
						if (f[m[i + x][j + y]-1] == 0 && ok) f[m[i + x][j + y]-1] = 1;
						else{
							ok = false;
							x = 3;
							y = 3;
							i = 9;
							j = 9;
						}
					}
				}
			}
		}
		if (ok) cout << "yes" << endl;
		else cout << "no" << endl;
	}
}