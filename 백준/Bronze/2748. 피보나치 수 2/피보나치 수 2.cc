#include <bits/stdc++.h>
#define pb push_back
#define mp make_pair
#define all(x) (x).begin(), (x).end()

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
const double PI = acos(-1);

ll arr[100]={0, 1, };

int main(){
  ios_base::sync_with_stdio(false);
	cin.tie(NULL);
  int n; cin >> n;
  for(int i=2; i<=n; i++){
    arr[i]=arr[i-1]+arr[i-2];
  }
  cout << arr[n] << '\n';
	return 0;
}
