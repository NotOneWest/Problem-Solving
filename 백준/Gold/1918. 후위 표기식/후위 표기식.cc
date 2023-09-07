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
  string mid; cin >> mid;
  stack<char> s;
  for(int i=0; i<mid.length(); i++){
    if('A'<=mid[i] && mid[i]<='Z') cout << mid[i];
    else{
      if(mid[i]=='(') s.push(mid[i]);
      else if(mid[i]==')'){
        while(!s.empty() && s.top()!='('){
          cout << s.top();
          s.pop();
        }
        s.pop();
      } else if(mid[i]=='-' || mid[i]=='+'){
        while(!s.empty() && s.top()!='('){
          cout << s.top();
          s.pop();
        }
        s.push(mid[i]);
      } else{
        while(!s.empty() && (s.top()=='*' || s.top()=='/')){
          cout << s.top();
          s.pop();
        }
        s.push(mid[i]);
      }
    }
  }
  while(!s.empty()){
    cout << s.top();
    s.pop();
  }
	return 0;
}
