#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

struct Node {
	int x, y;
};
vector<Node> loc;

int n, k, ans = 9e9;
int choose[3];
int visited[51];

void dfs(int idx, int cnt) {
	if (cnt == k) {
		int MAX = 0;
		for (int i = 0; i < n; i++) {
			if (visited[i]) continue;

			int MIN = 9e9;
			for (int j = 0; j < k; j++) MIN = min(MIN, abs(loc[i].x - loc[choose[j]].x) + abs(loc[i].y - loc[choose[j]].y));
			MAX = max(MAX, MIN);
		}
		ans = min(ans, MAX);
		return;
	}

	for (int i = idx; i < n; i++) {
		choose[cnt] = i;
		visited[i] = 1;
		dfs(i + 1, cnt + 1);
		visited[i] = 0;
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	cin >> n >> k;
	for (int i = 0; i < n; i++) {
		int x, y; cin >> x >> y;
		loc.push_back({ x, y });
	}

	dfs(0, 0);
	cout << ans;
	return 0;
}