#include <iostream>

#include <queue>

#include <vector>

#include <algorithm>

using namespace std;

struct Bus {
	int no;
	int xs, xe;
	int ys, ye;
};

Bus bus[5001];
int visited[5001];

int main() {
	int m, n, k; cin >> m >> n >> k;
	for (int i = 0; i < k; i++) {
		int b, x1, y1, x2, y2; cin >> b >> x1 >> y1 >> x2 >> y2;
		bus[i] = { b, min(x1, x2), max(x1, x2), min(y1, y2), max(y1, y2) };
	}
	int sx, sy, dx, dy; cin >> sx >> sy >> dx >> dy;

	int ans = -1;
	queue<pair<int, int>> q; // 버스 no, cnt

	// 처음 위치에서 바로 탈 수 있는 버스 queue에 push
	for (int i = 0; i < k; i++) {
		if (bus[i].xs <= sx && sx <= bus[i].xe && bus[i].ys <= sy && sy <= bus[i].ye) {
			q.push({ i, 1 });
			visited[bus[i].no] = 1;
		}
	}

	while (!q.empty()) {
		int no = q.front().first, cnt = q.front().second;
		q.pop();

		// 도착 위치에 내릴 수 있는 버스 탔는지 체크
		if (bus[no].xs <= dx && dx <= bus[no].xe && bus[no].ys <= dy && dy <= bus[no].ye) {
			ans = cnt;
			break;
		}

		for (int j = 0; j < k; j++) {
			if (visited[bus[j].no]) continue;

			if (bus[no].xs > bus[j].xe) continue;
			if (bus[j].xs > bus[no].xe) continue;
			if (bus[no].ys > bus[j].ye) continue;
			if (bus[j].ys > bus[no].ye) continue;

			q.push({ j, cnt + 1 });
			visited[bus[j].no] = 1;
		}
	}

	cout << ans << '\n';
	return 0;
}