#include <bits/stdc++.h>
#define pb push_back
#define mp make_pair
#define all(x) (x).begin(), (x).end()

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
const double PI = acos(-1);

int visited[100001], dfsorder[100001], number[100001], n, idx=0;
vector<int> v[100001];

bool comp(int a, int b){
  return (dfsorder[a] < dfsorder[b]); // dfs 순서에 따른 정렬
}

void dfs(int x){
  if(visited[x]==1) return;
  visited[x]=1;
  if(x!=number[idx++]){
    cout << 0 << '\n';
    exit(0);
  }
  int size=v[x].size();
  for(int i=0; i<size; i++){
    if(visited[v[x][i]]==0) dfs(v[x][i]);
  }
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
  cin >> n;
  for(int i=1; i<n; i++){
    int a,b; cin >> a >> b;
    v[a].pb(b);
    v[b].pb(a);
  }
  for(int i=0; i<n; i++){
    cin >> number[i];
    dfsorder[number[i]]=i+1;
  }
  for(int i=1; i<=n; i++) sort(all(v[i]), comp); // dfs 순서대로 정렬을 해줬어야함...
  dfs(1);
  cout << 1 << '\n';
	return 0;
}
