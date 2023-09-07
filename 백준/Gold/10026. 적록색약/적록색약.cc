#include <bits/stdc++.h>
#define pb push_back
#define mp make_pair
#define all(x) (x).begin(), (x).end()

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
const double PI = acos(-1);

int no[101][101] ,yes[101][101], num[2]={0,}; 
int dxy[4][2] = {{1,0}, {-1,0}, {0,1}, {0,-1}};

int main(){
	int n; cin >> n;
	for(int i=0; i<n; i++){
		string s; cin >> s;
		for(int j=0; j<n; j++){
			if(s[j]=='R'){
				no[i][j]=2;
				yes[i][j]=1;
			}
			else if(s[j]=='G'){
				no[i][j]=1;
				yes[i][j]=1;
			}
			else{
				no[i][j]=0;
				yes[i][j]=0;
			}
		}
	}
	for(int k=0; k<3; k++){
		for(int i=0; i<n; i++){
			for(int j=0; j<n; j++){
				queue<pii > q1;
				if(no[i][j] == k){
					num[0]++;
					q1.push(mp(i,j));
					no[i][j]=-1;
				}
				while(!q1.empty()){
					int x = q1.front().first, y = q1.front().second;
					q1.pop();
					for(int t=0; t<4; t++){
						int col = x + dxy[t][0];
						int row = y + dxy[t][1];
						if((col >=0 && col<n) && (row>=0 && row<n) && no[col][row] == k){
							no[col][row] = -1;
							q1.push(mp(col,row));
						}
					}
				}	
			}
		}
	}
	for(int k=0; k<2; k++){
		for(int i=0; i<n; i++){
			for(int j=0; j<n; j++){
				queue<pii > q2;
				if(yes[i][j] == k){
					num[1]++;
					q2.push(mp(i,j));
					yes[i][j]=-1;
				}
				while(!q2.empty()){
					int x = q2.front().first, y = q2.front().second;
					q2.pop();
					for(int t=0; t<4; t++){
						int col = x + dxy[t][0];
						int row = y + dxy[t][1];
						if((col >=0 && col<n) && (row>=0 && row<n) && yes[col][row] == k){
							yes[col][row] = -1;
							q2.push(mp(col,row));
						}
					}
				}	
			}
		}
	}
	cout << num[0] << ' ' << num[1];
	return 0;
}
