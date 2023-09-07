#include <bits/stdc++.h>
#define pb push_back
#define mp make_pair
#define all(x) (x).begin(), (x).end()

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
const double PI = acos(-1);

int n, w, bridge[101], l, t=1;
queue<int> q;

bool bridgeempty(){
  for(int i=0; i<w; i++){
    if(bridge[i]!=0) return false;
  }
  return true;
}

int weight(){
  int sum=0;
  for(int i=0; i<w; i++) sum+=bridge[i];
  return sum;
}


int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
  cin >> n >> w >> l;
  for(int i=0; i<n; i++){
    int x; cin >> x;
    q.push(x);
  }
  bridge[0]=q.front();
  q.pop();
  while(!bridgeempty() || !q.empty()){
    int temp=weight();
    if(temp<=l){
      temp-=bridge[w-1]; // 0이 아니라 나가기 직전 무게 제외 ;;;;;
      for(int i=w; i>0; i--){ // 옆으로 이동
        bridge[i]=bridge[i-1];
      }
      bridge[0]=0;
      if(!q.empty() && (temp+q.front())<=l){
        bridge[0]=q.front();
        q.pop();
      }
    }
    t++;
  }
  cout << t << "\n";
	return 0;
}
