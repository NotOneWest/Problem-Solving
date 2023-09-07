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
ll INF=1000000007;

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

int main(){ // Fa까지 홀수 ->F(홀수-1까지 합)+1
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
  ll num; cin >> num;
  if(num%2==0) num--;
  Matrix standard, ans;
  standard.data[0][0]=1;
  standard.data[0][1]=1;
  standard.data[1][0]=1;
  standard.data[1][1]=0;
  ans=divide(standard,num+1);
  cout << ans.data[0][1] << '\n';
	return 0;
}
