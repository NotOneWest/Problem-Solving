#include <bits/stdc++.h>
#define pb push_back
#define mp make_pair
#define all(x) (x).begin(), (x).end()

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
const double PI = acos(-1);

int S[20]={0};

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
  int m; cin >> m;
  for(int i=0; i<m; i++){
    string s; cin >> s;
    if(s=="add"){
      int x; cin >> x;
      S[x-1]=1;
    } else if(s[0]=='r'){
      int x; cin >> x;
      if(S[x-1]!=0) S[x-1]=0;
    } else if(s[0]=='t'){
      int x; cin >> x;
      if(S[x-1]!=0) S[x-1]=0;
      else S[x-1]=1;
    } else if(s[0]=='e') fill(S,S+20,0);
    else if(s=="all") fill(S,S+20,1);
    else{
      int x; cin >> x;
      if(S[x-1]!=0) cout << "1\n";
      else cout << "0\n";
    }
  }
	return 0;
}
