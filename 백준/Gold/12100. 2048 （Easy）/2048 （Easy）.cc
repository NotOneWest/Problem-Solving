#include <bits/stdc++.h>
#define pb push_back
#define mp make_pair
#define all(x) (x).begin(), (x).end()

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
const double PI = acos(-1);

int n, mx=0, board[21][21], copy_board[21][21], selection[5];

void right(){
	int check[21][21];
	for(int i=0; i<21; i++) memset(check[i],0,sizeof(check[i]));
	for(int i=0; i<n; i++){
		for(int j=n-2; j>=0; j--){
			if(copy_board[i][j]==0) continue;
			for(int k=(j+1); k<n; k++){
				if(copy_board[i][k]==0){
					copy_board[i][k]=copy_board[i][k-1];
					copy_board[i][k-1]=0;
				}
				else if (copy_board[i][k]==copy_board[i][k-1] && check[i][k]!=1){
					copy_board[i][k]*=2;
					copy_board[i][k-1]=0;
					check[i][k]=1;
					break; // 한번 결합하게 되면 더 결합 못 하니 멈춰야한다... 아니면 계속 진행되어 한번 더 합쳐짐..
				} else break; // 블록 이동 못하기 때문에 불필요한 이동 생기기전 멈춤
			}
		}
	}
}

void left(){
	int check[21][21];
	for(int i=0; i<21; i++) memset(check[i],0,sizeof(check[i]));
	for(int i=0; i<n; i++){
		for(int j=1; j<n; j++){
			if(copy_board[i][j]==0) continue;
			for(int k=(j-1); k>=0; k--){
				if(copy_board[i][k]==0){
					copy_board[i][k]=copy_board[i][k+1];
					copy_board[i][k+1]=0;
				}
				else if (copy_board[i][k]==copy_board[i][k+1] && check[i][k]!=1){
					copy_board[i][k]*=2;
					copy_board[i][k+1]=0;
					check[i][k]=1;
					break;
				} else break;
			}
		}
	}
}

void up(){
	int check[21][21];
	for(int i=0; i<21; i++) memset(check[i],0,sizeof(check[i]));
	for(int i=0; i<21; i++) memset(check[i],0,sizeof(check[i]));
	for(int i=0; i<n; i++){
		for(int j=1; j<n; j++){
			if(copy_board[j][i]==0) continue;
			for(int k=(j-1); k>=0; k--){
				if(copy_board[k][i]==0){
					copy_board[k][i]=copy_board[k+1][i];
					copy_board[k+1][i]=0;
				}
				else if (copy_board[k][i]==copy_board[k+1][i] && check[k][i]!=1){
					copy_board[k][i]*=2;
					copy_board[k+1][i]=0;
					check[k][i]=1;
					break;
				} else break;
			}
		}
	}
}

void down(){
	int check[21][21];
	for(int i=0; i<21; i++) memset(check[i],0,sizeof(check[i]));
	for(int i=0; i<n; i++){
		for(int j=n-2; j>=0; j--){
			if(copy_board[j][i]==0) continue;
			for(int k=(j+1); k<n; k++){
				if(copy_board[k][i]==0){
					copy_board[k][i]=copy_board[k-1][i];
					copy_board[k-1][i]=0;
				}
				else if (copy_board[k][i]==copy_board[k-1][i] && check[k][i]!=1){
					copy_board[k][i]*=2;
					copy_board[k-1][i]=0;
					check[k][i]=1;
					break;
				} else break;
			}
		}
	}
}

int playGame(){
	for(int i=0; i<n; i++){
		for(int j=0; j<n; j++) copy_board[i][j]=board[i][j];
	}
	int maxNum=0;
	for(int i=0; i<5; i++){
		if(selection[i]==0) right();
		else if(selection[i]==1) left();
		else if(selection[i]==2) up();
		else down();
	}
	for(int i=0; i<n; i++){
		for(int j=0; j<n; j++) maxNum=max(maxNum, copy_board[i][j]);
	}
	return maxNum;
}

void selectDirection(int cnt){
	if(cnt==5){
		int curr = playGame();
		mx=max(mx, curr);
		return;
	}
	selection[cnt]=0;
	selectDirection(cnt+1);
	selection[cnt]=1;
	selectDirection(cnt+1);
	selection[cnt]=2;
	selectDirection(cnt+1);
	selection[cnt]=3;
	selectDirection(cnt+1);
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> n;
	for(int i=0; i<n; i++){
		for(int j=0; j<n; j++) cin >> board[i][j];
	}
	selectDirection(0);
	cout << mx << '\n';
	return 0;
}




// cout << "\n-------------\n";
// for(int i=0; i<n; i++){
// 	for(int j=0; j<n; j++) cout << copy_board[i][j] << ' ';
// 	cout << "\n";
// }
// cout << "\n-------------\n";
