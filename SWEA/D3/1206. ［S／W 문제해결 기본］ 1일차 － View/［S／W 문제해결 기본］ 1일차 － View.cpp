#include<iostream>
#include<algorithm>

using namespace std;

int h[1001];

int main(int argc, char** argv)
{
	int test_case;
	int T = 10;
	for(test_case = 1; test_case <= T; ++test_case)
	{
        int n, ans=0; cin >> n;
        for(int i=0; i<n; i++) cin >> h[i];
		for(int i=2; i<(n-2); i++){
            int see = 0;
            see = max(h[i-2], h[i-1]);
            see = max(see, h[i+1]);
            see = max(see, h[i+2]);
            if(h[i] >= see) ans += (h[i] - see);
        }
        cout << "#" << test_case << " " << ans << "\n";
	}
	return 0;
}