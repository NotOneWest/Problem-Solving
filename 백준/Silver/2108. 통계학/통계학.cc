#include <bits/stdc++.h>
#define pb push_back
#define mp make_pair
#define all(x) (x).begin(), (x).end()

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
const double PI = acos(-1);

bool compare(pair<int, int> &a, pair<int, int> &b){
	if(a.first == b.first) return a.second < b.second;
	return a.first > b.first;
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
  int n,num[500001]; cin >> n;
  for(int i=0; i<n; i++) cin >> num[i];
  sort(num, num+n);
  double avg1, avg2=num[n/2], avg3, avg4=(num[n-1]-num[0]);
  for(int i=0; i<n; i++) avg1+=num[i];
  vector<pii> v;
  v.pb(mp(1,num[0]));
  for(int i=1; i<n; i++){
    if(v.back().second==num[i]) v.back().first++;
    else v.pb(mp(1,num[i]));
  }
  sort(all(v),compare);
  if(v[0].first==v[1].first) avg3=v[1].second;
  else avg3=v[0].second;
  if(round(avg1/n)==(-0)) cout << 0 << '\n';
  else cout << round(avg1/n) << "\n";
  cout << round(avg2) << "\n";
  cout << round(avg3) << "\n";
  cout << round(avg4) << "\n";
	return 0;
}
