#include <bits/stdc++.h>
using namespace std;

int main(){
	int n, k; cin >> n >> k;
	vector<int> v;
	for(int i=1; i<=k; i++){
		string s = to_string(n*i);
		reverse( s.begin(), s.end());
		v.push_back(atoi(s.c_str()));
	}
	sort(v.begin(), v.end());
	printf("%d", v[v.size()-1]);
	return 0;
}