#include <bits/stdc++.h>
#define pb push_back
#define mp make_pair
#define all(x) (x).begin(), (x).end()

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
const double PI = acos(-1);

int n,s,arr[21],cnt=0;

void func(int use, int sum){
  if(use==n){
    if(sum==s) cnt++;
    return;
  }
  func(use+1, sum); // 지금 idx 숫자가 사용 안된 경우 -> use는 ++이나 sum에는 안더해줌
  func(use+1, sum+arr[use]); // 지금 idx 숫자 사용된 경우
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
  cin >> n >> s;
  for(int i=0; i<n; i++) cin >> arr[i];
  func(0,0);
  if(s==0) cnt--; // 크기가 양수 -> 공집합 제외
  cout << cnt << '\n';
	return 0;
}
