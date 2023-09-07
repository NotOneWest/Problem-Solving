#include <bits/stdc++.h>
using namespace std;

int main(){
	int a,b;
	cin>>a >>b;
	
	int hour, min, sum=a*60+b-45;
	
	if(a==0 && b<45){
		hour = 23;
		min = 60-45+b;
	}
	else{
		hour = sum/60;
		min = sum%60;
	}
	printf("%d %d", hour, min);
	return 0;
}