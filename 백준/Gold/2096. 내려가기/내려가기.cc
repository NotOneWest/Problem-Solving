#include <bits/stdc++.h>
#define pb push_back
#define mp make_pair
#define all(x) (x).begin(), (x).end()

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
const double PI = acos(-1);

int num[3];
int dp[2][3], dp2[2][3]; // 메모리 초과가 난다. -> 100001 개 준비할 필요 x 2개로 줄바꿔가며 저장. 

int main(){
	int n; cin >> n;
	for(int i=1; i<=n; i++){
		cin >> num[0] >> num[1] >> num[2];
		for(int j=0;j<3; j++){
			if(j==0){
				dp[1][j]=max(dp[0][j],dp[0][j+1])+num[j];
				dp2[1][j]=min(dp2[0][j],dp2[0][j+1])+num[j];
			}
			else if(j==2){
				dp[1][j]=max(dp[0][j-1],dp[0][j])+num[j];
				dp2[1][j]=min(dp2[0][j-1],dp2[0][j])+num[j];
			}
			else{
				dp[1][j]=max({dp[0][j-1],dp[0][j],dp[0][j+1]})+num[j];
				dp2[1][j]=min({dp2[0][j-1],dp2[0][j],dp2[0][j+1]})+num[j];
			}
		}
		for (int j = 0; j < 3; j++) {
			dp[0][j] = dp[1][j];
			dp2[0][j] = dp2[1][j];
		}
	}
	cout << max({dp[1][0],dp[1][1],dp[1][2]}) << ' ' << min({dp2[1][0],dp2[1][1],dp2[1][2]});
	return 0;
}
