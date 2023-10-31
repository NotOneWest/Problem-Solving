#include <bits/stdc++.h>
using namespace std;

bool board[11][11], temp[11][11];
int dx[4] = { 0,0,1,-1 };
int dy[4] = { 1,-1,0,0 };

void init() {
	for(int i=0; i<10; i++){
		for(int j=0; j<10; j++) temp[i][j] = board[i][j];
	}
}

bool islight() {
	for(int i=0; i<10; i++){
		for(int j=0; j<10; j++) if(temp[i][j]) return 1;
	}
	return 0;
}

void turnOn(int x, int y){
	for(int i=0; i<4; i++){
		int nx = x+dx[i], ny = y+dy[i]; 
		if(x<0 || x>9 || y<0 || y>9) continue;
		temp[nx][ny] = !temp[nx][ny];
	}
	temp[x][y] = !temp[x][y];
}

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	int ans = 1e9;
	for(int i=0; i<10; i++){
		string s; cin >> s;
		for(int j=0; j<10; j++){
			if(s[j] == '#') board[i][j] = 0;
			else board[i][j] = 1;
		}
	}
	
	for(int k=0; k<1024; k++){
		int cnt = 0;
		init();
		
		for(int i=0; i<10; i++){
			if(k & (1<<i)){ cnt++; turnOn(0, i); } 
		}
		
		for(int i=1; i<10; i++){
			for(int j=0; j<10; j++){
				if(temp[i-1][j]){ cnt++; turnOn(i, j); }
			}
		}
		
		if(!islight()) ans = min(ans, cnt);
	}
	
	if(ans == 1e9) ans = -1;
	cout << ans << '\n';
	return 0;
}
