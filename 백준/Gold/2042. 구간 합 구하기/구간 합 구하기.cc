#include <iostream>
using namespace std;
#define ARRSIZE 1000000

long long tree[4 * ARRSIZE];
long long arr[ARRSIZE];
int n, m, k;
int start;

void init() {

	start = 2;
	while (start < n) {
		start *= 2;
	}
	for (int i = start; i < start + n; i++) {
		tree[i] = arr[i - start];
	}
	for (int i = start / 2; 1 <= i; i /= 2) {
		for (int j = i; j < i * 2; j++) {
			tree[j] = tree[j * 2] + tree[j * 2 + 1];
		}
	}
}

void update(int index, long long dif) {
	index += start;
	tree[index] += dif;
	index /= 2;
	while (1 <= index) {
		tree[index] += dif;
		index /= 2;
	}
}

long long query(int left, int right) {
	left += start;
	right += start + 1;
	long long sum = 0;
	while (left != right) {
		if (left % 2 == 1) {
			sum += tree[left];
			left++;
		}
		if (right % 2 == 1) {
			right--;
			sum += tree[right];
		}
		left /= 2;
		right /= 2;
	}
	return sum;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> n >> m >> k;
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}
	init();
	for (int i = 0; i < m + k; i++) {
		int a, b;
		long long c;
		cin >> a >> b >> c;
		if (a == 1) {
			long long dif = c - arr[b - 1];
			arr[b - 1] = c;
			update(b - 1, dif);
		} 
		else {
			cout << query(b - 1, c - 1) << "\n";
		}
	}
}