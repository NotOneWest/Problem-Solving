#include <bits/stdc++.h>
using namespace std;

map<string, int> m;
int parent[200001], cnt[200001];

int find(int x){
    if(x==parent[x]) return x;
	return parent[x]=find(parent[x]);
}

int unions(int x, int y){
    x = find(x);
    y = find(y);
    if(x!=y){
    	parent[x]=y;
    	cnt[y] += cnt[x];
	}
	return cnt[y];
}

int main(){
    ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
    int t; cin >> t;
    while(t--){
    	m.clear();
    	for(int i=0; i<200001; i++) parent[i]=i, cnt[i]=1;
    	
    	int f, index=1; cin >> f;
    	for(int i=0; i<f; i++){
    		string f1, f2; cin >> f1 >> f2;
    		if(m.count(f1) == 0){
    			m.insert(make_pair(f1, index));
    			index++;
			}
			
			if(m.count(f2) == 0){
    			m.insert(make_pair(f2, index));
    			index++;
			}
			cout << unions(m[f1], m[f2]) << "\n";
		}
	}
    return 0;
}