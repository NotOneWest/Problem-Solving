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
  int m,t,n; cin >> m >> t >> n;
  queue<pii> q[2];
  for(int i=0; i<n; i++){
    int arrive_time; cin >> arrive_time;
    string loc; cin >> loc;
    if(loc=="left") q[0].push(mp(i,arrive_time));
    else q[1].push(mp(i, arrive_time));
  }
  int time=0,pos=0,ans[10001];
  while((q[0].size()+q[1].size())>0){
    int people=0, wait=0;
    if(!q[0].empty() && q[0].front().second<=time){
      wait=1;
      if(pos==0) pos=1;
      else time+=t;
      people=0;
      while(!q[0].empty() && q[0].front().second<=time){
        if(people==m) break;
        people++;
        ans[q[0].front().first]=(time+t);
        q[0].pop();
      }
      time+=t;
    }
    if(!q[1].empty() && q[1].front().second<=time){
      wait=1;
      if(pos==1) pos=0;
      else time+=t;
      people=0;
      while(!q[1].empty() && q[1].front().second<=time){
        if(people==m) break;
        people++;
        ans[q[1].front().first]=(time+t);
        q[1].pop();
      }
      time+=t;
    }
    if(wait==0) time++; // 그냥 배가 이동하는게 아니라 사람이 올떄까지 기다리다 지금 위치든 반대 위치든 사람이 오면 출발하는 것 고려를 안했었다...
  }
  for(int i=0; i<n; i++) cout << ans[i] << '\n';
	return 0;
}
