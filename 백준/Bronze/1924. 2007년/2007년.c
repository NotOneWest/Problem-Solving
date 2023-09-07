#include <stdio.h>
#include <string.h>

int main(){
	
	int x,y,n=0;
	scanf("%d %d", &x, &y);
	
	int days[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
	
	if(x==1){
		n = y%7;
	}
	else{
	
		for(int i=1; i<x; i++){
			n += days[i-1];
		}
		n += y;
		n = n%7;
	}
	
	if(n==0) printf("%s", "SUN");
	if(n==1) printf("%s", "MON");
	if(n==2) printf("%s", "TUE");
	if(n==3) printf("%s", "WED");
	if(n==4) printf("%s", "THU");
	if(n==5) printf("%s", "FRI");
	if(n==6) printf("%s", "SAT");
	
	return 0;
}