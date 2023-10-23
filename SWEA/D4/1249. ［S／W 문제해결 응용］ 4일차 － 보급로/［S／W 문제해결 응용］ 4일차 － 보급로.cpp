#include<iostream>
#include<queue>
#include<vector>
#include<string.h>

using namespace std;

int dx[4] = {1, -1, 0, 0};
int dy[4] = {0, 0, 1, -1};
int road[100][100], cost[100][100];
bool visited[100][100];
int n;

int main(int argc, char** argv)
{
    ios_base :: sync_with_stdio(false); 
    cin.tie(NULL); 
    cout.tie(NULL);
	int test_case;
	int T; cin>>T;
    
	for(test_case = 1; test_case <= T; ++test_case)
	{
        cin >> n;
        
        for(int i=0; i<100; i++){
        	for(int j=0; j<100; j++){ road[i][j]=0; visited[i][j]=false; cost[i][j]=0; }
        }
        
        for(int i=0; i<n; i++){
            string s; cin >> s;
        	for(int j=0; j<n; j++) road[i][j] = (s[j] - '0');
        }
        
        queue<pair<int, int> > loc;
        loc.push(make_pair(0, 0));
        visited[0][0] = true;
        
        while(!loc.empty()){
            int x = loc.front().first, y = loc.front().second;
            loc.pop();
            
            for(int i=0; i<4; i++){
                int nx = (x + dx[i]), ny = (y + dy[i]);
                if(nx<0 || nx>(n-1) || ny<0 || ny>(n-1)) continue;
                
                if(visited[nx][ny] == 0 || cost[nx][ny] > (cost[x][y] + road[nx][ny])){
                	visited[nx][ny] = 1;
                    cost[nx][ny] = (cost[x][y] + road[nx][ny]);
                    loc.push(make_pair(nx, ny));
                }
            }
        }
        cout << "#" << test_case << " " << cost[n-1][n-1] << '\n';
	}
	return 0;//정상종료시 반드시 0을 리턴해야합니다.
}