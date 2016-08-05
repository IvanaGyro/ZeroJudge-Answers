#include <fstream>
#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

#define TIME

#ifdef FILE
int main(){
	fstream fs;
	fs.open("test.txt", ios::out | ios::trunc);
	if (!fs) cout << "error" << endl;

	srand(time(0));

	for (int i = 0; i < 10000000; i++){
		fs << rand()<< endl;
	}
	system("pause");
}
#endif //FILE


#ifdef TIME


int ReadInt1(int* n){
	static char ch;
	static int neg;
	while (((ch = getchar()) < '0' || ch >'9') && ch != '-') if (ch == EOF) return 0;
	if (ch == '-'){
		neg = -1;
		*n = 0;
	}
	else{
		neg = 1;
		*n = ch - '0';
	}
	while ((ch = getchar()) >= '0' && ch <= '9'){
		*n = (*n << 3) + (*n << 1) + ch - '0';
	}
	*n *= neg;
	return 1;
}


int ReadInt2(int* n){
	static char ch;
	static int neg;
	while (((ch = getchar()) < '0' || ch >'9') && ch != '-') if (ch == EOF) return 0;
	if (ch == '-'){
		neg = -1;
		*n = 0;
	}
	else{
		neg = 1;
		*n = ch - '0';
	}
	while ((ch = getchar()) >= '0' && ch <= '9'){
		*n = (*n << 3) + (*n << 1) + ch - '0';
	}
	*n = neg == -1? (-*n):*n;
	return 1;
}


int main(){
	clock_t START;

	int n, i;



	START = clock();
	for (i = 0; i < 5000000; i++) ReadInt1(&n);
	START = clock() - START;
	cout << "ReadInt1:" << START << endl;

	START = clock();
	for (i = 0; i < 5000000; i++) ReadInt2(&n);
	START = clock() - START;
	cout << "ReadInt2:" << START << endl;;

}



#endif TIME