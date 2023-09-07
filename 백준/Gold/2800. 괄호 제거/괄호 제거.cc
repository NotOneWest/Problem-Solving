#include <bits/stdc++.h>
#define pb push_back
#define mp make_pair
#define all(x) (x).begin(), (x).end()

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
const double PI = acos(-1);

vector<int> comb;
vector<pii> v;
set<string> ans;

void combination(int n, int r, int k, string s){
  if(comb.size()==r){
    string temp=s;
    for(int i=0; i<r; i++){
      int start=v[comb[i]-1].first, end=v[comb[i]-1].second;
      temp[start]=' ';
      temp[end]=' ';
    }
    temp.erase(remove(temp.begin(), temp.end(), ' '), temp.end());
    ans.insert(temp);
  } else if(k>n){

  } else{
    comb.pb(k);
    combination(n,r,k+1,s);
    comb.pop_back();
    combination(n,r,k+1,s);
  }
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
  string s; cin >> s;
  stack<pair<char,int> > st;
  for(int i=0; i<s.length(); i++){
    if(s[i]=='(') st.push(mp(s[i],i));
    else if(s[i]==')'){
      v.pb(mp(st.top().second, i));
      st.pop();
    }
  }
  sort(all(v));
  for(int i=1; i<=v.size(); i++) combination(v.size(), i, 1, s);
  for(auto i : ans) cout << i << '\n';
	return 0;
}
