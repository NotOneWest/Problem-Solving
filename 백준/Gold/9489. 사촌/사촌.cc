#include <bits/stdc++.h>
#define pb push_back
#define mp make_pair
#define all(x) (x).begin(), (x).end()

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
const double PI = acos(-1);

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
  while(1){
    int n,k; cin >> n >> k;
    if(n==0 && k==0) break;
    int num[1001]={-1}, parent[1001]={-1}, parent_idx=-1, k_idx=0;
    for(int i=1; i<=n; i++){
      cin >> num[i];
      if(num[i]==k) k_idx=i;
      if(num[i]!=(num[i-1]+1)) parent_idx++;
      parent[i]=parent_idx;
    }
    int ans=0;
    for(int i=1; i<=n; i++){
      if(parent[k_idx]!=parent[i] && parent[parent[k_idx]]==parent[parent[i]]) ans++;
    }
    cout << ans << '\n';
  }
	return 0;
}
