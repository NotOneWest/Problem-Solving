#include <iostream>
#include <cstdio>
#include <string>
using namespace std;

int main(){
	long long a,b,check=0, call=0;
	cin>>a >>b;
	
	while( (b%10==1 || b%2==0) && b>1){
		if(a == b){
			printf("%lld", check + 1);
			call = 1;
			break;
		}
		else{
			check ++;
			if(b%2==0) b = b/2;
			else b = b/10;
		}
	}
	if(call != 1 && a==b) printf("%lld", check+1);
	if(a!=b) printf("-1");
	
	return 0;
}