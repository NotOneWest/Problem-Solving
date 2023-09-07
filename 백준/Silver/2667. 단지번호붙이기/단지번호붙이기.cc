#include <bits/stdc++.h>
#define pb push_back
#define mp make_pair
#define all(x) (x).begin(), (x).end()

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
const double PI = acos(-1);

int home[26][26], area[626];
int dxy[4][2] = {{1,0}, {-1,0}, {0,1}, {0,-1}};


int main(){
	fill(area, area+26, 0);
	ios::sync_with_stdio(0);
  	cin.tie(0);
	int n; cin >> n;
	for(int i=0; i<n; i++){
		string s; cin >> s;
		for(int j=0; j<n; j++) home[i][j] = s[j]-'0';
	}
	queue< pii > q;	
	int num=0;
	for(int i=0; i<n; i++){
		for(int j=0; j<n; j++){
			if(home[i][j] == 1){
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
					if((col >=0 && col<n) && (row>=0 && row<n) && home[col][row] == 1){
						home[col][row] = -1;
						q.push(mp(col,row));
					}
				}
			}
		}
	}
	sort(area, area+num+1);
	cout << num << '\n';
	for(int i=1; i<num+1; i++){
		if(area[i] != 1) area[i]--;
		cout << area[i] << '\n';
	}
	return 0;
}