#include <bits/stdc++.h>
#define pb push_back
#define mp make_pair
#define all(x) (x).begin(), (x).end()

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
const double PI = acos(-1);

int main(){
	int n, k; cin >> n >> k;
	vector< pair< pii, pii > > v;
	pair< pii, pii > key;
	for(int i=0; i<n; i++){
		int nara, g, s, d; cin >> nara >> g >> s >> d;
		if(nara == k) key=mp(mp(g, s), mp(d, nara));
		v.pb(mp(mp(g, s), mp(d, nara)));
	}
	sort(all(v));
	for(int i=0; i<n; i++){
		if(v[i].second.second == k){
			printf("%d" ,n-i);
			break;
		}
	}
	return 0;
}
