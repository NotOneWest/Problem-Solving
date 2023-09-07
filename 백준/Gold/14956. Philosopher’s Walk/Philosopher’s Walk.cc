#include <bits/stdc++.h>
#define pb push_back
#define mp make_pair
#define all(x) (x).begin(), (x).end()

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
const double PI = acos(-1);

pii hilbert(int n, int m){
  pii p;
  if(n==2){ // x,y 좌표를 중간에 바꿔서 생각했었음...
    if(m==0) p=mp(1,1);
    else if(m==1) p=mp(1,2);
    else if(m==2) p=mp(2,2);
    else p=mp(2,1);
    return p;
  }
  int half=n/2, range=(half*half);
  if(m<range){
    pii pp=hilbert(half, m);
    p=mp(pp.second, pp.first);
  }
  else if(m<range*2){
    pii pp=hilbert(half, m-range);
    p=mp(pp.first, pp.second+half);
  }
  else if(m<range*3){
    pii pp=hilbert(half, m-range*2);
    p=mp(pp.first+half, pp.second+half);
  }
  else{
    pii pp=hilbert(half, m-range*3);
    p=mp(2*half-pp.second+1, half-pp.first+1);
  }
  return p;
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
  int n,m; cin >> n >> m;
  m--;
  pii ans=hilbert(n, m);
  cout << ans.first << ' ' << ans.second << '\n';
	return 0;
}
