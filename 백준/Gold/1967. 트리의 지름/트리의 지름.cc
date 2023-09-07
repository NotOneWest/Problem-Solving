#include <bits/stdc++.h>
#define pb push_back
#define mp make_pair
#define all(x) (x).begin(), (x).end()

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
const double PI = acos(-1);

int n, maxdis, maxnode, visited[100001];
vector< pii > node[100001];

void dfs(int start, int dis){
  if(visited[start]==1) return;
  visited[start]=1;
  if(maxdis < dis){
    maxdis=dis;
    maxnode=start;
  }
  for(int i=0; i<node[start].size(); i++){
    if(visited[node[start][i].first]!=1){
      dfs(node[start][i].first, dis+node[start][i].second);
    }
  }
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
  cin >> n;
  for(int i=1; i<n; i++){
    int start, end, dis; cin >> start >> end >> dis;
    node[start].pb(mp(end, dis));
    node[end].pb(mp(start, dis));
  }
  dfs(1,0);
  maxdis=0;
  for(int i=1; i<=n; i++) visited[i]=0;
  dfs(maxnode,0);
  cout << maxdis << '\n';
	return 0;
}
