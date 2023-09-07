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
  priority_queue<int> maxheap;
  int n; cin >> n;
  for(int i=0; i<n; i++){
    int x; cin >> x;
    if(x==0){
      if(maxheap.empty()) cout << "0\n";
      else{
        cout << maxheap.top() << '\n';
        maxheap.pop();
      }
    } else maxheap.push(x);
  }
	return 0;
}
