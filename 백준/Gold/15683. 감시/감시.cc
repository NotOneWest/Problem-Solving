#include <bits/stdc++.h>
#define pb push_back
#define mp make_pair
#define all(x) (x).begin(), (x).end()

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
const double PI = acos(-1);

int n,m,num=0, ans=0;
int office[9][9], copy_office[9][9];
vector<pair<pii, pii> > v; // num,dir,col,row

void east(int col, int row){
  for(int i=(row+1); i<m; i++){
    if(copy_office[col][i]==6) break;
    if(copy_office[col][i]==0) copy_office[col][i]=-1;
  }
}

void west(int col, int row){ // 0부터 돌리니 벽을 제대로 찾지 못함
  for(int i=row; i>=0; i--){
    if(copy_office[col][i]==6) break;
    if(copy_office[col][i]==0) copy_office[col][i]=-1;
  }
}

void south(int col, int row){
  for(int i=(col+1); i<n; i++){
    if(copy_office[i][row]==6) break;
    if(copy_office[i][row]==0) copy_office[i][row]=-1;
  }
}

void north(int col, int row){ // 0부터 돌리니 벽을 제대로 찾지 못함
  for(int i=col; i>=0; i--){
    if(copy_office[i][row]==6) break;
    if(copy_office[i][row]==0) copy_office[i][row]=-1;
  }
}

int BlindSpot(){
  for(int i=0; i<n; i++){
    for(int j=0; j<m; j++) copy_office[i][j]=office[i][j];
  }
  int sum=0,size=v.size();
  for(int i=0; i<size; i++){
    int col=v[i].second.first, row=v[i].second.second;
    if(v[i].first.first==1){
      if(v[i].first.second==0) east(col,row);
      else if(v[i].first.second==1) west(col,row);
      else if(v[i].first.second==2) south(col,row);
      else north(col,row);
    } else if(v[i].first.first==2){
      if(v[i].first.second==0){
        east(col,row);
        west(col,row);
      }
      else{
        south(col,row);
        north(col,row);
      }
    } else if(v[i].first.first==3){
      if(v[i].first.second==0){
        east(col,row);
        north(col,row);
      }
      else if(v[i].first.second==1){
        east(col,row);
        south(col,row);
      }
      else if(v[i].first.second==2){
        north(col,row);
        west(col,row);
      }
      else{
        south(col,row);
        west(col,row);
      }
    } else if(v[i].first.first==4){
      if(v[i].first.second==0){
        east(col,row);
        west(col,row);
        south(col,row);
      }
      else if(v[i].first.second==1){
        east(col,row);
        west(col,row);
        north(col,row);
      }
      else if(v[i].first.second==2){
        east(col,row);
        south(col,row);
        north(col,row);
      }
      else{
        south(col,row);
        north(col,row);
        west(col,row);
      }
    } else{
      east(col,row);
      west(col,row);
      south(col,row);
      north(col,row);
    }
  }
  for(int i=0; i<n; i++){
    for(int j=0; j<m; j++){
      if(copy_office[i][j]==0) sum++;
    }
  }
  return sum;
}

void ChooseDirection(int cnt){
  if(cnt==num){
    int temp=BlindSpot();
    ans=min(ans,temp);
    return;
  } // 길었던 이유 -> cnt로 vector index 늘려야하는데 매번 다하고 있었음 for문으로...
  if(v[cnt].first.first==5){
    v[cnt].first.second=0;
    ChooseDirection(cnt+1);
  } else if(v[cnt].first.first==2){
    v[cnt].first.second=0;
    ChooseDirection(cnt+1);
    v[cnt].first.second=1;
    ChooseDirection(cnt+1);
  } else{
    v[cnt].first.second=0;
    ChooseDirection(cnt+1);
    v[cnt].first.second=1;
    ChooseDirection(cnt+1);
    v[cnt].first.second=2;
    ChooseDirection(cnt+1);
    v[cnt].first.second=3;
    ChooseDirection(cnt+1);
  }
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
  cin >> n >> m;
  for(int i=0; i<n; i++){
    for(int j=0; j<m; j++){
      cin >> office[i][j];
      if(office[i][j]!=0 && office[i][j]<6){
        v.pb(mp(mp(office[i][j],0),mp(i,j)));
        num++;
      }
      if(office[i][j]==0) ans++;
    }
  }
  if(num!=0) ChooseDirection(0);
  cout << ans << '\n';
	return 0;
}
