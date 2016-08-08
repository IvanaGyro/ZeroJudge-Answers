#include <iostream>

using namespace std;

int read_int(int& n){
	static char c;
	static int neg;
	n = 0;
	while ((c = getchar()) != '-' && (c < '0' || c > '9')) if (c == EOF) return 0;
	if (c == '-') neg = -1;
	else{
		neg = 0;
		n = static_cast<int>(c - '0');
	}
	while ((c = getchar()) >= '0' && c <= '9'){
		n = (n << 3) + (n << 1) + static_cast<int>(c - '0');
	}
	if (neg) n = -n;
	ungetc(c, stdin);
	return 1;
}


int main(){
	int lines;
	int a, b, c;
	while (read_int(lines)){
		while (lines--){
			read_int(a);
			read_int(b);
			read_int(c);
			switch (a){
			case 1:
				printf("%lld\n", static_cast<long long>(b)+static_cast<long long>(c));
				break;
			case 2:
				printf("%d\n", b - c);
				break;
			case 3:
				printf("%lld\n", static_cast<long long>(b) * static_cast<long long>(c));
				break;
			case 4:
				printf("%d\n", b / c);
				break;
			default:
				break;
			}
		}
	}
	system("pause");
}