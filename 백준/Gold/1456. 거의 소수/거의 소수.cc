#include <bits/stdc++.h>
#define pb push_back
#define mp make_pair
#define all(x) (x).begin(), (x).end()

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
const double PI = acos(-1);

const ll mod = 10000001;
vector<ll> sosu;

void find_sosu(){
	vector<bool> check(mod,true);
	check[1]=false;
	for(ll i=2; i*i<=mod; i++){
		if(!check[i]) continue;
		for(ll j=i*i; j<=mod; j+=i) check[j]=false;
	}
	for(ll i=2; i<mod; i++){
		if(check[i]) sosu.pb(i);
	}
}

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	ll a,b,sum=0; cin >> a >> b;
	find_sosu();
	for(ll i=0; i<sosu.size(); i++){
		ll num = sosu[i];
		while(sosu[i]<=b/num){ 
			if(num*sosu[i]>=a) sum++;
			num*=sosu[i];
		}
	}
	cout << sum;
	return 0;
}