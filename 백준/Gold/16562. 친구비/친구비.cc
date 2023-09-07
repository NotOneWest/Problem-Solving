#include <bits/stdc++.h>
#define pb push_back
#define mp make_pair
#define all(x) (x).begin(), (x).end()

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
const double PI = acos(-1);

vector<int> parent;
int money[10001];

int find(int x){
	if(x==parent[x]) return x;
	else{
		int ch=find(parent[x]);
		parent[x]=ch;
		return ch;
	}
}
 
int merge(int x, int y){
	x=find(x);
	y=find(y);
	if(x!=y){
		if(money[x] > money[y]){
			parent[x]=y;
		}
		else parent[y]=x;
	}
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	int n,m,k,sum=0; cin >> n >> m >> k;
	parent.resize(n+1);
	for(int i=1; i<n+1; i++) parent[i]=i;
	for(int i=1; i<n+1; i++) cin >> money[i];
	for(int i=0;i<m; i++){
		int a,b; cin >> a >> b;
		merge(a,b);
	}
	for(int i=1; i<=n; i++){
		if(find(i)==i) sum+=money[i];
	}
	if(sum <= k)cout << sum;
	else cout << "Oh no";
	return 0;
}
