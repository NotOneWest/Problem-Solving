#include <bits/stdc++.h>
#define pb push_back
#define mp make_pair
#define all(x) (x).begin(), (x).end()

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
const double PI = acos(-1);

int dp[12];
void sum(){
	dp[1]=1;
	dp[2]=2;
	dp[3]=4;
	for(int i=4; i<=11; i++){
		dp[i]=(dp[i-3]+dp[i-2]+dp[i-1]);
	}
} 

int main(){
	int n; cin >> n;
	sum();
	for(int i=0; i<n; i++){
		int a; cin >> a;
		cout << dp[a] << '\n';
	}
	return 0;
}
