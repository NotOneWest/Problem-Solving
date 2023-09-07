#include <bits/stdc++.h>
#define pb push_back
#define mp make_pair
#define all(x) (x).begin(), (x).end()

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
const double PI = acos(-1);

int n,m,arr[8],num[8];

void func(int cnt){
  if(cnt==m){
    for(int i=0; i<m; i++) cout << arr[i] << ' ';
    cout << '\n';
    return;
  }
  int prev=-1; // 중복 없애기 위해 이전에 고른 수를 저장...
  for(int i=0; i<n; i++){
    if(prev!=num[i]){
      arr[cnt]=num[i];
      prev=num[i];
      func(cnt+1);
    }
  }
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
  cin >> n >> m;
  for(int i=0; i<n; i++) cin >> num[i];
  sort(num, num+n);
  func(0);
	return 0;
}
