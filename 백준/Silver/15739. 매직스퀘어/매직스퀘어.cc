#include <bits/stdc++.h>
#define pb push_back
#define mp make_pair
#define all(x) (x).begin(), (x).end()

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
const double PI = acos(-1);

int num[101][101];
set<int> s;

int main(){
	int n; cin >> n;
	int sum=(n*(n*n+1))/2, check=0;
	for(int i=0; i<n; i++){
		for(int j=0; j<n; j++){
			int k; cin >> k;
			num[i][j]=k;
			s.insert(k);
		}
	}
	int line=0, line2=0;
	for(int i=0; i<n; i++){
		int row=0, col=0;
		for(int j=0; j<n; j++){
			if(n%2==1 && i==n/2 && i==j){
				line+=num[i][j];
				line2+=num[i][j];
			}
			else if(i==j) line+=num[i][j];
			else if((i+j)==(n-1)) line2+=num[i][j];
			row+=num[i][j];
			col+=num[j][i];
		}
		if(row!=sum || col!=sum){
			check=1;
			break;
		}
	}
	if(line!=sum || line2!=sum) check=1;
	if(s.size()!=(n*n)) check=1;
	if(check) cout << "FALSE";
	else cout << "TRUE";
	return 0;
}
