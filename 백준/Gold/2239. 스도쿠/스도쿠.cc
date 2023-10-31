#include <bits/stdc++.h>
using namespace std;

vector<string> board;
bool row[10][10], col[10][10], box[10][10];

void sudoku(int index){
	if(index == 81){
		for(int i=0; i<9; i++) cout << board[i] << '\n';
		exit(0);
	}
	
	int c = index/9, r = index%9;
	if(board[c][r] == '0'){
		for(int i=1; i<=9; i++){
			if(!row[r][i] && !col[c][i] && !box[(c/3)*3 + r/3][i]){
				row[r][i] = true;
				col[c][i] = true;
				box[(c/3)*3 + r/3][i] = true;
				board[c][r] = (i + '0');
				sudoku(index + 1);
				board[c][r] = '0';
				row[r][i] = false;
				col[c][i] = false;
				box[(c/3)*3 + r/3][i] = false;
			}
		}
	} else sudoku(index + 1);
}

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	for(int i=0; i<9; i++){
		string s; cin >> s;
		board.push_back(s);
		for(int j=0; j<9; j++){
			if(s[j] != '0'){
				row[j][s[j]-'0'] = true;
				col[i][s[j]-'0'] = true;
				box[(i/3)*3+j/3][s[j]-'0'] = true;
			}
		}
	}
	sudoku(0);
	return 0;
}
