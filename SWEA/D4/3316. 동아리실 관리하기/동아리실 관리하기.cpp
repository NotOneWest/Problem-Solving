#include <iostream>
#include <string>
using namespace std;

int dp[10000][16];

int main(int argc, char** argv)
{
	int test_case;
	int T; cin >> T;

	for (test_case = 1; test_case <= T; ++test_case){
		string s; cin >> s;

		for (int day = 0; day < 10000; day++) {
			for (int i = 0; i < 16; i++) dp[day][i] = 0;
		}

		for (int day = 0; day < s.length(); day++) {
			// 책임자
			int today = (1 << (s[day] - 'A'));

			for (int prev = 1; prev < 16; prev++) {
				if (day == 0) {
					// 첫날은 A가 열쇠를 가지고 있음
					// A와 책임자가 모두 속해 있는 경우만 OK
					if ((today & prev) != 0 && (prev & 1) != 0) dp[day][prev] = 1;
				} else {
					// 전날에 가능한 case 중 탐색
					if (dp[day - 1][prev] != 0) {
						for (int now = 1; now < 16; now++) {
							// 책임자가 속하고, 전날 온 사람이 포함되어 있으면 OK
							if ((today & now) != 0 && (now & prev) != 0) {
								// 현재 경우 (day, now)에 전날까지 가능한 경우 모두 더함
								dp[day][now] += dp[day - 1][prev];
								dp[day][now] %= 1000000007;
							}
						}
					}
				}
			}
		}

		int ans = 0;
		for (int i = 1; i < 16; i++) {
			ans += dp[s.length() - 1][i];
			ans %= 1000000007;
		}

		cout << "#" << test_case << ' ' << ans << '\n';
	}
	return 0;
}