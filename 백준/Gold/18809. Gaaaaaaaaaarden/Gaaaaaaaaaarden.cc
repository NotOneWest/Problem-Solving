#include <bits/stdc++.h>
#define pb push_back
#define mp make_pair
#define all(x) (x).begin(), (x).end()

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
const double PI = acos(-1);

int n,m,g,r,soilsize=0,ans;
int dx[4] = { 0, 0, 1, -1 }, dy[4] = { 1, -1 ,0, 0 };
int garden[51][51], gtime[51][51], rtime[51][51], flowercheck[51][51];
vector<pii> soil,green,red;

void breed(){
  queue<pii> gq,rq;
  for(int i=0; i<51; i++){ // 배양 시간 초기화
    fill(gtime[i], gtime[i]+51, -1);
    fill(rtime[i], rtime[i]+51, -1);
    fill(flowercheck[i], flowercheck[i]+51, -1);
  }
  int flower=0, gsize=green.size(), rsize=red.size();
  // 씨앙 배양 준비
  for(int i=0; i<gsize; i++){
    gq.push(green[i]);
    gtime[green[i].first][green[i].second]=0;
  }
  for(int i=0; i<rsize; i++){
    rq.push(red[i]);
    rtime[red[i].first][red[i].second]=0;
  }
  while(!gq.empty() || !rq.empty()){
    gsize=gq.size();
    rsize=rq.size();
    for(int j=0; j<gsize; j++){
      int x=gq.front().first, y=gq.front().second;
      gq.pop();
      if(flowercheck[x][y]==3) continue;
      for(int i=0; i<4; i++){
        int nx=x+dx[i], ny=y+dy[i];
        if(nx>=0 && ny>=0 && nx<n && ny<m){
          if(gtime[nx][ny]==-1 && rtime[nx][ny]==-1 && garden[nx][ny]!=0){
            gq.push(mp(nx,ny));
            gtime[nx][ny]=(gtime[x][y]+1);
          }
        }
      }
    }
    for(int j=0; j<rsize; j++){
      int x=rq.front().first, y=rq.front().second;
      rq.pop();
      if(flowercheck[x][y]==3) continue;
      for(int i=0; i<4; i++){
        int nx=x+dx[i], ny=y+dy[i];
        if(nx>=0 && ny>=0 && nx<n && ny<m){
          if(rtime[nx][ny]!=-1) continue;
          if(garden[nx][ny]==0) continue;
          if(gtime[nx][ny]==-1){
            rq.push(mp(nx,ny));
            rtime[nx][ny]=(rtime[x][y]+1);
          } else if(gtime[nx][ny]==(rtime[x][y]+1)){ // rtime이 nx,ny 가 아니라 이전 시간 이므로 x,y
            flowercheck[nx][ny]=3;
            flower++;
            rtime[nx][ny]=rtime[x][y]+1;
          }
        }
      }
    }
  }
  ans=max(ans, flower);
}

void spread(int idx, int gcnt, int rcnt){
  if((soilsize-idx)<(gcnt+rcnt)) return; // 씨앗을 다 써야함->종료조건 ---- solidsize 가 아니라 idx 를 뺴줘야 남은 땅이 계산된다
  if(gcnt==0 && rcnt==0){
    breed();
    return;
  }
  // 심을 땅이 없을떄를 먼저 생각하는게 아니라 씨앗을 다 뿌린 경우 이후 땅이 없을 때 종료해야 한다
  if(idx==soilsize) return; // 심을 땅이 없다면->종료
  int x=soil[idx].first, y=soil[idx].second;
  spread(idx+1, gcnt, rcnt); // 이 땅에 안 뿌릴 경우
  if(gcnt>0){ // green 뿌릴 경우
    green.pb(mp(x,y));
    spread(idx+1, gcnt-1, rcnt);
    green.pop_back(); // 초기화
  }
  if(rcnt>0){ // red 뿌릴 경우
    red.pb(mp(x,y));
    spread(idx+1, gcnt, rcnt-1);
    red.pop_back(); // 초기화
  }
}


int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
  cin >> n >> m >> g >> r;
  for(int i=0; i<n; i++){
    for(int j=0; j<m; j++){
      int x; cin >> x;
      garden[i][j]=x;
      if(x==2) soil.pb(mp(i,j));
    }
  }
  soilsize=soil.size();
  spread(0,g,r);
  cout << ans << '\n';
	return 0;
}
// 처음에 틀린 이유 꽃이 피면 garden을 3으로 표시 해줬는데 계속 진행되다보면
// garden을 바꿔주면 새롭게 탐색할때 꽃이 핀곳 체크에 문제가 생기게 된다
