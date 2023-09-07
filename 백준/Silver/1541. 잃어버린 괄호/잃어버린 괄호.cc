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
  string s,temp=""; cin >> s;
  int sum=0;
  bool minus=false;
  for(int i=0; i<s.length(); i++){
    if(s[i]=='-'){
      if(!minus) sum+=stoi(temp);
      else sum-=stoi(temp);
      temp="";
      minus=true;
    } else if(s[i]=='+'){
      if(!minus) sum+=stoi(temp);
      else sum-=stoi(temp);
      temp="";
    } else temp+=s[i];
  }
  if(!minus) sum+=stoi(temp);
  else sum-=stoi(temp);
  cout << sum << '\n';
	return 0;
}
