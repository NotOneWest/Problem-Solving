#include <bits/stdc++.h>
#define pb push_back
#define mp make_pair
#define all(x) (x).begin(), (x).end()

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
const double PI = acos(-1);

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
  int n,m; cin >> n >> m;
  int next[101]={0,}, distance[101];
  for(int i=0; i<n; i++){
    int x,y; cin >> x >> y;
    next[x]=y;
  }
  for(int i=0; i<m; i++){
    int u,v; cin >> u >> v;
    next[u]=v;
  }
  queue<int> q;
  fill(distance, distance+101, -1);
  q.push(1);
  distance[1]=0;
  while(!q.empty()){
    int prev=q.front();
    q.pop();
    for(int i=1; i<=6; i++){
      int next_loc=(prev+i);
      if(next_loc<=100){
        if(next[next_loc]!=0) next_loc=next[next_loc];
        if(distance[next_loc]==-1){
          distance[next_loc]=(distance[prev]+1);
          q.push(next_loc);
        }
      }
    }
  }
  cout << distance[100] << '\n';
	return 0;
}
