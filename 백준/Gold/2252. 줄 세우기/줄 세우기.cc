#include <bits/stdc++.h>
#define pb push_back
#define mp make_pair
#define all(x) (x).begin(), (x).end()

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
const double PI = acos(-1);

vector<vector<int> > v(32005);
int line[32005];

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	int n, m; cin >> n >> m;
	for(int i=0; i<m; i++){
		int start, end; cin >> start >> end;
		v[start].pb(end);
		line[end]++;		
	}
	queue<int> q;
	for(int i=1; i<=n; i++){
		if(line[i]==0) q.push(i);
	}
	while(!q.empty()){
		int top=q.front();
		cout << top << ' ';
		q.pop();
		for(int i=0; i<v[top].size(); i++){
			line[v[top][i]]--;
			if(line[v[top][i]]==0) q.push(v[top][i]);
		}
	}
	return 0;
}
