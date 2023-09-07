#include <bits/stdc++.h>
#define pb push_back
#define mp make_pair
#define all(x) (x).begin(), (x).end()

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
const double PI = acos(-1);

int gcd(int a, int b){
	if(a==0) return b;
	return gcd(b%a, a);
}

ll lcm(int a, int b){
	return (a*b)/gcd(a,b);
}

int main(){
	int num[5];
	vector<ll> v;
	for(int i=0; i<5; i++) scanf("%d", &num[i]);
	for(int i=0; i<3; i++){
		for(int j=i+1; j<4; j++){
			for(int k=j+1; k<5; k++) v.pb(lcm(lcm(num[i],num[j]),num[k]));
		}
	}
	sort(all(v));
	cout << v[0];
	return 0;
}