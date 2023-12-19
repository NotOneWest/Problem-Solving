#include <string>
#include <vector>
#include <algorithm>
using namespace std;

bool comp(string a, string b){ return (a + b) > (b + a); }

string solution(vector<int> numbers) {
    string answer = "";
    vector<string> sorting;
    for(auto number : numbers) sorting.push_back(to_string(number));
    sort(sorting.begin(), sorting.end(), comp);
    for(auto s : sorting){
        answer += s;
        if(sorting[0] == "0") break; 
    }
    return answer;
}