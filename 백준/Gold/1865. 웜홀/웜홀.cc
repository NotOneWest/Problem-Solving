#include <bits/stdc++.h>
#define pb push_back
#define mp make_pair
#define all(x) (x).begin(), (x).end()

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
const double PI = acos(-1);

int INF=99999999;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
  int tc; cin >> tc;
  for(int c=0; c<tc; c++){
    int n,m,w,check=0; cin >> n >> m >> w;
    int dis[501];
    vector<pii > node[501];
    for(int i=1; i<=n; i++) node[i].clear();
    for(int i=0; i<m; i++){
      int s,e,t; cin >> s >> e >> t;
      node[s].pb(mp(e,t));
      node[e].pb(mp(s,t));
    }
    for(int i=0; i<w; i++){
      int s,e,t; cin >> s >> e >> t;
      node[s].pb(mp(e,-t));
    }
    for(int i=1; i<=n; i++) dis[i]=INF;
    dis[1]=0;
    for(int k=1; k<=n; k++){
      for(int i=1; i<=n; i++){
        for(int j=0; j<node[i].size(); j++){
          int next=node[i][j].first, cost=node[i][j].second;
          if(dis[next] > dis[i]+cost){
            dis[next]=(dis[i]+cost);
            if(k==n) check=1;
          }
        }
      }
    }
    if(check==1) cout << "YES" << '\n';
    else cout << "NO" << '\n';
  }
	return 0;
}
