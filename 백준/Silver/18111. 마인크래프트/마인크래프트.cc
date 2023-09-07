#include <bits/stdc++.h>
#define pb push_back
#define mp make_pair
#define all(x) (x).begin(), (x).end()

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
const double PI = acos(-1);

int block[501][501];

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
  int n,m,minh=257,maxh=0;
  ll b,needb,removeb,prevt=-1,prevh=-1;
  cin >> n >> m >> b;
  for(int i=0; i<n; i++){
    for(int j=0; j<m; j++){
      int h; cin >> h;
      block[i][j]=h;
      if(minh>h) minh=h;
      if(maxh<h) maxh=h;
    }
  }
  for(int t=minh; t<=maxh; t++){
    needb=0;
    removeb=0;
    for(int i=0; i<n; i++){
      for(int j=0; j<m; j++){
        if(block[i][j]>t) removeb += (block[i][j]-t);
        else needb += (t-block[i][j]);
      }
    }
    if(prevt==-1){
      if(needb <= (b+removeb)){
        prevt=(needb+removeb*2);
        prevh=t;
      }
    } else{
      if(needb <= (b+removeb)){
        if(prevt == (needb+removeb*2)){
          if(prevh<t){
            prevt=(needb+removeb*2);
            prevh=t;
          }
        }else if(prevt > (needb+removeb*2)){
          prevt=(needb+removeb*2);
          prevh=t;
        }
      }
    }
  }
  cout << prevt << ' ' << prevh << '\n';
	return 0;
}
