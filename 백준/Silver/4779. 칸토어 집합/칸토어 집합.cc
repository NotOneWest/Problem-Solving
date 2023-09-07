#include <bits/stdc++.h>
#define pb push_back
#define mp make_pair
#define all(x) (x).begin(), (x).end()

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
const double PI = acos(-1);

int n;
void cantor(int n){
  if(n==0){
    cout << '-';
    return;
  }
  cantor(n-1);
  for(int i=0; i<pow(3,n-1); i++) cout << ' ';
  cantor(n-1);
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
  while(1){
    cin >> n;
    if(cin.eof()==true) break;
    cantor(n);
    cout << '\n';
  }
	return 0;
}
