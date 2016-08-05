#include <iostream>
#include <string>
#include <cmath>
#include <cstring>

#define RomaDigitCount 7 
using namespace std;

namespace RomaNum{
typedef struct {
	char letter;
	int val;
}RomaDigit;

RomaDigit RomaDTb[RomaDigitCount] = {
	{ 'I', 1 },
	{ 'V', 5 },
	{ 'X', 10 },
	{ 'L', 50 },
	{ 'C', 100 },
	{ 'D', 500 },
	{ 'M', 1000 }
};

int Romatoi(const char* r){
	const char* ptr;
	int num = 0, last = 0;
	ptr = r + strlen(r);
	while (ptr != r){
		for (int i = 0; i < RomaDigitCount; i++){
			if (RomaDTb[i].letter == *(ptr - 1)){
				
				if (RomaDTb[i].val >= last){
					last = RomaDTb[i].val;
					num += last;
				}
				else num -= RomaDTb[i].val;
			}
		}
		ptr--;
	}
	return num;
}

string itoRoma(const int num){
	string r = "";
	int tmp;
	for (int i = RomaDigitCount - 1; i >= 0; i-=2){
		tmp = (num / RomaDTb[i].val) % 10;
		if (tmp == 9){
			r += RomaDTb[i].letter;
			r += RomaDTb[i + 2].letter;
		}
		else if (tmp >= 5){
			r += RomaDTb[i+1].letter;
			tmp -= 5;
			for (int j = 0; j < tmp; j++) r += RomaDTb[i].letter;
		}
		else if (tmp == 4){
			r += RomaDTb[i].letter;
			r += RomaDTb[i + 1].letter;
		}
		else{
			for (int j = 0; j < tmp; j++) r += RomaDTb[i].letter;
		}
	}
	return r;
}

}// namespace RomaNum

int main(){
	string s1, s2;
	int n1, n2, found = 0;
	getline(cin, s1);
	while (s1 != "#"){
		s2 = s1.substr(s1.find_first_of(" ")+1);
		s1 = s1.substr(0, s1.find_first_of(" "));
		n1 = RomaNum::Romatoi(s1.c_str());
		n2 = RomaNum::Romatoi(s2.c_str());
		n1 = abs(n1 - n2);
		if (n1 == 0) cout << "ZERO" << endl;
		else cout << RomaNum::itoRoma(n1) << endl;
		getline(cin, s1);
	} 
}