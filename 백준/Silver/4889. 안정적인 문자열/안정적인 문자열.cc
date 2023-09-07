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
  for(int c=1; 1; c++){
    int cnt=0;
    string s; cin >> s;
    if(s[0]=='-') break;
    stack<char> st;
    for(int i=0; i<s.length(); i++){
      if(st.size()==0){
        if(s[i]=='}'){
          cnt++;
          st.push('{');
        } else st.push(s[i]);
      } else{
        if(s[i]=='}') st.pop();
        else st.push(s[i]);
      }
    }
    cout << c << ". " << (cnt+st.size()/2) << '\n';
  }
	return 0;
}
