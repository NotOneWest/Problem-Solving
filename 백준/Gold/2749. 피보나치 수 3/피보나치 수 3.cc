#include <bits/stdc++.h>
#define pb push_back
#define mp make_pair
#define all(x) (x).begin(), (x).end()

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
const double PI = acos(-1);

struct matrix{
  ll data[2][2];
};
int inf=1000000;

matrix matrix_mult(matrix temp, matrix m){
  matrix ans;
  ans.data[0][0]=(temp.data[0][0]*m.data[0][0]+temp.data[1][0]*m.data[0][1])%inf;
  ans.data[0][1]=(temp.data[0][1]*m.data[0][0]+temp.data[1][1]*m.data[0][1])%inf;
  ans.data[1][0]=(temp.data[0][0]*m.data[1][0]+temp.data[1][0]*m.data[1][1])%inf;
  ans.data[1][1]=(temp.data[0][1]*m.data[1][0]+temp.data[1][1]*m.data[1][1])%inf;
  return ans;
}

matrix matrix_div(matrix ans, ll n){
  if(n>1){
    ans=matrix_div(ans, n/2);
    ans=matrix_mult(ans, ans);
    if(n%2==1){
      matrix m;
      m.data[0][0]=1;
      m.data[0][1]=1;
      m.data[1][0]=1;
      m.data[1][1]=0;
      ans=matrix_mult(ans, m);
    }
  }
  return ans;
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
  ll n; cin >> n;
  matrix a;
  a.data[0][0]=1;
  a.data[0][1]=1;
  a.data[1][0]=1;
  a.data[1][1]=0;
  a=matrix_div(a,n);
  cout << a.data[1][0] << '\n';
	return 0;
}
