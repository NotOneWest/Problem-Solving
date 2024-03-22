#include <iostream>
using namespace std;

int n, v;
int arr[50];

int solve(int middle, int end) {
	int sum = 0;
	sum += middle / 2;
	if (middle % 2 == 1) {
		sum++;
	}
	sum += (end - middle) / 2;
	if ((end - middle) % 2) {
		sum++;
	}
	return sum;
}

int main() {
	int res = 10000;
	cin >> n >> v;
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}
	for (int i = 0; i < n; i++) {
		for (int j = i + 1; j < n; j++) {
			if (v <= abs(arr[i] - arr[j])) {
				res = min(res, solve(i, j));
			}
		}
	}
	if (res == 10000) {
		cout << n;
	}
	else {
		cout << res + 1;
	}
}