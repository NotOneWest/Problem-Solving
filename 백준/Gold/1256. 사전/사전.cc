#include <bits/stdc++.h>
#define pb push_back
#define mp make_pair
#define all(x) (x).begin(), (x).end()

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
const double PI = acos(-1);
const ll MAX = 1000000000;
ll dp[201][201];

void com(){
	for(int i=0; i<=200; i++){
		for(int j=0; j<=i; j++){
			if(i==j || j==0) dp[i][j]=1;
			else{
				dp[i][j] = min(dp[i-1][j-1] + dp[i-1][j], MAX);
			}
		}
	}
}

int main(){
	int n,m; 
	ll k; cin >> n >> m >> k;
	com();
	if(k>dp[n+m][n]) cout << -1;
	else{
		string s;
		while(n!=0 && m!=0){
			if(k>dp[n+m-1][m]){
				s+='z';
				k-=dp[n+m-1][m];
				m--;
			}
			else{
				s+='a';
				n--;
			}
		}
		if(n==0){
			for(int i=0; i<m; i++) s+='z';
		}
		else for(int i=0; i<n; i++) s+='a';
		cout << s;
	}
	return 0;
}