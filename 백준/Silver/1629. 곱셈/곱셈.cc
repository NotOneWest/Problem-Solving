#include <bits/stdc++.h>
#define pb push_back
#define mp make_pair
#define all(x) (x).begin(), (x).end()

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
const double PI = acos(-1);

ll rest(ll a, ll b, ll c){
	if(b==0) return 1;
	ll val = rest(a, b/2, c);
	val = val*val%c; // (a+b)%c = (a%c+b%c)%c
	if(b%2==0) return val;
	else return val*a%c;
}

int main(){
	ll A, B, C; cin >> A >> B >> C;
	cout << rest(A,B,C);
	return 0;
}
// c**n -> n is even : c**(n/2) * c**(n/2)
//      -> n is odd : ( c**((n-1)/2) * c**((n-1)/2) ) * c                            