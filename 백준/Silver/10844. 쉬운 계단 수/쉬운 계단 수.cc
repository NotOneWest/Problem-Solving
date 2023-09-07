#include <bits/stdc++.h>
#define pb push_back
#define mp make_pair
#define all(x) (x).begin(), (x).end()

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
const double PI = acos(-1);

ll dp[101]={0,}, arr[101][10]={0,};
ll MOD = 1000000000;

int main(){
  int n; cin >> n;
  for(int i=1; i<10; i++) arr[1][i]=1;
  for(int i=2; i<=n; i++){
    for(int j=0; j<10; j++){
      if(j==0) arr[i][j] = arr[i-1][j+1]%MOD;
      else if(j==9) arr[i][j] = arr[i-1][j-1]%MOD;
      else{
        arr[i][j] = arr[i-1][j-1]%MOD + arr[i-1][j+1]%MOD;
      }
    }
  }
  for(int i=0; i<10; i++) dp[n] += arr[n][i];
  cout << dp[n]%MOD;
	return 0;
}
