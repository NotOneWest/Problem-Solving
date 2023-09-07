#include <iostream>
#include <cstdio>
#include <string>
#include <algorithm>
using namespace std;

int main(){
	string n; cin>>n;
	string s;
	for(int i=0; i<n.length(); i++) s += '1';
	int sum = n.length();
	if(n<s) sum--;
	if(atoi(n.c_str()) == 0) sum = 1;
	printf("%d", sum);
	return 0;
}
