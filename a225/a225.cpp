#include <iostream>

using namespace std;

int compare(int a, int b){
	if (a == b) return 0;
	if (a % 10 == b % 10){
		if (a > b) return -1;
		else return 1;
	}
	else if (a % 10 < b % 10) return -1;
	else return 1;
}


void quicksort(int beg, int end, int* sq){
	static int std, curidx, leftidx;
	if (beg >= end) return;
	std = sq[beg];
	leftidx = beg;
	for (curidx = beg + 1; curidx <= end; curidx++){
		if (compare(sq[curidx], std) <= 0){
			leftidx++;
			swap(sq[curidx], sq[leftidx]);
		}
	}
	swap(sq[beg], sq[leftidx]);

	quicksort(beg, leftidx - 1, sq);
	quicksort(leftidx + 1, end, sq);
}



int main(){
	int n, i;
	int *sq;
	while (cin >> n){
		sq = new int[n];
		for (i = 0; i < n; ++i){
			cin >> sq[i];
		}
		quicksort(0, n - 1, sq);
		for (i = 0; i < n; ++i) cout << sq[i] << " ";
		cout << endl;
		delete[] sq;
	}

}