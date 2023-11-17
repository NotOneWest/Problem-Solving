#include<iostream>
#include<algorithm>
#include<string>
using namespace std;

string num;
int k, ans = 0;
bool visited[1000000][11];

void dfs(string n, int cnt){
	if(cnt == k){
    	ans = max(ans, stoi(n));
        return;
    }
    
    for(int i=0; i<(n.length() - 1); i++){
    	for(int j=(i+1); j<n.length(); j++){
       		swap(n[i], n[j]);
            if(!visited[stoi(n)][cnt]){
                visited[stoi(n)][cnt] = true;
                dfs(n, cnt + 1);
            }
            swap(n[i], n[j]);
        }
    }
}

int main(int argc, char** argv)
{
	int test_case;
	int T; cin>>T;
    
	for(test_case = 1; test_case <= T; ++test_case)
	{
        cin >> num >> k;
        ans = 0;
        
        for(int i=0; i<1000000; i++){
            for(int j=0; j<10; j++) visited[i][j] = false;
        }
        
        dfs(num, 0);
        cout << "#" << test_case << " " << ans << "\n";
	}
	return 0;//정상종료시 반드시 0을 리턴해야합니다.
}