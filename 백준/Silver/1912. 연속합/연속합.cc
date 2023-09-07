#include <bits/stdc++.h>
#define pb push_back
#define mp make_pair
#define all(x) (x).begin(), (x).end()

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
const double PI = acos(-1);

int dp[100001], num[100001];

int main(){
	int n; cin >> n;
	for(int i=1; i<=n; i++) cin >> num[i];
	int maximum=-1000;
	dp[1]=num[1];
	for(int i=2; i<=n; i++){
		dp[i]=max(num[i],dp[i-1]+num[i]); 
		// 쭉 더하다가 안더하는게  더 크다면
		//그 자리에 있는 수를 저장해 더해가는 위치 초기화. 
		maximum=max(dp[i],maximum);
	}
	maximum=max(dp[1],maximum); // 제일 처음 수에서 안더하는게 최대일 수 있음. 
	cout << maximum;
	return 0;
}
