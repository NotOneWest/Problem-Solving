#include <bits/stdc++.h>
#define pb push_back
#define mp make_pair
#define all(x) (x).begin(), (x).end()

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
const double PI = acos(-1);

string dp[10001];
string biginteger(string a, string b){
  string res;
	int asize=a.length(), bsize=b.length();
  int i, carry=0;
  for(i=0; i<bsize; i++){
    char c=(a[i]-'0'+b[i]+carry);
    carry=0;
    if(c>'9'){
      carry=1;
      c-=10;
    }
    res+=c;
  }
  for(int j=i; j<asize; j++){
    char c=a[j]+carry;
    carry=0;
    if(c>'9'){
      carry=1;
      c-=10;
    }
    res+=c;
  }
  if(carry==1) res+='1';
	return res;
};

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
  int n; cin >> n;
  dp[0]="0";
  dp[1]="1";
  for(int i=2; i<=n; i++) dp[i]=biginteger(dp[i-1], dp[i-2]);
  for(int i=dp[n].size(); i>0; i--){
    cout << dp[n][i-1];
  }
	return 0;
}
