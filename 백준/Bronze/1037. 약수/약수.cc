#include <bits/stdc++.h>
using namespace std;

int main(){
	int t; cin >> t;
	int num[t], n;
	for(int i=0; i<t; i++) scanf("%d", &num[i]);
	sort(num, num+t);
	n = num[0]*num[t-1];
	printf("%d", n);
	return 0;	
}