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
  int n,m; cin >> n >> m;
  for(int i=0; i<m; i++){
    int u,v,w; cin >> u >> v >> w;
    vertex[u].pb(mp(w,v));
  }
  int start, end; cin >> start >> end;
  for(int i=0; i<=20001; i++) dis[i]=inf;
  dijkstra(start);
  cout << dis[end] << '\n';
	return 0;
}
