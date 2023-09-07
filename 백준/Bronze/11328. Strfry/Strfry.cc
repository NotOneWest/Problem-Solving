#include <bits/stdc++.h>
#define pb push_back
#define mp make_pair
#define all(x) (x).begin(), (x).end();

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
const double PI = acos(-1);

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	int n; cin >> n;
	for(int i=0; i<n; i++){
		char a[1001], b[1001]; cin >>a >>b;
		sort(a, a+strlen(a));
		sort(b,b+strlen(b));
		if(strcmp(a,b) == 0) cout << "Possible" << '\n';
		else cout << "Impossible" << '\n';
	}
	return 0;
}