#include <iostream>
using namespace std;

const int MAX = 100000;
int h, tree_size;
long long seg[MAX * 4];
long long arr[MAX + 1];

void init(int n) {
	h = 1;
	while (h < n)  h <<= 1;
	tree_size = h << 1;

	for (int i = h; i < tree_size; i++) {
		if ((i - h) >= n) seg[i] = 0;
		seg[i] = arr[i - h];
	}

	for (int i = (h-1); i >= 1; i--) seg[i] = seg[i << 1] + seg[i << 1 | 1];
}

void update(int idx, long long diff) {
	idx += h;
	while (1) {
		if (idx == 0) break;
		seg[idx] += diff;
		idx >>= 1;
	}
}

long long query(int l, int r) {
	long long res = 0;
	for (l += h, r += h; l < r; l >>= 1, r >>= 1) {
		if (l & 1) res += seg[l++];
		if (r & 1) res += seg[--r];
	}
	return res;
}

int main() {
	ios::sync_with_stdio(0); cin.tie(0);
	int n, q; cin >> n >> q;
	for (int i = 0; i < n; i++) cin >> arr[i];
	init(n);

	for (int i = 0; i < q; i++) {
		int x, y, a, b; cin >> x >> y >> a >> b;
		if (x > y) swap(x, y);
		cout << query(x-1, y) << '\n';
		update(a-1, ((long long) b) - arr[a-1]);
		arr[a - 1] = b;
	}
	return 0;
}
