#include <iostream>
#include <vector>
#include <algorithm>
#include <stdio.h>

using namespace std;

int n, k;
vector<int> bowl[101];

bool k_check(){
	int MAX=0, MIN = 10000;
	for(int i=0; i<n; i++){
		MAX = max(MAX, bowl[0][i]);
		MIN = min(MIN, bowl[0][i]);
	}
	return (k >= (MAX-MIN));
}

void move_fish(){
	int dx[4] = {0, 0, -1, 1};
	int dy[4] = {1, -1, 0, 0};
	vector<int> new_bowl[101];
	for(int i=0; i<=n; i++) new_bowl[i] = bowl[i];
	
	// 물고기의 수를 조절
	for(int i=0; i<n; i++){
		for(int j=0; j<n; j++){
			if(bowl[i][j] == -1) continue;
			
			for(int t=0; t<4; t++){
				int ni = i + dx[t], nj = j + dy[t];
				if(ni < 0 || ni > (n-1) || nj < 0 || nj > (n-1) || bowl[ni][nj] == -1) continue;
				
				new_bowl[i][j] += ((bowl[ni][nj] - bowl[i][j])/5);
			}
		}
	}
	
	// 다시 어항을 바닥에 일렬로
	vector<int> flat_bowl;
	for(int i=0; i<n; i++){
		for(int j=0; j<n; j++){
			if(new_bowl[j][i] == -1) continue;
			else flat_bowl.push_back(new_bowl[j][i]);
		}
	}
	
	for(int i=0; i<=n; i++){
		for(int j=0; j<=n; j++) bowl[i][j] = -1;
	}
	
	bowl[0] = flat_bowl;
}

void move(){
	// 물고기의 수가 가장 적은 어항에 물고기를 한 마리  
	int MIN = 10000;
	for(int i=0; i<n; i++) MIN = min(MIN, bowl[0][i]);
	for(int i=0; i<n; i++){
		if(bowl[0][i] == MIN) bowl[0][i]++;
	}
	
	// 공중 부양 1 
	int start=0, w=1, h=1;
	while((n - start - w) >= h){
		for(int i=0; i<h; i++){
			for(int j=0; j<w; j++){
				int ni = w - j;
				int nj = start + w + i;
				bowl[ni][nj] = bowl[i][start + j];
				bowl[i][start + j] = -1;
			}
		}
		start += w;
		(w == h) ? h++ : w++;
	}
	move_fish();
	
	// 공중 부양 2 
	start = 0; w = n/2; h = 1;
	for(int l=0; l<2; l++){
		for(int i=0; i<h; i++){
			for(int j=0; j<w; j++){
				int ni = 2*h - i - 1;
				int nj = start + 2*w - j - 1;
				bowl[ni][nj] = bowl[i][start + j];
				bowl[i][start + j] = -1;
			}
		}
		start = n/2; h *= 2; w /= 2;
	}
	move_fish();
}

void solution(){
	int cnt = 0;
	while(!k_check()){
		move();
		cnt++;
	}
	cout << cnt << "\n";
}

int main(){
	ios_base::sync_with_stdio;
	cin.tie(NULL); cout.tie(NULL);
	cin >> n >> k;
	
	for(int i=0; i<=n; i++){
		for(int j=0; j<=n; j++) bowl[i].push_back(-1);
	}
	
	for(int i=0; i<n; i++) cin >> bowl[0][i];
	solution();
	
	return 0;
}