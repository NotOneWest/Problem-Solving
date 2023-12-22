#include <bits/stdc++.h>
using namespace std;

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	
	int n; cin >> n;
	vector<long long> v;
	
	for(int i=0; i<n; i++){
		string s; cin >> s;
		reverse(s.begin(), s.end());
		v.push_back(stoll(s));
	}
	sort(v.begin(), v.end());
	
	for(int i=0; i<n; i++) cout << v[i] << '\n';
	

	return 0;
}
