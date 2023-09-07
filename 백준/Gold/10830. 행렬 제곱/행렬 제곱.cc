#include <bits/stdc++.h>
#define pb push_back
#define mp make_pair
#define all(x) (x).begin(), (x).end()

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
const double PI = acos(-1);

ll INF=1000,n,b;
struct Matrix{
  ll data[6][6];
};

Matrix mult(Matrix temp, Matrix m){
  Matrix ans;
  for(ll i=0; i<n; i++){
    for(ll j=0; j<n; j++) ans.data[i][j]=0;
  }
  for(ll i=0; i<n; i++){
    for(ll j=0; j<n; j++){
      for(ll c=0; c<n; c++){
        ans.data[i][j]+=(temp.data[i][c]*m.data[c][j]);
      }
      ans.data[i][j]%=INF;
    }
  }
  return ans;
}

Matrix divide(Matrix ans, Matrix start, ll a){
  if(a>1){
    ans=divide(ans, start, a/2);
    ans=mult(ans,ans);
    if(a%2==1){
      ans=mult(ans,start);
    }
  } else{
    for(ll i=0; i<n; i++){
      for(ll j=0; j<n; j++){
        ans.data[i][j]%=INF;
      }
    }
  }
  return ans;
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
  cin >> n >> b;
  Matrix a,start;
  for(ll i=0; i<n; i++){
    for(ll j=0; j<n; j++){
      ll x; cin >> x;
      a.data[i][j]=x;
    }
  }
  start=a;
  a=divide(a, start, b);
  for(ll i=0; i<n; i++){
    for(ll j=0; j<n; j++) cout << a.data[i][j] << ' ';
    cout << '\n';
  }
	return 0;
}
