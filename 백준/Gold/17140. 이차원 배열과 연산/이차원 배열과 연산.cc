#include <bits/stdc++.h>
#define pb push_back
#define mp make_pair
#define all(x) (x).begin(), (x).end()

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
const double PI = acos(-1);

int A[101][101], r, c, k;
int col=3, row=3;

void change(){ // 행과 열 바꿔주기
  int maxsize=max(col,row);
  for(int i=0; i<maxsize; i++){ // j를 0부터 시작하면 겹치는 것 발생
    for(int j=i+1; j<maxsize; j++) swap(A[i][j],A[j][i]);
  }
  swap(col, row);
}

void Rsorting(int col_n){
  int cnt[101]={0,};
  vector<pii> v;
  for(int i=0; i<row; i++) cnt[A[col_n][i]]++;
  for(int i=1; i<101; i++){
    if(cnt[i]==0) continue;
    v.pb(mp(cnt[i],i));
  }
  sort(all(v));
  int i=0,j=0,sz=v.size();
  while(i!=sz){
    if(j==100) break;
    A[col_n][j]=v[i].second;
    j++;
    A[col_n][j]=v[i].first;
    j++;
    i++;
  }
  row=max(row,j);
  fill(A[col_n] + j, A[col_n] + row, 0); // 0 채워주기
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
  cin >> r >> c >> k;
  for(int i=0; i<3; i++){
    for(int j=0; j<3; j++) cin >> A[i][j];
  }
  int ans=0;
  while(A[r-1][c-1]!=k && ans<=100){
    bool change_A=false;
    if(col<row){ // C연산 할때 행,열 바꿔주고 R연산하고 다시 C연산 해줌
      change();
      change_A=true;
    }
    for(int i=0; i<col; i++) Rsorting(i);
    if(change_A) change();
    ans++;
  }
  if(ans>100) cout << -1 << '\n';
  else cout << ans << '\n';
	return 0;
}
