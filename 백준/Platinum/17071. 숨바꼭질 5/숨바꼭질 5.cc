#include<iostream>
#include<algorithm>
#include<queue>
using namespace std;

int even_sec[500002], odd_sec[500002]; // 특정 거리에 도달하는 시간

void bfs(int n) {
	queue<int> q;
	q.push(n);
	even_sec[n] = 0;
	int size, t = 0;
	while (!q.empty()) {
		size = q.size();
		// 매 시간에 위치할 수 있는 좌표에서 계산
		for (int j = 0; j < size; j++) {
			int x = q.front();
			// 갈 수 있는 좌표 x-1, x+1, x*2
			int dx[3] = { x - 1, x + 1, x * 2 };
			q.pop();
			for (int i = 0; i < 3; i++) {
				if (0 <= dx[i] && dx[i] <= 500000) {
					// t+1초가 들어가서 t가 홀수일 때 짝수초
					if (t % 2 != 0) {
						if (even_sec[dx[i]] == 0) {
							q.push(dx[i]);
							even_sec[dx[i]] = t + 1;
						}
					}
					else {
						if (odd_sec[dx[i]] == 0) {
							q.push(dx[i]);
							odd_sec[dx[i]] = t + 1;
						}
					}
				}
			}
		}
		t++;
	}
}

int main() {
	ios::sync_with_stdio(0); cin.tie(0);
	int n, k; cin >> n >> k;

	if (n == k) {
		cout << 0;
		return 0;
	}

	bfs(n); // 미리 시간 계산
	int ans = 500010, t = 0;
	// 매초 동생의 좌표와 시간 비교
	while (k <= 500000) {
		if (t % 2 == 0) {
			if (0 < even_sec[k] && even_sec[k] <= t) ans = min(ans, t);
		}
		else {
			if (0 < odd_sec[k] && odd_sec[k] <= t) ans = min(ans, t);
		}
		t++; k += t;
	}
	if (ans == 500010) ans = -1;
	cout << ans;
	return 0;
}