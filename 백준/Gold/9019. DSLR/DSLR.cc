#include <bits/stdc++.h>
#define pb push_back
#define mp make_pair
#define all(x) (x).begin(), (x).end()

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
const double PI = acos(-1);

int D(int n){
  if((n*2)>9999) n=(2*n)%10000;
  else n*=2;
  return n;
}

int S(int n){
  if(n==0) return 9999;
  else return (n-1);
}

int L(int n){
  return (n%1000)*10 + n/1000;
}

int R(int n){
  return (n%10)*1000 + n/10;
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
  int visit[10002];
  int t; cin >> t;
  for(int i=0; i<t; i++){
    int a,b; cin >> a >> b;
    fill(visit, visit+10001, 0);
    queue< pair<int, string > > q;
    q.push(mp(a,""));
    visit[a]=1;
    while(!q.empty()){
      int next=q.front().first;
      string path=q.front().second;
      q.pop();
      if(D(next)==b){
        cout << path+"D" << '\n';
        break;
      }
      else{
        if(visit[D(next)]==0){
          visit[D(next)]=1;
          q.push(mp(D(next), path+"D"));
        }
      }
      if(S(next)==b){
        cout << path+"S" << '\n';
        break;
      }
      else{
        if(visit[S(next)]==0){
          visit[S(next)]=1;
          q.push(mp(S(next), path+"S"));
        }
      }
      if(L(next)==b){
        cout << path+"L" << '\n';
        break;
      }
      else{
        if(visit[L(next)]==0){
          visit[L(next)]=1;
          q.push(mp(L(next), path+"L"));
        }
      }
      if(R(next)==b){
        cout << path+"R" << '\n';
        break;
      }
      else{
        if(visit[R(next)]==0){
          visit[R(next)]=1;
          q.push(mp(R(next), path+"R"));
        }
      }
    }
  }
	return 0;
}
