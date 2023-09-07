#include <bits/stdc++.h>
#define pb push_back
#define mp make_pair
#define all(x) (x).begin(), (x).end()

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
const double PI = acos(-1);

string board[5];
int selection[26], ans=0;
int dx[4] = { 0, 0, 1, -1 }, dy[4] = { 1, -1 ,0, 0 };

bool checkfour(){
	int cnt=0;
	for(int i=0; i<25; i++){
		if(selection[i]==1){
			int x=(i/5), y=(i%5);
			if(board[x][y]=='S') cnt++;
		}
	}
	return (cnt>=4);
}

bool checkadj(){
	int flag=0, cnt=1, visited[5][5], selected[5][5];
	queue<pii> q;
	for(int i=0; i<5; i++){ // 초기화를 제대로 안해주니 오류가 난다... 별로 신경 안쓰는 포인트인데 앞으로 신경 쓸 것.
		fill(visited[i], visited[i]+5, 0);
		fill(selected[i], selected[i]+5, 0);
	}
	for(int i=0; i<25; i++){
		if(selection[i]==1){
			int x=(i/5), y=(i%5);
			selected[x][y]=1;
			if(flag==0){
				q.push(mp(x,y));
				visited[x][y]=1;
				flag++;
			}
		}
	}
	while (!q.empty()) {
		int x=q.front().first, y=q.front().second;
		q.pop();
		if(cnt==7) break;
		for(int i=0; i<4; i++){
			int nx=(x+dx[i]), ny=(y+dy[i]);
			if(nx>=0 && nx<5 && ny>=0 && ny<5){
				if(visited[nx][ny]==0 && selected[nx][ny]==1){
					visited[nx][ny]=1;
					cnt++;
					q.push(mp(nx,ny));
				}
			}
		}
	}
	return cnt==7;
}

void func(int start, int num){
	if(num==7){
		if(checkfour() && checkadj()) ans++;
		return;
	}
	for(int i=start; i<25; i++){
		if(selection[i]==0){
			selection[i]=1;
			func(i,num+1);
			selection[i]=0;
		}
	}
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	for(int i=0; i<5; i++) cin >> board[i];
	func(0,0);
	cout << ans << '\n';
	return 0;
}
