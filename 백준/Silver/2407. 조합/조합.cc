#include <bits/stdc++.h>
#define pb push_back
#define mp make_pair
#define all(x) (x).begin(), (x).end()

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
const double PI = acos(-1);

string dp[101][101];
string biginteger(string a, string b){
  string res;
	int size = a.size(), carry = 0;
	if(size > b.size()){
		int size2 = b.size();
		for(int i=0; i<size-size2; i++) b = '0' + b;
	}
	else if(size < b.size()) {
		for(int i=0; i<b.size()-size; i++) a = '0' + a;
		size = b.size();
	}
	for(int i=size-1; i>=0; i--){
		string c;
		c = to_string(a[i] + b[i] - '0' - '0' + carry);
		if(c.size() == 2){
			carry = c[0]-'0';
			res = c[1] + res;
		}
		else{
			res = c[0] + res;
			carry = 0;
		}
	}
	if (carry == 1) res = to_string(carry) + res;
	return res;
};
void combination(){
  dp[0][0]='0';
  dp[1][0]='1';
  dp[1][1]='1';
  for(int i=2; i<101; i++) dp[i][0]='1';
  for(int i=2; i<101; i++){
    for(int j=1; j<=i; j++){
      dp[i][j]=biginteger(dp[i-1][j-1], dp[i-1][j]);
    }
  }
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
  int n,m; cin >> n >> m;
  combination();
  cout << dp[n][m] << '\n';
	return 0;
}
