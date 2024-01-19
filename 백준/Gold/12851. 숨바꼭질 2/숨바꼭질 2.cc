#include<iostream>
#include<algorithm>
#include<queue>
using namespace std;

int n, k, ans = 100001, cnt = 0;
bool visited[100001];

void bfs(int n, int t) {
	queue<pair<int, int>> q;
	q.push(make_pair(n, t)); // 위치, 시간

	while (!q.empty()) {
		int x = q.front().first, sec = q.front().second;
		q.pop();
		visited[x] = true;

		if (x == k) {
			// 시간이 순차적으로 증가
			// cnt 갱신 순간이 최소 시간
			if (!cnt) { ans = sec; cnt++; }
			else if (cnt > 0 && ans == sec) cnt++;
		}

		int dx[3] = { x - 1, x + 1, x * 2 };
		for (int i = 0; i < 3; i++) {
			if (0 <= dx[i] && dx[i] <= 100000 && !visited[dx[i]]) q.push(make_pair(dx[i], sec + 1));
		}
	}
}

int main() {
	ios::sync_with_stdio(0); cin.tie(0);
	cin >> n >> k;

	if (n == k) cout << 0 << '\n' << 1;
	else { bfs(n, 0); cout << ans << '\n' << cnt; }
	return 0;
}