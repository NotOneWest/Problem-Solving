#include <bits/stdc++.h>
using namespace std;

int n, m, k, score=0;
int board[21][21];
int dice[4][3] = 
{
	{0, 2, 0},
	{4, 1, 3},
	{0, 5, 0},
	{0, 6, 0}
};

int down=dice[3][1], dir=0; // 동 남 서 북 
int dr[4] = {0, 1, 0, -1}, dc[4] = {1, 0, -1, 0};

pair<int, int> loc;

void move_dice(int dir){
	int tmp;
	if(dir == 0){
		tmp = dice[1][0];
		dice[1][0] = dice[3][1];
		dice[3][1] = dice[1][2];
		dice[1][2] = dice[1][1];
		dice[1][1] = tmp;
	} else if(dir == 2){
		tmp = dice[1][0];
		dice[1][0] = dice[1][1];
		dice[1][1] = dice[1][2];
		dice[1][2] = dice[3][1];
		dice[3][1] = tmp;
	} else if(dir == 1){
		tmp = dice[3][1];
        dice[3][1] = dice[2][1];
        dice[2][1] = dice[1][1];
        dice[1][1] = dice[0][1];
        dice[0][1] = tmp;
	} else{
		tmp = dice[0][1];
        dice[0][1] = dice[1][1];
        dice[1][1] = dice[2][1];
        dice[2][1] = dice[3][1];
        dice[3][1] = tmp;
	}
}

void cal_score(int r, int c, int val){
	bool used[21][21];
	for(int i=0; i<n; i++){
		for(int j=0; j<m; j++) used[i][j] = false;
	}
	int cnt = 0;
	queue<pair<int, int> > q;
	q.push(make_pair(r, c));
	used[r][c] = true;
	
	while(!q.empty()){
		int pr = q.front().first, pc = q.front().second;
		q.pop();
		cnt++;
		for(int i=0; i<4; i++){
			int nr = dr[i] + pr, nc = dc[i] + pc;
			if(nr < 0 || nr >= n || nc < 0 || nc >= m || used[nr][nc]) continue;
			if(board[nr][nc] == val){
				used[nr][nc] = true;
				q.push(make_pair(nr, nc));
			}
		}
	}
	score += (cnt*val);
}

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	cin >> n >> m >> k;
	for(int i=0; i<n; i++){
		for(int j=0; j<m; j++) cin >> board[i][j];
	}
	
	for(int t=0; t<k; t++){
		int nr = loc.first + dr[dir], nc = loc.second + dc[dir];
		
		if(nr < 0 || nr >= n || nc < 0 || nc >= m){
			dir = (dir+2)%4; nr = dr[dir] + loc.first, nc = dc[dir] + loc.second;
		}
		loc = make_pair(nr, nc);
		move_dice(dir);
		down = dice[3][1];
		
		cal_score(loc.first, loc.second, board[loc.first][loc.second]);
		
		if(down > board[nr][nc]) dir = (dir+1)%4;
		else if(down < board[nr][nc]) dir = (dir+3)%4;
	}
	cout << score << '\n';
	return 0;
}
