#include <iostream>

using namespace std;

int main(){
	int a, b, c, d;
	int judge[10][4];

	judge[0][0] = 719;
	judge[0][1] = 896;
	judge[0][2] = 448;
	judge[0][3] = 727;

	judge[1][0] = 674;
	judge[1][1] = 665;
	judge[1][2] = 142;
	judge[1][3] = 712;

	judge[2][0] = 663;
	judge[2][1] = 758;
	judge[2][2] = 38;
	judge[2][3] = 860;

	judge[3][0] = 293;
	judge[3][1] = 383;
	judge[3][2] = 422;
	judge[3][3] = 717;

	judge[4][0] = 392;
	judge[4][1] = 605;
	judge[4][2] = 903;
	judge[4][3] = 154;

	judge[5][0] = 42;
	judge[5][1] = 468;
	judge[5][2] = 335;
	judge[5][3] = 501;

	judge[6][0] = 663;
	judge[6][1] = 758;
	judge[6][2] = 38;
	judge[6][3] = 191;

	judge[7][0] = 663;
	judge[7][1] = 758;
	judge[7][2] = 38;
	judge[7][3] = 36;

	judge[8][0] = 663;
	judge[8][1] = 758;
	judge[8][2] = 38;
	judge[8][3] = 779;

	judge[9][0] = 663;
	judge[9][1] = 758;
	judge[9][2] = 38;
	judge[9][3] = 289;

	bool horse = false;
	cin >> a;
	cin >> b;
	cin >> c; 
	cin >> d;
	for (int i = 0; i < 10; i++){
		if (a == judge[i][0] && b == judge[i][1] && c == judge[i][2] && d == judge[i][3]) horse = true;
	}

	if (horse) cout << "YES" << endl;
	else cout << "NO" << endl;

}