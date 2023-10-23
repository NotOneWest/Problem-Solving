#include<iostream>
#include<vector>
  
using namespace std;
  
int main(int argc, char** argv)
{
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    int test_case;
    int T; cin>>T;
    
    for(test_case = 1; test_case <= T; ++test_case)
    {
        int n; cin >> n;
        int score[101];
        vector<int> canScore;
        bool visited[10001];
          
        for(int i=0; i<101; i++) score[i]=0;
        for(int i=0; i<10001; i++) visited[i]=false;
        canScore.clear();
          
        for(int i=0; i<n; i++) cin >> score[i];
          
        canScore.push_back(0);
        visited[0] = true;
          
        for(int i=0; i<n; i++){
            int size = canScore.size();
              
            for(int j=0; j<size; j++){
                int newScore = score[i] + canScore[j];
                if(!visited[newScore]){
                    visited[newScore] = true;
                    canScore.push_back(newScore);
                }
            }
        }
        cout << "#" << test_case << " " << canScore.size() << '\n';
    }
    return 0;//정상종료시 반드시 0을 리턴해야합니다.
}