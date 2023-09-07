#include <bits/stdc++.h>
#define pb push_back
#define mp make_pair
#define all(x) (x).begin(), (x).end()

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
const double PI = acos(-1);

int n,parent[100001]={0,},visited[100001]={0,};
vector<int> node[100001];

void dfs(int root){
  for(int i=0; i<node[root].size(); i++){
    if(visited[node[root][i]]==0){
      visited[node[root][i]]=1;
      parent[node[root][i]]=root;
      dfs(node[root][i]);
    }
  }
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
  cin >> n;
  for(int i=1; i<n; i++){
    int x,y; cin >> x >> y;
    node[x].pb(y);
    node[y].pb(x);
  }
  dfs(1);
  for(int i=2; i<=n; i++){
    cout << parent[i] << '\n';
  }
	return 0;
}
