#include <bits/stdc++.h>
using namespace std;

int main(){
	
	int t;
	cin >> t;
	for(int i=0; i<t; i++){
		int a,b;
		cin >>a >>b;
		printf("Case #%d: %d + %d = %d\n", i+1, a, b, a+b);
	}
	return 0;
}