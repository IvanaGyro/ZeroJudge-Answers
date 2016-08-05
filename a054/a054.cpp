#include <iostream>

using namespace std;

int main(){
	int sum, follow;
	int first[26];
	for (char ch = 'A'; ch <= 'Z'; ch++){
		switch (ch){
		case 'A':
			sum = 1 + 0 * 9;
			break;
		case 'B':
			sum = 1 + 1 * 9;
			break;
		case 'C':
			sum = 1 + 2 * 9;
			break;
		case 'D':
			sum = 1 + 3 * 9;
			break;
		case 'E':
			sum = 1 + 4 * 9;
			break;
		case 'F':
			sum = 1 + 5 * 9;
			break;
		case 'G':
			sum = 1 + 6 * 9;
			break;
		case 'H':
			sum = 1 + 7 * 9;
			break;
		case 'I':
			sum = 3 + 4 * 9;
			break;
		case 'J':
			sum = 1 + 8 * 9;
			break;
		case 'K':
			sum = 1 + 9 * 9;
			break;
		case 'L':
			sum = 2 + 0 * 9;
			break;
		case 'M':
			sum = 2 + 1 * 9;
			break;
		case 'N':
			sum = 2 + 2 * 9;
			break;
		case 'O':
			sum = 3 + 5 * 9;
			break;
		case 'P':
			sum = 2 + 3 * 9;
			break;
		case 'Q':
			sum = 2 + 4 * 9;
			break;
		case 'R':
			sum = 2 + 5 * 9;
			break;
		case 'S':
			sum = 2 + 6 * 9;
			break;
		case 'T':
			sum = 2 + 7 * 9;
			break;
		case 'U':
			sum = 2 + 8 * 9;
			break;
		case 'V':
			sum = 2 + 9 * 9;
			break;
		case 'W':
			sum = 3 + 2 * 9;
			break;
		case 'X':
			sum = 3 + 0 * 9;
			break;
		case 'Y':
			sum = 3 + 1 * 9;
			break;
		case 'Z':
			sum = 3 + 3 * 9;
			break;
		}
		first[ch - 'A'] = sum;
	}
	while (cin >> follow){
		sum = follow % 10;
		follow /= 10;
		for (int i = 0; i < 8; i++){
			sum += (follow % 10)*(i + 1);
			follow /= 10;
		}
		for (int i = 0; i < 26; i++){
			if ((sum + first[i]) % 10 == 0) cout << (char)(i + 'A');
		}
		cout << endl;
	}
}