#include <string>
#include <vector>
#include <iostream>

using namespace std;

string make_lower(string s){
    for(int i=0; i<s.length(); i++){
        if('A' <= s[i] && s[i] <= 'Z') s[i] -= ('A'-'a'); 
    }
    return s;
}

vector<string> make_union(string s){
    vector<string> v;
    for(int i=0; i<(s.length()-1); i++){
        if('a' <= s[i] && s[i] <= 'z'){
            if('a' <= s[i+1] && s[i+1] <= 'z') v.push_back(s.substr(i, 2));
        }
    }
    return v;
}

int solution(string str1, string str2) {
    int answer = 0;
    vector<string> str1_union, str2_union;
    str1 = make_lower(str1); str2 = make_lower(str2);
    str1_union = make_union(str1); 
    str2_union = make_union(str2);
    
    int str1_len = str1_union.size(), str2_len = str2_union.size();
    int same = 0, flag=0;
    
    for(int i=0; i<str1_len; i++){
        for(int j=0; j<str2_union.size(); j++){
            if(str1_union[i] == str2_union[j]){ 
                same++; 
                str2_union.erase(str2_union.begin() + j); 
                break; 
            }
        }
    }
    
    int union_len = (str1_len + str2_len - same); 
    if(union_len == 0){
        union_len = 1;
        if(same == 0) same = 1;
    }
    
    answer = (same * 65536 / union_len);
    return answer;
}