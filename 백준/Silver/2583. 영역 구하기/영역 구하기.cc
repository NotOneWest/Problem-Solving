#include <bits/stdc++.h>
#define pb push_back
#define mp make_pair
#define all(x) (x).begin(), (x).end()

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
const double PI = acos(-1);

int paper[101][101], area[10001]={0,};
int dxy[4][2] = {{1,0}, {-1,0}, {0,1}, {0,-1}};


int main(){
	ios::sync_with_stdio(0);
  	cin.tie(0);
	int m, n, k; cin >> m >> n >> k;
	for(int i=0; i<m; i++){
		for(int j=0; j<n; j++) paper[i][j]=1;
	}
	for(int i=0; i<k; i++){
		int a,b,c,d; cin >> a >> b >> c >> d;
		for(int y=b; y<d; y++){
			for(int x=a; x<c; x++){
				paper[y][x]=0;
			}
		}
	}
	queue< pii > q;	
	int num=0;
	for(int i=0; i<m; i++){
		for(int j=0; j<n; j++){
			if(paper[i][j] == 1){
				num++;
				q.push(mp(i,j));
			}
			while(!q.empty()){
				int x = q.front().first, y = q.front().second;
				area[num]++;
				q.pop();
				for(int t=0; t<4; t++){
					int col = x + dxy[t][0];
					int row = y + dxy[t][1];
					if((col >=0 && col<n) && (row>=0 && row<n) && paper[col][row] == 1){
						paper[col][row] = -1;
						q.push(mp(col,row));
					}
				}
			}
		}
	}
	sort(area+1, area+num+1);
	cout << num << '\n';
	for(int i=1; i<num+1; i++){
		if(area[i] != 1) area[i]--;
		cout << area[i] << ' ';
	}
	return 0;
}