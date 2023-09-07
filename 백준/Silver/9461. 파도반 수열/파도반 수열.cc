#include <bits/stdc++.h>
#define pb push_back
#define mp make_pair
#define all(x) (x).begin(), (x).end()

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
const double PI = acos(-1);

ll dp[101];
void p_n(){
  dp[1]=1;
  dp[2]=1;
  dp[3]=1;
  for(int i=4; i<101; i++){
    dp[i]=(dp[i-2]+dp[i-3]);
  }
}


int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
  int t; cin >> t;
  p_n();
  for(int i=0; i<t; i++){
    int n; cin >> n;
    cout << dp[n] << '\n';
  }
	return 0;
}
