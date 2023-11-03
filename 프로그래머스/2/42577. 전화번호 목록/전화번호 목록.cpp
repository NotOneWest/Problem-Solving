#include <bits/stdc++.h>
using namespace std;

bool solution(vector<string> phone_book) {
    bool answer = true;
    sort(phone_book.begin(), phone_book.end());
    for(int i=0; i<(phone_book.size()-1); i++){
        int len = min(phone_book[i].length(), phone_book[i+1].length());
        int check=0;
        for(int j=0; j<len; j++){
            if(phone_book[i][j] != phone_book[i+1][j]){
                check=1; break;
            }
        }
        if(!check){ answer = false; break; } 
    }
    return answer;
}