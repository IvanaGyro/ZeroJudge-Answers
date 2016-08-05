#include <cstdio>

#ifdef _MSC_VER
#define scanf scanf_s
#endif


int main(){
	int ans[4];
	int guess[4];
	int flag[4];
	int count[10];
	int countcpy[10];
	int n, i, A, B;
	while ( scanf("%d %d %d %d", &ans[0], &ans[1], &ans[2], &ans[3]) == 4){
		for (i = 0; i < 10; ++i) count[i] = 0;
		for (i = 0; i < 4; ++i) count[ans[i]]++;
		scanf("%d", &n);
		while (n--){
			A = 0;
			B = 0;
			for (i = 0; i < 10; ++i) countcpy[i] = count[i];
			for (i = 0; i < 4; ++i){
				scanf("%d", &guess[i]);
				if (guess[i] == ans[i]){
					flag[i] = 1;
					countcpy[guess[i]]--;
					A++;
				} 
				else flag[i] = 0;
			} 
			for (i = 0; i < 4; ++i){
				if (!flag[i] && countcpy[guess[i]]){
					countcpy[guess[i]]--;
					B++;
				}
			}
			printf("%dA%dB\n", A, B);
		}
	}
}