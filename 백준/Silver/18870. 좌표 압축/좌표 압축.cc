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
  int n; cin >> n;
  vector<pii> index;
  vector<int> v;
  for(int i=0; i<n; i++){
    int x; cin >> x;
    index.pb(pii(x,i));
    v.pb(x);
  }
  sort(all(index));
  sort(all(v));
  v.erase(unique(all(v)), v.end());
  int ans[n];
  int prev=index[0].first, rank=0;
  ans[index[0].second]=0;
  for(int i=1; i<n; i++){
    if(index[i].first==prev) ans[index[i].second]=rank;
    else{
      rank++;
      prev=index[i].first;
      ans[index[i].second]=rank;
    }
  }
  for(int i=0; i<n; i++){
    cout << ans[i] << ' ';
  }
  cout << '\n';
	return 0;
}
