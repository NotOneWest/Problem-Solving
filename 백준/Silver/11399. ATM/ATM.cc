#include <bits/stdc++.h>
#define pb push_back
#define mp make_pair
#define all(x) (x).begin(), (x).end()

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
const double PI = acos(-1);

int pi[1001];

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
  int n,ans=0; cin >> n;
  for(int i=0; i<n; i++){
    int time; cin >> time;
    pi[i]=time;
  }
  sort(pi,pi+n);
  for(int i=0; i<n; i++){
    ans+=(pi[i]*(n-i));
  }
  cout << ans << '\n';
	return 0;
}
