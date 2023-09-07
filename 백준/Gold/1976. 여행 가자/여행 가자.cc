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

void unions(int x, int y){
    x = find(x);
    y = find(y);
    if(x!=y){
    	if(x > y) parent[x] = y;
		else parent[y] = x;
    }
}

int main(){
    ios::sync_with_stdio(false);
	cin.tie(0);
    cin >> n >> m;
	parent.resize(n+1);
    for(int i=1; i<=n; i++) parent[i]=i;
    
    for(int i=1; i<=n; i++){
    	for(int j=1; j<=n; j++){
    		int connected; cin >> connected;
    		
    		if(connected) unions(i, j);
		}
    }
    
    int root;
    bool flag = true;
    for(int i=0; i<m; i++){
    	int city; cin >> city;
    	if(i==0) root = parent[city];
    	else{
    		if(root != parent[city]){
    			flag = false;
    			break;
			}
		}
	}
	
	if(flag) cout << "YES\n";
	else cout << "NO\n";
    return 0;
}