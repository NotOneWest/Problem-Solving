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
	int n; cin >> n;
	set<pair<int, string> > s;
	for(int i=0; i<n; i++){
		string str; cin >> str;
		s.insert(mp(str.length(), str));
	}
	for(auto i : s) cout << i.second << '\n';
	return 0;
}
