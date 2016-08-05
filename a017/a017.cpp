#define CODE2

#ifdef CODE1
#include <iostream>
#include <string>
#include <cstdlib>


using namespace std;

int main(){
	string s;
	while (getline(cin, s)){
		s = "echo 1 | awk '{printf \"%d\"," + s;
		s += "}'";
		system(s.c_str());
		cout << endl;
	}
}
#endif //CODE1

#ifdef CODE2

#include <iostream>
#include <vector>
#include <string>
#include <utility>

using namespace std;

enum OpPcd{
	MUL_P = 1,
	DIV_P = 1,
	MOD_P = 1,
	ADD_P = 2,
	SUB_P = 2,
	RBC_P = 10,
	LBC_P = 11,
	FIN_P = 0x7ffffffe,
	END_P = 0x7fffffff
};

enum OpName{
	MUL,
	DIV,
	MOD,
	ADD,
	SUB,
	RBC,
	LBC,
	END
};

void count(pair<OpPcd, OpName> op, vector<pair<OpPcd, OpName>>& vop, vector<int>& vnum){
	int post, pre;
	while (vop.back().first <= op.first){
		if (vnum.size() >= 2){
			post = vnum.at(vnum.size() - 1);
			vnum.pop_back();
			pre = vnum.at(vnum.size() - 1);
			vnum.pop_back();
			switch (vop.back().second){
			case MUL:
				vnum.push_back(pre*post);
				break;
			case DIV:
				vnum.push_back(pre / post);
				break;
			case MOD:
				vnum.push_back(pre%post);
				break;
			case ADD:
				vnum.push_back(pre + post);
				break;
			case SUB:
				vnum.push_back(pre - post);
				break;
			}
		}
		vop.pop_back();
	}
	vop.push_back(op);
}

int main(){
	string s, buf;
	vector<int> vnum;
	vector<pair<OpPcd, OpName>> vop;
	pair<OpPcd, OpName> op;
	int intbuf;
	int ans;

	buf.reserve(16);
	buf = "";
	while (getline(cin, s)){
		vnum.clear();
		vop.clear();
		vop.push_back(make_pair(END_P, END));
		for (int i = 0; i < s.length(); i++){
			switch (s[i]){
			case '*':
				op = make_pair(MUL_P, MUL);
				count(op, vop, vnum);
				break;
			case '/':
				op = make_pair(DIV_P, DIV);
				count(op, vop, vnum);
				break;
			case '%':
				op = make_pair(MOD_P, MOD);
				count(op, vop, vnum);
				break;
			case '+':
				op = make_pair(ADD_P, ADD);
				count(op, vop, vnum);
				break;
			case '-':
				op = make_pair(SUB_P, SUB);
				count(op, vop, vnum);
				break;
			case '(':
				op = make_pair(LBC_P, LBC);
				vop.push_back(op);
				break;
			case ')':
				op = make_pair(RBC_P, RBC);
				count(op, vop, vnum);
				vop.pop_back(); //)
				vop.pop_back(); //(
				break;
			}
			if (s[i] >= '0' && s[i] <= '9'){
				intbuf = s[i] - '0';
				while (s[i + 1] >= '0' && s[i + 1] <= '9'){
					i++;
					intbuf *= 10;
					intbuf += s[i] - '0';
				}
				vnum.push_back(intbuf);
			}
		}
		op = make_pair(FIN_P, END);
		count(op, vop, vnum);
		try{
			cout << vnum.at(vnum.size()-1) << endl;
		}
		catch (...){}
	}
}

#endif //CODE2

#ifdef CODE3

#include <iostream>
#include <cstring>
#include <cctype>
#include <string>
using namespace std;
int DFS(int, int);
string s;
int main(){
	while (getline(cin, s)){
		int result = DFS(0, s.length());
		cout << result << endl;
	}
}
int DFS(int le, int ri){
	int c = 0;
	for (int i = ri - 1; i >= le; i--){//後加減，先遞迴 
		if (s[i] == ')') c++;    //括弧內部分割      
		if (s[i] == '(') c--;
		if (s[i] == '+' && c == 0){ //後加減，先遞迴 
			return DFS(le, i) + DFS(i + 1, ri);
		}
		if (s[i] == '-' && c == 0){
			return DFS(le, i) - DFS(i + 1, ri);
		}
	}
	for (int i = ri - 1; i >= le; i--){ //先乘除，後遞迴 
		if (s[i] == ')') c++;    //括弧內部分割      
		if (s[i] == '(') c--;
		if (s[i] == '*' && c == 0){ //先乘除，後遞迴 
			return DFS(le, i)*DFS(i + 1, ri);
		}
		if (s[i] == '/' && c == 0){
			return DFS(le, i) / DFS(i + 1, ri);
		}
		if (s[i] == '%' && c == 0){
			return DFS(le, i) % DFS(i + 1, ri);
		}
	}
	if ((s[le] == '(') && (s[ri - 1] == ')')) return DFS(le + 1, ri - 1);  //去除刮號
	if (s[le] == ' ' &&s[ri - 1] == ' ') return  DFS(le + 1, ri - 1); //去除左右兩邊空格 
	if (s[le] == ' ') return  DFS(le + 1, ri); //去除左邊空格 
	if (s[ri - 1] == ' ') return  DFS(le, ri - 1); //去除右邊空格
	int num = 0;
	if (isdigit(s[le]) && isdigit(s[ri - 1])){//轉成數字 
		for (int i = le; i<ri; i++) num = num * 10 + s[i] - '0';
		return num;
	}
}

#endif //CODE3
