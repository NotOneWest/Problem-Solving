#include <bits/stdc++.h>
#define pb push_back
#define mp make_pair
#define all(x) (x).begin(), (x).end()

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
const double PI = acos(-1);

ll num[100001], dp[100001];

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
  int n,m,sum=0; cin >> n >> m;
  for(int i=0; i<n; i++){
    ll number; cin >> number;
    num[i+1]=number;
    sum+=number;
    dp[i+1]=sum;
  }
  for(int i=0; i<m; i++){
    int x,y; cin >> x >> y;
    cout << dp[y]-dp[x-1] << '\n';
  }
	return 0;
}
