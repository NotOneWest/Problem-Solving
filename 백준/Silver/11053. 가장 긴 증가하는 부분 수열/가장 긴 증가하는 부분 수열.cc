#include <bits/stdc++.h>
#define pb push_back
#define mp make_pair
#define all(x) (x).begin(), (x).end()

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
const double PI = acos(-1);

int dp[1001], num[1001]; 

int main(){
	int n; cin >> n;
	for(int i=1; i<=n; i++) cin >> num[i];
	
	dp[1]=1;
	for(int i=2; i<=n; i++){
		dp[i]=1;
		for(int j=1; j<i; j++){
			if(num[i]>num[j]){
				dp[i]=max(dp[j]+1,dp[i]);
			}
		}
	}
	int maximum=0;
	for(int i=1;i<=n;i++){
		maximum=max(maximum,dp[i]);
	}
	cout << maximum;
	return 0;
}
