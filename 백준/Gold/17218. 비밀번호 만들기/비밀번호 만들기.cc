#include <bits/stdc++.h>
#define pb push_back
#define mp make_pair
#define all(x) (x).begin(), (x).end()

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
const double PI = acos(-1);

string dp[41][41];

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
  string a,b; cin >> a >> b;
  bool check=false;
  for(int i=0; i<a.length(); i++){
    if(a[i]==b[0] || check){
      dp[i][0]=b[0];
      check=true;
    }
  }
  check=false;
  for(int i=0; i<b.length(); i++){
    if(a[0]==b[i] || check){
      dp[0][i]=a[0];
      check=true;
    }
  }
  for(int i=1; i<a.length(); i++){
    for(int j=1; j<b.length(); j++){
      if(a[i]==b[j]){
        dp[i][j]=(dp[i-1][j-1]+a[i]);
      }
      else{
        if(dp[i][j-1].length() > dp[i-1][j].length()) dp[i][j]=dp[i][j-1];
        else dp[i][j]=dp[i-1][j];
      }
    }
  }
  cout << dp[a.length()-1][b.length()-1] << '\n';
	return 0;
}
