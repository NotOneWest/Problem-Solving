#include <iostream>
#include <string>
#include <math.h>
using namespace std;


int main(){
	int n, i=1; cin>>n;
	string s;
	long long dp[8] = {9,};
	
	for(int t=1; t<8; t++){
		dp[t] = 9*(pow(10,t))*(t+1);	
	}
	
	int t=0, sum=0;
	while(t<7 && n>9){
		sum += dp[t];
		if(n>sum && n <= sum+dp[t+1]){
			n = n - sum;
			i = pow(10,t+1);
			break;
		}
		t++;
	}
	
	while(s.length() < n){
		s += to_string(i);
		i++;
	}
	printf("%d", s[n-1]-'0');
	return 0;
}