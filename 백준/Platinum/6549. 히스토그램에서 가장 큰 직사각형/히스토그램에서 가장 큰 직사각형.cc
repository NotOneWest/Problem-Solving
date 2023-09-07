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
  while(true){
    ll n; cin >> n;
    if(n==0) break;
    stack<pair<ll,ll> > s;
    ll ans=0;
    for(ll i=0; i<n; i++){
      ll h; cin >> h;
      int cur=i; // 최대 넓이는 (총 가로 길이 * 최소 높이) or (일정 높이가 가장 연속 된 사각형 넓이) or (가장 큰 높이)
      while(!s.empty() && s.top().first>=h){
        ans=max(ans, (i-s.top().second)*s.top().first); // 일정 높이가 가장 길게 연속 된 넓이 찾기
        // pop을 한 사각형은 이미 다음 top 보다 높이가 높기 때문에 위치를 저장해 놓으면 가로 길이를 알 수 있음.
        cur=s.top().second;
        s.pop(); // 최소 높이만 높이 값으로 stack에 들어가도록 pop
      }
      s.push(mp(h,cur));
    }
    while(!s.empty()){ // 비교가 한번도 안되었다면 가장 큰 높이가 최대 높이가 됨 or 마지막으로 연속 된 사각형 찾기.
      ans=max(ans, (n-s.top().second)*s.top().first);
      s.pop();
    }
    cout << ans << '\n';
  }
	return 0;
}
