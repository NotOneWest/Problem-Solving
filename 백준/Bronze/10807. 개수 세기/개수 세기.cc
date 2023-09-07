#include <bits/stdc++.h>
using namespace std;

int main(){
	int n; cin >> n;
	int num[n], v, cnt=0;
	for(int i=0; i<n; i++) scanf("%d", &num[i]);
	cin >> v;
	sort(num, num+n);
	for(int i=0; i<n; i++){
		if(num[i] == v) cnt++;
	}
	printf("%d", cnt);
	return 0;
}