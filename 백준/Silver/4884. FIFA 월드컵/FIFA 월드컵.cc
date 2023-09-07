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
  while(true){
    ll g,a,t,d,x=0; cin >> g >> t >> a >> d;
    if(g==-1 && a==-1 && t==-1 && d==-1) break;
    x+=((t*(t-1))/2)*g;
    ll nt=(a*g)+d;
    ll game=1;
    while(game<nt){
      x+=game;
      game*=2;
    }
    cout << g << '*' << a << '/' << t << '+' << d << '=' << x << '+' << (game-nt) << '\n';
  }
	return 0;
}
