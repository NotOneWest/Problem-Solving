#include <bits/stdc++.h>
#define pb push_back
#define mp make_pair
#define all(x) (x).begin(), (x).end()

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
const double PI = acos(-1);

int s[14], ans[14],k;

void lotto(int start, int cnt){
  if(cnt==6){
    for(int i=0; i<6; i++) cout << ans[i] << ' ';
    cout << '\n';
    return;
  }
  for(int i=start; i<k; i++){
    ans[cnt]=s[i];
    lotto(i+1, cnt+1); // start+1 이 아니라 i+1 -> start는 0으로 고정... i+1로 해야 index가 바뀜
  }
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
  while(1){
    cin >> k;
    if(k==0) break;
    for(int i=0; i<k; i++) cin >> s[i];
    lotto(0,0);
    cout << '\n';
  }
	return 0;
}
