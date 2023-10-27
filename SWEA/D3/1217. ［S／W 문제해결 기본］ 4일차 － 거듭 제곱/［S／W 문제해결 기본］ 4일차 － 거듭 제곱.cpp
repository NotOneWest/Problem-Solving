#include<iostream>

using namespace std;

int cal_pow(int a, int b, int res){
	if(b == 0) return res;
    cal_pow(a, b-1, res*a);
}

int main(int argc, char** argv)
{
	for(int i=0; i<10; i++)
	{
		int test_case, a, b; cin >> test_case >> a >> b;
        cout << "#" << test_case << " " << cal_pow(a, b, 1) << '\n';
	}
	return 0;//정상종료시 반드시 0을 리턴해야합니다.
}