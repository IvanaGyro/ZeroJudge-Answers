#include <iostream>
#include <cmath>

#define DIVISOR 10000000

using namespace std;

int ReadInt(int* n){
	static char ch;
	static bool neg;
	while (((ch = getchar()) < '0' || ch > '9') && ch != '-'){ if (ch == EOF) return 0; }
	neg = ch == '-' ? true : false;
	*n = neg ? 0 : ch - '0';
	while (((ch = getchar()) >= '0') && ch <= '9'){
		*n = (*n << 3) + (*n << 1) + ch - '0';
	}
	*n = neg ? -(*n) : *n;
	//if(ch != EOF) ungetc(ch, stdin);
	return 1;
}

int GCD(int a, int b){
	while ((a %= b) && (b %= a));
	return a + b;
}


void reduction(int* NTb, int n){
	static int i, j, num, d;
	i = n;
	for (; i; i--){
		num = i;
		j = 0;
		while (num != 1){
			d = GCD(num, NTb[j]);
			num /= d;
			NTb[j++] /= d;
		}
	}
}



int main(){
	int n, i, idx;
	int *NTb;
	long long ans;

	NTb = new int[5000];


	while (ReadInt(&n)){
		for (idx = 0, i = 2 * n + 2; idx < n - 1; ++i, ++idx){
			NTb[idx] = i;
		}
		reduction(NTb, n);
		ans = 1;
		for (i = 0; i < n - 1; ++i){
			ans = ans*NTb[i] % DIVISOR;
		}
		printf("%lld\n", ans);
	}
}