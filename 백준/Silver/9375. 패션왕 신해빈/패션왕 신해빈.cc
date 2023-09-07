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
  int t; cin >> t;
  for(int j=0; j<t; j++){
    int n, result=1; cin >> n;
    map<string, int> m;
    vector<string> v;
    for(int i=0; i<n; i++){
      string name, kind; cin >> name >> kind;
      if(m.find(kind)==m.end()){
        m.insert(mp(kind,1));
        v.pb(kind);
      }
      else m[kind]++;
    }
    for(int i=0; i<v.size(); i++){
      result*=(m[v[i]]+1);
    }
    cout << (result-1) << '\n';
  }
	return 0;
}
