#include <iostream>
#include <vector>
using namespace std;
#define INF (1<<31)-1

int n, m;
vector<pair<int, int>> house;
vector<pair<int, int>> chicken;
vector<int> selected;
int res;

int calculate() {
	int sum = 0;
	for (int i = 0; i < house.size(); i++) {
		int dist = INF;
		for (int j = 0; j < selected.size(); j++) {
			pair<int, int> p1 = { house[i].first,house[i].second };
			pair<int, int> p2 = { chicken[selected[j]].first,chicken[selected[j]].second };
			int temp = abs(p1.first - p2.first) + abs(p1.second - p2.second);
			dist = min(dist, temp);
		}
		sum += dist;
	}
	return sum;
}

void solve(int index, int cnt) {
	if (cnt == m) {
		res = min(res, calculate());
		return;
	}
	if (index == chicken.size()) {
		return;
	}
	selected.push_back(index);
	solve(index + 1, cnt + 1);
	selected.pop_back();
	solve(index + 1, cnt);
}


int main() {
	res = INF;
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			int tmp;
			cin >> tmp;
			if (tmp == 1) {
				house.push_back({ i,j });
			}
			else if (tmp == 2) {
				chicken.push_back({ i,j });
			}
		}
	}
	solve(0, 0);
	cout << res;
}