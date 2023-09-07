#include <bits/stdc++.h>
#define pb push_back
#define mp make_pair
#define all(x) (x).begin(), (x).end()

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
const double PI = acos(-1);

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	int t; cin >> t;
	for(int i=0; i<t; i++){
		int n,m; cin >> n >>m;
		int leg = m*2;
		cout<< leg-n << ' ' << m-(leg-n) << '\n';
	}
	return 0;
}
