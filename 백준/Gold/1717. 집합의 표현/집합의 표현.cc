#include <bits/stdc++.h>
#define pb push_back
#define mp make_pair
#define all(x) (x).begin(), (x).end()

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
const double PI = acos(-1);

vector<int> parent;

int find(int x){
	if(x==parent[x]) return x;
	else{
		int ch=find(parent[x]);
		parent[x]=ch;
		return ch;
	}
}

void merge(int x, int y){
	x=find(x);
	y=find(y);
	if(x!=y) parent[y]=x;
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	int n,cnt=0; cin >> n;
	parent.resize(n+1);
	for(int i=1; i<n+1; i++) parent[i]=i;
	int m; cin >> m;
	for(int i=0;i<m; i++){
		int cases,a,b; cin >> cases >> a >> b;
		if(cases==0) merge(a,b);
		else{
			if(find(a)==find(b)) cout << "YES\n";
			else cout << "NO\n";
		}
	}
	return 0;
}
