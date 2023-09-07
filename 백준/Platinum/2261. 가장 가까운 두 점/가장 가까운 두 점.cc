#include <bits/stdc++.h>
#define pb push_back
#define mp make_pair
#define all(x) (x).begin(), (x).end()

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
const double PI = acos(-1);

vector<pii > v;

bool cmpx(pii a, pii b){
	return a.first < b.first;
}

bool cmpy(pii a, pii b){
	return a.second < b.second;
}

int d(pii a, pii b){
	return (a.first-b.first)*(a.first-b.first) + (a.second-b.second)*(a.second-b.second);
}

int findk(int from, int to){
	if((to-from)==2){ // 제귀 종료 기준. 
		return d(v[from],v[from+1]);
	}
	if((to-from)==3){ // 재귀 종료 기준 2. 
		return min({d(v[from],v[from+1]),d(v[from],v[from+2]),d(v[from+1],v[from+2])});
	}
	int mid=(from+to)/2, line = v[mid].first;
	int k=min(findk(from, mid), findk(mid, to)); // 재귀로 시간 줄이기(2,3개 일때만 거리 계산).
	vector<pii> s;
	for(int i=from; i<to; i++){ // x좌표가 기준에서 +,- k 인 좌표들만 담는다. 
		int t = line-v[i].first;
		if((t*t)<k) s.pb(v[i]);
	}
	sort(all(s),cmpy); // y로 정렬.
	
	int size = s.size();
	for(int i=0; i<size-1; i++){ // y좌표가 k미만으로 차이나는 것들만 거리 계산. 
		for(int j=i+1; j<size; j++){
			if((s[i].second-s[j].second)*(s[i].second-s[j].second)>=k) break;
			k=min(k,d(s[i],s[j]));
		}
	}
	return k;
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	int n; cin >> n;
	for(int i=0; i<n; i++){
		int x,y; cin >> x >> y;
		v.pb(mp(x,y));
	}
	sort(all(v),cmpx);
	cout << findk(0,n);
	return 0;
}
