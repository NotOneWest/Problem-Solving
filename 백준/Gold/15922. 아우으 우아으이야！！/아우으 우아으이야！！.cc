#include <iostream>
#include <cstdio>
using namespace std;

int main(){
	long long n, sum=0; cin>>n;
	long long num[n*2];
	for(int i=0; i<n*2; i++) scanf("%lld", &num[i]);
	long long t=1;
	while(t<n*2-2){
		if(num[t] > num[t+1]){
			num[t+1] = num[t];
		}
		if(num[t] > num[t+2]){
			num[t+2] = num[t];
		}
		t+=2;
	}
	
	for(int i=0; i<n*2-1; i+=2){
		sum += num[i+1] - num[i];
	}
	
	printf("%lld", sum);
	return 0;
}