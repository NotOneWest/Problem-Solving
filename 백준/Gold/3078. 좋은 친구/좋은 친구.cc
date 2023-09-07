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
  int n,k; cin >> n >> k;
  queue<int> q[21];
  ll ans=0;
  for(int i=0; i<n; i++){
    string name; cin >> name;
    int len=name.length();
    while(!q[len].empty() && (i-q[len].front())>k) q[len].pop();
    ans+=q[len].size();
    // 큐에 남은 사람은 각 등수에 해당하는 사람과 친구인데 while 안에 넣어서 계산하려 했음...->등수 차이가 날떄만 계산되어 오류
    q[len].push(i);
  }
  cout << ans << '\n';
	return 0;
}
