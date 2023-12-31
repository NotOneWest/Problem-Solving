#include <iostream>
#include<vector>
using namespace std;

int dx[3] = {0, -1, -1};
int dy[3] = {-1, 0, -1};

int solution(vector<vector<int>> board)
{
    int answer = board[0][0]; // edge case 잘 생각할 것
    
    for(int i=1; i<board.size(); i++){
        for(int j=1; j<board[0].size(); j++){
            if(board[i][j] == 1){
                board[i][j] = 1 + min(board[i-1][j-1], min(board[i-1][j], board[i][j-1]));
            }
        }
    }
    
    for(int i=1; i<board.size(); i++){
        for(int j=1; j<board[0].size(); j++) answer = max(answer, board[i][j]);
    }

    return answer * answer;
}
