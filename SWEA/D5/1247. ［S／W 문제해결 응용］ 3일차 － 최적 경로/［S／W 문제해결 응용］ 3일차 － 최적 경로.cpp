#include<iostream>
#include<vector>

using namespace std;

vector<pair<int, int> > loc;
int visited[11];
int n, dist, startX, startY, endX, endY; 

void dfs(int x, int y, int size, int sum){
	if(size == n){
        sum += (abs(endX - x) + abs(endY - y));
        dist = min(dist, sum);
        return;
    }
    
    for(int i=0; i<n; i++){
        if(!visited[i]){
            visited[i] = true;
            dfs(loc[i].first, loc[i].second, size+1, sum + (abs(loc[i].first - x) + abs(loc[i].second - y)) );
            visited[i] = false;
        }
    }
}

int main(int argc, char** argv)
{
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
	int test_case;
	int T;
	cin>>T;
    
	for(test_case = 1; test_case <= T; ++test_case)
	{
        cin >> n;
        cin >> startX >> startY >> endX >> endY;
        
        for(int i=0; i<11; i++) visited[i] = 0;
        loc.clear();
        
        for(int i=0; i<n; i++){
            int x, y; cin >> x >> y;
            loc.push_back(make_pair(x, y));
        }
        
        dist = 99999999;
        dfs(startX, startY, 0, 0);
        cout << "#" << test_case << "  " << dist << "\n";
	}
	return 0;//정상종료시 반드시 0을 리턴해야합니다.
}