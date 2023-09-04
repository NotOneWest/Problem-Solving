#include <bits/stdc++.h>

using namespace std;

vector<int> solution(string s) {
    vector<int> answer;
    int cnt=0, zero=0, len = s.length(), num;
    while(s != "1"){
        s.erase(remove(s.begin(), s.end(), '0'), s.end());
        zero += len-s.length(); len = s.length();
        if(len > s.length()) cnt++;
        s = "";
        while(len >= 2){ s += to_string(len%2); len /= 2; }
        s += to_string(len); len = s.length(); cnt++;
    }
    answer.push_back(cnt);
    answer.push_back(zero);
    return answer;
}