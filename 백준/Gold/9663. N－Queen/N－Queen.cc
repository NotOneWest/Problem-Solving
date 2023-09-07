#include <bits/stdc++.h>
#define pb push_back
#define mp make_pair
#define all(x) (x).begin(), (x).end()

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
const double PI = acos(-1);

int col[16];
int order=1,n,ans=0;

bool check(int x){
  for(int i=1; i<x; i++){
    if(col[i]==col[x] || abs(col[i]-col[x])==(x-i)) return false;
  }
  return true;
}

void Nqueen(int step){
  if(step==(n+1)) ans++; // 다 통과하면 step이 n보다 1커야하는 것 뺴먹음..
  else{
    for(int i=1; i<=n; i++){
      col[step]=i;
      if(check(step)) Nqueen(step+1);
    }
  }
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
  cin >> n;
  Nqueen(1);
  cout << ans << '\n';
	return 0;
}
