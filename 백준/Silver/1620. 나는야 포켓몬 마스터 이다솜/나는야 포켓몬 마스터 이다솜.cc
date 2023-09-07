#include <bits/stdc++.h>
#define pb push_back
#define mp make_pair
#define all(x) (x).begin(), (x).end()

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
const double PI = acos(-1);

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
  int n,m; cin >> n >> m;
  map<string, int> dogam;
  vector<string> v;
  for(int i=1; i<=n; i++){
    string s; cin >> s;
    dogam.insert(pair<string, int>(s,i));
    v.pb(s);
  }
  for(int i=0; i<m; i++){
    string s; cin >> s;
    if(s[0]>'0' && s[0]<='9') cout << v[stoi(s)-1] << '\n';
    else cout << dogam[s] << '\n';
  }
	return 0;
}
