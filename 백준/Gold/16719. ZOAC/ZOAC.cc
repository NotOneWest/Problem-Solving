#include <bits/stdc++.h>
#define pb push_back
#define mp make_pair
#define all(x) (x).begin(), (x).end()

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
const double PI = acos(-1);

string s;
int visited[101];

void zoac(int start, int end){
  int idx=-1, MIN=1000000;
  for(int i=start; i<end; i++){
    if(visited[i]==0 && MIN>s[i]){
      MIN=s[i];
      idx=i;
    }
  }
  if(MIN==1000000) return; // 종료 조건 없어서 계속 같은 문자 반복되는 실수
  visited[idx]=1;
  for(int i=0; i<s.size(); i++){ 
    if(visited[i]==1) cout << s[i];
  }
  cout << '\n';
  zoac(idx,end);
  zoac(start,idx);
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
  cin >> s;
  zoac(0, s.size());
	return 0;
}
