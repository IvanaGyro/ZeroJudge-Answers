#include <iostream>

#ifdef _MSC_VER
#define scanf scanf_s
#endif //_MSC_VER

using namespace std;

int main(){
	unsigned n, count;
	while (scanf("%d", &n) == 1 && n != 0){
		n = ~n;
		count = 0;
		if (n >> 16 << 16 == n){
			n >>= 16;
			count += 16;
		}
		if (n >> 8 << 8 == n){
			n >>= 8;
			count += 8;
		}
		if (n >> 4 << 4 == n){
			n >>= 4;
			count += 4;
		}
		if (n >> 2 << 2 == n){
			n >>= 2;
			count += 2;
		}
		if (n >> 1 << 1 == n){
			n >>= 1;
			count += 1;
		}
		printf("%d\n", count);
	}
}