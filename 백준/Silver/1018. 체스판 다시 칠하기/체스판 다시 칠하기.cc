#include <bits/stdc++.h>
#define pb push_back
#define mp make_pair
#define all(x) (x).begin(), (x).end()

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
const double PI = acos(-1);

char board[51][51];
string white[8] = {
        { "WBWBWBWB" },
        { "BWBWBWBW" },
        { "WBWBWBWB" },
        { "BWBWBWBW" },
        { "WBWBWBWB" },
        { "BWBWBWBW" },
        { "WBWBWBWB" },
        { "BWBWBWBW" }

};
string black[8] = {
        { "BWBWBWBW" },
        { "WBWBWBWB" },
        { "BWBWBWBW" },
        { "WBWBWBWB" },
        { "BWBWBWBW" },
        { "WBWBWBWB" },
        { "BWBWBWBW" },
        { "WBWBWBWB" }
};

int whitefirst(int x, int y){
	int cnt=0;
	for(int i=x; i<(x+8); i++){
		for(int j=y; j<(y+8); j++){
			if(board[i][j] != white[i-x][j-y]) cnt++;	
		}
	}
	return cnt;
}

int blackfirst(int x, int y){
	int cnt=0;
	for(int i=x; i<(x+8); i++){
		for(int j=y; j<(y+8); j++){
			if(board[i][j] != black[i-x][j-y]) cnt++;	
		}
	}
	return cnt;
}


int main(){
	int m,n; cin >> n >> m;
	for(int i=0; i<n; i++){
		for(int j=0; j<m; j++){
			cin >> board[i][j];
		}
	}
	int result = 1000000;
	
	for(int i=0; i<(n-7); i++){
		for(int j=0; j<(m-7); j++){
			result = min({result, whitefirst(i,j), blackfirst(i,j)});
		}
	}
	cout << result;
	return 0;
}
