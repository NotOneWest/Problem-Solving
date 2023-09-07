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
  int n,ans=0; cin >> n;
  if(n==1) ans=1;
  else{
    int range=0;
    for(int i=1; i; i++){
      if((n-1)>6*range && (n-1)<=6*(range+i)){
        ans=i+1;
        break;
      } else{
        range = range+i;
      }
    }
  }
  cout << ans << '\n';
  return 0;
}
