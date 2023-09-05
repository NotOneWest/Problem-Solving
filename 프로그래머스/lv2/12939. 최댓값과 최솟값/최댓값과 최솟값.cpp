#include <bits/stdc++.h>

using namespace std;

string solution(string s) {
    string answer = "";
    
    string num="";
    vector<int> nums;
    for(int i=0; i<s.length(); i++){
        if(s[i] == ' '){ nums.push_back(stoi(num)); num=""; }
        else num += s[i];
    }
    nums.push_back(stoi(num));
    sort(nums.begin(), nums.end());
    answer += to_string(nums[0]);
    answer += " ";
    answer += to_string(nums[nums.size()-1]);
    return answer;
}