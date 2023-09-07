#include <bits/stdc++.h>
#define pb push_back
#define mp make_pair
#define all(x) (x).begin(), (x).end()

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
const double PI = acos(-1);
 
int dp[1000001];
void count(int n){
	dp[1]=0;
	dp[2]=1;
	dp[3]=1;
	for(int i=4; i<=n; i++){ // 조건이 겹치는 경우가 있어 최소를 골라내야한다. 
		dp[i]=dp[i-1]+1;
		if(i%2==0 && (dp[i/2]+1)<dp[i]) dp[i]=(dp[i/2]+1);
		if(i%3==0 && (dp[i/3]+1)<dp[i]) dp[i]=(dp[i/3]+1);
	}
}


int main(){
	int n; cin >> n;
	count(n);
	cout << dp[n];	
	return 0;
}
