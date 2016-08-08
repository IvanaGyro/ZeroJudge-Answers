#include <iostream>
#include <iomanip>

using namespace std;

int main(){
	int a, b, c, d, e, f;
	float T, xT, yT;
	float x, y;
	cout << fixed << setprecision(2);
	while (cin >> a){
		cin >> b;
		cin >> c;
		cin >> d;
		cin >> e;
		cin >> f;
		T = b * d - a * e;
		xT = b * f - c * e;
		yT = c * d - a * f;
		if (T == 0){
			if (xT == 0 || yT == 0){
				cout << "Too many" << endl;
			}
			else cout << "No answer" << endl;
		}
		else{
			x = xT / T;
			y = yT / T;
			cout << "x=" << x << endl;
			cout << "y=" << y << endl;
		}
	}
}