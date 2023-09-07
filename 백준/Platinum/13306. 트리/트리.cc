#include <bits/stdc++.h>
#define pb push_back
#define mp make_pair
#define all(x) (x).begin(), (x).end()

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
const double PI = acos(-1);

vector<int> parent;
int gp[200001], bc[400002], d[400002];

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
	if(x>y) swap(x, y);
	if(x==y) return;
	parent[y]=x;
}

int main(){
	int n,q; cin >> n >> q;
	parent.resize(n+1);
	for(int i=1; i<n+1; i++) parent[i]=i;
	for(int i=2; i<=n; i++) cin >> gp[i];
	for(int i=0; i<(n+q-1); i++){
		int x; cin >> x;
		if(x) cin >> bc[i] >> d[i];
		else cin >> bc[i];
	}
	stack<string> answer;
	for(int i=(n+q-2); i>=0; i--){
		if(d[i]==0){
			merge(gp[bc[i]], bc[i]);
		}
		else if(i==0 && d[i]!=0){
			for(int j=2; j<=n; j++){
				if(gp[j]!=0) merge(gp[j], j);
			}
			i--;
			if(find(bc[i])==find(d[i])) answer.push("YES");
			else answer.push("NO");
		}
		else{
			if(find(bc[i])==find(d[i])) answer.push("YES");
			else answer.push("NO");
		}	
	}
	while(!answer.empty()){
		cout << answer.top() << '\n';
		answer.pop();
	}
	return 0;
}
