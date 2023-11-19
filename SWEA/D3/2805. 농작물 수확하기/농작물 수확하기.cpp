#include<iostream>
#include<string>
#include<vector>
using namespace std;

int main(int argc, char** argv)
{
	int test_case;
	int T; cin>>T;
    
	for(test_case = 1; test_case <= T; ++test_case)
	{
		int n; cin >> n;
        vector<string> v;
        for(int i=0; i<n; i++){
            string s; cin >> s;
            v.push_back(s);
        }
        
        int sum = 0, left = n/2, right = n/2;
        for(int i=0; i<n; i++){
            for(int j=left; j<=right; j++) sum += (v[i][j] - '0');
            if(i < n/2){ left--; right++; }
            else{ left++; right--; }
        }
        
        cout << "#" << test_case << " " << sum << "\n";
	}
	return 0;
}