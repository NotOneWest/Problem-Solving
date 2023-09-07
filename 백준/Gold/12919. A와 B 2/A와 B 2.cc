#include <bits/stdc++.h>
#define pb push_back
#define mp make_pair
#define all(x) (x).begin(), (x).end()

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
const double PI = acos(-1);

void game(string s, string t){
  if(s==t){
    cout << 1 << '\n';
    exit(0);
  }
  if(s.length() >= t.length()) return;
  string curr=t;
  if(t[t.length()-1]=='A'){
    curr.erase(curr.length()-1);
    game(s,curr);
  }
  curr=t;
  if(t[0]=='B'){
    curr.erase(curr.begin());
    reverse(all(curr));
    game(s,curr);
  }
}


int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
  string s,t; cin >> s >> t;
  game(s,t);
  cout << 0 << '\n';
	return 0;
}
