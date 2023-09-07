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
  string s,number=""; cin >> s;
  deque<string> num;
  deque<char> operators;
  for(ll i=0; i<s.size(); i++){
    if(s[i]>='0' && s[i]<='9') number+=s[i];
    else{
      if(i==0) number+=s[i];
      else{
        operators.pb(s[i]);
        num.pb(number);
        number="";
      }
    }
  }
  num.pb(number);
  while(num.size()>1){
    if((operators.front()=='*' || operators.front()=='/') && (operators.back()=='+' || operators.back()=='-')){
      ll cal=0;
      if(operators.front()=='*') cal=(stoll(num[0])*stoll(num[1]));
      else cal=(stoll(num[0])/stoll(num[1]));
      num.pop_front();
      num.pop_front();
      num.push_front(to_string(cal));
      operators.pop_front();
    } else if((operators.front()=='+' || operators.front()=='-') && (operators.back()=='*' || operators.back()=='/')){
      ll cal=0, size=num.size();
      if(operators.back()=='*') cal=(stoll(num[size-2])*stoll(num[size-1]));
      else cal=(stoll(num[size-2])/stoll(num[size-1]));
      num.pop_back();
      num.pop_back();
      num.push_back(to_string(cal));
      operators.pop_back();
    } else{
      ll first=0, last=0, size=num.size();

      if(operators.front()=='*') first=(stoll(num[0])*stoll(num[1]));
      else if(operators.front()=='/') first=(stoll(num[0])/stoll(num[1]));
      else if(operators.front()=='+') first=(stoll(num[0])+stoll(num[1]));
      else first=(stoll(num[0])-stoll(num[1]));

      if(operators.back()=='*') last=(stoll(num[size-2])*stoll(num[size-1]));
      else if(operators.back()=='/') last=(stoll(num[size-2])/stoll(num[size-1]));
      else if(operators.back()=='+') last=(stoll(num[size-2])+stoll(num[size-1]));
      else last=(stoll(num[size-2])-stoll(num[size-1]));

      if(first<last){
        num.pop_back();
        num.pop_back();
        num.pb(to_string(last));
        operators.pop_back();
      } else{
        num.pop_front();
        num.pop_front();
        num.push_front(to_string(first));
        operators.pop_front();
      }
    }
  }
  cout << stoll(num[0]) << "\n";
	return 0;
}
