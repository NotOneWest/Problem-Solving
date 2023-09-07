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
  map<string, string> site_pw;
  for(int i=0; i<n; i++){
    string site, pw; cin >> site >> pw;
    site_pw.insert(mp(site,pw));
  }
  for(int i=0; i<m; i++){
    string find_site; cin >> find_site;
    cout << site_pw[find_site] << '\n';
  }
	return 0;
}
