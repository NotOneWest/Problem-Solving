#include <bits/stdc++.h>
#define pb push_back
#define mp make_pair
#define all(x) (x).begin(), (x).end()

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
const double PI = acos(-1);

vector<int> vertex[1001];
bool dfs_visitied[1001], bfs_visitied[1001];

void dfs(int node){
	cout << node << ' ';
	dfs_visitied[node]=true;
	for(int i=0; i<vertex[node].size(); i++){
		if(!dfs_visitied[vertex[node][i]]){
			dfs_visitied[vertex[node][i]]=true;
			dfs(vertex[node][i]);
		}
	}
}

void bfs(int node){
  cout << node << ' ';
	bfs_visitied[node]=true;
	queue<int> bfs_q;
	for(int i=0; i<vertex[node].size(); i++){
		bfs_q.push(vertex[node][i]);
	}
	while(!bfs_q.empty()){
		int next=bfs_q.front();
		bfs_q.pop();
		if(!bfs_visitied[next]){
			cout << next << ' ';
			bfs_visitied[next]=true;
			for(int i=0; i<vertex[next].size(); i++){
				if(!bfs_visitied[vertex[next][i]] && bfs_q.back()!=vertex[next][i]){
					bfs_q.push(vertex[next][i]);
				}
			}
		}
	}
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n,m,v; cin >> n >> m >> v;
	for(int i=0; i<m; i++){
		int x,y; cin >> x >> y;
		vertex[x].pb(y);
		vertex[y].pb(x);
	}
	for(int i=1; i<=n; i++) sort(all(vertex[i]));
	dfs(v);
  cout << '\n';
  bfs(v);
	cout << '\n';
	return 0;
}
