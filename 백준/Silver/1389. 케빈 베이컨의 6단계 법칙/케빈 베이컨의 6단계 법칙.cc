#include <bits/stdc++.h>
#define pb push_back
#define mp make_pair
#define all(x) (x).begin(), (x).end()

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
const double PI = acos(-1);

int n, fw[101][101];

void bfs(){
  for(int k=1; k<=n; k++){
    for(int i=1; i<=n; i++){
      if(i==k) continue;
      for(int j=1; j<=n; j++){
        if(fw[i][j] > (fw[i][k]+fw[k][j])) fw[i][j]=(fw[i][k]+fw[k][j]);
      }
    }
  }
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
  int m; cin >> n >> m;
  for(int i=0; i<m; i++){
    int a,b; cin >> a >> b;
    fw[a][b]=1;
    fw[b][a]=1;
  }
  for(int i=1; i<=n; i++){
    for(int j=1; j<=n; j++){
      if(i!=j && fw[i][j]==0) fw[i][j]=5001;
    }
  }
  bfs();
  int now=5001, sum=5001;
  for(int i=1; i<=n; i++){
    int now_sum=0;
    for(int j=1; j<=n; j++){
      now_sum+=fw[i][j];
    }
    if(now_sum < sum){
      sum=now_sum;
      now=i;
    } else if(now_sum==sum){
      sum=now_sum;
      if(i<now) now=i;
    }
  }
  cout << now << '\n';
	return 0;
}
