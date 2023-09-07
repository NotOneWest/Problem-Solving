#include <bits/stdc++.h>
#define pb push_back
#define mp make_pair
#define all(x) (x).begin(), (x).end()

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
const double PI = acos(-1);

int n, num[12], oper[4], Max=-1000000000, Min=1000000000;

void func(int sum, int k){
  if(k==n){
    Max=max(Max,sum);
    Min=min(Min,sum);
    return;
  }
  for(int i=0; i<4; i++){
    if(oper[i]==0) continue;
    oper[i]--;
    if(i==0) func(sum+num[k], k+1);
    if(i==1) func(sum-num[k], k+1);
    if(i==2) func(sum*num[k], k+1);
    if(i==3) func(sum/num[k], k+1);
    oper[i]++;
  }
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
  cin >> n;
  for(int i=0; i<n; i++) cin >> num[i];
  for(int i=0; i<4; i++) cin >> oper[i];
  func(num[0],1); // 곱하기와 나누기가 있으므로 처음 스타트를 0,0이 아니라 num[0],1 로 했어야함
  cout << Max << '\n';
  cout << Min << '\n';
	return 0;
}
