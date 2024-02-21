#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <set>
#include <algorithm>
using namespace std;

int n, m;
int parent[101];
int board[11][11];
int dist[11][11];

int dx[4] = { 0, 0, 1, -1 };
int dy[4] = { 1, -1, 0, 0 };

struct Node {
	int v1, v2, w;

	bool operator < (const Node& a) const {
		return w < a.w;
	}
};
vector<Node> edge;

int find(int x) {
	if (x == parent[x]) return x;
	return parent[x] = find(parent[x]);
}

void merge(int x, int y) {
	x = find(x); y = find(y);
	if (x == y) return;
	if (x < y) parent[y] = x;
	else parent[x] = y;
}

// 갈 수 있는 곳 모두 하나의 섬으로 표시
void bfs(int x, int y, int idx) {
	queue<pair<int, int>> q;
	q.push({ x, y });
	board[x][y] = idx;
	while (!q.empty()) {
		int cx = q.front().first, cy = q.front().second;
		q.pop();

		for (int i = 0; i < 4; i++) {
			int nx = cx + dx[i], ny = cy + dy[i];
			if (nx < 0 || nx >= n || ny < 0 || ny >= m) continue;
			if (board[nx][ny] == -1) {
				board[nx][ny] = idx;
				q.push({ nx, ny });
			}
		}
	}
}

// 좌표 (x, y) 에서 dir 방향으로 탐색
void move(int x, int y, int dir) {
	int dist = 0;
	int nx = x, ny = y;

	while (1) {
		nx += dx[dir]; ny += dy[dir];
		if (nx < 0 || nx >= n || ny < 0 || ny >= m) return;
		
		// 빈 곳이면 거리++
		if (board[nx][ny] == 0) dist++;
		else {
			// 섬 있는 경우 거리 2 이상이면 edge에 삽입
			if(dist >= 2) edge.push_back({ board[x][y], board[nx][ny], dist });
			return;
		}
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> board[i][j];
			if (board[i][j]) board[i][j] = -1;
		}
	}

	// 섬인 곳 -1로 마킹 후
	// 1, 2, 3 .. 순서로 bfs 돌며 표시
	int num = 1;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (board[i][j] == -1) bfs(i, j, num++);
		}
	}

	// 상, 하, 좌, 우 4 가지 방향으로 다리 탐색
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			for (int dir = 0; dir < 4; dir++) {
				if (board[i][j] != 0) move(i, j, dir);
			}
		}
	}

	// 정렬 후 크루스칼
	sort(edge.begin(), edge.end());
	// 섬 개수 만큼 초기화
	for (int i = 0; i < num; i++) parent[i] = i;

	int ans = 0, cnt = 0;
	for (int i = 0; i < edge.size(); i++) {
		if (find(edge[i].v1) == find(edge[i].v2)) continue;
		merge(edge[i].v1, edge[i].v2);
		ans += edge[i].w;
		cnt++;
	}

	// 섬 개수 - 1 만큼 연결되면 모두 연결
	if (cnt < (num - 2)) ans = -1;
	cout << ans << '\n';

	return 0;
}