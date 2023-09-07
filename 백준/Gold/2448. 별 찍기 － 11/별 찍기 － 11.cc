#include <bits/stdc++.h>
#define pb push_back
#define mp make_pair
#define all(x) (x).begin(), (x).end()

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
const double PI = acos(-1);
const int MAX = 1024 * 3 + 2;

char board[MAX][MAX*2-1];

void base(int x, int y){
  board[x][y]='*';
  board[x+1][y-1]='*';
  board[x+1][y+1]='*';
  for(int i=y-2; i<(y+3); i++) board[x+2][i]='*';
}


void star(int x, int y, int n){
  if(n==3){
    base(x,y);
    return;
  }
  int next=n/2;
  star(x,y,next); // 맨 위의 *를 기준으로 k가 커질떄마다 기준점들이 어떻게 되는지 check
  star(x+next,y-next,next);
  star(x+next,y+next,next);
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
  int n; cin >> n;
  star(0,n-1,n);
  for(int i=0; i<n; i++){
    for(int j=0; j<2*n; j++){
      if(board[i][j]=='*') cout << "*";
      else cout << ' ';
    }
    cout << "\n";
  }
	return 0;
}
