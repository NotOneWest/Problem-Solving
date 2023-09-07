#include <bits/stdc++.h>
#define pb push_back
#define mp make_pair
#define all(x) (x).begin(), (x).end()

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
const double PI = acos(-1);

vector<pii> v;

bool compare(pii a, pii b) {
  if(a.second==b.second){
    return a.first < b.first;
  }
  return a.second < b.second;
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n; cin >> n;
	for(int i=0; i<n; i++){
		int start,end; cin >> start >> end;
		v.pb(pii(start,end));
	}
  sort(all(v),compare);
  int cnt=1, prev_endtime=v[0].second;
  for(int i=1; i<n; i++){
    if(v[i].first>=prev_endtime){
      prev_endtime=v[i].second;
      cnt++;
    }
	}
  cout << cnt << '\n';
	return 0;
}
