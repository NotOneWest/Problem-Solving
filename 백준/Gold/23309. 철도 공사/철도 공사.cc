#include <bits/stdc++.h>
using namespace std;

const int MX = 1000005;
int pre[MX], nxt[MX];

int main(void) {
  ios_base::sync_with_stdio(false);
	cin.tie(NULL);
  fill(pre, pre+MX, -1);
  fill(nxt, nxt+MX, -1);
  int n,m,first,pre_num=-1; cin >> n >> m;
  for(int i=1; i<=n; i++){
    int num; cin >> num;
    if(i==1) first=num;
    if(pre_num!=-1) nxt[pre_num]=num;
    pre[num]=pre_num;
    pre_num=num;
  }
  nxt[pre_num]=first;
  pre[first]=pre_num;
  string button;
  int i,j;
  for(int c=0; c<m; c++){
    cin >> button;
    if(button=="BN"){
      cin >> i >> j;
      cout << nxt[i] << "\n";
      pre[j]=i;
      nxt[j]=nxt[i];
      pre[nxt[i]]=j;
      nxt[i]=j;
    } else if(button=="BP"){
      cin >> i >> j;
      cout << pre[i] << "\n";
      nxt[j]=i;
      pre[j]=pre[i];
      nxt[pre[i]]=j;
      pre[i]=j;
    } else if(button=="CN"){
      cin >> i;
      cout << nxt[i] << "\n";
      int prev=pre[nxt[i]], next=nxt[nxt[i]];
      nxt[prev]=next;
      pre[next]=prev;
    } else{
      cin >> i;
      cout << pre[i] << "\n";
      int prev=pre[pre[i]], next=nxt[pre[i]];
      nxt[prev]=next;
      pre[next]=prev;
    }
    // cout << "-----------------\n";
    // for(int i=0; i<12; i++){
    //   cout << pre[i] << ' ';
    // }
    // cout << "this is pre\n";
    // for(int i=0; i<12; i++){
    //   cout << nxt[i] << ' ';
    // }
    // cout << "this is nxt\n";
  }
  return 0;
}
