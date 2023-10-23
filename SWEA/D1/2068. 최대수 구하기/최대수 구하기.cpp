#include<iostream>
#include<algorithm>

using namespace std;

int main(int argc, char** argv)
{
	int test_case;
	int T; cin>>T;
    
	for(test_case = 1; test_case <= T; ++test_case)
	{
        int nums[10];
        for(int i=0; i<10; i++) cin >> nums[i];
        sort(nums, nums + 10);
        cout << "#" << test_case << " " << nums[9] << '\n';
	}
	return 0;//정상종료시 반드시 0을 리턴해야합니다.
}