#include <bits/stdc++.h>
#define pb push_back
#define mp make_pair
#define all(x) (x).begin(), (x).end()

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
const double PI = acos(-1);

int n, cnt=0, ans=0;
vector<pii> v;

void func(int idx){
  if(idx==n){ // 모든 경우 end
    ans=max(ans, cnt);
    return;
  }
  if(v[idx].first<=0 || cnt==(n-1)){  // 이미 계란 깨졌을때 or 계란 1개 빼고 다 깨졌을때
    func(idx+1);
    return;
  }
  for(int i=0; i<n; i++){
    if(idx==i || v[i].first<=0) continue; // 내구도가 0일떄 안한는게 아니고 0보다 작으면 꺠진거라는걸 헷갈림...
    v[idx].first-=v[i].second;
    v[i].first-=v[idx].second;
    if(v[idx].first<=0) cnt++;
    if(v[i].first<=0) cnt++;
    func(idx+1);
    //초기화
    if(v[idx].first<=0) cnt--;
    if(v[i].first<=0) cnt--;
    v[idx].first+=v[i].second;
    v[i].first+=v[idx].second;
  }
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
  cin >> n;
  for(int i=0; i<n; i++){
    int d,w; cin >> d >> w;
    v.pb(mp(d,w));
  }
  func(0);
  cout << ans << '\n';
	return 0;
}
