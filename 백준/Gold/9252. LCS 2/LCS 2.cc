#include <bits/stdc++.h>
using namespace std;

int lcs[1001][1001];

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	string a, b; cin >> a >> b;
	for(int i=0; i<1001; i++){ lcs[i][0] = 0; lcs[0][i] = 0; }
	
	for(int i=0; i<=b.length(); i++){
		for(int j=0; j<=a.length(); j++){
			if(i == 0 || j == 0) lcs[i][j] = 0;
			else if(b[i-1] == a[j-1]) lcs[i][j] = lcs[i-1][j-1] + 1;
			else lcs[i][j] = max(lcs[i-1][j], lcs[i][j-1]);
		}
	}
	
	string res = "";
	int y = b.length(), x = a.length();
	while(1){
		if(lcs[y][x] == 0) break;
		
		if(lcs[y][x] == lcs[y-1][x]) y--;
		else if(lcs[y][x] == lcs[y][x-1]) x--;
		else{ y--; x--; res += a[x]; }
	}
	
	cout << lcs[b.length()][a.length()] << '\n';
	for(int i=res.length(); i>0; i--) cout << res[i-1];
	return 0;
}
