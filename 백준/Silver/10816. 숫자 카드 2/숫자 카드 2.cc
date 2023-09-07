#include <bits/stdc++.h>
#define pb push_back
#define mp make_pair
#define all(x) (x).begin(), (x).end()

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
const double PI = acos(-1);

int card[20000001];

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
  int n; cin >> n;
  for(int i=0; i<n; i++){
    int card_num; cin >> card_num;
    card[card_num+10000000]++;
  }
  int m; cin >> m;
  for(int i=0; i<m; i++){
    int num; cin >> num;
    cout << card[num+10000000] << ' ';
  }
	return 0;
}
