/*#include <iostream>

using namespace std;

int main(){
	int i, j,t, n, count, min = 0, tmp, pre, r;
	int sum[1000], first[1000];
	cin >> t;
	for (t; t > 0; t--){
		cin >> n;
		for (i = 0; i < n; i++){
			sum[i] = 0;
		}
		for (i = 0; i < n; i++){
			cin >> pre;
			first[i] = pre;
			for (j = 1; j < n; j++){
				cin >> tmp;
				sum[i] += tmp > pre ? tmp - pre : tmp - pre + n;
				pre = tmp;
			}
		}

		min = 0;
		for (i = 0; i < n; i++){
			count = 0;
			for (j = 0; j < n; j++){
				r = (i + j) % n + 1;
				tmp = first[j] >= r ? (first[j] - r) : (first[j] - r + n);
				tmp += sum[j];
				count = count>tmp ? count : tmp;
			}
			if (min == 0 || count < min) min = count;
		}
		cout << min << endl;
	}
}*/


#include <stdio.h>


int main(){
	int i, j, t, n, count, min = 0, tmp, pre, r;
	int sum[1000], first[1000];
	scanf("%d", &t);
	for (t; t > 0; t--){
		scanf("%d", &n);
		for (i = 0; i < n; i++){
			sum[i] = 0;
		}
		for (i = 0; i < n; i++){
			scanf("%d", &pre);
			first[i] = pre;
			for (j = 1; j < n; j++){
				scanf("%d", &tmp);
				sum[i] += tmp > pre ? tmp - pre : tmp - pre + n;
				pre = tmp;
			}
		}

		min = 0;
		for (i = 0; i < n; i++){
			count = 0;
			for (j = 0; j < n; j++){
				r = (i + j) % n + 1;
				tmp = first[j] >= r ? (first[j] - r) : (first[j] - r + n);
				tmp += sum[j];
				count = count>tmp ? count : tmp;
			}
			if (min == 0 || count < min) min = count;
		}
		printf("%d\n", min);
	}
}