#include <bits/stdc++.h>
using namespace std;

int ccw(pair<long long, long long> a, pair<long long, long long> b, pair<long long, long long> c){
	long long val = (a.first * b.second + b.first * c.second + c.first * a.second);
	val -= (a.second * b.first + b.second * c.first + c.second * a.first);
	if(val < 0) return -1;
	else if(val > 0) return 1;
	else return 0;
}

void loc(vector<pair<long long, long long> > dot){
	long double px = (dot[0].second * dot[1].first - dot[0].first * dot[1].second) * (dot[2].second - dot[3].second) - (dot[0].second - dot[1].second) * (dot[2].second * dot[3].first - dot[2].first * dot[3].second);
	long double py = (dot[0].second * dot[1].first - dot[0].first * dot[1].second) * (dot[2].first - dot[3].first) - (dot[0].first - dot[1].first) * (dot[2].second * dot[3].first - dot[2].first * dot[3].second);
	long double p = (dot[0].second - dot[1].second) * (dot[2].first - dot[3].first) - (dot[0].first - dot[1].first) * (dot[2].second - dot[3].second);
	
	if(p == 0){ // 일직선 끝 점끼리 교차 
		if(dot[1] == dot[2]) cout << dot[1].first << " "  << dot[1].second << '\n';
		else if(dot[0] == dot[3]) cout << dot[0].first << " " << dot[0].second << '\n';
	} else{ // X 모양 교차 or V 모양 교차 
		long double x = px / p; 
		long double y = py / p;
		
		cout << fixed;
		cout.precision(9);
		cout << y << " " << x;
	}
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
	
	if(d1*d2 <= 0 && d3*d4 <= 0){
		if(d1*d2 == 0 && d3*d4 == 0){
			if(dot[0] > dot[1]) swap(dot[0], dot[1]);
			if(dot[2] > dot[3]) swap(dot[2], dot[3]);
			if((dot[0] <= dot[3] && dot[1] >= dot[2])){ cout << "1\n"; loc(dot); } 
			else  cout << "0\n";
		} else{ cout << "1\n"; loc(dot); }
	} else  cout << "0\n";
	
	return 0;
}