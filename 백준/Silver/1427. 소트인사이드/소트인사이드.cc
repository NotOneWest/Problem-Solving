#include <cstdio>
#include <iostream>
#include <algorithm>
#include <string>
#include <cstdlib>
using namespace std;

int main(){
	string a; cin>>a;
	int len = a.size();
	int n = atoi(a.c_str());
	int num[len];
	for(int i=0; i<len; i++){
		num[i] = n%10;
		n=n/10;
	}
	sort(num, num+len);
	
	for(int i=0; i<len; i++) printf("%d", num[len-i-1]);
	return 0;
}