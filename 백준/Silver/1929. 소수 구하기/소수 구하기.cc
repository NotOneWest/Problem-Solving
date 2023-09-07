#include <bits/stdc++.h>
#define pb push_back
#define mp make_pair
#define all(x) (x).begin(), (x).end()

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
const double PI = acos(-1);

vector<int> sosu(int n){
	vector<int> res;
	vector<bool> check(n+1,true);
	check[1]=false;
	for(ll i=2; i<=n; i++){
		if(!check[i]) continue;
		for(ll j=i*i; j<=n; j+=i){
			check[j]=false;
		}
	}
	for(int i=1; i<=n; i++){
		if(check[i]) res.pb(i);
	}
	return res;
}


int main(){
	int m,n; cin >> m >> n;
	vector<int> num;
	num = sosu(n);
	for(auto i : num){
		if(i>=m) cout << i << '\n';
	}
	return 0;
}
