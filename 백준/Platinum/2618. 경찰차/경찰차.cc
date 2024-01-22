#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

int n, w;
int dp[1001][1001];
vector<pair<int, int>> cases;

// dp[A][B] : 1 번이 A, 2번이 B까지 처리한 경우 최소 이동 거리
// dfs로 사건 경우 갱신하며 최소 이동 거리 dp에 저장
int cal(int p1, int p2) {
	if (p1 == w || p2 == w) return 0; // 마지막 사건에 도달하면 끝
	if (dp[p1][p2] != -1) return dp[p1][p2];

	int next = max(p1, p2) + 1; // 다음 사건은 더 큰 번호 + 1
	int dist1, dist2;

	if (p1 == 0) dist1 = abs(cases[next-1].first - 1) + abs(cases[next-1].second - 1);
	else dist1 = abs(cases[p1-1].first - cases[next-1].first) + abs(cases[p1-1].second - cases[next-1].second);

	if (p2 == 0) dist2 = abs(cases[next-1].first - n) + abs(cases[next-1].second - n);
	else dist2 = abs(cases[p2-1].first - cases[next-1].first) + abs(cases[p2-1].second - cases[next-1].second);

	// 이후 갱신 next, p2 / p1, next 2 가지
	dist1 += cal(next, p2), dist2 += cal(p1, next);

	dp[p1][p2] = min(dist1, dist2);

	return dp[p1][p2];
}

// 경로 찾는 함수
void route(int p1, int p2) {
	if (p1 == w || p2 == w) return; // 마지막 사건에 도달하면 끝

	int next = max(p1, p2) + 1; // 다음 사건은 더 큰 번호 + 1
	int dist1, dist2;

	if (p1 == 0) dist1 = abs(cases[next - 1].first - 1) + abs(cases[next - 1].second - 1);
	else dist1 = abs(cases[p1 - 1].first - cases[next - 1].first) + abs(cases[p1 - 1].second - cases[next - 1].second);

	if (p2 == 0) dist2 = abs(cases[next - 1].first - n) + abs(cases[next - 1].second - n);
	else dist2 = abs(cases[p2 - 1].first - cases[next - 1].first) + abs(cases[p2 - 1].second - cases[next - 1].second);

	// 사건으로 이동 거리 계산 후, 이전 경로 중 최소 비교해 갱신
	if (dp[next][p2] + dist1 < dp[p1][next] + dist2) {
		cout << 1 << '\n';
		route(next, p2);
	}
	else {
		cout << 2 << '\n';
		route(p1, next);
	}
}


int main() {
	ios::sync_with_stdio(0); cin.tie(0);
	cin >> n >> w;
	for (int i = 0; i < w; i++) {
		int x, y; cin >> x >> y;
		cases.push_back(make_pair(x, y));
	}

	for (int i = 0; i <= w; i++) {
		for (int j = 0; j <= w; j++) dp[i][j] = -1;
	}

	cout << cal(0, 0) << '\n';
	route(0, 0);

	return 0;
}