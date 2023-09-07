#include <bits/stdc++.h>
#define pb push_back
#define mp make_pair
#define all(x) (x).begin(), (x).end()

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
const double PI = acos(-1);

int num[10001];

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	ll n; cin >> n;
	for(int i=0; i<n; i++){
		int k; cin >> k;
		num[k]++;
	}
	for(int i=1; i<10001; i++){
		for(int j=0; j<num[i]; j++) cout << i << '\n';
	}
	return 0;
}