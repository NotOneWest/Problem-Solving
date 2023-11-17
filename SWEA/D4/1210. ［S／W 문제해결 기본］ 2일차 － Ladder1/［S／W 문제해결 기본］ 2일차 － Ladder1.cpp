#include<iostream>
using namespace std;

int main(int argc, char** argv)
{
	for(int test_case = 1; test_case <= 10; ++test_case)
	{
        int tc; cin >> tc;
        int x = 99, y = 0;
        
        int board[100][100];
		bool visited[100][100];
        for(int i=0; i<100; i++){
            for(int j=0; j<100; j++){
                cin >> board[i][j];
                visited[i][j] = false;
                if(i == 99 && board[i][j] == 2) y=j;
            }
        }
        
        while(1){
            if(x == 0) break;
            
            if(y == 0){
                if(board[x][y+1] == 1 && !visited[x][y+1]){ y++; visited[x][y] = true; }
                else{ x--; visited[x][y] = true; }
            } else if(y == 99){
                if(board[x][y-1] == 1 && !visited[x][y-1]){ y--; visited[x][y] = true; }
                else{ x--; visited[x][y] = true; }
            } else{
                if(board[x][y-1] == 1 && !visited[x][y-1]){ y--; visited[x][y] = true; }
                else if(board[x][y+1] == 1 && !visited[x][y+1]){ y++; visited[x][y] = true; }
                else{ x--; visited[x][y] = true; }
            }
        }
        
        cout << "#" << tc << " " << y << "\n";
	}
	return 0;
}

// #include<iostream>
// using namespace std;

// int board[100][100];
// bool visited[100][100];
// int dx[3] = {0, 0, -1}, dy[3] = {-1, 1, 0};
// int answer;

// void route(int x, int y){
//     if(x == 0){ answer = y; return; }
    
//     for(int i=0; i<3; i++){
//         int nx = x + dx[i], ny = y + dy[i];
//         if(nx<0 || nx >=100 || ny<0 || ny>=100 || board[nx][ny] == 0 || visited[nx][ny]) continue;
//         visited[nx][ny] = true;
//         route(nx, ny);
//         return;
//     }
// }

// int main(int argc, char** argv)
// {
// 	for(int test_case = 1; test_case <= 10; ++test_case)
// 	{
//         int tc, y; cin >> tc;
//         answer = y = 0;
//         for(int i=0; i<100; i++){
//             for(int j=0; j<100; j++){
//                 cin >> board[i][j];
//                 visited[i][j] = false;
//                 if(i == 99 && board[i][j] == 2) y=j;
//             }
//         }
//         route(99, y);
//         cout << "#" << tc << " " << y << "\n";
// 	}
// 	return 0;
// }
