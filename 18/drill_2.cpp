#include <iostream>
#include <vector>

using namespace std;

vector<int> gv = {1,2,4,8,16,32,64,128,256,512};

void f(vector<int> arg) {
	vector<int> lv(arg);
	
	cout << "lv: ";
	for(int i = 0; i < lv.size(); ++i) {
		lv[i] = arg[i];
		cout << lv[i] << " ";
	}
	cout << endl;

	vector<int>lv2 = arg;
	cout << "lv2: ";
	for(int i = 0; i < lv.size(); ++i) {
		cout << lv2[i] << " ";
	}
	cout << endl;
}

int main() {
	f(gv);
	vector<int> vv = {1,2,4,8,16,32,64,128,256,512};
	f(vv);
}