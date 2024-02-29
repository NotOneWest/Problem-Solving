#include <iostream>
#include <algorithm>
using namespace std;

int ans;
int n, w, h;
int board[15][12];
int dx[4] = { 1, -1, 0, 0 };
int dy[4] = { 0, 0, 1, -1 };

void breakBrick(int x, int y, int num) {
	board[x][y] = 0;

	if (num == 1) return;
	for (int k = 1; k < num; k++) {
		for (int d = 0; d < 4; d++) {
			int nx = x + dx[d] * k, ny = y + dy[d] * k;
			if (nx < 0 || nx >= h || ny < 0 || ny >= w) continue;
			if (board[nx][ny] == 0) continue;
			
			breakBrick(nx, ny, board[nx][ny]);
			board[nx][ny] = 0;
		}
	}
}

void downBrick() {
	for (int i = 0; i < w; i++) {
		int idx = h-1;
		for (int j = (h - 1); j >= 0; j--) {
			if (board[j][i] != 0) board[idx--][i] = board[j][i];
		}
		for (int j = idx; j >= 0; j--) board[j][i] = 0;
	}
}

void dfs(int idx) {
	if (idx == n) {
		int cnt = 0;
		for (int i = 0; i < h; i++) {
			for (int j = 0; j < w; j++) {
				if (board[i][j]) cnt++;
			}
		}
		ans = min(ans, cnt);

		return;
	}

	int copy_board[15][12];
	for (int i = 0; i < h; i++) {
		for (int j = 0; j < w; j++) copy_board[i][j] = board[i][j];
	}

	for (int y = 0; y < w; y++) {
		int nx = 0;
		for (int x = 0; x < h; x++) {
			if (board[x][y]) { nx = x; break; }
		}

		if (board[nx][y]) {
			breakBrick(nx, y, board[nx][y]);
			downBrick();
			dfs(idx + 1);
		}

		for (int i = 0; i < h; i++) {
			for (int j = 0; j < w; j++) board[i][j] = copy_board[i][j];
		}
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	int T; cin >> T;
	for (int tc = 1; tc <= T; tc++) {
		cin >> n >> w >> h;
		ans = 181;
		for (int i = 0; i < h; i++) {
			for (int j = 0; j < w; j++) cin >> board[i][j];
		}

		dfs(0);

		if (ans == 181) ans = 0;
		cout << "#" << tc << " " << ans << '\n';
	}
	return 0;
}

