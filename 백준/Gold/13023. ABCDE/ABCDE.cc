#include <bits/stdc++.h>
#define pb push_back
#define mp make_pair
#define all(x) (x).begin(), (x).end()

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
const double PI = acos(-1);

int dx[4]={1,-1,0,0}, dy[4]={0,0,-1,1}, visited[2001], n, m, check=0;
vector<int> v[2001];

void dfs(int x, int cnt){
  visited[x]=1;
  if(cnt==4){
    check=1;
    return;
  }
  int size=v[x].size();
  for(int i=0; i<size; i++){
    if(visited[v[x][i]]!=1) dfs(v[x][i], cnt+1);
  }
  visited[x]=0; // 초기화
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
  cin >> n >> m;
  for(int i=0; i<m; i++){
    int a,b; cin >> a >> b;
    v[a].pb(b);
    v[b].pb(a);
  }
  for(int i=0; i<n; i++){
    if(check) break;
    dfs(i,0);
  } // 모든 사람으로부터 시작 탐색
  if(check) cout << 1 << '\n';
  else cout << 0 << '\n';
	return 0;
}
