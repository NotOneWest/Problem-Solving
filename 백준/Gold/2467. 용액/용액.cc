#include <bits/stdc++.h>
using namespace std;

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	int n; cin >> n;
	vector<int> v;
	for(int i=0; i<n; i++){
		int val; cin >> val;
		v.push_back(val);
	}
	
	int MIN = 2000000001;
	pair<int, int> ans;
	int start = 0, end = n-1;
	while(start < end){
		int value = v[start] + v[end];
		if(MIN > abs(value)){
			MIN = abs(value);
			ans = make_pair(start, end);
		}
		if(value < 0) start++;
		else end--;
	}
	
	cout << v[ans.first] << " " << v[ans.second] << '\n';
	return 0;
}
