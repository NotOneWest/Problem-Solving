#include <iostream>
#include <cstdio>
using namespace std;

int main(){
	
	string n; cin>>n;
	int step=0;
	
	string copy;
	
	if(n.length() < 2) n = '0' + n;
	copy = n;
	
	while(copy != n || step < 1){
		char prev = copy[1];
		int sum = copy[0] + copy[1] -96;
		if(sum >= 10) copy[1] = sum%10 + 48;
		else copy[1] = sum +48;
		copy[0] = prev;
		step++;
	}
	printf("%d", step);
	return 0;
}