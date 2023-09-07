#include <bits/stdc++.h>
#define pb push_back
#define mp make_pair
#define all(x) (x).begin(), (x).end()

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
const double PI = acos(-1);

vector<int> v[101];
bool visited[101];
int cnt=0;

void dfs(int node){
  visited[node]=true;
  for(int i=0; i<v[node].size(); i++){
    if(!visited[v[node][i]]){
      cnt++;
      dfs(v[node][i]);
    }
  }
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
  int pc_num, graphs; cin >> pc_num >> graphs;
  for(int i=0; i<graphs; i++){
    int x,y; cin >> x >> y;
    v[x].pb(y);
    v[y].pb(x);
  }
  dfs(1);
  cout << cnt << '\n';
	return 0;
}
