#include <bits/stdc++.h>
#define pb push_back
#define mp make_pair
#define all(x) (x).begin(), (x).end()

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
const double PI = acos(-1);

char board[101][101];
int reals[101][101];
int dxy[8][2] = {{1,0}, {-1,0}, {0,1}, {0,-1}, {1,1}, {-1,-1}, {1,-1}, {-1,1}};

int main(){
	while(1){
		int r,c; cin >> r >> c;
		if(r==0 && c==0) break;
		
		for(int i=0; i<101; i++){
			fill(board[i], board[i]+101, 0);
			fill(reals[i], reals[i]+101, -1);
		}
		
		for(int i=0; i<r; i++){
			for(int j=0; j<c; j++){
				cin >> board[i][j];
			}
		}
		
		
		for(int i=0; i<r; i++){
			for(int j=0; j<c; j++){
				if(board[i][j]=='*') reals[i][j]=-1;
				else{
					int cnt=0;
					for(int t=0; t<8; t++){
						int col = i + dxy[t][0];
						int row = j + dxy[t][1];
						if((col >=0 && col<r) && (row>=0 && row<c)){
							if(board[col][row] == '*') cnt++;
						}
					}
					reals[i][j]=cnt;
				}
			}
		}
		
		for(int i=0; i<r; i++){
			for(int j=0; j<c; j++){
				if(reals[i][j]==-1) cout << "*";
				else cout << reals[i][j];
			}
			cout << '\n';
		}
	}
	return 0;
}
