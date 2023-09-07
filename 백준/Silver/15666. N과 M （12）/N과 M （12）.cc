#include <bits/stdc++.h>
#define pb push_back
#define mp make_pair
#define all(x) (x).begin(), (x).end()

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
const double PI = acos(-1);

int n,m,sequence[9]={0,},visited[9]={0,};
vector<int> num;

void dfs(int start, int cnt){
  if(cnt==m){
    for(int i=0; i<m; i++){
      cout << sequence[i] << ' ';
    }
    cout << '\n';
  } else{
    int prev=-1;
    for(int i=start; i<=n; i++){
      if(num[i-1]!=prev){
        sequence[cnt]=num[i-1];
        prev=sequence[cnt];
        dfs(i,cnt+1);
      }
    }
  }
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
  cin >> n >> m;
  for(int i=1; i<=n; i++){
    int x; cin >> x;
    num.pb(x);
  }
  sort(all(num));
  dfs(1,0);
	return 0;
}
