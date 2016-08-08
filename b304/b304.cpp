#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main(){
	string input;
	int n;
	bool right;
	vector<char> stack;
	cin >> n;
	getchar(); // get \n
	while (n--){
		getline(cin, input);
		right = true;
		stack.clear();
		for (string::iterator siter = input.begin(); siter != input.end() && right; ++siter){
			switch (*siter){
			case '(':
				stack.push_back('(');
				break;
			case '[':
				stack.push_back('[');
				break;
			case ')':
				if (!stack.empty()){
					if (stack.back() != '(') right = false;
					else stack.pop_back();
				}
				else right = false;
				break;
			case ']':
				if (!stack.empty()){
					if (stack.back() != '[') right = false;
					else stack.pop_back();
				}
				else right = false;
				break;
			default:
				break;
			}
		}
		if (!stack.empty()) right = false;
		if (right) cout << "Yes" << endl;
		else cout << "No" << endl;
	}
}