#include <bits/stdc++.h>
using namespace std;

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	int n, k; cin >> n >> k;
	vector<int> v;
	for(int i=0; i<n; i++){
		int num; cin >> num;
		v.push_back(num);
	}
	
	int len = (n+1), sum = v[0], start = 0, end = 1;
	
	while(1){
		if(start >= n || end > n) break;
		
		if(sum >= k){
			len = min(len, (end-start));
			sum -= v[start]; start++;
		} else{ sum += v[end]; end++; }
	}
	if(len > n) len = 0;
	cout << len << '\n';
	return 0;
}
