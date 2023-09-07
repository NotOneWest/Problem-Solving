#include <bits/stdc++.h>
#define pb push_back
#define mp make_pair
#define all(x) (x).begin(), (x).end()

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
const double PI = acos(-1);

ll gcd(ll a, ll b){
	if(a==0) return b;
	return gcd(b%a, a);
}

int main(){
	int t; cin >> t;
	for(int i=0; i<t; i++){
		ll n,sum=0; cin >> n;
		ll num[n]={0,};
		for(int j=0; j<n; j++) scanf("%lld", &num[j]);
		for(int j=0; j<n-1; j++){
			for(int k=j+1; k<n; k++){
				sum+=gcd(num[j],num[k]);
			}
		}	
		printf("%lld\n", sum);
	}
	return 0;
}
