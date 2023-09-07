#include <bits/stdc++.h>
#define pb push_back
#define mp make_pair
#define all(x) (x).begin(), (x).end()

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
const double PI = acos(-1);

int main(){
	int t; cin >> t;
	for(int i=0; i<t; i++){
		int n; cin >> n;
		vector<string> v;
		for(int j=0; j<n; j++){
			string s; cin >> s;
			v.pb(s);
		}
		sort(all(v));
		bool check=true;
		for(int j=1; j<n; j++){
			if(v[j-1] == v[j].substr(0,v[j-1].size())){
				check=false;
				break;
			}
		}
		if(check) cout << "YES\n";
		else cout << "NO\n";
	}
	return 0;
}