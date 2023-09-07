#include <cstdio>
#include <string>
#include <iostream>
using namespace std;

int main(){
	
	int n;
	scanf("%d", &n);
	
	for(int i=0; i<n; i++){
		int len;
		scanf("%d", &len);
		string a = "";
		for(int j=0; j<len; j++){
			string b; cin >> b;
			if( a > b) a = b + a;
			else a += b;	
		}
		printf("%s\n", a.c_str());
	}
	return 0;
}