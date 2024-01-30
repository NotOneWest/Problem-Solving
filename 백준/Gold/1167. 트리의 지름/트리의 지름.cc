#include <iostream>
#include <vector>
#include <queue>
using namespace std;

struct Node {
	int go; // 다음 노드
	int w; // 가중치
};

vector<Node> alist[10001]; // 다음노드, 가중치 저장
int visited[10001]; // 노드 방문 체크
int maxCost = 0, deepestNode = 0; // 가중치 큰 노드 위치 저장

void bfs(int node, int cost) {
	// BFS를 위해 queue 생성
	queue<Node> q;
	q.push({node, cost}); // {시작 위치, 현재 가중치} push
	visited[node] = 1; // 방문 처리

	while (!q.empty()) {
		// 현재 노드 저장 후 추출
		Node curr = q.front(); 
		visited[curr.go] = 1; // 방문 처리
		q.pop();

		// queue의 처음 노드에서 갈 수 있는 곳 모두 push
		for (auto nxt : alist[curr.go]) {
			if (visited[nxt.go]) continue;
			// 다음 위치로 이동 시 가중치 : 현재까지 가중치 + 이동 가중치
			q.push({nxt.go, curr.w + nxt.w });

			// 최대 가중치를 가지는 위치 갱신
			if ((curr.w + nxt.w) > maxCost) {
				maxCost = (curr.w + nxt.w);
				deepestNode = nxt.go;
			}
		}
	}
}

void dfs(int node, int cost) {
	if (visited[node]) return;

	// 최대 가중치를 가지는 위치 갱신
	if (cost > maxCost) {
		maxCost = cost;
		deepestNode = node;
	}

	visited[node] = 1; // 방문 처리

	// 처음 노드에서 갈 수 있는 곳 모두 dfs
	for (auto nxt : alist[node]) {
		if (visited[nxt.go]) continue;
		// 다음 위치로 이동 시 가중치 : 현재까지 가중치 + 이동 가중치
		dfs(nxt.go, cost + nxt.w);
	}
}

int main() {
	int n; cin >> n;
	for (int i = 1; i < n; i++) {
		int p, c, w; cin >> p >> c >> w;
		alist[p].push_back({ c, w });
		alist[c].push_back({ p, w });
	}

	// 1번부터 탐색하며 최대 가중치를 갖는 노드 위치 탐색
	// dfs(1, 0);
	bfs(1, 0);

	// 방문 초기화 (노드 번호 범위 모르니 최대로 초기화)
	fill(visited, visited + 10001, 0); 
	// 가중치 초기화
	maxCost = 0;

	// 최대 가중치를 갖는 노드에서 트리의 지름 탐색
	bfs(deepestNode, 0);
	//dfs(deepestNode, 0);

	cout << maxCost;
	return 0;
}
