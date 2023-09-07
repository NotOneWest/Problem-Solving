#include <bits/stdc++.h>
#define pb push_back
#define mp make_pair
#define all(x) (x).begin(), (x).end()

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
const double PI = acos(-1);

int l,c,visited[16];
char alphabet[16], pw[16];

bool check(char a){
  if(a=='a' || a=='e' || a=='i' || a=='o' || a=='u') return true;
  else return false;
}

void func(int start, int len){
  if(len==l){
    int cnt1=0, cnt2=0, flag=0;
    for(int i=0; i<l; i++){ // 자음 모음 개수 check
      if(check(pw[i])) cnt1++;
      else cnt2++;
    }
    if(cnt1>=1 && cnt2>=2) flag=1;
    if(flag){
      for(int i=0; i<l; i++) cout << pw[i];
      cout << '\n';
    }
  }
  for(int i=start; i<c; i++){
    pw[len]=alphabet[i];
    func(i+1,len+1); 
    // start+1 로 했는데 i+1 로 해야함..... start+1로 하면 그냥 순서대로 진행->백트래킹이 안됨
    // 비슷한 실수 계속 반복중... 백트래킹 하는 인자 잘 확인할 것
  }
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
  cin >> l >> c;
  for(int i=0; i<c; i++) cin >> alphabet[i];
  sort(alphabet, alphabet+c);
  func(0,0);
	return 0;
}
