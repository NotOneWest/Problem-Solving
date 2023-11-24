#include <bits/stdc++.h>
using namespace std;

int ccw(pair<int, int> a, pair<int, int> b, pair<int, int> c){
	long long val = (a.first * b.second + b.first * c.second + c.first * a.second);
	val -= (a.second * b.first + b.second * c.first + c.second * a.first);
	if(val < 0) return -1;
	else if(val > 0) return 1;
	else return 0;
}

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	
	vector<pair<int, int> > dot(3);
	for(int i=0; i<3; i++){
		int x, y; cin >> x >> y;
		dot[i] = make_pair(x, y);
	}
	
	cout << ccw(dot[0], dot[1], dot[2]) << '\n';
	
	return 0;
}
