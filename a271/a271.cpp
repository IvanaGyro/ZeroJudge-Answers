#include <iostream>
#include <string>

using namespace std;

int main(){
	int N;
	int x, y, z, w, n, m;
	int poison;
	bool dead;
	string input;
	while (cin >> N){
		while (N--){
			cin >> x;
			cin >> y;
			cin >> z;
			cin >> w;
			cin >> n;
			cin >> m;
			poison = 0;
			dead = false;
			getchar();
			getline(cin, input);
			for (string::iterator siter = input.begin(); siter != input.end(); ++siter){
				if (*siter >= '0' && *siter <= '4'){
					if ((m -= poison) <= 0){
						dead = true;
						break;
					} 
					switch (*siter){
					case '1':
						m += x;
						break;
					case '2':
						m += y;
						break;
					case '3':
						m -= z;
						break;
					case '4':
						m -= w;
						poison += n;
						break;
					}
					if (m < 0){
						dead = true;
						break;
					}
				}
			}
			if (dead) cout << "bye~Rabbit" << endl;
			else cout << m << "g" << endl;
		}
	}
}