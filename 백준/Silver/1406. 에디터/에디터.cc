#include <bits/stdc++.h>
using namespace std;

const int MX = 1000005;
char dat[MX];
int pre[MX], nxt[MX];
int unused = 1;

void insert(int addr, char num){
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

void traverse(){
  int cur = nxt[0];
  while(cur != -1){
    cout << dat[cur];
    cur = nxt[cur];
  }
}

int main(void) {
  ios_base::sync_with_stdio(false);
	cin.tie(NULL);
  fill(pre, pre+MX, -1);
  fill(nxt, nxt+MX, -1);
  fill(dat, dat+MX, ';');
  string s; cin >> s;
  for(int i=0; i<s.length(); i++) insert(i, s[i]);
  int t, curr=s.length(); cin >> t;
  for(int i=0; i<t; i++){ // 처음 미스 : 커서를 prev, next 를 사용해 바꿔줘야 하는데 그냥 -1, +1 로 생각
    char button; cin >> button;
    if(button=='L'){
      if(pre[curr]!=-1) curr=pre[curr];
    } else if(button=='D'){
      if(nxt[curr]!=-1) curr=nxt[curr];
    } else if(button=='B'){
      if(pre[curr]!=-1){
        erase(curr);
        curr=pre[curr];
      }
    } else{
      char x; cin >> x;
      insert(curr, x);
      curr=nxt[curr];
    }
  }
  traverse();
  return 0;
}
