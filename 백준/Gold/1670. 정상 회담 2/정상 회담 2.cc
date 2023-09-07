#include <bits/stdc++.h>
#define pb push_back
#define mp make_pair
#define all(x) (x).begin(), (x).end()

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
const double PI = acos(-1);
const int MOD=987654321;


ll dp[10001];
void sum(){
	dp[0]=1;
	dp[2]=1;
	for(int i=4; i<=10000; i+=2){
		for(int j=0; j<i; j+=2){
			dp[i]+=dp[j]*dp[i-j-2];
			dp[i]=dp[i]%MOD;
		}
	}
}


int main(){
	int n; cin >> n;
	sum();
	cout << dp[n];
	return 0;
}
