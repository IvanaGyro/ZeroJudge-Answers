#include <iostream>
#include <string.h>

using namespace std;

int main(){
	int num;
	char buffer[11];
	while (cin >> num){
		while (num && !(num % 10)) num /= 10;
#ifdef _MSC_VER
		sprintf_s(buffer, "%d", num);
#else
		sprintf(buffer, "%d", num);
#endif // _MSC_VER
		for (int i = strlen(buffer) - 1; i >= 0; i--){
			cout << buffer[i];
		}
		cout << endl;
	}
}