#include <bits/stdc++.h>
#define pb push_back
#define mp make_pair
#define all(x) (x).begin(), (x).end()

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
const double PI = acos(-1);

int n, s[21][21], team[21], ans=1000000000;

void func(int player, int k){
  if(k==n/2){
    int start=0, link=0;
    if(team[1]==1){
      for(int i=1; i<=n; i++){
        for(int j=1; j<=n; j++){
          if(team[i]==1 && team[j]==1) start+=s[i][j];
          if(team[i]==0 && team[j]==0) link+=s[i][j];
        }
      }
      ans=min(ans,abs(start-link));
    }
    return;
  }
  for(int i=player; i<=n; i++){
    team[i]=1;
    func(i+1,k+1);
    team[i]=0;
  }

}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
  cin >> n;
  for(int i=1; i<=n; i++){
    for(int j=1; j<=n; j++) cin >> s[i][j];
  }
  func(1,0);
  cout << ans << '\n';
	return 0;
}
