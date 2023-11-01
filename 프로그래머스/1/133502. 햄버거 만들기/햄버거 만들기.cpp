#include <string>
#include <vector>

using namespace std;

int solution(vector<int> ingredient) {
    int answer = 0;
    string s;
    for(int i=0; i<ingredient.size(); i++){
        s += to_string(ingredient[i]);
        if(s.length() >= 4){
            string temp = s.substr(s.length()-4);
            if(temp == "1231"){
                s = s.substr(0, s.length()-4);
                answer++;
            }
        }
    }
    
    return answer;
}