#include <bits/stdc++.h>
#define pb push_back
#define mp make_pair
#define all(x) (x).begin(), (x).end()

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
const double PI = acos(-1);

int dx[4]={1,0,-1,0}, dy[4]={0,1,0,-1};
char board[103][103];
int visited[103][103], key[26], h, w;

void find(char c){
  if(key[c-'a']==1) return;
  for(int i=0; i<h+2; i++){
    for(int j=0; j<w+2; j++){
      if(board[i][j]==(c-32)){
        board[i][j]='.';
        key[c-'a']=1;
      }
    }
  }
  // cout << "-------------\n";
  // for(int i=0; i<h+2; i++){
  //   for(int j=0; j<w+2; j++) cout << board[i][j];
  //   cout << '\n';
  // }
  // cout << "-------------\n";
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
  int t; cin >> t;
  for(int test=0; test<t; test++){
    fill(key,key+26,0);
    for(int i=0; i<103; i++) fill(visited[i], visited[i]+103, 0);
    int answer=0; cin >> h >> w;
    queue<pii> q;
    for(int i=0; i<=w+1; i++){
      board[0][i]='.';
      board[h+1][i]='.';
    }
    for(int i=0; i<=h+1; i++){
      board[i][0]='.';
      board[i][w+1]='.';
    }
    for(int i=1; i<=h; i++){
      for(int j=1; j<=w; j++) cin >> board[i][j];
    }
    string keys; cin >> keys;
    if(keys!="0") for(int i=0; i<keys.length(); i++) find(keys[i]);
    q.push(mp(0,0));
    while(!q.empty()){
      int curx=q.front().first, cury=q.front().second;
      q.pop();
      if(visited[curx][cury]==1 || board[curx][cury]=='*' || (board[curx][cury]>='A' && board[curx][cury]<='Z')) continue;
      visited[curx][cury]=1;
      if(board[curx][cury]=='$'){
        answer++;
        board[curx][cury]='.';
      }
      if(board[curx][cury]>='a' && board[curx][cury]<='z'){
        find(board[curx][cury]);
        board[curx][cury]='.';
        for(int i=0; i<101; i++) fill(visited[i], visited[i]+101, 0);
        while(!q.empty()) q.pop();
        q.push(mp(curx,cury));
        continue;
      }
      for(int i=0; i<4; i++){
        int nx=curx+dx[i], ny=cury+dy[i];
        if(nx>=0 && nx<(h+2) && ny>=0 && ny<(w+2)) q.push(mp(nx,ny));
      }
    }
    cout << answer << "\n";
  }
	return 0;
}
