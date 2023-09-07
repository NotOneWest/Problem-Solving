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
  int t; cin >> t;
  for(int i=0; i<t; i++){
    int h,w,n; cin >> h >> w >> n;
    int floor=n, num=1;
    while(floor > h){
      floor-=h;
      num+=1;
    }
    if(num < 10){
      printf("%d0%d\n", floor, num);
    } else {
      printf("%d%d\n", floor, num);
    }
  }
  return 0;
}
