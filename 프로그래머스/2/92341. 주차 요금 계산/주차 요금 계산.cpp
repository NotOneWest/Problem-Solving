#include<bits/stdc++.h>
using namespace std;

vector<int> solution(vector<int> fees, vector<string> records) {
    vector<int> answer;
    
    map<string, string> pakring_records;
    map<string, int> parking_times;
    
    for(auto record : records){
        string times = record.substr(0, 5);
        string num = record.substr(6, 4);
        string flag = record.substr(11);
        
        if(flag == "IN") pakring_records[num] = times;
        else{
            int hour = stoi(times.substr(0, 2)) - stoi(pakring_records[num].substr(0, 2));
            int min = stoi(times.substr(3)) - stoi(pakring_records[num].substr(3));
            
            parking_times[num] += (hour*60 + min);
            pakring_records[num] = "----";
        }
    }
    
    for(auto record : pakring_records){
        if(record.second != "----"){
            int hour = 23 - stoi(record.second.substr(0, 2));
            int min = 59 - stoi(record.second.substr(3));
            
            parking_times[record.first] += (hour*60 + min);
        }
    }
    
    for(auto parking_time : parking_times){
        int fee = fees[1];
        if(parking_time.second > fees[0]){
            fee += ((parking_time.second - fees[0]) / fees[2]) * fees[3];
            if(((parking_time.second - fees[0]) % fees[2]) != 0) fee += fees[3];
        }
        
        answer.push_back(fee);
    }
    
    return answer;
}