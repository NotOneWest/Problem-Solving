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
	
	for(ll i=1; i<45827; i++){
		if(n<(i*i)){
			cout << i-1;
			break;
		}
		else if(n==(i*i)){
			cout << i;
			break;
		}
	}
	return 0;
}