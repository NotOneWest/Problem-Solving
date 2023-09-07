#include <bits/stdc++.h>
#define pb push_back
#define mp make_pair
#define all(x) (x).begin(), (x).end()

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
const double PI = acos(-1);

int drinks[10001], dp[10000];

void sum(int n){
	dp[0]=0;
	dp[1] = drinks[1];
	dp[2] = drinks[1]+drinks[2];
	for(int i=3; i<=n; i++){
		dp[i] = max({dp[i-2]+drinks[i], dp[i-3]+drinks[i-1]+drinks[i], dp[i-1]});
	}
}

int main(){
	int n; cin >> n;
	for(int i=1; i<=n; i++){
		cin >> drinks[i];
	}
	sum(n);
	cout << dp[n];
	return 0;
}
