#include <bits/stdc++.h>
using namespace std;

int n, m;
vector<int> parent;

int find(int x){
    if(x==parent[x]) return x;
	else{
		int ch=find(parent[x]);
		parent[x]=ch;
		return ch;
	}
}

void unions(int x, int y){
    x = find(x);
    y = find(y);
    if(x!=y) parent[y] = x; 
}

int main(){
    ios::sync_with_stdio(false);
	cin.tie(0);
    cin >> n >> m;
	parent.resize(n+1);
    for(int i=1; i<=n; i++) parent[i]=i;
    for(int i=0; i<m; i++){
        int mode, a, b; cin >> mode >> a >> b;
        if(mode == 0) unions(a, b);
        else{
            if(find(a) == find(b)) cout << "YES\n";
            else cout << "NO\n";
        }
    }
    return 0;
}