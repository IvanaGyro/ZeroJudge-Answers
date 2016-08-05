#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(){
	int buf, t;
	vector<int> arr;
	while (cin >> t){
		arr.reserve(t);
		while (t--){
			cin >> buf;
			arr.push_back(buf);
		}
		sort(arr.begin(), arr.end());
		for (vector<int>::iterator iter = arr.begin(); iter != arr.end(); iter++){
			cout << *iter << " ";
		}
		cout << endl;
		vector<int>().swap(arr);
	}
}