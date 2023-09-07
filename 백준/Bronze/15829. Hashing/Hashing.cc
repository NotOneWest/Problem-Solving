#include <bits/stdc++.h>
#define pb push_back
#define mp make_pair
#define all(x) (x).begin(), (x).end()

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
const double PI = acos(-1);
const int m=1234567891;

int main(){
  ios_base::sync_with_stdio(false);
	cin.tie(NULL);
  int l; cin >> l;
  ll sum=0, r=1;
  for(int i=0; i<l; i++){
    char c; cin >> c;
    sum += ((c-'a'+1)*r)%m;
    r=(r*31)%m;
  }
  cout << sum << '\n';
  return 0;
}
