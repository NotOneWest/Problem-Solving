#include <bits/stdc++.h>
#define pb push_back
#define mp make_pair
#define all(x) (x).begin(), (x).end()

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
const double PI = acos(-1);

int n, arr[1001], dp[1001], dp_reverse[1001];

void func(){
  for(int i=0; i<n; i++){ // 앞에서 부터 작은 것 있으면 dp[작은 것]+1
    dp[i]=1; // 맨 처음에는 자기 자신인 1
    for(int j=0; j<=i; j++){
      if(arr[j]<arr[i]) dp[i]=max(dp[i], dp[j]+1);
    }
  }
  for(int i=n-1; i>=0; i--){ // 뒤에서 부터 판단
    dp_reverse[i]=1;
    for(int j=n-1; j>=i; j--){
      if(arr[j]<arr[i]) dp_reverse[i]=max(dp_reverse[i], dp_reverse[j]+1);
    }
  }
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
  cin >> n;
  for(int i=0; i<n; i++) cin >> arr[i];
  func();
  int ans=0;
  for(int i=0; i<n; i++) ans=max(ans, dp[i]+dp_reverse[i]-1);
  // 3,3이면 3번이 2번 포함 -> -1 해줘야함...
  cout << ans << '\n';
	return 0;
}
