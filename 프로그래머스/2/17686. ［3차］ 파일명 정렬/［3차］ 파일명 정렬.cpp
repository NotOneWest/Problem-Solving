#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

struct file_info{
    string head;
    int num;
    int index;
};

bool comp(const file_info& a, const file_info& b){
    if(a.head == b.head){
        if(a.num == b.num) return a.index < b.index;
        else return a.num < b.num;
    }else return a.head < b.head;
}

vector<string> solution(vector<string> files) {
    vector<string> answer;
    
    vector<file_info> sorting;
    for(int idx=0; idx<files.size(); idx++){
        int flag = 0;
        string head="";
        string num="";
        for(int i=0; i<files[idx].length(); i++){
            if('0'<=files[idx][i] && files[idx][i]<='9'){
                if(flag == 0) flag = 1;
            }
            else{
                if(flag == 1) flag = 2;
            }
            
            if(flag == 0) head += tolower(files[idx][i]);
            else if(flag == 1) num += files[idx][i];
            else break;
        }
        
        file_info info;
        info.index = idx;
        info.head = head;
        info.num = stoi(num);
        sorting.push_back(info);
    }
    sort(sorting.begin(), sorting.end(), comp);
    
    for(int i=0; i<sorting.size(); i++) answer.push_back(files[sorting[i].index]);
    return answer;
}