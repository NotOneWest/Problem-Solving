#include <bits/stdc++.h>
#define pb push_back
#define mp make_pair
#define all(x) (x).begin(), (x).end()

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
const double PI = acos(-1);

vector<pii> vertex[20001];
int dis[20001], inf=999999999;

void dijkstra(int start){
  dis[start]=0;
  priority_queue<pii> pq;
  pq.push(mp(0, start));
  while(!pq.empty()){
    int cur=pq.top().second, curdis=-pq.top().first;
    pq.pop();
    if(dis[cur]<curdis) continue;
    for(int i=0; i<vertex[cur].size(); i++){
      int next=vertex[cur][i].second, nextdis=vertex[cur][i].first+curdis;
      if(dis[next]>nextdis){
        dis[next]=nextdis;
        pq.push(mp(-nextdis, next));
      }
    }
  }
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
  int V,e,k; cin >> V >> e >> k;
  for(int i=0; i<e; i++){
    int u,v,w; cin >> u >> v >> w;
    vertex[u].pb(mp(w,v));
  }
  for(int i=0; i<=V; i++) dis[i]=inf;
  dijkstra(k);
  for(int i=1; i<=V; i++){
    if(dis[i]==inf) cout << "INF\n";
    else cout << dis[i] << '\n';
  }
	return 0;
}
