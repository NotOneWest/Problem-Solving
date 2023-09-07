#include <cstdio>
#include <algorithm>
using namespace std;

int main(){
	int n,m;
	scanf("%d:%d", &n, &m);
	
	int a,b;
	if(n>=m){
		a=n;
		b=m;
	}
	else{
		a=m;
		b=n;
	}
	while(b!=0){
		int n=a%b;
		a=b;
		b=n;
	}
	
	printf("%d:%d", n/a, m/a);
	return 0;
}