#include <bits/stdc++.h>
#define pb push_back
#define mp make_pair
#define all(x) (x).begin(), (x).end()

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
const double PI = acos(-1);

int main(){
  ios_base::sync_with_stdio(false);
	cin.tie(NULL);
  int t; cin >> t;
  for(int i=0; i<t; i++){
    priority_queue<pll> maxheap;
    priority_queue<pll> minheap;
    bool visited[1000001]={false,};
    int k; cin >> k;
    for(int j=0; j<k; j++){
      char c;
      ll n; cin >> c >>n;
      if(c=='I'){
        maxheap.push(pll(n,j));
        minheap.push(pll(-n,j));
        visited[j]=true;
      } else{
        if(n==1){
          while(!maxheap.empty() && !visited[maxheap.top().second]){
            maxheap.pop();
          }
          if(!maxheap.empty()){
            visited[maxheap.top().second]=false;
            maxheap.pop();
          }
        }else{
          while(!minheap.empty() && !visited[minheap.top().second]){
            minheap.pop();
          }
          if(!minheap.empty()){
            visited[minheap.top().second]=false;
            minheap.pop();
          }
        }
      }
    }
    while(!maxheap.empty() && !visited[maxheap.top().second]){
      maxheap.pop();
    }
    while(!minheap.empty() && !visited[minheap.top().second]){
      minheap.pop();
    }
    if(maxheap.empty() && minheap.empty()) cout << "EMPTY\n";
    else cout << maxheap.top().first << ' ' << -minheap.top().first << '\n';
  }
	return 0;
}
