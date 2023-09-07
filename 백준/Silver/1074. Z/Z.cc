#include <bits/stdc++.h>
#define pb push_back
#define mp make_pair
#define all(x) (x).begin(), (x).end()

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
const double PI = acos(-1);

ll n,r,c,cnt=0, ans;

void find(int right, int left, int top, int bottom){
  // cout << right << ' ' << left << ' ' << top << ' ' << bottom << "[][]\n";
  // cout << cnt << "->cnt\n";
  if(right>=c && left<=c && top>=r && bottom<=r){
    if( (right-1)==left && (top-1)==bottom ){
      for(int i=bottom; i<=top; i++){
        for(int j=left; j<=right; j++){
          if(i!=0 || j!=0) cnt++;
          if(i==r && j==c){
            ans=cnt;
            return;
          }
        }
      }
    } else{
      find( (left+right)/2, left, (top+bottom)/2, bottom );
      find( right, (left+right)/2+1, (top+bottom)/2, bottom );
      find( (left+right)/2, left, top, (top+bottom)/2+1 );
      find( right, (left+right)/2+1, top, (top+bottom)/2+1 );
    }
  } else{
    if(left==0 && bottom==0) cnt += ((right-left+1)*(top-bottom+1)-1);
    else cnt += (right-left+1)*(top-bottom+1);
  }
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
  cin >> n >> r >> c;
  find(pow(2,n)-1, 0, pow(2,n)-1, 0);
  cout << ans << '\n';
	return 0;
}
