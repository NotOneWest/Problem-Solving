#include <bits/stdc++.h>
#define pb push_back
#define mp make_pair
#define all(x) (x).begin(), (x).end()

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
const double PI = acos(-1);

int main(){
  int a,b,c,d,e,ans;
  cin >> a >> b >> c >> d >> e;
  ans = (a*a+b*b+c*c+d*d+e*e)%10;
  cout << ans << '\n';
	return 0;
}
