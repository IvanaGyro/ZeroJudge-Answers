#include <iostream>
#include <string>

using namespace std;

string add(const string a,const string b){
	if (a.length() < b.length()) return add(b, a);
	string ans;
	int carry = 0, len_b, len_a,i;
	ans = a;
	len_a = a.length();
	len_b = b.length();
	for (i = 1; i <= len_b; i++){
		ans[len_a - i] = a[len_a - i] - '0' + b[len_b - i] - '0' + carry;
		carry = ans[len_a - i] / 10;
		ans[len_a - i] %= 10;
		ans[len_a - i] += '0';
	}
	if (carry){
		if (len_a == len_b){
			ans = '1' + ans;
			carry = 0;
		}
		else{
			i = len_a - len_b - 1;
			while (carry && i >= 0){
				ans[i] += carry;
				carry = (ans[i] - '0') / 10;
				ans[i] = ans[i] > '9' ? ans[i] - 10 : ans[i];
				i--;
			}
			if (carry){
				ans = '1' + ans;
				carry = 0;
			}
		}
	}
	return ans.substr(ans.find_first_not_of("0") == string::npos ? ans.length() - 1 : ans.find_first_not_of("0"));
}

string mul(const string a, const string b){
	string a_cp = a.substr(a.find_first_not_of("0") == string::npos ? a.length() - 1 : a.find_first_not_of("0"));
	string b_cp = b.substr(b.find_first_not_of("0") == string::npos ? b.length() - 1 : b.find_first_not_of("0"));
	string ans = "0";
	for (int i = b_cp[0] - '0'; i > 0; i--){
		ans = add(ans, a_cp);
	}
	for (unsigned int i = 1; i < b_cp.length(); i++){
		ans += '0';
		for (int j = b_cp[i] - '0'; j >0; j--){
			ans = add(ans, a_cp);
		}
	}
	return ans;
}

string sub(const string a, const string b){
	string a_cp = a.substr(a.find_first_not_of("0") == string::npos ? a.length() - 1 : a.find_first_not_of("0"));
	string b_cp = b.substr(b.find_first_not_of("0") == string::npos ? b.length() - 1 : b.find_first_not_of("0"));

	if (a_cp.length() < b_cp.length()) return string('-' + sub(b_cp, a_cp));
	else if (a_cp.length() == b_cp.length()){
		if (a_cp.compare(b_cp) < 0) return string('-' + sub(b_cp, a_cp));
	}
	string ans = a_cp;
	int aptr = a_cp.length() -1, bptr = b_cp.length() -1, carry = 0;
	while (bptr >= 0 || (aptr >= 0 && carry)){
		if (bptr >= 0){
			if (ans[aptr] - carry >= b_cp[bptr]){
				ans[aptr] = ans[aptr] - carry - b_cp[bptr] + '0';
				carry = 0;
			}
			else{
				ans[aptr] = ans[aptr] + 10 - carry - b_cp[bptr] + '0';
				carry = 1;
			}
			aptr--;
			bptr--;
		}
		else{
			if (ans[aptr] - carry >= '0'){
				ans[aptr] = ans[aptr] - carry;
				carry = 0;
			}
			else{
				ans[aptr] = ans[aptr] + 10 - carry;
				carry = 1;
			}
			aptr--;
		}
	}
	return ans.substr(ans.find_first_not_of("0") == string::npos ? ans.length() - 1 : ans.find_first_not_of("0"));
}

string div(const string a, const string b){
	string a_cp = a.substr(a.find_first_not_of("0") == string::npos ? a.length() - 1 : a.find_first_not_of("0"));
	string b_cp = b.substr(b.find_first_not_of("0") == string::npos ? b.length() - 1 : b.find_first_not_of("0"));

	if (a_cp.length() < b_cp.length()) return string("0");
	else if (a_cp.length() == b_cp.length()){
		if (a_cp.compare(b_cp) < 0) return string("0");
	}

	string ans = "0";
	int ptr = 0, shift = 0;
	while (b_cp.length() < a_cp.length()){
		shift++;
		b_cp += '0';
	} 
	for (ptr; ptr <= shift; ptr++){
		ans += '0';
		while (a_cp.compare(b_cp) >= 0){
			a_cp = sub(a_cp, b_cp);
			while (a_cp.length() < b_cp.length()) a_cp = '0' + a_cp;
			ans = add(ans, "1");
		}
		b_cp = '0' + b_cp;
		a_cp += '0';
	}
	return ans.substr(ans.find_first_not_of("0") == string::npos ? ans.length() - 1 : ans.find_first_not_of("0"));
}

int main(){
	string sin, s1, s2;
	int found;
	while (getline(cin, sin)){
		found = sin.find_first_of(" ");
		s1 = sin.substr(0, found);
		s2 = sin.substr(sin.find_last_of(" ") + 1);
		switch (sin[found+1])
		{
		case '+':
			s1 = add(s1, s2);
			break;
		case '-':
			s1 = sub(s1, s2);
			break;
		case '*':
			s1 = mul(s1, s2);
			break;
		case '/':
			s1 = div(s1, s2);
			break;
		}
		cout << s1 << endl;
	}
}