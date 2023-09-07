#include <bits/stdc++.h>
#define pb push_back
#define mp make_pair
#define all(x) (x).begin(), (x).end()

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
const double PI = acos(-1);

int dp[100001];

void coins(int money){
	dp[1]=1;
	dp[2]=1;
	dp[3]=2;
	dp[4]=2;
	dp[5]=1;
	dp[6]=2;
	dp[7]=1;
	for(int i=8; i<=money; i++){
		dp[i] = min({dp[i-1]+1, dp[i-2]+1, dp[i-5]+1, dp[i-7]+1});
	}
}

int main(){
	int money; cin >> money;
	coins(money);
	cout << dp[money];
	return 0;
}
