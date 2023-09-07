#include <bits/stdc++.h>
#define pb push_back
#define mp make_pair
#define all(x) (x).begin(), (x).end()

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
const double PI = acos(-1);

int n, graph[101][101];

void bfs(int start){
  queue<int> q;
  int visit[101]={0,};
  q.push(start);
  while(!q.empty()){
    int now=q.front();
    q.pop();
    for(int i=1; i<=n; i++){
      if(graph[now][i]==1 && visit[i]==0){
        q.push(i);
        visit[i]=1;
        graph[start][i]=1;
      }
    }
  }
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
  cin >> n;
  for(int i=1; i<=n; i++){
    for(int j=1; j<=n; j++){
      int vertex; cin >> vertex;
      graph[i][j]=vertex;
    }
  }
  for(int i=1; i<=n; i++) bfs(i);
  for(int i=1; i<=n; i++){
    for(int j=1; j<=n; j++) cout << graph[i][j] << ' ';
    cout << '\n';
  }
	return 0;
}
