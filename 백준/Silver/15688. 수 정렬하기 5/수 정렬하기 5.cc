#include <bits/stdc++.h>
using namespace std;

int main(){
	int t; cin >> t;
	vector<int> v;
	for(int i=0; i<t; i++){
		int num;
		scanf("%d", &num);
		v.push_back(num);
	}
	sort(v.begin(), v.end());
	for(int i=0; i<t; i++) printf("%d\n", v[i]);
	return 0;
}