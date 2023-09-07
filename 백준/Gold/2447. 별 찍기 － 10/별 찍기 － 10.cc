#include <bits/stdc++.h>
#define pb push_back
#define mp make_pair
#define all(x) (x).begin(), (x).end()

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
const double PI = acos(-1);

void star(int x, int y, int n){
    if((x/n)%3==1 && (y/n)%3==1) cout << ' ';
    // n 일떄 빈칸인 위치를 n/3을 반복해 (1,1) 위치로 표현하기 위해 (x/n)%3, (y/n)%3으로 표현..
    else{
      if(n/3==0) cout << '*'; // n이 1일때 멈추고 print 해줘야함.
      else star(x,y,n/3);
    }
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
  int n; cin >> n;
  for(int i=0; i<n; i++){
    for(int j=0; j<n; j++) star(i,j,n);
    cout << '\n';
  }
	return 0;
}
