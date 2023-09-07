#include <bits/stdc++.h>
#define pb push_back
#define mp make_pair
#define all(x) (x).begin(), (x).end()

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
const double PI = acos(-1);

int loc[100001], pow_num[100001], ans=0, MOD=1000000;

void make_pow(int n){ // 하노이 탑 n가지 판 이동 개수 -> (2의 n제곱 -1)
  pow_num[0]=1;
  for(int i=1; i<=n; i++){
    pow_num[i]=(pow_num[i-1]*2)%MOD;
  }
}

void hanoi(int n, int to){
  if(n==0) return;
  int from=loc[n];
  if(from==to) hanoi(n-1, to);
  else{
    hanoi(n-1, 6-from-to);
    ans=(ans+pow_num[n-1])%MOD;
    // n번쨰 디스크 to에 옮기기 + n-1번째 까지 모두 옯기기 -> 1+2^(n-1)-1=2^(n-1)
  }
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
  int n,a,b,c; cin >> n >> a >> b >> c;
  for(int i=0; i<a; i++){
    int x; cin >> x;
    loc[x]=1;
  }
  for(int i=0; i<b; i++){
    int x; cin >> x;
    loc[x]=2;
  }
  for(int i=0; i<c; i++){
    int x; cin >> x;
    loc[x]=3;
  }
  make_pow(n);
  hanoi(n,loc[n]);
  cout << loc[n] << '\n' << ans << '\n';
	return 0;
}
