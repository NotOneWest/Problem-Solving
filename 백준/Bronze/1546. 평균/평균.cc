#include <bits/stdc++.h>
using namespace std;

int main(){
	int n; cin >> n;
	double avg, num[n];
	for(int i=0; i<n; i++){
		double a; cin >> a;
		num[i] = a;
	}
	sort(num, num+n);
	for(int i=0; i<n; i++) num[i] = (num[i]/num[n-1])*100;
	for(int i=0; i<n; i++) avg += num[i];
	
	printf("%f", avg/n);
	return 0;
}