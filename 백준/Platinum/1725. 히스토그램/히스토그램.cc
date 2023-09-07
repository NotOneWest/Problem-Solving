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
  stack<pair<ll,ll> > st;
  ll ans=0;
  for(int i=0; i<n; i++){
    ll h; cin >> h;
    int cur=i;
    while(!st.empty() && st.top().first>=h){ // 가장 높은 높이를 ans에 저장하는 과정
      ans=max(ans, (i-st.top().second)*st.top().first);
      cur=st.top().second;
      st.pop();
    }
    st.push(mp(h,cur));
  }
  while(!st.empty()){ // 가장 큰 사각형 찾는 과정 ---> 가장 길게 연속되는 사각형 넓이 계산
    ans=max(ans, (n-st.top().second)*st.top().first);
    st.pop();
  }
  cout << ans << '\n';
	return 0;
}
