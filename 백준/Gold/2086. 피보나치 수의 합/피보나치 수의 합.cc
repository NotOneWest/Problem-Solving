#include <bits/stdc++.h>
#define pb push_back
#define mp make_pair
#define all(x) (x).begin(), (x).end()

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
const double PI = acos(-1);

struct Matrix{
  ll data[2][2];
};
ll INF=1000000000;

Matrix mult(Matrix temp, Matrix m){
  Matrix ans;
  ans.data[0][0]=(temp.data[0][0]*m.data[0][0]+temp.data[1][0]*m.data[0][1])%INF;
  ans.data[0][1]=(temp.data[0][1]*m.data[0][0]+temp.data[1][1]*m.data[0][1])%INF;
  ans.data[1][0]=(temp.data[0][0]*m.data[1][0]+temp.data[1][0]*m.data[1][1])%INF;
  ans.data[1][1]=(temp.data[0][1]*m.data[1][0]+temp.data[1][1]*m.data[1][1])%INF;
  return ans;
}

Matrix divide(Matrix ans, ll n){
  if(n>1){
    ans=divide(ans,n/2);
    ans=mult(ans,ans);
    if(n%2==1){
      Matrix m;
      m.data[0][0]=1;
      m.data[0][1]=1;
      m.data[1][0]=1;
      m.data[1][1]=0;
      ans=mult(ans,m);
    }
  }
  return ans;
}

int main(){ // F(a~b)->F(b+2)-F(a+1)
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
  ll a,b; cin >> a >> b;
  Matrix standard, start, end;
  standard.data[0][0]=1;
  standard.data[0][1]=1;
  standard.data[1][0]=1;
  standard.data[1][1]=0;
  start=divide(standard,a+1);
  end=divide(standard,b+2);
  cout << (end.data[0][1]-start.data[0][1]+INF)%INF << '\n';
	return 0;
}
