#include <bits/stdc++.h>
#define pb push_back
#define mp make_pair
#define all(x) (x).begin(), (x).end()

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
const double PI = acos(-1);

int a[101][101], b[101][101], ans[101][101];

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
  int n,m,k; cin >> n >> m;
  for(int i=0; i<n; i++){
    for(int j=0; j<m; j++){
      int num; cin >> num;
      a[i][j]=num;
    }
  }
  cin >> m >> k;
  for(int i=0; i<m; i++){
    for(int j=0; j<k; j++){
      int num; cin >> num;
      b[i][j]=num;
    }
  }
  for(int i=0; i<n; i++){
    for(int j=0; j<k; j++){
      for(int x=0; x<m; x++) ans[i][j]+=(a[i][x]*b[x][j]);
    }
  }
  for(int i=0; i<n; i++){
    for(int j=0; j<k; j++) cout << ans[i][j] << ' ';
    cout << '\n';
  }
	return 0;
}
