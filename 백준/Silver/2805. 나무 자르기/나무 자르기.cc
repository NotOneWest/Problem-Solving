#include <bits/stdc++.h>
#define pb push_back
#define mp make_pair
#define all(x) (x).begin(), (x).end()

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
const double PI = acos(-1);

ll max_h=0;
vector<ll> v;

int main(){
	ll n,m; cin >> n >> m;
	for(int i=0; i<n; i++){
		int h; cin >> h;
		v.pb(h);
	}
	sort(v.rbegin(), v.rend());
	ll low=0, high=v[0];
	while(low<=high){
		ll mid=(low+high)/2, sum=0;
		for(int i=0; i<n; i++){
			if((v[i]-mid)>0){
				sum+=(v[i]-mid);
			}
		}
		if(sum>=m){
			if(max_h < mid) max_h=mid;
			low=mid+1;
		}
		else high=mid-1;
	}
	cout << max_h;
	return 0;
}