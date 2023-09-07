#include <bits/stdc++.h>
#define pb push_back
#define mp make_pair
#define all(x) (x).begin(), (x).end()

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
const double PI = acos(-1);

int board[10][10];
bool row[10][10], col[10][10], box[10][10];

void func(int index){
  if(index==81){
    for(int i=0; i<9; i++){
      for(int j=0; j<9; j++) cout << board[i][j] << ' ';
      cout << '\n';
    }
    exit(0);
  }
  int col_n=index/9, row_n=index%9;
  if(board[col_n][row_n]==0){
    for(int i=1; i<=9; i++){
      if(row[row_n][i]==0 && col[col_n][i]==0 && box[(col_n/3)*3+(row_n/3)][i]==0){
        row[row_n][i]=true;
        col[col_n][i]=true;
        box[(col_n/3)*3+(row_n/3)][i]=true;
        board[col_n][row_n]=i;
        func(index+1);
        board[col_n][row_n]=0;
        row[row_n][i]=false;
        col[col_n][i]=false;
        box[(col_n/3)*3+(row_n/3)][i]=false;
      }
    }
  } else func(index+1);
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
  for(int i=0; i<9; i++){
    for(int j=0; j<9; j++){
      cin >> board[i][j];
      if(board[i][j]!=0){
        row[j][board[i][j]]=true;
        col[i][board[i][j]]=true;
        box[(i/3)*3+(j/3)][board[i][j]]=true;
      }
    }
  }
  func(0);
	return 0;
}
