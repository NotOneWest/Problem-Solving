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
  vector<char> v;
  string s,bomb; cin >> s >> bomb;
  for(int j=0; j<s.length(); j++){
    if(v.size()<(bomb.length()-1)) v.pb(s[j]);
    else{
      int flag=0;
      if(bomb[bomb.size()-1]==s[j]){
        for(int i=1; i<bomb.length(); i++){
          if(v[v.size()-i]==bomb[bomb.length()-1-i]) flag=1;
          else{
            v.pb(s[j]);
            flag=0;
            break;
          }
        }
        if(flag==1){
          for(int i=1; i<bomb.length(); i++) v.pop_back();
        }
      } else v.pb(s[j]);
    }
  }
  if(v.size()==0) cout << "FRULA\n";
  else{
    for(int i=0; i<v.size(); i++) cout << v[i];
    cout << "\n";
  }
	return 0;
}
