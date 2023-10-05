#include <bits/stdc++.h>

using namespace std;

int n, m, a, b, cnt=0, ans=0;
vector<int> relation[101];
int visited[101] = {0, };

void dfs(int node){
	if(node == b) ans = cnt;
	
	visited[node] = 1;
	for(int i=0; i<relation[node].size(); i++){
		int next = relation[node][i];
		if(visited[next] == 0){
			visited[next] = 1;
			cnt++;
			dfs(next);
			cnt--;
		} 	
	} 
}

int main(){
	cin >> n >> a >> b >> m;
	for(int i=0; i<m; i++){
		int x, y; cin >> x >> y;
		relation[x].push_back(y);
		relation[y].push_back(x);
	}
	dfs(a);
	if(ans != 0) cout << ans << '\n';
	else cout << -1 << '\n';
	return 0;
}