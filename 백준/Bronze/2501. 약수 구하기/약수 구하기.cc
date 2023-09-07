#include <bits/stdc++.h>
#define pb push_back
#define mp make_pair
#define all(x) (x).begin(), (x).end()

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
const double PI = acos(-1);

vector<int> v;

void solve(int n){
	int i=1;
	while(i*i<=n){
		if(n%i==0){
			v.pb(i);
			if(i*i!=n) v.pb(n/i);
		}
		i++;
	}
}

int main(){
	int n,k; cin >> n >> k;
	solve(n);
	if(v.size()<k) cout << 0;
	else{
		sort(all(v));
		cout << v[k-1];
	}
	return 0;
}