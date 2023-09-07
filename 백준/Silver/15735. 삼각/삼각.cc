#include <bits/stdc++.h>
#define pb push_back
#define mp make_pair
#define all(x) (x).begin(), (x).end()

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
const double PI = acos(-1);

int main(){
	ll n; cin >> n;
	ll sum=(n*(n+1)*(n+2))/6;
	if(n%2){
		for(int i=1; i<=(n/2); i++){
			for(int j=1; j<=(2*i); j++) sum+=j;
		}
	}
	else{
		for(int i=1; i<=(n/2); i++){
			for(int j=1; j<=(2*i-1); j++) sum+=j;
		}
	}
	cout << sum;
	return 0;
}