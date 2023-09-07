#include <cstdio>
#include <iostream>
using namespace std;

int main(){
	int a, b, c, x, y,sum1=0, sum2=0;
	scanf("%d %d %d %d %d", &a, &b, &c, &x, &y);
	
	sum1 = x*a + y*b;
	if(x>y) {
		sum2 = y*2*c + (x-y)*a < y*2*c + (x-y)*2*c ? y*2*c + (x-y)*a : y*2*c + (x-y)*2*c; 
	}
	else sum2 = x*2*c + (y-x)*b < x*2*c + (y-x)*2*c ? x*2*c + (y-x)*b : x*2*c + (y-x)*2*c; 
	
	if(sum1>sum2) printf("%d", sum2);
	else printf("%d", sum1);
	return 0;
}