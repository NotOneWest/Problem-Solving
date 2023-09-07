#include <bits/stdc++.h>

using namespace std;

int maps[21][21];
int loc[6]={0, 1, 2, 3, 4, 5}; // 바닥, 정면, 위, 뒤, 오, 왼 
int dice[6]={0, 0, 0, 0, 0, 0};
int n, m, x, y, k;

int move(int dir){
	int temp=0, temp2=0;
	if(dir==1) {
		if(y == (m-1)) return 0; 
		y++; 
		temp=loc[0]; temp2=loc[2]; 
		loc[0]=loc[5]; loc[2]=loc[4]; 
		loc[4]=temp; loc[5]=temp2;  
	} else if(dir==2) {
		if(y == 0) return 0;
		y--;
		temp=loc[0]; temp2=loc[2]; 
		loc[0]=loc[4]; loc[2]=loc[5]; 
		loc[4]=temp2; loc[5]=temp; 
	} else if(dir==3) {
		if(x == 0) return 0;
		x--; temp = loc[0];
		loc[0]=loc[1]; loc[1]=loc[2]; loc[2]=loc[3]; loc[3]=temp;
	} else{ 
		if(x == (n-1)) return 0;
		x++; temp = loc[3];
		loc[3]=loc[2]; loc[2]=loc[1]; loc[1]=loc[0]; loc[0]=temp; 
	}
	return 1;
}

int main(){
	cin >> n >> m >> x >> y >> k;
	for(int i=0; i<n; i++){
		for(int j=0; j<m; j++) cin >> maps[i][j];
	}
	
	if(maps[x][y]) { dice[loc[0]] = maps[x][y]; maps[x][y]=0; } 
	
	for(int t=0; t<k; t++){
		int dir; cin >> dir;
		if(move(dir) == 0) continue;
		
		if(maps[x][y]) { dice[loc[0]] = maps[x][y]; maps[x][y]=0; } 
		else maps[x][y]=dice[loc[0]];
		
		cout << dice[loc[2]] << '\n';
	}
	return 0;
}