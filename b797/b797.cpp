/*#include <stdio.h>
#include <math.h>


int countRange(int n, int mr){
	int msq, msqsum;
	int sum = 0;
	if (mr == 1) return 1;
	msq = mr * mr;
	for (msqsum = 0; msqsum <= n; msqsum += msq){
		sum += countRange(n - msqsum, mr - 1);
	}
	return sum;
}


int main(){
	int n, ans, t;
	scanf("%d", &t);
	for (t; t > 0; t--){
		scanf("%d", &n);
		printf("%d\n", countRange(n, (int)sqrt((double)n)));
	}	
}*/


#include <cmath>
#include <iostream>
#include <ctime>


unsigned long long countRange(int n, int mr, unsigned long long** ans){
	int msq, msqsum, i;
	unsigned long long sum = 0;
	if (n == 0) return 0;
	if (mr == 1) return 1;
	if (mr == 2){
		return n / 4 + 1;
	}
	msq = (int)sqrt(n);
	if (ans[n][mr]) {
		return ans[n][mr];
	}
	msq = mr * mr;
	for (msqsum = 0; msqsum < n; msqsum += msq){
		sum += countRange(n - msqsum, mr - 1, ans);
	}
	if (msqsum == n) sum++;
	ans[n][mr] = sum;
	return sum;
}


int main(){
	int n, t, i, j;
	unsigned long long** ans;
	clock_t START, END;

	ans = new unsigned long long*[40001];
	for (i = 0; i < 40001; i++){
		ans[i] = new unsigned long long[201];
		for (j = 0; j < 201; j++){
			ans[i][j] = 0;
		}
	}
	scanf_s("%d", &t);
	START = clock();
	for (t; t > 0; t--){
		scanf_s("%d", &n);
		printf("%llu\n", countRange(n, (int)sqrt((double)n), ans));
		//countRange(n, (int)sqrt((double)n), ans);
	}
	END = clock();
	std::cout << END - START << std::endl;
	system("pause");
}