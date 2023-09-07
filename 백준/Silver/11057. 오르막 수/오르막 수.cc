#include <bits/stdc++.h>
#define pb push_back
#define mp make_pair
#define all(x) (x).begin(), (x).end()

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
const double PI = acos(-1);

int mod=10007, dp[1001][10];

void upnum(int n){
	for(int i=1; i<=n; i++){
		for(int j=0; j<10; j++){
			if(i==1) dp[i][j]=1;
			else{
				for(int k=j; k<10; k++){
					dp[i][j]+=dp[i-1][k];
				}
				dp[i][j]=dp[i][j]%mod;	
			}
		}
	}
}

int main(){
	int n; cin >> n;
	upnum(n);
	ll sum=0;
	for(int i=0; i<10; i++) sum+=dp[n][i];
	cout <<sum%mod;
	return 0;
}
