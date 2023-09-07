#include <bits/stdc++.h>
#define pb push_back
#define mp make_pair
#define all(x) (x).begin(), (x).end()

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
const double PI = acos(-1);

ll dp[1000001];

int main(){
  int n; cin >> n;
  dp[1]=1;
  dp[2]=2;
  for(int i=3; i<=n; i++){
    dp[i] = (dp[i-1]+dp[i-2])%15746;
  }
  cout << dp[n]%15746;
	return 0;
}
