#include <bits/stdc++.h>
#define pb push_back
#define mp make_pair
#define all(x) (x).begin(), (x).end()

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
const double PI = acos(-1);

int dp[50001];

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
  int n; cin >> n;
  dp[0]=0;
  dp[1]=1;
  for(int i=2; i<=n; i++){
    int k=sqrt(i);
    if(pow(k,2)==i) dp[i]=1;
    else dp[i]=i;
  }
  for(int i=1; i<=n; i++){
    for(int j=1; j<= sqrt(i); j++){
      dp[i]=min(dp[i], (dp[j*j]+dp[i-j*j]) );
    }
  }
  cout << dp[n] << '\n';
	return 0;
}
