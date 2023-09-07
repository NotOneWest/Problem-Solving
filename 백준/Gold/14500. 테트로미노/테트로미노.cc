#include <bits/stdc++.h>
#define pb push_back
#define mp make_pair
#define all(x) (x).begin(), (x).end()

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
const double PI = acos(-1);

int num[510][510]; // 크기를 n,m으로 입력 받으면 인덱스 벗어날 가능성 있었음... 헤멘 이유 1번

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
  int n,m; cin >> n >> m;
  for(int i=0; i<n; i++){
    for(int j=0; j<m; j++){
      int x; cin >> x;
      num[i][j]=x;
    }
  }
  priority_queue<int> pq;

  for(int i=0; i<n; i++){
    for(int j=0; j<m; j++){
      pq.push(num[i][j]+num[i][j+1]+num[i][j+2]+num[i][j+3]);
      pq.push(num[i][j]+num[i+1][j]+num[i+2][j]+num[i+3][j]);

      pq.push(num[i][j]+num[i][j+1]+num[i+1][j]+num[i+1][j+1]);

      pq.push(num[i][j]+num[i+1][j]+num[i+2][j]+num[i+2][j+1]);
      pq.push(num[i][j]+num[i][j+1]+num[i][j+2]+num[i+1][j]);
      pq.push(num[i][j]+num[i][j+1]+num[i+1][j+1]+num[i+2][j+1]);
      pq.push(num[i][j+2]+num[i+1][j]+num[i+1][j+1]+num[i+1][j+2]);
      pq.push(num[i][j+1]+num[i+1][j+1]+num[i+2][j]+num[i+2][j+1]);
      pq.push(num[i][j]+num[i+1][j]+num[i+1][j+1]+num[i+1][j+2]);
      pq.push(num[i][j]+num[i][j+1]+num[i][j+2]+num[i+1][j+2]);
      pq.push(num[i][j]+num[i+1][j]+num[i+2][j]+num[i][j+1]);

      pq.push(num[i][j]+num[i+1][j]+num[i+1][j+1]+num[i+2][j+1]);
      pq.push(num[i][j+1]+num[i][j+2]+num[i+1][j]+num[i+1][j+1]);
      pq.push(num[i][j]+num[i][j+1]+num[i+1][j+1]+num[i+1][j+2]);
      pq.push(num[i][j+1]+num[i+1][j]+num[i+1][j+1]+num[i+2][j]);

      pq.push(num[i][j]+num[i][j+1]+num[i][j+2]+num[i+1][j+1]);
      pq.push(num[i+1][j]+num[i+1][j+1]+num[i+1][j+2]+num[i][j+1]);
      pq.push(num[i][j]+num[i+1][j]+num[i+1][j+1]+num[i+2][j]);
      pq.push(num[i][j+1]+num[i+1][j]+num[i+1][j+1]+num[i+2][j+1]);
    }
  }
  cout << pq.top() << '\n';
	return 0;
}
