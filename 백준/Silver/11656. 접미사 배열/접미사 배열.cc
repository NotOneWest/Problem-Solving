#include <iostream>
#include <cstdio>
#include <string>
#include <algorithm>
#include <vector>
using namespace std;

int main(){
	string a;
	cin >> a;
	vector<string> v;
	for(int i=0; i<a.size(); i++){
		string b = a.substr(i);
		v.push_back(b);
	}
	sort(v.begin(), v.end());
	for(int i=0; i<a.size(); i++) printf("%s\n", v[i].c_str());
	return 0;
}