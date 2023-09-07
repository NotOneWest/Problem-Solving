#include <bits/stdc++.h>
#define pb push_back
#define mp make_pair
#define all(x) (x).begin(), (x).end()

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
const double PI = acos(-1);

vector<int> vertex[1001];
bool visitied[1001];

void dfs(int node){
  visitied[node]=true;
  for(int i=0; i<vertex[node].size(); i++){
    if(visitied[vertex[node][i]]==false){
      dfs(vertex[node][i]);
    }
  }
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
  int n,m,cnt=0; cin >> n >> m;
  for(int i=0; i<m; i++){
    int u,v; cin >> u >> v;
    vertex[u].pb(v);
    vertex[v].pb(u);
  }
  for(int i=1; i<(n+1); i++){
    if(visitied[i]==false){
      dfs(i);
      cnt++;
    }
  }
  cout << cnt << '\n';
	return 0;
}
