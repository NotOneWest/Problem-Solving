#include <string>
#include <vector>
using namespace std;

char num[] = {'0','1','2','3','4','5','6','7','8','9','A','B','C','D','E','F' };

string change(int number, int n){
    string s = "";
    while(number >= n){
        s += num[number%n];
        number /= n;
    }
    s += num[number%n];
    return s;
}

string solution(int n, int t, int m, int p) {
    string answer = "";
    int turn = 0;
    for(int i=0; i<=m*t; i++){
        string s = change(i, n);
        for(int j=(s.length()-1); j>=0; j--){
            turn ++;
            if(((turn-p) % m) == 0) answer += s[j];
            if(answer.length() == t) break;
        }
        if(answer.length() == t) break;
    }
    return answer;
}