#include <iostream>
#include <cmath>

using namespace std;

int main(){
	int a, b, c, n, b2_4ac,r;
	while (cin >> n){
		for (n; n; n--){
#ifdef _MSC_VER
			scanf_s("%d", &a);
			scanf_s("%d", &b);
			scanf_s("%d", &c);
#else
			scanf("%d", &a);
			scanf("%d", &b);
			scanf("%d", &c);
#endif //_MSC_VER
			b2_4ac = b*b - 4 * a*c;
			r = sqrt(b2_4ac);
			if (r*r == b2_4ac) printf("Yes\n");
			else printf("No\n");
		}
	}


}