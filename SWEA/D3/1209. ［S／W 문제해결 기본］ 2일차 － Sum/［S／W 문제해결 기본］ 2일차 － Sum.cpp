#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int main(int argc, char** argv)
{
	int test_case;
	for(test_case = 1; test_case <= 10; ++test_case)
	{
        int tc; cin >> tc;
        int board[100][100];
        vector<int> sum;
        for(int i=0; i<100; i++){
            for(int j=0; j<100; j++) cin >> board[i][j];
        }
        
        int sum1=0, sum2=0;
        for(int i=0; i<100; i++){
            sum1 += board[i][i];
            sum2 += board[i][99-i];
            int col_sum=0, row_sum=0;
            for(int j=0; j<100; j++){
                row_sum += board[i][j];
                col_sum += board[j][i];
            }
            sum.push_back(col_sum);
            sum.push_back(row_sum);
        }
        sum.push_back(sum1);
        sum.push_back(sum2);
        
        sort(sum.begin(), sum.end());
        cout << "#" << tc << " " << sum[201] << "\n";
	}
	return 0;
}