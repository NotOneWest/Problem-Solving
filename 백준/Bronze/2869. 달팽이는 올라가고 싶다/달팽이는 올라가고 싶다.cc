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
  int a,b,v,ans=0; cin >> a >> b >> v;
  if((v-a)==0) ans=1;
  else{
    ans=1;
    ans += (v-a)/(a-b);
    if(((v-a)%(a-b))!=0) ans++;
  }
  cout << ans << '\n';
  return 0;
}
