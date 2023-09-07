#include <bits/stdc++.h>
#define pb push_back
#define mp make_pair
#define all(x) (x).begin(), (x).end()

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
const double PI = acos(-1);

string gear[4];

void rotation(int idx, int dir){
  int direction[4]={0,};
  direction[idx]=dir;
  int index=idx;
  while(index>0 && gear[index][6]!=gear[index-1][2]){ // 오른쪽 확인
    direction[index-1]=-direction[index];
    index--;
  }
  while(index<3 && gear[index][2]!=gear[index+1][6]){ // 왼쪽 확인
    direction[index+1]=-direction[index];
    index++;
  }
  for(int t=0; t<4; t++){
    if(direction[t]==-1){
      string temp=gear[t]; // gear 참조를 t로 해야했는데 계속 idx로 하고 있었음...
      for(int i=0; i<7; i++) gear[t][i]=temp[i+1];
      gear[t][7]=temp[0];
    } else if(direction[t]==1){
      string temp=gear[t];
      for(int i=1; i<8; i++) gear[t][i]=temp[i-1];
      gear[t][0]=temp[7];
    }
  }
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
  for(int i=0; i<4; i++) cin >> gear[i];
  int k; cin >> k;
  for(int i=0; i<k; i++){
    int idx, dir; cin >> idx >> dir;
    rotation(idx-1, dir);
  }
  int ans=0;
  for(int i=0; i<4; i++) ans+=((gear[i][0]-'0')*(pow(2, i)));
  cout << ans << '\n';
	return 0;
}
