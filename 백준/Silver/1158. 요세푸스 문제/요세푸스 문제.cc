#include <bits/stdc++.h>
using namespace std;

const int MX = 1000005;
int dat[MX], pre[MX], nxt[MX];
int unused = 1;

void insert(int addr, int num){
  dat[unused]=num;
  pre[unused]=addr;
  nxt[unused]=nxt[addr];
  if(nxt[addr]!=-1) pre[nxt[addr]]=unused;
  nxt[addr]=unused;
  unused++;
}

void erase(int addr){
  nxt[pre[addr]]=nxt[addr];
  if(nxt[addr]!=-1) pre[nxt[addr]]=pre[addr];
}

int main(void) {
  ios_base::sync_with_stdio(false);
	cin.tie(NULL);
  fill(pre, pre+MX, -1);
  fill(nxt, nxt+MX, -1);
  int n,k,curr=1,j=1; cin >> n >> k;
  for(int i=1; i<=n; i++) insert(i-1, i);
  pre[1]=n;
  nxt[n]=1;
  vector<int> v;
  while(n!=0){
    if(j==k){
      v.push_back(dat[curr]);
      erase(curr);
      n--;
      j=1;
    }else j++;
    curr=nxt[curr];
  }
  cout << '<';
  for(int i=0; i<v.size(); i++){
    cout << v[i];
    if(i!=(v.size()-1)) cout << ", ";
  }
  cout << ">\n";
  return 0;
}
