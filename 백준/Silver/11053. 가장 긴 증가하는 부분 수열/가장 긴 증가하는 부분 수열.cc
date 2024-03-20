#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int arr[2000];
int dp[2000];
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int n;
	cin >> n;
	int max = 0;
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}
	for (int i = 0; i < n; i++) {
		dp[i] = 1;
		for (int j = 0; j < i; j++) {
			if (arr[i] > arr[j]) {
				if (dp[j] + 1 > dp[i])	dp[i] = dp[j] + 1;
			}
		}
		if (max < dp[i])	max = dp[i];
	}
	cout << max;
}