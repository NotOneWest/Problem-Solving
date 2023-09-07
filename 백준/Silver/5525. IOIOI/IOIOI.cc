#include <bits/stdc++.h>
#define pb push_back
#define mp make_pair
#define all(x) (x).begin(), (x).end()

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
const double PI = acos(-1);

int pi[1000001];

void kmp(string pattern){
  int begin=-1,end=0;
  pi[end]=begin;
  while(end<pattern.length()){
    if(begin==-1 || (begin>=0 && pattern[begin]==pattern[end])){
      begin++;
      end++;
      pi[end]=begin;
    } else{
      pi[end]=begin;
      end++;
    }
  }
}

int findpattern(string s, string pn){
  int cnt=0, m=pn.length(), begin=0, pnbegin=0;
  while(begin < s.length()){
    if(pnbegin==-1 || s[begin]==pn[pnbegin]){
      begin++;
      pnbegin++;
    } else if(s[begin]!=pn[pnbegin]) pnbegin=pi[pnbegin];
    if(pnbegin == m){
      cnt++;
      pnbegin=pi[pnbegin];
    }
  }
  return cnt;
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
  int n,m,ans=0; cin >> n >> m;
  string s,pn=""; cin >> s;
  for(int i=0; i<n; i++) pn += "IO";
  pn+="I";
  kmp(pn);
  cout << findpattern(s, pn) << '\n';
	return 0;
}
