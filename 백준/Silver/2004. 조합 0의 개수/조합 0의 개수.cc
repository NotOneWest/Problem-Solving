#include <bits/stdc++.h>
#define pb push_back
#define mp make_pair
#define all(x) (x).begin(), (x).end()

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
const double PI = acos(-1);

ll nfind(ll n, ll k){
	int sum=0;
	while(n!=0){
		sum+=n/k;
		n=n/k;
	}
	return sum;
}

ll mfind(ll n, ll m, ll k){
	int sum=0;
	while(m!=0){
		sum+=m/k;
		m=m/k;
	}
	while(n!=0){
		sum+=n/k;
		n=n/k;
	}
	return sum;
}

int main(){
	ll n,m,two=0,five=0; cin >> n >> m;
	two=nfind(n,2)-mfind(n-m,m,2);
	five=nfind(n,5)-mfind(n-m,m,5);
	if(five<two) cout << five;
	else cout << two;
	return 0;
}