#include <bits/stdc++.h>
#define pb push_back
#define mp make_pair
#define all(x) (x).begin(), (x).end()

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
const double PI = acos(-1);

int v, maxdis, maxnode, visited[100001];
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
  cin >> v;
  for(int i=0; i<v; i++){
    int x; cin >> x;
    while(true){
      int num,dis; cin >> num;
      if(num!=-1){
        cin >> dis;
        node[x].pb(mp(num,dis));
      } else break;
    }
  }
  dfs(1,0);
  maxdis=0;
  for(int i=1; i<=v; i++) visited[i]=0;
  dfs(maxnode,0);
  cout << maxdis << '\n';
	return 0;
}
