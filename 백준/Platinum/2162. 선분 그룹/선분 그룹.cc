#include <bits/stdc++.h>
using namespace std;

int parent[3001];

int ccw(pair<long long, long long> a, pair<long long, long long> b, pair<long long, long long> c){
	long long val = (a.first * b.second + b.first * c.second + c.first * a.second);
	val -= (a.second * b.first + b.second * c.first + c.second * a.first);
	if(val < 0) return -1;
	else if(val > 0) return 1;
	else return 0;
}

bool isCross(vector<pair<long long, long long> > v, vector<pair<long long, long long> > v2){
	int d1, d2, d3, d4;
	
	d1 = ccw(v[0], v2[0], v2[1]);
	d2 = ccw(v[1], v2[0], v2[1]);
	d3 = ccw(v[0], v[1], v2[0]);
	d4 = ccw(v[0], v[1], v2[1]);
	
	if(d1*d2 <= 0 && d3*d4 <= 0){
		if(d1*d2 == 0 && d3*d4 == 0){
			if(v[0] > v[1]) swap(v[0], v[1]);
			if(v2[0] > v2[1]) swap(v2[0], v2[1]);
			return (v[0] <= v2[1] && v[1] >= v2[0]);
		} else return true;
	} else return false;
}

int find(int x) {
	if (parent[x] == x) return x;
	return parent[x] = find(parent[x]);
}

void merge(int x, int y) {
	x = find(x);
	y = find(y);
	
	if (x == y) return;
	
	if(x < y) parent[y] = x;
	else parent[x] = y;
}

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	
	int n; cin >> n;
	vector<vector<pair<long long, long long> > > line(n);
	for(int i=0; i<n; i++){
		long long x1, y1, x2, y2; cin >> x1 >> y1 >> x2 >> y2;
		line[i].push_back(make_pair(x1, y1));
		line[i].push_back(make_pair(x2, y2));
		parent[i] = i;
	}
	
	for(int i=0; i<(n-1); i++){
		for(int j=(i+1); j<n; j++){
			if(isCross(line[i], line[j])) merge(i, j);
		}
	}
	
	vector<int> cnt(n+1, 0);
	// parent[i]가 아닌 find(i)로 최종으로 부모를 찾아야 함... 최종적으로 그룹 판별 
	for(int i=0; i<n; i++) cnt[find(i)]++;
	
	int len = 0, MAX = 0;
	for(int i=0; i<=n; i++){
		len += (cnt[i] > 0);
		MAX = max(MAX, cnt[i]);
	}
	
	cout << len << "\n" << MAX << '\n';
	
	return 0;
}