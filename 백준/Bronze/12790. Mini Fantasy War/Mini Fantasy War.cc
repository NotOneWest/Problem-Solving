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
		int h,m,a,d,hu,mu,au,du; cin >> h >> m >> a >> d >> hu >> mu >> au >> du;
		if(h+hu < 1){
			h=1;
			hu=0;
		}
		if(m+mu < 1){
			m=1;
			mu=0;
		}
		if(a+au < 0){
			a=0;
			au=0;
		}
		cout << (h+hu)+(m+mu)*5+(a+au+d+du)*2 << '\n';
	}
	return 0;
}
