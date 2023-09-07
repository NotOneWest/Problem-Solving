#include <bits/stdc++.h>
#define pb push_back
#define mp make_pair
#define all(x) (x).begin(), (x).end()

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
const double PI = acos(-1);

int n,m,sequence[9]={0,},visited[9]={0,};

void dfs(int start, int cnt){
  if(cnt==m){
    for(int i=0; i<m; i++){
      cout << sequence[i] << ' ';
    }
    cout << '\n';
  } else{
    for(int i=start; i<=n; i++){
      if(visited[i]==0){
        visited[i]=1;
        sequence[cnt]=i;
        dfs(i,cnt+1);
        visited[i]=0;
      }
    }
  }
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
  cin >> n >> m;
  dfs(1,0);
	return 0;
}
