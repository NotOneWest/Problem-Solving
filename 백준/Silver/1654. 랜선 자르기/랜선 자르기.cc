#include <bits/stdc++.h>
#define pb push_back
#define mp make_pair
#define all(x) (x).begin(), (x).end()

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
const double PI = acos(-1);

int main(){
  int k,n; cin >> k >> n;
  ll len[k];
  for(int i=0; i<k; i++){
    ll num; cin >> num;
    len[i]=num;
  }
  sort(len, len+k);
  ll low=1,high=len[k-1],mid,max_len=0;
  while(low<=high){
    mid=(low+high)/2;
    ll cnt=0;
    for(int i=0; i<k; i++){
      cnt+=(len[i]/mid);
    }
    if(cnt>=n){
      low=mid+1;
      if(mid>max_len) max_len=mid;
    }
    else high=mid-1;
  }
  if(n==1) cout << len[k-1] << '\n';
  else cout << max_len << '\n';
	return 0;
}
