#include <bits/stdc++.h>
using namespace std;

bool board[10][10], temp[10][10];
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

void turnOn(int y, int x){
	for(int i=0; i<4; i++){
		int ny = y+dy[i], nx = x+dx[i];
		if(nx<0 || nx>9 || ny<0 || ny>9) continue; // nx, ny를 x, y로 ... 실수
		temp[ny][nx] = !temp[ny][nx];
	}
	temp[y][x] = !temp[y][x];
}

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	int ans = -1;
	for(int i=0; i<10; i++){
		string s; cin >> s;
		for(int j=0; j<10; j++){
			if(s[j] == '#') board[i][j] = 0;
			else board[i][j] = 1;
		}
	}
	
	for(int k=0; k<=1024; k++){
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
		
		if(!islight()){
			if(ans == -1) ans = cnt;
			else ans = min(ans, cnt);
		}
	}
	cout << ans << '\n';
	return 0;
}
