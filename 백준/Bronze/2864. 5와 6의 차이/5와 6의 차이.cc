#include <cstdio>
#include <algorithm>
#include <cstring>
#include <iostream>
using namespace std;

int main(){
	string a, b;
	cin>>a; cin>>b;
	
	int min=0, max=0;
	for(int t=0; t<a.length(); t++){
		if(a[t] == '5') a[t] = '6';
	}
	max += atoi(a.c_str());
	for(int t=0; t<a.length(); t++){
		if(a[t] == '6') a[t] = '5';
	}
	min += atoi(a.c_str());
	for(int k=0; k<b.length(); k++){
		if(b[k] == '5') b[k] = '6';
	}
	max += atoi(b.c_str());
	for(int k=0; k<b.length(); k++){
		if(b[k] == '6') b[k] = '5';
	}
	min += atoi(b.c_str());
	
	printf("%d %d", min, max);
	return 0;
}