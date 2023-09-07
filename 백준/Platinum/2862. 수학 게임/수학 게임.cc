#include <bits/stdc++.h>
#define pb push_back
#define mp make_pair
#define all(x) (x).begin(), (x).end()

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
const double PI = acos(-1);

ll dp[73]={1,1};

ll small(ll n){
	for(int i=1; i<=73; i++){
		if(dp[i]==n) return n;
		if(dp[i+1]>n) return small(n-dp[i]);
	}
}

int main(){
	ll n; cin >> n;
	for(int i=2; i<=73; i++) dp[i]=dp[i-2]+dp[i-1];
	cout << small(n);
	return 0;
}
// 규칙을 찾아본 결과 n 이 피보나치 수이면 n 개를 가져가야하고,
// 아니면 그보다 적게 가져갈 수 있다.
// --> n보다 작은 것 중 가장 큰 피보나치 수가 되도록 가져오면 된다.
// --> 그게 안된다면, 두번째 턴에서 가져갈 수 있는 최대의 수ㄹ를 가져가는 경우가 
//     n 보다 작은 것 중 가장 큰 피보나치 수가 안되도록 하면 된다.
// 따라서 k+1 번째가 n 보다 큰 첫 피보나치 수라면, (n - k번째 피보나치 수) 개만큼 가져가면 된다.
// 따라서 n-fibnum(k) 를 탐색해주면 된다. -> dp  