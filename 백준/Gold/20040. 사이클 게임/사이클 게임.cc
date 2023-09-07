#include <bits/stdc++.h>
using namespace std;

int n, m;
vector<int> parent;
vector<int> des;

int find(int x){
    if(x==parent[x]) return x;
	else{
		int ch=find(parent[x]);
		parent[x]=ch;
		return ch;
	}
}

bool unions(int x, int y){
    x = find(x);
    y = find(y);
    if(x==y) return true;
    if(x!=y){
    	parent[y]=x;
    	return false;
	}
}

int main(){
    ios::sync_with_stdio(false);
	cin.tie(0);
    cin >> n >> m;
	parent.resize(n+1);
    for(int i=1; i<=n; i++) parent[i]=i;
    
    int ans = 0;
    for(int i=1; i<=m; i++){
    	int u, v; cin >> u >> v;
    	if(unions(u, v)){
    		ans = i;
    		break;
		}
	}
	cout << ans;
    return 0;
}