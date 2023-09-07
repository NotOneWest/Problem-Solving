#include <bits/stdc++.h>
#define pb push_back
#define mp make_pair
#define all(x) (x).begin(), (x).end()

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
const double PI = acos(-1);

int a[1000001];

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n, b, c; cin >> n;
	for(int i=0; i<n; i++) cin >> a[i];
	cin >> b >> c;
	
	ll ans=0;
	for(int i=0; i<n; i++){
		if(a[i] < b) ans++;
		else{
			ans += ((a[i]-b)/c + 1);
			if((a[i]-b)%c) ans++;
		}
	}
	cout << ans << '\n';
	return 0;
}