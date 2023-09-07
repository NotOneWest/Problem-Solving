#include <bits/stdc++.h>
#define pb push_back
#define mp make_pair
#define all(x) (x).begin(), (x).end()

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
const double PI = acos(-1);

int node[10001];

void postorder(int start, int end){
  if(start>=end) return;
  if(end==(start+1)){
    cout << node[start] << '\n';
    return; // 출력하고 안끝냄...
  }
  int next=start+1;
  while(next<end){
    if(node[start]<node[next]) break;
    next++;
  }
  postorder(start+1, next);
  postorder(next, end);
  cout << node[start] << '\n';
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
  int n, index=0;
  while(cin >> n){
    node[index]=n;
    index++;
  }
  postorder(0, index);
	return 0;
}
