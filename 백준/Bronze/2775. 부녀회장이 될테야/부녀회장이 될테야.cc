#include <bits/stdc++.h>
#define pb push_back
#define mp make_pair
#define all(x) (x).begin(), (x).end()

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
const double PI = acos(-1);

int sum[15][15];

int main(){
  ios_base::sync_with_stdio(false);
	cin.tie(NULL);
  for(int i=0; i<15; i++){
    for(int j=1; j<15; j++){
      if(i==0) sum[i][j]=j;
      else{
        if(j==1) sum[i][j]=1;
        else{
          for(int c=1; c<=j; c++){
            sum[i][j]+=sum[i-1][c];
          }
        }
      }
    }
  }
  int t; cin >> t;
  for(int i=0; i<t; i++){
    int k,n; cin >> k >> n;
    cout << sum[k][n] << '\n';
  }
  return 0;
}
