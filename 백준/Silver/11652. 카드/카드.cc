#include <bits/stdc++.h>
#define pb push_back
#define mp make_pair
#define all(x) (x).begin(), (x).end()

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
const double PI = acos(-1);

ll a[100001];
ll now=0,pre=0;

int main(){
  ios_base::sync_with_stdio(false);
	cin.tie(NULL);
  int n,cnt=1,ans=0; cin >> n;
  for(int i=0; i<n; i++){
    ll num; cin >> num;
    a[i]=num;
  }
  sort(a,a+n);
  now=a[0];
  pre=now;
  for(int i=1; i<n; i++){
    if(now==a[i]){
      cnt++;
    } else{
      if(ans<cnt){
        ans=cnt;
        pre=now;
      }
      if(ans==cnt){
        if(pre>a[i]) pre=a[i];
      }
      now=a[i];
      cnt=1;
    }
  }
  if(ans<cnt) pre=now;
  cout << pre << '\n';
	return 0;
}
