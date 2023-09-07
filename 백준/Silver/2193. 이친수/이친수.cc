#include <bits/stdc++.h>
#define pb push_back
#define mp make_pair
#define all(x) (x).begin(), (x).end()

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
const double PI = acos(-1);

ll dp[91];
void sum(){
	dp[1]=1;
	dp[2]=1;
	for(int i=3; i<91; i++){
		dp[i]=dp[i-1]+dp[i-2];
	}
}

int main(){
	int n; cin >> n;
	sum();
	cout << dp[n];
	return 0;
}
