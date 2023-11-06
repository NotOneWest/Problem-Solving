#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int nums[100001];

vector<int> solution(string s) {
    vector<int> answer;
    for(int i=0; i<100001; i++) nums[i] = 0;
    
    string num="";
    for(int i=0; i<s.length(); i++){
        if(num.length() == 0){
            if('0' <= s[i] && s[i] <= '9') num += s[i];
        } else{
            if('0' <= s[i] && s[i] <= '9') num += s[i];
            else{
                nums[stoi(num)]++;
                num="";
            }
        }
    }
    vector<pair<int, int> > v;
    for(int i=1; i<100001; i++){
        if(nums[i] > 0) v.push_back(make_pair(-nums[i], i));
    }
    sort(v.begin(), v.end());
    
    for(int i=0; i<v.size(); i++) answer.push_back(v[i].second);
    
    return answer;
}