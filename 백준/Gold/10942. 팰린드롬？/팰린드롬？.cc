#include <bits/stdc++.h>
#define pb push_back
#define mp make_pair
#define all(x) (x).begin(), (x).end()

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
const double PI = acos(-1);

int dp[2001][2001], num[2001];

void palin(int n){
	for(int i=1; i<=n; i++){
		dp[i][i]=1;
	}
	for(int i=1; i<n; i++){
		if(num[i]==num[i+1]) dp[i][i+1]=1;
	}
	for(int i=2; i<n; i++){
		for(int j=1; j<=(n-i); j++){
			if(num[j]==num[j+i] && dp[j+1][j+i-1]==1) dp[j][j+i]=1;
		}
	}
}

int main(){
	int n; cin >> n;
	for(int i=1; i<=n; i++) scanf("%d", &num[i]);
	palin(n);
	int m; cin >> m;
	for(int p=0; p<m; p++){
		int a,b;
		scanf("%d %d", &a, &b);
		printf("%d\n", dp[a][b]);
	}
	return 0;
}