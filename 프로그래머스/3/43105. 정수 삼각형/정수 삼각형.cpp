#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

int solution(vector<vector<int>> triangle) {
    int answer = 0, len = triangle.size();
    
    for(int i=1; i<len; i++){
        for(int j=0; j<triangle[i].size(); j++){
            if(j == 0) triangle[i][j] += triangle[i-1][j];
            else if(j == (triangle[i].size()-1)) triangle[i][j] += triangle[i-1][j-1];
            else triangle[i][j] += max(triangle[i-1][j-1], triangle[i-1][j]);
        }
    }
    
    sort(triangle[len-1].begin(), triangle[len-1].end());
    
    return triangle[len-1].back();
}