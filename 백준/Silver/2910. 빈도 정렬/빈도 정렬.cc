#include <bits/stdc++.h>
using namespace std;

bool comp(pair<int, int> a, pair<int, int> b){ return a.first > b.first; }

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	
	int n, c; cin >> n >> c;
	vector<pair<int, int>> v;
	
	for(int i=0; i<n; i++){
		int num; cin >> num;
		
		bool flag = false;
		for(int j=0; j<v.size(); j++){
			if(v[j].second == num){
				v[j].first++;
				flag = true;
				break;
			}
		}
		if(!flag) v.push_back(make_pair(1, num));
	}
	
	stable_sort(v.begin(), v.end(), comp);
	
	for(auto i : v){
		while (i.first--) cout << i.second << ' ';
	}

	return 0;
}
