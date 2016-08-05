#include <iostream>
#include <cstdio>
#include <string>

using namespace std;

bool isvalidP(int n, int* pos){
	static int i, count;
	count = 0;
	for (i = 0; i < n; ++i){
		if (pos[i] < n){
			count++;
			if (count >= n >> 1 + n & 1) return true;
		}
		else return false;
	}
	return false;
}

bool isEnd(int n, int* pos){
	static int i;
	for (i = 0; i < n; ++i){
		if (pos[i] != i * 2)return false;
	}
	return true;
}


void cP(int n, int l, int* pos){
	static int i;
	if (l < n - 1){
		cP(n, l + 1, pos);
		if (pos[l + 1] >(l + 1) * 2){
			for (i = n - 1; i >= l; --i){
				pos[i] = pos[l] + i - l + 1;
			}
		}
	}
	else pos[l]++;
}


void printP(int n, int* pos){
	static string s;
	static int i;
	s.clear();
	s.append(n, '(');
	s.append(n, ')');
	printf("%s\n", s.c_str());
	for (i = 0; i < n; ++i) pos[i] = i;
	while (!isEnd(n, pos)){
		cP(n, 0, pos);
		if (isvalidP(n, pos)){
			s.clear();
			s.append(n * 2, ')');
			for (i = 0; i < n; ++i){
				s[pos[i]] = '(';
			}
			printf("%s\n", s.c_str());
			//cout << s << endl;
		}
	}
}

int main(){
	int n, mask;
	int *pos;
	while (cin >> n){
		pos = new int[n];
		printP(n, pos);
		printf("\n");
	}


}