#include<vector>
#include<algorithm>
#include<iostream>

using namespace std;

int main(int argc, char** argv)
{
	int test_case;
	int T = 10;
    
	for(test_case = 1; test_case <= T; ++test_case)
	{
        int dump; cin >> dump;
        vector<int> v;
        for(int i=0; i<100; i++){
            int h; cin >> h;
            v.push_back(h);
        }
        
        for(int i=0; i<dump; i++){
            sort(v.begin(), v.end());
            if((v[99] - v[0]) == 0) break;
            v[99]--; v[0]++;
        }
        sort(v.begin(), v.end());
        cout << "#" << test_case << " " << (v[99] - v[0]) << "\n";
	}
	return 0;//정상종료시 반드시 0을 리턴해야합니다.
}