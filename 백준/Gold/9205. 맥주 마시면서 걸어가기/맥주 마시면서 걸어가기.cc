#include <bits/stdc++.h>

using namespace std;

int t, n, visited[101];
vector<pair<int, int> > store;
pair<int, int> home, festival;
bool flag = false;

int cal(pair<int, int> a, pair<int, int> b){
	return (abs(a.first - b.first) + abs(a.second - b.second));
}

void simulation(pair<int, int> loc){
	if(cal(loc, festival) <= 1000) flag = true;
	
	for(int i=0; i<n; i++){
		if(visited[i] == 0 && cal(loc, store[i]) <= 1000){
			visited[i] = 1;
			simulation(store[i]);
		}
	}
}

int main(){
	cin >> t;
	for(int c=0; c<t; c++){
		cin >> n;
		store.clear();
		fill_n(visited, 101, 0);
		
		int x, y; cin >> x >> y;
		home = make_pair(x, y);
		for(int i=0; i<n; i++){
			cin >> x >> y;
			store.push_back(make_pair(x, y));
		}
		cin >> x >> y;
		festival = make_pair(x, y);
		sort(store.begin(), store.end());
		
		simulation(home);
		if(flag) cout << "happy\n";
		else cout << "sad\n";
		
		flag=false;
	}
	return 0;
}