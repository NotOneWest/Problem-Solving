#include <bits/stdc++.h>
using namespace std;

int ccw(pair<long long, long long> a, pair<long long, long long> b, pair<long long, long long> c){
	long long val = (a.first * b.second + b.first * c.second + c.first * a.second);
	val -= (a.second * b.first + b.second * c.first + c.second * a.first);
	if(val < 0) return -1;
	else if(val > 0) return 1;
	else return 0;
}

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	
	vector<pair<long long, long long> > dot(4);
	for(int i=0; i<4; i++){
		long long x, y; cin >> x >> y;
		dot[i] = make_pair(x, y);
	}
	
	int d1, d2, d3, d4;
	
	d1 = ccw(dot[0], dot[2], dot[3]);
	d2 = ccw(dot[1], dot[2], dot[3]);
	d3 = ccw(dot[0], dot[1], dot[2]);
	d4 = ccw(dot[0], dot[1], dot[3]);
	
	cout << (d1*d2 < 0 && d3*d4 < 0) << "\n";
	
	return 0;
}
