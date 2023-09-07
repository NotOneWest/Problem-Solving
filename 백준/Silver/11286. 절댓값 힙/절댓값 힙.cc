#include <bits/stdc++.h>
#define pb push_back
#define mp make_pair
#define all(x) (x).begin(), (x).end()

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
const double PI = acos(-1);

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
  int n; cin >> n;
  priority_queue< pii > pq;
  for(int i=0; i<n; i++){
    int x; cin >> x;
    if(x==0){
      if(pq.empty()) cout << "0\n";
      else{
        cout << -pq.top().second << '\n';
        pq.pop();
      }
    } else{
      pq.push(mp(-abs(x), -x));
    }
  }
	return 0;
}
