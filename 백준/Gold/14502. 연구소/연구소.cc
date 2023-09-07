#include <bits/stdc++.h>
#define pb push_back
#define mp make_pair
#define all(x) (x).begin(), (x).end()

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
const double PI = acos(-1);

int n,m,ans=0,lab[9][9];
int dx[4]={0,1,0,-1}, dy[4]={1,0,-1,0};
vector<pii> virus, zero;

int virus_move(){
  queue<pii> q;
  int visited[9][9], num=0;
  for(int i=0; i<9; i++) memset(visited[i], 0, sizeof(visited[i]));
  for(int i=0; i<n; i++){
    for(int j=0; j<m; j++){
      if(lab[i][j]==2) q.push(mp(i,j));
    }
  }
  while(!q.empty()){
    int x=q.front().first, y=q.front().second;
    q.pop();
    num++;
    for(int i=0; i<4; i++){
      int nx=(x+dx[i]), ny=(y+dy[i]);
      if(nx>=0 && nx<n && ny>=0 && ny<m){
        if(visited[nx][ny]==0 && lab[nx][ny]==0){
          visited[nx][ny]=1;
          q.push(mp(nx,ny));
        }
      }
    }
  }
  return num;
}

void func(int idx, int wall){
  int sz=zero.size(), sz_v=virus.size();
  if(wall==3){
    int v_num=virus_move();
    ans=max(ans, sz-3-v_num+sz_v);
    return;
  }
  for(int i=idx; i<sz; i++){
    lab[zero[i].first][zero[i].second]=1;
    func(i+1,wall+1);
    lab[zero[i].first][zero[i].second]=0;
  }
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
  cin >> n >> m;
  for(int i=0; i<n; i++){
    for(int j=0; j<m; j++){
      cin >> lab[i][j];
      if(lab[i][j]==2) virus.pb(mp(i,j));
      if(lab[i][j]==0) zero.pb(mp(i,j));
    }
  }
  func(0,0);
  cout << ans << '\n';
	return 0;
}
