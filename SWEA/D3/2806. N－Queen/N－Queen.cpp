#include<iostream>
#include<algorithm>
using namespace std;

int col[11];
int n, ans=0;
bool check(int x){
    for(int i=0; i<x; i++){
        if(col[x] == col[i] || abs(x-i) == abs(col[x] - col[i])) return false;
    }
    return true;
}

void Nqueen(int cnt){
    if(cnt == n){
    	ans++;
        return;
    }
    
    for(int i=0; i<n; i++){
        col[cnt] = i;
        if(check(cnt)) Nqueen(cnt + 1);
    }
}

int main(int argc, char** argv)
{
	int test_case;
	int T; cin>>T;
    
	for(test_case = 1; test_case <= T; ++test_case)
	{
        cin >> n;
        for(int i=0; i<n; i++) col[i] = 0;
        ans = 0;
        Nqueen(0);
        cout << "#" << test_case << " " << ans << "\n";
	}
	return 0;//정상종료시 반드시 0을 리턴해야합니다.
}