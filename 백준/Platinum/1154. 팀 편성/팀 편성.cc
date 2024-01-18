#include<iostream>
#include<vector>
using namespace std;

int neighbor[1001][1001];
int parents[1001];

// 부모를 찾는 함수
int find(int x) {
	if (parents[x] == x) return x;
	parents[x] = find(parents[x]);
	return parents[x];
}

// a, b 끼리 결합 ... 1이 기준이 되어 구분해줌
void merge(int a, int b) {
	int parent_a = find(a);
	int parent_b = find(b);

	if (parent_a == 1) parents[parent_b] = 1;
	else if (parent_b == 1) parents[parent_a] = 1;
	else parents[parent_a] = parent_b;
}

int main() {
	ios::sync_with_stdio(0); cin.tie(0);
	int n; cin >> n;

	for (int i = 0; i <= n; i++) {
		parents[i] = i;
		for (int j = 0; j <= n; j++) neighbor[i][j] = 0;
	}

	while (1) {
		int x, y; cin >> x >> y;
		if (x == -1 && y == -1) break;
		neighbor[x][y] = 1;
		neighbor[y][x] = 1;
	}

	// 친구가 아니라는 것은, 무조건 그 친구와 다른 그룹
	for (int i = 1; i <= n; i++) {
		vector<int> not_neigbor;
		for (int j = 1; j <= n; j++) {
			if (i == j || neighbor[i][j]) continue;
			not_neigbor.push_back(j);
		}

		if (!not_neigbor.empty()) {
			for (int j = 0; j < (not_neigbor.size() - 1); j++) {
				merge(not_neigbor[j], not_neigbor[j + 1]);
			}
		}
	}

	// 그룹 판별 Visited[부모]
	int visited[1001], group = 0;
	for (int i = 0; i <= n; i++) visited[i] = 0;
	for (int i = 1; i <= n; i++) visited[find(i)]++;

	vector<int> no_group;
	for (int i = 1; i <= n; i++) {
		if (visited[i] == 1) no_group.push_back(i);
		else if (visited[i] > 1) group++;
	}

	// 그룹의 개수가 1개 또는 2개
	if (!no_group.empty()) group++;
	
	if (group > 2) {
		cout << -1;
		return 0;
	}

	// 모든 친구들이 서로 친구이면 Group -> 0
	// 그룹으로 묶이지 않은 친구들은 그 친구들끼리 그룹으로
	if (!no_group.empty()) {
		for (int j = 0; j < (no_group.size() - 1); j++) {
			merge(no_group[j], no_group[j + 1]);
		}
	}

	// 각 그룹에 대해 검증
	vector<int> group1, group2;
	for (int i = 1; i <= n; i++) {
		if (find(i) == 1) group1.push_back(i);
		else group2.push_back(i);
	}

	for (int i = 0; i <group1.size(); i++) {
		for (int j = 0; j < i; j++) {
			if (!neighbor[group1[i]][group1[j]]) {
				cout << -1;
				return 0;
			}
		}
	}

	for (int i = 0; i < group2.size(); i++) {
		for (int j = 0; j < i; j++) {
			if (!neighbor[group2[i]][group2[j]]) {
				cout << -1;
				return 0;
			}
		}
	}

	cout << "1\n";
	for (int i = 0; i < group1.size(); i++) cout << group1[i] << ' ';
	cout << "-1\n";
	for (int i = 0; i < group2.size(); i++) cout << group2[i] << ' ';
	cout << "-1\n";

	return 0;
}