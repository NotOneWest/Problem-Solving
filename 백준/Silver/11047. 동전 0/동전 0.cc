#include <cstdio>
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(){
	int n; cin>>n;
	long long k, coins=0; cin>>k;
	
	int money[n];
	for(int i=0; i<n; i++) scanf("%d", &money[i]);
	
	for(int j=n-1; j>=0; j--){
		if(k >= money[j]){
			coins+=k/money[j];
			k = k%money[j];
		}
	}
	
	printf("%d", coins);
	return 0;
}