#include <bits/stdc++.h>
using namespace std;

int main(){
	int a,b;
	cin >>a >>b;
	
	int result = a*b;
	
	for(int i=0; i<3; i++){
		printf("%d\n", a*(b%10));
		b = b/10;
	}
	
	printf("%d", result);
	return 0;
}